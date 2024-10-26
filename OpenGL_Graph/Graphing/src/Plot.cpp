// Include the necessary headers
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include <vector>

// Window dimensions
const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;

// Vertex and Fragment Shader source code
const char* vertexShaderSource = R"glsl(
    #version 330 core
    layout (location = 0) in vec2 aPos;
    void main() {
        gl_Position = vec4(aPos, 0.0, 1.0);
    }
)glsl";

const char* fragmentShaderSource = R"glsl(
    #version 330 core
    out vec4 FragColor;
    uniform vec3 color;
    void main() {
        FragColor = vec4(color, 1.0);
    }
)glsl";

// Function to plot (y = sin(x) in this case)
float functionToPlot(float x) {
    return std::sin(x);
}

// Function to initialize OpenGL and create a window
GLFWwindow* initOpenGL() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return nullptr;
    }

    // Set GLFW to use OpenGL version 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a windowed mode window and OpenGL context
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL Graphing Tool", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return nullptr;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Disable V-Sync
    glfwSwapInterval(1);

    // Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return nullptr;
    }

    return window;
}

// Function to compile a shader
GLuint compileShader(GLenum type, const char* source) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    // Check for compile errors
    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    return shader;
}

// Function to create the shader program
GLuint createShaderProgram() {
    GLuint vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
    GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

    // Create shader program and link shaders
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Check for linking errors
    int success;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    // Clean up shaders as they're no longer needed after linking
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

// Function to create a line between two points
std::vector<float> createLine(float x1, float y1, float x2, float y2) {
    return { x1, y1, x2, y2 };
}

// Function to create a plot of the function in the range [-10, 10]
std::vector<float> createPlotData(float offset) {
    std::vector<float> data;
    for (float x = -10.0f; x <= 10.0f; x += 0.1f) {
        float y = functionToPlot(x + offset);
        data.push_back(x / 10.0f);  // Normalize to fit within the window
        data.push_back(y / 2.0f);   // Normalize to fit within the window
    }
    return data;
}

int main() {
    // Initialize OpenGL and create a window
    GLFWwindow* window = initOpenGL();
    if (!window) {
        return -1;
    }

    // Create shader program
    GLuint shaderProgram = createShaderProgram();

    // Create data for axes
    std::vector<float> xAxes = createLine(-1.0f, 0.0f, 1.0f, 0.0f); // X-axis
    std::vector<float> yAxis = createLine(0.0f, -1.0f, 0.0f, 1.0f); // Y-axis

    // Create Vertex Array Object and Vertex Buffer Object
    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // Animation variables
    float offset = 0.0f;
    float speed = 1.0f; // Speed of animation

    // FPS calculation variables
    double previousTime = glfwGetTime();
    int frameCount = 0;
    

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT);

        // Calculate FPS
        double currentTime = glfwGetTime();
        frameCount++;
        if (currentTime - previousTime >= 1.0) {
            std::cout << "FPS: " << frameCount << std::endl;
            frameCount = 0;
            previousTime = currentTime;
        }

        // Use the shader program
        glUseProgram(shaderProgram);
        GLuint colorLocation = glGetUniformLocation(shaderProgram, "color");

        // Bind VAO
        glBindVertexArray(VAO);

        // Draw X-axis
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, xAxes.size() * sizeof(float), xAxes.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glUniform3f(colorLocation, 1.0f, 1.0f, 1.0f); // White color for axes
        glDrawArrays(GL_LINES, 0, 2);

        // Draw Y-axis
        glBufferData(GL_ARRAY_BUFFER, yAxis.size() * sizeof(float), yAxis.data(), GL_STATIC_DRAW);
        glDrawArrays(GL_LINES, 0, 2);

        // Update plot data
        std::vector<float> plotData = createPlotData(offset);
        offset += 0.01f * speed; // Update offset for animation

        // Draw the plot
        glBufferData(GL_ARRAY_BUFFER, plotData.size() * sizeof(float), plotData.data(), GL_STATIC_DRAW);
        glUniform3f(colorLocation, 1.0f, 0.0f, 0.0f); // Red color for the plot
        glDrawArrays(GL_LINE_STRIP, 0, plotData.size() / 2);

        // Unbind VAO
        glBindVertexArray(0);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    // Clean up resources
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
    glDeleteProgram(shaderProgram);
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
