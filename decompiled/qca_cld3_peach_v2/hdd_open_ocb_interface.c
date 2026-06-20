__int64 __fastcall hdd_open_ocb_interface(
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
  unsigned __int8 *intf_addr; // x0
  unsigned __int8 *v11; // x20
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w21
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  int v30; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v31; // [xsp+8h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  intf_addr = (unsigned __int8 *)wlan_hdd_get_intf_addr((__int64)a1, 8, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( intf_addr )
  {
    v11 = intf_addr;
    result = hdd_open_adapter_no_trans(a1, 8u, "wlanocb%d", intf_addr, &v30);
    if ( (_DWORD)result )
    {
      v21 = result;
      wlan_hdd_release_intf_addr((__int64)a1, v11, v13, v14, v15, v16, v17, v18, v19, v20);
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to open 802.11p interface",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "hdd_open_ocb_interface");
      result = v21;
    }
  }
  else
  {
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
