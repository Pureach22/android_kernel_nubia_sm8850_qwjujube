__int64 __fastcall pmo_core_enable_hw_filter_in_fwr(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int ref; // w20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int *v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 comp_private_obj; // x0
  __int64 v37; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v39; // x8
  int v40; // w9
  __int64 v41; // x0
  _BYTE v43[4]; // [xsp+0h] [xbp-10h] BYREF
  int v44; // [xsp+4h] [xbp-Ch]

  qdf_trace_msg(
    0x4Du,
    8u,
    "%s: enter",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "pmo_core_enable_hw_filter_in_fwr",
    0,
    *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808));
  ref = wlan_objmgr_vdev_try_get_ref(a1, 0xAu, v10, v11, v12, v13, v14, v15, v16, v17);
  if ( !ref )
  {
    if ( (unsigned int)wlan_vdev_is_up() )
    {
      ref = 11;
LABEL_10:
      wlan_objmgr_vdev_release_ref(a1, 0xAu, v27, v28, v29, v30, v31, v32, v33, v34, v35);
      goto LABEL_11;
    }
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(*(_QWORD *)(a1 + 216) + 80LL), 4u);
    v37 = comp_private_obj;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(comp_private_obj + 1040);
      v39 = *(_QWORD *)(v37 + 1048);
      if ( (v39 & 1) == 0 )
      {
LABEL_8:
        raw_spin_unlock(v37 + 1040);
LABEL_9:
        v40 = *(_DWORD *)(v37 + 4);
        v41 = *(_QWORD *)(*(_QWORD *)(a1 + 216) + 80LL);
        v43[0] = *(_BYTE *)(a1 + 168);
        v44 = v40;
        v43[1] = 1;
        ref = pmo_tgt_conf_hw_filter(v41, v43);
        goto LABEL_10;
      }
    }
    else
    {
      raw_spin_lock_bh(comp_private_obj + 1040);
      v39 = *(_QWORD *)(v37 + 1048) | 1LL;
      *(_QWORD *)(v37 + 1048) = v39;
      if ( (v39 & 1) == 0 )
        goto LABEL_8;
    }
    *(_QWORD *)(v37 + 1048) = v39 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v37 + 1040);
    goto LABEL_9;
  }
LABEL_11:
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v19, v20, v21, v22, v23, v24, v25, v26, "pmo_core_enable_hw_filter_in_fwr");
  _ReadStatusReg(SP_EL0);
  return ref;
}
