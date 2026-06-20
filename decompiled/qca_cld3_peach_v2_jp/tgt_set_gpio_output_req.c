__int64 __fastcall tgt_set_gpio_output_req(
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
  __int64 (*v10)(void); // x8
  const char *v12; // x2
  const char *v13; // x3

  if ( !a1 )
  {
    v12 = "%s: NULL psoc";
    v13 = "tgt_set_gpio_output_req";
LABEL_8:
    qdf_trace_msg(0x7Au, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, v13);
    return 29;
  }
  v9 = *(_QWORD *)(a1 + 2128);
  if ( !v9 )
  {
    v12 = "%s: tx_ops is NULL";
    v13 = "wlan_psoc_get_gpio_txops";
    goto LABEL_8;
  }
  v10 = *(__int64 (**)(void))(v9 + 1976);
  if ( *((_DWORD *)v10 - 1) != 1190134446 )
    __break(0x8228u);
  return v10();
}
