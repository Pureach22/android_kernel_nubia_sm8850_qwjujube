__int64 __fastcall ucfg_nan_get_callbacks(
        __int64 a1,
        void *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v22; // x8

  if ( !a1 )
  {
    qdf_trace_msg(0x53u, 2u, "%s: psoc is null", a3, a4, a5, a6, a7, a8, a9, a10, "nan_get_psoc_priv_obj");
    goto LABEL_11;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
  if ( !comp_private_obj )
  {
LABEL_11:
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: nan psoc priv object is NULL",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "ucfg_nan_get_callbacks");
    return 29;
  }
  v20 = comp_private_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(comp_private_obj);
  }
  else
  {
    raw_spin_lock_bh(comp_private_obj);
    *(_QWORD *)(v20 + 8) |= 1uLL;
  }
  qdf_mem_copy(a2, (const void *)(v20 + 16), 0xC0u);
  v22 = *(_QWORD *)(v20 + 8);
  if ( (v22 & 1) != 0 )
  {
    *(_QWORD *)(v20 + 8) = v22 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v20);
  }
  else
  {
    raw_spin_unlock(v20);
  }
  return 0;
}
