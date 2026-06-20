__int64 __fastcall gen8_hwsched_bus_set(__int64 a1, unsigned int a2, unsigned int a3)
{
  unsigned int v4; // w20
  unsigned int v5; // w21
  bool v6; // w23
  _BOOL4 v7; // w22
  __int64 result; // x0

  v4 = 0xFFFF;
  if ( *(_DWORD *)(a1 + 10404) == a2 )
    v5 = 255;
  else
    v5 = a2;
  if ( *(_DWORD *)(a1 + 10464) == a3 || (v4 = a3) != 0 )
  {
LABEL_8:
    v6 = v5 == 255;
    v7 = v4 == 0xFFFF;
    if ( v4 == 0xFFFF && v5 == 255 )
      return 0;
    goto LABEL_12;
  }
  if ( (*(_BYTE *)(a1 + 24032) & 1) != 0 )
  {
    v4 = 0xFFFF;
    goto LABEL_8;
  }
  v7 = 0;
  v4 = 0;
  v6 = v5 == 255;
LABEL_12:
  result = gen8_hwsched_dcvs_set(a1, 255, v5, v4);
  if ( (_DWORD)result )
    return result;
  if ( !v6 )
  {
    gmu_core_scale_gmu_frequency(a1, v5);
    *(_DWORD *)(a1 + 10404) = v5;
  }
  if ( !v7 )
  {
    if ( (*(_BYTE *)(a1 + 24032) & 1) == 0 )
      icc_set_bw(*(_QWORD *)(a1 + 10456), 1000 * v4, 0);
    *(_DWORD *)(a1 + 10464) = v4;
  }
  return 0;
}
