__int64 __fastcall wlan_set_def_pre_cac_chan(__int64 a1, unsigned int a2, _DWORD *a3, unsigned int *a4, int *a5)
{
  __int64 v10; // x0
  __int64 channel_khz; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x23
  __int64 v21; // x0
  int v22; // w24
  int v23; // w9
  unsigned int v24; // w22
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int v33; // w8
  __int64 v34; // x9
  __int64 result; // x0
  bool v36; // zf
  int v37; // [xsp+8h] [xbp-18h] BYREF
  __int64 v38; // [xsp+Ch] [xbp-14h]
  int v39; // [xsp+14h] [xbp-Ch]
  __int64 v40; // [xsp+18h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 24);
  v39 = 0;
  v38 = 0;
  channel_khz = ieee80211_get_channel_khz(v10, 1000 * a2);
  if ( !channel_khz )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: channel conversion failed %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_set_def_pre_cac_chan",
      a2);
    result = 4294967274LL;
    goto LABEL_25;
  }
  v20 = channel_khz;
  v21 = *(_QWORD *)(a1 + 8);
  v37 = *a5;
  wlan_reg_set_channel_params_for_pwrmode(v21, a2, 0, (__int64)&v37, 0, v12, v13, v14, v15, v16, v17, v18, v19);
  v22 = 3;
  if ( (unsigned __int8)v38 == 1 )
    v23 = 3;
  else
    v23 = 1;
  if ( (unsigned __int8)v38 == 3 )
    v24 = 2;
  else
    v24 = v23;
  cfg80211_chandef_create(a3, v20, v24);
  v33 = v37;
  switch ( v37 )
  {
    case 2:
      goto LABEL_15;
    case 3:
      v22 = 5;
LABEL_15:
      v34 = 2;
      goto LABEL_16;
    case 4:
      v22 = v39;
      a3[2] = 4;
      if ( v22 )
      {
        v34 = 4;
LABEL_16:
        a3[v34] = v22;
      }
      break;
  }
  v36 = (v33 & 0xFFFFFFFE) == 2 || v33 == 4;
  if ( v36 && HIDWORD(v38) )
    a3[3] = HIDWORD(v38);
  *a4 = v24;
  *a5 = v33;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: pre cac ch def: chan:%d width:%d freq1:%d freq2:%d",
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    "wlan_set_def_pre_cac_chan",
    *(unsigned int *)(*(_QWORD *)a3 + 4LL),
    (unsigned int)a3[2],
    (unsigned int)a3[3],
    (unsigned int)a3[4]);
  result = 0;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
