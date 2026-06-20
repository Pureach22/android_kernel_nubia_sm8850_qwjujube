__int64 sub_132B9C()
{
  _ReadStatusReg(TPIDR_EL2);
  return kgsl_set_smmu_aperture();
}
