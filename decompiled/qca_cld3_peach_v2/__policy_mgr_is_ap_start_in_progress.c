void __fastcall _policy_mgr_is_ap_start_in_progress(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 v3; // x29
  __int64 v4; // x30
  unsigned int v5; // w19
  int vdev_active_cmd_type; // w0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  _DWORD *v17; // x9
  __int64 v18; // x8
  bool is_non_scan_cmd_type_in_vdev_queue; // w0
  __int64 v20; // [xsp+8h] [xbp-28h]

  if ( a2 )
  {
    if ( a3 )
    {
      if ( *a3 == 255 )
      {
        v20 = v4;
        v5 = *(_DWORD *)(a2 + 16);
        if ( v5 <= 0xB && ((1 << v5) & 0x80A) != 0 )
        {
          vdev_active_cmd_type = wlan_serialization_get_vdev_active_cmd_type(a2);
          v17 = a3;
          v18 = a2;
          if ( vdev_active_cmd_type == 21
            || (is_non_scan_cmd_type_in_vdev_queue = wlan_ser_is_non_scan_cmd_type_in_vdev_queue(
                                                       a2,
                                                       0x15u,
                                                       v9,
                                                       v10,
                                                       v11,
                                                       v12,
                                                       v13,
                                                       v14,
                                                       v15,
                                                       v16),
                v17 = a3,
                v18 = a2,
                is_non_scan_cmd_type_in_vdev_queue) )
          {
            *v17 = *(unsigned __int8 *)(v18 + 168);
            qdf_trace_msg(
              0x4Fu,
              8u,
              "%s: vdev %d op mode %d start bss is pending",
              v9,
              v10,
              v11,
              v12,
              v13,
              v14,
              v15,
              v16,
              "__policy_mgr_is_ap_start_in_progress",
              v3,
              v20);
          }
        }
      }
    }
  }
}
