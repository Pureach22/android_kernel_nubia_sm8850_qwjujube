__int64 __fastcall pmo_core_ns_check_offload(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  const char *v16; // x2
  unsigned int *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 comp_private_obj; // x0
  unsigned int *v36; // x8
  __int64 v37; // x20
  int v38; // w21
  unsigned __int64 StatusReg; // x8
  unsigned int v40; // w22
  __int64 v41; // x8

  v6 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a3, 10);
  if ( v6 )
  {
    v15 = v6;
    if ( *(_DWORD *)(v6 + 16) == 11 )
    {
      v16 = "%s: NS offload not supported in NaN mode";
LABEL_4:
      qdf_trace_msg(0x4Du, 8u, v16, v7, v8, v9, v10, v11, v12, v13, v14, "pmo_core_ns_check_offload");
LABEL_8:
      wlan_objmgr_vdev_release_ref(v15, 0xAu, v17, v18, v19, v20, v21, v22, v23, v24, v25);
      return 4;
    }
    if ( (wlan_vdev_mlme_get_is_mlo_link(a1, a3) & 1) != 0 )
    {
      qdf_trace_msg(
        0x4Du,
        8u,
        "%s: NS offload not supported for MLO partner link with vdev_id[%d]",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "pmo_core_ns_check_offload",
        (unsigned __int8)a3);
      goto LABEL_8;
    }
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v15, 4u);
    if ( a2 > 1 )
    {
LABEL_23:
      wlan_objmgr_vdev_release_ref(v15, 0xAu, v36, v7, v8, v9, v10, v11, v12, v13, v14);
      return 0;
    }
    v37 = comp_private_obj;
    v38 = *(unsigned __int8 *)(*(_QWORD *)comp_private_obj + 13LL);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(comp_private_obj + 1056);
      if ( *(_BYTE *)(v37 + 20) )
      {
LABEL_16:
        v40 = *(unsigned __int8 *)(v37 + 668);
        goto LABEL_19;
      }
    }
    else
    {
      raw_spin_lock_bh(comp_private_obj + 1056);
      *(_QWORD *)(v37 + 1064) |= 1uLL;
      if ( *(_BYTE *)(v37 + 20) )
        goto LABEL_16;
    }
    v40 = 0;
LABEL_19:
    v41 = *(_QWORD *)(v37 + 1064);
    if ( (v41 & 1) != 0 )
    {
      *(_QWORD *)(v37 + 1064) = v41 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v37 + 1056);
    }
    else
    {
      raw_spin_unlock(v37 + 1056);
    }
    v36 = (unsigned int *)(v38 & v40);
    if ( (_DWORD)v36 == 1 )
    {
      v16 = "%s: active offload is enabled and offload already sent";
      goto LABEL_4;
    }
    goto LABEL_23;
  }
  qdf_trace_msg(0x4Du, 2u, "%s: vdev is NULL", v7, v8, v9, v10, v11, v12, v13, v14, "pmo_core_ns_check_offload");
  return 4;
}
