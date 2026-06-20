__int64 __fastcall lim_mgmt_radio_measure_report_tx_complete(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        int a11,
        __int64 a12)
{
  int v13; // w10
  __int64 v14; // x8
  int v15; // w20
  int v16; // w9
  unsigned int v17; // w20
  int v18; // w9
  __int16 v19; // w10
  unsigned int v20; // w11
  _BYTE *v21; // x8
  __int16 v22; // w23
  int v23; // w26
  unsigned int v24; // w21
  unsigned __int16 v25; // w25
  unsigned __int8 *ie_ptr_from_eid; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned __int8 *v36; // x24
  unsigned __int8 v37; // w27
  __int16 v38; // w25
  unsigned __int64 v39; // x8
  unsigned __int8 *v40; // x1
  __int16 v41; // w22
  __int64 v42; // x1
  __int64 v43; // x2
  __int64 v44; // x3
  __int64 v45; // x4
  __int64 v46; // x0
  __int64 v48; // [xsp+0h] [xbp-40h] BYREF
  unsigned __int64 time_of_the_day_us; // [xsp+8h] [xbp-38h]
  __int64 v50; // [xsp+10h] [xbp-30h]
  __int64 v51; // [xsp+18h] [xbp-28h]
  __int64 v52; // [xsp+20h] [xbp-20h]
  __int64 v53; // [xsp+28h] [xbp-18h]
  int v54; // [xsp+30h] [xbp-10h]
  __int64 v55; // [xsp+38h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a10 )
  {
    if ( a12 )
    {
      if ( a11 == 1 )
        v13 = 2;
      else
        v13 = 3;
      v14 = *(_QWORD *)(a10 + 224);
      if ( a11 )
        v15 = v13;
      else
        v15 = 1;
      if ( (*(_BYTE *)(a10 + 68) & 4) != 0 )
        v16 = *(unsigned __int16 *)(a10 + 66);
      else
        v16 = 0;
      v18 = *(_DWORD *)(a10 + 112) + v16;
      if ( (*(_BYTE *)(v14 + 1) & 0x40) != 0 )
        v19 = -32;
      else
        v19 = -24;
      if ( (*(_BYTE *)(v14 + 1) & 0x40) != 0 )
        v20 = 32;
      else
        v20 = 24;
      if ( (_WORD)v18 && (unsigned __int16)v18 > (v20 | 3) )
      {
        v21 = (_BYTE *)(v14 + v20);
        if ( *v21 == 5 && v21[1] == 1 )
        {
          v22 = (_WORD)v21 + 3;
          v23 = *(unsigned __int8 *)(a12 + 58);
          v24 = (unsigned __int8)v21[2];
          v25 = v18 + v19 - 3;
          ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(0x27u, v21 + 3, v25);
          if ( ie_ptr_from_eid )
          {
            v36 = ie_ptr_from_eid;
            v37 = 0;
            v38 = v22 + v25;
            do
            {
              v39 = v36[1];
              if ( v39 > 2 )
              {
                v40 = &v36[v39 + 2];
                if ( v36[4] == 5 )
                  ++v37;
              }
              else
              {
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: Bad Measurement Report element",
                  v28,
                  v29,
                  v30,
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  "lim_mgmt_radio_measure_report_tx_complete");
                v40 = &v36[v36[1] + 2];
              }
              v36 = wlan_get_ie_ptr_from_eid(0x27u, v40, v38 - (unsigned __int16)v40);
            }
            while ( v36 );
          }
          else
          {
            v37 = 0;
          }
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: vdev_id %d dialog_token %d num_measuremt %d",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "lim_mgmt_radio_measure_report_tx_complete",
            *(unsigned __int8 *)(a12 + 10),
            v24,
            v37);
          v41 = *(unsigned __int8 *)(a12 + 10);
          v54 = 0;
          v52 = 0;
          v53 = 0;
          v50 = 0;
          v51 = 0;
          v48 = 0;
          time_of_the_day_us = 0;
          qdf_mem_set(&v48, 0x34u, 0);
          HIWORD(v48) = v41;
          time_of_the_day_us = qdf_get_time_of_the_day_us();
          v46 = ktime_get(time_of_the_day_us, v42, v43, v44, v45);
          HIBYTE(v52) = v24;
          BYTE6(v52) = v37;
          LOWORD(v52) = 11267;
          v54 = v54 & 0xFFFF87FF | (v15 << 11) | 0x100;
          v51 = v46 / 1000;
          v54 = v23 & 0xFFFFF9FF | ((wlan_get_diag_tx_status(v15) & 3) << 9) | v54 & 0xFFFFF900;
          host_diag_event_report_payload(3384, 52, &v48);
        }
        else
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Not a beacon report frame type:%d",
            a1,
            a2,
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            "lim_mgmt_radio_measure_report_tx_complete");
        }
        v17 = 0;
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Invalid buffer length %d",
          a1,
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          "lim_mgmt_radio_measure_report_tx_complete",
          (unsigned __int16)v18);
        v17 = 16;
      }
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Invalid param",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "lim_mgmt_radio_measure_report_tx_complete");
      v17 = 16;
    }
    _qdf_nbuf_free(a10);
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Invalid nbuf buffer",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "lim_mgmt_radio_measure_report_tx_complete");
    v17 = 16;
  }
  _ReadStatusReg(SP_EL0);
  return v17;
}
