__int64 __fastcall ucfg_p2p_roc_req(
        __int64 a1,
        unsigned int *a2,
        _QWORD *a3,
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
  __int64 v16; // x5
  __int64 v17; // x6
  __int64 v18; // x7
  unsigned int v19; // w8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 comp_private_obj; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x22
  __int64 v38; // x0
  __int64 v39; // x23
  unsigned int v40; // w0
  unsigned int v41; // w19
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 result; // x0
  unsigned int v51; // w0
  int v52; // w8
  unsigned int v53; // w9
  unsigned int v54; // w9
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  unsigned int v63; // w20
  unsigned int v64; // w21
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  int v73; // [xsp+14h] [xbp-3Ch] BYREF
  __int64 v74; // [xsp+18h] [xbp-38h] BYREF
  __int64 v75; // [xsp+20h] [xbp-30h]
  __int64 (__fastcall *v76)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+28h] [xbp-28h]
  __int64 v77; // [xsp+30h] [xbp-20h]
  __int64 v78; // [xsp+38h] [xbp-18h]
  __int64 v79; // [xsp+40h] [xbp-10h]
  __int64 v80; // [xsp+48h] [xbp-8h]

  v80 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = *a2;
  v17 = a2[1];
  v18 = a2[2];
  v19 = a2[3];
  v78 = 0;
  v79 = 0;
  v76 = nullptr;
  v77 = 0;
  v74 = 0;
  v75 = 0;
  v73 = 0;
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: soc:%pK, vdev_id:%d, chanfreq:%d, phy_mode:%d, duration:%d",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "ucfg_p2p_roc_req",
    a1,
    v16,
    v17,
    v18,
    v19);
  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 5u);
    if ( comp_private_obj )
    {
      v37 = comp_private_obj;
      v38 = _qdf_mem_malloc(0xF8u, "ucfg_p2p_roc_req", 143);
      if ( v38 )
      {
        v39 = v38;
        v40 = qdf_idr_alloc(v37 + 224, v38, &v73);
        if ( v40 )
        {
          v41 = v40;
          _qdf_mem_free(v39);
          qdf_trace_msg(
            0x4Eu,
            2u,
            "%s: failed to alloc idr, status %d",
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            "ucfg_p2p_roc_req",
            v41);
          result = v41;
        }
        else
        {
          if ( a4 == 7 && (p2p_is_sta_vdev_usage_allowed_for_p2p_dev(a1) & 1) != 0 )
          {
            v51 = wlan_p2p_set_rand_mac_for_p2p_dev(a1, *a2, a2[1], v73, a2[3]);
            if ( v51 )
              goto LABEL_13;
          }
          v52 = v73;
          *a3 = v73;
          *(_QWORD *)(v39 + 16) = v37;
          v53 = *a2;
          LOWORD(v74) = 0;
          *(_DWORD *)(v39 + 24) = v53;
          *(_DWORD *)(v39 + 40) = a2[1];
          *(_BYTE *)(v39 + 44) = a2[2];
          v54 = a2[3];
          *(_DWORD *)(v39 + 224) = 0;
          *(_DWORD *)(v39 + 228) = v52;
          *(_DWORD *)(v39 + 240) = a4;
          *(_QWORD *)(v39 + 48) = v54;
          v75 = v39;
          v76 = p2p_process_cmd;
          v51 = scheduler_post_message_debug(
                  0x33u,
                  0x4Eu,
                  72,
                  (unsigned __int16 *)&v74,
                  0xB4u,
                  (__int64)"ucfg_p2p_roc_req");
          if ( v51 )
          {
LABEL_13:
            v63 = v51;
            _qdf_mem_free(v39);
            qdf_idr_remove(v37 + 224, v73);
            v64 = v63;
            qdf_trace_msg(
              0x4Eu,
              2u,
              "%s: post msg fail:%d",
              v65,
              v66,
              v67,
              v68,
              v69,
              v70,
              v71,
              v72,
              "ucfg_p2p_roc_req",
              v63);
          }
          else
          {
            v64 = 0;
          }
          qdf_trace_msg(
            0x4Eu,
            8u,
            "%s: cookie = 0x%llx",
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            "ucfg_p2p_roc_req",
            *a3);
          result = v64;
        }
      }
      else
      {
        result = 2;
      }
    }
    else
    {
      qdf_trace_msg(0x4Eu, 2u, "%s: P2P soc object is NULL", v29, v30, v31, v32, v33, v34, v35, v36, "ucfg_p2p_roc_req");
      result = 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: psoc context passed is NULL",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "ucfg_p2p_roc_req");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
