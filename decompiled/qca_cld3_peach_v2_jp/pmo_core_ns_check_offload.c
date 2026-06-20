__int64 __fastcall pmo_core_ns_check_offload(__int64 a1, unsigned int a2, unsigned int a3)
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
  const char *v14; // x2
  unsigned int *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 comp_private_obj; // x0
  unsigned int *v26; // x8
  __int64 v27; // x20
  int v28; // w21
  unsigned __int64 StatusReg; // x8
  unsigned int v30; // w22
  __int64 v31; // x8

  v4 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a3, 10);
  if ( !v4 )
  {
    qdf_trace_msg(0x4Du, 2u, "%s: vdev is NULL", v5, v6, v7, v8, v9, v10, v11, v12, "pmo_core_ns_check_offload");
    return 4;
  }
  v13 = v4;
  if ( *(_DWORD *)(v4 + 16) == 11 )
  {
    v14 = "%s: NS offload not supported in NaN mode";
LABEL_4:
    qdf_trace_msg(0x4Du, 8u, v14, v5, v6, v7, v8, v9, v10, v11, v12, "pmo_core_ns_check_offload");
    wlan_objmgr_vdev_release_ref(v13, 0xAu, v15, v16, v17, v18, v19, v20, v21, v22, v23);
    return 4;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v4, 4u);
  if ( a2 <= 1 )
  {
    v27 = comp_private_obj;
    v28 = *(unsigned __int8 *)(*(_QWORD *)comp_private_obj + 13LL);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(comp_private_obj + 1056);
      if ( *(_BYTE *)(v27 + 20) )
        goto LABEL_11;
    }
    else
    {
      raw_spin_lock_bh(comp_private_obj + 1056);
      *(_QWORD *)(v27 + 1064) |= 1uLL;
      if ( *(_BYTE *)(v27 + 20) )
      {
LABEL_11:
        v30 = *(unsigned __int8 *)(v27 + 668);
        v31 = *(_QWORD *)(v27 + 1064);
        if ( (v31 & 1) == 0 )
        {
LABEL_12:
          raw_spin_unlock(v27 + 1056);
          goto LABEL_13;
        }
LABEL_19:
        *(_QWORD *)(v27 + 1064) = v31 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v27 + 1056);
LABEL_13:
        v26 = (unsigned int *)(v28 & v30);
        if ( (_DWORD)v26 == 1 )
        {
          v14 = "%s: active offload is enabled and offload already sent";
          goto LABEL_4;
        }
        goto LABEL_15;
      }
    }
    v30 = 0;
    v31 = *(_QWORD *)(v27 + 1064);
    if ( (v31 & 1) == 0 )
      goto LABEL_12;
    goto LABEL_19;
  }
LABEL_15:
  wlan_objmgr_vdev_release_ref(v13, 0xAu, v26, v5, v6, v7, v8, v9, v10, v11, v12);
  return 0;
}
