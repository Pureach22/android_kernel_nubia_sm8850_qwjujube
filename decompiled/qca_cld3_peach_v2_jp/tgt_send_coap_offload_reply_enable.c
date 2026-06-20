__int64 __fastcall tgt_send_coap_offload_reply_enable(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 (*v12)(void); // x8
  const char *v14; // x2
  const char *v15; // x3

  if ( !a1 )
  {
    qdf_trace_msg(0x9Cu, 2u, "%s: NULL vdev", a2, a3, a4, a5, a6, a7, a8, a9, "tgt_send_coap_offload_reply_enable");
    return 29;
  }
  v9 = *(_QWORD *)(a1 + 152);
  if ( !v9 || (v10 = *(_QWORD *)(v9 + 80)) == 0 )
  {
    v14 = "%s: NULL psoc";
    v15 = "wlan_vdev_get_coap_txops";
LABEL_10:
    qdf_trace_msg(0x9Cu, 2u, v14, a2, a3, a4, a5, a6, a7, a8, a9, v15);
    return 0;
  }
  v11 = *(_QWORD *)(v10 + 2128);
  if ( !v11 )
  {
    v14 = "%s: tx_ops is NULL";
    v15 = "wlan_psoc_get_coap_txops";
    goto LABEL_10;
  }
  v12 = *(__int64 (**)(void))(v11 + 2136);
  if ( !v12 )
    return 0;
  if ( *((_DWORD *)v12 - 1) != -605826951 )
    __break(0x8228u);
  return v12();
}
