__int64 __fastcall rmnet_rx_priv_handler(__int64 *a1)
{
  __int64 v1; // x20
  unsigned int v2; // w19
  int v4; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *a1;
  v4 = 3;
  rmnet_module_hook_wlan_ingress_rx_handler(&v4, a1);
  v2 = v4;
  if ( v4 == 3 )
    rmnet_module_hook_perf_ingress_rx_handler(v1);
  _ReadStatusReg(SP_EL0);
  return v2;
}
