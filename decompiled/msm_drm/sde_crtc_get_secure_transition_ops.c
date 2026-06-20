__int64 __fastcall sde_crtc_get_secure_transition_ops(__int64 a1, __int64 a2, char a3)
{
  __int64 v4; // x8
  __int64 v5; // x26
  int v6; // w9
  __int64 v8; // x8
  int v9; // w20
  __int64 v10; // x24
  __int64 *v11; // x22
  int v12; // w27
  __int64 *v13; // x8
  __int64 v14; // x9
  unsigned int v15; // w25
  __int64 v16; // x11
  __int64 v17; // x20
  int v18; // w8
  __int64 v19; // x8
  int v20; // w9
  int v21; // w7
  unsigned int v22; // w23
  int v23; // w8
  void *v24; // x0
  const char *v25; // x1
  int v27; // [xsp+3Ch] [xbp-4h]

  if ( !a1 || !*(_QWORD *)(a1 + 2008) )
  {
    v24 = &unk_25E167;
    v25 = "sde_crtc_get_secure_transition_ops";
LABEL_79:
    printk(v24, v25);
    return (unsigned int)-22;
  }
  if ( !*(_QWORD *)a1 || (v4 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) == 0 )
  {
    v24 = &unk_25E167;
    v25 = "_sde_crtc_get_kms";
    goto LABEL_79;
  }
  v5 = *(_QWORD *)(v4 + 8);
  if ( !v5 )
  {
    v24 = &unk_234896;
    v25 = "_sde_crtc_get_kms";
    goto LABEL_79;
  }
  v6 = *(_DWORD *)(v5 + 3664);
  *(_DWORD *)(v5 + 3660) = *(_DWORD *)(v5 + 3656);
  *(_DWORD *)(v5 + 3668) = v6;
  v8 = *(_QWORD *)(a1 + 2008);
  if ( v8 )
    v9 = *(_DWORD *)(v8 + 1408);
  else
    v9 = -22;
  v10 = *(_QWORD *)(v5 + 152);
  v11 = *(__int64 **)(*(_QWORD *)a1 + 816LL);
  if ( v11 == (__int64 *)(*(_QWORD *)a1 + 816LL) )
  {
    LOBYTE(v12) = 0;
  }
  else
  {
    v12 = 0;
    do
    {
      if ( ((*(_DWORD *)(*(_QWORD *)(a1 + 2008) + 20LL) >> *((_DWORD *)v11 + 15)) & 1) != 0
        && (sde_encoder_is_dsi_display(v11 - 1) & 1) != 0 )
      {
        v12 |= sde_encoder_check_curr_mode(v11 - 1, 1);
      }
      v11 = (__int64 *)*v11;
    }
    while ( v11 != (__int64 *)(*(_QWORD *)a1 + 816LL) );
  }
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "crtc%d: secure_level %d old_valid_fb %d post_commit %d\n",
      *(_DWORD *)(a1 + 112),
      v9,
      a3 & 1,
      v12 & 1);
  v27 = v9;
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_crtc_get_secure_transition_ops",
    2887,
    4,
    *(_DWORD *)(a1 + 112),
    v9,
    *(_DWORD *)(v5 + 3656),
    a3 & 1,
    v12 & 1);
  v13 = *(__int64 **)(*(_QWORD *)a1 + 840LL);
  v14 = *(_QWORD *)a1 + 840LL;
  if ( v13 != (__int64 *)v14 )
  {
    v15 = 0;
    while ( 1 )
    {
      if ( ((*(_DWORD *)(*(_QWORD *)(a1 + 2008) + 12LL) >> *((_DWORD *)v13 + 437)) & 1) != 0 )
      {
        v16 = v13[220];
        if ( v16 )
        {
          v15 = *(_DWORD *)(v16 + 1520);
          if ( v15 >= 4 )
          {
            printk(&unk_268A49, "sde_crtc_get_secure_transition_ops");
            return (unsigned int)-22;
          }
          if ( v15 == 3 )
            break;
        }
      }
      v13 = (__int64 *)*v13;
      if ( v13 == (__int64 *)v14 )
      {
        v17 = v5 + 3696;
        mutex_lock(v5 + 3696);
        if ( v15 < 2 )
          goto LABEL_40;
        goto LABEL_76;
      }
    }
    v17 = v5 + 3696;
    mutex_lock(v5 + 3696);
    v18 = *(_DWORD *)(v5 + 3656);
    if ( v27 == 1 && !v18 )
    {
      v19 = *(_QWORD *)(v10 + 22008);
      v20 = 1;
      *(_DWORD *)(v5 + 3664) = 1;
      *(_DWORD *)(v5 + 3672) = 1;
      if ( (v19 & 0x400000000LL) != 0 )
        v21 = 5;
      else
        v21 = 4;
      *(_DWORD *)(v5 + 3656) = v21;
      if ( (a3 & 1) != 0 )
        v22 = 7;
      else
        v22 = 1;
      if ( (*(_QWORD *)(v10 + 22008) & 0x100000000LL) != 0 )
        *(_DWORD *)(v5 + 3680) = 1;
      v15 = 3;
      goto LABEL_73;
    }
    if ( v18 )
      goto LABEL_76;
    v21 = 5;
    *(_DWORD *)(v5 + 3664) = v27;
    v20 = 1;
    v15 = 3;
    *(_DWORD *)(v5 + 3656) = 5;
    if ( (a3 & 1) != 0 )
      v22 = 3;
    else
      v22 = 1;
    goto LABEL_72;
  }
  v17 = v5 + 3696;
  mutex_lock(v5 + 3696);
  v15 = 0;
