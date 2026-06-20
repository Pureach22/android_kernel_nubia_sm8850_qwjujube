__int64 __fastcall p2p_check_random_mac(__int64 a1, __int64 a2, const void *a3)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  __int64 comp_private_obj; // x0
  unsigned int *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  _BYTE *v24; // x21
  unsigned int *v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  const char *v34; // x2
  unsigned int *v36; // x8
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7

  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 15);
  if ( !v4 )
  {
    v34 = "%s: vdev is null";
LABEL_14:
    qdf_trace_msg(0x4Eu, 8u, v34, v5, v6, v7, v8, v9, v10, v11, v12, "p2p_check_random_mac");
    return 0;
  }
  v13 = v4;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v4, 5u);
  if ( !comp_private_obj )
  {
    wlan_objmgr_vdev_release_ref(v13, 0xFu, v15, v16, v17, v18, v19, v20, v21, v22, v23);
    v34 = "%s: p2p vdev object is NULL";
    goto LABEL_14;
  }
  v24 = (_BYTE *)comp_private_obj;
  raw_spin_lock(comp_private_obj + 24);
  if ( (v24[48] != 1 || (unsigned int)qdf_mem_cmp(v24 + 49, a3, 6u))
    && (v24[264] != 1 || (unsigned int)qdf_mem_cmp(v24 + 265, a3, 6u))
    && (v24[480] != 1 || (unsigned int)qdf_mem_cmp(v24 + 481, a3, 6u))
    && (v24[696] != 1 || (unsigned int)qdf_mem_cmp(v24 + 697, a3, 6u)) )
  {
    raw_spin_unlock(v24 + 24);
    wlan_objmgr_vdev_release_ref(v13, 0xFu, v25, v26, v27, v28, v29, v30, v31, v32, v33);
    return 0;
  }
  raw_spin_unlock(v24 + 24);
  wlan_objmgr_vdev_release_ref(v13, 0xFu, v36, v37, v38, v39, v40, v41, v42, v43, v44);
  return 1;
}
