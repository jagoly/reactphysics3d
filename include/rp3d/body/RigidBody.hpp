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

#ifndef REACTPHYSICS3D_RIGID_BODY_H
#define REACTPHYSICS3D_RIGID_BODY_H

#include <rp3d/body/CollisionBody.hpp>
#include <rp3d/engine/Material.hpp>
#include <rp3d/mathematics/mathematics.hpp>
#include <rp3d/memory/MemoryAllocator.hpp>

namespace reactphysics3d {

// Class declarations
struct JointListElement;
class Joint;
class DynamicsWorld;

// Class RigidBody
/**
 * This class represents a rigid body of the physics
 * engine. A rigid body is a non-deformable body that
 * has a constant mass. This class inherits from the
 * CollisionBody class.
  */
class RigidBody : public CollisionBody {

    protected :

        // -------------------- Attributes -------------------- //

        /// Intial mass of the body
        decimal mInitMass;

        /// Center of mass of the body in local-space coordinates.
        /// The center of mass can therefore be different from the body origin
        Vector3 mCenterOfMassLocal;

        /// Center of mass of the body in world-space coordinates
        Vector3 mCenterOfMassWorld;

        /// Linear velocity of the body
        Vector3 mLinearVelocity;

        /// Angular velocity of the body
        Vector3 mAngularVelocity;

        /// Current external force on the body
        Vector3 mExternalForce;

        /// Current external torque on the body
        Vector3 mExternalTorque;

        /// Local inertia tensor of the body (in local-space) with respect to the
        /// center of mass of the body
        Matrix3x3 mInertiaTensorLocal;

        /// Inverse of the inertia tensor of the body
        Matrix3x3 mInertiaTensorLocalInverse;

        /// Inverse of the mass of the body
        decimal mMassInverse;

        /// True if the gravity needs to be applied to this rigid body
        bool mIsGravityEnabled;

        /// Material properties of the rigid body
        Material mMaterial;

        /// Linear velocity damping factor
        decimal mLinearDamping;

        /// Angular velocity damping factor
        decimal mAngularDamping;

        /// First element of the linked list of joints involving this body
        JointListElement* mJointsList;        

        // -------------------- Methods -------------------- //

        /// Private copy-constructor
        RigidBody(const RigidBody& body);

        /// Private assignment operator
        RigidBody& operator=(const RigidBody& body);

        /// Remove a joint from the joints list
        void removeJointFromJointsList(MemoryAllocator& memoryAllocator, const Joint* joint);

        /// Update the transform of the body after a change of the center of mass
        void updateTransformWithCenterOfMass();

        /// Update the broad-phase state for this body (because it has moved for instance)
        virtual void updateBroadPhaseState() const;

    public :

        // -------------------- Methods -------------------- //

        /// Constructor
        RigidBody(const Transform& transform, CollisionWorld& world, bodyindex id);

        /// Destructor
        virtual ~RigidBody();

        /// Set the type of the body (static, kinematic or dynamic)
        void setType(BodyType type);

        /// Set the current position and orientation
        virtual void setTransform(const Transform& transform);

        /// Return the mass of the body
        decimal getMass() const;

        /// Return the linear velocity
        Vector3 getLinearVelocity() const;

        /// Set the linear velocity of the body.
        void setLinearVelocity(const Vector3& linearVelocity);

        /// Return the angular velocity
        Vector3 getAngularVelocity() const;

        /// Set the angular velocity.
        void setAngularVelocity(const Vector3& angularVelocity);

        /// Set the variable to know whether or not the body is sleeping
        virtual void setIsSleeping(bool isSleeping);

        /// Return the local inertia tensor of the body (in body coordinates)
        const Matrix3x3& getInertiaTensorLocal() const;

        /// Set the local inertia tensor of the body (in body coordinates)
        void setInertiaTensorLocal(const Matrix3x3& inertiaTensorLocal);

        /// Set the local center of mass of the body (in local-space coordinates)
        void setCenterOfMassLocal(const Vector3& centerOfMassLocal);

        /// Set the mass of the rigid body
        void setMass(decimal mass);

        /// Return the inertia tensor in world coordinates.
        Matrix3x3 getInertiaTensorWorld() const;

        /// Return the inverse of the inertia tensor in world coordinates.
        Matrix3x3 getInertiaTensorInverseWorld() const;

        /// Return true if the gravity needs to be applied to this rigid body
        bool isGravityEnabled() const;

        /// Set the variable to know if the gravity is applied to this rigid body
        void enableGravity(bool isEnabled);

        /// Return a reference to the material properties of the rigid body
        Material& getMaterial();

        /// Set a new material for this rigid body
        void setMaterial(const Material& material);

