__int64 __fastcall wlan_green_ap_pdev_obj_create_notification(
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
  __int64 v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  if ( a1 )
  {
    v10 = _qdf_mem_malloc(0xA0u, "wlan_green_ap_pdev_obj_create_notification", 78);
    if ( v10 )
    {
      v11 = v10;
      *(_DWORD *)(v10 + 28) = 8;
      *(_QWORD *)(v10 + 20) = 0x100000000LL;
      *(_QWORD *)(v10 + 12) = 20;
      *(_WORD *)(v10 + 9) = 1;
      *(_QWORD *)v10 = a1;
      *(_QWORD *)(v10 + 72) = wlan_green_ap_timer_fn;
      *(_QWORD *)(v10 + 80) = a1;
      init_timer_key(v10 + 32, _os_timer_shim_13, 0, 0, 0);
      *(_DWORD *)(v11 + 88) = 0;
      *(_QWORD *)(v11 + 96) = 0;
      if ( (unsigned int)wlan_objmgr_pdev_component_obj_attach(
                           a1,
                           0x16u,
                           v11,
                           0,
                           v12,
                           v13,
                           v14,
                           v15,
                           v16,
                           v17,
                           v18,
                           v19) )
      {
        qdf_trace_msg(
          0x5Du,
          2u,
          "%s: Failed to attach green ap ctx in pdev ctx",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "wlan_green_ap_pdev_obj_create_notification");
        timer_delete_sync(v11 + 32);
        _qdf_mem_free(v11);
        return 16;
      }
      else
      {
        qdf_trace_msg(
          0x5Du,
          4u,
          "%s: Green AP creation successful, green ap ctx: %pK, pdev: %pK",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "wlan_green_ap_pdev_obj_create_notification",
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
      0x5Du,
      2u,
      "%s: pdev context passed is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_green_ap_pdev_obj_create_notification");
    return 4;
  }
}
