__int64 __fastcall wlan_dp_rx_fisa_cbk(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 context; // x0

  context = dp_get_context();
  return dp_fisa_rx(context, a2, a3);
}
