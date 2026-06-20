__int64 __fastcall csr_bss_start(_QWORD *a1, unsigned int a2, __int64 a3)
{
  __int64 v3; // x23
  __int64 v5; // x0
  _QWORD *vdev_by_id_from_pdev; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int v17; // w4
  __int64 v18; // x19
  void *v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x20
  int v29; // w9
  int v30; // w8
  int v31; // w9
  __int64 v32; // x0
  __int16 v33; // w8
  int v34; // w9
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int started; // w0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x4
  __int64 result; // x0
  unsigned int *v54; // x8
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  unsigned int *v63; // x8
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  unsigned int v78; // w8
  unsigned int v79; // w8
  _DWORD v80[2]; // [xsp+0h] [xbp-50h] BYREF
  __int64 (__fastcall *v81)(__int64, int, double, double, double, double, double, double, double, double); // [xsp+8h] [xbp-48h]
  __int64 v82; // [xsp+10h] [xbp-40h]
  __int64 v83; // [xsp+18h] [xbp-38h]
  __int64 v84; // [xsp+20h] [xbp-30h]
  __int64 v85; // [xsp+28h] [xbp-28h]
  __int64 v86; // [xsp+30h] [xbp-20h] BYREF
  __int64 v87; // [xsp+38h] [xbp-18h]
  __int64 v88; // [xsp+40h] [xbp-10h]
  __int64 v89; // [xsp+48h] [xbp-8h]

  v89 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v82 = 0;
  v83 = 0;
  if ( a2 > 5 )
    goto LABEL_15;
  v3 = a1[2153] + 96LL * a2;
  if ( !v3 )
    goto LABEL_15;
  v5 = a1[2695];
  v87 = 0;
  v88 = 0;
  v86 = 0;
  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(v5, a2, 7u);
  if ( !vdev_by_id_from_pdev )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: VDEV not found for vdev id : %d",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "csr_bss_start",
      a2);
    goto LABEL_15;
  }
  v17 = *((_DWORD *)vdev_by_id_from_pdev + 4);
  v18 = (__int64)vdev_by_id_from_pdev;
  if ( v17 > 0xB || ((1 << v17) & 0x80A) == 0 )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Start BSS request for invalid mode %d",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "csr_bss_start");
    goto LABEL_14;
  }
  v19 = (void *)_qdf_mem_malloc(0x2B0u, "csr_bss_start", 8110);
  if ( !v19 )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: SAP BSS config allocation failed",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "csr_bss_start");
LABEL_14:
    wlan_objmgr_vdev_release_ref(v18, 7u, v63, v64, v65, v66, v67, v68, v69, v70, v71);
    goto LABEL_15;
  }
  v28 = (__int64)v19;
  qdf_mem_copy(v19, (const void *)a3, 0x2B0u);
  _X9 = (unsigned int *)(a1 + 2693);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v78 = __ldxr(_X9);
    v79 = v78 + 1;
  }
  while ( __stlxr(v79, _X9) );
  __dmb(0xBu);
  v29 = v79 & 0xFFFFFF | 0xD000000;
  v30 = *(unsigned __int8 *)(v28 + 375);
  *(_DWORD *)(v28 + 4) = v29;
  *(_DWORD *)(v3 + 44) = v30;
  LOWORD(v30) = *(_WORD *)(a3 + 42);
  *(_WORD *)(v3 + 48) = v30;
  v31 = *(_DWORD *)(a3 + 368);
  v32 = a1[2695];
  WORD2(v87) = v30;
  LODWORD(v87) = v31;
  if_mgr_is_beacon_interval_valid(v32, a2, (__int64)&v86);
  v33 = WORD2(v87);
  *(_WORD *)(a3 + 42) = WORD2(v87);
  *(_WORD *)(v3 + 48) = v33;
  *(_BYTE *)(a3 + 680) = policy_mgr_get_connection_count(a1[2694]);
  v34 = *(_DWORD *)(v28 + 4);
  v81 = sme_sap_ser_callback;
  LODWORD(v82) = 0;
  v80[0] = 21;
  v80[1] = v34;
  BYTE4(v82) = 2;
  v84 = v18;
  v85 = v28;
  LODWORD(v83) = 12000;
  started = wlan_vdev_mlme_ser_start_bss((__int64)v80, v35, v36, v37, v38, v39, v40, v41, v42);
  v52 = started;
  _CF = started >= 2;
  result = 0;
  if ( _CF )
  {
    qdf_trace_msg(0x34u, 2u, "%s: ser cmd status %d", v44, v45, v46, v47, v48, v49, v50, v51, "csr_bss_start", v52);
    wlan_objmgr_vdev_release_ref(v18, 7u, v54, v55, v56, v57, v58, v59, v60, v61, v62);
    _qdf_mem_free(v28);
LABEL_15:
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
