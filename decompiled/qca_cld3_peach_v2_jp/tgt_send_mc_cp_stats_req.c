__int64 __fastcall tgt_send_mc_cp_stats_req(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *v10; // x8
  __int64 (*v11)(void); // x8
  const char *v12; // x2
  const char *v13; // x3

  if ( !a1 || (v10 = *(_QWORD **)(a1 + 2128)) == nullptr )
  {
    qdf_trace_msg(0x62u, 2u, "%s: tx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_cp_stats_get_tx_ops");
    v12 = "%s: could not get tx_ops";
    goto LABEL_8;
  }
  if ( a2 == 6 )
  {
    v11 = (__int64 (*)(void))v10[41];
    if ( !v11 )
    {
      v12 = "%s: could not get send_req_big_data_stats";
      v13 = "send_big_data_stats_req";
      goto LABEL_9;
    }
LABEL_11:
    if ( *((_DWORD *)v11 - 1) != -794477841 )
      __break(0x8228u);
    return v11();
  }
  if ( a2 == 4 )
  {
    v11 = (__int64 (*)(void))v10[38];
    if ( !v11 )
    {
      v12 = "%s: could not get send_req_peer_stats";
LABEL_8:
      v13 = "tgt_send_mc_cp_stats_req";
LABEL_9:
      qdf_trace_msg(0x62u, 2u, v12, a3, a4, a5, a6, a7, a8, a9, a10, v13);
      return 29;
    }
    goto LABEL_11;
  }
  v11 = (__int64 (*)(void))v10[37];
  if ( !v11 )
  {
    v12 = "%s: could not get send_req_stats";
    goto LABEL_8;
  }
  if ( *((_DWORD *)v11 - 1) != -374870499 )
    __break(0x8228u);
  return v11();
}
