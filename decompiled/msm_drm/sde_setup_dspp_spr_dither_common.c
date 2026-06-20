__int64 __fastcall sde_setup_dspp_spr_dither_common(
        __int64 a1,
        __int64 *a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7)
{
  __int64 v7; // x15
  __int64 v8; // d14
  __int64 v9; // x21
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x10
  __int64 v13; // x11
  __int64 result; // x0

  v9 = *a2;
  v10 = *(unsigned int *)(*a2 + 12);
  if ( (unsigned int)v10 >= 9
    || (v11 = *(unsigned int *)(v9 + 16), (unsigned int)v11 > 8)
    || (v12 = *(unsigned int *)(v9 + 20), (unsigned int)v12 > 8)
    || (v13 = *(unsigned int *)(v9 + 24), (unsigned int)v13 > 8) )
  {
    __break(0x5512u);
    *(_QWORD *)(v7 - 24) = v8;
    *(double *)(v7 - 16) = a7;
    return sde_setup_dspp_spr_dither_v2();
  }
  else
  {
    result = sde_reg_write(
               a1,
               *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 452LL) + 4,
               dither_depth_map_1[v10] & 3
             | (4 * (dither_depth_map_1[v11] & 3)) & 0xF
             | (16 * (dither_depth_map_1[v12] & 3)) & 0x3F
             | ((dither_depth_map_1[v13] & 3) << 6)
             | ((unsigned __int8)(*(_DWORD *)(v9 + 8) != 0) << 8),
               "base + offset");
    *a3 = 1;
    if ( (*(_QWORD *)(*(_QWORD *)(a1 + 72) + 32LL) & 0x8000) != 0 && (*(_BYTE *)v9 & 1) != 0 )
      *a3 = 17;
  }
  return result;
}
