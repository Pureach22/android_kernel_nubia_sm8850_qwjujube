__int64 __fastcall hdd_sysfs_ipaoptdpctrl_store(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  __int64 *context; // x20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  int v56; // w0
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  int v65; // w21
  __int64 v66; // x20
  __int64 v68; // x20
  char *v69; // x0
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  __int64 v78; // x22
  unsigned __int64 v79; // x23
  char *v80; // x0
  int v81; // w26
  char *v82; // x0
  char *v83; // x0
  int v84; // w0
  int v85; // w0
  char *v86; // x0
  char *v87; // x0
  _QWORD *v88; // x8
  unsigned __int64 v89; // x9
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  __int64 v98; // [xsp+8h] [xbp-218h] BYREF
  _WORD v99[2]; // [xsp+10h] [xbp-210h] BYREF
  __int16 v100; // [xsp+14h] [xbp-20Ch] BYREF
  char *stringp; // [xsp+18h] [xbp-208h] BYREF
  _QWORD v102[30]; // [xsp+20h] [xbp-200h] BYREF
  int v103; // [xsp+110h] [xbp-110h]
  _QWORD v104[31]; // [xsp+118h] [xbp-108h] BYREF
  __int16 v105; // [xsp+210h] [xbp-10h]
  __int64 v106; // [xsp+218h] [xbp-8h]

  v106 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v98 = 0;
  context = _cds_get_context(51, (__int64)"hdd_sysfs_ipaoptdpctrl_store", a1, a2, a3, a4, a5, a6, a7, a8);
  v23 = _wlan_hdd_validate_context(
          (__int64)context,
          (__int64)"hdd_sysfs_ipaoptdpctrl_store",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22);
  if ( !v23 )
  {
    if ( !wlan_hdd_validate_modules_state((__int64)context, v24, v25, v26, v27, v28, v29, v30, v31)
      || (ucfg_ipa_is_enabled() & 1) == 0 )
    {
      a12 = -22;
      goto LABEL_14;
    }
    if ( !hdd_get_adapter((__int64)context, 0) && !hdd_get_adapter((__int64)context, 1) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: device mode not supporting opt_dp_ctrl",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "hdd_sysfs_ipaoptdpctrl_store");
      a12 = 0;
      goto LABEL_14;
    }
    v23 = _osif_psoc_sync_op_start(*(_QWORD *)(context[3] + 488), &v98, (__int64)"hdd_sysfs_ipaoptdpctrl_store");
    if ( !v23 )
    {
      v105 = 0;
      memset(v104, 0, sizeof(v104));
      v103 = 0;
      memset(v102, 0, sizeof(v102));
      v100 = 0;
      v99[0] = 0;
      qdf_trace_msg(0x33u, 8u, "%s: enter", v40, v41, v42, v43, v44, v45, v46, v47, "__hdd_sysfs_ipaoptdpctrl_store");
      if ( ucfg_dp_ipa_ctrl_debug_supported(*context) )
      {
        v56 = hdd_sysfs_validate_and_copy_buf(v104, 250, a11, a12);
        if ( v56 )
        {
          v65 = v56;
          v66 = jiffies;
          if ( _hdd_sysfs_ipaoptdpctrl_store___last_ticks_14 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: invalid input",
              v57,
              v58,
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              "__hdd_sysfs_ipaoptdpctrl_store");
            _hdd_sysfs_ipaoptdpctrl_store___last_ticks_14 = v66;
          }
          a12 = v65;
          goto LABEL_21;
        }
        stringp = (char *)v104;
        v69 = strsep(&stringp, " ");
        if ( v69 && !(unsigned int)kstrtou8(v69, 0, v102) )
        {
          if ( !LOBYTE(v102[0]) )
          {
LABEL_44:
            ucfg_ipa_set_opt_dp_ctrl_flt(context[1], (unsigned __int8 *)v102, v70, v71, v72, v73, v74, v75, v76, v77);
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: exit",
              v90,
              v91,
              v92,
              v93,
              v94,
              v95,
              v96,
              v97,
              "__hdd_sysfs_ipaoptdpctrl_store");
            goto LABEL_21;
          }
          v78 = 0;
          v79 = 0;
          while ( 1 )
          {
            v80 = strsep(&stringp, " ");
            if ( !v80 )
              break;
            if ( v78 == 30 )
              goto LABEL_46;
            if ( (unsigned int)kstrtou8(v80, 0, (char *)&v102[v78] + 4) )
              break;
            v81 = BYTE4(v102[v78]);
            v82 = strsep(&stringp, " ");
            if ( v81 )
            {
              if ( !v82 )
                break;
              parse_ipv6(v82, &v102[v78 + 1]);
              v83 = strsep(&stringp, " ");
              if ( !v83 )
                break;
              parse_ipv6(v83, &v102[v78 + 3]);
            }
            else
            {
              if ( !v82 )
                break;
              v84 = convert_ip();
              if ( (unsigned __int64)(v78 * 8 + 8) > 0xF4 )
                goto LABEL_45;
              LODWORD(v102[v78 + 1]) = v84;
              if ( !strsep(&stringp, " ") )
                break;
              v85 = convert_ip();
              if ( (unsigned __int64)(v78 * 8 + 12) > 0xF4 )
                goto LABEL_45;
              HIDWORD(v102[v78 + 1]) = v85;
            }
            v86 = strsep(&stringp, " ");
            if ( !v86 || (unsigned int)kstrtou16(v86, 0, &v100) )
              break;
            if ( (unsigned __int64)(v78 * 8 - 203) < 0xFFFFFFFFFFFFFF0BLL )
              goto LABEL_45;
            WORD1(v102[v78 + 5]) = v100;
            v87 = strsep(&stringp, " ");
            if ( !v87 || (unsigned int)kstrtou16(v87, 0, v99) )
              break;
            if ( (unsigned __int64)(v78 * 8 - 201) < 0xFFFFFFFFFFFFFF0BLL
              || (v88 = &v102[v78],
                  WORD2(v102[v78 + 5]) = v99[0],
                  (unsigned __int64)(v78 * 8 - 205) < 0xFFFFFFFFFFFFFF0BLL) )
            {
LABEL_45:
              __break(1u);
LABEL_46:
              __break(0x5512u);
              return convert_ip();
            }
            v89 = LOBYTE(v102[0]);
            ++v79;
            v78 += 6;
            *((_BYTE *)v88 + 40) = 17;
            if ( v79 >= v89 )
              goto LABEL_44;
          }
        }
      }
      else
      {
        v68 = jiffies;
        if ( _hdd_sysfs_ipaoptdpctrl_store___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: opt_dp_ctrl, ipa debug is not supported",
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            "__hdd_sysfs_ipaoptdpctrl_store");
          _hdd_sysfs_ipaoptdpctrl_store___last_ticks = v68;
        }
      }
      a12 = -22;
LABEL_21:
      _osif_psoc_sync_op_stop(v98, (__int64)"hdd_sysfs_ipaoptdpctrl_store");
      goto LABEL_14;
    }
  }
  a12 = v23;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return a12;
}
