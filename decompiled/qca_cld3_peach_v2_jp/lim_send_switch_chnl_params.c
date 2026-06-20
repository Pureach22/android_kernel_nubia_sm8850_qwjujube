__int64 __fastcall lim_send_switch_chnl_params(
        __int64 a1,
        __int64 a2,
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
  __int64 v23; // x21
  unsigned int started; // w24
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int v33; // w8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  char is_chan_switch_in_progress; // w0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  char v59; // w8
  __int64 result; // x0
  const char *v61; // x2
  __int64 v62; // [xsp+8h] [xbp-68h] BYREF
  __int64 v63; // [xsp+10h] [xbp-60h]
  __int64 v64; // [xsp+18h] [xbp-58h]
  __int64 v65; // [xsp+20h] [xbp-50h]
  __int64 v66; // [xsp+28h] [xbp-48h]
  int v67; // [xsp+30h] [xbp-40h]
  _QWORD v68[7]; // [xsp+38h] [xbp-38h] BYREF

  v68[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v67 = 0;
  v65 = 0;
  v66 = 0;
  v63 = 0;
  v64 = 0;
  v62 = 0;
  context = _cds_get_context(54, (__int64)"lim_send_switch_chnl_params", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
    goto LABEL_19;
  if ( !a2 )
  {
    v61 = "%s: session is NULL";
LABEL_18:
    qdf_trace_msg(0x35u, 2u, v61, v13, v14, v15, v16, v17, v18, v19, v20, "lim_send_switch_chnl_params");
LABEL_19:
    result = 16;
    goto LABEL_20;
  }
  if ( !*(_QWORD *)(a2 + 16) )
  {
    v61 = "%s: vdev is NULL";
    goto LABEL_18;
  }
  v21 = context;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a2 + 16), v13, v14, v15, v16, v17, v18, v19, v20);
  if ( !cmpt_obj )
  {
    v61 = "%s: vdev component object is NULL";
    goto LABEL_18;
  }
  v23 = cmpt_obj;
  *(_BYTE *)(a2 + 9794) = 1;
  lim_post_csa_ocv_sa_query_check(a1, a2, 0);
  started = lim_pre_vdev_start(a1, v23, a2);
  if ( !started )
  {
    *(_BYTE *)(a1 + 8885) = 0;
    *(_QWORD *)(a1 + 8888) = "lim_send_switch_chnl_params";
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Defer LIM msg %d",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "lim_send_switch_chnl_params",
      0);
    v33 = *(unsigned __int8 *)(a1 + 8885);
    memset(v68, 0, 48);
    if ( v33 )
    {
      if ( *(_WORD *)(a1 + 8688) )
      {
        LOWORD(v68[0]) = 5119;
        if ( (unsigned int)lim_post_msg_api(a1, (unsigned __int16 *)v68) )
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Failed to post lim msg:0x%x",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "lim_post_msg_to_process_deferred_queue",
            LOWORD(v68[0]));
      }
    }
    started = wma_pre_chan_switch_setup(*(unsigned __int8 *)(a2 + 10));
    if ( !started )
    {
      is_chan_switch_in_progress = mlme_is_chan_switch_in_progress(
                                     *(_QWORD *)(a2 + 16),
                                     v42,
                                     v43,
                                     v44,
                                     v45,
                                     v46,
                                     v47,
                                     v48,
                                     v49);
      started = vdev_mgr_start_send(v23, is_chan_switch_in_progress & 1, v51, v52, v53, v54, v55, v56, v57, v58);
      if ( !started )
      {
        wma_post_chan_switch_setup(*(unsigned __int8 *)(a2 + 10));
        goto LABEL_14;
      }
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: failed status = %d",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "lim_send_switch_chnl_params",
      started);
  }
  v59 = *(_BYTE *)(a2 + 10);
  LODWORD(v63) = started;
  LOBYTE(v62) = v59;
  wma_handle_channel_switch_resp(v21, &v62);
LABEL_14:
  result = 0;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