        /// Return the linear velocity damping factor
        decimal getLinearDamping() const;

        /// Set the linear damping factor
        void setLinearDamping(decimal linearDamping);

        /// Return the angular velocity damping factor
        decimal getAngularDamping() const;

        /// Set the angular damping factor
        void setAngularDamping(decimal angularDamping);

        /// Return the first element of the linked list of joints involving this body
        const JointListElement* getJointsList() const;

        /// Return the first element of the linked list of joints involving this body
        JointListElement* getJointsList();

        /// Apply an external force to the body at its center of mass.
        void applyForceToCenterOfMass(const Vector3& force);

        /// Apply an external force to the body at a given point (in world-space coordinates).
        void applyForce(const Vector3& force, const Vector3& point);

        /// Apply an external torque to the body.
        void applyTorque(const Vector3& torque);

        /// Add a collision shape to the body.
        virtual ProxyShape* addCollisionShape(CollisionShape* collisionShape,
                                              const Transform& transform,
                                              decimal mass);

        /// Remove a collision shape from the body
        virtual void removeCollisionShape(const ProxyShape* proxyShape);

        /// Recompute the center of mass, total mass and inertia tensor of the body using all
        /// the collision shapes attached to the body.
        void recomputeMassInformation();

        // -------------------- Friendship -------------------- //

