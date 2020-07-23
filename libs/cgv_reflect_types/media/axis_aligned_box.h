#pragma once

#include <cgv_reflect_types/math/fvec.h>
#include <cgv/media/axis_aligned_box.h>
#include <cgv/reflect/reflect_extern.h>

namespace cgv {
	namespace reflect {
		namespace media {

/**
 * An axis aligned box, defined by to points: min and max
 */
template<typename T, cgv::type::uint32_type N>
struct axis_aligned_box : public cgv::media::axis_aligned_box<T,N>
{
	bool self_reflect(cgv::reflect::reflection_handler& rh) {
		return
			rh.reflect_member("minp", this->minp) &&
			rh.reflect_member("maxp", this->maxp);
	}
};

		}

#ifdef REFLECT_IN_CLASS_NAMESPACE
}} namespace cgv { namespace media {
#endif

template<typename T, cgv::type::uint32_type N>
cgv::reflect::extern_reflection_traits<cgv::media::axis_aligned_box<T,N>, cgv::reflect::media::axis_aligned_box<T,N> > get_reflection_traits(const cgv::media::axis_aligned_box<T,N>&) { return cgv::reflect::extern_reflection_traits<cgv::media::axis_aligned_box<T,N>, cgv::reflect::media::axis_aligned_box<T,N> >(); }

	}
}

