__int64 __fastcall sde_crtc_frame_event_work(__int64 a1)
{
  _QWORD *v1; // x20
  __int64 v3; // x8
  int *v4; // x22
  int v5; // w8
  __int64 v6; // x23
  int v7; // w0
  int v8; // w0
  int v9; // w4
  int v10; // w5
  int v11; // w2
  int v12; // w3
  int v13; // w6
  __int64 v14; // x8
  _QWORD *i; // x26
  __int64 v16; // x0
  __int64 v17; // x0
  _QWORD *v18; // x8
  _QWORD *v19; // x1
  _QWORD *v20; // x2
  __int64 v21; // x9
  __int64 result; // x0
  void *v23; // x0
  unsigned int v24; // w8
  int v25; // w24
  unsigned int v28; // w10
  int v29; // w7
  unsigned int v36; // w8
  unsigned int v37; // w8
  char v38; // [xsp+0h] [xbp-40h]
  char v39; // [xsp+0h] [xbp-40h]
  int v40; // [xsp+4h] [xbp-3Ch] BYREF
  __int64 v41; // [xsp+8h] [xbp-38h] BYREF
  _QWORD v42[6]; // [xsp+10h] [xbp-30h] BYREF

  v42[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    result = printk(&unk_2656CD, "sde_crtc_frame_event_work");
    goto LABEL_46;
  }
  v1 = *(_QWORD **)(a1 + 40);
  if ( !v1 || !v1[251] )
  {
    result = printk(&unk_25E167, "sde_crtc_frame_event_work");
    goto LABEL_46;
  }
  if ( !*v1 || (v3 = *(_QWORD *)(*v1 + 56LL)) == 0 )
  {
    v23 = &unk_25E167;
LABEL_51:
    printk(v23, "_sde_crtc_get_kms");
    result = printk(&unk_248EC7, "sde_crtc_frame_event_work");
    goto LABEL_46;
  }
  if ( !*(_QWORD *)(v3 + 8) )
  {
    v23 = &unk_234896;
    goto LABEL_51;
  }
  _ReadStatusReg(SP_EL0);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "crtc%d event:%u ts:%lld\n", *((_DWORD *)v1 + 28), *(_DWORD *)(a1 + 80), *(_QWORD *)(a1 + 72));
  v4 = (int *)(v1 + 14);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_crtc_frame_event_work",
    3755,
    4,
    *((_DWORD *)v1 + 28),
    *(_DWORD *)(a1 + 80),
    4369,
    -1059143953,
    v38);
  v5 = *(_DWORD *)(a1 + 80);
  if ( (v5 & 0x20) == 0 && (v5 & 7) != 0 )
  {
    v6 = *(_QWORD *)(*v1 + 8LL);
    v7 = _pm_runtime_resume(v6, 4);
    if ( v7 < 0 )
    {
      v24 = *(_DWORD *)(v6 + 480);
      v25 = v7;
      do
      {
        if ( !v24 )
          break;
        _X12 = (unsigned int *)(v6 + 480);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v28 = __ldxr(_X12);
          if ( v28 != v24 )
            break;
          if ( !__stlxr(v24 - 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v28 == v24;
        v24 = v28;
      }
      while ( !_ZF );
      printk(&unk_24C43E, "sde_crtc_frame_event_work");
      sde_evtlog_log(sde_dbg_base_evtlog, "sde_crtc_frame_event_work", 3767, -1, v25, 60333, -1059143953, v29, v39);
    }
    else
    {
      sde_crtc_get_frame_data(v1);
      _pm_runtime_idle(*(_QWORD *)(*v1 + 8LL), 4);
    }
    if ( *((int *)v1 + 1178) <= 0 )
    {
      printk(&unk_25A8CF, "sde_crtc_frame_event_work");
      v8 = sde_dbg_base_evtlog;
      v9 = *((_DWORD *)v1 + 28);
      v10 = *(_DWORD *)(a1 + 80);
      v11 = 3781;
      v12 = -1;
      v13 = 13107;
    }
    else
    {
      _X9 = (unsigned int *)(v1 + 589);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v36 = __ldxr(_X9);
        v37 = v36 - 1;
      }
      while ( __stlxr(v37, _X9) );
      __dmb(0xBu);
      if ( !v37 )
      {
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "crtc%d ts:%lld last pending\n", *v4, *(_QWORD *)(a1 + 72));
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "sde_crtc_frame_event_work",
          3788,
          -1,
          *((_DWORD *)v1 + 28),
          *(_DWORD *)(a1 + 80),
          17476,
          -1059143953,
          v39);
        sde_core_perf_crtc_release_bw(v1);
        if ( (*(_BYTE *)(a1 + 80) & 8) == 0 )
          goto LABEL_34;
        goto LABEL_18;
      }
      v8 = sde_dbg_base_evtlog;
      v9 = *v4;
      v10 = *(_DWORD *)(a1 + 80);
      v11 = 3792;
      v12 = 4;
      v13 = 21845;
    }
    sde_evtlog_log(v8, "sde_crtc_frame_event_work", v11, v12, v9, v10, v13, -1059143953, v39);
  }
  if ( (*(_BYTE *)(a1 + 80) & 8) != 0 )
  {
LABEL_18:
    sde_fence_signal(v1[404], *(_QWORD *)(a1 + 72), *(_DWORD *)(a1 + 80) & 2, 0);
    v40 = 1;
    if ( *((_BYTE *)v1 + 7924) == 1 )
      sde_crtc_opr_event_notify((__int64)v1);
    v14 = *(_QWORD *)(a1 + 48);
    if ( v14 && *(_BYTE *)(v14 + 5016) == 1 )
      sde_encoder_misr_sign_event_notify(*(_QWORD *)(v14 + 2272));
    if ( *((_BYTE *)v1 + 7945) == 1 )
      sde_crtc_event_notify(v1, 134217745, &v40, 4);
    for ( i = *(_QWORD **)(*v1 + 816LL); i != (_QWORD *)(*v1 + 816LL); i = (_QWORD *)*i )
    {
      if ( (_QWORD *)i[9] == v1
        && (((__int64 (__fastcall *)(_QWORD *))sde_encoder_copr_allow_notify)(i - 1) & 1) != 0
        && *((_BYTE *)v1 + 7947) == 1 )
      {
        v16 = v1[277];
        v41 = 0x2880000013LL;
        memset(v42, 0, 40);
        if ( (unsigned int)sde_dspp_copr_read_status(v16, v42) )
          printk(&unk_2159CA, "sde_crtc_copr_status_event_notify");
        else
          msm_mode_object_event_notify(v1 + 14, *v1, &v41, v42);
      }
    }
  }
