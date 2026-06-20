__int64 __fastcall hdd_open_adapters_for_monitor_mode(
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
  int v10; // w8
  unsigned __int8 *intf_addr; // x0
  unsigned __int8 *v12; // x20
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w21
  int v23; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( curr_con_mode == 4 && (ucfg_dp_ml_mon_supported() & 1) != 0 )
    v10 = 64;
  else
    v10 = 32;
  v23 = v10;
  intf_addr = (unsigned __int8 *)wlan_hdd_get_intf_addr((__int64)a1, 6, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( intf_addr )
  {
    v12 = intf_addr;
    result = hdd_open_adapter_no_trans(a1, 6u, "wlan%d", intf_addr, &v23);
    if ( (_DWORD)result )
    {
      v22 = result;
      wlan_hdd_release_intf_addr((__int64)a1, v12, v14, v15, v16, v17, v18, v19, v20, v21);
      result = v22;
    }
  }
  else
  {
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
