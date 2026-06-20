__int64 __fastcall sde_connector_trigger_cmd_backlight_sr(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x3
  __int64 v12; // x4
  __int64 v13; // x5
  int v14; // w6
  int v15; // w7
  __int64 v16; // x8
  __int64 v17; // x8
  unsigned int v18; // w20
  int v20; // w7
  char v21; // [xsp+0h] [xbp+0h]
  char v22; // [xsp+0h] [xbp+0h]

  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_connector_trigger_cmd_backlight_sr",
    1757,
    -1,
    4369,
    -1059143953,
    a7,
    a8,
    v21);
  if ( a1 )
  {
    v16 = *(_QWORD *)(a1 + 2512);
    if ( v16 && (v17 = *(_QWORD *)(v16 + 8)) != 0 && !*(_DWORD *)(v17 + 4712) && (*(_BYTE *)(v17 + 6040) & 1) == 0 )
    {
      v18 = sde_connector_trigger_cmd_self_refresh(a1, v9, v10, v11, v12, v13, v14, v15);
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "sde_connector_trigger_cmd_backlight_sr",
        1768,
        -1,
        13107,
        v18,
        -1059143953,
        v20,
        v22);
    }
    else
    {
      v18 = 0;
    }
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_connector_trigger_cmd_backlight_sr",
      1771,
      -1,
      8738,
      *(_DWORD *)(a1 + 64),
      -1059143953,
      v15,
      v22);
  }
  else
  {
    printk(&unk_270664, "sde_connector_trigger_cmd_backlight_sr");
    return (unsigned int)-22;
  }
  return v18;
}
