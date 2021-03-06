#ifndef _LIGHT_SOURCE_H_
#define _LIGHT_SOURCE_H_

#include "Primitive.h"

class LightSource : public Primitive {
public:
    int light_num;
    float intensity;
    Primitive* wrapped;


    // methods
    LightSource(Primitive* wrappee,float intensity);
    LightSource(const LightSource& other);
    LightSource& operator= (const LightSource& other);
    virtual ~LightSource();

    // LightSource methods
    jVec3 getDirection(jVec3& hitPoint);
    jVec3 getEmmitance();
    bool isDirectional();

    // samples for soft-shadowing..
    bool isAreaLightSource();
    void setIsAreaLightSource(bool value);
    void generateSamples(int rows, int cols);
    jVec3 getSamplePoint(int i);

    // from Primitive
    virtual void draw(jMat4& transform);
    virtual bool intersects(Ray& ray,HitRecord& rs, jMat4& transform);
    virtual jVec3 getNormal(jVec3& hitPoint,jMat4& transform,HitRecord hit);
    virtual jVec3 getOrigin();
    virtual void flatten(jMat4& transform);
    virtual LightSource* clone() const;

protected:
    std::vector<jVec3> _sample_points;
    bool _is_area_light_source;
};

#endif
