__int64 __fastcall dp_svc_remove(
        unsigned __int8 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v9; // w19
  __int64 context; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x21
  unsigned __int64 StatusReg; // x8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x8
  __int64 v31; // x20
  __int64 v32; // x8
  __int64 v34; // x8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x0

  v9 = a1;
  if ( a1 >= 0x20u )
  {
    qdf_trace_msg(0x45u, 2u, "%s: invalid svc_id:%u for delete", a2, a3, a4, a5, a6, a7, a8, a9, "dp_svc_remove", a1);
    return 4;
  }
  context = dp_get_context();
  if ( !context || (v20 = *(_QWORD *)(context + 1552)) == 0 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: svc_ctx is not initialised", v12, v13, v14, v15, v16, v17, v18, v19, "dp_svc_remove");
    return 4;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v20 + 264);
  }
  else
  {
    raw_spin_lock_bh(v20 + 264);
    *(_QWORD *)(v20 + 272) |= 1uLL;
  }
  v30 = a1;
  v31 = *(_QWORD *)(v20 + 8LL * a1);
  if ( !v31 )
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: no service class with svc_id:%u",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "dp_svc_remove",
      v9);
LABEL_14:
    v32 = *(_QWORD *)(v20 + 272);
    if ( (v32 & 1) != 0 )
    {
      *(_QWORD *)(v20 + 272) = v32 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v20 + 264);
    }
    else
    {
      raw_spin_unlock(v20 + 264);
    }
    return 4;
  }
  if ( *(_BYTE *)(v31 + 17) )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: svc_id:%u is in use with ref:%u",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "dp_svc_remove",
      v9);
    goto LABEL_14;
  }
  *(_QWORD *)(v20 + 8 * v30) = 0;
  v34 = *(_QWORD *)(v20 + 272);
  --*(_DWORD *)(v20 + 256);
  if ( (v34 & 1) != 0 )
  {
    *(_QWORD *)(v20 + 272) = v34 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v20 + 264);
  }
  else
  {
    raw_spin_unlock(v20 + 264);
  }
  v43 = qdf_trace_msg(
          0x45u,
          5u,
          "%s: service class deleted for svc_id:%d",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          "dp_svc_remove",
          v9);
  synchronize_rcu(v43);
  _qdf_mem_free(v31);
  return 0;
}
