__int64 __fastcall sub_20F5C4(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 _X7)
{
  __asm { STZ2G           X7, [X23,#0x540] }
  return msm_property_install_volatile_enum(a1, a2, a3, a4, a5, a6, a7, _X7);
}
