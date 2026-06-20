__int64 __fastcall sme_apf_read_work_memory(__int64 a1, __int64 a2, __int64 a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _QWORD *context; // x0

  if ( (unsigned int)qdf_mutex_acquire(a1 + 12776) )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: sme_acquire_global_lock failed",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "sme_apf_read_work_memory");
  }
  else
  {
    *(_QWORD *)(a1 + 14504) = a3;
    qdf_mutex_release(a1 + 12776);
  }
  context = _cds_get_context(54, (__int64)"sme_apf_read_work_memory", v14, v15, v16, v17, v18, v19, v20, v21);
  if ( context )
    return wma_send_apf_read_work_memory_cmd(context, a2);
  else
    return 16;
}
