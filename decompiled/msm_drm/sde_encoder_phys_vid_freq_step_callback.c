__int64 __fastcall sde_encoder_phys_vid_freq_step_callback(__int64 a1)
{
  __int64 *v1; // x21
  __int64 v2; // x20
  int v5; // w6
  int v6; // w7
  __int64 v7; // x22
  __int64 v8; // x8
  __int64 v9; // x8
  __int64 v10; // x20
  __int64 v11; // x8
  int v12; // w0
  void (__fastcall *v13)(_QWORD); // x9
  __int64 v14; // x0
  __int64 v15; // x8
  void *v16; // x0
  int v18; // w6
  int v19; // w7
  int v20; // w20
  int v21; // w6
  int v22; // w7
  int v23; // w6
  int v24; // w7
  int v25; // w6
  int v26; // w7
  int v27; // w6
  int v28; // w7
  int v29; // w6
  int v30; // w7
  int v36; // w8
  char v37; // [xsp+0h] [xbp-50h]
  _QWORD v38[9]; // [xsp+8h] [xbp-48h] BYREF

  v1 = (__int64 *)(a1 - 2480);
  v38[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 != 2480 )
  {
    v2 = a1 - 2472;
    if ( *(_QWORD *)(a1 - 2472) )
    {
      _X0 = (unsigned int *)sde_encoder_get_disp_op(*v1);
      v7 = *v1;
      if ( *(_BYTE *)(*v1 + 751) != 1 )
        goto LABEL_33;
      if ( *(_BYTE *)(a1 - 128) != 1 )
      {
        if ( *(_BYTE *)(a1 - 127) != 1 || !*(_QWORD *)v2 || !*(_DWORD *)(*(_QWORD *)v2 + 4676LL) )
          goto LABEL_33;
        if ( (unsigned int)_X0 < 3 )
        {
          v13 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 - 2056) + 8LL * (unsigned int)_X0 + 704);
          if ( v13 )
          {
            v14 = *(_QWORD *)(a1 - 2056);
            if ( *((_DWORD *)v13 - 1) != -1596594834 )
              __break(0x8229u);
            v13(v14);
          }
          goto LABEL_33;
        }
        __break(0x5512u);
        goto LABEL_49;
      }
      if ( *(_WORD *)(a1 - 124) != 4 )
        goto LABEL_33;
      v38[6] = 0;
      v38[7] = 0;
      *(_WORD *)(a1 - 124) = 3;
      memset(v38, 0, 48);
      if ( v7 && *(_QWORD *)v7 )
      {
        v8 = *(_QWORD *)(*(_QWORD *)v7 + 56LL);
        if ( v8 )
        {
          v9 = *(_QWORD *)(v8 + 8);
          if ( v9 )
          {
            v10 = *(_QWORD *)(v9 + 136);
            if ( v10 )
            {
LABEL_11:
              v11 = *(_QWORD *)(v10 + 56);
              if ( !v11 || !*(_QWORD *)(v11 + 8) )
                goto LABEL_33;
              sde_evtlog_log(sde_dbg_base_evtlog, "sde_encoder_restore_state", 945, -1, 4369, -1059143953, v5, v6, v37);
              if ( *(_QWORD *)(v7 + 4872)
                || (printk(&unk_249482, "sde_encoder_restore_state"),
                    sde_evtlog_log(
                      sde_dbg_base_evtlog,
                      "sde_encoder_restore_state",
                      948,
                      -1,
                      60333,
                      -1059143953,
                      v18,
                      v19,
                      v37),
                    *(_QWORD *)(v7 + 4872)) )
              {
                drm_mode_config_reset(v10);
              }
              drm_modeset_acquire_init(v38, 0);
              while ( 1 )
              {
                v12 = drm_modeset_lock_all_ctx(v10, v38);
                if ( v12 != -35 )
                  break;
                drm_modeset_backoff(v38);
              }
              if ( v12 )
              {
                __break(0x800u);
                goto LABEL_29;
              }
              v15 = *(_QWORD *)(v7 + 4872);
              if ( !v15 )
              {
LABEL_29:
                drm_modeset_drop_locks(v38);
                drm_modeset_acquire_fini(v38);
                goto LABEL_33;
              }
              *(_QWORD *)(v15 + 72) = v38;
              v20 = drm_atomic_helper_commit_duplicated_state(*(_QWORD *)(v7 + 4872), v38);
              printk(&unk_2494B7, "sde_encoder_restore_state");
              sde_evtlog_log(sde_dbg_base_evtlog, "sde_encoder_restore_state", 970, -1, v20, -1059143953, v21, v22, v37);
              if ( v20 != -35 )
                goto LABEL_38;
              drm_modeset_backoff(v38);
              v20 = drm_atomic_helper_commit_duplicated_state(*(_QWORD *)(v7 + 4872), v38);
              printk(&unk_2494B7, "sde_encoder_restore_state");
              sde_evtlog_log(sde_dbg_base_evtlog, "sde_encoder_restore_state", 970, -1, v20, -1059143953, v23, v24, v37);
              if ( v20 != -35 )
                goto LABEL_38;
              drm_modeset_backoff(v38);
              v20 = drm_atomic_helper_commit_duplicated_state(*(_QWORD *)(v7 + 4872), v38);
              printk(&unk_2494B7, "sde_encoder_restore_state");
              sde_evtlog_log(sde_dbg_base_evtlog, "sde_encoder_restore_state", 970, -1, v20, -1059143953, v25, v26, v37);
              if ( v20 != -35 )
                goto LABEL_38;
              drm_modeset_backoff(v38);
              v20 = drm_atomic_helper_commit_duplicated_state(*(_QWORD *)(v7 + 4872), v38);
              printk(&unk_2494B7, "sde_encoder_restore_state");
              sde_evtlog_log(sde_dbg_base_evtlog, "sde_encoder_restore_state", 970, -1, v20, -1059143953, v27, v28, v37);
              if ( v20 != -35 )
                goto LABEL_38;
              drm_modeset_backoff(v38);
              v20 = drm_atomic_helper_commit_duplicated_state(*(_QWORD *)(v7 + 4872), v38);
              printk(&unk_2494B7, "sde_encoder_restore_state");
              sde_evtlog_log(sde_dbg_base_evtlog, "sde_encoder_restore_state", 970, -1, v20, -1059143953, v29, v30, v37);
              if ( v20 == -35 )
              {
                drm_modeset_backoff(v38);
              }
              else
              {
LABEL_38:
                if ( (v20 & 0x80000000) == 0 )
                {
LABEL_40:
                  _X0 = *(unsigned int **)(v7 + 4872);
LABEL_49:
                  __asm { PRFM            #0x11, [X0] }
                  do
                    v36 = __ldxr(_X0);
                  while ( __stlxr(v36 - 1, _X0) );
                  if ( v36 == 1 )
                  {
                    __dmb(9u);
                    _drm_atomic_state_free();
                  }
                  else if ( v36 <= 0 )
                  {
                    refcount_warn_saturate(_X0, 3);
                  }
                  *(_QWORD *)(v7 + 4872) = 0;
                  goto LABEL_29;
                }
              }
              _drm_err("failed to restore state, %d\n", v20);
              goto LABEL_40;
            }
LABEL_33:
            sde_evtlog_log(
              sde_dbg_base_evtlog,
              "sde_encoder_phys_vid_freq_step_callback",
              1174,
              2,
              *(unsigned __int8 *)(v7 + 751),
              *(unsigned __int8 *)(a1 - 128),
              -1059143953,
              v6,
              v37);
            goto LABEL_34;
          }
        }
        v16 = &unk_234896;
      }
      else
      {
        v16 = &unk_26FCAB;
      }
      printk(v16, "sde_encoder_get_kms");
      v10 = 0x29ED0C0029EE27LL;
      goto LABEL_11;
    }
  }
  printk(&unk_2382D0, "sde_encoder_phys_vid_freq_step_callback");
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return 0;
}
