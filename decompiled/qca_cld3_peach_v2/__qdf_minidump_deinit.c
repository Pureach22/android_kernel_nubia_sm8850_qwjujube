void _qdf_minidump_deinit()
{
  double v0; // d0
  double v1; // d1
  double v2; // d2
  double v3; // d3
  double v4; // d4
  double v5; // d5
  double v6; // d6
  double v7; // d7
  __int64 *v8; // x21
  __int64 *v9; // x22

  if ( qdf_va_md_initialized == 1 )
  {
    qdf_va_md_initialized = 0;
    qcom_va_md_unregister("peach_v2", &qdf_va_md_notif_blk);
    qword_825CA0 = raw_spin_lock_irqsave(&qdf_va_md_list_lock);
    v8 = (__int64 *)qdf_va_md_list;
    if ( (__int64 *)qdf_va_md_list != &qdf_va_md_list )
    {
      do
      {
        v9 = (__int64 *)*v8;
        qdf_list_remove_node((__int64)&qdf_va_md_list, v8);
        _qdf_mem_free((__int64)v8);
        v8 = v9;
      }
      while ( v9 != &qdf_va_md_list );
    }
    if ( (_DWORD)qword_825CB8 )
      qdf_trace_msg(0x33u, 2u, "%s: list length not equal to zero", v0, v1, v2, v3, v4, v5, v6, v7, "qdf_list_destroy");
    raw_spin_unlock_irqrestore(&qdf_va_md_list_lock, qword_825CA0);
  }
}
