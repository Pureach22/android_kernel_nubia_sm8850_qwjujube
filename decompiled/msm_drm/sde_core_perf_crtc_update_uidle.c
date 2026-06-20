__int64 __fastcall sde_core_perf_crtc_update_uidle(__int64 result, char a2)
{
  __int64 v2; // x20
  __int64 v3; // x8
  __int64 v4; // x26
  int v6; // w6
  int v7; // w7
  int v8; // w4
  __int64 v9; // x8
  __int64 *v10; // x28
  int v11; // w27
  unsigned int v12; // w21
  unsigned int v13; // w8
  __int64 *v14; // x22
  unsigned int dfps_maxfps; // w23
  int intf_mode; // w0
  __int64 v17; // x8
  _QWORD *v18; // x24
  _QWORD *v19; // x9
  _BOOL4 v20; // w25
  int v21; // w7
  __int64 v22; // x8
  _QWORD *i; // x24
  void *v24; // x0
  __int64 v25; // x8
  bool v26; // w24
  __int64 v27; // x0
  __int64 v28; // x22
  __int64 v29; // x8
  void (__fastcall *v30)(__int64, __int64 *); // x8
  __int64 v31; // x8
  int v32; // w5
  int v33; // w6
  int v34; // w7
  __int64 v35; // x2
  __int64 v36; // x3
  __int64 v37; // x4
  __int64 v38; // x5
  __int64 v39; // x6
  int v40; // w7
  __int64 v41; // x8
  void (__fastcall *v42)(__int64, __int64 *); // x8
  __int64 v43; // x8
  unsigned int *j; // x21
  __int64 v45; // x21
  __int64 v46; // x8
  _DWORD *v47; // x8
  void *v48; // x0
  char v49; // [xsp+0h] [xbp-40h]
  int v50; // [xsp+24h] [xbp-1Ch]
  __int64 v51; // [xsp+28h] [xbp-18h] BYREF
  unsigned __int64 v52; // [xsp+30h] [xbp-10h]
  __int64 v53; // [xsp+38h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !result )
  {
    v48 = &unk_25E167;
LABEL_82:
    result = printk(v48, "sde_core_perf_crtc_update_uidle");
    goto LABEL_83;
  }
  v2 = result;
  if ( !*(_QWORD *)result || (v3 = *(_QWORD *)(*(_QWORD *)result + 56LL)) == 0 )
  {
    v24 = &unk_231B33;
LABEL_80:
    printk(v24, "_sde_crtc_get_kms");
    goto LABEL_81;
  }
  v4 = *(_QWORD *)(v3 + 8);
  if ( !v4 )
  {
    v24 = &unk_234896;
    goto LABEL_80;
  }
  if ( !*(_QWORD *)(v4 + 152) )
  {
LABEL_81:
    v48 = &unk_234896;
    goto LABEL_82;
  }
  if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 136) + 56LL) + 5912LL) == 1 )
  {
LABEL_83:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  mutex_lock(&sde_core_perf_lock);
  v8 = *(_DWORD *)(*(_QWORD *)(v4 + 1976) + 21976LL);
  if ( !v8 || (a2 & 1) != 0 && (*(_BYTE *)(*(_QWORD *)(v4 + 1976) + 21984LL) & 1) == 0 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "uidle is not enabled %d %d\n", v8, *(unsigned __int8 *)(*(_QWORD *)(v4 + 1976) + 21984LL));
    goto LABEL_77;
  }
  v9 = *(_QWORD *)v2;
  v10 = *(__int64 **)(*(_QWORD *)v2 + 864LL);
  if ( v10 != (__int64 *)(*(_QWORD *)v2 + 864LL) )
  {
    v11 = 0;
    v12 = 2;
    while ( 1 )
    {
      v14 = v10 - 2;
      if ( v10 != &qword_10 && *((_BYTE *)v10 + 156) )
      {
        dfps_maxfps = sde_crtc_get_dfps_maxfps(v10 - 2);
        if ( !dfps_maxfps )
          dfps_maxfps = sde_crtc_get_fps_mode(v10 - 2);
        if ( (_drm_debug & 4) != 0 )
        {
          v50 = *((_DWORD *)v10 + 24);
          intf_mode = sde_crtc_get_intf_mode(v10 - 2, v10[249]);
          v17 = *(v10 - 2);
          v18 = *(_QWORD **)(v17 + 816);
          v19 = (_QWORD *)(v17 + 816);
          v20 = (unsigned int)(intf_mode - 3) < 2;
          while ( v18 != v19 )
          {
            if ( (__int64 *)v18[9] == v14 )
            {
              if ( (((__int64 (__fastcall *)(_QWORD *))sde_encoder_in_clone_mode)(v18 - 1) & 1) != 0 )
              {
                v21 = 1;
                goto LABEL_33;
              }
              v17 = *v14;
            }
            v18 = (_QWORD *)*v18;
            v19 = (_QWORD *)(v17 + 816);
          }
          v21 = 0;
LABEL_33:
          _drm_dev_dbg(
            0,
            0,
            0,
            "crtc=%d fps:%d wb:%d cwb:%d uidle:%d uidle_crtc:%d en:%d\n",
            v50,
            dfps_maxfps,
            v20,
            v21,
            v12,
            2,
            a2 & 1);
        }
        if ( (unsigned int)++v11 > 1 || (unsigned int)sde_crtc_get_intf_mode(v10 - 2, v10[249]) - 3 < 2 )
          goto LABEL_46;
        v22 = *v14;
        for ( i = *(_QWORD **)(*v14 + 816); i != (_QWORD *)(v22 + 816); i = (_QWORD *)*i )
        {
          if ( (__int64 *)i[9] == v14 )
          {
            if ( (((__int64 (__fastcall *)(_QWORD *))sde_encoder_in_clone_mode)(i - 1) & 1) != 0 )
              goto LABEL_46;
            v22 = *v14;
          }
        }
        if ( !dfps_maxfps )
        {
LABEL_46:
          v12 = 0;
          goto LABEL_48;
        }
        if ( dfps_maxfps > *(_DWORD *)(*(_QWORD *)(v4 + 1976) + 21968LL) )
          v13 = dfps_maxfps <= *(_DWORD *)(*(_QWORD *)(v4 + 1976) + 21972LL);
        else
          v13 = 2;
        if ( v13 < v12 )
          v12 = v13;
        if ( !v12 )
          goto LABEL_48;
        v9 = *(_QWORD *)v2;
      }
      v10 = (__int64 *)*v10;
      if ( v10 == (__int64 *)(v9 + 864) )
        goto LABEL_48;
    }
  }
  v12 = 2;
