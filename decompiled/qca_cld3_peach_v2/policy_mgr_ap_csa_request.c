__int64 __fastcall policy_mgr_ap_csa_request(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        int a4,
        unsigned int a5,
        int a6,
        char a7,
        char a8)
{
  __int64 context; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x28
  __int64 v26; // x19
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 result; // x0
  const char *v36; // x2
  char v37; // w27
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // [xsp+8h] [xbp-28h]
  __int64 v55; // [xsp+8h] [xbp-28h]
  unsigned __int64 v56; // [xsp+10h] [xbp-20h] BYREF
  __int64 v57; // [xsp+18h] [xbp-18h]
  __int64 v58; // [xsp+20h] [xbp-10h]
  __int64 v59; // [xsp+28h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v57 = 0;
  v58 = 0;
  v56 = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v36 = "%s: Invalid context";
LABEL_8:
    qdf_trace_msg(0x4Fu, 2u, v36, v17, v18, v19, v20, v21, v22, v23, v24, "policy_mgr_ap_csa_request");
    result = 4;
    goto LABEL_10;
  }
  v25 = *(_QWORD *)(context + 2096);
  v26 = context;
  if ( !v25 )
  {
    v36 = "%s: Invalid work_info context";
    goto LABEL_8;
  }
  if ( (wlan_mlme_is_aux_emlsr_support(a1) & 1) != 0 )
  {
    qdf_mutex_acquire(v26 + 56);
    if ( *(_DWORD *)(v25 + 8) )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: has pending csa vdev %d reason %d %d to %d forced %d",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "policy_mgr_ap_csa_request",
        *(unsigned __int8 *)(v25 + 12),
        *(unsigned int *)(v25 + 16),
        *(unsigned int *)(v25 + 20),
        *(unsigned __int8 *)(v25 + 28),
        v54,
        v56,
        v57,
        v58,
        v59);
      qdf_mutex_release(v26 + 56);
      result = 8;
    }
    else
    {
      v55 = *(_QWORD *)(v26 + 2088);
      v37 = (v55 == qdf_get_current_task()) | a8;
      qdf_mutex_release(v26 + 56);
      qdf_mem_set(&v56, 0x18u, 0);
      v56 = __PAIR64__(a5, a3);
      LOBYTE(v57) = v37 & 1;
      result = ml_nlink_conn_change_notify(a1, a2, 14, &v56);
      if ( (_DWORD)result == 24 && (v37 & 1) == 0 )
      {
        qdf_mutex_acquire(v26 + 56);
        *(_BYTE *)(v25 + 12) = a2;
        *(_DWORD *)(v25 + 16) = a4;
        *(_DWORD *)(v25 + 20) = a3;
        *(_DWORD *)(v25 + 8) = a5;
        *(_DWORD *)(v25 + 24) = a6;
        *(_BYTE *)(v25 + 28) = a7 & 1;
        qdf_mutex_release(v26 + 56);
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: defer csa for vdev %d reason %d %d to %d forced %d",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "policy_mgr_ap_csa_request",
          *(unsigned __int8 *)(v25 + 12),
          *(unsigned int *)(v25 + 16),
          *(unsigned int *)(v25 + 20),
          *(unsigned int *)(v25 + 8),
          *(unsigned __int8 *)(v25 + 28));
        if ( (_qdf_delayed_work_start(v26 + 1008, 0) & 1) == 0 )
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: sta_ap check_work already queued",
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            "policy_mgr_ap_csa_request");
        result = 24;
      }
    }
  }
  else
  {
    result = 0;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
