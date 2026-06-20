__int64 __fastcall wifi_pos_convert_host_pdev_id_to_target(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 tx_ops; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _DWORD *v23; // x8
  const char *v25; // x2

  tx_ops = wifi_pos_get_tx_ops(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !tx_ops )
  {
    v25 = "%s: tx_ops is null";
LABEL_8:
    qdf_trace_msg(0x25u, 2u, v25, v15, v16, v17, v18, v19, v20, v21, v22, "wifi_pos_convert_host_pdev_id_to_target");
    return 29;
  }
  v23 = *(_DWORD **)(tx_ops + 24);
  if ( !v23 )
  {
    v25 = "%s: wifi_pos_convert_pdev_id_host_to_target is null";
    goto LABEL_8;
  }
  if ( *(v23 - 1) != -1930435158 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v23)(a1, a2, a3);
}
