__int64 __fastcall tdls_send_update_to_fw(
        __int64 result,
        __int64 a2,
        char a3,
        char a4,
        char a5,
        unsigned __int8 a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  unsigned int v14; // w25
  __int64 v15; // x22
  __int64 v16; // x20
  int v21; // w24
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x20
  __int64 v32; // x23
  int v33; // w8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7

  v14 = *(_DWORD *)(a2 + 156);
  v15 = result;
  if ( (v14 & 0x20) != 0 )
  {
    v21 = 0;
    if ( (a5 & 1) != 0 && (a3 & 1) == 0 )
    {
      if ( (v14 & 0x40) != 0 )
      {
        if ( (v14 & 0x80) != 0 )
          v21 = 4;
        else
          v21 = 3;
      }
      else
      {
        v21 = 2;
      }
    }
    result = wlan_cm_is_vdev_connected(*(_QWORD *)result, a7, a8, a9, a10, a11, a12, a13, a14);
    if ( (result & 1) != 0 || (a3 & 1) != 0 || (a5 & 1) == 0 )
    {
      *(_DWORD *)(a2 + 8) = v21;
      *(_DWORD *)(a2 + 12) = v21;
      result = _qdf_mem_malloc(0x40u, "tdls_send_update_to_fw", 1600);
      if ( result )
      {
        v32 = result;
        *(_DWORD *)(result + 8) = *(_DWORD *)(v15 + 732);
        *(_DWORD *)(result + 12) = *(_DWORD *)(v15 + 736);
        *(_DWORD *)(result + 16) = *(_DWORD *)(v15 + 748);
        *(_DWORD *)(result + 20) = *(_DWORD *)(v15 + 756);
        v33 = *(_DWORD *)(v15 + 760);
        *(_DWORD *)result = a6;
        *(_DWORD *)(result + 24) = v33;
        *(_BYTE *)(v15 + 968) = a6;
        *(_DWORD *)(result + 4) = *(_DWORD *)(a2 + 8);
        *(_DWORD *)(result + 28) = (v14 >> 1) & 2 | (unsigned __int8)v14 & (unsigned __int8)~a4 & 1 | (v14 >> 1) & 4;
        *(_DWORD *)(result + 32) = *(_DWORD *)(a2 + 148);
        *(_DWORD *)(result + 36) = *(_DWORD *)(a2 + 152);
        *(_DWORD *)(result + 40) = *(_DWORD *)(a2 + 140);
        *(_DWORD *)(result + 44) = *(_DWORD *)(a2 + 144);
        *(_DWORD *)(result + 48) = *(_DWORD *)(a2 + 112);
        *(_DWORD *)(result + 52) = *(_DWORD *)(a2 + 120);
        *(_DWORD *)(result + 56) = *(_DWORD *)(a2 + 172);
        *(_DWORD *)(result + 60) = *(_DWORD *)(a2 + 176);
        if ( !(unsigned int)tgt_tdls_set_fw_state(*(_QWORD *)a2, result) )
        {
          if ( (a5 & 1) != 0 )
            *(_BYTE *)(a2 + 224) = a6;
          qdf_trace_msg(
            0,
            8u,
            "%s: FW tdls state%d sent for vdev id %d",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "tdls_send_update_to_fw",
            *(unsigned int *)(v32 + 4),
            a6);
        }
        return _qdf_mem_free(v32);
      }
    }
    else
    {
      v31 = jiffies;
      if ( tdls_send_update_to_fw___last_ticks_46 - jiffies + 125 < 0 )
      {
        result = qdf_trace_msg(
                   0,
                   4u,
                   "%s: Vdev:%d is not connected. Don't enable TDLS",
                   v23,
                   v24,
                   v25,
                   v26,
                   v27,
                   v28,
                   v29,
                   v30,
                   "tdls_send_update_to_fw",
                   *(unsigned __int8 *)(*(_QWORD *)v15 + 168LL));
        tdls_send_update_to_fw___last_ticks_46 = v31;
      }
    }
  }
  else
  {
    v16 = jiffies;
    if ( tdls_send_update_to_fw___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0,
                 4u,
                 "%s: vdev:%d TDLS mode is not enabled",
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 a12,
                 a13,
                 a14,
                 "tdls_send_update_to_fw",
                 *(unsigned __int8 *)(*(_QWORD *)result + 168LL));
      tdls_send_update_to_fw___last_ticks = v16;
    }
  }
  return result;
}
