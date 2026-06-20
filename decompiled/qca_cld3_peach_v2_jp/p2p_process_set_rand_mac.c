__int64 __fastcall p2p_process_set_rand_mac(
        _BYTE *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x22
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x20
  __int64 comp_private_obj; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int *v30; // x8
  __int64 result; // x0
  _DWORD *v32; // x8
  __int64 v33; // x1
  unsigned int v34; // w19
  __int64 v35; // x24
  __int64 v36; // x23
  char v37; // w9
  __int64 (__fastcall *v38)(__int64, __int64 *); // x10
  unsigned int v39; // w21
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int *v48; // x8
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  unsigned int *v57; // x8
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // [xsp+0h] [xbp-40h]
  __int64 v67; // [xsp+8h] [xbp-38h]
  __int64 v68; // [xsp+10h] [xbp-30h]
  __int64 v69; // [xsp+18h] [xbp-28h]
  __int64 v70; // [xsp+20h] [xbp-20h] BYREF
  __int64 v71; // [xsp+28h] [xbp-18h]
  __int64 v72; // [xsp+30h] [xbp-10h]
  __int64 v73; // [xsp+38h] [xbp-8h]

  v73 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v72) = 0;
  v70 = 0;
  v71 = 0;
  if ( !a1 || !*(_QWORD *)a1 )
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
      "p2p_process_set_rand_mac");
    result = 4;
    goto LABEL_16;
  }
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: random_mac:vdev %d set %d mac filter %02x:%02x:%02x:**:**:%02x freq %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "p2p_process_set_rand_mac",
    *((unsigned int *)a1 + 2),
    (unsigned __int8)a1[24],
    (unsigned __int8)a1[12],
    (unsigned __int8)a1[13],
    (unsigned __int8)a1[14],
    (unsigned __int8)a1[17],
    *((_DWORD *)a1 + 5),
    v69,
    v70,
    v71,
    v72,
    v73);
  v10 = *(_QWORD *)a1;
  v11 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          *(_QWORD *)a1,
          *((unsigned int *)a1 + 2),
          15);
  if ( !v11 )
  {
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: random_mac:vdev is null vdev %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "p2p_process_set_rand_mac",
      *((unsigned int *)a1 + 2));
LABEL_11:
    result = 16;
    goto LABEL_12;
  }
  v20 = v11;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v11, 5u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: random_mac:p2p_vdev_obj is null vdev %d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "p2p_process_set_rand_mac",
      *((unsigned int *)a1 + 2));
    goto LABEL_10;
  }
  v30 = *(unsigned int **)(comp_private_obj + 904);
  if ( v30 )
  {
    LODWORD(v67) = *(unsigned __int8 *)(comp_private_obj + 921);
    LODWORD(v68) = *(_DWORD *)(comp_private_obj + 924);
    LODWORD(v66) = *(unsigned __int8 *)(comp_private_obj + 918);
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: random_mac:Busy on vdev %d set %d mac filter %02x:%02x:%02x:**:**:%02x freq %d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "p2p_process_set_rand_mac",
      *(unsigned int *)(comp_private_obj + 912),
      *(unsigned __int8 *)(comp_private_obj + 928),
      *(unsigned __int8 *)(comp_private_obj + 916),
      *(unsigned __int8 *)(comp_private_obj + 917),
      v66,
      v67,
      v68);
LABEL_10:
    wlan_objmgr_vdev_release_ref(v20, 0xFu, v30, v22, v23, v24, v25, v26, v27, v28, v29);
    goto LABEL_11;
  }
  v35 = *(_QWORD *)(v10 + 2128);
  if ( v35 == -144 )
    goto LABEL_10;
  v30 = *(unsigned int **)(v35 + 216);
  if ( !v30 )
    goto LABEL_10;
  v36 = comp_private_obj;
  qdf_mem_set(&v70, 0x14u, 0);
  LODWORD(v70) = *((_DWORD *)a1 + 2);
  qdf_mem_copy((char *)&v70 + 4, a1 + 12, 6u);
  v37 = a1[24];
  v38 = *(__int64 (__fastcall **)(__int64, __int64 *))(v35 + 216);
  HIDWORD(v71) = *((_DWORD *)a1 + 5);
  LOBYTE(v72) = v37;
  if ( *((_DWORD *)v38 - 1) != -404801417 )
    __break(0x822Au);
  v39 = v38(v10, &v70);
  if ( v39 )
  {
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: random_mac:p2p set mac addr rx filter, status:%d",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      "p2p_process_set_rand_mac",
      v39);
    wlan_objmgr_vdev_release_ref(v20, 0xFu, v48, v49, v50, v51, v52, v53, v54, v55, v56);
    result = v39;
LABEL_12:
    v32 = *((_DWORD **)a1 + 4);
    if ( v32 )
    {
      v33 = *((_QWORD *)a1 + 5);
      v34 = result;
      if ( *(v32 - 1) != 1192198747 )
        __break(0x8228u);
      ((void (__fastcall *)(_QWORD, __int64))v32)(0, v33);
      result = v34;
    }
    goto LABEL_16;
  }
  if ( a1[24] == 1 )
    qdf_mem_copy((void *)(v36 + 904), a1, 0x30u);
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: random_mac:p2p set mac addr rx filter, status:%d",
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    "p2p_process_set_rand_mac",
    0);
  wlan_objmgr_vdev_release_ref(v20, 0xFu, v57, v58, v59, v60, v61, v62, v63, v64, v65);
  result = 0;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
