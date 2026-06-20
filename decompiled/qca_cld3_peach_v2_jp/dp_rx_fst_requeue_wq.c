__int64 __fastcall dp_rx_fst_requeue_wq(__int64 result)
{
  __int64 v1; // x29
  __int64 v2; // x30
  __int64 v3; // x8
  __int64 v4; // x1
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // [xsp+8h] [xbp-8h]

  v3 = *(_QWORD *)(result + 1480);
  if ( v3 )
  {
    if ( *(_BYTE *)(v3 + 616) == 1 )
    {
      v13 = v2;
      v4 = *(_QWORD *)(v3 + 400);
      *(_BYTE *)(v3 + 616) = 0;
      queue_work_on(32, v4, v3 + 352);
      return qdf_trace_msg(
               0x45u,
               5u,
               "%s: requeued defer fst update task",
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               "dp_rx_fst_requeue_wq",
               v1,
               v13);
    }
  }
  return result;
}
