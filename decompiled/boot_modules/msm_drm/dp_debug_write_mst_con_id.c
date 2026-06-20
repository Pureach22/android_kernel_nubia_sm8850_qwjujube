size_t __fastcall dp_debug_write_mst_con_id(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, __int64 *a4)
{
  __int64 v4; // x22
  __int64 v8; // x8
  size_t v9; // x19
  size_t v10; // x0
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v13; // x0
  _QWORD *v14; // x20
  unsigned int v15; // w8
  bool v16; // zf
  __int64 v17; // x8
  __int64 v18; // x21
  __int64 v19; // x20
  __int64 v20; // x0
  __int64 v22; // x0
  __int64 v23; // x21
  __int64 v24; // x0
  unsigned __int64 v25; // x23
  unsigned int v26; // w2
  void *v27; // x0
  __int64 v28; // x0
  unsigned __int64 v29; // x23
  void *v30; // x0
  unsigned int v31; // [xsp+0h] [xbp-30h] BYREF
  unsigned int v32; // [xsp+4h] [xbp-2Ch] BYREF
  char s[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v34; // [xsp+10h] [xbp-20h]
  __int64 v35; // [xsp+18h] [xbp-18h]
  __int64 v36; // [xsp+20h] [xbp-10h]
  __int64 v37; // [xsp+28h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  v32 = 0;
  if ( v4 )
  {
    v35 = 0;
    v36 = 0;
    *(_QWORD *)s = 0;
    v34 = 0;
    v31 = 0;
    mutex_lock(v4 + 376);
    v8 = *a4;
    v9 = 0;
    if ( v8 )
      goto LABEL_27;
    if ( a3 >= 0x1F )
      v9 = 31;
    else
      v9 = a3;
    _check_object_size(s, v9, 0);
    v10 = inline_copy_from_user((__int64)s, a2, v9);
    if ( v10 )
    {
LABEL_7:
      ipc_log_context = get_ipc_log_context(v10);
      StatusReg = _ReadStatusReg(SP_EL0);
      ipc_log_string(ipc_log_context, "[d][%-4d]clearing mst_con_id\n", *(_DWORD *)(StatusReg + 1800));
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]clearing mst_con_id\n", *(_DWORD *)(StatusReg + 1800));
      *(_DWORD *)(v4 + 16) = 0;
      goto LABEL_27;
    }
    s[v9] = 0;
    v10 = sscanf(s, "%d %d", &v32, &v31);
    if ( (_DWORD)v10 != 2 )
    {
LABEL_27:
      mutex_unlock(v4 + 376);
      goto LABEL_28;
    }
    if ( !v32 )
      goto LABEL_7;
    v13 = drm_mode_object_find(***(_QWORD ***)(v4 + 144), 0, v32, 3233857728LL);
    if ( !v13 || (v14 = (_QWORD *)(v13 - 64), v13 == 64) )
    {
      v22 = get_ipc_log_context(v13);
      ipc_log_string(v22, "[e][%-4d]invalid connector id %u\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), v32);
      printk(&unk_25D7DE, "dp_debug_write_mst_con_id");
      goto LABEL_27;
    }
    if ( !*(_QWORD *)(v13 + 2704) || !*(_QWORD *)(v13 + 2712) )
    {
      v19 = v13;
      v20 = get_ipc_log_context(v13);
      ipc_log_string(v20, "[e][%-4d]invalid connector state %d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), v32);
      printk(&unk_26150D, "dp_debug_write_mst_con_id");
      v13 = v19;
      goto LABEL_26;
    }
    v15 = v31;
    v16 = v31 == 3;
    *(_DWORD *)(v4 + 16) = v32;
    if ( v16 )
    {
LABEL_26:
      drm_mode_object_put(v13);
      goto LABEL_27;
    }
    if ( v15 == 2 )
    {
      v23 = v13;
      v28 = get_ipc_log_context(v13);
      v29 = _ReadStatusReg(SP_EL0);
      ipc_log_string(v28, "[i][%-4d]unplug mst connector %d\n", *(_DWORD *)(v29 + 1800), v32);
      v26 = *(_DWORD *)(v29 + 1800);
      if ( (_drm_debug & 4) == 0 )
      {
        v27 = &unk_27C73D;
        goto LABEL_34;
      }
      v30 = &unk_259B6B;
    }
    else
    {
      if ( v15 != 1 )
      {
        v17 = *(_QWORD *)(v13 + 2704);
        if ( v17 )
        {
LABEL_21:
          v18 = v13;
          if ( *(_BYTE *)(v4 + 160) == 1 )
            dp_sim_update_port_status(*(_QWORD *)(v4 + 424), *(unsigned __int8 *)(*(_QWORD *)(v13 + 2712) + 8LL), v31);
          else
            *(_BYTE *)(v17 + 980) = v31 == 2;
          drm_kms_helper_hotplug_event(*v14);
          v13 = v18;
          goto LABEL_26;
        }
        goto LABEL_26;
      }
      v23 = v13;
      v24 = get_ipc_log_context(v13);
      v25 = _ReadStatusReg(SP_EL0);
      ipc_log_string(v24, "[i][%-4d]plug mst connector %d\n", *(_DWORD *)(v25 + 1800), v32);
      v26 = *(_DWORD *)(v25 + 1800);
      if ( (_drm_debug & 4) == 0 )
      {
        v27 = &unk_261545;
LABEL_34:
        printk(v27, "dp_debug_write_mst_con_id");
        goto LABEL_38;
      }
      v30 = &unk_259B39;
    }
    printk(v30, v26);
LABEL_38:
    v13 = v23;
    v17 = *(_QWORD *)(v23 + 2704);
    if ( v17 )
      goto LABEL_21;
    goto LABEL_26;
  }
  v9 = -19;
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return v9;
}
