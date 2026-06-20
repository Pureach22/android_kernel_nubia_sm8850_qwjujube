__int64 __fastcall sub_20DBD8(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x21

  *(_QWORD *)(a8 + 41) = v8;
  return msm_gem_map_vma(a1, a2, a3, a4, a5);
}
