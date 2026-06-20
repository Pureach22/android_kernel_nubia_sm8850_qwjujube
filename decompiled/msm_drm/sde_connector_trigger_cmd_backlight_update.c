__int64 __fastcall sde_connector_trigger_cmd_backlight_update(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  int v9; // w7
  __int64 result; // x0
  __int64 v11; // x26
  int v12; // w7
  int v13; // w6
  int v14; // w7
  __int64 v15; // x8
  __int64 v16; // x8
  __int64 v17; // x20
  int v18; // w0
  int v19; // w4
  int v20; // w2
  int v21; // w7
  unsigned int v22; // w20
  int v23; // w11
  unsigned int v24; // w10
  int v25; // w22
  int v26; // w6
  int v27; // w21
  int v28; // w9
  int v29; // w8
  unsigned int v30; // w23
  unsigned int v31; // w24
  unsigned int v32; // w0
  int v33; // w6
  unsigned int v34; // w8
  unsigned int v35; // w9
  int v36; // w0
  void *v37; // x0
  char v38; // [xsp+0h] [xbp-50h]
  char v39; // [xsp+0h] [xbp-50h]
  char v40; // [xsp+0h] [xbp-50h]

  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_connector_trigger_cmd_backlight_update",
    1715,
    -1,
    4369,
    -1059143953,
    a7,
    a8,
    v38);
  if ( !a1 )
  {
    printk(&unk_270664, "sde_connector_trigger_cmd_backlight_update");
    return 4294967274LL;
  }
  if ( *(_DWORD *)(a1 + 4576) == 1 )
  {
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_connector_trigger_cmd_backlight_update",
      1723,
      -1,
      *(_DWORD *)(a1 + 64),
      13107,
      -1059143953,
      v9,
      v39);
    return 0;
  }
  v11 = *(_QWORD *)(a1 + 2744);
  if ( (unsigned int)mutex_trylock(v11 + 896) )
  {
    mutex_lock(a1 + 4592);
    if ( (*(_BYTE *)(a1 + 4572) & 1) == 0 )
    {
      v18 = sde_dbg_base_evtlog;
      v20 = 198;
      v19 = 13107;
      goto LABEL_17;
    }
    if ( *(_QWORD *)a1 && (v15 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) != 0 )
    {
      if ( *(_QWORD *)(v15 + 8) )
      {
        v16 = *(_QWORD *)(a1 + 2512);
        if ( (v16 && (v17 = *(_QWORD *)(v16 + 16)) != 0 || (v17 = *(_QWORD *)(a1 + 2272)) != 0)
          && *(_DWORD *)(v17 + 4912) == 1 )
        {
          sde_encoder_handle_next_backlight_update(v17);
          v18 = sde_dbg_base_evtlog;
          v19 = *(_DWORD *)(v17 + 4912);
          v20 = 218;
LABEL_17:
          sde_evtlog_log(v18, "sde_connector_apply_incremental_bl", v20, -1, v19, -1059143953, v13, v14, v39);
LABEL_18:
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "sde_connector_trigger_cmd_backlight_update",
            1744,
            -1,
            8738,
            *(_DWORD *)(a1 + 64),
            -1059143953,
            v21,
            v40);
          v22 = 0;
LABEL_19:
          mutex_unlock(a1 + 4592);
          mutex_unlock(v11 + 896);
          return v22;
        }
        v23 = *(_DWORD *)(a1 + 4568);
        v24 = *(_DWORD *)(a1 + 4724);
        v25 = *(_DWORD *)(a1 + 4544);
        v26 = *(_DWORD *)(a1 + 4548);
        v27 = *(_DWORD *)(a1 + 4556);
        v28 = *(_DWORD *)(a1 + 4560);
        v29 = v23 + 1;
        *(_DWORD *)(a1 + 4568) = v23 + 1;
        if ( v23 + 1 == v24 )
        {
          v30 = v27;
          v31 = v25;
        }
        else if ( v25 <= v26 )
        {
          v31 = v26 - ((v26 - v25) % v24 * v29 / v24 + (v26 - v25) / v24 * v29);
          v30 = v28 + (v28 - v27) / v24 * ~v23 - (v28 - v27) % v24 * v29 / v24;
        }
        else
        {
          v31 = (v25 - v26) % v24 * v29 / v24 + (v25 - v26) / v24 * v29 + v26;
          v30 = v28 + (v27 - v28) / v24 * v29 + (v27 - v28) % v24 * v29 / v24;
        }
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "sde_connector_apply_incremental_bl",
          250,
          -1,
          *(_DWORD *)(a1 + 64),
          v25,
          v26,
          v27,
          v28);
        _ReadStatusReg(SP_EL0);
        v32 = sde_backlight_set_notify(a1, v31, v30);
        if ( !v32 )
        {
          v34 = *(_DWORD *)(a1 + 4568);
          v35 = *(_DWORD *)(a1 + 4724);
          *(_DWORD *)(a1 + 4552) = v31;
          *(_DWORD *)(a1 + 4564) = v30;
          if ( v34 >= v35 )
          {
            v36 = sde_dbg_base_evtlog;
            *(_DWORD *)(a1 + 4568) = 0;
            *(_BYTE *)(a1 + 4572) = 0;
            *(_DWORD *)(a1 + 4548) = v25;
            *(_DWORD *)(a1 + 4560) = v27;
            sde_evtlog_log(v36, "sde_connector_apply_incremental_bl", 269, -1, 17476, -1059143953, v33, v21, v40);
          }
          else if ( *(_BYTE *)(a1 + 4572) == 1 )
          {
            sde_encoder_handle_next_backlight_update(v17);
          }
          goto LABEL_18;
        }
        v22 = v32;
        printk(&unk_2212D7, "sde_connector_apply_incremental_bl");
LABEL_35:
        printk(&unk_26D023, "sde_connector_trigger_cmd_backlight_update");
        goto LABEL_19;
      }
      v37 = &unk_234896;
    }
    else
    {
      v37 = &unk_242658;
    }
    printk(v37, "sde_connector_get_kms");
    printk(&unk_234896, "sde_connector_apply_incremental_bl");
    v22 = -22;
    goto LABEL_35;
  }
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_connector_trigger_cmd_backlight_update",
    1729,
    -1,
    *(_DWORD *)(a1 + 64),
    60333,
    -1059143953,
    v12,
    v39);
  result = *(_QWORD *)(a1 + 2744);
  if ( result )
  {
    sde_encoder_handle_next_backlight_update(result);
    return 0;
  }
  return result;
}
