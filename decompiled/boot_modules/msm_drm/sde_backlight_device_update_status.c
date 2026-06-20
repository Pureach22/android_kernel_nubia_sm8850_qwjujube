__int64 __fastcall sde_backlight_device_update_status(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 v8; // x20
  __int64 v9; // x8
  __int64 v10; // x19
  int v11; // w9
  unsigned int v12; // w8
  _QWORD *v13; // x9
  _QWORD *v14; // x9
  __int64 v15; // x10
  unsigned int v16; // w21
  __int64 v17; // x8
  unsigned int v18; // w8
  bool v19; // zf
  int v20; // w22
  __int64 v21; // x0
  __int64 v22; // x8
  __int64 (__fastcall *v23)(_QWORD); // x8
  __int64 v24; // x8
  __int64 v25; // x23
  __int64 v26; // x0
  int v27; // w5
  int v28; // w6
  int v29; // w0
  int v30; // w2
  int v31; // w4
  int v32; // w7
  int v33; // w0
  __int64 v34; // x0
  void *v35; // x0
  __int64 result; // x0
  __int64 v37; // x24
  __int64 v38; // x0
  __int64 v39; // x8
  int v40; // w9
  __int64 v41; // x8
  unsigned int v42; // w8
  __int64 v43; // x9
  __int64 v44; // x24
  _BOOL4 v45; // w6
  int v46; // w7
  int v47; // w6
  int v48; // w0
  int v49; // w6
  int v50; // w7
  void *v51; // x0
  char v52; // [xsp+0h] [xbp-10h]
  char v53; // [xsp+0h] [xbp-10h]
  char v54; // [xsp+0h] [xbp-10h]
  char v55; // [xsp+0h] [xbp-10h]
  __int64 v56; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(a1 + 320);
  if ( !v8 || !*(_QWORD *)v8 || (v9 = *(_QWORD *)(*(_QWORD *)v8 + 56LL)) == 0 )
  {
    v35 = &unk_242658;
LABEL_49:
    printk(v35, "sde_connector_get_kms");
    printk(&unk_234896, "sde_backlight_device_update_status");
    return 4294967274LL;
  }
  v10 = *(_QWORD *)(v9 + 8);
  if ( !v10 )
  {
    v35 = &unk_234896;
    goto LABEL_49;
  }
  if ( *(_DWORD *)(a1 + 8) )
  {
    v11 = *(_DWORD *)(a1 + 16);
    v12 = 0;
  }
  else
  {
    v11 = *(_DWORD *)(a1 + 16);
    v12 = *(_DWORD *)a1;
    if ( (v11 & 3) != 0 )
      v12 = 0;
  }
  if ( sde_backlight_device_update_status_state != v11 && !v12 )
  {
    sde_backlight_device_update_status_state = v11;
    if ( !v11 )
      return 0;
  }
  if ( *(_DWORD *)(v8 + 2736) != 16 )
    return 0;
  v13 = (_QWORD *)(v8 + 2760);
  if ( *(_BYTE *)(v8 + 5128) == 1 )
    v13 = (_QWORD *)*v13;
  v14 = (_QWORD *)*v13;
  if ( !v14 )
    return 0;
  v15 = v14[33];
  if ( v12 >= *(_DWORD *)(v15 + 1488) )
    v12 = *(_DWORD *)(v15 + 1488);
  if ( *(_QWORD *)(v8 + 4400) >= (unsigned __int64)(int)v12 )
    v16 = v12;
  else
    v16 = *(_QWORD *)(v8 + 4400);
  *(_DWORD *)(v15 + 1492) = v16;
  v17 = v14[33];
  v18 = v16 % *(_DWORD *)(v17 + 1488) * *(_DWORD *)(v17 + 1484) / *(_DWORD *)(v17 + 1488)
      + v16 / *(_DWORD *)(v17 + 1488) * *(_DWORD *)(v17 + 1484);
  if ( v18 )
    v19 = 1;
  else
    v19 = v16 == 0;
  if ( v19 )
    v20 = v18;
  else
    v20 = 1;
  if ( (*(_BYTE *)(v8 + 4540) & 1) == 0 )
  {
    *(_DWORD *)(v8 + 4536) = v20;
    return 0;
  }
  sde_evtlog_log(sde_dbg_base_evtlog, "sde_backlight_device_update_status", 434, -1, v20, v16, -1059143953, a8, v52);
  v21 = *(_QWORD *)(v10 + 6384);
  if ( v21 )
  {
    mutex_lock(v21);
    v22 = *(_QWORD *)(v10 + 6384);
    if ( v22 )
    {
      v23 = *(__int64 (__fastcall **)(_QWORD))(v22 + 88);
      if ( v23 )
      {
        if ( *((_DWORD *)v23 - 1) != 1370937740 )
          __break(0x8228u);
        if ( (v23(v10) & 1) == 0 )
        {
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(0, 0, 0, "skipping bl update due to HW unavailablity\n");
          goto LABEL_53;
        }
      }
    }
  }
  if ( *(_QWORD *)(v8 + 2968) )
  {
    if ( !*(_DWORD *)(v8 + 4724) || !*(_DWORD *)(v8 + 4688) )
    {
      sde_backlight_set_notify(v8, v16, v20);
      mutex_lock(v8 + 4592);
      v34 = v8 + 4592;
      *(_DWORD *)(v8 + 4552) = v16;
      *(_DWORD *)(v8 + 4564) = v20;
      *(_DWORD *)(v8 + 4548) = v16;
      *(_DWORD *)(v8 + 4560) = v20;
LABEL_51:
      mutex_unlock(v34);
LABEL_52:
      *(_DWORD *)(v8 + 4536) = 0;
      goto LABEL_53;
    }
    v24 = *(_QWORD *)(v8 + 2512);
    if ( !v24 || (v25 = *(_QWORD *)(v24 + 16)) == 0 )
      v25 = *(_QWORD *)(v8 + 2272);
    *(_DWORD *)(v8 + 4576) = 1;
    v26 = mutex_lock(v8 + 4592);
    v27 = *(_DWORD *)(v8 + 4548);
    v28 = *(_DWORD *)(v8 + 3296);
    if ( !v27 || v28 == 5 )
    {
      v29 = sde_dbg_base_evtlog;
      v30 = 326;
      v31 = 13107;
LABEL_43:
      sde_evtlog_log(v29, "sde_connector_begin_incremental_bl", v30, -1, v31, v27, v28, -1059143953, v53);
      sde_encoder_phys_cancel_backlight_timer(v25);
      *(_BYTE *)(v8 + 4572) = 0;
      if ( !(unsigned int)sde_backlight_set_notify(v8, v16, v20) )
      {
        v33 = sde_dbg_base_evtlog;
        *(_DWORD *)(v8 + 4568) = 0;
        *(_DWORD *)(v8 + 4548) = v16;
        *(_DWORD *)(v8 + 4560) = v20;
        *(_DWORD *)(v8 + 4552) = v16;
        *(_DWORD *)(v8 + 4564) = v20;
        sde_evtlog_log(v33, "sde_connector_begin_incremental_bl", 372, -1, v16, v20, -1059143953, v32, v54);
      }
      v34 = v8 + 4592;
      goto LABEL_51;
    }
    if ( *(_BYTE *)(v8 + 4728) != 1 )
      goto LABEL_74;
    v37 = *(_QWORD *)(v8 + 2744);
    v38 = ktime_get(v26);
    v39 = *(_QWORD *)(v8 + 2744);
    v40 = *(_DWORD *)(v37 + 3944);
    if ( v39 )
    {
      if ( v40 )
      {
        if ( *(_QWORD *)(v8 + 4584) )
        {
          if ( *(_QWORD *)v8 && (v41 = *(_QWORD *)(*(_QWORD *)v8 + 56LL)) != 0 )
          {
            if ( *(_QWORD *)(v41 + 8) )
            {
LABEL_66:
              v42 = 0x3B9ACA00u / *(_DWORD *)(v37 + 3944);
              v43 = *(_QWORD *)(v8 + 4584);
              if ( v38 - v43 < *(unsigned int *)(v8 + 4724) * (unsigned __int64)v42 )
              {
                v44 = v38;
                sde_evtlog_log(
                  sde_dbg_base_evtlog,
                  "sde_connector_is_cont_bl_updates",
                  298,
                  -1,
                  (int)v38 / 1000,
                  v43 / 1000,
                  v42 / 0x3E8,
                  -1059143953,
                  v53);
LABEL_72:
                v29 = sde_dbg_base_evtlog;
                v27 = *(_DWORD *)(v8 + 4552);
                v28 = *(_DWORD *)(v8 + 4564);
                *(_QWORD *)(v8 + 4584) = v44;
                v30 = 331;
                v31 = 17476;
                goto LABEL_43;
              }
              *(_QWORD *)(v8 + 4584) = v38;
LABEL_74:
              if ( (*(_BYTE *)(v8 + 4572) & 1) != 0 )
              {
                sde_encoder_phys_cancel_backlight_timer(v25);
                v46 = *(_DWORD *)(v8 + 4552);
                v47 = *(_DWORD *)(v8 + 4564);
                *(_DWORD *)(v8 + 4548) = v46;
                *(_DWORD *)(v8 + 4560) = v47;
              }
              else
              {
                v47 = *(_DWORD *)(v8 + 4564);
                v46 = *(_DWORD *)(v8 + 4552);
              }
              *(_BYTE *)(v8 + 4572) = 1;
              v48 = sde_dbg_base_evtlog;
              *(_DWORD *)(v8 + 4544) = v16;
              *(_DWORD *)(v8 + 4556) = v20;
              *(_DWORD *)(v8 + 4568) = 0;
              sde_evtlog_log(v48, "sde_connector_begin_incremental_bl", 347, -1, v20, v16, v47, v46, 239);
              if ( v25 && (kthread_cancel_delayed_work_sync(v25 + 944) & 1) != 0 )
              {
                sde_evtlog_log(
                  sde_dbg_base_evtlog,
                  "sde_connector_begin_incremental_bl",
                  351,
                  -1,
                  21845,
                  -1059143953,
                  v49,
                  v50,
                  v55);
                sde_encoder_rc_restart_delayed(v25, 1);
              }
              sde_encoder_handle_next_backlight_update(v25);
              mutex_unlock(v8 + 4592);
              *(_DWORD *)(v8 + 4576) = 0;
              goto LABEL_52;
            }
            v56 = v38;
            v51 = &unk_234896;
          }
          else
          {
            v56 = v38;
            v51 = &unk_242658;
          }
          printk(v51, "sde_connector_get_kms");
          v38 = v56;
          goto LABEL_66;
        }
        v44 = v38;
        v45 = 0;
      }
      else
      {
        v44 = v38;
        v45 = 1;
      }
    }
    else
    {
      v44 = v38;
      v45 = v40 == 0;
    }
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_connector_is_cont_bl_updates",
      288,
      -1,
      13107,
      v39 == 0,
      v45,
      *(_QWORD *)(v8 + 4584) == 0,
      239);
    goto LABEL_72;
  }
LABEL_53:
  result = *(_QWORD *)(v10 + 6384);
  if ( !result )
    return result;
  mutex_unlock(result);
  return 0;
}
