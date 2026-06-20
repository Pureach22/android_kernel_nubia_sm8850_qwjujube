__int64 __fastcall ucfg_nan_send_delete_pasn_peer(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w8
  __int16 v23; // w9
  void *v24; // x0
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x19
  __int64 comp_private_obj; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int v44; // w0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned int v53; // w20
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  const char *v62; // x2
  __int64 result; // x0
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  unsigned int v80; // w0
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  __int64 v89; // x20
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  unsigned int *v98; // x8
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  __int64 v107; // [xsp+8h] [xbp-48h] BYREF
  void *v108; // [xsp+10h] [xbp-40h]
  __int64 (__fastcall *v109)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-38h]
  __int64 (__fastcall *v110)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+20h] [xbp-30h]
  __int64 v111; // [xsp+28h] [xbp-28h]
  __int64 v112; // [xsp+30h] [xbp-20h]
  __int64 v113; // [xsp+38h] [xbp-18h] BYREF
  __int64 v114; // [xsp+40h] [xbp-10h]
  __int64 v115; // [xsp+48h] [xbp-8h]

  v115 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v111 = 0;
  v112 = 0;
  v109 = nullptr;
  v110 = nullptr;
  v107 = 0;
  v108 = nullptr;
  v114 = 0;
  if ( (nan_is_pairing_allowed(a1, a4, a5, a6, a7, a8, a9, a10, a11) & 1) == 0 )
  {
    v62 = "%s:  NAN pairing is not allowed";
LABEL_11:
    qdf_trace_msg(0x53u, 8u, v62, v14, v15, v16, v17, v18, v19, v20, v21, "ucfg_nan_send_delete_pasn_peer");
    result = 0;
    goto LABEL_12;
  }
  if ( ((unsigned __int8)nan_is_peer_exist_for_opmode(a1, a3, 16) & 1) == 0 )
  {
    v62 = "%s:  NAN peer does not exist";
    goto LABEL_11;
  }
  v22 = *(_DWORD *)a3;
  v23 = *(_WORD *)(a3 + 4);
  v113 = a1;
  LODWORD(v114) = v22;
  WORD2(v114) = v23;
  BYTE6(v114) = a2;
  v24 = (void *)_qdf_mem_malloc(0x10u, "ucfg_nan_send_delete_pasn_peer", 1698);
  v108 = v24;
  if ( v24 )
  {
    qdf_mem_copy(v24, &v113, 0x10u);
    LOWORD(v107) = 1;
    v109 = nan_pasn_scheduled_handler;
    v110 = nan_pasn_flush_callback;
    v25 = osif_request_alloc(ucfg_nan_send_delete_pasn_peer_req_params);
    if ( v25 )
    {
      v34 = v25;
      if ( a1 )
      {
        comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
        if ( comp_private_obj )
        {
          *(_QWORD *)(comp_private_obj + 312) = osif_request_cookie(v34);
          v44 = scheduler_post_message_debug(
                  0x53u,
                  0x53u,
                  72,
                  (unsigned __int16 *)&v107,
                  0x6BFu,
                  (__int64)"ucfg_nan_send_delete_pasn_peer");
          if ( v44 )
          {
            v53 = v44;
            qdf_trace_msg(
              0x53u,
              2u,
              "%s: failed to post msg to NAN component, status: %d",
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              "ucfg_nan_send_delete_pasn_peer");
            nan_pasn_flush_callback((unsigned __int16 *)&v107, v54, v55, v56, v57, v58, v59, v60, v61);
          }
          else
          {
            v80 = osif_request_wait_for_response(v34);
            if ( v80 )
            {
              v53 = v80;
              qdf_trace_msg(
                0x53u,
                2u,
                "%s: NAN PASN peer delete request fails",
                v81,
                v82,
                v83,
                v84,
                v85,
                v86,
                v87,
                v88,
                "ucfg_nan_send_delete_pasn_peer");
            }
            else
            {
              v89 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 20);
              qdf_trace_msg(
                0x53u,
                8u,
                "%s: peer deleted successfully",
                v90,
                v91,
                v92,
                v93,
                v94,
                v95,
                v96,
                v97,
                "ucfg_nan_send_delete_pasn_peer");
              wlan_objmgr_vdev_release_ref(v89, 0x14u, v98, v99, v100, v101, v102, v103, v104, v105, v106);
              v53 = 0;
            }
          }
          goto LABEL_17;
        }
      }
      else
      {
        qdf_trace_msg(0x53u, 2u, "%s: psoc is null", v26, v27, v28, v29, v30, v31, v32, v33, "nan_get_psoc_priv_obj");
      }
      qdf_trace_msg(
        0x53u,
        2u,
        "%s: psoc_nan_obj is null",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "ucfg_nan_send_delete_pasn_peer");
      nan_pasn_flush_callback((unsigned __int16 *)&v107, v72, v73, v74, v75, v76, v77, v78, v79);
      v53 = 29;
LABEL_17:
      osif_request_put(v34);
      result = v53;
      goto LABEL_12;
    }
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: Request allocation failure",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "ucfg_nan_send_delete_pasn_peer");
    nan_pasn_flush_callback((unsigned __int16 *)&v107, v64, v65, v66, v67, v68, v69, v70, v71);
    result = 2;
  }
  else
  {
    result = 2;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
