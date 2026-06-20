__int64 __fastcall target_if_sops_stop_spectral_scan(
        __int64 *a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v12; // w8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  unsigned int v22; // w21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  void (__fastcall *v31)(__int64 *, __int64 *, __int64); // x9
  unsigned __int8 v32[4]; // [xsp+0h] [xbp-10h] BYREF
  unsigned __int8 v33[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v34; // [xsp+8h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33[0] = 0;
  v32[0] = 0;
  v12 = target_if_spectral_info_read((__int64)a1, a2, 1, v32, 1, a3, a4, a5, a6, a7, a8, a9, a10);
  result = 0xFFFFFFFFLL;
  if ( !v12 && v32[0] )
  {
    v22 = target_if_spectral_info_write(a1, a2, 0, v33, 1, v13, v14, v15, v16, v17, v18, v19, v20);
    LODWORD(result) = target_if_spectral_info_write(a1, a2, 1, v33, 1, v23, v24, v25, v26, v27, v28, v29, v30);
    result = (_DWORD)result ? (unsigned int)result : v22;
    if ( a2 == 1 && !(_DWORD)result )
    {
      v31 = (void (__fastcall *)(__int64 *, __int64 *, __int64))a1[12];
      *(__int64 *)((char *)a1 + 780) = 0;
      if ( *((_DWORD *)v31 - 1) != 2051770554 )
        __break(0x8229u);
      v31(a1, a1 + 90, 1);
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
