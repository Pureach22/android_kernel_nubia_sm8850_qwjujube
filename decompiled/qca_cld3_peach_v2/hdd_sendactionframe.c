__int64 __fastcall hdd_sendactionframe(
        __int64 a1,
        unsigned __int16 *a2,
        unsigned int a3,
        unsigned __int8 a4,
        unsigned int a5,
        unsigned __int8 *a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  unsigned int v15; // w0
  const char *v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x26
  __int64 v27; // x22
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  const char *v41; // x2
  __int64 result; // x0
  int v43; // w9
  unsigned int v44; // w4
  unsigned int v45; // w5
  int v46; // w0
  _WORD *v47; // x0
  __int64 v48; // x23
  unsigned int v49; // w19
  int v50; // w5
  _QWORD *v51; // [xsp+8h] [xbp-88h] BYREF
  __int64 v52; // [xsp+10h] [xbp-80h]
  __int64 v53; // [xsp+18h] [xbp-78h]
  __int64 v54; // [xsp+20h] [xbp-70h]
  __int64 v55; // [xsp+28h] [xbp-68h]
  __int64 v56; // [xsp+30h] [xbp-60h]
  __int64 v57; // [xsp+38h] [xbp-58h]
  __int64 v58; // [xsp+40h] [xbp-50h] BYREF
  _QWORD v59[9]; // [xsp+48h] [xbp-48h] BYREF

  v59[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v59, 0, 64);
  v57 = 0;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = nullptr;
  v52 = 0;
  if ( a5 <= 4 )
  {
    qdf_trace_msg(
      0x33u,
      3u,
      "%s: Invalid payload length: %d",
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      "hdd_sendactionframe");
LABEL_13:
    result = 4294967274LL;
    goto LABEL_14;
  }
  v15 = *(_DWORD *)(a1 + 40);
  if ( v15 )
  {
    v16 = qdf_opmode_str(v15);
    qdf_trace_msg(
      0x33u,
      3u,
      "%s: Unsupported in mode %s(%d)",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "hdd_sendactionframe",
      v16,
      *(unsigned int *)(a1 + 40));
    goto LABEL_13;
  }
  v25 = *(_QWORD *)(a1 + 24);
  v27 = *(_QWORD *)(a1 + 52832);
  if ( !hdd_cm_is_vdev_associated((_DWORD *)v27) )
  {
    v41 = "%s: Not associated";
    goto LABEL_12;
  }
  if ( *(_DWORD *)a2 != *(_DWORD *)(v27 + 308) || a2[2] != *(unsigned __int16 *)(v27 + 312) )
  {
    v41 = "%s: STA is not associated to this AP";
LABEL_12:
    qdf_trace_msg(0x33u, 3u, v41, v32, v33, v34, v35, v36, v37, v38, v39, "hdd_sendactionframe");
    goto LABEL_13;
  }
  v43 = *a6;
  v44 = a3;
  v45 = a3;
  HIDWORD(v59[0]) = a3;
  if ( v43 != 127 || (v46 = qdf_mem_cmp(a6 + 1, &hdd_sendactionframe_oui, 3u), v44 = a3, v45 = a3, v46) )
  {
    if ( v45 )
      goto LABEL_18;
LABEL_25:
    qdf_trace_msg(0x33u, 2u, "Invalid freq : %d", v32, v33, v34, v35, v36, v37, v38, v39, v44);
    goto LABEL_13;
  }
  v50 = *(_DWORD *)(v27 + 700);
  if ( a3 )
  {
    if ( v50 != a3 )
    {
      qdf_trace_msg(
        0x33u,
        3u,
        "%s: freq(%u) is different from operating freq(%u)",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "hdd_sendactionframe");
      goto LABEL_13;
    }
    ucfg_cm_abort_roam_scan(*(_QWORD *)(v25 + 8), *(unsigned __int8 *)(*(_QWORD *)(a1 + 52832) + 8LL));
  }
  else
  {
    HIDWORD(v59[0]) = *(_DWORD *)(v27 + 700);
    if ( !v50 )
      goto LABEL_25;
  }
LABEL_18:
  v47 = (_WORD *)_qdf_mem_malloc((int)(a5 + 24), "hdd_sendactionframe", 868);
  if ( v47 )
  {
    v48 = (__int64)v47;
    *v47 = 208;
    qdf_mem_copy(v47 + 2, a2, 6u);
    qdf_mem_copy((void *)(v48 + 10), (const void *)(a1 + 1617), 6u);
    qdf_mem_copy((void *)(v48 + 16), a2, 6u);
    qdf_mem_copy((void *)(v48 + 24), a6, a5);
    v51 = v59;
    LOBYTE(v52) = 0;
    HIDWORD(v52) = a4;
    v53 = v48;
    v54 = (int)(a5 + 24);
    LOWORD(v55) = 257;
    v49 = wlan_hdd_mgmt_tx(0, a1 + 112, &v51, &v58);
    _qdf_mem_free(v48);
    result = v49;
  }
  else
  {
    result = 4294967284LL;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
