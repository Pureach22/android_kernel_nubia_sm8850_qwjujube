__int64 __fastcall reg_txpb_unregister_callback(__int64 a1)
{
  __int64 result; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  result = reg_get_psoc_obj(a1);
  if ( !result )
    return qdf_trace_msg(
             0x51u,
             2u,
             "%s: reg psoc private obj is NULL",
             v2,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             "reg_txpb_unregister_callback");
  *(_QWORD *)(result + 93976) = 0;
  *(_QWORD *)(result + 93984) = 0;
  return result;
}
