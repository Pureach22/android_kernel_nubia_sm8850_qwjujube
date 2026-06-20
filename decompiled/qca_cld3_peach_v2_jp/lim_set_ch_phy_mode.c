__int64 __fastcall lim_set_ch_phy_mode(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *v21; // x20
  __int64 cmpt_obj; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned __int16 *v31; // x25
  __int64 v32; // x24
  unsigned int v33; // w0
  char v34; // w0
  signed int v35; // w21
  char v36; // w23
  unsigned int bw_value; // w22
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  int v46; // w23
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  unsigned int v55; // w1
  const char *v56; // x2
  unsigned int v57; // w1
  char v58; // w0
  __int64 *v59; // x8
  __int64 v60; // x9
  bool is_24ghz_ch_freq; // w0
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // x8
  __int64 v71; // x9
  unsigned int v72; // w1
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  int v81; // w9
  unsigned int v82; // w1
  __int64 v83; // x0
  int v84; // w0
  __int64 result; // x0
  int v86; // w19
  int v87; // w8
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  unsigned int v96; // w1
  _QWORD v97[3]; // [xsp+8h] [xbp-18h] BYREF

  v97[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(53, (__int64)"lim_set_ch_phy_mode", a3, a4, a5, a6, a7, a8, a9, a10);
  v97[0] = 0;
  v97[1] = 0;
  if ( !context )
    goto LABEL_42;
  v21 = context;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, v13, v14, v15, v16, v17, v18, v19, v20);
  if ( cmpt_obj )
  {
    v31 = *(unsigned __int16 **)(a1 + 40);
    v32 = cmpt_obj;
    v33 = *v31;
    *((_DWORD *)v31 + 4) = v33;
    v34 = wlan_reg_freq_to_band(v33);
    v35 = *((_DWORD *)v31 + 6);
    v36 = v34;
    bw_value = (unsigned __int16)wlan_reg_get_bw_value(v35);
    if ( bw_value < 0x15 )
    {
      v57 = *((_DWORD *)v31 + 4);
      if ( !v57 )
        goto LABEL_12;
      v58 = wlan_reg_freq_to_chan(v21[2695], v57, v38, v39, v40, v41, v42, v43, v44, v45);
    }
    else
    {
      v46 = 1 << v36;
      if ( *((_BYTE *)v31 + 3) )
      {
        *((_DWORD *)v31 + 4) = wlan_reg_chan_band_to_freq(
                                 v21[2695],
                                 *((unsigned __int8 *)v31 + 3),
                                 v46,
                                 v38,
                                 v39,
                                 v40,
                                 v41,
                                 v42,
                                 v43,
                                 v44,
                                 v45);
        if ( bw_value >= 0x51 )
        {
          v55 = *((unsigned __int8 *)v31 + 4);
          if ( *((_BYTE *)v31 + 4) )
          {
LABEL_7:
            *((_DWORD *)v31 + 5) = wlan_reg_chan_band_to_freq(
                                     v21[2695],
                                     v55,
                                     v46,
                                     v47,
                                     v48,
                                     v49,
                                     v50,
                                     v51,
                                     v52,
                                     v53,
                                     v54);
LABEL_13:
            *((_QWORD *)v31 + 1) = 0;
            v59 = (__int64 *)(v31 + 4);
            *((_DWORD *)v31 + 6) = v35;
            if ( v35 <= 1 )
            {
              if ( v35 )
              {
                if ( v35 != 1 )
                  goto LABEL_28;
                v60 = 0x200000;
              }
              else
              {
                v60 = 0x100000;
              }
LABEL_27:
              *v59 = v60;
LABEL_28:
              is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*v31);
              v70 = *((_QWORD *)v31 + 1);
              v71 = 256;
              v31[3] = 0;
              v72 = *v31;
              if ( is_24ghz_ch_freq )
                v71 = 128;
              *((_QWORD *)v31 + 1) = v70 | v71;
              if ( (wlan_reg_is_dfs_for_freq(v21[2695], v72, v62, v63, v64, v65, v66, v67, v68, v69) & 1) != 0 )
                v31[3] |= 2u;
              v81 = *((_DWORD *)v31 + 5);
              if ( v81 )
              {
                if ( *((_DWORD *)v31 + 6) == 4 )
                  v82 = v81 - 30;
                else
                  v82 = *v31;
                v83 = v21[2695];
                LODWORD(v97[0]) = *((_DWORD *)v31 + 6);
                if ( (unsigned int)wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                                     v83,
                                     v82,
                                     (unsigned int *)v97,
                                     0,
                                     v73,
                                     v74,
                                     v75,
                                     v76,
                                     v77,
                                     v78,
                                     v79,
                                     v80) == 2 )
                  v31[3] |= 4u;
              }
              v23 = wma_chan_phy_mode(*v31, (unsigned int)v35, a2);
              if ( v84 != 31 && v84 )
              {
                if ( *((_DWORD *)v31 + 4) )
                {
                  if ( (unsigned int)(v35 - 3) > 1 || *((_DWORD *)v31 + 5) )
                  {
                    v86 = v84;
                    v87 = wmi_host_to_fw_phymode(v84);
                    result = 0;
                    *(_DWORD *)(v32 + 176) = v87;
                    *((_DWORD *)v31 + 7) = v86;
                    goto LABEL_43;
                  }
                  v56 = "%s: Invalid center freq2 for 160MHz";
                }
                else
                {
                  v56 = "%s: Invalid center freq1";
                }
              }
              else
              {
                v56 = "%s: Invalid phy mode!";
              }
              goto LABEL_41;
            }
            if ( v35 != 2 )
            {
              if ( v35 == 3 )
              {
                v60 = 0x4000000;
              }
              else
              {
                if ( v35 != 4 )
                  goto LABEL_28;
                v60 = 0x8000000;
              }
              goto LABEL_27;
            }
LABEL_24:
            v60 = 0x800000;
            v35 = 2;
            goto LABEL_27;
          }
LABEL_23:
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Invalid cntr_freq for bw %d, drop to 80",
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            "lim_set_ch_phy_mode",
            bw_value);
          *((_QWORD *)v31 + 1) = 0;
          v59 = (__int64 *)(v31 + 4);
          *(_QWORD *)(v31 + 10) = 0x200000000LL;
          *((_BYTE *)v31 + 4) = 0;
          goto LABEL_24;
        }
LABEL_12:
        *((_DWORD *)v31 + 5) = 0;
        *((_BYTE *)v31 + 4) = 0;
        goto LABEL_13;
      }
      if ( bw_value >= 0xA0 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Skip center_freq check for bw %d",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "lim_set_ch_phy_mode",
          bw_value);
        v55 = *((unsigned __int8 *)v31 + 4);
        if ( *((_BYTE *)v31 + 4) )
          goto LABEL_7;
        goto LABEL_23;
      }
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Invalid cntr_freq for bw %d, drop to 20",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "lim_set_ch_phy_mode",
        bw_value);
      v96 = *((_DWORD *)v31 + 4);
      if ( !v96 )
      {
        v35 = 0;
        goto LABEL_12;
      }
      v58 = wlan_reg_freq_to_chan(v21[2695], v96, v88, v89, v90, v91, v92, v93, v94, v95);
      v35 = 0;
    }
    *((_BYTE *)v31 + 3) = v58;
    goto LABEL_12;
  }
  v56 = "%s: vdev component object is NULL";
LABEL_41:
  qdf_trace_msg(0x35u, 2u, v56, v23, v24, v25, v26, v27, v28, v29, v30, "lim_set_ch_phy_mode");
LABEL_42:
  result = 16;
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return result;
}
