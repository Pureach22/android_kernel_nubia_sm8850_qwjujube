__int64 __fastcall lim_log_session_states(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v9; // w8
  __int64 v10; // x19
  __int64 v11; // x27
  unsigned __int64 v12; // x20
  __int64 v13; // x24
  __int64 v14; // x25
  __int64 v15; // x26
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  v9 = *(unsigned __int16 *)(result + 3992);
  if ( *(_WORD *)(result + 3992) )
  {
    v10 = result;
    v11 = 0;
    v12 = 0;
    do
    {
      if ( *(_BYTE *)(*(_QWORD *)(v10 + 12264) + v11 + 70) )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: sysRole(%d) Session (%d)",
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          "lim_log_session_states",
          *(unsigned int *)(v10 + 4060),
          (unsigned int)v12);
        v13 = lim_sme_state_str(*(unsigned int *)(*(_QWORD *)(v10 + 12264) + v11 + 80));
        v14 = lim_sme_state_str(*(unsigned int *)(*(_QWORD *)(v10 + 12264) + v11 + 84));
        v15 = lim_mlm_state_str(*(unsigned int *)(*(_QWORD *)(v10 + 12264) + v11 + 72));
        v16 = lim_mlm_state_str(*(unsigned int *)(*(_QWORD *)(v10 + 12264) + v11 + 76));
        result = qdf_trace_msg(
                   0x35u,
                   8u,
                   "%s: SME: Curr %s,Prev %s,MLM: Curr %s,Prev %s",
                   v17,
                   v18,
                   v19,
                   v20,
                   v21,
                   v22,
                   v23,
                   v24,
                   "lim_log_session_states",
                   v13,
                   v14,
                   v15,
                   v16);
        v9 = *(unsigned __int16 *)(v10 + 3992);
      }
      ++v12;
      v11 += 14000;
    }
    while ( v12 < v9 );
  }
  return result;
}
