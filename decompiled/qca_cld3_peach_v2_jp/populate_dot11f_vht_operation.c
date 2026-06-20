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
  int v16; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w1
  int v26; // w23
  unsigned int updated; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w1
  unsigned __int16 v37; // w2
  unsigned __int16 v38; // w9
  unsigned int v39; // w9
  char v40; // w10
  char v41; // w8
  __int64 v42; // x8
  __int16 v43; // w8
  unsigned int v45; // [xsp+8h] [xbp-18h] BYREF
  __int64 v46; // [xsp+Ch] [xbp-14h]
  int v47; // [xsp+14h] [xbp-Ch]
  __int64 v48; // [xsp+18h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v47 = 0;
  v46 = 0;
  if ( a2 )
  {
    v4 = (unsigned __int8 *)(a2 + 7170);
    if ( *(_BYTE *)(a2 + 7170) )
    {
      v7 = wlan_reg_freq_to_band(*(_DWORD *)(a2 + 284));
      v16 = wlan_reg_chan_band_to_freq(*(_QWORD *)(a1 + 21560), v4[4], 1 << v7, v8, v9, v10, v11, v12, v13, v14, v15);
      v25 = v4[14];
      v26 = v16;
      HIDWORD(v46) = v16;
      if ( v25 )
        v47 = wlan_reg_chan_band_to_freq(*(_QWORD *)(a1 + 21560), v25, 1 << v7, v17, v18, v19, v20, v21, v22, v23, v24);
      updated = wlan_dnw_update_bandwidth(*(_QWORD *)(a2 + 16));
      v36 = *(_DWORD *)(a2 + 284);
      v37 = 0;
      v45 = updated;
      if ( !v7 && updated == 1 )
      {
        v38 = v36 + 20;
        if ( v26 != v36 + 10 )
          v38 = 0;
        if ( v26 == v36 - 10 )
          v37 = v36 - 20;
        else
          v37 = v38;
      }
      wlan_reg_set_channel_params_for_pwrmode(
        *(_QWORD *)(a1 + 21560),
        v36,
        v37,
        (__int64)&v45,
        0,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35);
      v39 = v45;
      *(_BYTE *)a3 = 1;
      if ( v39 < 2 )
      {
        v41 = 0;
        *(_WORD *)(a3 + 1) = 0;
      }
      else
      {
        v40 = BYTE1(v46);
        *(_BYTE *)(a3 + 1) = 1;
        *(_BYTE *)(a3 + 2) = v40;
        if ( v39 - 3 > 1 )
          v41 = 0;
        else
          v41 = BYTE2(v46);
      }
      *(_BYTE *)(a3 + 3) = v41;
      v42 = *(_QWORD *)(a1 + 8);
      if ( v4[1465] == 1 )
        v43 = *(_WORD *)(v42 + 2648) & 0xFFFC | *(_WORD *)(v42 + 2656) | 0xC;
      else
        v43 = *(_WORD *)(v42 + 2648) & 0xFFF0 | *(_WORD *)(v42 + 2656) & 0xFFF3 | (4 * *(unsigned __int8 *)(v42 + 2664));
      *(_WORD *)(a3 + 4) = v43;
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
