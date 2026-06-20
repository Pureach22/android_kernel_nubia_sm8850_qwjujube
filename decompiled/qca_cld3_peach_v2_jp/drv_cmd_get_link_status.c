__int64 __fastcall drv_cmd_get_link_status(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        const char *a11,
        __int64 a12,
        __int64 a13)
{
  __int64 v15; // x22
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x0
  __int64 v34; // x21
  __int64 v35; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  const char *v44; // x2
  unsigned int driver_state; // w0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  int v54; // w4
  unsigned __int8 v55; // w0
  int v56; // w8
  __int64 v57; // x20
  unsigned __int64 v58; // x19
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v68; // x9
  unsigned __int64 v69; // x9
  unsigned __int64 v75; // x8
  unsigned __int64 v76; // x8
  unsigned __int64 v78; // x9
  __int64 result; // x0
  const char *v80; // x0
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  const char *v89; // x2
  unsigned int v90; // w1
  _QWORD v91[5]; // [xsp+8h] [xbp-28h] BYREF

  v91[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = *a1;
  if ( (cds_get_driver_state(a2, a3, a4, a5, a6, a7, a8, a9) & 8) != 0
    || (cds_get_driver_state(v16, v17, v18, v19, v20, v21, v22, v23) & 0x10) != 0 )
  {
    driver_state = cds_get_driver_state(v16, v17, v18, v19, v20, v21, v22, v23);
    qdf_trace_msg(
      0x33u,
      3u,
      "%s: Recovery in Progress. State: 0x%x Ignore!!!",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "wlan_hdd_get_link_status",
      driver_state);
LABEL_9:
    v54 = 0;
    goto LABEL_10;
  }
  v24 = *(_DWORD *)(v15 + 40);
  if ( (v24 | 2) != 2 )
  {
    v80 = qdf_opmode_str(v24);
    qdf_trace_msg(
      0x33u,
      3u,
      "%s: Unsupported in mode %s(%d)",
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      "wlan_hdd_get_link_status",
      v80,
      *(unsigned int *)(v15 + 40));
    goto LABEL_9;
  }
  if ( !hdd_cm_is_vdev_associated(*(_DWORD **)(v15 + 52824)) )
  {
    v89 = "%s: Not associated!";
    v90 = 3;
LABEL_25:
    qdf_trace_msg(0x33u, v90, v89, v25, v26, v27, v28, v29, v30, v31, v32, "wlan_hdd_get_link_status");
    goto LABEL_9;
  }
  v33 = osif_request_alloc(wlan_hdd_get_link_status_params);
  if ( !v33 )
  {
    v89 = "%s: Request allocation failure";
    v90 = 2;
    goto LABEL_25;
  }
  v34 = v33;
  v35 = osif_request_cookie(v33);
  if ( (unsigned int)sme_get_link_status(
                       *(_QWORD *)(*(_QWORD *)(v15 + 24) + 16LL),
                       hdd_get_link_status_cb,
                       v35,
                       *(unsigned __int8 *)(*(_QWORD *)(v15 + 52824) + 8LL)) )
  {
    v44 = "%s: Unable to retrieve link status";
  }
  else
  {
    if ( !(unsigned int)osif_request_wait_for_response(v34) )
    {
      *(_BYTE *)(v15 + 42082) = *(_BYTE *)osif_request_priv(v34);
      goto LABEL_29;
    }
    v44 = "%s: SME timed out while retrieving link status";
  }
  qdf_trace_msg(0x33u, 2u, v44, v36, v37, v38, v39, v40, v41, v42, v43, "wlan_hdd_get_link_status");
LABEL_29:
  osif_request_put(v34);
  v54 = *(unsigned __int8 *)(v15 + 42082);
LABEL_10:
  memset(v91, 0, 32);
  scnprintf(v91, 32, "%s %d", a11, v54);
  v56 = *(_DWORD *)(a13 + 12);
  if ( v56 > v55 )
    LOBYTE(v56) = v55 + 1;
  v57 = (unsigned __int8)v56;
  if ( (unsigned __int8)v56 >= 0x21u )
  {
    _copy_overflow(32, (unsigned __int8)v56);
  }
  else
  {
    v58 = *(_QWORD *)a13;
    _check_object_size(v91, (unsigned __int8)v56, 1);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v68 = v58, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v68 = v58 & ((__int64)(v58 << 8) >> 8);
    if ( 0x8000000000LL - v57 >= v68 )
    {
      v69 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v75 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v75 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v75);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v69);
      v57 = _arch_copy_to_user(v58 & 0xFF7FFFFFFFFFFFFFLL, v91, v57);
      v76 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v78 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v78 - 4096);
      _WriteStatusReg(TTBR1_EL1, v78);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v76);
    }
    if ( !v57 )
    {
      result = 0;
      goto LABEL_21;
    }
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: failed to copy data to user buffer",
    v59,
    v60,
    v61,
    v62,
    v63,
    v64,
    v65,
    v66,
    "drv_cmd_get_link_status");
  result = 4294967282LL;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
