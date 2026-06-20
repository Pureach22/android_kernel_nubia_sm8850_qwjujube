__int64 __fastcall tgt_get_coex_multi_config_support(
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
  char v11; // w0

  if ( !a1 || (v9 = *(_QWORD *)(a1 + 2128)) == 0 )
  {
    qdf_trace_msg(0x70u, 2u, "%s: tx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_psoc_get_coex_txops");
    goto LABEL_8;
  }
  v10 = *(__int64 (**)(void))(v9 + 1936);
  if ( !v10 )
  {
LABEL_8:
    v11 = 0;
    return v11 & 1;
  }
  if ( *((_DWORD *)v10 - 1) != -1548408 )
    __break(0x8228u);
  v11 = v10();
  return v11 & 1;
}
