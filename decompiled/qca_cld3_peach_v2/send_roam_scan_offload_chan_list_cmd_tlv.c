__int64 __fastcall send_roam_scan_offload_chan_list_cmd_tlv(__int64 a1, unsigned int *a2)
{
  int v2; // w23
  int v5; // w22
  __int64 v6; // x19
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 result; // x0
  _DWORD *v16; // x8
  __int64 v17; // x4
  int v18; // w9
  int v19; // w9
  unsigned __int64 v20; // x9
  unsigned __int64 v21; // x5
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w20

  v2 = *((unsigned __int8 *)a2 + 4);
  v5 = 4 * v2;
  v6 = wmi_buf_alloc_fl(a1, 4 * v2 + 24, "send_roam_scan_offload_chan_list_cmd_tlv", 0x16F6u);
  result = 2;
  if ( v6 )
  {
    v16 = *(_DWORD **)(v6 + 224);
    *v16 = 13434896;
    v17 = *a2;
    v16[3] = v2;
    v16[1] = v17;
    v18 = *((unsigned __int8 *)a2 + 408);
    v16[5] = v5 | 0x100000;
    if ( v18 == 1 )
      v19 = 2;
    else
      v19 = 3;
    v16[2] = v19;
    if ( v2 )
    {
      v20 = 0;
      do
      {
        v21 = (unsigned int)v16[3];
        v16[v20 + 6] = a2[v20 + 2];
        if ( v20 > 0x4E )
          break;
        ++v20;
      }
      while ( v20 < v21 );
      v17 = (unsigned int)v16[1];
    }
    else
    {
      v21 = 0;
    }
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: RSO_CFG: vdev:%d num_chan:%d cache_type:%d",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "send_roam_scan_offload_chan_list_cmd_tlv",
      v17,
      v21,
      *((unsigned __int8 *)a2 + 408));
    wmi_mtrace(0xB006u, 0xFFu, 0);
    result = wmi_unified_cmd_send_fl(
               a1,
               v6,
               v5 + 24,
               0xB006u,
               "send_roam_scan_offload_chan_list_cmd_tlv",
               0x1718u,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29);
    if ( (_DWORD)result )
    {
      v30 = result;
      wmi_buf_free();
      return v30;
    }
  }
  return result;
}
