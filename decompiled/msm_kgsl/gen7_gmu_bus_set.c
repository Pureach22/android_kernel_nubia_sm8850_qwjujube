__int64 __fastcall gen7_gmu_bus_set(__int64 a1, unsigned int a2, unsigned int a3)
{
  unsigned int v6; // w21
  unsigned int v7; // w20
  bool v8; // w23
  _BOOL4 v9; // w22
  __int64 result; // x0

  if ( **(_DWORD **)(a1 + 14264) >> 1 != 230528 )
    kgsl_icc_set_tag(a1 + 8832);
  if ( *(_DWORD *)(a1 + 10404) == a2 )
    v6 = 255;
  else
    v6 = a2;
  v7 = 0xFFFF;
  if ( *(_DWORD *)(a1 + 10464) == a3 || (v7 = a3) != 0 )
  {
LABEL_10:
    v8 = v6 == 255;
    v9 = v7 == 0xFFFF;
    if ( v7 == 0xFFFF && v6 == 255 )
      return 0;
    goto LABEL_14;
  }
  if ( (*(_BYTE *)(a1 + 24032) & 1) != 0 )
  {
    v7 = 0xFFFF;
    goto LABEL_10;
  }
  v9 = 0;
  v7 = 0;
  v8 = v6 == 255;
LABEL_14:
  result = gen7_gmu_dcvs_set(a1, 255, v6, v7);
  if ( (_DWORD)result )
    return result;
  if ( !v8 )
    *(_DWORD *)(a1 + 10404) = v6;
  if ( !v9 )
  {
    if ( (*(_BYTE *)(a1 + 24032) & 1) == 0 )
      icc_set_bw(*(_QWORD *)(a1 + 10456), 1000 * v7, 0);
    *(_DWORD *)(a1 + 10464) = v7;
  }
  return 0;
}
