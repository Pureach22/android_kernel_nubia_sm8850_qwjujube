__int64 __fastcall wlan_mgmt_txrx_deregister_rx_cb(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  const char *v13; // x2
  __int64 v14; // x4
  const char *v15; // x2
  __int64 v16; // x21
  __int64 comp_private_obj; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x20
  _QWORD *v29; // x22

  if ( !a1 )
  {
    v15 = "%s: psoc context is NULL";
LABEL_5:
    qdf_trace_msg(0x4Bu, 2u, v15, a5, a6, a7, a8, a9, a10, a11, a12, "wlan_mgmt_txrx_deregister_rx_cb");
    return 4;
  }
  if ( a2 >= 0x36 )
  {
    v13 = "%s: Invalid component id %d passed";
    v14 = a2;
LABEL_8:
    qdf_trace_msg(0x4Bu, 2u, v13, a5, a6, a7, a8, a9, a10, a11, a12, "wlan_mgmt_txrx_deregister_rx_cb", v14);
    return 4;
  }
  v16 = a4;
  if ( (unsigned int)a4 - 139 <= 0xFFFFFF75 )
  {
    v13 = "%s: Invalid value for num_entries: %d passed";
    v14 = a4;
    goto LABEL_8;
  }
  if ( !a3 )
  {
    v15 = "%s: frame cb info pointer is NULL";
    goto LABEL_5;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 1);
  if ( comp_private_obj )
  {
    v28 = comp_private_obj;
    v29 = (_QWORD *)(a3 + 8);
    do
    {
      ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))wlan_mgmt_txrx_delete_rx_handler)(
        v28,
        *v29,
        a2,
        *((unsigned int *)v29 - 2));
      --v16;
      v29 += 2;
    }
    while ( v16 );
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x4Bu,
      2u,
      "%s: mgmt txrx context is NULL",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "wlan_mgmt_txrx_deregister_rx_cb");
    return 16;
  }
}