LABEL_40:
  v23 = *(_DWORD *)(v5 + 3656);
  if ( v23 == 1 || v23 == 4 )
  {
LABEL_42:
    if ( (*(_QWORD *)(v10 + 22008) & 0x400000000LL) != 0 )
      v21 = 6;
    else
      v21 = 3;
    if ( (v12 & 1) != 0 )
      v20 = 2;
    else
      v20 = 1;
    *(_DWORD *)(v5 + 3656) = v21;
    *(_DWORD *)(v5 + 3672) = v20;
    if ( (a3 & 1) != 0 )
      v22 = 3;
    else
      v22 = 1;
    if ( (*(_QWORD *)(v10 + 22008) & 0x100000000LL) != 0 )
      *(_DWORD *)(v5 + 3680) = 2;
    goto LABEL_73;
  }
  if ( *(_DWORD *)(v5 + 3664) == 1 )
  {
    if ( v23 == 5 || v23 == 2 )
      goto LABEL_42;
  }
  else if ( v23 == 5 || v23 == 2 )
  {
    v21 = 6;
    if ( (v12 & 1) != 0 )
      v20 = 2;
    else
      v20 = 1;
    if ( (a3 & 1) != 0 )
      v22 = 3;
    else
      v22 = 1;
    *(_DWORD *)(v5 + 3656) = 6;
LABEL_72:
    *(_DWORD *)(v5 + 3672) = v20;
LABEL_73:
    if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(
        0,
        0,
        0,
        "crtc%d: state%d sec%d sec_lvl%d type%d ops%x\n",
        *(_DWORD *)(a1 + 112),
        v21,
        v27,
        *(_DWORD *)(v5 + 3664),
        v20,
        v22);
      v21 = *(_DWORD *)(v5 + 3656);
      v20 = *(_DWORD *)(v5 + 3672);
    }
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_crtc_get_secure_transition_ops",
      2940,
      -1,
      *(_DWORD *)(a1 + 112),
      v27,
      v15,
      v21,
      v20);
    goto LABEL_77;
  }
LABEL_76:
  v22 = 0;
LABEL_77:
  mutex_unlock(v17);
  return v22;
}
