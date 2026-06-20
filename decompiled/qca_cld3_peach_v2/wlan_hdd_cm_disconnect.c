__int64 __fastcall wlan_hdd_cm_disconnect(__int64 a1, __int64 a2, unsigned __int16 a3)
{
  __int64 v3; // x22
  __int64 v5; // x19
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x20
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w0

  v3 = *(_QWORD *)(a2 + 2712);
  v5 = *(_QWORD *)(a2 + 55520);
  if ( (unsigned int)hdd_get_conparam(a1) == 5 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Command not allowed in FTM mode",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "wlan_hdd_cm_disconnect");
    return 4294967274LL;
  }
  else
  {
    result = _wlan_hdd_validate_context(v3, "wlan_hdd_cm_disconnect");
    if ( !(_DWORD)result )
    {
      if ( (unsigned int)_wlan_hdd_validate_vdev_id(*(unsigned __int8 *)(v5 + 8), "wlan_hdd_cm_disconnect") )
      {
        return 4294967274LL;
      }
      else if ( *(_BYTE *)(v3 + 488) == 1 )
      {
        v24 = jiffies;
        if ( wlan_hdd_cm_disconnect___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            4u,
            "%s: wiphy is suspended retry disconnect",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "wlan_hdd_cm_disconnect");
          wlan_hdd_cm_disconnect___last_ticks = v24;
        }
        return 4294967285LL;
      }
      else
      {
        qdf_mtrace(51, 51, 0x22u, *(_BYTE *)(v5 + 8), a3);
        hdd_print_netdev_txq_status(a2);
        if ( a3 == 3 )
          qdf_dp_trace_dump_all(0x64u, 0xFFu, v25, v26, v27, v28, v29, v30, v31, v32);
        v33 = wlan_hdd_cm_issue_disconnect(v5, a3, 1);
        return qdf_status_to_os_return(v33);
      }
    }
  }
  return result;
}
