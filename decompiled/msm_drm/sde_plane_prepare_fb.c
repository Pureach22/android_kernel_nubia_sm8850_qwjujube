__int64 __fastcall sde_plane_prepare_fb(
        int *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 v8; // x20
  __int64 v10; // x22
  int v11; // w4
  int v12; // w8
  __int64 result; // x0
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 v16; // x3
  __int64 v17; // x8
  _QWORD *v18; // x8
  unsigned int v19; // w20
  char v20; // w9
  __int64 v21; // x22
  unsigned int v22; // w0
  unsigned int v23; // w19
  unsigned int v24; // w21
  char v25; // [xsp+0h] [xbp-60h]
  _QWORD v26[10]; // [xsp+10h] [xbp-50h] BYREF

  v26[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a2 + 16);
  if ( !v8 )
  {
LABEL_32:
    result = 0;
    goto LABEL_33;
  }
  memset(v26, 0, 72);
  if ( (_drm_debug & 4) != 0 )
  {
    v10 = a2;
    if ( a1 )
      v11 = a1[26];
    else
      v11 = -1;
    _drm_dev_dbg(0, 0, 0, "plane%d FB[%u]\n", v11, *(_DWORD *)(v8 + 24));
    a2 = v10;
  }
  if ( !a2 )
    goto LABEL_23;
  v12 = *(_DWORD *)(a2 + 1648);
  result = 0;
  if ( v12 == 2 || v12 == 8 )
    goto LABEL_33;
  if ( !a1 )
  {
LABEL_23:
    printk(&unk_27D28A, "_sde_plane_get_aspace");
    v19 = -22;
LABEL_36:
    printk(&unk_2466A8, "sde_plane_prepare_fb");
    result = v19;
    goto LABEL_33;
  }
  if ( !*(_QWORD *)a1 || (v14 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) == 0 || (v15 = *(_QWORD *)(v14 + 8)) == 0 )
  {
    printk(&unk_234896, "_sde_plane_get_aspace");
    goto LABEL_35;
  }
  v16 = *(_QWORD *)(a2 + 1520);
  if ( (unsigned int)(v16 - 2) >= 2 )
  {
    if ( (_DWORD)v16 != 1 )
    {
      if ( (_DWORD)v16 )
      {
        printk(&unk_25044B, "_sde_plane_get_aspace");
        v19 = -14;
        goto LABEL_36;
      }
      v17 = *(_QWORD *)(v15 + 1704);
      if ( !v17 )
        goto LABEL_35;
      goto LABEL_25;
    }
    v17 = *(_QWORD *)(v15 + 1720);
    if ( v17 )
    {
LABEL_25:
      *(_QWORD *)(a2 + 1744) = v17;
      v20 = *(_BYTE *)(v17 + 268);
      *(_BYTE *)(a2 + 1786) = v20 ^ 1;
      if ( (v20 & 1) == 0 )
      {
        sde_evtlog_log(sde_dbg_base_evtlog, "sde_plane_prepare_fb", 2273, -1, a1[26], a1[482], -1059143953, a8, v25);
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "plane%d domain not attached, prepare_fb handled later\n", a1[26]);
        goto LABEL_32;
      }
      v21 = a2;
      v22 = msm_framebuffer_prepare(v8, v17);
      if ( v22 )
      {
        v24 = v22;
        printk(&unk_23C0FA, "sde_plane_prepare_fb");
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "sde_plane_prepare_fb",
          2285,
          -1,
          *(_DWORD *)(v8 + 24),
          a1[26],
          a1[482],
          v24,
          173);
        result = v24;
        goto LABEL_33;
      }
      v18 = (_QWORD *)(v21 + 1744);
      if ( *(_DWORD *)(v21 + 1520) != 3 )
        goto LABEL_28;
      goto LABEL_20;
    }
LABEL_35:
    v19 = -22;
    goto LABEL_36;
  }
  v18 = (_QWORD *)(a2 + 1744);
  *(_QWORD *)(a2 + 1744) = 0;
  *(_BYTE *)(a2 + 1786) = 0;
  if ( (_DWORD)v16 == 3 )
  {
LABEL_20:
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "deferring dma-buf mapping to commit phase\n");
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_plane_prepare_fb",
      2304,
      -1,
      a1[26],
      *(_DWORD *)(v8 + 24),
      3,
      -1059143953,
      v25);
    goto LABEL_32;
  }
LABEL_28:
  result = sde_format_populate_layout(*v18, v8, v26);
  if ( (_DWORD)result )
  {
    v23 = result;
    printk(&unk_2503F1, "sde_plane_prepare_fb");
    result = v23;
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
