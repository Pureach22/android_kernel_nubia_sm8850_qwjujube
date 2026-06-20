__int64 __fastcall wlan_cm_sta_set_chan_param(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int *a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  __int64 v16; // x23
  __int64 v20; // x26
  __int64 v22; // x2
  unsigned int v23; // w25
  unsigned int v24; // w24
  const char *v25; // x2
  __int64 result; // x0
  int v28; // w0
  unsigned int v29; // w9
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x4
  __int128 v39; // kr00_16
  bool v40; // zf
  _WORD v41[2]; // [xsp+8h] [xbp-48h] BYREF
  __int16 v42; // [xsp+Ch] [xbp-44h] BYREF
  _QWORD v43[6]; // [xsp+10h] [xbp-40h] BYREF
  int v44; // [xsp+40h] [xbp-10h]
  __int64 v45; // [xsp+48h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v42 = 0;
  v44 = 0;
  memset(v43, 0, sizeof(v43));
  v41[0] = 0;
  if ( !a1 || !a7 )
  {
    v25 = "%s: invalid input parameters";
LABEL_12:
    qdf_trace_msg(0x68u, 2u, v25, a8, a9, a10, a11, a12, a13, a14, a15, "wlan_cm_sta_set_chan_param");
    result = 4;
    goto LABEL_27;
  }
  v16 = *(_QWORD *)(a1 + 216);
  if ( !v16 )
  {
    v25 = "%s: invalid pdev";
    goto LABEL_12;
  }
  if ( a3 == 1 )
  {
    v20 = a1;
    if ( (wlan_reg_is_24ghz_ch_freq(a2) & 1) != 0 )
    {
      v28 = wlan_reg_chan_band_to_freq(v16, a5, 1);
      v29 = a2 + 20;
      v23 = 0;
      if ( v28 != a2 + 10 )
        v29 = 0;
      if ( v28 == a2 - 10 )
        v24 = a2 - 20;
      else
        v24 = v29;
      goto LABEL_20;
    }
    goto LABEL_19;
  }
  v20 = a1;
  if ( a3 != 7 )
  {
LABEL_19:
    v24 = 0;
    v23 = 0;
    goto LABEL_20;
  }
  if ( (wlan_reg_is_6ghz_chan_freq(a2) & 1) != 0 )
    v22 = 4;
  else
    v22 = 2;
  v23 = wlan_reg_chan_band_to_freq(v16, a6, v22);
  v24 = 0;
LABEL_20:
  wlan_reg_extract_puncture_by_bw(a3, a4, a2, v23, 0, &v42);
  if ( v42 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: sta vdev %d freq %d RX bw %d puncture 0x%x primary chan is punctured",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "wlan_cm_sta_set_chan_param",
      *(unsigned __int8 *)(v20 + 168),
      a2,
      a3,
      (unsigned __int16)a4);
    result = 5;
  }
  else
  {
    if ( *a7 != 7 )
      v23 = 0;
    qdf_mem_set(v43, 0x34u, 0);
    wlan_reg_fill_channel_list_for_pwrmode(v16, a2, v24, *a7, v23, v43, 0, 1);
    v38 = *(_QWORD *)((char *)v43 + 4);
    v39 = *(_OWORD *)((char *)&v43[1] + 4);
    v40 = HIDWORD(v43[0]) == a3;
    *(_QWORD *)a7 = *(_QWORD *)((char *)v43 + 4);
    *(_OWORD *)(a7 + 2) = v39;
    if ( !v40 )
    {
      wlan_reg_extract_puncture_by_bw(a3, a4, a2, a7[3], v38, v41);
      LOWORD(a4) = v41[0];
    }
    result = 0;
    *((_WORD *)a7 + 9) = a4;
  }
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