LABEL_34:
  if ( (*(_DWORD *)(a1 + 80) & 0x10) != 0 )
  {
    if ( v1[563] )
    {
      v1[555] = *(_QWORD *)(a1 + 72);
      kernfs_notify();
    }
    if ( *(_QWORD *)(a1 + 48) )
      sde_connector_complete_commit();
    else
      printk(&unk_223EF5, "_sde_crtc_retire_event");
  }
  if ( (*(_BYTE *)(a1 + 80) & 4) != 0 )
    printk(&unk_219643, "sde_crtc_frame_event_work");
  v17 = raw_spin_lock_irqsave((char *)v1 + 6036);
  v18 = (_QWORD *)(a1 + 56);
  v19 = (_QWORD *)v1[679];
  v20 = v1 + 678;
  v21 = v17;
  if ( (_QWORD *)(a1 + 56) == v1 + 678 || v19 == v18 || (_QWORD *)*v19 != v20 )
  {
    _list_add_valid_or_report(a1 + 56, v19);
  }
  else
  {
    v1[679] = v18;
    *(_QWORD *)(a1 + 56) = v20;
    *(_QWORD *)(a1 + 64) = v19;
    *v19 = v18;
  }
  result = raw_spin_unlock_irqrestore((char *)v1 + 6036, v21);
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
