__int64 __fastcall sde_spr_check_udc_cfg(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned __int16 *v4; // x9
  unsigned __int16 *v5; // x11
  __int64 v6; // x2
  unsigned int v7; // w8
  __int64 v8; // x8
  unsigned __int16 *v9; // x12
  unsigned __int16 *v10; // x13
  unsigned __int16 *v11; // x0
  int v12; // w17
  int v13; // w16
  unsigned int v14; // w9
  __int64 v15; // x2
  unsigned int v16; // w17
  unsigned int v17; // w10
  unsigned int v18; // w9
  __int64 v19; // x10
  unsigned __int16 *v20; // x16
  const char *v21; // x0
  __int64 v22; // x1

  result = 4294967274LL;
  if ( !a1 || !a2 )
    return result;
  v4 = *(unsigned __int16 **)a2;
  if ( !*(_QWORD *)a2 )
    return 0;
  v5 = v4 + 5;
  if ( v4[5] || v4[6] )
  {
    v6 = 0;
    v7 = v4[4];
    if ( v4[4] )
    {
LABEL_31:
      v21 = "SPR UDC can not be used with this config. CFG4: %u CFG11: %u";
      v22 = v7;
LABEL_32:
      _drm_err(v21, v22, v6);
      return 4294967274LL;
    }
  }
  else
  {
    v6 = v4[7] == 0;
    v7 = v4[4];
    if ( v4[4] )
      goto LABEL_31;
  }
  if ( (v6 & 1) != 0 )
    goto LABEL_31;
  v8 = 0;
  v9 = v4 + 9;
  v10 = v4 + 37;
  while ( 2 )
  {
    v11 = &v9[9 * v8];
    v12 = v5[v8];
    v13 = v11[1];
    v14 = v11[2];
    v15 = v11[3];
    if ( v12 == 2 )
    {
      v16 = (2 * *(_DWORD *)(a2 + 96) + 2) / 3u;
    }
    else if ( v12 == 1 )
    {
      v16 = (unsigned int)(*(_DWORD *)(a2 + 96) + 1) >> 1;
    }
    else
    {
      if ( v5[v8] )
      {
        _drm_err("Can't calculate decimation");
        return 4294967274LL;
      }
      v16 = *(_DWORD *)(a2 + 96);
    }
    v17 = v14 + *v11;
    if ( v17 >= v16 )
    {
      v21 = "Invalid CFG1 - C%u x2 %u";
LABEL_36:
      v22 = (unsigned int)v8;
      v6 = v17;
      goto LABEL_32;
    }
    v17 = v15 + v13;
    if ( (unsigned int)(v15 + v13) >= *(_DWORD *)(a2 + 92) )
    {
      v21 = "Invalid CFG1 - C%u y2 %u";
      goto LABEL_36;
    }
    if ( (unsigned int)(v15 - 257) <= 0xFFFFFF00 )
    {
      _drm_err("Invalid CFG1 - C%u Lines %u", (unsigned int)v8, v15);
      return 4294967274LL;
    }
    if ( v14 - 513 <= 0xFFFFFE00 )
    {
      _drm_err("Invalid CFG1 - C%u W %u", (unsigned int)v8, v11[2]);
      return 4294967274LL;
    }
    v18 = v14 >> 1;
    v19 = 0;
    v20 = v10;
    do
    {
      if ( v18 < *(v20 - 1) )
      {
        v21 = "Invalid CFG2 - C%u L%u, o1 exceeds limits";
LABEL_29:
        v22 = (unsigned int)v8;
        v6 = (unsigned int)v19;
        goto LABEL_32;
      }
      if ( v18 > *v20 )
      {
        v21 = "Invalid CFG2 - C%u L%u, o2 should exceeds limits";
        goto LABEL_29;
      }
      ++v19;
      v20 += 2;
    }
    while ( v15 != v19 );
    ++v8;
    result = 0;
    v10 += 512;
    if ( v8 != 3 )
      continue;
    return result;
  }
}
