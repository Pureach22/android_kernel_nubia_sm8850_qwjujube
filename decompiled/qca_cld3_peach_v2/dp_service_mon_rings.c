__int64 __fastcall dp_service_mon_rings(__int64 a1, unsigned int a2)
{
  unsigned int v4; // w0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 result; // x0
  unsigned int v14; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  if ( (!(unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a1 + 40))
     || !(unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(a1 + 40), 0))
    && *(_QWORD *)(a1 + 72) )
  {
    v4 = dp_mon_process(a1, 0, 0, a2);
    qdf_trace_msg(
      0x85u,
      8u,
      "%s: Reaped %d descs from Monitor rings",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "dp_service_mon_rings",
      v4);
  }
  result = wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a1 + 40));
  if ( !(_DWORD)result || (result = wlan_cfg_get_pdev_idx(*(_QWORD *)(a1 + 40), 1), !(_BYTE)result) )
  {
    if ( *(_QWORD *)(a1 + 72) )
    {
      v14 = dp_mon_process(a1, 0, 1, a2);
      return qdf_trace_msg(
               0x85u,
               8u,
               "%s: Reaped %d descs from Monitor rings",
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               "dp_service_mon_rings",
               v14);
    }
  }
  return result;
}
