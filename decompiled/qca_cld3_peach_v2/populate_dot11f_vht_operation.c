__int64 __fastcall populate_dot11f_vht_operation(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int8 *v4; // x26
  int v7; // w22
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  int v16; // w23
  int v17; // w8
  int v18; // w0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w1
  unsigned int updated; // w0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w1
  unsigned int v38; // w2
  unsigned int v39; // w9
  unsigned int v40; // w9
  char v41; // w10
  char v42; // w8
  __int64 v43; // x8
  __int16 v44; // w8
  unsigned int v46; // [xsp+0h] [xbp-20h] BYREF
  __int64 v47; // [xsp+4h] [xbp-1Ch]
  __int64 v48; // [xsp+Ch] [xbp-14h]
  int v49; // [xsp+14h] [xbp-Ch]
  __int64 v50; // [xsp+18h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v49 = 0;
  v48 = 0;
  v47 = 0;
  if ( a2 )
  {
    v4 = (unsigned __int8 *)(a2 + 7170);
    if ( *(_BYTE *)(a2 + 7170) )
    {
      v7 = wlan_reg_freq_to_band(*(_DWORD *)(a2 + 284));
      if ( *(_DWORD *)(a2 + 7036) == 1 && v4[2901] == 1 && v4[2610] == 1 )
      {
        v16 = v4[2608];
        v17 = v4[2609];
        HIDWORD(v47) = v16;
        LODWORD(v48) = v17;
      }
      else
      {
        v18 = wlan_reg_chan_band_to_freq(*(_QWORD *)(a1 + 21632), v4[4], 1 << v7, v8, v9, v10, v11, v12, v13, v14, v15);
        v27 = v4[16];
        v16 = v18;
        HIDWORD(v47) = v18;
        if ( v27 )
          LODWORD(v48) = wlan_reg_chan_band_to_freq(
                           *(_QWORD *)(a1 + 21632),
                           v27,
                           1 << v7,
                           v19,
                           v20,
                           v21,
                           v22,
                           v23,
                           v24,
                           v25,
                           v26);
      }
      updated = wlan_dnw_update_bandwidth(*(_QWORD *)(a2 + 16));
      v37 = *(_DWORD *)(a2 + 284);
      v38 = 0;
      v46 = updated;
      if ( !v7 && updated == 1 )
      {
        v39 = v37 + 20;
        if ( v16 != v37 + 10 )
          v39 = 0;
        if ( v16 == v37 - 10 )
          v38 = v37 - 20;
        else
          v38 = v39;
      }
      wlan_reg_set_channel_params_for_pwrmode(
        *(_QWORD *)(a1 + 21632),
        v37,
        v38,
        (__int64)&v46,
        0,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36);
      v40 = v46;
      *(_BYTE *)a3 = 1;
      if ( v40 < 2 )
      {
        v42 = 0;
        *(_WORD *)(a3 + 1) = 0;
      }
      else
      {
        v41 = BYTE1(v47);
        *(_BYTE *)(a3 + 1) = 1;
        *(_BYTE *)(a3 + 2) = v41;
        if ( v40 - 3 > 1 )
          v42 = 0;
        else
          v42 = BYTE2(v47);
      }
      *(_BYTE *)(a3 + 3) = v42;
      v43 = *(_QWORD *)(a1 + 8);
      if ( v4[1465] == 1 )
        v44 = *(_WORD *)(v43 + 2852) & 0xFFFC | *(_WORD *)(v43 + 2860) | 0xC;
      else
        v44 = *(_WORD *)(v43 + 2852) & 0xFFF0 | *(_WORD *)(v43 + 2860) & 0xFFF3 | (4 * *(unsigned __int8 *)(v43 + 2868));
      *(_WORD *)(a3 + 4) = v44;
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
