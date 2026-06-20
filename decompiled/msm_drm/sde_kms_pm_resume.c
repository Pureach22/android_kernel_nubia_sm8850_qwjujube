__int64 __fastcall sde_kms_pm_resume(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  __int64 v8; // x19
  __int64 v9; // x8
  __int64 v10; // x21
  __int64 *i; // x23
  int v12; // w7
  int v13; // w4
  __int64 result; // x0
  int v15; // w0
  __int64 v16; // x8
  int v17; // w1
  int v19; // w4
  int v25; // w8
  char v26; // [xsp+0h] [xbp-50h]
  char v27; // [xsp+0h] [xbp-50h]
  _QWORD v28[9]; // [xsp+8h] [xbp-48h] BYREF

  v28[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1
    || (v8 = *(_QWORD *)(a1 + 152)) == 0
    || (v9 = *(_QWORD *)(v8 + 56), memset(v28, 0, 64), !v9)
    || (v10 = *(_QWORD *)(v9 + 8)) == 0 )
  {
    result = 4294967274LL;
    goto LABEL_14;
  }
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_kms_pm_resume",
    5073,
    -1,
    *(_QWORD *)(v10 + 2128) != 0,
    -1059143953,
    a7,
    a8,
    v26);
  for ( i = *(__int64 **)(v8 + 816); ; i = (__int64 *)*i )
  {
    if ( i == (__int64 *)(v8 + 816) )
    {
      if ( *(_QWORD *)(v10 + 2128) )
        drm_mode_config_reset(v8);
      drm_modeset_acquire_init(v28, 0);
      while ( 1 )
      {
        v15 = drm_modeset_lock_all_ctx(v8, v28);
        if ( v15 != -35 )
          break;
        drm_modeset_backoff(v28);
      }
      if ( v15 )
      {
        __break(0x800u);
      }
      else
      {
        v16 = *(_QWORD *)(v10 + 2128);
        *(_BYTE *)(v10 + 2136) = 0;
        if ( v16 )
        {
          *(_QWORD *)(v16 + 72) = v28;
          v17 = drm_atomic_helper_commit_duplicated_state(*(_QWORD *)(v10 + 2128), v28);
          if ( v17 != -35 )
            goto LABEL_28;
          drm_modeset_backoff(v28);
          v17 = drm_atomic_helper_commit_duplicated_state(*(_QWORD *)(v10 + 2128), v28);
          if ( v17 != -35 )
            goto LABEL_28;
          drm_modeset_backoff(v28);
          v17 = drm_atomic_helper_commit_duplicated_state(*(_QWORD *)(v10 + 2128), v28);
          if ( v17 == -35
            && (drm_modeset_backoff(v28),
                v17 = drm_atomic_helper_commit_duplicated_state(*(_QWORD *)(v10 + 2128), v28),
                v17 == -35)
            && (drm_modeset_backoff(v28),
                v17 = drm_atomic_helper_commit_duplicated_state(*(_QWORD *)(v10 + 2128), v28),
                v17 == -35) )
          {
            drm_modeset_backoff(v28);
            v17 = -35;
          }
          else
          {
LABEL_28:
            if ( (v17 & 0x80000000) == 0 )
              goto LABEL_30;
          }
          _drm_err("failed to restore state, %d\n", v17);
LABEL_30:
          _X0 = *(unsigned int **)(v10 + 2128);
          __asm { PRFM            #0x11, [X0] }
          do
            v25 = __ldxr(_X0);
          while ( __stlxr(v25 - 1, _X0) );
          if ( v25 == 1 )
          {
            __dmb(9u);
            _drm_atomic_state_free(_X0);
          }
          else if ( v25 <= 0 )
          {
            refcount_warn_saturate(_X0, 3);
          }
          *(_QWORD *)(v10 + 2128) = 0;
        }
      }
      drm_modeset_drop_locks(v28);
      drm_modeset_acquire_fini(v28);
      drm_kms_helper_poll_enable(v8);
      result = 0;
      goto LABEL_14;
    }
    if ( (unsigned int)sde_encoder_in_cont_splash((__int64)(i - 1)) && i[9] )
      break;
  }
  if ( (_drm_debug & 4) != 0 )
  {
    if ( i == (__int64 *)&unk_8 )
      v13 = -1;
    else
      v13 = *((_DWORD *)i + 4);
    _drm_dev_dbg(0, 0, 0, "skip PM resume entry splash is enabled on enc:%d\n", v13);
  }
  if ( i == (__int64 *)&unk_8 )
    v19 = -1;
  else
    v19 = *((_DWORD *)i + 4);
  sde_evtlog_log(sde_dbg_base_evtlog, "sde_kms_pm_resume", 5078, -1, v19, 8738, -1059143953, v12, v27);
  result = 4294967274LL;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
