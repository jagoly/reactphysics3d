/********************************************************************************
* ReactPhysics3D physics library, http://www.reactphysics3d.com                 *
* Copyright (c) 2010-2016 Daniel Chappuis                                       *
*********************************************************************************
*                                                                               *
* This software is provided 'as-is', without any express or implied warranty.   *
* In no event will the authors be held liable for any damages arising from the  *
* use of this software.                                                         *
*                                                                               *
* Permission is granted to anyone to use this software for any purpose,         *
* including commercial applications, and to alter it and redistribute it        *
* freely, subject to the following restrictions:                                *
*                                                                               *
* 1. The origin of this software must not be misrepresented; you must not claim *
*    that you wrote the original software. If you use this software in a        *
*    product, an acknowledgment in the product documentation would be           *
*    appreciated but is not required.                                           *
*                                                                               *
* 2. Altered source versions must be plainly marked as such, and must not be    *
*    misrepresented as being the original software.                             *
*                                                                               *
* 3. This notice may not be removed or altered from any source distribution.    *
*                                                                               *
********************************************************************************/


/********************************************************************************
* ReactPhysics3D                                                                *
* Version 0.6.0                                                                 *
* http://www.reactphysics3d.com                                                 *
* Created by Daniel Chappuis                                                    *
* Modifications by James Gangur                                                 *
********************************************************************************/

#ifndef REACTPHYSICS3D_H
#define REACTPHYSICS3D_H

#include <rp3d/configuration.hpp>
#include <rp3d/mathematics/mathematics.hpp>
#include <rp3d/body/CollisionBody.hpp>
#include <rp3d/body/RigidBody.hpp>
#include <rp3d/engine/DynamicsWorld.hpp>
#include <rp3d/engine/CollisionWorld.hpp>
#include <rp3d/engine/Material.hpp>
#include <rp3d/engine/EventListener.hpp>
#include <rp3d/collision/shapes/CollisionShape.hpp>
#include <rp3d/collision/shapes/BoxShape.hpp>
#include <rp3d/collision/shapes/SphereShape.hpp>
#include <rp3d/collision/shapes/ConeShape.hpp>
#include <rp3d/collision/shapes/CylinderShape.hpp>
#include <rp3d/collision/shapes/CapsuleShape.hpp>
#include <rp3d/collision/shapes/ConvexMeshShape.hpp>
#include <rp3d/collision/shapes/ConcaveMeshShape.hpp>
#include <rp3d/collision/shapes/HeightFieldShape.hpp>
#include <rp3d/collision/shapes/AABB.hpp>
#include <rp3d/collision/ProxyShape.hpp>
#include <rp3d/collision/RaycastInfo.hpp>
#include <rp3d/collision/TriangleMesh.hpp>
#include <rp3d/collision/TriangleVertexArray.hpp>
#include <rp3d/constraint/BallAndSocketJoint.hpp>
#include <rp3d/constraint/SliderJoint.hpp>
#include <rp3d/constraint/HingeJoint.hpp>
#include <rp3d/constraint/FixedJoint.hpp>

/// Alias to the ReactPhysics3D namespace
namespace rp3d = reactphysics3d;

#endif
