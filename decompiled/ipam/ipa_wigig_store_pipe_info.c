void __fastcall ipa_wigig_store_pipe_info(_QWORD *a1, unsigned int a2)
{
  __int64 ipc_logbuf; // x0
  long double v5; // q0
  __int64 ipc_logbuf_low; // x0
  _QWORD *v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(
      ipc_logbuf,
      "ipa_wigig %s:%d idx %d: desc_ring HWHEAD_pa %pa, HWTAIL_pa %pa, status_ring HWHEAD_pa %pa, HWTAIL_pa %pa\n",
      "ipa_wigig_store_pipe_info",
      567,
      a2,
      a1 + 2,
      a1 + 3,
      a1 + 6,
      a1 + 7);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v5 = ipc_log_string(
           ipc_logbuf_low,
           "ipa_wigig %s:%d idx %d: desc_ring HWHEAD_pa %pa, HWTAIL_pa %pa, status_ring HWHEAD_pa %pa, HWTAIL_pa %pa\n",
           "ipa_wigig_store_pipe_info",
           567,
           a2,
           a1 + 2,
           a1 + 3,
           a1 + 6,
           a1 + 7);
  }
  if ( a2 >= 5 )
  {
    __break(0x5512u);
    ipa_wigig_pipe_to_bit_val(v5);
  }
  else
  {
    v7 = (_QWORD *)(ipa_wigig_ctx + ((unsigned __int64)a2 << 6));
    v7[18] = a1[2];
    v7[19] = a1[3];
    v7[22] = a1[6];
    v7[23] = a1[7];
    if ( ipa3_get_ipc_logbuf() )
    {
      v8 = ipa3_get_ipc_logbuf();
      ipc_log_string(v8, "ipa_wigig %s:%d exit\n", "ipa_wigig_store_pipe_info", 581);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v9 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v9, "ipa_wigig %s:%d exit\n", "ipa_wigig_store_pipe_info", 581);
    }
  }
}
