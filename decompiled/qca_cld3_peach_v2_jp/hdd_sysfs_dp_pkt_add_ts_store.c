__int64 __fastcall hdd_sysfs_dp_pkt_add_ts_store(
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
  _QWORD *context; // x21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int v33; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  int v42; // w20
  __int64 v43; // x21
  char *v44; // x0
  int v45; // w20
  char *v46; // x22
  char *v47; // x0
  char *v48; // x0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  int v57; // w8
  int v58; // w9
  int v59; // w8
  unsigned int v60; // w22
  char *v61; // x0
  unsigned int v62; // w0
  char *v63; // x0
  unsigned int v64; // w0
  const char *v65; // x2
  __int64 v66; // x4
  const char *v67; // x2
  __int64 v68; // [xsp+0h] [xbp-230h] BYREF
  _WORD v69[2]; // [xsp+8h] [xbp-228h] BYREF
  unsigned __int16 v70; // [xsp+Ch] [xbp-224h] BYREF
  char *v71; // [xsp+10h] [xbp-220h] BYREF
  char *stringp; // [xsp+18h] [xbp-218h] BYREF
  _BYTE s[513]; // [xsp+27h] [xbp-209h] BYREF
  __int64 v74; // [xsp+228h] [xbp-8h]

  v74 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v68 = 0;
  context = _cds_get_context(51, (__int64)"hdd_sysfs_dp_pkt_add_ts_store", a1, a2, a3, a4, a5, a6, a7, a8);
  v23 = _wlan_hdd_validate_context(
          (__int64)context,
          (__int64)"hdd_sysfs_dp_pkt_add_ts_store",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22);
  if ( v23
    || (v23 = _osif_psoc_sync_op_start(*(_QWORD *)(context[3] + 488LL), &v68, (__int64)"hdd_sysfs_dp_pkt_add_ts_store")) != 0 )
  {
    a12 = v23;
  }
  else
  {
    memset(s, 0, sizeof(s));
    if ( wlan_hdd_validate_modules_state((__int64)context, v25, v26, v27, v28, v29, v30, v31, v32) )
    {
      v33 = hdd_sysfs_validate_and_copy_buf(s, 513, a11, a12);
      if ( v33 )
      {
        v42 = v33;
        v43 = jiffies;
        if ( _hdd_sysfs_dp_pkt_add_ts_store___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: invalid input",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "__hdd_sysfs_dp_pkt_add_ts_store",
            v68);
          _hdd_sysfs_dp_pkt_add_ts_store___last_ticks = v43;
        }
        a12 = v42;
      }
      else
      {
        v44 = (char *)skip_spaces(s);
        v45 = (unsigned __int8)*v44;
        v46 = v44;
        qdf_clear_dp_pkt_add_ts_info(v44);
        if ( v45 )
        {
          v71 = nullptr;
          stringp = v46;
          v70 = 0;
          v69[0] = 0;
          while ( 1 )
          {
            v47 = strsep(&stringp, ",");
            if ( !v47 )
              break;
            v71 = v47;
            v48 = strsep(&v71, ":");
            if ( !v48 )
              goto LABEL_39;
            v57 = (unsigned __int8)*v48;
            v58 = v57 - 84;
            if ( v57 == 84 )
            {
              v58 = (unsigned __int8)v48[1] - 67;
              if ( v48[1] == 67 )
                v58 = (unsigned __int8)v48[2] - 80;
            }
            if ( v58 )
            {
              v59 = v57 - 85;
              if ( !v59 )
              {
                v59 = (unsigned __int8)v48[1] - 68;
                if ( v48[1] == 68 )
                  v59 = (unsigned __int8)v48[2] - 80;
              }
              if ( v59 )
              {
                v65 = "%s: protocol not supported";
LABEL_38:
                qdf_trace_msg(0x33u, 2u, v65, v49, v50, v51, v52, v53, v54, v55, v56, "hdd_set_dp_pkt_add_ts_info", v68);
LABEL_39:
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: all protocol do not set successfully",
                  v49,
                  v50,
                  v51,
                  v52,
                  v53,
                  v54,
                  v55,
                  v56,
                  "__hdd_sysfs_dp_pkt_add_ts_store",
                  v68);
                break;
              }
              v60 = 2;
            }
            else
            {
              v60 = 1;
            }
            v61 = strsep(&v71, ":");
            if ( !v61 )
              goto LABEL_39;
            v62 = kstrtou16(v61, 0, &v70);
            if ( v62 )
            {
              v66 = v62;
              v67 = "%s: Invalid port value ret %d";
              goto LABEL_36;
            }
            if ( !v70 )
            {
              v65 = "%s: port not valid";
              goto LABEL_38;
            }
            v63 = strsep(&v71, ":");
            if ( !v63 )
              goto LABEL_39;
            v64 = kstrtou16(v63, 0, v69);
            if ( v64 )
            {
              v66 = v64;
              v67 = "%s: Invalid offset value ret %d";
LABEL_36:
              qdf_trace_msg(
                0x33u,
                2u,
                v67,
                v49,
                v50,
                v51,
                v52,
                v53,
                v54,
                v55,
                v56,
                "hdd_set_dp_pkt_add_ts_info",
                v66,
                v68);
              goto LABEL_39;
            }
            if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))qdf_set_dp_pkt_add_ts_info)(
                                 v60,
                                 v70,
                                 v69[0]) )
            {
              v65 = "%s: pkt info set failed";
              goto LABEL_38;
            }
          }
        }
      }
    }
    else
    {
      a12 = -22;
    }
    _osif_psoc_sync_op_stop(v68, (__int64)"hdd_sysfs_dp_pkt_add_ts_store");
  }
  _ReadStatusReg(SP_EL0);
  return a12;
}
