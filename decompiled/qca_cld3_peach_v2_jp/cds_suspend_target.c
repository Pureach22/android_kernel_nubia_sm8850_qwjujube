__int64 __fastcall cds_suspend_target(__int64 a1)
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

  result = ucfg_pmo_psoc_suspend_target(*(_QWORD *)(a1 + 24), 1);
  if ( (_DWORD)result )
    return qdf_trace_msg(
             0x38u,
             2u,
             "%s: Failed to suspend target, status = %d",
             v2,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             "cds_suspend_target",
             (unsigned int)result);
  return result;
}
