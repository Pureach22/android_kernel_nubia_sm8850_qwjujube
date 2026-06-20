__int64 __fastcall rrm_cleanup(
        __int64 result,
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
  __int64 v10; // x20
  unsigned __int8 v11; // w19
  __int64 v12; // x21
  __int64 v13; // x5
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  v10 = result;
  v11 = a2;
  if ( *(_BYTE *)(result + 20230) )
    --*(_BYTE *)(result + 20230);
  if ( (unsigned __int8)a2 >= 5u )
  {
    __break(0x5512u);
    return rrm_process_chan_load_report_xmit(result, a2);
  }
  else
  {
    v12 = *(_QWORD *)(result + 20232 + 8LL * (unsigned __int8)a2);
    if ( v12 )
    {
      if ( *(_BYTE *)(v12 + 16) )
      {
        _qdf_mem_free(*(_QWORD *)(v12 + 24));
        *(_QWORD *)(v12 + 24) = 0;
        *(_BYTE *)(v12 + 16) = 0;
      }
      if ( *(_BYTE *)(v12 + 3) == 7 )
      {
        qdf_trace_msg(0x35u, 8u, "%s: deactivate rrm sta stats timer", a3, a4, a5, a6, a7, a8, a9, a10, "rrm_cleanup");
        lim_deactivate_and_change_timer(v10, 22);
        qdf_mem_set((void *)(v10 + 21296), 0x118u, 0);
      }
      _qdf_mem_free(v12);
      v13 = *(unsigned __int8 *)(v10 + 20230);
      *(_QWORD *)(v10 + 20232 + 8LL * v11) = 0;
      return qdf_trace_msg(
               0x35u,
               8u,
               "%s: cleanup rrm req idx:%d, num_active_request:%d",
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               "rrm_cleanup",
               v11,
               v13);
    }
  }
  return result;
}
