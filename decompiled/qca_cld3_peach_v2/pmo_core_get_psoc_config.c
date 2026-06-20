__int64 __fastcall pmo_core_get_psoc_config(
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 comp_private_obj; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  _QWORD *v29; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v31; // x8
  unsigned int v32; // w19
  const char *v33; // x4

  qdf_trace_msg(0x4Du, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "pmo_core_get_psoc_config");
  if ( a1 && a2 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
    if ( comp_private_obj )
    {
      v29 = (_QWORD *)comp_private_obj;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(comp_private_obj + 1040);
      }
      else
      {
        raw_spin_lock_bh(comp_private_obj + 1040);
        v29[131] |= 1uLL;
      }
      qdf_mem_copy(a2, v29, 0x80u);
      v31 = v29[131];
      if ( (v31 & 1) != 0 )
      {
        v29[131] = v31 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v29 + 130);
      }
      else
      {
        raw_spin_unlock(v29 + 130);
      }
    }
    v32 = 0;
  }
  else
  {
    if ( a1 )
      v33 = "psoc_cfg";
    else
      v33 = "psoc";
    qdf_trace_msg(0x4Du, 2u, "%s: %s is null", v12, v13, v14, v15, v16, v17, v18, v19, "pmo_core_get_psoc_config", v33);
    v32 = 29;
  }
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v21, v22, v23, v24, v25, v26, v27, v28, "pmo_core_get_psoc_config");
  return v32;
}
