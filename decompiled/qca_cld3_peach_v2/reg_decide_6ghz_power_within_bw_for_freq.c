__int64 __fastcall reg_decide_6ghz_power_within_bw_for_freq(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        _WORD *a5,
        __int16 *a6,
        _DWORD *a7,
        unsigned int a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        unsigned __int16 a17)
{
  unsigned int v22; // w22
  int v23; // w25
  unsigned int _5g_bonded_channel_for_pwrmode; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  const char *v33; // x2
  __int64 result; // x0
  __int64 v35; // x25
  unsigned int v36; // w22
  __int16 v37; // w9
  __int16 v38; // w26
  _DWORD *v39; // x8
  int v40; // w8
  __int16 v41; // w11
  __int64 v42; // x0
  __int16 v43; // w10
  unsigned int v44; // w22
  int v45; // [xsp+4h] [xbp-1Ch] BYREF
  _WORD v46[2]; // [xsp+8h] [xbp-18h] BYREF
  _WORD v47[2]; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v48[2]; // [xsp+10h] [xbp-10h] BYREF

  v48[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45 = 0;
  v48[0] = 0;
  if ( *(_DWORD *)(channel_map + 504) > (unsigned int)(unsigned __int16)a2
    || *(_DWORD *)(channel_map + 1212) < (unsigned int)(unsigned __int16)a2 )
  {
    goto LABEL_14;
  }
  v47[0] = 0;
  v46[0] = 0;
  if ( !a4 )
  {
    v33 = "%s: is_psd pointer null";
LABEL_13:
    qdf_trace_msg(0x51u, 2u, v33, a9, a10, a11, a12, a13, a14, a15, a16, "reg_decide_6ghz_power_within_bw_for_freq");
    goto LABEL_14;
  }
  if ( !a5 )
  {
    v33 = "%s: min_tx_power pointer null";
    goto LABEL_13;
  }
  if ( !a6 )
  {
    v33 = "%s: min_psd_eirp pointer null";
    goto LABEL_13;
  }
  if ( !a7 )
  {
    v33 = "%s: power_type pointer null";
    goto LABEL_13;
  }
  v22 = a2;
  v23 = a3;
  _5g_bonded_channel_for_pwrmode = reg_get_5g_bonded_channel_for_pwrmode(a1, a2, a3, v48, a8, a17);
  if ( _5g_bonded_channel_for_pwrmode - 4 > 0xFFFFFFFD )
  {
    if ( v23 )
    {
      v35 = v48[0];
      v36 = *(unsigned __int16 *)v48[0];
      if ( v36 > *(unsigned __int16 *)(v48[0] + 2LL) )
      {
LABEL_18:
        reg_get_cur_6g_ap_pwr_type();
        result = 0;
        goto LABEL_15;
      }
      if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, __int64, _WORD *, _WORD *, int *))reg_get_channel_power_attr_from_secondary_list_for_freq)(
                           a1,
                           *(unsigned __int16 *)v48[0],
                           a4,
                           v47,
                           v46,
                           &v45) )
        goto LABEL_14;
      v40 = v46[0];
      v41 = v47[0];
      *a6 = v46[0];
      *a5 = v41;
      if ( v40 < *a6 )
        *a6 = v40;
      v42 = a1;
      v43 = v45;
      v39 = a7;
      if ( v47[0] < (unsigned int)(unsigned __int16)*a5 )
        *a5 = v47[0];
      v44 = v36 + 20;
      v38 = v45 | v43;
      if ( v44 <= *(unsigned __int16 *)(v35 + 2) )
      {
        while ( !(unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, __int64, _WORD *, _WORD *, int *))reg_get_channel_power_attr_from_secondary_list_for_freq)(
                                 v42,
                                 v44,
                                 a4,
                                 v47,
                                 v46,
                                 &v45) )
        {
          if ( v46[0] < *a6 )
            *a6 = v46[0];
          v42 = a1;
          v39 = a7;
          if ( v47[0] < (unsigned int)(unsigned __int16)*a5 )
            *a5 = v47[0];
          v44 += 20;
          v38 |= v45;
          if ( v44 > *(unsigned __int16 *)(v35 + 2) )
            goto LABEL_27;
        }
        goto LABEL_14;
      }
    }
    else
    {
      if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, __int64, _WORD *, _WORD *, int *))reg_get_channel_power_attr_from_secondary_list_for_freq)(
                           a1,
                           v22,
                           a4,
                           v47,
                           v46,
                           &v45) )
        goto LABEL_14;
      v37 = v47[0];
      v38 = v45;
      *a6 = v46[0];
      v39 = a7;
      *a5 = v37;
    }
LABEL_27:
    if ( (~v38 & 0x2200) == 0 )
    {
      result = 0;
      *v39 = 0;
      goto LABEL_15;
    }
    if ( (v38 & 0x2000) != 0 )
    {
      result = 0;
      *a7 = 1;
      goto LABEL_15;
    }
    goto LABEL_18;
  }
  qdf_trace_msg(
    0x51u,
    2u,
    "%s: invalid channel state %d",
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    "reg_decide_6ghz_power_within_bw_for_freq",
    _5g_bonded_channel_for_pwrmode);
LABEL_14:
  result = 4;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
