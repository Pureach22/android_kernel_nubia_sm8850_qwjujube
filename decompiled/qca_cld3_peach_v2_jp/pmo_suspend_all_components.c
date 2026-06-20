__int64 __fastcall pmo_suspend_all_components(__int64 a1)
{
  __int64 context; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  __int64 v12; // x23
  __int64 v13; // x21
  unsigned __int64 StatusReg; // x24
  __int64 v15; // x8
  __int64 (__fastcall *v16)(__int64, __int64); // x25
  __int64 v17; // x22
  unsigned int v18; // w0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v28; // w22
  unsigned __int64 v29; // x24
  __int64 v30; // x8
  void (__fastcall *v31)(__int64, __int64); // x25
  __int64 v32; // x21

  context = pmo_get_context();
  if ( !context )
  {
    qdf_trace_msg(0x4Du, 2u, "%s: unable to get pmo ctx", v3, v4, v5, v6, v7, v8, v9, v10, "pmo_suspend_all_components");
    return 16;
  }
  v11 = context;
  v12 = 0;
  v13 = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v11 + 1728);
      v15 = *(_QWORD *)(v11 + 1736);
    }
    else
    {
      raw_spin_lock_bh(v11 + 1728);
      v15 = *(_QWORD *)(v11 + 1736) | 1LL;
      *(_QWORD *)(v11 + 1736) = v15;
    }
    v16 = *(__int64 (__fastcall **)(__int64, __int64))(v11 + v12);
    v17 = *(_QWORD *)(v11 + v12 + 432);
    if ( (v15 & 1) != 0 )
      break;
    raw_spin_unlock(v11 + 1728);
    if ( v16 )
      goto LABEL_10;
LABEL_3:
    ++v13;
    v12 += 8;
    if ( v13 == 54 )
      return 0;
  }
  *(_QWORD *)(v11 + 1736) = v15 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(v11 + 1728);
  if ( !v16 )
    goto LABEL_3;
LABEL_10:
  if ( *((_DWORD *)v16 - 1) != -1796695762 )
    __break(0x8239u);
  v18 = v16(a1, v17);
  if ( !v18 )
    goto LABEL_3;
  v28 = v18;
  qdf_trace_msg(
    0x4Du,
    2u,
    "%s: component %d failed to suspend; status: %d",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "pmo_suspend_all_components",
    (unsigned int)v13);
  if ( (_DWORD)v12 )
  {
    v29 = _ReadStatusReg(SP_EL0);
    do
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v29 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v29 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v11 + 1728);
        v30 = *(_QWORD *)(v11 + 1736);
      }
      else
      {
        raw_spin_lock_bh(v11 + 1728);
        v30 = *(_QWORD *)(v11 + 1736) | 1LL;
        *(_QWORD *)(v11 + 1736) = v30;
      }
      v31 = *(void (__fastcall **)(__int64, __int64))(v11 + v12 + 856);
      v32 = *(_QWORD *)(v11 + v12 + 1288);
      if ( (v30 & 1) != 0 )
      {
        *(_QWORD *)(v11 + 1736) = v30 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v11 + 1728);
        if ( v31 )
        {
LABEL_28:
          if ( *((_DWORD *)v31 - 1) != -1796695762 )
            __break(0x8239u);
          v31(a1, v32);
        }
      }
      else
      {
        raw_spin_unlock(v11 + 1728);
        if ( v31 )
          goto LABEL_28;
      }
      v12 -= 8;
    }
    while ( v12 );
  }
  return v28;
}
