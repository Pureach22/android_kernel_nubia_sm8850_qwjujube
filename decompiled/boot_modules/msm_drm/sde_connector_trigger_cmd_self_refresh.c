__int64 __fastcall sde_connector_trigger_cmd_self_refresh(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  __int64 v8; // x20
  __int64 (__fastcall *v10)(__int64, __int64); // x8
  __int64 v11; // x0
  __int64 v12; // x2
  __int64 v13; // x3
  __int64 v14; // x4
  __int64 v15; // x5
  __int64 v16; // x6
  int v17; // w7
  void *v19; // x0
  char v20; // [xsp+0h] [xbp+0h]

  if ( !a1 )
  {
    v19 = &unk_270664;
LABEL_13:
    printk(v19, "sde_connector_trigger_cmd_self_refresh");
    return 4294967274LL;
  }
  v8 = *(_QWORD *)(a1 + 2744);
  if ( !v8 )
  {
    v19 = &unk_25EF47;
    goto LABEL_13;
  }
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_connector_trigger_cmd_self_refresh",
    1692,
    -1,
    *(_DWORD *)(a1 + 64),
    -1059143953,
    a7,
    a8,
    v20);
  _ReadStatusReg(SP_EL0);
  if ( *(_BYTE *)(a1 + 4713) != 1 )
    return sde_connector_update_cmd(a1, 0x8000000000LL, 1);
  v10 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 3240);
  v11 = *(_QWORD *)(a1 + 2760);
  if ( *((_DWORD *)v10 - 1) != -1783020508 )
    __break(0x8228u);
  if ( (v10(v11, 39) & 1) != 0 )
    return sde_connector_update_cmd(a1, 0x8000000000LL, 1);
  if ( *(_DWORD *)(v8 + 888) != 4 )
    sde_encoder_handle_video_psr_self_refresh(v8, 0, v12, v13, v14, v15, v16, v17);
  return 0;
}
