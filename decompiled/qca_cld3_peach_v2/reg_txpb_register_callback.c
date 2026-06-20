__int64 __fastcall reg_txpb_register_callback(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7

  result = reg_get_psoc_obj(a1);
  if ( !result )
    return qdf_trace_msg(
             0x51u,
             2u,
             "%s: reg psoc private obj is NULL",
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             "reg_txpb_register_callback");
  *(_QWORD *)(result + 93976) = a2;
  *(_QWORD *)(result + 93984) = a3;
  return result;
}
