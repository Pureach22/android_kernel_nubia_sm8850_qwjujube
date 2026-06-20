__int64 __fastcall wlan_hdd_cfg80211_update_band(
        __int64 a1,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x22
  __int64 v23; // x21
  int *v24; // x27
  __int64 v25; // x23
  __int64 v26; // x24
  _BOOL4 v28; // w25
  _BOOL4 v30; // w26
  int channel_state_for_pwrmode; // w0
  __int64 v32; // x8
  int v33; // w9
  __int64 v34; // x8
  unsigned int v35; // w9

  qdf_trace_msg(0x33u, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "wlan_hdd_cfg80211_update_band");
  v22 = 0;
  v23 = a2 + 328;
  do
  {
    v24 = *(int **)(v23 + 8 * v22);
    if ( v24 && v24[5] >= 1 )
    {
      v25 = 0;
      v26 = 0;
      v28 = a3 == 2 && v22 == 0;
      v30 = a3 == 1 && v22 == 1;
      while ( 1 )
      {
        channel_state_for_pwrmode = wlan_reg_get_channel_state_for_pwrmode(
                                      *(_QWORD *)(a1 + 8),
                                      *(_DWORD *)(*(_QWORD *)v24 + v25 + 4),
                                      0,
                                      v14,
                                      v15,
                                      v16,
                                      v17,
                                      v18,
                                      v19,
                                      v20,
                                      v21);
        if ( v28 )
          break;
        if ( v30 )
        {
          v32 = *(_QWORD *)v24;
          goto LABEL_25;
        }
        if ( channel_state_for_pwrmode )
        {
          v32 = *(_QWORD *)v24;
          goto LABEL_28;
        }
LABEL_30:
        v24 = *(int **)(v23 + 8 * v22);
        ++v26;
        v25 += 64;
        if ( v26 >= v24[5] )
          goto LABEL_2;
      }
      v32 = *(_QWORD *)v24;
      v33 = *(_DWORD *)(*(_QWORD *)v24 + v25 + 4);
      if ( (v33 == 2412 || v33 == 2437 || v33 == 2462) && channel_state_for_pwrmode == 3 )
      {
LABEL_28:
        v34 = v32 + v25;
        v35 = *(_DWORD *)(v34 + 12) & 0xFFFFFFFE;
      }
      else
      {
LABEL_25:
        v34 = v32 + v25;
        v35 = *(_DWORD *)(v34 + 12) | 1;
      }
      *(_DWORD *)(v34 + 12) = v35;
      goto LABEL_30;
    }
LABEL_2:
    ++v22;
  }
  while ( v22 != 6 );
  return 0;
}
