#ifndef _RTX_HITABLE_HITABLE_H_
#define _RTX_HITABLE_HITABLE_H_ 

#include <CppUtil/RTX/AABB.h>

#include <CppUtil/RTX/HitableVisitor.h>
#include <CppUtil/RTX/HitRecord.h>

#define HITABLE_SETUP(CLASS) \
HEAP_OBJ_SETUP(CLASS)\
public:\
virtual void Accept(HitableVisitor::Ptr hitableVisitor) const{\
	hitableVisitor->Visit(CThis());\
}


namespace RTX {
	class Ray;
	class Material;

	struct HitRst {
		HitRst(bool hit = false) : hit(hit), isMatCoverable(true), material(NULL) { }

		bool hit;
		HitRecord record;
		CppUtil::Basic::CPtr<Material> material;
		bool isMatCoverable;
		//------------
		static const HitRst InValid;
	};

	class Hitable : public CppUtil::Basic::HeapObj{
		HEAP_OBJ_SETUP(Hitable)
	public:
		Hitable(CppUtil::Basic::CPtr<Material> material = NULL);

		const CppUtil::Basic::CPtr<Material> GetMat() const { return material; };
		bool IsMatCoverable() const { return isMatCoverable; }

		virtual HitRst RayIn(CppUtil::Basic::Ptr<Ray> & ray) const = 0;
		virtual const AABB GetBoundingBox() const = 0;
		virtual void Accept(HitableVisitor::Ptr hitableVisitor) const = 0;
	private:
		CppUtil::Basic::CPtr<Material> material;
		bool isMatCoverable;
	};
}
#endif