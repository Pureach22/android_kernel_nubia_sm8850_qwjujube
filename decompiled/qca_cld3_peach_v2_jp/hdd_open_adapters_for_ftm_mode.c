__int64 __fastcall hdd_open_adapters_for_ftm_mode(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v10; // w20
  unsigned __int8 *intf_addr; // x0
  unsigned __int8 *v12; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v22; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v10 = 4;
  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = 0;
  intf_addr = (unsigned __int8 *)wlan_hdd_get_intf_addr((__int64)a1, 4, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( intf_addr )
  {
    v12 = intf_addr;
    v10 = hdd_open_adapter_no_trans(a1, 4u, "wlan%d", intf_addr, &v22);
    if ( v10 )
      wlan_hdd_release_intf_addr((__int64)a1, v12, v13, v14, v15, v16, v17, v18, v19, v20);
  }
  _ReadStatusReg(SP_EL0);
  return v10;
}
