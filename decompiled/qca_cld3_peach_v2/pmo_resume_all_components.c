__int64 __fastcall pmo_resume_all_components(__int64 a1)
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
  __int64 v12; // x21
  unsigned int v13; // w22
  unsigned __int64 StatusReg; // x27
  __int64 v15; // x8
  __int64 v16; // x9
  __int64 (__fastcall *v17)(__int64, __int64); // x28
  __int64 v18; // x26
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7

  context = pmo_get_context();
  if ( context )
  {
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
      v16 = v11 + 8 * v12;
      v17 = *(__int64 (__fastcall **)(__int64, __int64))(v16 + 864);
      v18 = *(_QWORD *)(v16 + 1296);
      if ( (v15 & 1) != 0 )
      {
        *(_QWORD *)(v11 + 1736) = v15 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v11 + 1728);
        if ( v17 )
        {
LABEL_10:
          if ( *((_DWORD *)v17 - 1) != -1796695762 )
            __break(0x823Cu);
          v13 = v17(a1, v18);
          if ( v13 )
          {
            qdf_trace_msg(
              0x4Du,
              1u,
              "%s: Non-recoverable failure occurred!",
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              "pmo_resume_all_components");
            qdf_trace_msg(
              0x4Du,
              1u,
              "%s: component %d failed to resume; status: %d",
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              "pmo_resume_all_components",
              (unsigned int)v12,
              v13);
          }
        }
      }
      else
      {
        raw_spin_unlock(v11 + 1728);
        if ( v17 )
          goto LABEL_10;
      }
      if ( ++v12 == 54 )
        return v13;
    }
  }
  qdf_trace_msg(0x4Du, 2u, "%s: unable to get pmo ctx", v3, v4, v5, v6, v7, v8, v9, v10, "pmo_resume_all_components");
  return 16;
}
