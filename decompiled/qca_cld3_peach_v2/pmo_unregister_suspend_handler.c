__int64 __fastcall pmo_unregister_suspend_handler(
        unsigned int a1,
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
  __int64 context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v30; // x21
  __int64 v31; // x9
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w19
  _QWORD *v42; // x9
  __int64 v43; // x9
  __int64 v44; // x22

  qdf_trace_msg(0x4Du, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "pmo_unregister_suspend_handler");
  context = pmo_get_context();
  if ( !context )
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: unable to get pmo ctx",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "pmo_unregister_suspend_handler");
    goto LABEL_13;
  }
  if ( a1 >= 0x36 )
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: component id: %d is %s then valid components id",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "pmo_unregister_suspend_handler",
      a1,
      "More");
LABEL_13:
    v40 = 16;
    goto LABEL_14;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    v30 = context;
    raw_spin_lock(context + 1728);
  }
  else
  {
    v44 = context;
    raw_spin_lock_bh(context + 1728);
    v30 = v44;
    *(_QWORD *)(v44 + 1736) |= 1uLL;
  }
  if ( *(_QWORD *)(v30 + 8LL * a1) != a2 )
  {
    v31 = *(_QWORD *)(v30 + 1736);
    if ( (v31 & 1) != 0 )
    {
      *(_QWORD *)(v30 + 1736) = v31 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v30 + 1728);
    }
    else
    {
      raw_spin_unlock(v30 + 1728);
    }
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: can't find suspend handler for component id: %d ",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "pmo_unregister_suspend_handler",
      a1);
    goto LABEL_13;
  }
  v42 = (_QWORD *)(v30 + 8LL * a1);
  *v42 = 0;
  v42[54] = 0;
  v43 = *(_QWORD *)(v30 + 1736);
  if ( (v43 & 1) != 0 )
  {
    *(_QWORD *)(v30 + 1736) = v43 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v30 + 1728);
  }
  else
  {
    raw_spin_unlock(v30 + 1728);
  }
  v40 = 0;
LABEL_14:
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v21, v22, v23, v24, v25, v26, v27, v28, "pmo_unregister_suspend_handler");
  return v40;
}
