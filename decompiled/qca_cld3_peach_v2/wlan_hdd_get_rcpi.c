__int64 __fastcall wlan_hdd_get_rcpi(
        __int64 a1,
        const void *a2,
        _DWORD *a3,
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
  const char *v24; // x2
  const char *v25; // x3
  unsigned int v26; // w1
  __int64 v27; // x24
  int v28; // w8
  __int64 result; // x0
  _DWORD *v30; // x22
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x0
  __int64 v40; // x22
  __int64 v41; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x23
  __int64 v51; // x0
  __int16 v52; // w9
  unsigned int rcpi; // w0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned int v62; // w21
  unsigned int v63; // w19
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  const char *v72; // x2
  __int64 v73; // x0
  int v74; // w10
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  int v83; // [xsp+0h] [xbp-10h] BYREF
  __int16 v84; // [xsp+4h] [xbp-Ch]
  __int64 v85; // [xsp+8h] [xbp-8h]

  v85 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v84 = 0;
  v83 = 0;
  qdf_trace_msg(0x33u, 8u, "%s: enter", a5, a6, a7, a8, a9, a10, a11, a12, "wlan_hdd_get_rcpi");
  *a3 = 0;
  if ( (unsigned int)hdd_get_conparam() == 5 )
  {
    v24 = "%s: Command not allowed in FTM mode";
    v25 = "wlan_hdd_get_rcpi";
LABEL_3:
    v26 = 2;
LABEL_15:
    qdf_trace_msg(0x33u, v26, v24, v16, v17, v18, v19, v20, v21, v22, v23, v25);
    goto LABEL_16;
  }
  if ( !a1 )
  {
    v24 = "%s: adapter context is NULL";
LABEL_13:
    v25 = "wlan_hdd_get_rcpi";
    v26 = 3;
    goto LABEL_15;
  }
  v27 = *(_QWORD *)(a1 + 24);
  if ( (unsigned int)_wlan_hdd_validate_context(
                       v27,
                       (__int64)"wlan_hdd_get_rcpi",
                       v16,
                       v17,
                       v18,
                       v19,
                       v20,
                       v21,
                       v22,
                       v23) )
    goto LABEL_16;
  if ( (*(_BYTE *)(v27 + 1819) & 1) == 0 )
  {
    v24 = "%s: RCPI not supported";
    v25 = "wlan_hdd_get_rcpi";
    v26 = 8;
    goto LABEL_15;
  }
  if ( !a2 )
  {
    v24 = "%s: RCPI peer mac-addr is NULL";
    goto LABEL_13;
  }
  qdf_mem_copy(&v83, a2, 6u);
  v28 = *(_DWORD *)(a1 + 40);
  if ( v28 > 1 )
  {
    if ( v28 == 3 )
    {
LABEL_25:
      if ( (*(_QWORD *)(*(_QWORD *)(a1 + 52832) + 5968LL) & 2) == 0 )
      {
        v24 = "%s: Invalid rcpi request, softap not started";
LABEL_32:
        v25 = "hdd_is_rcpi_applicable";
        goto LABEL_3;
      }
      if ( (hdd_is_peer_associated(a1, &v83, v16, v17, v18, v19, v20, v21, v22, v23) & 1) == 0 )
      {
        v24 = "%s: invalid peer mac-addr: not associated";
        goto LABEL_32;
      }
LABEL_33:
      v39 = _qdf_mem_malloc(0x20u, "wlan_hdd_get_rcpi", 9643);
      if ( !v39 )
        goto LABEL_16;
      v40 = v39;
      v41 = osif_request_alloc(wlan_hdd_get_rcpi_params);
      if ( !v41 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Request allocation failure",
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          "wlan_hdd_get_rcpi");
        _qdf_mem_free(v40);
        result = 4294967284LL;
        goto LABEL_17;
      }
      v50 = v41;
      v51 = osif_request_cookie(v41);
      v52 = v84;
      *(_DWORD *)(v40 + 24) = v83;
      *(_WORD *)(v40 + 28) = v52;
      *(_DWORD *)v40 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 52832) + 8LL);
      *(_DWORD *)(v40 + 4) = a4;
      *(_QWORD *)(v40 + 8) = wlan_hdd_get_rcpi_cb;
      *(_QWORD *)(v40 + 16) = v51;
      rcpi = sme_get_rcpi(*(_QWORD *)(v27 + 16), v40);
      if ( rcpi )
      {
        v62 = rcpi;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Unable to retrieve RCPI",
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          "wlan_hdd_get_rcpi");
        v63 = qdf_status_to_os_return(v62);
      }
      else
      {
        if ( (unsigned int)osif_request_wait_for_response(v50) )
        {
          v72 = "%s: SME timed out while retrieving RCPI";
        }
        else
        {
          v73 = osif_request_priv(v50);
          v74 = *(_DWORD *)(v73 + 4);
          *(_WORD *)(a1 + 52204) = *(_WORD *)(v73 + 8);
          *(_DWORD *)(a1 + 52200) = v74;
          *(_DWORD *)(a1 + 52196) = *(_DWORD *)v73;
          if ( !(unsigned int)qdf_mem_cmp(&v83, (const void *)(v73 + 4), 6u) )
          {
            *a3 = *(_DWORD *)(a1 + 52196);
            qdf_trace_msg(0x33u, 8u, "%s: RCPI = %d", v64, v65, v66, v67, v68, v69, v70, v71, "wlan_hdd_get_rcpi");
            v63 = 0;
            goto LABEL_43;
          }
          v72 = "%s: mis match of mac addr from call-back";
        }
        qdf_trace_msg(0x33u, 2u, v72, v64, v65, v66, v67, v68, v69, v70, v71, "wlan_hdd_get_rcpi");
        v63 = -22;
      }
LABEL_43:
      _qdf_mem_free(v40);
      osif_request_put(v50);
      qdf_trace_msg(0x33u, 8u, "%s: exit", v75, v76, v77, v78, v79, v80, v81, v82, "wlan_hdd_get_rcpi");
      result = v63;
      goto LABEL_17;
    }
    if ( v28 != 2 )
    {
LABEL_27:
      v24 = "%s: Invalid rcpi request";
      goto LABEL_32;
    }
  }
  else if ( v28 )
  {
    if ( v28 != 1 )
      goto LABEL_27;
    goto LABEL_25;
  }
  v30 = *(_DWORD **)(a1 + 52832);
  if ( !hdd_cm_is_vdev_associated(v30) )
    goto LABEL_16;
  if ( !hdd_cm_is_vdev_roaming(*(_QWORD *)(a1 + 52832)) )
  {
    if ( (unsigned int)qdf_mem_cmp(&v83, v30 + 77, 6u) )
    {
      v24 = "%s: mac addr is different from bssid connected";
      goto LABEL_32;
    }
    goto LABEL_33;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Roaming in progress, return cached RCPI",
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    "hdd_is_rcpi_applicable");
  result = qdf_mem_cmp((const void *)(a1 + 52200), &v83, 6u);
  if ( !(_DWORD)result )
  {
    *a3 = *(_DWORD *)(a1 + 52196);
    goto LABEL_17;
  }
LABEL_16:
  result = 4294967274LL;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
