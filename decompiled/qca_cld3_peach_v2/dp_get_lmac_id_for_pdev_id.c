__int64 __fastcall dp_get_lmac_id_for_pdev_id(__int64 a1, int a2, int a3)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7

  v6 = wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a1 + 40));
  if ( (_DWORD)v6 )
  {
    if ( a3 )
    {
      __break(0x5512u);
      return dp_monitor_vdev_timer_start(v6);
    }
    else
    {
      return *(unsigned __int8 *)(*(_QWORD *)(a1 + 72) + 1LL);
    }
  }
  else if ( a2 && a3 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Both mac_id and pdev_id cannot be non zero",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "dp_get_lmac_id_for_pdev_id");
    return 0;
  }
  else
  {
    return (unsigned int)(a3 + a2);
  }
}