LABEL_48:
  v25 = *(_QWORD *)(v4 + 136);
  if ( (a2 & 1) == 0 )
    v12 = 0;
  v26 = v12 != 0;
  if ( v25 && *(_QWORD *)(v25 + 8) && *(_QWORD *)(v4 + 3536) )
  {
    v27 = sde_evtlog_log(sde_dbg_base_evtlog, "_sde_core_perf_enable_uidle", 653, -1, v12, -1059143953, v6, v7, v49);
    v28 = *(_QWORD *)(v4 + 3536);
    v51 = 1;
    v52 = 18;
    v29 = *(unsigned int *)(v28 + 28);
    BYTE5(v52) = v12 != 0;
    if ( (unsigned int)v29 >= 3 )
      goto LABEL_85;
    v30 = *(void (__fastcall **)(__int64, __int64 *))(v28 + 8 * v29 + 64);
    if ( v30 )
    {
      if ( *((_DWORD *)v30 - 1) != -447034885 )
        __break(0x8228u);
      v30(v28, &v51);
      v28 = *(_QWORD *)(v4 + 3536);
    }
    v31 = *(_QWORD *)(v4 + 152) + 20480LL;
    v32 = *(_DWORD *)(*(_QWORD *)(v4 + 152) + 21944LL);
    v52 = __PAIR64__(v12, v32);
    v33 = *(_DWORD *)(v31 + 1456);
    LODWORD(v51) = v33;
    v34 = *(_DWORD *)(v31 + 1460);
    HIDWORD(v51) = v34;
    if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "fal10_danger:%d fal10_exit_cnt:%d fal10_exit_danger:%d\n", v32, v33, v34);
      v34 = HIDWORD(v51);
      v32 = v52;
      v33 = v51;
    }
    v27 = sde_evtlog_log(sde_dbg_base_evtlog, "_sde_core_uidle_setup_cfg", 620, -1, v12, v32, v33, v34, 239);
    v41 = *(unsigned int *)(v28 + 28);
    if ( (unsigned int)v41 >= 3 )
      goto LABEL_85;
    v42 = *(void (__fastcall **)(__int64, __int64 *))(v28 + 8 * v41 + 40);
    if ( v42 )
    {
      if ( *((_DWORD *)v42 - 1) != -1313686289 )
        __break(0x8228u);
      v42(v28, &v51);
    }
    v43 = *(_QWORD *)v2;
    for ( j = *(unsigned int **)(*(_QWORD *)v2 + 816LL); j != (unsigned int *)(v43 + 816); j = *(unsigned int **)j )
    {
      if ( *((_QWORD *)j + 9) == v2 )
      {
        sde_encoder_uidle_enable(j - 2, 1, v35, v36, v37, v38, v39, v40);
        v43 = *(_QWORD *)v2;
      }
    }
    *(_BYTE *)(v4 + 2097) = v26;
  }
  else
  {
    printk(&unk_26240E, "_sde_core_perf_enable_uidle");
  }
  *(_BYTE *)(*(_QWORD *)(v4 + 1976) + 21986LL) = (a2 & 1) == 0;
  if ( !*(_DWORD *)(*(_QWORD *)(v4 + 152) + 21980LL) )
  {
LABEL_77:
    result = mutex_unlock(&sde_core_perf_lock);
    goto LABEL_83;
  }
  v45 = *(_QWORD *)(v4 + 3536);
  v27 = sde_evtlog_log(
          sde_dbg_base_evtlog,
          "_sde_core_perf_uidle_setup_cntr",
          698,
          -1,
          a2 & 1,
          -1059143953,
          v39,
          v40,
          v49);
  v46 = *(unsigned int *)(v45 + 28);
  if ( (unsigned int)v46 < 3 )
  {
    v47 = *(_DWORD **)(v45 + 8 * v46 + 88);
    if ( v47 )
    {
      if ( *(v47 - 1) != 193872765 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v47)(v45, a2 & 1);
      *(_BYTE *)(*(_QWORD *)(v4 + 152) + 21985LL) = a2 & 1;
    }
    goto LABEL_77;
  }
LABEL_85:
  __break(0x5512u);
  return sde_core_perf_crtc_release_bw(v27);
}
