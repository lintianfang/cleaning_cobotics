#pragma once

#include "fltk_gui_group.h"
#include "DockableGroup.h"
#include "lib_begin.h"

/** has one central child and an arbitrary number of children that can dock to the north, east, south or west 
    border in an arbitrary order. */
class fltk_dockable_group : public cgv::gui::gui_group, public fltk_gui_group
{
protected:
	DockableGroup* group;
public:
	/// construct from width, height and name
	fltk_dockable_group(int x, int y, int w, int h, const std::string& _name);
	/// destruct group realization
	~fltk_dockable_group();
	/// return the type name
	std::string get_type_name() const { return "fltk_dockable_group"; }
	/// only uses the implementation of fltk_base
	std::string get_property_declarations();
	/// abstract interface for the setter
	bool set_void(const std::string& property, const std::string& value_type, const void* value_ptr);
	/// abstract interface for the getter
	bool get_void(const std::string& property, const std::string& value_type, void* value_ptr);
	/// return a fltk::Widget pointer that can be cast into a fltk::Group
	void* get_user_data() const;
	/// put default sizes into dimension fields and set inner_group to be active
	void prepare_new_element(cgv::gui::gui_group_ptr ggp, int& x, int& y, int& w, int& h);
	/// align last element and add element to group
	void finalize_new_element(cgv::gui::gui_group_ptr ggp, const std::string& align, cgv::base::base_ptr element);
	/// remove all elements of the vector that point to child, return the number of removed children
	unsigned int remove_child(base_ptr child) { return static_cast<fltk_gui_group*>(this)->remove_child(cgv::gui::gui_group_ptr(this), child); }
	/// remove all children
	void remove_all_children() { return static_cast<fltk_gui_group*>(this)->remove_all_children(cgv::gui::gui_group_ptr(this)); }
};

/// ref counted pointer to fltk_dockable_group
typedef cgv::data::ref_ptr<fltk_dockable_group> fltk_dockable_group_ptr;

#ifdef WIN32
CGV_TEMPLATE template class CGV_API cgv::data::ref_ptr<fltk_dockable_group>;
#endif

#include <cgv/config/lib_end.h>
