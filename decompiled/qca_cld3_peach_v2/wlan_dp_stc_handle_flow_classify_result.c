__int64 __fastcall wlan_dp_stc_handle_flow_classify_result(__int64 a1)
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
  __int64 v11; // x12
  __int64 v12; // x2
  __int64 v13; // x11
  __int64 v14; // x10
  __int64 v15; // x22
  int v16; // w12
  int v17; // w13
  __int64 v18; // x20
  __int64 v19; // x2
  int v20; // w4
  int v21; // w4
  __int64 v22; // x22
  unsigned __int16 v23; // w0
  unsigned __int16 v24; // w20
  __int16 v25; // w0
  __int16 v26; // w25
  __int16 v27; // w0
  unsigned __int16 v28; // w25
  __int16 v29; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned __int16 v38; // w0
  unsigned __int16 v39; // w21
  __int16 v40; // w0
  __int16 v41; // w25
  __int16 v42; // w0
  unsigned __int16 v43; // w25
  __int16 v44; // w0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  int v53; // w8
  char v54; // w8
  _QWORD v55[33]; // [xsp+18h] [xbp-108h] BYREF

  v55[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = dp_get_context();
  v11 = *(_QWORD *)(result + 2936);
  memset(v55, 0, 256);
  if ( v11 )
  {
    v13 = *(_QWORD *)(a1 + 24);
    v12 = *(_QWORD *)(a1 + 32);
    v14 = *(_QWORD *)(a1 + 16);
    v15 = *(_QWORD *)(v11 + 6400);
    v16 = WORD1(v12);
    v17 = BYTE4(v12);
    v18 = 0;
    v19 = v13 ^ v12;
    while ( 1 )
    {
      if ( (*(_DWORD *)(v15 + 16) | 8) != 8 )
      {
        v20 = *(_DWORD *)(v15 + 36);
        if ( (v20 & 2) == 0 )
        {
          if ( *(_BYTE *)(v15 + 1880) == 2 )
          {
            if ( (v20 & 8) == 0 )
              goto LABEL_3;
          }
          else if ( (v20 & 4) == 0 )
          {
            goto LABEL_3;
          }
        }
        if ( (*(_QWORD *)a1 ^ *(_QWORD *)(a1 + 8) ^ v14 ^ *(_QWORD *)(v15 + 64) ^ v19) == 0x574C414E5F44505FLL
          && *(unsigned __int16 *)(v15 + 228) == (unsigned __int16)*(_QWORD *)(a1 + 32)
          && *(unsigned __int16 *)(v15 + 230) == v16
          && *(unsigned __int8 *)(v15 + 232) == v17 )
        {
          v21 = *(_DWORD *)(a1 + 40);
          if ( ((v21 & 1) == 0
             || *(_DWORD *)(v15 + 196) == (unsigned int)*(_QWORD *)a1 && *(_DWORD *)(v15 + 212) == (_DWORD)v14)
            && ((v21 & 2) == 0
             || *(_OWORD *)(v15 + 196) == *(_OWORD *)a1
             && *(_QWORD *)(v15 + 212) == v14
             && *(_QWORD *)(v15 + 220) == v13) )
          {
            *(_BYTE *)(v15 + 44) = *(_BYTE *)(a1 + 52);
            scnprintf(v55, 256, "0x%x", *(_DWORD *)a1);
            v39 = v38;
            scnprintf((char *)v55 + v38, 256 - v38, " 0x%x", *(_DWORD *)(a1 + 16));
            v41 = v40 + v39;
            scnprintf(
              (char *)v55 + (unsigned __int16)(v40 + v39),
              256 - (unsigned __int16)(v40 + v39),
              " %u",
              *(unsigned __int16 *)(a1 + 32));
            v43 = v42 + v41;
            scnprintf((char *)v55 + v43, 256 - v43, " %u", *(unsigned __int16 *)(a1 + 34));
            v45 = scnprintf(
                    (char *)v55 + (unsigned __int16)(v44 + v43),
                    256 - (unsigned __int16)(v44 + v43),
                    " %u",
                    *(unsigned __int8 *)(a1 + 36));
            result = qdf_trace_msg(
                       0x45u,
                       5u,
                       "%s: STC: sampling flow %d tuple (%s) result %d ul_tid %u sample_start_ts %llu current stage %u",
                       v45,
                       v46,
                       v47,
                       v48,
                       v49,
                       v50,
                       v51,
                       v52,
                       "wlan_dp_stc_handle_flow_classify_result",
                       (unsigned int)v18,
                       v55,
                       *(unsigned __int8 *)(a1 + 52),
                       *(unsigned __int8 *)(a1 + 53),
                       *(_QWORD *)(v15 + 72),
                       *(unsigned __int8 *)(v15 + 1880));
            v53 = *(unsigned __int8 *)(a1 + 52);
            if ( (unsigned int)(v53 - 7) < 0xFFFFFFFE || *(_QWORD *)(v15 + 24) )
            {
              *(_BYTE *)(v15 + 44) = v53;
              v54 = *(_BYTE *)(a1 + 53);
              *(_DWORD *)(v15 + 16) = 8;
              *(_BYTE *)(v15 + 45) = v54;
            }
            goto LABEL_26;
          }
        }
      }
LABEL_3:
      ++v18;
      v15 += 1872;
      if ( v18 == 128 )
      {
        result = qdf_trace_msg(
                   0x45u,
                   5u,
                   "%s: STC: Could not find the classified flow in table",
                   v3,
                   v4,
                   v5,
                   v6,
                   v7,
                   v8,
                   v9,
                   v10,
                   "wlan_dp_stc_handle_flow_classify_result");
        goto LABEL_26;
      }
    }
  }
  v22 = jiffies;
  if ( wlan_dp_stc_handle_flow_classify_result___last_ticks - jiffies + 125 < 0 )
  {
    scnprintf(v55, 256, "0x%x", *(_DWORD *)a1);
    v24 = v23;
    scnprintf((char *)v55 + v23, 256 - v23, " 0x%x", *(_DWORD *)(a1 + 16));
    v26 = v25 + v24;
    scnprintf(
      (char *)v55 + (unsigned __int16)(v25 + v24),
      256 - (unsigned __int16)(v25 + v24),
      " %u",
      *(unsigned __int16 *)(a1 + 32));
    v28 = v27 + v26;
    scnprintf((char *)v55 + v28, 256 - v28, " %u", *(unsigned __int16 *)(a1 + 34));
    v30 = scnprintf(
            (char *)v55 + (unsigned __int16)(v29 + v28),
            256 - (unsigned __int16)(v29 + v28),
            " %u",
            *(unsigned __int8 *)(a1 + 36));
    result = qdf_trace_msg(
               0x45u,
               5u,
               "%s: STC context detached! Tuple (%s), result %d",
               v30,
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               "wlan_dp_stc_handle_flow_classify_result",
               v55,
               *(unsigned __int8 *)(a1 + 52));
    wlan_dp_stc_handle_flow_classify_result___last_ticks = v22;
  }
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
