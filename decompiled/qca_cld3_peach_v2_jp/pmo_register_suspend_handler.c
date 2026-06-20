__int64 __fastcall pmo_register_suspend_handler(
        unsigned int a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 context; // x0
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
  unsigned int v31; // w19
  unsigned __int64 StatusReg; // x8
  __int64 v33; // x22
  _QWORD *v34; // x9
  __int64 v35; // x9
  __int64 v37; // x23

  qdf_trace_msg(0x4Du, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "pmo_register_suspend_handler");
  context = pmo_get_context();
  if ( context )
  {
    if ( a1 < 0x36 )
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v33 = context;
        raw_spin_lock(context + 1728);
      }
      else
      {
        v37 = context;
        raw_spin_lock_bh(context + 1728);
        v33 = v37;
        *(_QWORD *)(v37 + 1736) |= 1uLL;
      }
      v34 = (_QWORD *)(v33 + 8LL * a1);
      *v34 = a2;
      v34[54] = a3;
      v35 = *(_QWORD *)(v33 + 1736);
      if ( (v35 & 1) != 0 )
      {
        *(_QWORD *)(v33 + 1736) = v35 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v33 + 1728);
      }
      else
      {
        raw_spin_unlock(v33 + 1728);
      }
      v31 = 0;
    }
    else
    {
      qdf_trace_msg(
        0x4Du,
        2u,
        "%s: component id: %d is %s then valid components id",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "pmo_register_suspend_handler",
        a1,
        "More");
      v31 = 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: unable to get pmo ctx",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "pmo_register_suspend_handler");
    v31 = 16;
  }
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v23, v24, v25, v26, v27, v28, v29, v30, "pmo_register_suspend_handler");
  return v31;
}
