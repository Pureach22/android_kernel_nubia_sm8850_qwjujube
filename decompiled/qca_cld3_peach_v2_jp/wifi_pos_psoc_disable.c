__int64 __fastcall wifi_pos_psoc_disable(
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
  unsigned int (*v10)(void); // x8
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w19
  const char *v20; // x2
  const char *v21; // x2

  if ( !a1 )
  {
    v21 = "%s: psoc is null";
LABEL_9:
    qdf_trace_msg(0x25u, 2u, v21, a2, a3, a4, a5, a6, a7, a8, a9, "wifi_pos_get_tx_ops");
    v19 = 29;
    v20 = "%s: tx_ops is null";
    goto LABEL_10;
  }
  v9 = *(_QWORD *)(a1 + 2128);
  if ( !v9 )
  {
    v21 = "%s: tx_ops is NULL";
    goto LABEL_9;
  }
  v10 = *(unsigned int (**)(void))(v9 + 792);
  if ( *((_DWORD *)v10 - 1) != -770124015 )
    __break(0x8228u);
  v19 = 0;
  if ( v10() )
  {
    v20 = "%s: target_if_wifi_pos_deregister_events failed";
LABEL_10:
    qdf_trace_msg(0x25u, 2u, v20, v11, v12, v13, v14, v15, v16, v17, v18, "wifi_pos_psoc_disable");
  }
  return v19;
}
