__int64 __fastcall wlan_mgmt_txrx_psoc_obj_create_notification(
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
  __int64 v10; // x0
  __int64 v11; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( a1 )
  {
    v10 = _qdf_mem_malloc(0x470u, "wlan_mgmt_txrx_psoc_obj_create_notification", 63);
    if ( v10 )
    {
      v11 = v10;
      *(_QWORD *)v10 = a1;
      *(_DWORD *)(v10 + 1120) = 0;
      *(_QWORD *)(v10 + 1128) = 0;
      if ( (unsigned int)wlan_objmgr_psoc_component_obj_attach(a1, 1, v10, 0) )
      {
        qdf_trace_msg(
          0x4Bu,
          2u,
          "%s: Failed to attach mgmt txrx ctx in psoc ctx",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "wlan_mgmt_txrx_psoc_obj_create_notification");
        _qdf_mem_free(v11);
        return 16;
      }
      else
      {
        qdf_trace_msg(
          0x4Bu,
          8u,
          "%s: Mgmt txrx creation successful, mgmt txrx ctx: %pK, psoc: %pK",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "wlan_mgmt_txrx_psoc_obj_create_notification",
          v11,
          a1);
        return 0;
      }
    }
    else
    {
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Bu,
      2u,
      "%s: psoc context passed is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_mgmt_txrx_psoc_obj_create_notification");
    return 4;
  }
}
