__int64 __fastcall sde_kms_trigger_null_flush(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  int v8; // w8
  __int64 result; // x0
  __int64 v11; // x8
  char v12; // w9
  __int64 v13; // x22
  char v14; // w21
  __int64 v15; // x8
  _QWORD *v16; // x26
  int v17; // w0
  int v18; // w4
  __int64 v19; // x27
  __int64 v20; // x28
  int v21; // w0
  unsigned int v22; // w22
  __int64 v24; // x0
  int v26; // w27
  int v31; // w8
  char v32; // [xsp+0h] [xbp-50h]
  _QWORD v33[9]; // [xsp+8h] [xbp-48h] BYREF

  v33[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    printk(&unk_234896, "sde_kms_trigger_null_flush");
    result = 4294967274LL;
    goto LABEL_39;
  }
  v8 = *(_DWORD *)(a1 + 2544);
  if ( !v8 )
  {
LABEL_38:
    result = 0;
    goto LABEL_39;
  }
  if ( *(_DWORD *)(a1 + 3568) != v8 )
  {
    v11 = 0;
    v12 = 1;
    while ( 1 )
    {
      v13 = a1 + 2712 + 80 * v11;
      v14 = v12;
      if ( *(_BYTE *)v13 == 1 )
      {
        v15 = *(_QWORD *)(v13 + 8);
        if ( v15 )
          break;
      }
LABEL_7:
      v12 = 0;
      v11 = 1;
      if ( (v14 & 1) == 0 )
        goto LABEL_38;
    }
    v16 = *(_QWORD **)(v15 + 80);
    if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "triggering null commit on enc:%d\n", *(_DWORD *)(v15 + 24));
      v15 = *(_QWORD *)(v13 + 8);
      v17 = sde_dbg_base_evtlog;
      if ( !v15 )
      {
        v18 = -1;
        goto LABEL_14;
      }
    }
    else
    {
      v17 = sde_dbg_base_evtlog;
    }
    v18 = *(_DWORD *)(v15 + 24);
LABEL_14:
    sde_evtlog_log(v17, "sde_kms_trigger_null_flush", 4817, -1, v18, 4369, -1059143953, a8, v32);
    v19 = *(_QWORD *)(a1 + 136);
    v20 = *(_QWORD *)(v13 + 8);
    memset(v33, 0, 64);
    drm_modeset_acquire_init(v33, 0);
    v21 = drm_modeset_lock_all_ctx(v19, v33);
    if ( v21 == -35 )
    {
      v22 = 0;
      do
      {
        drm_modeset_backoff(v33);
        _const_udelay(2147500);
        v21 = drm_modeset_lock_all_ctx(v19, v33);
        if ( v21 != -35 )
          break;
      }
      while ( v22++ < 0x13 );
    }
    if ( v21 )
    {
      __break(0x800u);
      v26 = 1;
    }
    else
    {
      v24 = drm_atomic_state_alloc(v19);
      if ( v24 )
      {
        _X22 = (unsigned int *)v24;
        *(_QWORD *)(v24 + 72) = v33;
        v26 = sde_kms_set_crtc_for_conn(v19, v20, v24);
        if ( !v26 )
        {
          v26 = drm_atomic_commit(_X22);
          if ( v26 )
            printk(&unk_2773E0, "_sde_kms_null_commit");
        }
        __asm { PRFM            #0x11, [X22] }
        do
          v31 = __ldxr(_X22);
        while ( __stlxr(v31 - 1, _X22) );
        if ( v31 == 1 )
        {
          __dmb(9u);
          _drm_atomic_state_free(_X22);
        }
        else if ( v31 <= 0 )
        {
          refcount_warn_saturate(_X22, 3);
        }
      }
      else
      {
        _drm_err("failed to allocate atomic state, %d\n", 0);
        v26 = 0;
      }
    }
    drm_modeset_drop_locks(v33);
    drm_modeset_acquire_fini(v33);
    if ( !v26 && v16 )
    {
      sde_kms_cancel_delayed_work(v16);
    }
    else if ( v26 )
    {
      _drm_err("null flush commit failure during lastclose\n");
    }
    goto LABEL_7;
  }
  result = 4294967274LL;
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return result;
}
