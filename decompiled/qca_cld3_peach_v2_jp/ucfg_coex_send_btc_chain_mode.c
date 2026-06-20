__int64 __fastcall ucfg_coex_send_btc_chain_mode(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned int a10)
{
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( a10 <= 2 )
  {
    qdf_trace_msg(
      0x70u,
      8u,
      "%s: send btc chain mode %d for vdev %d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "ucfg_coex_send_btc_chain_mode",
      a10);
    result = wlan_coex_config_send();
  }
  else
  {
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
