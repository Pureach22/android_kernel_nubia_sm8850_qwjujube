__int64 __fastcall lim_update_ext_tpe_power(
        __int64 a1,
        __int64 a2,
        unsigned __int8 *a3,
        unsigned int a4,
        _BYTE *a5,
        unsigned __int8 a6,
        unsigned __int16 *a7,
        char a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16)
{
  __int64 v24; // x0
  __int64 cmpt_obj; // x0
  __int64 v26; // x19
  unsigned __int8 v27; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w20
  unsigned int v37; // w8
  unsigned __int64 v38; // x26
  unsigned int v39; // w27
  unsigned int v40; // w8
  int v41; // w22
  __int64 v43; // x28
  __int64 v44; // x24
  __int64 v45; // x25
  __int64 v46; // x19
  unsigned int v47; // w8
  int v48; // w8
  __int64 v49; // x9
  __int64 v50; // x10
  int v51; // w9
  int v52; // w8
  _BYTE *v53; // [xsp+8h] [xbp-28h]
  int v54; // [xsp+10h] [xbp-20h] BYREF
  __int64 v55; // [xsp+14h] [xbp-1Ch]
  __int64 v56; // [xsp+1Ch] [xbp-14h]
  int v57; // [xsp+24h] [xbp-Ch]
  __int64 v58; // [xsp+28h] [xbp-8h]

  v58 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = *(_QWORD *)(a2 + 16);
  v57 = 0;
  v56 = 0;
  v55 = 0;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v24, a9, a10, a11, a12, a13, a14, a15, a16);
  if ( !cmpt_obj )
    goto LABEL_14;
  v26 = cmpt_obj;
  v27 = *(_BYTE *)(a2 + 7186);
  v54 = 7;
  LODWORD(v56) = wlan_reg_compute_6g_center_freq_from_cfi(v27);
  if ( (a8 & 1) == 0 )
  {
    v37 = a3[1];
    if ( (v37 & 7) <= 2 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: tx power count advertised by ap %d less than %d",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "lim_get_eirp_320_power_from_tpe_ie");
      v36 = 0;
      goto LABEL_15;
    }
    if ( a3[2] < 5u
      || (v40 = (v37 >> 3) & 7, v41 = 0, v40 <= 4) && ((1 << v40) & 0x15) != 0 && (v41 = a3[11], v41 == 100) )
    {
LABEL_14:
      v36 = 0;
      goto LABEL_15;
    }
    wlan_reg_set_channel_params_for_pwrmode(
      *(_QWORD *)(a1 + 21632),
      *(_DWORD *)(a2 + 284),
      0,
      (__int64)&v54,
      0,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35);
    if ( *(unsigned __int8 *)(v26 + 640) == v41 )
    {
      v51 = *(_DWORD *)(v26 + 588);
      v52 = HIDWORD(v55);
      if ( v51 == HIDWORD(v55) )
        goto LABEL_36;
    }
    else
    {
      v52 = HIDWORD(v55);
    }
    *a5 = 1;
    v51 = v52;
LABEL_36:
    v36 = 1;
    *(_DWORD *)(v26 + 588) = v51;
    *(_BYTE *)(v26 + 640) = v41;
    *(_DWORD *)(v26 + 940) = v51;
    *(_WORD *)(v26 + 944) = v41;
    goto LABEL_15;
  }
  v36 = a6;
  if ( a6 < 0x10u )
  {
    v38 = a3[11] & 0xF;
    if ( (a3[11] & 0xF) != 0 )
    {
      v39 = v38 + a6;
      if ( v39 <= 0x10 )
      {
        v53 = a5;
        v43 = v26 + 636;
        v44 = v26 + 572;
        v45 = v26 + 780;
        v46 = 12;
        do
        {
          if ( a7 )
          {
            if ( a4 >= *a7 )
            {
              v47 = a7[1];
              if ( a4 <= v47 )
                a4 = v47 + 20;
            }
          }
          v48 = a3[v46];
          if ( v48 == 128 )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: %d is punctured freq",
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              "lim_update_ext_tpe_power",
              a4);
          }
          else
          {
            v49 = v36;
            if ( *(unsigned __int8 *)(v43 + v36) != v48 || *(_DWORD *)(v44 + 4LL * v36) != a4 )
              *v53 = 1;
            v50 = v45 + 8LL * v36++;
            *(_DWORD *)(v44 + 4 * v49) = a4;
            *(_BYTE *)(v43 + v49) = v48;
            *(_WORD *)(v50 + 4) = v48;
            *(_DWORD *)v50 = a4;
          }
          if ( v46 - 11 >= v38 )
            break;
          a4 += 20;
          ++v46;
        }
        while ( v36 < v39 );
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: total powers greater than max %d",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "lim_update_ext_tpe_power",
          16);
      }
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Ext psd count is 0",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "lim_update_ext_tpe_power");
    }
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: already updated %d psd powers",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "lim_update_ext_tpe_power",
      a6);
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return v36;
}
