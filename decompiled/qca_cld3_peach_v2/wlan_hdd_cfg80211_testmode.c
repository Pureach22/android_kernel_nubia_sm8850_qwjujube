__int64 __fastcall wlan_hdd_cfg80211_testmode(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  char v4; // b13
  __int64 v8; // x0
  __int64 result; // x0
  __int64 v10; // x2
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  int v19; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  const char *v28; // x2
  int v29; // w0
  const char *v30; // x2
  int v31; // w19
  unsigned int v32; // w1
  unsigned int v33; // w19
  __int64 v34; // x0
  int v35; // w4
  _WORD *v36; // x20
  __int64 conparam; // x0
  unsigned int v38; // w0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  void *v47; // x0
  void *v48; // x21
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // [xsp+8h] [xbp-38h] BYREF
  __int64 v58; // [xsp+10h] [xbp-30h] BYREF
  __int64 v59; // [xsp+18h] [xbp-28h]
  unsigned __int16 *v60; // [xsp+20h] [xbp-20h]
  __int64 v61; // [xsp+28h] [xbp-18h]
  __int64 v62; // [xsp+30h] [xbp-10h]
  __int64 v63; // [xsp+38h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 488);
  v57 = 0;
  result = _osif_psoc_sync_op_start(v8, &v57, "wlan_hdd_cfg80211_testmode");
  if ( (_DWORD)result )
    goto LABEL_11;
  v61 = 0;
  v62 = 0;
  v59 = 0;
  v60 = nullptr;
  v58 = 0;
  if ( a1 )
  {
    qdf_trace_msg(0x33u, 8u, "%s: enter", v11, v12, v13, v14, v15, v16, v17, v18, "__wlan_hdd_cfg80211_testmode");
    v19 = _wlan_hdd_validate_context(a1 + 1536, "__wlan_hdd_cfg80211_testmode");
    if ( v19 )
    {
LABEL_10:
      v33 = v19;
      _osif_psoc_sync_op_stop(v57, "wlan_hdd_cfg80211_testmode");
      result = v33;
LABEL_11:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    if ( *(_DWORD *)(a1 + 3000) == 2 )
    {
      v28 = "%s: Driver Modules are closed";
LABEL_6:
      qdf_trace_msg(0x33u, 2u, v28, v20, v21, v22, v23, v24, v25, v26, v27, "__wlan_hdd_cfg80211_testmode");
      v19 = -22;
      goto LABEL_10;
    }
    v29 = _nla_parse(&v58, 4, a3, a4, &wlan_hdd_tm_policy, 31, 0);
    if ( v29 )
    {
      v30 = "%s: Testmode INV ATTR";
      v31 = v29;
      v32 = 2;
    }
    else
    {
      if ( !v59 )
      {
        v28 = "%s: Testmode INV CMD";
        goto LABEL_6;
      }
      v34 = qdf_mtrace(51, 51, 0x44u, 0xFFu, *(_DWORD *)(v59 + 4));
      v35 = *(_DWORD *)(v59 + 4);
      if ( v35 )
      {
        if ( v35 != 1 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: command: %d not supported",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            "__wlan_hdd_cfg80211_testmode");
          v19 = -95;
          goto LABEL_10;
        }
        if ( v60 )
        {
          v36 = v60 + 2;
          if ( (unsigned int)*v60 - 4 > 0x47 )
          {
            if ( *v36 == 1 && !v60[15] )
            {
              v19 = -22;
            }
            else if ( (unsigned __int16)(*v60 - 4) == 72 )
            {
              v47 = (void *)_qdf_mem_malloc(0x48u, "__wlan_hdd_cfg80211_testmode", 32098);
              if ( v47 )
              {
                v48 = v47;
                qdf_mem_set(v47, 0x48u, 0);
                qdf_mem_copy(v48, v36, 0x48u);
                if ( (unsigned int)ucfg_pmo_lphb_config_req(
                                     *(_QWORD *)(a1 + 1536),
                                     v48,
                                     a1 + 1536,
                                     wlan_hdd_cfg80211_lphb_ind_handler) )
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: LPHB Config Fail, disable",
                    v49,
                    v50,
                    v51,
                    v52,
                    v53,
                    v54,
                    v55,
                    v56,
                    "__wlan_hdd_cfg80211_testmode");
                _qdf_mem_free((__int64)v48);
                v19 = 0;
              }
              else
              {
                v19 = -12;
              }
            }
            else
            {
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: buf_len=%d exceeded hb_params size limit",
                v20,
                v21,
                v22,
                v23,
                v24,
                v25,
                v26,
                v27,
                "__wlan_hdd_cfg80211_testmode",
                (unsigned __int16)(*v60 - 4));
              v19 = -34;
            }
            goto LABEL_10;
          }
          v28 = "%s: Invalid buffer length for TM_ATTR_DATA";
        }
        else
        {
          v28 = "%s: Testmode INV DATA";
        }
        goto LABEL_6;
      }
      conparam = hdd_get_conparam(v34);
      if ( (_DWORD)conparam != 5 )
      {
        v38 = hdd_get_conparam(conparam);
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: FTM Command not allowed in mission mode, mode %d",
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          "__wlan_hdd_cfg80211_testmode",
          v38);
        v19 = -22;
        goto LABEL_10;
      }
      v31 = wlan_cfg80211_ftm_testmode_cmd(*(_QWORD *)(a1 + 1544), a3, a4);
      v30 = "%s: exit";
      v32 = 8;
    }
    qdf_trace_msg(0x33u, v32, v30, v20, v21, v22, v23, v24, v25, v26, v27, "__wlan_hdd_cfg80211_testmode");
    v19 = v31;
    goto LABEL_10;
  }
  __break(0x800u);
  *(_BYTE *)(v10 + 199) = v4;
  return wlan_hdd_cfg80211_set_bitrate_mask();
}
