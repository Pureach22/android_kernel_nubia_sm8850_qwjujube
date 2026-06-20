__int64 __fastcall hdd_update_indoor_channel(
        __int64 *a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x22
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x24
  unsigned __int64 v22; // x25
  __int64 v23; // x26
  int *v24; // x8
  __int64 v25; // x23
  __int64 v26; // x21
  unsigned __int64 v27; // x28
  __int64 v28; // x0
  __int64 v29; // x22
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int v38; // w8
  int v39; // w8
  bool v40; // zf
  int v41; // w5
  int v42; // w9
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 result; // x0
  char v53[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v54; // [xsp+8h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = a1[3];
  qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_update_indoor_channel");
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: mark indoor channel disable: %d",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "hdd_update_indoor_channel",
    a2 & 1);
  v21 = 0;
  v22 = 0;
  v23 = v12 + 328;
  do
  {
    v24 = *(int **)(v23 + 8 * v21);
    if ( v24 && v24[5] >= 1 && v22 <= 0x65 )
    {
      v25 = 0;
      v26 = 12;
      v27 = 36 * v22;
      do
      {
        v28 = *a1;
        v29 = *(_QWORD *)v24;
        v53[0] = 0;
        ucfg_mlme_get_indoor_channel_support(v28, v53);
        v38 = *(_DWORD *)(v29 + v26);
        if ( (a2 & 1) != 0 )
        {
          if ( (v38 & 0x200) != 0 )
          {
            *(_DWORD *)(v29 + v26) = v38 | 1;
            if ( v27 > 0xE57 )
              goto LABEL_30;
            qdf_trace_msg(
              0x33u,
              4u,
              "%s: Mark indoor channel %d as disable",
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              "hdd_modify_indoor_channel_state_flags",
              *(unsigned int *)&reg_channels[v27]);
            if ( v27 > 0xE4F )
              goto LABEL_30;
            *(_DWORD *)&reg_channels[v27 + 8] = 0;
          }
        }
        else if ( (v38 & 0x200) != 0 )
        {
          *(_DWORD *)(v29 + v26) = v38 & 0xFFFFFFFE;
          v39 = v38 & 0xA;
          if ( v53[0] )
            v40 = v39 == 0;
          else
            v40 = 0;
          if ( v40 )
            v41 = 3;
          else
            v41 = 2;
          if ( v27 - 3664 < 0xFFFFFFFFFFFFF1A8LL
            || (*(_DWORD *)&reg_channels[v27 + 8] = v41, v27 - 3668 < 0xFFFFFFFFFFFFF1A8LL) )
          {
LABEL_30:
            __break(1u);
          }
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Mark indoor channel %d as cds_chan state %d",
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            "hdd_modify_indoor_channel_state_flags",
            reg_channels[v27 + 4]);
        }
        v24 = *(int **)(v23 + 8 * v21);
        v42 = v25 + 1;
        if ( v25 + 1 >= v24[5] )
          break;
        v26 += 64;
        v27 += 36LL;
      }
      while ( v22 + v25++ < 0x65 );
      v22 = (unsigned int)(v22 + v42);
    }
    ++v21;
  }
  while ( v21 != 6 );
  if ( (unsigned int)ucfg_reg_notify_sap_event(a1[1], a2 & 1) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to notify sap event",
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      "hdd_update_indoor_channel");
  result = qdf_trace_msg(0x33u, 8u, "%s: exit", v44, v45, v46, v47, v48, v49, v50, v51, "hdd_update_indoor_channel");
  _ReadStatusReg(SP_EL0);
  return result;
}
