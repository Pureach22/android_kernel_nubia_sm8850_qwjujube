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
        double a16)
{
  unsigned int v21; // w22
  int v22; // w25
  unsigned int _5g_bonded_channel_for_pwrmode; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  const char *v32; // x2
  __int64 result; // x0
  __int64 v34; // x25
  unsigned int v35; // w22
  __int16 v36; // w9
  __int16 v37; // w26
  _DWORD *v38; // x8
  int v39; // w8
  __int16 v40; // w11
  __int64 v41; // x0
  __int16 v42; // w10
  unsigned int v43; // w22
  int v44; // [xsp+4h] [xbp-1Ch] BYREF
  _WORD v45[2]; // [xsp+8h] [xbp-18h] BYREF
  _WORD v46[2]; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v47[2]; // [xsp+10h] [xbp-10h] BYREF

  v47[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v44 = 0;
  v47[0] = 0;
  if ( *(_DWORD *)(channel_map + 504) > (unsigned int)(unsigned __int16)a2
    || *(_DWORD *)(channel_map + 1212) < (unsigned int)(unsigned __int16)a2 )
  {
    goto LABEL_14;
  }
  v46[0] = 0;
  v45[0] = 0;
  if ( !a4 )
  {
    v32 = "%s: is_psd pointer null";
LABEL_13:
    qdf_trace_msg(0x51u, 2u, v32, a9, a10, a11, a12, a13, a14, a15, a16, "reg_decide_6ghz_power_within_bw_for_freq");
    goto LABEL_14;
  }
  if ( !a5 )
  {
    v32 = "%s: min_tx_power pointer null";
    goto LABEL_13;
  }
  if ( !a6 )
  {
    v32 = "%s: min_psd_eirp pointer null";
    goto LABEL_13;
  }
  if ( !a7 )
  {
    v32 = "%s: power_type pointer null";
    goto LABEL_13;
  }
  v21 = a2;
  v22 = a3;
  _5g_bonded_channel_for_pwrmode = reg_get_5g_bonded_channel_for_pwrmode(a1, a2, a3, v47, a8);
  if ( _5g_bonded_channel_for_pwrmode - 4 > 0xFFFFFFFD )
  {
    if ( v22 )
    {
      v34 = v47[0];
      v35 = *(unsigned __int16 *)v47[0];
      if ( v35 > *(unsigned __int16 *)(v47[0] + 2LL) )
      {
LABEL_18:
        reg_get_cur_6g_ap_pwr_type();
        result = 0;
        goto LABEL_15;
      }
      if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, __int64, _WORD *, _WORD *, int *))reg_get_channel_power_attr_from_secondary_list_for_freq)(
                           a1,
                           *(unsigned __int16 *)v47[0],
                           a4,
                           v46,
                           v45,
                           &v44) )
        goto LABEL_14;
      v39 = v45[0];
      v40 = v46[0];
      *a6 = v45[0];
      *a5 = v40;
      if ( v39 < *a6 )
        *a6 = v39;
      v41 = a1;
      v42 = v44;
      v38 = a7;
      if ( v46[0] < (unsigned int)(unsigned __int16)*a5 )
        *a5 = v46[0];
      v43 = v35 + 20;
      v37 = v44 | v42;
      if ( v43 <= *(unsigned __int16 *)(v34 + 2) )
      {
        while ( !(unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, __int64, _WORD *, _WORD *, int *))reg_get_channel_power_attr_from_secondary_list_for_freq)(
                                 v41,
                                 v43,
                                 a4,
                                 v46,
                                 v45,
                                 &v44) )
        {
          if ( v45[0] < *a6 )
            *a6 = v45[0];
          v41 = a1;
          v38 = a7;
          if ( v46[0] < (unsigned int)(unsigned __int16)*a5 )
            *a5 = v46[0];
          v43 += 20;
          v37 |= v44;
          if ( v43 > *(unsigned __int16 *)(v34 + 2) )
            goto LABEL_27;
        }
        goto LABEL_14;
      }
    }
    else
    {
      if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, __int64, _WORD *, _WORD *, int *))reg_get_channel_power_attr_from_secondary_list_for_freq)(
                           a1,
                           v21,
                           a4,
                           v46,
                           v45,
                           &v44) )
        goto LABEL_14;
      v36 = v46[0];
      v37 = v44;
      *a6 = v45[0];
      v38 = a7;
      *a5 = v36;
    }
LABEL_27:
    if ( (~v37 & 0x2200) == 0 )
    {
      result = 0;
      *v38 = 0;
      goto LABEL_15;
    }
    if ( (v37 & 0x2000) != 0 )
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
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    "reg_decide_6ghz_power_within_bw_for_freq",
    _5g_bonded_channel_for_pwrmode);
LABEL_14:
  result = 4;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
