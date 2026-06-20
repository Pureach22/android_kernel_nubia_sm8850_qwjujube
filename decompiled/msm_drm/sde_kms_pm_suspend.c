__int64 __fastcall sde_kms_pm_suspend(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  __int64 v8; // x21
  __int64 v10; // x8
  __int64 v11; // x20
  __int64 *v12; // x24
  __int64 v13; // x1
  __int64 v14; // x2
  __int64 v15; // x3
  __int64 v16; // x4
  __int64 v17; // x5
  __int64 v18; // x6
  int v19; // w7
  int v20; // w4
  int v21; // w23
  unsigned int v22; // w0
  unsigned int v23; // w27
  int v30; // w8
  unsigned __int64 v31; // x0
  __int64 v32; // x0
  __int64 v34; // x0
  __int64 v35; // x25
  __int64 v36; // x8
  __int64 v37; // x8
  char v38; // w8
  char v39; // w9
  __int64 v40; // x8
  __int64 v41; // x10
  unsigned __int64 crtc_state; // x0
  int v44; // w8
  int v45; // w4
  int v46; // w4
  int v47; // w4
  unsigned int v51; // w9
  char v52; // [xsp+0h] [xbp-60h]
  char v53; // [xsp+0h] [xbp-60h]
  _QWORD v54[2]; // [xsp+8h] [xbp-58h] BYREF
  _QWORD v55[9]; // [xsp+18h] [xbp-48h] BYREF

  v55[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_93;
  v8 = *(_QWORD *)(a1 + 152);
  if ( !v8 )
    goto LABEL_93;
  v10 = *(_QWORD *)(v8 + 56);
  memset(v55, 0, 64);
  if ( !v10 )
    goto LABEL_93;
  v54[0] = 0;
  v54[1] = 0;
  v11 = *(_QWORD *)(v10 + 8);
  if ( !v11 )
    goto LABEL_93;
  sde_evtlog_log(sde_dbg_base_evtlog, "sde_kms_pm_suspend", 4903, -1, 0, -1059143953, a7, a8, v52);
  drm_kms_helper_poll_disable(v8);
  v12 = (__int64 *)(v8 + 816);
  do
  {
    v12 = (__int64 *)*v12;
    if ( v12 == (__int64 *)(v8 + 816) )
    {
      drm_modeset_acquire_init(v55, 0);
      v21 = 0;
      while ( 1 )
      {
        v22 = drm_modeset_lock_all_ctx(v8, v55);
        if ( v22 )
        {
          v23 = v22;
          if ( v22 != -35 )
            goto LABEL_69;
          goto LABEL_67;
        }
        _X0 = *(unsigned int **)(v11 + 2128);
        if ( _X0 )
        {
          __asm { PRFM            #0x11, [X0] }
          do
            v30 = __ldxr(_X0);
          while ( __stlxr(v30 - 1, _X0) );
          if ( v30 == 1 )
          {
            __dmb(9u);
            _drm_atomic_state_free(_X0);
          }
          else if ( v30 <= 0 )
          {
            refcount_warn_saturate(_X0, 3);
          }
        }
        v31 = drm_atomic_helper_duplicate_state(v8, v55);
        v23 = v31;
        *(_QWORD *)(v11 + 2128) = v31;
        if ( v31 && v31 < 0xFFFFFFFFFFFFF001LL )
        {
          v32 = drm_atomic_state_alloc(v8);
          if ( !v32 )
          {
            v23 = -12;
            _drm_err("failed to allocate crtc disable state, %d\n", -12);
            goto LABEL_82;
          }
          _X28 = (unsigned int *)v32;
          *(_QWORD *)(v32 + 72) = v55;
          drm_connector_list_iter_begin(v8, v54);
          v34 = drm_connector_list_iter_next(v54);
          if ( v34 )
          {
            v35 = v34;
            do
            {
              v36 = *(_QWORD *)(v35 + 2512);
              if ( !v36
                || !*(_QWORD *)(v36 + 8)
                || *(_DWORD *)(v35 + 2084)
                || (((__int64 (__fastcall *)(_QWORD))sde_encoder_in_clone_mode)(*(_QWORD *)(v35 + 2272)) & 1) != 0 )
              {
                goto LABEL_30;
              }
              if ( sde_encoder_check_curr_mode(*(_QWORD *)(v35 + 2272), 1) )
              {
                v37 = *(_QWORD *)(v35 + 2272);
                if ( v37 )
                {
                  v38 = *(_BYTE *)(v37 + 749);
                }
                else
                {
                  printk(&unk_26FCAB, "sde_encoder_in_video_psr");
                  v38 = 0;
                }
                v39 = v38 ^ 1;
                v40 = *(_QWORD *)(v35 + 2512);
                if ( !v40 )
                  goto LABEL_43;
              }
              else
              {
                v39 = 0;
                v40 = *(_QWORD *)(v35 + 2512);
                if ( !v40 )
                  goto LABEL_43;
              }
              v41 = *(_QWORD *)(v40 + 1472);
              if ( !((v41 != 1) | v39 & 1) )
              {
                v23 = sde_connector_set_property_for_commit(v35, _X28, 31, 2);
                if ( v23 )
                {
                  _drm_err("failed to set lp2 for conn %d\n", *(_DWORD *)(v35 + 64));
                  drm_connector_list_iter_end(v54);
                  goto LABEL_62;
                }
                v40 = *(_QWORD *)(v35 + 2512);
                goto LABEL_46;
              }
              if ( !((v41 != 2) | v39 & 1) )
                goto LABEL_30;
LABEL_43:
              v23 = 1;
LABEL_46:
              crtc_state = drm_atomic_get_crtc_state(_X28, *(_QWORD *)(v40 + 8));
              if ( !crtc_state || crtc_state >= 0xFFFFFFFFFFFFF001LL )
              {
                _drm_err(
                  "failed to get crtc %d state\n",
                  *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v35 + 2512) + 8LL) + 112LL));
                drm_connector_list_iter_end(v54);
                v23 = -22;
                goto LABEL_62;
              }
              if ( v23 )
                *(_BYTE *)(crtc_state + 9) = 0;
              ++v21;
LABEL_30:
              v35 = drm_connector_list_iter_next(v54);
            }
            while ( v35 );
          }
          drm_connector_list_iter_end(v54);
          if ( v21 )
          {
            v23 = drm_atomic_commit(_X28);
            if ( (v23 & 0x80000000) != 0 )
            {
              _drm_err("failed to disable crtcs, %d\n", v23);
            }
            else
            {
              *(_BYTE *)(v11 + 2136) = 1;
              sde_kms_pm_suspend_idle_helper(v11, a1);
            }
          }
          else
          {
            _drm_dev_dbg(0, 0, 0, "all crtcs are already in the off state\n");
            *(_BYTE *)(v11 + 2136) = 1;
            sde_kms_pm_suspend_idle_helper(v11, a1);
            v23 = 0;
          }
LABEL_62:
          __asm { PRFM            #0x11, [X28] }
          do
            v44 = __ldxr(_X28);
          while ( __stlxr(v44 - 1, _X28) );
          if ( v44 == 1 )
          {
            __dmb(9u);
            _drm_atomic_state_free(_X28);
            if ( v23 != -35 )
              goto LABEL_69;
          }
          else if ( v44 <= 0 )
          {
            refcount_warn_saturate(_X28, 3);
            if ( v23 != -35 )
            {
LABEL_69:
              if ( !v23 && v21 )
              {
                v23 = 0;
                goto LABEL_84;
              }
LABEL_82:
              if ( *(_QWORD *)(v11 + 2128) )
              {
                drm_atomic_state_put();
                *(_QWORD *)(v11 + 2128) = 0;
              }
LABEL_84:
              drm_modeset_drop_locks(v55);
              drm_modeset_acquire_fini(v55);
              _pm_runtime_idle(a1, 4);
              _X8 = (unsigned int *)(a1 + 480);
              __asm { PRFM            #0x11, [X8] }
              do
                v51 = __ldxr(_X8);
              while ( __stxr(v51 + 1, _X8) );
              if ( *(_BYTE *)(v11 + 3746) == 1 )
                sde_kms_dump_clks_state(v11);
              goto LABEL_94;
            }
          }
          else if ( v23 != -35 )
          {
            goto LABEL_69;
          }
        }
        else
        {
          _drm_err("failed to back up suspend state, %d\n", v31);
          *(_QWORD *)(v11 + 2128) = 0;
          if ( v23 != -35 )
            goto LABEL_69;
        }
LABEL_67:
        drm_modeset_backoff(v55);
      }
    }
    if ( (unsigned int)sde_encoder_in_cont_splash((__int64)(v12 - 1)) && v12[9] )
    {
      if ( (_drm_debug & 4) != 0 )
      {
        if ( v12 == (__int64 *)&unk_8 )
          v20 = -1;
        else
          v20 = *((_DWORD *)v12 + 4);
        _drm_dev_dbg(0, 0, 0, "skip PM suspend, splash is enabled on enc:%d\n", v20);
      }
      if ( v12 == (__int64 *)&unk_8 )
        v47 = -1;
      else
        v47 = *((_DWORD *)v12 + 4);
      sde_evtlog_log(sde_dbg_base_evtlog, "sde_kms_pm_suspend", 4916, -1, v47, 8738, -1059143953, v19, v53);
      goto LABEL_93;
    }
  }
  while ( (sde_encoder_smooth_dimming_in_progress((__int64)(v12 - 1), v13, v14, v15, v16, v17, v18, v19) & 1) == 0 );
  if ( (_drm_debug & 4) != 0 )
  {
    if ( v12 == (__int64 *)&unk_8 )
      v45 = -1;
    else
      v45 = *((_DWORD *)v12 + 4);
    _drm_dev_dbg(0, 0, 0, "skip PM suspend, smooth dimming in progress enc:%d\n", v45);
  }
  if ( v12 == (__int64 *)&unk_8 )
    v46 = -1;
  else
    v46 = *((_DWORD *)v12 + 4);
  sde_evtlog_log(sde_dbg_base_evtlog, "sde_kms_pm_suspend", 4923, -1, v46, 13107, 8738, -1059143953, v53);
LABEL_93:
  v23 = -22;
LABEL_94:
  _ReadStatusReg(SP_EL0);
  return v23;
}
