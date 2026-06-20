__int64 __fastcall sde_connector_check_update_vhm_cmd(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x1
  unsigned int updated; // w22
  int v5; // w7
  __int64 v6; // x27
  __int64 v7; // x8
  __int64 v8; // x21
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x21
  int v13; // w7
  char v14; // [xsp+0h] [xbp-40h]
  char v15; // [xsp+0h] [xbp-40h]

  if ( !a1 )
  {
    printk(&unk_270664, "sde_connector_check_update_vhm_cmd");
    return (unsigned int)-22;
  }
  v1 = *(_QWORD *)(a1 + 2744);
  if ( v1 )
    *(_DWORD *)(v1 + 4912) = 0;
  if ( (unsigned int)sde_encoder_in_cont_splash(*(_QWORD *)(a1 + 2272)) )
    return 0;
  if ( *(_QWORD *)(a1 + 4704) )
  {
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_connector_check_update_vhm_cmd",
      1510,
      -1,
      *(_DWORD *)(a1 + 4720),
      *(unsigned __int8 *)(a1 + 4716),
      13107,
      -1059143953,
      v14);
    mutex_lock(a1 + 4592);
    v6 = *(_QWORD *)(a1 + 4704);
    if ( (*(_DWORD *)(a1 + 4720) | 4) == 5 || sde_encoder_is_self_refresh_completed(v1) )
    {
      v7 = *(_QWORD *)(a1 + 2512);
      if ( !v7
        || *(_DWORD *)(v7 + 1472) != 5
        && ((v8 = *(_QWORD *)(v7 + 8)) == 0
         || (v9 = *(_QWORD *)(v8 + 2008)) == 0
         || (sde_evtlog_log(
               sde_dbg_base_evtlog,
               "sde_crtc_is_power_on_frame",
               1435,
               -1,
               (*(unsigned __int8 *)(v9 + 10) >> 2) & 1,
               *(unsigned __int8 *)(v9 + 9),
               -1059143953,
               v5,
               v15),
             v10 = *(_QWORD *)(v8 + 2008),
             (*(_BYTE *)(v10 + 10) & 4) == 0)
         || (*(_BYTE *)(v10 + 9) & 1) == 0) )
      {
        *(_DWORD *)(a1 + 4720) = 0;
        *(_WORD *)(a1 + 4716) = 257;
      }
    }
    if ( *(_BYTE *)(a1 + 4716) == 1 )
    {
      v11 = 1LL << (*(_BYTE *)(v6 + 24) + 28);
      if ( (*(_BYTE *)(a1 + 4717) & 1) == 0 )
        goto LABEL_24;
    }
    else
    {
      v11 = 0;
      if ( *(_BYTE *)(a1 + 4717) != 1 )
      {
        updated = 0;
LABEL_26:
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "sde_connector_check_update_vhm_cmd",
          1542,
          -1,
          17476,
          updated,
          SHIDWORD(v11),
          v11,
          *(_DWORD *)(v6 + 24));
        *(_WORD *)(a1 + 4716) = 0;
        mutex_unlock(a1 + 4592);
        return updated;
      }
    }
    if ( *(_BYTE *)(v6 + 28) == 1 )
      v11 |= 0x2000000000uLL;
    else
      v11 |= 0x1000000000uLL;
LABEL_24:
    updated = sde_connector_update_cmd(a1, v11, 1);
    if ( v1 )
      *(_DWORD *)(v1 + 4912) = 1;
    goto LABEL_26;
  }
  if ( (_drm_debug & 4) != 0 )
    printk(&unk_243306, v3);
  else
    printk(&unk_23572C, "sde_connector_check_update_vhm_cmd");
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_connector_check_update_vhm_cmd",
    1505,
    -1,
    21845,
    60333,
    -1059143953,
    v13,
    v14);
  return (unsigned int)-22;
}
