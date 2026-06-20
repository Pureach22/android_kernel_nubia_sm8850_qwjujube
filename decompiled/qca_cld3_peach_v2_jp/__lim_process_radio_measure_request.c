__int64 __fastcall _lim_process_radio_measure_request(
        __int64 result,
        __int64 a2,
        unsigned __int8 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int16 *v11; // x22
  __int64 v12; // x26
  unsigned int v13; // w20
  __int64 v16; // x23
  unsigned int v17; // w25
  __int64 v18; // x24
  unsigned int v19; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x5
  __int64 v29; // x6
  __int64 v30; // x7
  int v31; // w8
  int v32; // w9
  int v33; // w10
  int v34; // w11
  int v35; // w12
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7

  if ( a3 )
  {
    v11 = *(unsigned __int16 **)(a2 + 16);
    v12 = *(_QWORD *)(a2 + 24);
    v13 = *(_DWORD *)(a2 + 40);
    v16 = result;
    v17 = v11[11] >> 4;
    if ( v17 == *(unsigned __int16 *)(result + 20156) && (*(_QWORD *)(result + 20160) || *(_QWORD *)(result + 20168)) )
      return qdf_trace_msg(
               0x35u,
               2u,
               "%s: rrm report req frame, seq num: %d is already in progress, drop it",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "__lim_process_radio_measure_request",
               v17);
    *(_WORD *)(result + 20156) = v17;
    result = _qdf_mem_malloc(0xD5Au, "__lim_process_radio_measure_request", 1282);
    if ( result )
    {
      v18 = result;
      v19 = dot11f_unpack_radio_measurement_request(v16, v12, v13, result, 0);
      if ( (v19 & 0x10000000) != 0 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Failed to unpack and parse a Radio Measure request (0x%08x, %d bytes):",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "__lim_process_radio_measure_request",
          v19,
          v13);
        ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(53, 2, v12, v13);
        return _qdf_mem_free(v18);
      }
      if ( v19 )
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Warnings while unpacking a Radio Measure request (0x%08x, %d bytes):",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "__lim_process_radio_measure_request",
          v19,
          v13);
      if ( v11 == (unsigned __int16 *)-10LL )
      {
        v30 = 0;
        v28 = 0;
        v29 = 0;
        v31 = 0;
      }
      else
      {
        v28 = *((unsigned __int8 *)v11 + 10);
        v29 = *((unsigned __int8 *)v11 + 11);
        v30 = *((unsigned __int8 *)v11 + 12);
        v31 = *((unsigned __int8 *)v11 + 15);
        if ( v11 == (unsigned __int16 *)-16LL )
        {
          v34 = 0;
          v32 = 0;
          v33 = 0;
          v35 = 0;
          goto LABEL_16;
        }
      }
      v32 = *((unsigned __int8 *)v11 + 16);
      v33 = *((unsigned __int8 *)v11 + 17);
      v34 = *((unsigned __int8 *)v11 + 18);
      v35 = *((unsigned __int8 *)v11 + 21);
LABEL_16:
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: vdev: %d Received rrm req from sa addr:%02x:%02x:%02x:**:**:%02x bssId:%02x:%02x:%02x:**:**:%02x session add"
        "r:%02x:%02x:%02x:**:**:%02x session self addr:%02x:%02x:%02x:**:**:%02x",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "__lim_process_radio_measure_request",
        a3[10],
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        a3[24],
        a3[25],
        a3[26],
        a3[29],
        a3[30],
        a3[31],
        a3[32],
        a3[35]);
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: RX RRM - type %hu, sub type %hu, seq num[%d]",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "__lim_process_radio_measure_request",
        (*v11 >> 2) & 3,
        (unsigned __int8)*v11 >> 4,
        v17);
      rrm_process_radio_measurement_request(v16, a3 + 24, v18, a3, v11, v13, a2);
      return _qdf_mem_free(v18);
    }
  }
  return result;
}
