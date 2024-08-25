#ifndef VERTEXES_H
#define VERTEXES_H
#define STB_IMAGE_IMPLEMENTATION

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <stb/stb_image.h>

const char* vertexShaderSource = "#version 460 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aColor;\n"
"layout (location = 2) in vec2 aTexCoord;\n"
"uniform mat4 uProjection;\n"
"uniform mat4 uView;\n"
"uniform mat4 uModel;\n"
"out vec3 oColor;\n"
"out vec2 TexCoord;\n"
"void main()\n"
"{\n"
"   oColor = aColor;\n"
"   gl_Position = uProjection * uView * uModel * vec4(aPos, 1.0);\n"
"   TexCoord = vec2(aTexCoord.x, aTexCoord.y);\n"
"}\0";

const char* fragmentShaderSource = "#version 460 core\n"
"out vec4 FragColor;\n"
"in vec3 oColor;\n"
"in vec2 TexCoord;\n"
"uniform float number;\n"
"uniform sampler2D ourTexture;\n"
"void main()\n"
"{\n"
"   FragColor = texture(ourTexture, TexCoord) * vec4(oColor.x, oColor.y * number, oColor.z, 1.0f);\n"
"}\n\0";

float verticesPoly[] = {
     // positions         // colors           // texture coords
     0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
};

float vertices[] = {
         // positions         // colors       // texture coords
        -0.5f, -0.5f, -0.5f,  1.0, 1.0, 1.0,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0, 1.0, 1.0,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0, 1.0, 1.0,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0, 1.0, 1.0,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  1.0, 1.0, 1.0,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  1.0, 1.0, 1.0,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  1.0, 1.0, 1.0,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0, 1.0, 1.0,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0, 1.0, 1.0,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0, 1.0, 1.0,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  1.0, 1.0, 1.0,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  1.0, 1.0, 1.0,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0, 1.0, 1.0,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0, 1.0, 1.0,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  1.0, 1.0, 1.0,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  1.0, 1.0, 1.0,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  1.0, 1.0, 1.0,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0, 1.0, 1.0,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0, 1.0, 1.0,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0, 1.0, 1.0,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0, 1.0, 1.0,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0, 1.0, 1.0,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0, 1.0, 1.0,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0, 1.0, 1.0,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  1.0, 1.0, 1.0,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0, 1.0, 1.0,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0, 1.0, 1.0,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0, 1.0, 1.0,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  1.0, 1.0, 1.0,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  1.0, 1.0, 1.0,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  1.0, 1.0, 1.0,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0, 1.0, 1.0,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0, 1.0, 1.0,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0, 1.0, 1.0,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0, 1.0, 1.0,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0, 1.0, 1.0,  0.0f, 1.0f
};

unsigned int indices[] = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
};

unsigned int shaderProgram, vertexShader, fragmentShader;

unsigned int VAO, VBO, EBO;

unsigned int texture1;

float rotationSpeed = 1;
float fovSpeed = 0;

void MakeAllShaderOperations() {
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);

    glCompileShader(vertexShader);
    glCompileShader(fragmentShader);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void UseShader() {
    glUseProgram(shaderProgram);
}

void MakeAllVertexOperations() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void MakeAllTextureOperations() {
    stbi_set_flip_vertically_on_load(true);
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    unsigned char* data = stbi_load("../logo.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    glUniform1i(glGetUniformLocation(shaderProgram, "ourTexture"), 0);
}

void DrawEverything() {
    UseShader();
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glBindVertexArray(VAO);
}

void SetShaderFloat(std::string paramName, float value) {
    glUniform1f(glGetUniformLocation(shaderProgram, paramName.c_str()), value);
}

void SetShaderMat4(std::string paramName, glm::mat4 value) {
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, paramName.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}

double clamp(double d, double min, double max) {
    const double t = d < min ? min : d;
    return t > max ? max : t;
}

void initImGui(GLFWwindow* window) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Set up Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 460");

    // Set up Dear ImGui style
    ImGui::StyleColorsLight();
}

void showFPSImGui() {

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::SetNextWindowSize(ImVec2(100, 10));
    ImGui::SetNextWindowPos(ImVec2(10, 10));

    ImGui::Begin("Performance", NULL, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoTitleBar);
    ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);
    ImGui::End();


    ImGui::SetNextWindowSize(ImVec2(200, 100));
    ImGui::SetNextWindowPos(ImVec2(10, 50));
    ImGui::Begin("Polygons rotation speed", NULL, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoTitleBar);
    ImGui::InputFloat("Speed", &rotationSpeed);
    if (ImGui::Button("+")) {
        rotationSpeed += .1f;
    }

    if (ImGui::Button("-")) {
        rotationSpeed -= .1f;
    }
    ImGui::End();


    ImGui::SetNextWindowSize(ImVec2(200, 100));
    ImGui::SetNextWindowPos(ImVec2(10, 150));
    ImGui::Begin("Change fov", NULL, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoTitleBar);
    ImGui::InputFloat("Add fov", &fovSpeed);
    if (ImGui::Button("+")) {
        fovSpeed -= 5.0f;
    }

    if (ImGui::Button("-")) {
        fovSpeed += 5.0f;
    }
    ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void shutdownImGui() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

#endif // !VERTEXES_H
