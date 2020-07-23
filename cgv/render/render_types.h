#pragma once

#include <cgv/math/fvec.h>
#include <cgv/math/fmat.h>
#include <cgv/math/vec.h>
#include <cgv/math/mat.h>
#include <cgv/math/quaternion.h>
#include <cgv/media/color.h>
#include <cgv/media/axis_aligned_box.h>

namespace cgv {
	namespace render {

		struct render_types
		{
			/// declare rgb color type
			typedef cgv::media::color<float, cgv::media::RGB> rgb;
			/// declare rgba color type
			typedef cgv::media::color<float, cgv::media::RGB, cgv::media::OPACITY> rgba;
			/// declare rgb color type
			typedef cgv::media::color<cgv::type::uint8_type, cgv::media::RGB> rgb8;
			/// declare rgba color type
			typedef cgv::media::color<cgv::type::uint8_type, cgv::media::RGB, cgv::media::OPACITY> rgba8;
			/// declare type of 2d vectors
			typedef cgv::math::fvec<float, 2> vec2;
			/// declare type of 3d vectors
			typedef cgv::math::fvec<float, 3> vec3;
			/// declare type of homogeneous vectors
			typedef cgv::math::fvec<float, 4> vec4;
			/// declare type of vector with varying dimension
			typedef cgv::math::vec<float> vecn;
			/// declare type of 2x2 matrices
			typedef cgv::math::fmat<float, 2, 2> mat2;
			/// declare type of 3x3 matrices
			typedef cgv::math::fmat<float, 3, 3> mat3;
			/// declare type of 4x4 matrices
			typedef cgv::math::fmat<float, 4, 4> mat4;
			/// declare type of 3x4 matrices which are often used to store a pose
			typedef cgv::math::fmat<float, 3, 4> mat34;
			/// declare type of matrices of varying dimensions
			typedef cgv::math::mat<float> matn;
			/// declare type of 2d vectors
			typedef cgv::math::fvec<double, 2> dvec2;
			/// declare type of 3d vectors
			typedef cgv::math::fvec<double, 3> dvec3;
			/// declare type of homogeneous vectors
			typedef cgv::math::fvec<double, 4> dvec4;
			/// declare type of vector with varying dimension
			typedef cgv::math::vec<double> dvecn;
			/// declare type of 2x2 matrices
			typedef cgv::math::fmat<double, 2, 2> dmat2;
			/// declare type of 3x3 matrices
			typedef cgv::math::fmat<double, 3, 3> dmat3;
			/// declare type of 4x4 matrices
			typedef cgv::math::fmat<double, 4, 4> dmat4;
			/// declare type of 3x4 matrices which are often used to store a pose
			typedef cgv::math::fmat<double, 3, 4> dmat34;
			/// declare type of matrices of varying dimensions
			typedef cgv::math::mat<double> dmatn;
			/// declare type of 2d boxes
			typedef cgv::media::axis_aligned_box<float, 2> box2;
			/// declare type of 3d boxes
			typedef cgv::media::axis_aligned_box<float, 3> box3;
			/// declare type of 4d boxes
			typedef cgv::media::axis_aligned_box<float, 4> box4;
			/// declare type of 2d boxes
			typedef cgv::media::axis_aligned_box<double, 2> dbox2;
			/// declare type of 3d boxes
			typedef cgv::media::axis_aligned_box<double, 3> dbox3;
			/// declare type of 4d boxes
			typedef cgv::media::axis_aligned_box<double, 4> dbox4;
			/// declare type of quaternion
			typedef cgv::math::quaternion<float> quat;
			/// declare type of double quaternion
			typedef cgv::math::quaternion<double> dquat;
			/// declare type of 2d integer vectors
			typedef cgv::math::fvec<int32_t, 2> ivec2;
			/// declare type of 3d integer vectors
			typedef cgv::math::fvec<int32_t, 3> ivec3;
			/// declare type of 4d integer vectors
			typedef cgv::math::fvec<int32_t, 4> ivec4;
			/// declare type of 2d unsigned integer vectors
			typedef cgv::math::fvec<uint32_t, 2> uvec2;
			/// declare type of 3d unsigned integer vectors
			typedef cgv::math::fvec<uint32_t, 3> uvec3;
			/// declare type of 4d unsigned integer vectors
			typedef cgv::math::fvec<uint32_t, 4> uvec4;
		};

	}
}