__int64 __fastcall target_if_cfr_dump_lut_enh(
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
  __int64 comp_private_obj; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x20
  unsigned __int64 StatusReg; // x8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w21
  __int64 v39; // x8
  unsigned int *v40; // x8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7

  if ( (unsigned int)wlan_objmgr_pdev_try_get_ref(a1, 0x30u, a2, a3, a4, a5, a6, a7, a8, a9) )
    return qdf_trace_msg(
             0x6Au,
             2u,
             "%s: failed to get pdev reference",
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             "target_if_cfr_dump_lut_enh");
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x1Eu);
  if ( comp_private_obj )
  {
    v28 = comp_private_obj;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(comp_private_obj + 1704);
      if ( *(_DWORD *)(v28 + 80) )
        goto LABEL_8;
    }
    else
    {
      raw_spin_lock_bh(comp_private_obj + 1704);
      *(_QWORD *)(v28 + 1712) |= 1uLL;
      if ( *(_DWORD *)(v28 + 80) )
      {
LABEL_8:
        v38 = 0;
        do
          get_lut_entry(v28, v38++, v30, v31, v32, v33, v34, v35, v36, v37);
        while ( v38 < *(_DWORD *)(v28 + 80) );
      }
    }
    v39 = *(_QWORD *)(v28 + 1712);
    if ( (v39 & 1) != 0 )
    {
      *(_QWORD *)(v28 + 1712) = v39 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v28 + 1704);
    }
    else
    {
      raw_spin_unlock(v28 + 1704);
    }
    return wlan_objmgr_pdev_release_ref(a1, 0x30u, v40, v41, v42, v43, v44, v45, v46, v47, v48);
  }
  qdf_trace_msg(
    0x6Au,
    2u,
    "%s: pdev object for CFR is null",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "target_if_cfr_dump_lut_enh");
  return wlan_objmgr_pdev_release_ref(a1, 0x30u, v40, v41, v42, v43, v44, v45, v46, v47, v48);
}
