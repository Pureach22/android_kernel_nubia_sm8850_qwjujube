__int64 __fastcall sde_crtc_commit_kickoff(__int64 result, __int64 a2)
{
  _QWORD *v2; // x24
  __int64 v3; // x20
  __int64 v4; // x8
  __int64 v5; // x23
  __int64 v6; // x8
  __int64 v7; // x19
  __int64 v9; // x28
  __int64 **v10; // x26
  __int64 **v11; // x21
  char v12; // w27
  _BOOL4 v14; // w22
  __int64 v15; // x0
  int v16; // w7
  unsigned __int64 v17; // x8
  unsigned int v18; // w9
  unsigned __int64 v19; // x8
  char v20; // w9
  __int64 v21; // x19
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x9
  int v25; // w7
  int v26; // w0
  int v27; // w4
  int v28; // w2
  int v29; // w5
  __int64 v30; // x2
  __int64 v31; // x3
  __int64 v32; // x4
  __int64 v33; // x5
  int v34; // w6
  int v35; // w7
  __int64 v36; // x8
  __int64 *v37; // x19
  __int64 v38; // x22
  __int64 *v39; // x22
  __int64 v40; // x8
  __int64 v41; // x0
  void *v42; // x0
  unsigned int v48; // w8
  unsigned int v49; // w8
  char v50; // [xsp+0h] [xbp-30h]
  char v51; // [xsp+0h] [xbp-30h]
  __int64 displays_affected; // [xsp+18h] [xbp-18h] BYREF
  __int64 v53; // [xsp+20h] [xbp-10h]
  __int64 v54; // [xsp+28h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  displays_affected = 0;
  v53 = 0;
  if ( !result )
    goto LABEL_91;
  v2 = *(_QWORD **)result;
  v3 = result;
  if ( !*(_QWORD *)result || (v4 = v2[7]) == 0 )
  {
    v42 = &unk_25E167;
LABEL_90:
    printk(v42, "_sde_crtc_get_kms");
LABEL_91:
    result = printk(&unk_215A31, "sde_crtc_commit_kickoff");
    goto LABEL_92;
  }
  v5 = *(_QWORD *)(v4 + 8);
  if ( !v5 )
  {
    v42 = &unk_234896;
    goto LABEL_90;
  }
  v6 = *(_QWORD *)(v5 + 136);
  if ( !v6 || !*(_QWORD *)(v6 + 56) )
    goto LABEL_91;
  if ( *(_DWORD *)(result + 2192) )
  {
    v7 = *(_QWORD *)(result + 2008);
    _ReadStatusReg(SP_EL0);
    if ( v7 )
      v9 = *(_QWORD *)(v7 + 1504);
    else
      LODWORD(v9) = 0;
    *(_BYTE *)(result + 7944) = 0;
    v10 = (__int64 **)(v2 + 102);
    *(_BYTE *)(result + 6040) = 1;
    v11 = (__int64 **)v2[103];
    if ( v11 == v2 + 102 )
    {
      v12 = 0;
    }
    else
    {
      v12 = 0;
      do
      {
        if ( v11[9] == (__int64 *)v3 )
        {
          displays_affected = (unsigned int)sde_crtc_get_displays_affected(v3, *(_QWORD *)(v3 + 2008));
          if ( (unsigned int)sde_encoder_prepare_for_kickoff(v11 - 1, &displays_affected) )
            *(_BYTE *)(v3 + 7756) = 1;
          if ( (_DWORD)v9 )
            sde_encoder_control_idle_pc(v11 - 1, (_DWORD)v9 == 1);
          result = sde_encoder_get_intf_mode(v11 - 1);
          v12 |= (_DWORD)result == 2;
        }
        v11 = (__int64 **)v11[1];
      }
      while ( v11 != v10 );
    }
    if ( *(_BYTE *)(v3 + 7756) == 1 )
    {
      _ZF = HIDWORD(v53) == 2;
      *(_DWORD *)(v3 + 7584) = HIDWORD(v53);
      if ( _ZF )
      {
        v14 = 0;
      }
      else
      {
        result = sde_crtc_reset_hw((__int64 *)v3, a2, v53);
        v14 = result != 0;
      }
      *(_BYTE *)(v3 + 7756) = 0;
    }
    else
    {
      v14 = 0;
    }
    v15 = ktime_get(result);
    v17 = (v15 - *(_QWORD *)(v3 + 4456)) / 1000;
    v18 = *(_DWORD *)(v3 + 4448) + 1;
    *(_DWORD *)(v3 + 4448) = v18;
    if ( v17 >= 0xF4240 )
    {
      v19 = 10000000 * (unsigned __int64)v18 / (unsigned int)v17;
      v20 = _drm_debug;
      *(_DWORD *)(v3 + 4464) = v19;
      if ( (v20 & 4) != 0 )
      {
        v21 = v15;
        _drm_dev_dbg(
          0,
          0,
          0,
          " FPS for crtc%d is %d.%d\n",
          *(_DWORD *)(v3 + 112),
          (unsigned int)v19 / 0xA,
          (unsigned int)v19 % 0xA);
        v15 = v21;
      }
      *(_QWORD *)(v3 + 4456) = v15;
      *(_DWORD *)(v3 + 4448) = 0;
    }
    if ( *(_QWORD *)(v3 + 4472) )
    {
      v22 = ktime_get(v15);
      v23 = *(unsigned int *)(v3 + 4480);
      v24 = *(_QWORD *)(v3 + 4472);
      *(_DWORD *)(v3 + 4480) = v23 + 1;
      *(_QWORD *)(v24 + 8 * v23) = v22;
      *(_DWORD *)(v3 + 4480) %= 0x3E8u;
    }
    if ( *(_DWORD *)(v3 + 4712) )
    {
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "_sde_crtc_flush_frame_events",
        5440,
        -1,
        *(_DWORD *)(v3 + 112),
        4369,
        -1059143953,
        v16,
        v50);
      if ( *(_QWORD *)(v3 + 4776) == v3 + 4776 )
        kthread_flush_work(v3 + 4720);
      if ( *(_QWORD *)(v3 + 4864) == v3 + 4864 )
        kthread_flush_work(v3 + 4808);
      if ( *(_QWORD *)(v3 + 4952) == v3 + 4952 )
        kthread_flush_work(v3 + 4896);
      if ( *(_QWORD *)(v3 + 5040) == v3 + 5040 )
        kthread_flush_work(v3 + 4984);
      if ( *(_QWORD *)(v3 + 5128) == v3 + 5128 )
        kthread_flush_work(v3 + 5072);
      if ( *(_QWORD *)(v3 + 5216) == v3 + 5216 )
        kthread_flush_work(v3 + 5160);
      if ( *(_QWORD *)(v3 + 5304) == v3 + 5304 )
        kthread_flush_work(v3 + 5248);
      if ( *(_QWORD *)(v3 + 5392) == v3 + 5392 )
        kthread_flush_work(v3 + 5336);
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "_sde_crtc_flush_frame_events",
        5451,
        4,
        *(_DWORD *)(v3 + 112),
        8738,
        -1059143953,
        v25,
        v51);
    }
    else if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "no frames pending\n");
    }
    *(_DWORD *)(v3 + 7568) = *(_DWORD *)(*(_QWORD *)(v3 + 2008) + 12LL);
    _X9 = (unsigned int *)(v3 + 4712);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v48 = __ldxr(_X9);
      v49 = v48 + 1;
    }
    while ( __stlxr(v49, _X9) );
    __dmb(0xBu);
    if ( v49 == 1 )
    {
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "crtc%d first commit\n", *(_DWORD *)(v3 + 112));
      v26 = sde_dbg_base_evtlog;
      v27 = *(_DWORD *)(v3 + 112);
      v28 = 5754;
      v29 = 13107;
    }
    else
    {
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "crtc%d commit\n", *(_DWORD *)(v3 + 112));
      v26 = sde_dbg_base_evtlog;
      v27 = *(_DWORD *)(v3 + 112);
      v28 = 5757;
      v29 = 17476;
    }
    sde_evtlog_log(v26, "sde_crtc_commit_kickoff", v28, -1, v27, v29, -1059143953, v16, v50);
    ++*(_QWORD *)(v3 + 4416);
    result = sde_vbif_clear_errors(v5);
    if ( v14 )
    {
      v36 = *(_QWORD *)v3;
      v37 = *(__int64 **)(*(_QWORD *)v3 + 840LL);
      if ( v37 != (__int64 *)(*(_QWORD *)v3 + 840LL) )
      {
        v38 = *(_QWORD *)(v3 + 2208);
        do
        {
          if ( ((*(_DWORD *)(*(_QWORD *)(v3 + 2008) + 12LL) >> *((_DWORD *)v37 + 437)) & 1) != 0 && v37[220] )
          {
            ((void (__fastcall *)(__int64 *, __int64, _QWORD))sde_plane_ctl_flush)(v37 - 1, v38, 0);
            v36 = *(_QWORD *)v3;
          }
          v37 = (__int64 *)*v37;
        }
        while ( v37 != (__int64 *)(v36 + 840) );
      }
      result = (__int64)sde_crtc_blend_setup((char *)v3, 0, v30, v31, v32, v33, v34, v35);
    }
    if ( (*(_QWORD *)(v3 + 7928) & 1) != 0 )
      result = sde_fence_update_hw_fences_txq(*(_QWORD *)(v3 + 3232), v12 & 1, 0, *(unsigned int *)(v5 + 6400));
    v39 = *v10;
    if ( *(_QWORD *)(v3 + 8016) && v39 != (__int64 *)v10 )
    {
      do
      {
        if ( ((*(_DWORD *)(*(_QWORD *)(v3 + 2008) + 20LL) >> *((_DWORD *)v39 + 15)) & 1) != 0 )
        {
          result = ((__int64 (__fastcall *)(__int64 *))sde_encoder_in_clone_mode)(v39 - 1);
          if ( (result & 1) == 0 )
          {
            result = sde_encoder_check_curr_mode(v39 - 1, 1);
            if ( (result & 1) == 0 )
              result = sde_encoder_begin_commit(v39 - 1);
          }
        }
        v39 = (__int64 *)*v39;
      }
      while ( v39 != (__int64 *)v10 );
      v39 = *v10;
    }
    while ( v39 != (__int64 *)v10 )
    {
      if ( v39[9] == v3 )
        result = sde_encoder_kickoff(v39 - 1, 1);
      v39 = (__int64 *)*v39;
    }
    v40 = *(_QWORD *)(v3 + 2584);
    *(_BYTE *)(v3 + 6040) = 0;
    if ( v40 )
    {
      __break(0x800u);
    }
    else
    {
      v41 = raw_spin_lock_irqsave(v2 + 53);
      *(_QWORD *)(v3 + 2584) = *(_QWORD *)(*(_QWORD *)(v3 + 2008) + 312LL);
      result = raw_spin_unlock_irqrestore(v2 + 53, v41);
    }
  }
LABEL_92:
  _ReadStatusReg(SP_EL0);
  return result;
}
