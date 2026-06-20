__int64 __fastcall scm_eht_puncture_valid(__int64 a1, __int64 a2)
{
  __int64 v2; // x23
  int v3; // w19
  int v6; // w21
  char v7; // w0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  int v16; // w0
  unsigned int v17; // w20
  int v18; // w21
  int v19; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 result; // x0
  unsigned __int16 v29; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v30; // [xsp+38h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a2 + 1808);
  v29 = 0;
  if ( v2
    && (~*(unsigned __int8 *)(v2 + 3) & 3) == 0
    && (v3 = *(unsigned __int16 *)(v2 + 11), *(_WORD *)(v2 + 11))
    && ((v6 = *(_BYTE *)(v2 + 8) & 7, v7 = wlan_reg_freq_to_band(*(_DWORD *)(a2 + 1192)), (*(_BYTE *)(v2 + 3) & 1) != 0)
      ? (v16 = wlan_reg_chan_band_to_freq(
                 a1,
                 *(unsigned __int8 *)(v2 + 10),
                 1LL << v7,
                 v8,
                 v9,
                 v10,
                 v11,
                 v12,
                 v13,
                 v14,
                 v15))
      : (v16 = 0),
        v6 != 4 ? (v17 = v6) : (v17 = 7),
        v6 != 4 ? (v18 = 0) : (v18 = v16),
        (v19 = wlan_reg_extract_puncture_by_bw(
                 v17,
                 v3,
                 *(_DWORD *)(a2 + 1192),
                 v18,
                 0,
                 &v29,
                 v8,
                 v9,
                 v10,
                 v11,
                 v12,
                 v13,
                 v14,
                 v15)) != 0
     || v29) )
  {
    qdf_trace_msg(
      0x15u,
      8u,
      "%s: %02x:%02x:%02x:**:**:%02xfreq %d width %d 320m center %d puncture: orig %d new %d status %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "scm_eht_puncture_valid",
      *(unsigned __int8 *)(a2 + 1),
      *(unsigned __int8 *)(a2 + 2),
      *(unsigned __int8 *)(a2 + 3),
      *(unsigned __int8 *)(a2 + 6),
      *(_DWORD *)(a2 + 1192),
      v17,
      v18,
      v3,
      v29,
      v19);
    result = 0;
  }
  else
  {
    result = 1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