        friend class DynamicsWorld;
        friend class ContactSolver;
        friend class BallAndSocketJoint;
        friend class SliderJoint;
        friend class HingeJoint;
        friend class FixedJoint;
};

// Method that return the mass of the body
/**
 * @return The mass (in kilograms) of the body
 */
inline decimal RigidBody::getMass() const {
    return mInitMass;
}

// Return the linear velocity
/**
 * @return The linear velocity vector of the body
 */
inline Vector3 RigidBody::getLinearVelocity() const {
    return mLinearVelocity;
}

// Return the angular velocity of the body
/**
 * @return The angular velocity vector of the body
 */
inline Vector3 RigidBody::getAngularVelocity() const {
    return mAngularVelocity;
}

// Return the local inertia tensor of the body (in local-space coordinates)
/**
 * @return The 3x3 inertia tensor matrix of the body (in local-space coordinates)
 */
inline const Matrix3x3& RigidBody::getInertiaTensorLocal() const {
    return mInertiaTensorLocal;
}

// Return the inertia tensor in world coordinates.
/// The inertia tensor I_w in world coordinates is computed
/// with the local inertia tensor I_b in body coordinates
/// by I_w = R * I_b * R^T
/// where R is the rotation matrix (and R^T its transpose) of
/// the current orientation quaternion of the body
/**
 * @return The 3x3 inertia tensor matrix of the body in world-space coordinates
 */
inline Matrix3x3 RigidBody::getInertiaTensorWorld() const {

    // Compute and return the inertia tensor in world coordinates
    return mTransform.getOrientation().getMatrix() * mInertiaTensorLocal *
           mTransform.getOrientation().getMatrix().getTranspose();
}

// Return the inverse of the inertia tensor in world coordinates.
/// The inertia tensor I_w in world coordinates is computed with the
/// local inverse inertia tensor I_b^-1 in body coordinates
/// by I_w = R * I_b^-1 * R^T
/// where R is the rotation matrix (and R^T its transpose) of the
/// current orientation quaternion of the body
/**
 * @return The 3x3 inverse inertia tensor matrix of the body in world-space
 *         coordinates
 */
inline Matrix3x3 RigidBody::getInertiaTensorInverseWorld() const {

    // TODO : DO NOT RECOMPUTE THE MATRIX MULTIPLICATION EVERY TIME. WE NEED TO STORE THE
    //        INVERSE WORLD TENSOR IN THE CLASS AND UPLDATE IT WHEN THE ORIENTATION OF THE BODY CHANGES

    // Compute and return the inertia tensor in world coordinates
    return mTransform.getOrientation().getMatrix() * mInertiaTensorLocalInverse *
           mTransform.getOrientation().getMatrix().getTranspose();
}

// Return true if the gravity needs to be applied to this rigid body
/**
 * @return True if the gravity is applied to the body
 */
inline bool RigidBody::isGravityEnabled() const {
    return mIsGravityEnabled;
}

// Set the variable to know if the gravity is applied to this rigid body
/**
 * @param isEnabled True if you want the gravity to be applied to this body
 */
inline void RigidBody::enableGravity(bool isEnabled) {
    mIsGravityEnabled = isEnabled;
}

// Return a reference to the material properties of the rigid body
/**
 * @return A reference to the material of the body
 */
inline Material& RigidBody::getMaterial() {
    return mMaterial;
}

// Set a new material for this rigid body
/**
 * @param material The material you want to set to the body
 */
inline void RigidBody::setMaterial(const Material& material) {
    mMaterial = material;
}

// Return the linear velocity damping factor
/**
 * @return The linear damping factor of this body
 */
inline decimal RigidBody::getLinearDamping() const {
    return mLinearDamping;
}

// Set the linear damping factor. This is the ratio of the linear velocity
// that the body will lose every at seconds of simulation.
/**
 * @param linearDamping The linear damping factor of this body
 */
inline void RigidBody::setLinearDamping(decimal linearDamping) {
    assert(linearDamping >= decimal(0.0));
    mLinearDamping = linearDamping;
}

// Return the angular velocity damping factor
/**
 * @return The angular damping factor of this body
 */
inline decimal RigidBody::getAngularDamping() const {
    return mAngularDamping;
}

// Set the angular damping factor. This is the ratio of the angular velocity
// that the body will lose at every seconds of simulation.
/**
 * @param angularDamping The angular damping factor of this body
 */
inline void RigidBody::setAngularDamping(decimal angularDamping) {
    assert(angularDamping >= decimal(0.0));
    mAngularDamping = angularDamping;
}

// Return the first element of the linked list of joints involving this body
/**
 * @return The first element of the linked-list of all the joints involving this body
 */
inline const JointListElement* RigidBody::getJointsList() const {
    return mJointsList;
}

// Return the first element of the linked list of joints involving this body
/**
 * @return The first element of the linked-list of all the joints involving this body
 */
inline JointListElement* RigidBody::getJointsList() {
    return mJointsList;
}

// Set the variable to know whether or not the body is sleeping
inline void RigidBody::setIsSleeping(bool isSleeping) {

    if (isSleeping) {
        mLinearVelocity.setToZero();
        mAngularVelocity.setToZero();
        mExternalForce.setToZero();
        mExternalTorque.setToZero();
    }

    Body::setIsSleeping(isSleeping);
}

// Apply an external force to the body at its center of mass.
/// If the body is sleeping, calling this method will wake it up. Note that the
/// force will we added to the sum of the applied forces and that this sum will be
/// reset to zero at the end of each call of the DynamicsWorld::update() method.
/// You can only apply a force to a dynamic body otherwise, this method will do nothing.
/**
 * @param force The external force to apply on the center of mass of the body
 */
inline void RigidBody::applyForceToCenterOfMass(const Vector3& force) {

    // If it is not a dynamic body, we do nothing
    if (mType != DYNAMIC) return;

    // Awake the body if it was sleeping
    if (mIsSleeping) {
        setIsSleeping(false);
    }

    // Add the force
    mExternalForce += force;
}

// Apply an external force to the body at a given point (in world-space coordinates).
/// If the point is not at the center of mass of the body, it will also
/// generate some torque and therefore, change the angular velocity of the body.
/// If the body is sleeping, calling this method will wake it up. Note that the
/// force will we added to the sum of the applied forces and that this sum will be
/// reset to zero at the end of each call of the DynamicsWorld::update() method.
/// You can only apply a force to a dynamic body otherwise, this method will do nothing.
/**
 * @param force The force to apply on the body
 * @param point The point where the force is applied (in world-space coordinates)
 */
inline void RigidBody::applyForce(const Vector3& force, const Vector3& point) {

    // If it is not a dynamic body, we do nothing
    if (mType != DYNAMIC) return;

    // Awake the body if it was sleeping
    if (mIsSleeping) {
        setIsSleeping(false);
    }

    // Add the force and torque
    mExternalForce += force;
    mExternalTorque += (point - mCenterOfMassWorld).cross(force);
}

// Apply an external torque to the body.
/// If the body is sleeping, calling this method will wake it up. Note that the
/// force will we added to the sum of the applied torques and that this sum will be
/// reset to zero at the end of each call of the DynamicsWorld::update() method.
/// You can only apply a force to a dynamic body otherwise, this method will do nothing.
/**
 * @param torque The external torque to apply on the body
 */
inline void RigidBody::applyTorque(const Vector3& torque) {

    // If it is not a dynamic body, we do nothing
    if (mType != DYNAMIC) return;

    // Awake the body if it was sleeping
    if (mIsSleeping) {
        setIsSleeping(false);
    }

    // Add the torque
    mExternalTorque += torque;
}

/// Update the transform of the body after a change of the center of mass
inline void RigidBody::updateTransformWithCenterOfMass() {

    // Translate the body according to the translation of the center of mass position
    mTransform.setPosition(mCenterOfMassWorld - mTransform.getOrientation() * mCenterOfMassLocal);
}

}

#endif
