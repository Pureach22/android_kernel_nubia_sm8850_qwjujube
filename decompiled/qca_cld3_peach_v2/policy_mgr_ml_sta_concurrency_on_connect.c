__int64 __fastcall policy_mgr_ml_sta_concurrency_on_connect(
        __int64 result,
        __int64 a2,
        unsigned int a3,
        unsigned __int8 *a4,
        char a5,
        unsigned __int8 *a6,
        __int64 a7,
        __int64 a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16)
{
  unsigned int v16; // w23
  __int64 v17; // x22
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w25
  unsigned __int16 *v33; // x8
  unsigned int v34; // w26
  char is_mlo_vdev; // w0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x8
  __int64 v53; // x26
  __int64 v54; // x8
  unsigned __int64 v55; // x28
  __int64 v56; // x9
  bool is_24ghz_ch_freq; // w27
  bool v58; // w0
  unsigned __int8 *v59; // x28
  unsigned int v60; // w10
  _BOOL4 v61; // w19
  unsigned __int64 v62; // x19
  int v64; // w0
  __int64 v65; // x28
  unsigned int v66; // w27
  unsigned int v67; // w27
  unsigned int v68; // w27
  __int64 v69; // x5
  unsigned int v70; // w23
  const char *v71; // x2
  __int64 v72; // x4
  __int64 v73; // x8
  unsigned int v74; // w2
  unsigned int v75; // w27
  unsigned int v76; // w27
  unsigned int v77; // w27
  unsigned int v78; // w23
  __int64 v79; // [xsp+0h] [xbp-20h]
  unsigned int v80; // [xsp+8h] [xbp-18h]
  int v81; // [xsp+10h] [xbp-10h] BYREF
  char v82; // [xsp+14h] [xbp-Ch]
  __int64 v83; // [xsp+18h] [xbp-8h]

  v83 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = *(unsigned __int8 *)(a2 + 168);
  v82 = 0;
  v81 = 0;
  if ( a5 )
  {
    v17 = result;
    if ( (wlan_vdev_mlme_is_mlo_vdev(a2, a9, a10, a11, a12, a13, a14, a15, a16) & 1) != 0 )
    {
      v32 = *(_DWORD *)(a7 + 4LL * *a6);
    }
    else
    {
      v33 = *(unsigned __int16 **)(a2 + 32);
      v32 = v33 ? *v33 : 0;
    }
    v34 = *(unsigned __int8 *)(a8 + *a6);
    is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(a2, v24, v25, v26, v27, v28, v29, v30, v31);
    result = qdf_trace_msg(
               0x4Fu,
               8u,
               "%s: vdev %d: Freq %d (non ML vdev id %d), is ML STA %d",
               v36,
               v37,
               v38,
               v39,
               v40,
               v41,
               v42,
               v43,
               "policy_mgr_ml_sta_concurrency_on_connect",
               v16,
               v32,
               v34,
               is_mlo_vdev & 1);
    if ( v32 )
    {
      v52 = *(_QWORD *)(a2 + 216);
      if ( !v52 )
        goto LABEL_61;
      v53 = *(_QWORD *)(v52 + 80);
      if ( !v53 )
        goto LABEL_61;
      if ( (_BYTE)a3 )
      {
        v54 = 0;
        v55 = (unsigned __int8)a3;
        do
        {
          v56 = a4[v54];
          if ( *(_DWORD *)(a7 + 4 * v56) == v32 )
          {
            qdf_trace_msg(
              0x4Fu,
              8u,
              "%s: vdev %d: ML vdev %d lead to SCC, STA freq %d ML freq %d, no need to disable link",
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              "policy_mgr_get_concurrent_num_links",
              *(unsigned __int8 *)(a2 + 168),
              *(unsigned __int8 *)(a8 + v56),
              v32,
              v32);
            goto LABEL_61;
          }
          ++v54;
        }
        while ( (unsigned __int8)a3 != v54 );
        is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(v32);
        v58 = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a7 + 4LL * *a4));
        if ( is_24ghz_ch_freq )
        {
          v59 = a4;
          if ( v58 )
            goto LABEL_73;
          v60 = a3;
          LOBYTE(v81) = *(_BYTE *)(a8 + *a4);
          if ( (unsigned __int8)a3 != 1 )
          {
            v59 = a4 + 1;
            if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a7 + 4LL * a4[1])) )
              goto LABEL_73;
            v60 = a3;
            BYTE1(v81) = *(_BYTE *)(a8 + *v59);
            if ( (unsigned __int8)a3 != 2 )
            {
              v59 = a4 + 2;
              if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a7 + 4LL * a4[2])) )
                goto LABEL_73;
              v60 = a3;
              BYTE2(v81) = *(_BYTE *)(a8 + *v59);
              if ( (unsigned __int8)a3 != 3 )
              {
                v59 = a4 + 3;
                if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a7 + 4LL * a4[3])) )
                  goto LABEL_73;
                v60 = a3;
                HIBYTE(v81) = *(_BYTE *)(a8 + *v59);
                if ( (unsigned __int8)a3 != 4 )
                {
                  v59 = a4 + 4;
                  if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a7 + 4LL * a4[4])) )
                    goto LABEL_73;
                  v60 = a3;
                  v82 = *(_BYTE *)(a8 + *v59);
                  if ( (unsigned __int8)a3 != 5 )
                  {
                    v59 = a4 + 5;
                    if ( !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a7 + 4LL * a4[5])) )
                      goto LABEL_100;
                    goto LABEL_73;
                  }
                }
              }
            }
          }
          goto LABEL_59;
        }
        v80 = a3;
        if ( v58 )
        {
          v61 = 0;
        }
        else
        {
          v79 = v17;
          v62 = 0;
          while ( v55 - 1 != v62 )
          {
            if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a7 + 4LL * a4[++v62])) )
              goto LABEL_37;
          }
          v62 = v55;
