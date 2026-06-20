__int64 __fastcall dp_soc_reset_cpu_ring_map(__int64 a1)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  int v11; // w19
  __int64 v12; // x22
  __int64 v13; // x24

  result = wlan_cfg_get_dp_soc_nss_cfg(*(_QWORD *)(a1 + 40));
  v11 = result;
  v12 = 0;
  v13 = a1 + 13048;
  do
  {
    if ( v11 > 2 )
    {
      if ( v11 == 3 )
      {
        *(_BYTE *)(v13 + v12) = dp_cpu_ring_map[v12 + 54];
      }
      else
      {
        if ( v11 != 7 )
        {
LABEL_2:
          result = qdf_trace_msg(
                     0x45u,
                     2u,
                     "%s: tx_ring_map failed due to invalid nss cfg",
                     v3,
                     v4,
                     v5,
                     v6,
                     v7,
                     v8,
                     v9,
                     v10,
                     "dp_soc_reset_cpu_ring_map");
          goto LABEL_3;
        }
        *(_BYTE *)(v13 + v12) = dp_cpu_ring_map[v12 + 72];
      }
    }
    else if ( v11 == 1 )
    {
      *(_BYTE *)(v13 + v12) = dp_cpu_ring_map[v12 + 18];
    }
    else
    {
      if ( v11 != 2 )
        goto LABEL_2;
      *(_BYTE *)(v13 + v12) = dp_cpu_ring_map[v12 + 36];
    }
LABEL_3:
    ++v12;
  }
  while ( v12 != 18 );
  return result;
}
