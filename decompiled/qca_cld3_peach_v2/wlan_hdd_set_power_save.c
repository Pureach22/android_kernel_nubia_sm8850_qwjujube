__int64 __fastcall wlan_hdd_set_power_save(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 *v12; // x21
  __int64 v13; // x22
  unsigned int v14; // w23
  int v15; // w8
  const char *v16; // x2
  unsigned int v17; // w1
  __int64 result; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w22
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x8
  _BYTE v37[4]; // [xsp+30h] [xbp-10h] BYREF
  _BYTE v38[4]; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v39; // [xsp+38h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    v12 = *(__int64 **)(a1 + 24);
    v13 = *v12;
    if ( !*v12 )
    {
      v16 = "%s: psoc is null";
      v17 = 2;
      goto LABEL_12;
    }
    if ( (*(_DWORD *)(a1 + 40) & 0xFFFFFFFE) != 2 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: unable to process device mode %d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "wlan_hdd_set_power_save");
      result = 4294967274LL;
      goto LABEL_19;
    }
    v14 = *a2;
    if ( wlan_vdev_p2p_is_wfd_r2_mode(*v12, *a2, a3, a4, a5, a6, a7, a8, a9, a10) )
    {
      v15 = *(_DWORD *)(a1 + 40);
      if ( v15 == 2 )
      {
        v37[0] = 0;
        hdd_get_twt_requestor(v13, v37);
        if ( v37[0] == 1 )
        {
LABEL_9:
          v16 = "%s: WFD R2 mode, reject NOA cmd";
          v17 = 8;
LABEL_12:
          qdf_trace_msg(0x33u, v17, v16, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_hdd_set_power_save");
          result = 4294967274LL;
          goto LABEL_19;
        }
      }
      else
      {
        if ( v15 != 3 )
          goto LABEL_9;
        v38[0] = 0;
        ucfg_twt_cfg_get_responder(v13, v38);
        if ( (ucfg_twt_resp_check_bit(v13, v14, 3, v38[0]) & 1) != 0 )
          goto LABEL_9;
      }
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: opp ps:%d, ct window:%d, duration:%d, interval:%d, count:%d start:%d, single noa duration:%d, ps selection:%d, vdev id:%d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_hdd_set_power_save",
      a2[1],
      a2[2],
      a2[4],
      a2[5],
      a2[3],
      a2[8],
      a2[6],
      a2[7],
      *a2);
    v27 = ucfg_p2p_set_ps(v13, a2, v19, v20, v21, v22, v23, v24, v25, v26);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: p2p set power save, status:%d",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "wlan_hdd_set_power_save",
      v27);
    v36 = *(_QWORD *)(a1 + 52832);
    if ( a2[4] )
    {
      hdd_send_twt_role_disable_cmd(v12, 3, *(unsigned __int8 *)(v36 + 8));
    }
    else
    {
      hdd_send_twt_requestor_enable_cmd(v12, *(unsigned __int8 *)(v36 + 8));
      hdd_send_twt_responder_enable_cmd(v12, *(unsigned __int8 *)(*(_QWORD *)(a1 + 52832) + 8LL));
    }
    result = qdf_status_to_os_return(v27);
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: null param, adapter:%pK, ps_config:%pK",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_hdd_set_power_save",
      a1,
      a2);
    result = 4294967274LL;
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
