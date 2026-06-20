void __fastcall ipareg_construct_qtime_timestamp_cfg(__int64 a1, _DWORD *a2, int *a3)
{
  int v3; // w8
  int v4; // w8
  int v5; // w8
  int v6; // w8
  int *v7; // x19
  _DWORD *v8; // x20
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  v3 = *a2;
  if ( (a2[1] & 1) == 0 && v3 )
  {
    v7 = a3;
    v8 = a2;
    printk(&unk_3BFCCE, "ipareg_construct_qtime_timestamp_cfg");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipahal %s:%d non zero DPL shift while legacy mode\n",
        "ipareg_construct_qtime_timestamp_cfg",
        1001);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipahal %s:%d non zero DPL shift while legacy mode\n",
        "ipareg_construct_qtime_timestamp_cfg",
        1001);
    }
    __break(0x800u);
    v3 = *v8;
    a2 = v8;
    a3 = v7;
  }
  v4 = *a3 | v3 & 0x1F;
  *a3 = v4;
  v5 = v4 | (*((unsigned __int8 *)a2 + 4) << 7);
  *a3 = v5;
  v6 = ((a2[2] & 0x1F) << 8) | v5;
  *a3 = v6;
  *a3 = ((a2[3] & 0x1F) << 16) | v6;
}
