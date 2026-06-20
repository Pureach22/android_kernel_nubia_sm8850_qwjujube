__int64 __fastcall hdd_tx_powerboost_reinit(
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
  int v9; // w8
  __int64 result; // x0
  _QWORD v12[9]; // [xsp+8h] [xbp-48h] BYREF

  v12[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(unsigned __int8 *)(a1 + 8568);
  memset(v12, 0, 64);
  if ( v9 == 1 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: TPB: Issue boost ready after SSR reinit",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "hdd_tx_powerboost_reinit");
    result = hdd_txpb_issue_app_stop_ready(a1, v12, "Reinit", "APP_START");
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
