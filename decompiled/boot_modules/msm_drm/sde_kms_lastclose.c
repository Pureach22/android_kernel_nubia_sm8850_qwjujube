__int64 __fastcall sde_kms_lastclose(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x0
  int v4; // w6
  int v5; // w7
  int v7; // w0
  unsigned __int64 plane_state; // x25
  __int64 v9; // x26
  _QWORD *v10; // x23
  int v11; // w0
  _QWORD *v12; // x23
  int v13; // w0
  __int64 v14; // x0
  __int64 v15; // x26
  int v16; // w0
  int v17; // w7
  void *v18; // x0
  __int64 result; // x0
  int v25; // w8
  int v26; // w7
  char v27; // [xsp+0h] [xbp-60h]
  _QWORD v28[8]; // [xsp+8h] [xbp-58h] BYREF
  _QWORD v29[3]; // [xsp+48h] [xbp-18h] BYREF

  v29[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v28, 0, sizeof(v28));
  if ( a1 )
  {
    v2 = *(_QWORD *)(a1 + 136);
    drm_modeset_acquire_init(v28, 0);
    v3 = drm_atomic_state_alloc(v2);
    if ( v3 )
    {
      _X19 = v3;
      v7 = sde_dbg_base_evtlog;
      *(_QWORD *)(_X19 + 72) = v28;
      sde_evtlog_log(v7, "sde_kms_lastclose", 3322, -1, 4369, -1059143953, v4, v5, v27);
      while ( 1 )
      {
        LODWORD(plane_state) = drm_modeset_lock_all_ctx(v2, v28);
        if ( !(_DWORD)plane_state )
        {
          v9 = *(_QWORD *)(a1 + 136);
          v29[0] = 0;
          v29[1] = 0;
          v10 = (_QWORD *)(v9 + 840);
          while ( 1 )
          {
            v10 = (_QWORD *)*v10;
            if ( v10 == (_QWORD *)(v9 + 840) )
              break;
            plane_state = drm_atomic_get_plane_state(_X19, v10 - 1);
            if ( plane_state >= 0xFFFFFFFFFFFFF001LL )
            {
              printk(&unk_22E734, "_sde_kms_helper_reset_custom_properties");
              goto LABEL_21;
            }
            v11 = sde_plane_helper_reset_custom_properties(v10 - 1, plane_state);
            if ( v11 )
            {
              LODWORD(plane_state) = v11;
              v18 = &unk_22B118;
              goto LABEL_26;
            }
          }
          v12 = (_QWORD *)(v9 + 864);
          while ( 1 )
          {
            v12 = (_QWORD *)*v12;
            if ( v12 == (_QWORD *)(v9 + 864) )
              break;
            plane_state = drm_atomic_get_crtc_state(_X19, v12 - 2);
            if ( plane_state >= 0xFFFFFFFFFFFFF001LL )
            {
              v18 = &unk_2354B2;
              goto LABEL_26;
            }
            v13 = sde_crtc_helper_reset_custom_properties((__int64)(v12 - 2), plane_state);
            if ( v13 )
            {
              LODWORD(plane_state) = v13;
              v18 = &unk_26276E;
              goto LABEL_26;
            }
          }
          drm_connector_list_iter_begin(v9, v29);
          while ( 1 )
          {
            v14 = drm_connector_list_iter_next(v29);
            if ( !v14 )
            {
              drm_connector_list_iter_end(v29);
              LODWORD(plane_state) = drm_atomic_commit(_X19);
              goto LABEL_21;
            }
            v15 = v14;
            plane_state = drm_atomic_get_connector_state(_X19, v14);
            if ( plane_state >= 0xFFFFFFFFFFFFF001LL )
              break;
            v16 = sde_connector_helper_reset_custom_properties(v15, plane_state);
            if ( v16 )
            {
              LODWORD(plane_state) = v16;
              v18 = &unk_273F83;
              goto LABEL_26;
            }
          }
          v18 = &unk_219CD8;
LABEL_26:
          printk(v18, "_sde_kms_helper_reset_custom_properties");
        }
LABEL_21:
        if ( (_DWORD)plane_state != -35 )
          break;
        drm_atomic_state_clear(_X19);
        drm_modeset_backoff(v28);
        sde_evtlog_log(sde_dbg_base_evtlog, "sde_kms_lastclose", 3385, -1, -35, 13107, -1059143953, v17, v27);
      }
      __asm { PRFM            #0x11, [X19] }
      do
        v25 = __ldxr((unsigned int *)_X19);
      while ( __stlxr(v25 - 1, (unsigned int *)_X19) );
      if ( v25 == 1 )
      {
        __dmb(9u);
        _drm_atomic_state_free(_X19);
      }
      else if ( v25 <= 0 )
      {
        refcount_warn_saturate(_X19, 3);
      }
    }
    else
    {
      LODWORD(plane_state) = -12;
    }
    drm_modeset_drop_locks(v28);
    drm_modeset_acquire_fini(v28);
    if ( (_DWORD)plane_state )
      printk(&unk_23F7EB, "sde_kms_lastclose");
    result = sde_evtlog_log(
               sde_dbg_base_evtlog,
               "sde_kms_lastclose",
               3378,
               -1,
               plane_state,
               8738,
               -1059143953,
               v26,
               v27);
  }
  else
  {
    result = printk(&unk_215A31, "sde_kms_lastclose");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
