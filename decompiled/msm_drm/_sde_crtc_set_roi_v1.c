__int64 __fastcall sde_crtc_set_roi_v1(__int64 *a1, __int64 a2)
{
  __int64 v2; // x24
  int v4; // w4
  int v5; // w4
  int v6; // w8
  __int64 v7; // x26
  unsigned __int64 v8; // x20
  __int64 *v9; // x23
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x9
  int v12; // w4
  int v13; // w4
  int v14; // w4
  int v15; // w4
  __int64 result; // x0
  _QWORD v17[4]; // [xsp+20h] [xbp-50h] BYREF
  __int64 v18; // [xsp+40h] [xbp-30h]
  _QWORD v19[5]; // [xsp+48h] [xbp-28h] BYREF

  v19[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  memset(v19, 0, 32);
  v18 = 0;
  memset(v17, 0, sizeof(v17));
  *(__int64 *)((char *)a1 + 620) = 0;
  *(__int64 *)((char *)a1 + 628) = 0;
  *(__int64 *)((char *)a1 + 636) = 0;
  *(__int64 *)((char *)a1 + 644) = 0;
  *(__int64 *)((char *)a1 + 652) = 0;
  *(__int64 *)((char *)a1 + 660) = 0;
  *(__int64 *)((char *)a1 + 668) = 0;
  *(__int64 *)((char *)a1 + 676) = 0;
  *(__int64 *)((char *)a1 + 684) = 0;
  *(__int64 *)((char *)a1 + 748) = 0;
  *(__int64 *)((char *)a1 + 756) = 0;
  *(__int64 *)((char *)a1 + 732) = 0;
  *(__int64 *)((char *)a1 + 740) = 0;
  *(__int64 *)((char *)a1 + 716) = 0;
  *(__int64 *)((char *)a1 + 724) = 0;
  *(__int64 *)((char *)a1 + 700) = 0;
  *(__int64 *)((char *)a1 + 708) = 0;
  *(__int64 *)((char *)a1 + 692) = 0;
  if ( !a2 )
  {
    if ( (_drm_debug & 4) != 0 )
    {
      if ( !v2 )
      {
LABEL_45:
        v5 = -1;
        goto LABEL_46;
      }
LABEL_8:
      v5 = *(_DWORD *)(v2 + 112);
LABEL_46:
      _drm_dev_dbg(0, 0, 0, "crtc%d: rois cleared\n", v5);
    }
LABEL_47:
    result = 0;
    goto LABEL_48;
  }
  if ( inline_copy_from_user_2((int)v17, a2, 0x48u) )
  {
    printk(&unk_245E45, "_sde_crtc_set_roi_v1");
    result = 4294967274LL;
    goto LABEL_48;
  }
  if ( (_drm_debug & 4) != 0 )
  {
    if ( v2 )
      v4 = *(_DWORD *)(v2 + 112);
    else
      v4 = -1;
    _drm_dev_dbg(0, 0, 0, "crtc%d: num_rects %d\n", v4, LODWORD(v17[0]));
  }
  if ( !LODWORD(v17[0]) )
  {
    if ( (_drm_debug & 4) != 0 )
    {
      if ( !v2 )
        goto LABEL_45;
      goto LABEL_8;
    }
    goto LABEL_47;
  }
  if ( LODWORD(v17[0]) < 5 )
  {
    v6 = HIDWORD(v18);
    v7 = 0;
    v8 = 0;
    *((_DWORD *)a1 + 155) = v17[0];
    *((_DWORD *)a1 + 164) = v6;
    while ( 1 )
    {
      v9 = &a1[v7];
      v10 = *(_QWORD *)((char *)&v17[v7] + 4);
      a1[v7 + 78] = v10;
      v11 = v10;
      if ( (a1[82] & 1) != 0 )
      {
        if ( v7 == 4 )
          goto LABEL_51;
        v11 = v19[v7];
      }
      *(__int64 *)((char *)v9 + 660) = v11;
      if ( (_drm_debug & 4) != 0 )
      {
        if ( v2 )
        {
          v12 = *(_DWORD *)(v2 + 112);
          if ( v7 == 4 )
            goto LABEL_52;
        }
        else
        {
          v12 = -1;
          if ( v7 == 4 )
            goto LABEL_52;
        }
        _drm_dev_dbg(
          0,
          0,
          0,
          "crtc%d: roi%d: roi (%d,%d) (%d,%d)\n",
          v12,
          v8,
          (unsigned __int16)v10,
          WORD1(v10),
          WORD2(v10),
          HIWORD(v10));
      }
      if ( v2 )
      {
        v13 = *(_DWORD *)(v2 + 112);
        if ( v7 == 4 )
          goto LABEL_52;
      }
      else
      {
        v13 = -1;
        if ( v7 == 4 )
          goto LABEL_52;
      }
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "_sde_crtc_set_roi_v1",
        1347,
        4,
        v13,
        *((unsigned __int16 *)v9 + 312),
        WORD1(a1[v7 + 78]),
        WORD2(a1[v7 + 78]),
        HIWORD(a1[v7 + 78]));
      if ( (_drm_debug & 4) != 0 )
      {
        if ( v2 )
          v14 = *(_DWORD *)(v2 + 112);
        else
          v14 = -1;
        if ( (unsigned __int64)(v7 * 8 - 31) < 0xFFFFFFFFFFFFFFB7LL
          || (unsigned __int64)(v7 * 8 - 29) < 0xFFFFFFFFFFFFFFB7LL
          || (unsigned __int64)(v7 * 8 - 27) < 0xFFFFFFFFFFFFFFB7LL )
        {
LABEL_51:
          __break(1u);
LABEL_52:
          __break(0x5512u);
        }
        _drm_dev_dbg(
          0,
          0,
          0,
          "crtc%d, roi_feature_flags %d: spr roi%d: spr roi (%d,%d) (%d,%d)\n",
          v14,
          HIDWORD(v18),
          v8,
          LOWORD(v19[v7]),
          WORD1(v19[v7]),
          WORD2(v19[v7]),
          HIWORD(v19[v7]));
      }
      if ( v2 )
        v15 = *(_DWORD *)(v2 + 112);
      else
        v15 = -1;
      if ( (unsigned __int64)(v7 * 8 - 31) < 0xFFFFFFFFFFFFFFB7LL
        || (unsigned __int64)(v7 * 8 - 29) < 0xFFFFFFFFFFFFFFB7LL
        || (unsigned __int64)(v7 * 8 - 27) < 0xFFFFFFFFFFFFFFB7LL )
      {
        goto LABEL_51;
      }
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "_sde_crtc_set_roi_v1",
        1358,
        4,
        v15,
        SHIDWORD(v18),
        LOWORD(v19[v7]),
        WORD1(v19[v7]),
        WORD2(v19[v7]));
      ++v8;
      ++v7;
      if ( v8 >= LODWORD(v17[0]) )
        goto LABEL_47;
    }
  }
  printk(&unk_26565E, "_sde_crtc_set_roi_v1");
  result = 4294967274LL;
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
