cmake_minimum_required(VERSION 3.0)
project(RP3D_TESTBED CXX)

# Build bundled NanoGUI
set(LIBRARY_OUTPUT_PATH "")
add_subdirectory("nanogui")

# Copy the shaders and meshes used for the demo into the build directory
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/build/testbed")
file(COPY "shaders" DESTINATION "${EXECUTABLE_OUTPUT_PATH}")
file(COPY "meshes" DESTINATION "${EXECUTABLE_OUTPUT_PATH}")

set(OPENGLFRAMEWORK_SOURCES
    opengl-framework/src/maths/Color.h
    opengl-framework/src/maths/Matrix3.h
    opengl-framework/src/maths/Matrix4.h
    opengl-framework/src/maths/Vector2.h
    opengl-framework/src/maths/Vector3.h
    opengl-framework/src/maths/Vector4.h
    opengl-framework/src/Camera.cpp
    opengl-framework/src/Camera.h
    opengl-framework/src/definitions.h
    opengl-framework/src/FrameBufferObject.cpp
    opengl-framework/src/FrameBufferObject.h
    opengl-framework/src/Light.h
    opengl-framework/src/Light.cpp
    opengl-framework/src/Mesh.h
    opengl-framework/src/Mesh.cpp
    opengl-framework/src/MeshReaderWriter.h
    opengl-framework/src/MeshReaderWriter.cpp
    opengl-framework/src/Object3D.h
    opengl-framework/src/Object3D.cpp
    opengl-framework/src/openglframework.h
    opengl-framework/src/Shader.h
    opengl-framework/src/Shader.cpp
    opengl-framework/src/Texture2D.h
    opengl-framework/src/Texture2D.cpp
    opengl-framework/src/TextureReaderWriter.h
    opengl-framework/src/TextureReaderWriter.cpp
    opengl-framework/src/VertexBufferObject.h
    opengl-framework/src/VertexBufferObject.cpp
    opengl-framework/src/VertexArrayObject.h
    opengl-framework/src/VertexArrayObject.cpp
)

set(TESTBED_SOURCES
    src/Main.cpp
    src/TestbedApplication.h
    src/TestbedApplication.cpp
    src/Gui.h
    src/Gui.cpp
    src/Scene.h
    src/Scene.cpp
    src/SceneDemo.h
    src/SceneDemo.cpp
    src/Timer.h
    src/Timer.cpp
)

set(COMMON_SOURCES
    common/Box.h
    common/Box.cpp
    common/Cone.h
    common/Cone.cpp
    common/Sphere.h
    common/Sphere.cpp
    common/Line.h
    common/Line.cpp
    common/Capsule.h
    common/Capsule.cpp
    common/ConvexMesh.h
    common/ConvexMesh.cpp
    common/ConcaveMesh.h
    common/ConcaveMesh.cpp
    common/Cylinder.h
    common/Cylinder.cpp
    common/Dumbbell.h
    common/Dumbbell.cpp
    common/HeightField.h
    common/HeightField.cpp
    common/PhysicsObject.h
    common/PhysicsObject.cpp
    common/VisualContactPoint.h
    common/VisualContactPoint.cpp
    common/PerlinNoise.h
    common/PerlinNoise.cpp
)

set(SCENES_SOURCES
    scenes/cubes/CubesScene.h
    scenes/cubes/CubesScene.cpp
    scenes/joints/JointsScene.h
    scenes/joints/JointsScene.cpp
    scenes/raycast/RaycastScene.h
    scenes/raycast/RaycastScene.cpp
    scenes/collisionshapes/CollisionShapesScene.h
    scenes/collisionshapes/CollisionShapesScene.cpp
    scenes/concavemesh/ConcaveMeshScene.h
    scenes/concavemesh/ConcaveMeshScene.cpp
    scenes/heightfield/HeightFieldScene.h
    scenes/heightfield/HeightFieldScene.cpp
)

# Add .user file to set debug path in Visual Studio
set(USER_FILE testbed.vcxproj.user)
set(VS_USERFILE_WORKING_DIRECTORY_DEBUG ${EXECUTABLE_OUTPUT_PATH})
set(OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/${USER_FILE})
configure_file(VisualStudioUserTemplate.user ${USER_FILE} @ONLY)

# Include ReactPhysics3D Headers
include_directories("../include/rp3d")

# Include NanoGUI, glew, glfw and NanoVG headers
include_directories("glew/include" "nanogui/ext/glfw/include" "nanogui/ext/glew/include" "nanogui/include" "nanogui/ext/nanovg/src")

# Include Eigen as system headers to prevent compiler warnings
include_directories(SYSTEM "nanogui/ext/eigen")

# Include OpenGL-Framework and Testbed headers
include_directories("opengl-framework/src" "src" "common" "scenes")

# Create the executable target
add_executable(rp3d_testbed ${OPENGLFRAMEWORK_SOURCES} ${TESTBED_SOURCES} ${COMMON_SOURCES} ${SCENES_SOURCES})

# Require and enable C++11 features
set_property(TARGET rp3d_testbed PROPERTY CXX_STANDARD 11)
set_property(TARGET rp3d_testbed PROPERTY CXX_STANDARD_REQUIRED ON)

# Link testbed with libraries
target_link_libraries(rp3d_testbed reactphysics3d nanogui ${NANOGUI_EXTRA_LIBS})
