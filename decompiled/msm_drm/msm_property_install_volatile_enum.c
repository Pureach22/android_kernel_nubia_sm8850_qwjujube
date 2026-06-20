__int64 __fastcall msm_property_install_volatile_enum(
        __int64 a1,
        const char *a2,
        int a3,
        int a4,
        __int64 a5,
        unsigned int a6,
        unsigned int a7,
        unsigned int a8)
{
  return msm_property_install_enum_helper(a1, a2, a3, a4, a5, a6, a7, a8, 1);
}
