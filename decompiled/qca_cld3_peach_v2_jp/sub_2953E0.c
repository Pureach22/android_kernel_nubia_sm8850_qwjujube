__int64 __fastcall sub_2953E0(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        float a9)
{
  int v9; // s29

  *(_DWORD *)a3 = v9;
  *(float *)(a3 + 4) = a9;
  return cm_ext_hdl_destroy(a1, a2, a3 - 116);
}
