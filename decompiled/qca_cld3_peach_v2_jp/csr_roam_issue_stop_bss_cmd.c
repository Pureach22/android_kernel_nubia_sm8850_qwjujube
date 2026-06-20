__int64 __fastcall csr_roam_issue_stop_bss_cmd(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 v3; // x19
  __int64 v5; // x22
  __int64 v7; // x0
  _QWORD *vdev_by_id_from_pdev; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  _BYTE *v26; // x0
  unsigned int *v27; // x8
  unsigned int v28; // w0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x4
  __int64 result; // x0
  unsigned int v45; // w8
  unsigned int v46; // w8
  __int64 v47; // [xsp+8h] [xbp-38h] BYREF
  __int64 (__fastcall *v48)(__int64, int, double, double, double, double, double, double, double, double); // [xsp+10h] [xbp-30h]
  __int64 v49; // [xsp+18h] [xbp-28h]
  __int64 v50; // [xsp+20h] [xbp-20h]
  __int64 v51; // [xsp+28h] [xbp-18h]
  __int64 v52; // [xsp+30h] [xbp-10h]
  __int64 v53; // [xsp+38h] [xbp-8h]

  v5 = a3;
  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 21560);
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = nullptr;
  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(v7, a2, 7u);
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
      "csr_roam_issue_stop_bss_cmd",
      (unsigned __int8)a2);
    goto LABEL_13;
  }
  if ( (unsigned __int8)a2 >= 6u )
  {
    __break(0x5512u);
  }
  else
  {
    v3 = (__int64)vdev_by_id_from_pdev;
    v17 = a1 + 4LL * (unsigned __int8)a2;
    if ( *(_DWORD *)(v17 + 17172) == 3 && *(_DWORD *)(v17 + 17196) == 5 )
    {
      cm_stop_wait_for_key_timer(*(_QWORD *)(a1 + 21552), a2);
      csr_roam_substate_change(a1, 0, (unsigned __int8)a2, v18, v19, v20, v21, v22, v23, v24, v25);
    }
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Stop BSS vdev_id: %d bss_type %d",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "csr_roam_issue_stop_bss_cmd",
      (unsigned __int8)a2,
      (unsigned int)v5);
    v26 = (_BYTE *)_qdf_mem_malloc(8u, "csr_roam_issue_stop_bss_cmd", 8180);
    v5 = (__int64)v26;
    if ( !v26 )
      goto LABEL_11;
    *v26 = a2;
  }
  _X9 = (unsigned int *)(a1 + 21544);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v45 = __ldxr(_X9);
    v46 = v45 + 1;
  }
  while ( __stlxr(v46, _X9) );
  __dmb(0xBu);
  *(_DWORD *)(v5 + 4) = v46 & 0xFFFFFF | 0xD000000;
  LODWORD(v47) = 22;
  HIDWORD(v47) = v46 & 0xFFFFFF | 0xD000000;
  v48 = sme_sap_ser_callback;
  BYTE4(v49) = 2;
  LODWORD(v49) = 0;
  v51 = v3;
  v52 = v5;
  LODWORD(v50) = 17000;
  v28 = wlan_vdev_mlme_ser_stop_bss((__int64)&v47, v9, v10, v11, v12, v13, v14, v15, v16);
  v37 = v28;
  _CF = v28 >= 2;
  result = 0;
  if ( _CF )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: ser cmd status %d",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "csr_roam_issue_stop_bss_cmd",
      v37);
LABEL_11:
    wlan_objmgr_vdev_release_ref(v3, 7u, v27, v9, v10, v11, v12, v13, v14, v15, v16);
    _qdf_mem_free(v5);
LABEL_13:
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
