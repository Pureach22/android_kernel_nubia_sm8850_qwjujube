void __fastcall ipareg_construct_endp_init_hol_block_timer_n_v4_5(__int64 a1, __int64 a2, int *a3)
{
  int v3; // w8
  int *v4; // x19
  __int64 v5; // x20
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( *(unsigned __int8 *)(a2 + 14) >= 2u )
  {
    v4 = a3;
    v5 = a2;
    printk(&unk_3CEC52, "ipareg_construct_endp_init_hol_block_timer_n_v4_5");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipahal %s:%d Pulse generator is not 0 or 1 %d\n",
        "ipareg_construct_endp_init_hol_block_timer_n_v4_5",
        2168,
        *(unsigned __int8 *)(v5 + 14));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipahal %s:%d Pulse generator is not 0 or 1 %d\n",
        "ipareg_construct_endp_init_hol_block_timer_n_v4_5",
        2168,
        *(unsigned __int8 *)(v5 + 14));
    }
    a2 = v5;
    __break(0x800u);
    a3 = v4;
  }
  v3 = *a3 | *(_BYTE *)(a2 + 15) & 0x1F;
  *a3 = v3;
  *a3 = ((*(_BYTE *)(a2 + 14) & 1) << 8) | v3;
}
