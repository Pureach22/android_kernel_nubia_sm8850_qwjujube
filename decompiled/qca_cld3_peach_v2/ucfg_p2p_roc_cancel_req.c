__int64 __fastcall ucfg_p2p_roc_cancel_req(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 comp_private_obj; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x22
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 result; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  _QWORD *v51; // x0
  __int64 v52; // x19
  unsigned int v53; // w20
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // [xsp+0h] [xbp-40h] BYREF
  __int64 v63; // [xsp+8h] [xbp-38h] BYREF
  _QWORD *v64; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v65)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 v66; // [xsp+20h] [xbp-20h]
  __int64 v67; // [xsp+28h] [xbp-18h]
  __int64 v68; // [xsp+30h] [xbp-10h]
  __int64 v69; // [xsp+38h] [xbp-8h]

  v69 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v67 = 0;
  v68 = 0;
  v65 = nullptr;
  v66 = 0;
  v63 = 0;
  v64 = nullptr;
  v62 = 0;
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: soc:%pK, cookie:0x%llx",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "ucfg_p2p_roc_cancel_req",
    a1,
    a3);
  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 5u);
    if ( comp_private_obj )
    {
      v33 = comp_private_obj;
      if ( (unsigned int)qdf_idr_find(comp_private_obj + 224, a3, &v62) )
      {
        qdf_trace_msg(
          0x4Eu,
          8u,
          "%s: invalid id for cookie 0x%llx",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "ucfg_p2p_roc_cancel_req",
          a3);
        result = 4;
      }
      else
      {
        if ( a4 == 7
          && (p2p_is_sta_vdev_usage_allowed_for_p2p_dev(a1) & 1) != 0
          && !(unsigned int)policy_mgr_mode_specific_get_channel(a1, 3) )
        {
          p2p_del_random_mac(a1, *(unsigned __int8 *)(a2 + 168), a3, v43, v44, v45, v46, v47, v48, v49, v50);
        }
        v51 = (_QWORD *)_qdf_mem_malloc(0x10u, "ucfg_p2p_roc_cancel_req", 231);
        if ( v51 )
        {
          *v51 = v33;
          v52 = (__int64)v51;
          LOWORD(v63) = 1;
          v51[1] = v62;
          v64 = v51;
          v65 = p2p_process_cmd;
          result = scheduler_post_message_debug(
                     0x33u,
                     0x4Eu,
                     72,
                     (unsigned __int16 *)&v63,
                     0xF4u,
                     (__int64)"ucfg_p2p_roc_cancel_req");
          if ( (_DWORD)result )
          {
            v53 = result;
            _qdf_mem_free(v52);
            qdf_trace_msg(
              0x4Eu,
              2u,
              "%s: post msg fail:%d",
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              v61,
              "ucfg_p2p_roc_cancel_req",
              v53);
            result = v53;
          }
        }
        else
        {
          result = 2;
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x4Eu,
        2u,
        "%s: p2p soc context is NULL",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "ucfg_p2p_roc_cancel_req");
      result = 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: psoc context passed is NULL",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "ucfg_p2p_roc_cancel_req");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
