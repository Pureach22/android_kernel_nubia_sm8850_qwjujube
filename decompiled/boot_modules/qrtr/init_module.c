__int64 init_module()
{
  __int64 v0; // x19
  __int64 compatible_node; // x0
  unsigned int v2; // w19
  int v4; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v0 = 0;
  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = 0;
  while ( 1 )
  {
    compatible_node = of_find_compatible_node(v0, 0, "qcom,qrtr");
    if ( !compatible_node )
      break;
    v0 = compatible_node;
    if ( (of_property_read_variable_u32_array(compatible_node, "qcom,node-id", &v4, 1, 0) & 0x80000000) == 0 )
    {
      qrtr_local_nid = v4;
      break;
    }
  }
  qrtr_local_ilc = ipc_log_context_create(4, "qrtr_local", 0);
  v2 = proto_register(&qrtr_proto, 1);
  if ( !v2 )
  {
    v2 = sock_register(&qrtr_family);
    if ( !v2 )
    {
      v2 = qrtr_ns_init();
      if ( !v2 )
      {
        qrtr_backup_lo = (__int64)&qrtr_backup_lo;
        qword_D8F8 = (__int64)&qrtr_backup_lo;
        qword_D900 = 0;
        qrtr_backup_hi = (__int64)&qrtr_backup_hi;
        qword_D910 = (__int64)&qrtr_backup_hi;
        qword_D918 = 0;
        qrtr_backup_work = 0xFFFFFFFE00000LL;
        qword_D928 = (__int64)&qword_D928;
        qword_D930 = (__int64)&qword_D928;
        qword_D938 = (__int64)qrtr_alloc_backup;
        queue_work_on(32, system_unbound_wq, &qrtr_backup_work);
        tracepoint_probe_register(&_tracepoint_suspend_resume, qrtr_debug_suspend_trace_probe, 0);
        goto LABEL_10;
      }
      sock_unregister(42);
    }
    proto_unregister(&qrtr_proto);
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return v2;
}
