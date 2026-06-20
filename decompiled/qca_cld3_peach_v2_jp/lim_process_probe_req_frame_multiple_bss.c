__int64 __fastcall lim_process_probe_req_frame_multiple_bss(
        __int64 result,
        unsigned int *a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x20
  unsigned int v14; // w24
  unsigned int v15; // w21
  __int64 v16; // x27
  unsigned __int16 *active_channel; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  v12 = result;
  if ( a3 )
  {
    if ( *(_DWORD *)(a3 + 88) == 1 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Received a probe request frame",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "lim_indicate_probe_req_to_hdd");
      lim_send_sme_mgmt_frame_ind(
        v12,
        **((unsigned __int8 **)a2 + 2) >> 4,
        *((_QWORD *)a2 + 2),
        a2[10] + 24,
        *(unsigned __int8 *)(a3 + 10),
        *a2,
        a2[2],
        0);
    }
    return ((__int64 (__fastcall *)(__int64, unsigned int *, __int64))lim_process_probe_req_frame)(v12, a2, a3);
  }
  else if ( *(_WORD *)(result + 3992) )
  {
    v14 = *(unsigned __int16 *)a2;
    v15 = 0;
    do
    {
      result = pe_find_session_by_session_id(v12, v15);
      if ( result )
      {
        v16 = result;
        if ( *(_DWORD *)(result + 88) == 1 )
        {
          result = wlan_vdev_is_up();
          if ( !(_DWORD)result )
          {
            active_channel = (unsigned __int16 *)wlan_vdev_get_active_channel(*(_QWORD *)(v16 + 16));
            if ( active_channel && *active_channel == v14 )
            {
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: Received a probe request frame",
                v18,
                v19,
                v20,
                v21,
                v22,
                v23,
                v24,
                v25,
                "lim_indicate_probe_req_to_hdd");
              lim_send_sme_mgmt_frame_ind(
                v12,
                **((unsigned __int8 **)a2 + 2) >> 4,
                *((_QWORD *)a2 + 2),
                a2[10] + 24,
                *(unsigned __int8 *)(v16 + 10),
                *a2,
                a2[2],
                0);
              result = ((__int64 (__fastcall *)(__int64, unsigned int *, __int64))lim_process_probe_req_frame)(
                         v12,
                         a2,
                         v16);
            }
            else
            {
              result = qdf_trace_msg(
                         0x35u,
                         8u,
                         "%s: do not send probe resp to requested probe freq %d",
                         v18,
                         v19,
                         v20,
                         v21,
                         v22,
                         v23,
                         v24,
                         v25,
                         "lim_process_probe_req_frame_multiple_bss",
                         v14);
            }
          }
        }
      }
      ++v15;
    }
    while ( *(unsigned __int16 *)(v12 + 3992) > (unsigned int)(unsigned __int8)v15 );
  }
  return result;
}
