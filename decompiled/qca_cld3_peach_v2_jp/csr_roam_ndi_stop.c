__int64 __fastcall csr_roam_ndi_stop(__int64 a1, __int64 a2)
{
  unsigned int v3; // w19
  __int64 v4; // x0
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x21
  unsigned int *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w21
  bool is_vdev_id_up; // w23
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 active_cmd; // x22
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 result; // x0
  __int64 v44; // [xsp+8h] [xbp-28h] BYREF
  __int64 v45; // [xsp+10h] [xbp-20h]
  __int64 v46; // [xsp+18h] [xbp-18h]
  __int64 v47; // [xsp+20h] [xbp-10h]
  __int64 v48; // [xsp+28h] [xbp-8h]

  v3 = a2;
  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 21552);
  v46 = 0;
  v47 = 0;
  v45 = 0;
  v5 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v4, a2, 11);
  if ( v5 )
  {
    v46 = v5;
    HIDWORD(v45) = 6;
    v14 = v5;
    v44 = 0x1500000000LL;
    LOBYTE(v47) = 2;
    wlan_serialization_cancel_request((unsigned int *)&v44, v6, v7, v8, v9, v10, v11, v12, v13);
    wlan_objmgr_vdev_release_ref(v14, 0xBu, v15, v16, v17, v18, v19, v20, v21, v22, v23);
    v24 = (unsigned __int8)v3;
  }
  else
  {
    v24 = (unsigned __int8)v3;
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: vdev not found for id %d",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "csr_flush_pending_start_bss_cmd",
      (unsigned __int8)v3);
  }
  is_vdev_id_up = wlan_is_vdev_id_up(*(_QWORD *)(a1 + 21560), v3);
  active_cmd = wlan_serialization_get_active_cmd(
                 *(_QWORD *)(a1 + 21552),
                 v3,
                 0x15u,
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 v31,
                 v32,
                 v33);
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: vdev_id: %d is_vdev_up %d is_start_bss_in_active_q %d",
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    "csr_roam_ndi_stop",
    v24,
    is_vdev_id_up,
    active_cmd != 0);
  if ( is_vdev_id_up || active_cmd )
    result = csr_roam_issue_stop_bss_cmd(a1, v3, 2);
  else
    result = 16;
  _ReadStatusReg(SP_EL0);
  return result;
}
