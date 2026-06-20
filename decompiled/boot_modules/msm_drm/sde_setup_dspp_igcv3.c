__int64 __fastcall sde_setup_dspp_igcv3(_DWORD *a1, _DWORD *a2)
{
  __int64 v3; // x21
  int v4; // w1
  int v5; // w8
  __int64 v6; // x2
  __int64 i; // x23
  int v8; // w8
  __int64 v9; // x2
  int v10; // w8
  __int64 v11; // x2
  __int64 j; // x23
  int v13; // w8
  __int64 v14; // x2
  int v15; // w8
  __int64 v16; // x2
  __int64 k; // x23
  int v18; // w8
  __int64 v19; // x2
  _DWORD *v20; // x0
  __int64 v21; // x2

  if ( !a1 || !a2 )
    return _drm_err("invalid param ctx %pK cfg %pK\n", a1, a2);
  v3 = *(_QWORD *)a2;
  if ( !*(_QWORD *)a2 )
  {
    _drm_dev_dbg(0, 0, 1, "disable igc feature\n");
    v20 = a1;
    v21 = 0;
    return sde_reg_write(v20, 0, v21, "IGC_OPMODE_OFF");
  }
  v4 = a2[2];
  if ( v4 == 4632 )
  {
    v5 = *(_DWORD *)(v3 + 8) & 0xFFF;
    *(_DWORD *)(v3 + 8) = v5;
    v6 = v5 | (~(1 << (a1[16] - 1)) << 28) | 0x2000000u;
    *(_DWORD *)(v3 + 8) = v6;
    sde_reg_write(a1 + 8, 0, v6, "offset");
    for ( i = 12; i != 1032; i += 4 )
    {
      v8 = *(_DWORD *)(v3 + i) & 0xFFF;
      *(_DWORD *)(v3 + i) = v8;
      v9 = v8 | (unsigned int)(~(1 << (a1[16] - 1)) << 28);
      *(_DWORD *)(v3 + i) = v9;
      sde_reg_write(a1 + 8, 0, v9, "offset");
    }
    v10 = *(_DWORD *)(v3 + 1032) & 0xFFF;
    *(_DWORD *)(v3 + 1032) = v10;
    v11 = v10 | (~(1 << (a1[16] - 1)) << 28) | 0x2000000u;
    *(_DWORD *)(v3 + 1032) = v11;
    sde_reg_write(a1 + 8, 4, v11, "offset");
    for ( j = 1036; j != 2056; j += 4 )
    {
      v13 = *(_DWORD *)(v3 + j) & 0xFFF;
      *(_DWORD *)(v3 + j) = v13;
      v14 = v13 | (unsigned int)(~(1 << (a1[16] - 1)) << 28);
      *(_DWORD *)(v3 + j) = v14;
      sde_reg_write(a1 + 8, 4, v14, "offset");
    }
    v15 = *(_DWORD *)(v3 + 2056) & 0xFFF;
    *(_DWORD *)(v3 + 2056) = v15;
    v16 = v15 | (~(1 << (a1[16] - 1)) << 28) | 0x2000000u;
    *(_DWORD *)(v3 + 2056) = v16;
    sde_reg_write(a1 + 8, 8, v16, "offset");
    for ( k = 2060; k != 3080; k += 4 )
    {
      v18 = *(_DWORD *)(v3 + k) & 0xFFF;
      *(_DWORD *)(v3 + k) = v18;
      v19 = v18 | (unsigned int)(~(1 << (a1[16] - 1)) << 28);
      *(_DWORD *)(v3 + k) = v19;
      sde_reg_write(a1 + 8, 8, v19, "offset");
    }
    if ( (*(_BYTE *)v3 & 1) != 0 )
      sde_reg_write(a1, 2016, *(_DWORD *)(v3 + 3080) & 0xF, "IGC_DITHER_OFF");
    v20 = a1;
    v21 = 1;
    return sde_reg_write(v20, 0, v21, "IGC_OPMODE_OFF");
  }
  return _drm_err("invalid size of payload len %d exp %zd\n", v4, 0x1218u);
}
