__int64 __fastcall p2p_process_set_rand_mac_rsp(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x21
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x19
  __int64 comp_private_obj; // x0
  unsigned int *v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  _QWORD *v31; // x20
  void (__fastcall *v32)(_BOOL8, __int64); // x8
  __int64 v33; // x1
  _BOOL8 v34; // x0
  unsigned int *v35; // x8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v45; // x4
  const char *v46; // x2

  if ( !a1 || !*(_QWORD *)a1 || !**(_QWORD **)a1 )
  {
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: random_mac:set_filter_req is null",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "p2p_process_set_rand_mac_rsp");
    return 4;
  }
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: random_mac:process rsp on vdev %d status %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "p2p_process_set_rand_mac_rsp",
    *(unsigned int *)(a1 + 8),
    *(unsigned int *)(a1 + 12));
  v10 = a1;
  v11 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          **(_QWORD **)a1,
          *(unsigned int *)(a1 + 8),
          15);
  if ( !v11 )
  {
    v45 = *(unsigned int *)(a1 + 8);
    v46 = "%s: random_mac:vdev is null vdev %d";
LABEL_18:
    qdf_trace_msg(0x4Eu, 8u, v46, v12, v13, v14, v15, v16, v17, v18, v19, "p2p_process_set_rand_mac_rsp", v45);
    return 4;
  }
  v20 = v11;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v11, 5u);
  if ( !comp_private_obj )
  {
    wlan_objmgr_vdev_release_ref(v20, 0xFu, v22, v23, v24, v25, v26, v27, v28, v29, v30);
    v45 = *(unsigned int *)(v10 + 8);
    v46 = "%s: random_mac:p2p_vdev_obj is null vdev %d";
    goto LABEL_18;
  }
  v31 = (_QWORD *)comp_private_obj;
  if ( !*(_QWORD *)(comp_private_obj + 904) )
  {
    wlan_objmgr_vdev_release_ref(v20, 0xFu, nullptr, v23, v24, v25, v26, v27, v28, v29, v30);
    v45 = *(unsigned int *)(v10 + 8);
    v46 = "%s: random_mac:no pending set req for vdev %d";
    goto LABEL_18;
  }
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: random_mac:get pending req on vdev %d set %d mac filter %02x:%02x:%02x:**:**:%02x freq %d",
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    "p2p_process_set_rand_mac_rsp",
    *(unsigned int *)(comp_private_obj + 912),
    *(unsigned __int8 *)(comp_private_obj + 928),
    *(unsigned __int8 *)(comp_private_obj + 916),
    *(unsigned __int8 *)(comp_private_obj + 917),
    *(unsigned __int8 *)(comp_private_obj + 918),
    *(unsigned __int8 *)(comp_private_obj + 921),
    *(_DWORD *)(comp_private_obj + 924));
  v32 = (void (__fastcall *)(_BOOL8, __int64))v31[117];
  if ( v32 )
  {
    v33 = v31[118];
    v34 = *(_DWORD *)(v10 + 12) != 0;
    if ( *((_DWORD *)v32 - 1) != 1192198747 )
      __break(0x8228u);
    v32(v34, v33);
  }
  qdf_mem_set(v31 + 113, 0x30u, 0);
  wlan_objmgr_vdev_release_ref(v20, 0xFu, v35, v36, v37, v38, v39, v40, v41, v42, v43);
  return 0;
}