LABEL_37:
          v61 = v62 >= v55;
        }
      }
      else
      {
        if ( wlan_reg_is_24ghz_ch_freq(v32) )
          goto LABEL_61;
        v80 = a3;
        v61 = 1;
      }
      v64 = wlan_cm_same_band_sta_allowed(v53);
      if ( (_BYTE)v80 && ((v61 | v64) & 1) != 0 )
      {
        v65 = 0;
        while ( 1 )
        {
          v66 = *(_DWORD *)(a7 + 4LL * a4[v65]);
          if ( (policy_mgr_is_hw_sbs_capable(v53) & 1) != 0
            && !wlan_reg_is_24ghz_ch_freq(v32)
            && !wlan_reg_is_24ghz_ch_freq(v66)
            && (policy_mgr_2_freq_same_mac_in_sbs(v53, v32, v66) & 1) == 0 )
          {
            break;
          }
          if ( (unsigned __int8)v80 == ++v65 )
            goto LABEL_56;
        }
        v67 = *(_DWORD *)(a7 + 4LL * *a4);
        a3 = v80;
        v59 = a4;
        if ( (policy_mgr_is_hw_sbs_capable(v53) & 1) == 0 )
          goto LABEL_73;
        v59 = a4;
        if ( wlan_reg_is_24ghz_ch_freq(v32) )
          goto LABEL_73;
        v59 = a4;
        if ( wlan_reg_is_24ghz_ch_freq(v67) )
          goto LABEL_73;
        v59 = a4;
        if ( (policy_mgr_2_freq_same_mac_in_sbs(v53, v32, v67) & 1) != 0 )
          goto LABEL_73;
        v60 = v80;
        LOBYTE(v81) = *(_BYTE *)(a8 + *a4);
        if ( (unsigned __int8)v80 != 1 )
        {
          v59 = a4 + 1;
          v68 = *(_DWORD *)(a7 + 4LL * a4[1]);
          if ( (policy_mgr_is_hw_sbs_capable(v53) & 1) == 0 )
            goto LABEL_73;
          v79 = v17;
          if ( wlan_reg_is_24ghz_ch_freq(v32)
            || wlan_reg_is_24ghz_ch_freq(v68)
            || (policy_mgr_2_freq_same_mac_in_sbs(v53, v32, v68) & 1) != 0 )
          {
            goto LABEL_73;
          }
          v60 = v80;
          BYTE1(v81) = *(_BYTE *)(a8 + *v59);
          if ( (unsigned __int8)v80 != 2 )
          {
            v59 = a4 + 2;
            v75 = *(_DWORD *)(a7 + 4LL * a4[2]);
            if ( (policy_mgr_is_hw_sbs_capable(v53) & 1) == 0
              || wlan_reg_is_24ghz_ch_freq(v32)
              || wlan_reg_is_24ghz_ch_freq(v75)
              || (policy_mgr_2_freq_same_mac_in_sbs(v53, v32, v75) & 1) != 0 )
            {
              goto LABEL_73;
            }
            v60 = v80;
            BYTE2(v81) = *(_BYTE *)(a8 + *v59);
            if ( (unsigned __int8)v80 != 3 )
            {
              v59 = a4 + 3;
              v76 = *(_DWORD *)(a7 + 4LL * a4[3]);
              if ( (policy_mgr_is_hw_sbs_capable(v53) & 1) == 0
                || wlan_reg_is_24ghz_ch_freq(v32)
                || wlan_reg_is_24ghz_ch_freq(v76)
                || (policy_mgr_2_freq_same_mac_in_sbs(v53, v32, v76) & 1) != 0 )
              {
                goto LABEL_73;
              }
              v60 = v80;
              HIBYTE(v81) = *(_BYTE *)(a8 + *v59);
              if ( (unsigned __int8)v80 != 4 )
              {
                v59 = a4 + 4;
                v77 = *(_DWORD *)(a7 + 4LL * a4[4]);
                if ( (policy_mgr_is_hw_sbs_capable(v53) & 1) != 0
                  && !wlan_reg_is_24ghz_ch_freq(v32)
                  && !wlan_reg_is_24ghz_ch_freq(v77)
                  && (policy_mgr_2_freq_same_mac_in_sbs(v53, v32, v77) & 1) == 0 )
                {
                  v60 = v80;
                  v82 = *(_BYTE *)(a8 + *v59);
                  if ( (unsigned __int8)v80 != 5 )
                  {
                    v59 = a4 + 5;
                    v78 = *(_DWORD *)(a7 + 4LL * a4[5]);
                    if ( (policy_mgr_is_hw_sbs_capable(v53) & 1) != 0
                      && !wlan_reg_is_24ghz_ch_freq(v32)
                      && !wlan_reg_is_24ghz_ch_freq(v78)
                      && (policy_mgr_2_freq_same_mac_in_sbs(v53, v32, v78) & 1) == 0 )
                    {
LABEL_100:
                      __break(1u);
                    }
                    goto LABEL_73;
                  }
                  goto LABEL_59;
                }
LABEL_73:
                v73 = *v59;
                v70 = 1;
                v69 = *(unsigned __int8 *)(a8 + v73);
                LOBYTE(v81) = *(_BYTE *)(a8 + v73);
LABEL_74:
                qdf_trace_msg(
                  0x4Fu,
                  8u,
                  "%s: affected link found: %u vdev_id: %u",
                  v44,
                  v45,
                  v46,
                  v47,
                  v48,
                  v49,
                  v50,
                  v51,
                  "policy_mgr_ml_sta_concurrency_on_connect",
                  (unsigned __int8)v70,
                  v69,
                  v79);
                v74 = 3;
                if ( (unsigned __int8)v70 >= (unsigned int)(unsigned __int8)a3 || (unsigned __int8)v70 > 5u )
                  goto LABEL_78;
                if ( (mlo_is_sta_inactivity_allowed_with_quiet(v17, a8, a3, a4, v70, &v81) & 1) != 0 )
                {
                  v74 = 2;
LABEL_78:
                  result = policy_mgr_mlo_sta_set_link_ext(
                             v17,
                             1u,
                             v74,
                             v70,
                             (unsigned __int8 *)&v81,
                             0,
                             0,
                             v44,
                             v45,
                             v46,
                             v47,
                             v48,
                             v49,
                             v50,
                             v51);
                  goto LABEL_63;
                }
                v72 = (unsigned __int8)v81;
                v71 = "%s: vdev %d: force inactivity is not allowed";
                goto LABEL_62;
              }
            }
          }
        }
      }
      else
      {
LABEL_56:
        a3 = v80;
        if ( !(_BYTE)v80 )
          goto LABEL_61;
        v59 = a4;
        if ( !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a7 + 4LL * *a4)) )
          goto LABEL_73;
        v60 = v80;
        LOBYTE(v81) = *(_BYTE *)(a8 + *a4);
        if ( (unsigned __int8)v80 != 1 )
        {
          v59 = a4 + 1;
          if ( !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a7 + 4LL * a4[1])) )
            goto LABEL_73;
          v60 = v80;
          BYTE1(v81) = *(_BYTE *)(a8 + *v59);
          if ( (unsigned __int8)v80 != 2 )
          {
            v59 = a4 + 2;
            if ( !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a7 + 4LL * a4[2])) )
              goto LABEL_73;
            v60 = v80;
            BYTE2(v81) = *(_BYTE *)(a8 + *v59);
            if ( (unsigned __int8)v80 != 3 )
            {
              v59 = a4 + 3;
              if ( !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a7 + 4LL * a4[3])) )
                goto LABEL_73;
              v60 = v80;
              HIBYTE(v81) = *(_BYTE *)(a8 + *v59);
              if ( (unsigned __int8)v80 != 4 )
              {
                v59 = a4 + 4;
                if ( !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a7 + 4LL * a4[4])) )
                  goto LABEL_73;
                v60 = v80;
                v82 = *(_BYTE *)(a8 + *v59);
                if ( (unsigned __int8)v80 != 5 )
                {
                  v59 = a4 + 5;
                  if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a7 + 4LL * a4[5])) )
                    goto LABEL_100;
                  goto LABEL_73;
                }
              }
            }
          }
        }
      }
LABEL_59:
      if ( (_BYTE)v60 )
      {
        a3 = v60;
        v69 = (unsigned __int8)v81;
        v70 = v60;
        goto LABEL_74;
      }
LABEL_61:
      v71 = "%s: vdev %d: no affected link found";
      v72 = v16;
LABEL_62:
      result = qdf_trace_msg(
                 0x4Fu,
                 8u,
                 v71,
                 v44,
                 v45,
                 v46,
                 v47,
                 v48,
                 v49,
                 v50,
                 v51,
                 "policy_mgr_ml_sta_concurrency_on_connect",
                 v72,
                 v79);
    }
  }
LABEL_63:
  _ReadStatusReg(SP_EL0);
  return result;
}
