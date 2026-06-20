__int64 __fastcall dp_svc_get_meta_data_by_id(unsigned __int8 a1, __int64 a2, int *a3)
{
  __int64 context; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x8
  unsigned __int64 StatusReg; // x9
  int v16; // w9
  unsigned int v17; // w20

  context = dp_get_context();
  if ( context && (v14 = *(_QWORD *)(context + 1552)) != 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    *(_DWORD *)(StatusReg + 16) += 512;
    v16 = a1;
    if ( a1 <= 0x1Fu && *(_QWORD *)(v14 + 8LL * a1) )
    {
      v17 = 0;
      *a3 = (v16 << 16) | 0xB000000;
    }
    else
    {
      v17 = 4;
    }
    local_bh_enable_5();
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: svc_ctx is not initialised",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "dp_svc_get_meta_data_by_id");
    return 4;
  }
  return v17;
}
