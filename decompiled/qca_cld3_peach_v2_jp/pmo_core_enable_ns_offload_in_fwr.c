__int64 __fastcall pmo_core_enable_ns_offload_in_fwr(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  __int64 comp_private_obj; // x21
  __int64 v14; // x22
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int *v31; // x8
  const char *v32; // x2
  const char *v33; // x3
  unsigned int v34; // w1
  unsigned int v35; // w20
  unsigned __int64 StatusReg; // x8
  __int64 v37; // x8
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // w21
  __int64 v47; // x8

  if ( !a1 )
  {
    qdf_trace_msg(0x4Du, 2u, "%s: vdev is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "pmo_core_enable_ns_offload_in_fwr");
    return 4;
  }
  result = wlan_objmgr_vdev_try_get_ref(a1, 0xAu, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !(_DWORD)result )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
    v14 = *(_QWORD *)comp_private_obj;
    if ( (*(_BYTE *)(*(_QWORD *)wlan_objmgr_vdev_get_comp_private_obj(a1, 4u) + 8LL) & 1) == 0 )
    {
      v32 = "%s: ns offload statically disable";
      v33 = "pmo_core_ns_offload_sanity";
LABEL_10:
      v34 = 8;
LABEL_11:
      qdf_trace_msg(0x4Du, v34, v32, v15, v16, v17, v18, v19, v20, v21, v22, v33);
      goto LABEL_13;
    }
    if ( (pmo_core_is_vdev_supports_offload(a1, v15, v16, v17, v18, v19, v20, v21, v22) & 1) == 0 )
    {
      qdf_trace_msg(
        0x4Du,
        8u,
        "%s: vdev in invalid opmode for ns offload %d",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "pmo_core_ns_offload_sanity",
        *(unsigned int *)(a1 + 16));
      goto LABEL_13;
    }
    if ( (unsigned int)wlan_vdev_is_up() )
    {
LABEL_13:
      v35 = 4;
LABEL_14:
      wlan_objmgr_vdev_release_ref(a1, 0xAu, v31, v15, v16, v17, v18, v19, v20, v21, v22);
      return v35;
    }
    if ( a2 == 7 )
    {
      *(_BYTE *)(v14 + 9) = 1;
    }
    else if ( (*(_BYTE *)(v14 + 9) & 1) == 0 )
    {
      v32 = "%s: ns offload dynamically disable";
LABEL_33:
      v33 = "pmo_core_enable_ns_offload_in_fwr";
      goto LABEL_10;
    }
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(comp_private_obj + 1056);
    }
    else
    {
      raw_spin_lock_bh(comp_private_obj + 1056);
      *(_QWORD *)(comp_private_obj + 1064) |= 1uLL;
    }
    v37 = *(_QWORD *)(comp_private_obj + 1064);
    if ( *(_DWORD *)(comp_private_obj + 24) )
    {
      if ( (v37 & 1) != 0 )
      {
        *(_QWORD *)(comp_private_obj + 1064) = v37 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(comp_private_obj + 1056);
      }
      else
      {
        raw_spin_unlock(comp_private_obj + 1056);
      }
      v46 = *(unsigned __int8 *)(a1 + 104);
      qdf_trace_msg(
        0x4Du,
        8u,
        "%s: Enable ns offload in fwr vdev id: %d vdev: %pK trigger: %d",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "pmo_core_enable_ns_offload_in_fwr",
        *(unsigned __int8 *)(a1 + 104),
        a1,
        (unsigned int)a2);
      v47 = *(_QWORD *)wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
      if ( !v47 )
      {
        v32 = "%s: psoc_ctx is NULL";
        goto LABEL_35;
      }
      if ( a2 > 6 )
      {
        if ( a2 != 10 )
        {
          if ( a2 != 7 )
            goto LABEL_28;
LABEL_38:
          if ( (*(_BYTE *)(v47 + 13) & 1) == 0 )
          {
            qdf_trace_msg(
              0x4Du,
              8u,
              "%s: active offload is disabled, skip in mode:%d",
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              "pmo_core_do_enable_ns_offload",
              (unsigned int)a2);
            v35 = 0;
            goto LABEL_14;
          }
        }
      }
      else if ( a2 )
      {
        if ( a2 != 5 )
        {
LABEL_28:
          v32 = "%s: invalid pmo trigger";
LABEL_35:
          v33 = "pmo_core_do_enable_ns_offload";
          v34 = 2;
          goto LABEL_11;
        }
        goto LABEL_38;
      }
      v35 = pmo_tgt_enable_ns_offload_req(a1, v46);
      goto LABEL_14;
    }
    if ( (v37 & 1) != 0 )
    {
      *(_QWORD *)(comp_private_obj + 1064) = v37 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(comp_private_obj + 1056);
    }
    else
    {
      raw_spin_unlock(comp_private_obj + 1056);
    }
    v32 = "%s: skip ns offload enable as ns count is 0";
    goto LABEL_33;
  }
  return result;
}
