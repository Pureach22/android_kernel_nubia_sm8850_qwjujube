__int64 __fastcall msm_property_install_volatile_range(
        __int64 a1,
        const char *a2,
        unsigned int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        unsigned int a7)
{
  return msm_property_install_integer(a1, a2, a3, a4, a5, a6, a7, 1);
}
