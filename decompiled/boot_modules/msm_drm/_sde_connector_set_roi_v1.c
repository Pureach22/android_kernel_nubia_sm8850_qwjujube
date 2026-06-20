__int64 __fastcall sde_connector_set_roi_v1(__int64 a1, _QWORD *a2, __int64 a3)
{
  unsigned int v5; // w4
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x8
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x8
  __int64 result; // x0
  _QWORD v11[10]; // [xsp+10h] [xbp-50h] BYREF

  v11[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v11, 0, 72);
  a2[256] = 0;
  a2[257] = 0;
  a2[258] = 0;
  a2[259] = 0;
  a2[260] = 0;
  a2[261] = 0;
  a2[262] = 0;
  a2[263] = 0;
  a2[264] = 0;
  if ( a3 )
  {
    if ( inline_copy_from_user_4((int)v11, a3, 0x48u) )
    {
      printk(&unk_27DF74, "_sde_connector_set_roi_v1");
      result = 4294967274LL;
      goto LABEL_25;
    }
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "conn%d num_rects %d\n", *(_DWORD *)(a1 + 64), LODWORD(v11[0]));
    v5 = v11[0];
    if ( !LODWORD(v11[0]) )
    {
      if ( (_drm_debug & 4) == 0 )
        goto LABEL_24;
      goto LABEL_23;
    }
    if ( LODWORD(v11[0]) >= 5 )
    {
      printk(&unk_235818, "_sde_connector_set_roi_v1");
      result = 4294967274LL;
      goto LABEL_25;
    }
    v6 = *(_QWORD *)((char *)v11 + 4);
    *((_DWORD *)a2 + 512) = v11[0];
    *(_QWORD *)((char *)a2 + 2052) = v6;
    if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(
        0,
        0,
        0,
        "conn%d roi%d: roi (%d,%d) (%d,%d)\n",
        *(_DWORD *)(a1 + 64),
        0,
        (unsigned __int16)v6,
        WORD1(v6),
        WORD2(v6),
        HIWORD(v6));
      v5 = v11[0];
    }
    if ( v5 < 2 )
      goto LABEL_24;
    v7 = *(_QWORD *)((char *)&v11[1] + 4);
    *(_QWORD *)((char *)a2 + 2060) = *(_QWORD *)((char *)&v11[1] + 4);
    if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(
        0,
        0,
        0,
        "conn%d roi%d: roi (%d,%d) (%d,%d)\n",
        *(_DWORD *)(a1 + 64),
        1,
        (unsigned __int16)v7,
        WORD1(v7),
        WORD2(v7),
        HIWORD(v7));
      v5 = v11[0];
    }
    if ( v5 < 3 )
      goto LABEL_24;
    v8 = *(_QWORD *)((char *)&v11[2] + 4);
    *(_QWORD *)((char *)a2 + 2068) = *(_QWORD *)((char *)&v11[2] + 4);
    if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(
        0,
        0,
        0,
        "conn%d roi%d: roi (%d,%d) (%d,%d)\n",
        *(_DWORD *)(a1 + 64),
        2,
        (unsigned __int16)v8,
        WORD1(v8),
        WORD2(v8),
        HIWORD(v8));
      v5 = v11[0];
    }
    if ( v5 < 4 )
      goto LABEL_24;
    v9 = *(_QWORD *)((char *)&v11[3] + 4);
    *(_QWORD *)((char *)a2 + 2076) = *(_QWORD *)((char *)&v11[3] + 4);
    if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(
        0,
        0,
        0,
        "conn%d roi%d: roi (%d,%d) (%d,%d)\n",
        *(_DWORD *)(a1 + 64),
        3,
        (unsigned __int16)v9,
        WORD1(v9),
        WORD2(v9),
        HIWORD(v9));
      v5 = v11[0];
    }
    if ( v5 < 5 )
      goto LABEL_24;
    *(_QWORD *)((char *)a2 + 2084) = *(_QWORD *)((char *)&v11[4] + 4);
    if ( (_drm_debug & 4) == 0 && v5 == 5 )
      goto LABEL_24;
    __break(0x5512u);
  }
  if ( (_drm_debug & 4) != 0 )
LABEL_23:
    _drm_dev_dbg(0, 0, 0, "conn%d rois cleared\n", *(_DWORD *)(a1 + 64));
LABEL_24:
  result = 0;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
