__int64 __fastcall tgt_psoc_get_wakelock_info(__int64 a1)
{
  __int64 priv; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  priv = mlme_psoc_get_priv(a1);
  if ( priv )
    return priv + 752;
  qdf_trace_msg(0x68u, 2u, "%s: PSOC_MLME is NULL", v2, v3, v4, v5, v6, v7, v8, v9, "tgt_psoc_get_wakelock_info");
  return 0;
}
