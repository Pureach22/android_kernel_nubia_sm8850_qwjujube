__int64 __fastcall lim_update_ext_tpe_power(
        __int64 a1,
        __int64 a2,
        unsigned __int8 *a3,
        unsigned int a4,
        _BYTE *a5,
        unsigned __int8 a6,
        char a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  __int64 v22; // x0
  __int64 cmpt_obj; // x0
  __int64 v24; // x26
  unsigned __int8 v25; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w20
  unsigned int v35; // w8
  unsigned __int64 v36; // x25
  unsigned int v37; // w27
  unsigned int v38; // w8
  int v39; // w22
  __int64 v41; // x8
  __int64 v42; // x26
  __int64 v43; // x24
  __int64 v44; // x28
  __int64 v45; // x23
  int v46; // w8
  __int64 v47; // x9
  __int64 v48; // x10
  int v49; // w9
  int v50; // w8
  int v51; // [xsp+8h] [xbp-18h] BYREF
  __int64 v52; // [xsp+Ch] [xbp-14h]
  int v53; // [xsp+14h] [xbp-Ch]
  __int64 v54; // [xsp+18h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = *(_QWORD *)(a2 + 16);
  v52 = 0;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v22, a8, a9, a10, a11, a12, a13, a14, a15);
  if ( !cmpt_obj )
    goto LABEL_14;
  v24 = cmpt_obj;
  v25 = *(_BYTE *)(a2 + 7184);
  v51 = 7;
  v53 = wlan_reg_compute_6g_center_freq_from_cfi(v25);
  if ( (a7 & 1) == 0 )
  {
    v35 = a3[1];
    if ( (v35 & 7) <= 2 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: tx power count advertised by ap %d less than %d",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "lim_get_eirp_320_power_from_tpe_ie");
      v34 = 0;
      goto LABEL_15;
    }
    if ( a3[2] < 5u
      || (v38 = (v35 >> 3) & 7, v39 = 0, v38 <= 4) && ((1 << v38) & 0x15) != 0 && (v39 = a3[11], v39 == 100) )
    {
LABEL_14:
      v34 = 0;
      goto LABEL_15;
    }
    wlan_reg_set_channel_params_for_pwrmode(
      *(_QWORD *)(a1 + 21560),
      *(_DWORD *)(a2 + 284),
      0,
      (__int64)&v51,
      0,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33);
    if ( *(unsigned __int8 *)(v24 + 624) == v39 )
    {
      v49 = *(_DWORD *)(v24 + 572);
      v50 = HIDWORD(v52);
      if ( v49 == HIDWORD(v52) )
        goto LABEL_32;
    }
    else
    {
      v50 = HIDWORD(v52);
    }
    *a5 = 1;
    v49 = v50;
LABEL_32:
    v34 = 1;
    *(_DWORD *)(v24 + 572) = v49;
    *(_BYTE *)(v24 + 624) = v39;
    *(_DWORD *)(v24 + 924) = v49;
    *(_WORD *)(v24 + 928) = v39;
    goto LABEL_15;
  }
  v34 = a6;
  if ( a6 < 0x10u )
  {
    v36 = a3[11] & 0xF;
    if ( (a3[11] & 0xF) != 0 )
    {
      v37 = v36 + a6;
      if ( v37 <= 0x10 )
      {
        v41 = v24;
        v42 = v24 + 620;
        v43 = 12;
        v44 = v41 + 556;
        v45 = v41 + 764;
        do
        {
          v46 = a3[v43];
          if ( v46 == 128 )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: %d is punctured freq",
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              "lim_update_ext_tpe_power",
              a4);
          }
          else
          {
            v47 = v34;
            if ( *(unsigned __int8 *)(v42 + v34) != v46 || a4 != *(_DWORD *)(v44 + 4LL * v34) )
              *a5 = 1;
            v48 = v45 + 8LL * v34++;
            *(_DWORD *)(v44 + 4 * v47) = a4;
            *(_BYTE *)(v42 + v47) = v46;
            *(_WORD *)(v48 + 4) = v46;
            *(_DWORD *)v48 = a4;
          }
          if ( v43 - 11 >= v36 )
            break;
          a4 += 20;
          ++v43;
        }
        while ( v34 < v37 );
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: total powers greater than max %d",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
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
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "lim_update_ext_tpe_power");
    }
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: already updated %d psd powers",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "lim_update_ext_tpe_power",
      a6);
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return v34;
}
