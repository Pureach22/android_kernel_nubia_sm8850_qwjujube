__int64 __fastcall dp_get_num_rx_contexts(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x1
  __int64 v4; // x2
  __int64 v5; // x3
  __int64 v6; // x4
  unsigned int reo_rings_mapping; // w0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w0
  unsigned int v17; // w19
  unsigned int v18; // w8
  unsigned int v19; // w8

  result = wlan_cfg_get_num_rx_context(*(_QWORD *)(a1 + 40));
  if ( !(_DWORD)result )
  {
    reo_rings_mapping = wlan_cfg_get_reo_rings_mapping(*(_QWORD *)(a1 + 40), v3, v4, v5, v6);
    if ( *(_WORD *)(a1 + 20008) )
    {
      if ( *(_WORD *)(a1 + 20008) == 1 )
      {
        v16 = reo_rings_mapping & 0xFFFFFF77;
      }
      else
      {
        v17 = reo_rings_mapping;
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: unknown arch_id 0x%x",
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          "dp_get_num_rx_contexts");
        v16 = v17;
      }
    }
    else
    {
      v16 = reo_rings_mapping & 0xFFFFFFF7;
    }
    v18 = (((((v16 >> 1) & 0x55555555) + (v16 & 0x55555555)) >> 2) & 0x33333333)
        + ((((v16 >> 1) & 0x55555555) + (v16 & 0x55555555)) & 0x33333333);
    v19 = (((((v18 >> 4) & 0x7070707) + (v18 & 0x7070707)) >> 8) & 0xF000F)
        + ((((v18 >> 4) & 0x7070707) + (v18 & 0x7070707)) & 0xF000F);
    return (v19 & 0x1F) + HIWORD(v19);
  }
  return result;
}
