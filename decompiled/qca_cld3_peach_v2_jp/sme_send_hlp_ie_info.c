__int64 __fastcall sme_send_hlp_ie_info(
        _QWORD *a1,
        unsigned int a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w21
  __int64 result; // x0
  __int64 v16; // x19
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x22
  __int64 ext_hdl; // x0
  unsigned int *v28; // x8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  const char *v37; // x2
  unsigned int v38; // w1
  int v39; // w11
  unsigned int *v40; // x8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int64 v65; // [xsp+8h] [xbp-38h] BYREF
  __int64 v66; // [xsp+10h] [xbp-30h]
  __int64 v67; // [xsp+18h] [xbp-28h]
  __int64 v68; // [xsp+20h] [xbp-20h]
  __int64 v69; // [xsp+28h] [xbp-18h]
  __int64 v70; // [xsp+30h] [xbp-10h]
  __int64 v71; // [xsp+38h] [xbp-8h]

  v11 = (unsigned __int8)a2;
  v71 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  v65 = 0;
  v66 = 0;
  if ( (unsigned __int8)a2 > 5u || !(a1[2153] + 96LL * (unsigned __int8)a2) )
  {
    v37 = "%s: session NULL";
    v38 = 2;
LABEL_15:
    result = qdf_trace_msg(0x34u, v38, v37, a4, a5, a6, a7, a8, a9, a10, a11, "sme_send_hlp_ie_info");
    goto LABEL_16;
  }
  if ( (*(_BYTE *)(a1[1] + 1563LL) & 1) == 0 )
  {
    v37 = "%s: Fast roam is disabled";
LABEL_14:
    v38 = 8;
    goto LABEL_15;
  }
  if ( (csr_is_conn_state_connected() & 1) == 0 )
  {
    v37 = "%s: vdev not connected";
    goto LABEL_14;
  }
  result = _qdf_mem_malloc(0x808u, "sme_send_hlp_ie_info", 6722);
  if ( result )
  {
    v16 = result;
    v17 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1[2694], a2, 2);
    if ( v17 )
    {
      v26 = v17;
      ext_hdl = wlan_vdev_mlme_get_ext_hdl(v17, v18, v19, v20, v21, v22, v23, v24, v25);
      if ( ext_hdl )
      {
        if ( (unsigned int)(*(_DWORD *)(ext_hdl + 24072) - 2045) > 0xFFFFF7FE )
        {
          *(_BYTE *)v16 = a2;
          v39 = *(_DWORD *)(ext_hdl + 24072);
          *(_WORD *)(v16 + 8) = a3;
          *(_BYTE *)(v16 + 10) = BYTE2(a3);
          *(_DWORD *)(v16 + 4) = v39 + 4;
          *(_BYTE *)(v16 + 11) = HIBYTE(a3);
          qdf_mem_copy((void *)(v16 + 12), *(const void **)(ext_hdl + 24064), *(unsigned int *)(ext_hdl + 24072));
          wlan_objmgr_vdev_release_ref(v26, 2u, v40, v41, v42, v43, v44, v45, v46, v47, v48);
          v66 = v16;
          LODWORD(v65) = 4520;
          if ( (unsigned int)qdf_mutex_acquire((__int64)(a1 + 1597)) )
          {
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: sme lock acquire fails",
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              v55,
              v56,
              "sme_send_hlp_ie_info");
          }
          else
          {
            if ( !(unsigned int)scheduler_post_message_debug(
                                  0x34u,
                                  0x36u,
                                  54,
                                  (unsigned __int16 *)&v65,
                                  0x1A75u,
                                  (__int64)"sme_send_hlp_ie_info") )
            {
              result = qdf_mutex_release((__int64)(a1 + 1597));
              goto LABEL_16;
            }
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: Not able to post WMA_HLP_IE_INFO message to HAL",
              v57,
              v58,
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              "sme_send_hlp_ie_info");
            qdf_mutex_release((__int64)(a1 + 1597));
          }
          goto LABEL_22;
        }
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: HLP IE len exceeds %d",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "sme_send_hlp_ie_info");
      }
      wlan_objmgr_vdev_release_ref(v26, 2u, v28, v29, v30, v31, v32, v33, v34, v35, v36);
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev object is NULL for vdev_id %d",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "sme_send_hlp_ie_info",
        v11);
    }
LABEL_22:
    result = _qdf_mem_free(v16);
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
