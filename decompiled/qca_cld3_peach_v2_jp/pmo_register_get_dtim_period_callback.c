__int64 __fastcall pmo_register_get_dtim_period_callback(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int ref; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w19
  const char *v23; // x2
  __int64 comp_private_obj; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v35; // x8

  if ( a1 )
  {
    if ( a2 )
    {
      ref = wlan_objmgr_psoc_try_get_ref(a1, 0xAu, a3, a4, a5, a6, a7, a8, a9, a10);
      if ( ref )
      {
        v21 = ref;
        qdf_trace_msg(
          0x4Du,
          2u,
          "%s: pmo cannot get the reference out of psoc",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "pmo_register_get_dtim_period_callback");
        return v21;
      }
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
      if ( !comp_private_obj )
        goto LABEL_15;
      v33 = comp_private_obj;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(comp_private_obj + 1040);
        v35 = *(_QWORD *)(v33 + 1048);
        *(_QWORD *)(v33 + 1024) = a2;
        if ( (v35 & 1) == 0 )
        {
LABEL_14:
          raw_spin_unlock(v33 + 1040);
LABEL_15:
          wlan_objmgr_psoc_release_ref(a1, 0xAu, v25, v26, v27, v28, v29, v30, v31, v32);
          return 0;
        }
      }
      else
      {
        raw_spin_lock_bh(comp_private_obj + 1040);
        v35 = *(_QWORD *)(v33 + 1048) | 1LL;
        *(_QWORD *)(v33 + 1048) = v35;
        *(_QWORD *)(v33 + 1024) = a2;
        if ( (v35 & 1) == 0 )
          goto LABEL_14;
      }
      *(_QWORD *)(v33 + 1048) = v35 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v33 + 1040);
      goto LABEL_15;
    }
    v23 = "%s: pmo_get_dtim_period is null";
  }
  else
  {
    v23 = "%s: psoc is null";
  }
  qdf_trace_msg(0x4Du, 2u, v23, a3, a4, a5, a6, a7, a8, a9, a10, "pmo_register_get_dtim_period_callback");
  return 29;
}
