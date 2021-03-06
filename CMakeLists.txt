cmake_minimum_required(VERSION 3.0)
project(REACTPHYSICS3D CXX)

# Release by default
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

# Where to build the library
set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/build")

enable_testing()

# ReactPhysics3D Options
option(RP3D_BUILD_TESTS "Select this if you want to build the tests" OFF)
option(RP3D_BUILD_TESTBED "Select this if you want to build the testbed application" OFF)
option(RP3D_ENABLE_PROFILER "Select this if you want to enable the built in profiler" OFF)
option(RP3D_DOUBLE_PRECISION "Select this if you want to use double precision floats" OFF)
option(RP3D_SHARED_LIB "Select this if you want to build a shared library instead" OFF)

if(RP3D_ENABLE_PROFILER)
    add_definitions(-DRP3D_ENABLE_PROFILER)
endif()

if(RP3D_DOUBLE_PRECISION)
    add_definitions(-DRP3D_DOUBLE_PRECISION)
endif()

# Enable compiler warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Ensure that the compiler supports C++11 and enable it
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    include(CheckCXXCompilerFlag)
    check_cxx_compiler_flag("-std=c++11" COMPILER_SUPPORTS_CXX11)
    if(COMPILER_SUPPORTS_CXX11)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    else()
        message("The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
    endif()
endif()

set(SRCDIR "${PROJECT_SOURCE_DIR}/source")
set(INCDIR "${PROJECT_SOURCE_DIR}/include/rp3d")

# Source files
set(REACTPHYSICS3D_SOURCES
    "${INCDIR}/configuration.hpp"
    "${INCDIR}/decimal.hpp"
    "${INCDIR}/reactphysics3d.hpp"
    "${INCDIR}/body/Body.hpp"
    "${SRCDIR}/body/Body.cpp"
    "${INCDIR}/body/CollisionBody.hpp"
    "${SRCDIR}/body/CollisionBody.cpp"
    "${INCDIR}/body/RigidBody.hpp"
    "${SRCDIR}/body/RigidBody.cpp"
    "${INCDIR}/collision/broadphase/BroadPhaseAlgorithm.hpp"
    "${SRCDIR}/collision/broadphase/BroadPhaseAlgorithm.cpp"
    "${INCDIR}/collision/broadphase/DynamicAABBTree.hpp"
    "${SRCDIR}/collision/broadphase/DynamicAABBTree.cpp"
    "${INCDIR}/collision/narrowphase/CollisionDispatch.hpp"
    "${INCDIR}/collision/narrowphase/DefaultCollisionDispatch.hpp"
    "${SRCDIR}/collision/narrowphase/DefaultCollisionDispatch.cpp"
    "${INCDIR}/collision/narrowphase/EPA/EdgeEPA.hpp"
    "${SRCDIR}/collision/narrowphase/EPA/EdgeEPA.cpp"
    "${INCDIR}/collision/narrowphase/EPA/EPAAlgorithm.hpp"
    "${SRCDIR}/collision/narrowphase/EPA/EPAAlgorithm.cpp"
    "${INCDIR}/collision/narrowphase/EPA/TriangleEPA.hpp"
    "${SRCDIR}/collision/narrowphase/EPA/TriangleEPA.cpp"
    "${INCDIR}/collision/narrowphase/EPA/TrianglesStore.hpp"
    "${SRCDIR}/collision/narrowphase/EPA/TrianglesStore.cpp"
    "${INCDIR}/collision/narrowphase/GJK/Simplex.hpp"
    "${SRCDIR}/collision/narrowphase/GJK/Simplex.cpp"
    "${INCDIR}/collision/narrowphase/GJK/GJKAlgorithm.hpp"
    "${SRCDIR}/collision/narrowphase/GJK/GJKAlgorithm.cpp"
    "${INCDIR}/collision/narrowphase/NarrowPhaseAlgorithm.hpp"
    "${SRCDIR}/collision/narrowphase/NarrowPhaseAlgorithm.cpp"
    "${INCDIR}/collision/narrowphase/SphereVsSphereAlgorithm.hpp"
    "${SRCDIR}/collision/narrowphase/SphereVsSphereAlgorithm.cpp"
    "${INCDIR}/collision/narrowphase/ConcaveVsConvexAlgorithm.hpp"
    "${SRCDIR}/collision/narrowphase/ConcaveVsConvexAlgorithm.cpp"
    "${INCDIR}/collision/shapes/AABB.hpp"
    "${SRCDIR}/collision/shapes/AABB.cpp"
    "${INCDIR}/collision/shapes/ConvexShape.hpp"
    "${SRCDIR}/collision/shapes/ConvexShape.cpp"
    "${INCDIR}/collision/shapes/ConcaveShape.hpp"
    "${SRCDIR}/collision/shapes/ConcaveShape.cpp"
    "${INCDIR}/collision/shapes/BoxShape.hpp"
    "${SRCDIR}/collision/shapes/BoxShape.cpp"
    "${INCDIR}/collision/shapes/CapsuleShape.hpp"
    "${SRCDIR}/collision/shapes/CapsuleShape.cpp"
    "${INCDIR}/collision/shapes/CollisionShape.hpp"
    "${SRCDIR}/collision/shapes/CollisionShape.cpp"
    "${INCDIR}/collision/shapes/ConeShape.hpp"
    "${SRCDIR}/collision/shapes/ConeShape.cpp"
    "${INCDIR}/collision/shapes/ConvexMeshShape.hpp"
    "${SRCDIR}/collision/shapes/ConvexMeshShape.cpp"
    "${INCDIR}/collision/shapes/CylinderShape.hpp"
    "${SRCDIR}/collision/shapes/CylinderShape.cpp"
    "${INCDIR}/collision/shapes/SphereShape.hpp"
    "${SRCDIR}/collision/shapes/SphereShape.cpp"
    "${INCDIR}/collision/shapes/TriangleShape.hpp"
    "${SRCDIR}/collision/shapes/TriangleShape.cpp"
    "${INCDIR}/collision/shapes/ConcaveMeshShape.hpp"
    "${SRCDIR}/collision/shapes/ConcaveMeshShape.cpp"
    "${INCDIR}/collision/shapes/HeightFieldShape.hpp"
    "${SRCDIR}/collision/shapes/HeightFieldShape.cpp"
    "${INCDIR}/collision/RaycastInfo.hpp"
    "${SRCDIR}/collision/RaycastInfo.cpp"
    "${INCDIR}/collision/ProxyShape.hpp"
    "${SRCDIR}/collision/ProxyShape.cpp"
    "${INCDIR}/collision/TriangleVertexArray.hpp"
    "${SRCDIR}/collision/TriangleVertexArray.cpp"
    "${INCDIR}/collision/TriangleMesh.hpp"
    "${SRCDIR}/collision/TriangleMesh.cpp"
    "${INCDIR}/collision/CollisionDetection.hpp"
    "${SRCDIR}/collision/CollisionDetection.cpp"
    "${INCDIR}/collision/CollisionShapeInfo.hpp"
    "${INCDIR}/collision/ContactManifold.hpp"
    "${SRCDIR}/collision/ContactManifold.cpp"
    "${INCDIR}/collision/ContactManifoldSet.hpp"
    "${SRCDIR}/collision/ContactManifoldSet.cpp"
    "${INCDIR}/constraint/BallAndSocketJoint.hpp"
    "${SRCDIR}/constraint/BallAndSocketJoint.cpp"
    "${INCDIR}/constraint/ContactPoint.hpp"
    "${SRCDIR}/constraint/ContactPoint.cpp"
    "${INCDIR}/constraint/FixedJoint.hpp"
    "${SRCDIR}/constraint/FixedJoint.cpp"
    "${INCDIR}/constraint/HingeJoint.hpp"
    "${SRCDIR}/constraint/HingeJoint.cpp"
    "${INCDIR}/constraint/Joint.hpp"
    "${SRCDIR}/constraint/Joint.cpp"
    "${INCDIR}/constraint/SliderJoint.hpp"
    "${SRCDIR}/constraint/SliderJoint.cpp"
    "${INCDIR}/engine/CollisionWorld.hpp"
    "${SRCDIR}/engine/CollisionWorld.cpp"
    "${INCDIR}/engine/ConstraintSolver.hpp"
    "${SRCDIR}/engine/ConstraintSolver.cpp"
    "${INCDIR}/engine/ContactSolver.hpp"
    "${SRCDIR}/engine/ContactSolver.cpp"
    "${INCDIR}/engine/DynamicsWorld.hpp"
    "${SRCDIR}/engine/DynamicsWorld.cpp"
    "${INCDIR}/engine/EventListener.hpp"
    "${INCDIR}/engine/Impulse.hpp"
    "${INCDIR}/engine/Island.hpp"
    "${SRCDIR}/engine/Island.cpp"
    "${INCDIR}/engine/Material.hpp"
    "${SRCDIR}/engine/Material.cpp"
    "${INCDIR}/engine/OverlappingPair.hpp"
    "${SRCDIR}/engine/OverlappingPair.cpp"
    "${INCDIR}/engine/Profiler.hpp"
    "${SRCDIR}/engine/Profiler.cpp"
    "${INCDIR}/engine/Timer.hpp"
    "${SRCDIR}/engine/Timer.cpp"
    "${INCDIR}/mathematics/mathematics.hpp"
    "${INCDIR}/mathematics/mathematics_functions.hpp"
    "${SRCDIR}/mathematics/mathematics_functions.cpp"
    "${INCDIR}/mathematics/Matrix2x2.hpp"
    "${SRCDIR}/mathematics/Matrix2x2.cpp"
    "${INCDIR}/mathematics/Matrix3x3.hpp"
    "${SRCDIR}/mathematics/Matrix3x3.cpp"
    "${INCDIR}/mathematics/Quaternion.hpp"
    "${SRCDIR}/mathematics/Quaternion.cpp"
    "${INCDIR}/mathematics/Transform.hpp"
    "${SRCDIR}/mathematics/Transform.cpp"
    "${INCDIR}/mathematics/Vector2.hpp"
    "${SRCDIR}/mathematics/Vector2.cpp"
    "${INCDIR}/mathematics/Vector3.hpp"
    "${INCDIR}/mathematics/Ray.hpp"
    "${SRCDIR}/mathematics/Vector3.cpp"
    "${INCDIR}/memory/MemoryAllocator.hpp"
    "${SRCDIR}/memory/MemoryAllocator.cpp"
    "${INCDIR}/memory/Stack.hpp"
)

# Include ReactPhysics3D headers
include_directories("${PROJECT_SOURCE_DIR}/include")

if(NOT RP3D_SHARED_LIB)
    # Create a static library target
    add_library(reactphysics3d STATIC ${REACTPHYSICS3D_SOURCES})
else()
    # Create a shared library target
    add_library(reactphysics3d SHARED ${REACTPHYSICS3D_SOURCES})
endif()

# Add install target if on Linux
if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    install(TARGETS reactphysics3d DESTINATION "lib")
    install(DIRECTORY ${INCDIR} DESTINATION "include")
endif()


if(RP3D_BUILD_TESTS)
   add_subdirectory("tests")
endif()

if(RP3D_BUILD_TESTBED)
   add_subdirectory("testbed")
endif()
