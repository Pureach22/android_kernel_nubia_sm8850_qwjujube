__int64 __fastcall sde_crtc_enable(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  __int64 v8; // x8
  __int64 v10; // x25
  __int64 v11; // x20
  __int64 v12; // x24
  __int64 v13; // x1
  int v14; // w7
  __int64 **v15; // x21
  __int64 v16; // x0
  __int64 *i; // x23
  char v18; // w8
  __int64 connector; // x0
  __int64 v20; // x8
  __int64 v21; // x8
  __int64 *v22; // x27
  char v23; // w0
  __int64 v24; // x0
  _QWORD *v25; // x23
  __int64 j; // x20
  _DWORD *v27; // x8
  __int64 result; // x0
  __int64 v29; // x22
  __int64 v30; // x25
  __int64 v31; // x23
  __int64 v32; // x21
  __int64 v33; // x7
  __int64 v34; // x8
  unsigned __int64 v35; // x8
  unsigned int v36; // w8
  int v37; // w5
  int v38; // w6
  unsigned __int64 v39; // x21
  void *v40; // x0
  char v41; // [xsp+0h] [xbp-20h]
  char v42; // [xsp+0h] [xbp-20h]
  unsigned int v43; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v44; // [xsp+18h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || (v8 = *(_QWORD *)a1) == 0 || (v10 = *(_QWORD *)(v8 + 56)) == 0 )
  {
    v40 = &unk_25E167;
LABEL_64:
    result = printk(v40, "sde_crtc_enable");
    goto LABEL_65;
  }
  v11 = *(_QWORD *)(v10 + 8);
  if ( !v11 )
  {
    printk(&unk_234896, "_sde_crtc_get_kms");
    goto LABEL_62;
  }
  if ( !*(_QWORD *)(v11 + 152) )
  {
LABEL_62:
    v40 = &unk_248EC7;
    goto LABEL_64;
  }
  if ( (*(_WORD *)(*(_QWORD *)(v8 + 8) + 488LL) & 7) != 0 )
  {
    v40 = &unk_24FBDF;
    goto LABEL_64;
  }
  v12 = *(_QWORD *)(a1 + 2008);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "crtc%d\n", *(_DWORD *)(a1 + 112));
  sde_evtlog_log(sde_dbg_base_evtlog, "sde_crtc_enable", 6390, 4, *(_DWORD *)(a1 + 112), -1059143953, a7, a8, v41);
  if ( (*(_BYTE *)(a1 + 4512) & 1) == 0 )
  {
    v13 = *(_QWORD *)(a1 + 2008);
    *(_DWORD *)(a1 + 7872) = *(_DWORD *)(v13 + 20);
    if ( (unsigned int)sde_crtc_get_intf_mode((__int64 *)a1, v13) - 5 <= 0xFFFFFFFD )
    {
      if ( (*(_QWORD *)(*(_QWORD *)(v11 + 152) + 22008LL) & 0x1000000) != 0 )
        drm_crtc_set_max_vblank_count(a1, 0x7FFFFFFF);
      drm_crtc_vblank_on(a1);
    }
  }
  mutex_lock(a1 + 4616);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_crtc_enable",
    6412,
    -1,
    *(_DWORD *)(a1 + 112),
    *(unsigned __int8 *)(a1 + 4512),
    -1059143953,
    v14,
    v42);
  sde_core_perf_crtc_update_uidle(a1, 1);
  v15 = *(__int64 ***)(a1 + 2008);
  v16 = **v15;
  for ( i = *(__int64 **)(v16 + 816); ; i = (__int64 *)*i )
  {
    if ( i == (__int64 *)(v16 + 816) )
      goto LABEL_57;
    if ( ((*((_DWORD *)v15 + 5) >> *((_DWORD *)i + 15)) & 1) != 0 )
    {
      v18 = ((__int64 (__fastcall *)(__int64 *))sde_encoder_in_clone_mode)(i - 1);
      v16 = **v15;
      if ( (v18 & 1) == 0 )
        break;
    }
  }
  connector = sde_encoder_get_connector(v16, i - 1);
  if ( !connector || (v20 = *(_QWORD *)(connector + 2512)) == 0 )
  {
LABEL_57:
    result = printk(&unk_261FD4, "sde_crtc_enable");
    goto LABEL_65;
  }
  if ( *(_BYTE *)(a1 + 4512) == 1 )
  {
    if ( (*(_BYTE *)(v20 + 3240) & 0x14) != 0 )
    {
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "%s extra crtc enable expected during DMS\n", (const char *)(a1 + 2176));
    }
    else
    {
      _warn_printk("%s unexpected crtc enable\n", (const char *)(a1 + 2176));
      __break(0x800u);
    }
    result = mutex_unlock(a1 + 4616);
    goto LABEL_65;
  }
  v21 = *(_QWORD *)a1;
  v22 = *(__int64 **)(*(_QWORD *)a1 + 816LL);
  if ( v22 != (__int64 *)(*(_QWORD *)a1 + 816LL) )
  {
    do
    {
      if ( ((*(_DWORD *)(*(_QWORD *)(a1 + 2008) + 20LL) >> *((_DWORD *)v22 + 15)) & 1) != 0 )
      {
        sde_encoder_register_frame_event_callback(v22 - 1, &sde_crtc_frame_event_cb, a1);
        v23 = sde_encoder_check_curr_mode(v22 - 1, 1);
        sde_crtc_static_img_control((_DWORD *)a1, 2, v23 & 1);
        v21 = *(_QWORD *)a1;
      }
      v22 = (__int64 *)*v22;
    }
    while ( v22 != (__int64 *)(v21 + 816) );
  }
  *(_BYTE *)(a1 + 4512) = 1;
  sde_cp_crtc_enable(a1);
  sde_cp_crtc_resume(a1);
  mutex_unlock(a1 + 4616);
  v24 = raw_spin_lock_irqsave(a1 + 6032);
  v25 = *(_QWORD **)(a1 + 4600);
  for ( j = v24; v25 != (_QWORD *)(a1 + 4600); v25 = (_QWORD *)*v25 )
  {
    v27 = (_DWORD *)*(v25 - 1);
    if ( v27 )
    {
      if ( *(v27 - 1) != 1979947765 )
        __break(0x8228u);
      if ( ((unsigned int (__fastcall *)(__int64, __int64, _QWORD *))v27)(a1, 1, v25 - 6) )
        printk(&unk_25E58F, "sde_crtc_enable");
    }
  }
  result = raw_spin_unlock_irqrestore(a1 + 6032, j);
  if ( !*(_DWORD *)(v10 + 5912) )
  {
    result = sde_power_handle_register_event(v10 + 16, 27, sde_crtc_handle_power_event, a1, a1 + 2176);
    *(_QWORD *)(a1 + 7384) = result;
  }
  if ( *(int *)(v12 + 464) >= 1 )
  {
    v29 = 0;
    v30 = v12 + 336;
    do
    {
      if ( v29 == 16 )
        __break(0x5512u);
      result = sde_connector_schedule_status_work(*(_QWORD *)(v30 + 8 * v29), 1);
      v31 = *(_QWORD *)(v30 + 8 * v29);
      v43 = 0;
      if ( !v31 )
        goto LABEL_43;
      v32 = *(_QWORD *)(*(_QWORD *)(v31 + 2512) + 16LL);
      result = sde_encoder_is_built_in_display(v32);
      if ( (result & 1) == 0 )
        goto LABEL_43;
      if ( (sde_encoder_check_curr_mode(v32, 2) & 1) != 0 && (sde_encoder_get_transfer_time(v32, &v43), v43) )
      {
        v33 = (v43 + 999999) / v43;
        v34 = *(_QWORD *)(v31 + 2512);
        if ( !v34 )
          goto LABEL_54;
      }
      else
      {
        v33 = (int)drm_mode_vrefresh(a1 + 176);
        v34 = *(_QWORD *)(v31 + 2512);
        if ( !v34 )
          goto LABEL_54;
      }
      v35 = *(_QWORD *)(v34 + 1376) - 4LL;
      if ( v35 > 0xC )
      {
LABEL_54:
        v36 = 1;
        goto LABEL_55;
      }
      v36 = dword_287468[v35];
LABEL_55:
      v37 = *(unsigned __int16 *)(a1 + 186);
      v38 = *(unsigned __int16 *)(a1 + 196);
      v39 = ((unsigned __int16)(105 * (v37 * v38 * v33 % 0x64uLL)) / 0x64u + 105 * (v37 * v38 * v33 / 0x64uLL)) / v36;
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "[%s] h=%d v=%d fps=%lld lm=%d mode_clk=%llu\n",
          (const char *)(a1 + 256),
          v37,
          v38,
          v33,
          v36,
          ((unsigned __int16)(105 * (v37 * v38 * v33 % 0x64uLL)) / 0x64u + 105 * (v37 * v38 * v33 / 0x64uLL)) / v36);
      result = sde_core_perf_crtc_reserve_res(a1, v39);
LABEL_43:
      ++v29;
    }
    while ( v29 < *(int *)(v12 + 464) );
  }
LABEL_65:
  _ReadStatusReg(SP_EL0);
  return result;
}
