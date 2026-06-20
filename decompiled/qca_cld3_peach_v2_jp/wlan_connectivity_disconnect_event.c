__int64 __fastcall wlan_connectivity_disconnect_event(
        __int64 result,
        unsigned __int16 *a2,
        unsigned int a3,
        int a4,
        char a5)
{
  __int64 v5; // x19
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  int v26; // w20
  char v27; // w22
  unsigned int v28; // w8
  __int64 v29; // x1
  __int64 v30; // x2
  __int64 v31; // x3
  __int64 v32; // x4
  __int64 v33; // x0
  __int16 v34; // w9
  _BYTE s[331]; // [xsp+15h] [xbp-14Bh] BYREF

  *(_QWORD *)&s[323] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_DWORD *)(result + 16) )
  {
    v5 = result;
    memset(s, 0, 0x143u);
    if ( a2 )
    {
      if ( *(_QWORD *)(v5 + 152) )
      {
        if ( *(_DWORD *)a2 | a2[2] )
        {
          qdf_mem_copy(s, a2, 6u);
          if ( a3 > 0xFFEA )
          {
            v28 = a3 - 65520;
            if ( a3 - 65520 < 0xF && ((0x5FFFu >> (a3 + 16)) & 1) != 0 )
            {
              v26 = dword_A2B8F8[v28];
              v27 = byte_A2B934[v28];
            }
            else
            {
              qdf_trace_msg(
                0x38u,
                2u,
                "%s: No diag code for the qca reason code: %d",
                v18,
                v19,
                v20,
                v21,
                v22,
                v23,
                v24,
                v25,
                "wlan_connectivity_discon_reason_to_diag_reason",
                a3);
              v26 = 0;
              v27 = 99;
            }
          }
          else
          {
            v26 = 0;
            if ( (a5 & 1) != 0 )
              v27 = 1;
            else
              v27 = 3;
          }
          *(_QWORD *)&s[8] = qdf_get_time_of_the_day_us();
          v33 = ktime_get(*(_QWORD *)&s[8], v29, v30, v31, v32);
          v34 = *(unsigned __int8 *)(v5 + 104);
          *(_WORD *)&s[40] = 12;
          *(_WORD *)&s[6] = v34;
          *(_DWORD *)&s[52] = a4;
          s[38] = v27;
          s[32] = 5;
          *(_DWORD *)&s[319] = *(_DWORD *)&s[319] & 0xFFFFFF00 | v26;
          *(_QWORD *)&s[24] = v33 / 1000;
          result = host_diag_event_report_payload(3355, 323, s);
        }
        else
        {
          result = qdf_trace_msg(
                     0x38u,
                     8u,
                     "%s: vdev:%d reason:%d , bssid is zero",
                     v10,
                     v11,
                     v12,
                     v13,
                     v14,
                     v15,
                     v16,
                     v17,
                     "wlan_connectivity_disconnect_event",
                     *(unsigned __int8 *)(v5 + 104),
                     a3);
        }
      }
      else
      {
        result = qdf_trace_msg(
                   0x38u,
                   2u,
                   "%s: Pdev not found",
                   v10,
                   v11,
                   v12,
                   v13,
                   v14,
                   v15,
                   v16,
                   v17,
                   "wlan_connectivity_disconnect_event");
      }
    }
    else
    {
      result = qdf_trace_msg(
                 0x38u,
                 2u,
                 "%s: vdev:%d peer mac not found",
                 v10,
                 v11,
                 v12,
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 "wlan_connectivity_disconnect_event",
                 *(unsigned __int8 *)(v5 + 104));
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
