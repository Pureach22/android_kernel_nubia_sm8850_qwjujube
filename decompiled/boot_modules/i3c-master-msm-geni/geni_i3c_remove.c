__int64 __fastcall geni_i3c_remove(__int64 a1)
{
  __int64 v1; // x19
  int v2; // w0
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 168);
  geni_i3c_enable_hotjoin_irq(v1, 0);
  destroy_workqueue(*(_QWORD *)(v1 + 21488));
  wakeup_source_unregister(*(_QWORD *)(v1 + 21528));
  if ( *(_QWORD *)(v1 + 21704) && *(_QWORD *)(v1 + 21712) != -1 )
    dma_unmap_page_attrs(*(_QWORD *)(v1 + 21632));
  if ( *(_BYTE *)(v1 + 21321) == 1 )
    qcom_geni_i3c_ibi_unconf(v1);
  pm_runtime_force_suspend(*(_QWORD *)(v1 + 8));
  v2 = pinctrl_select_state(*(_QWORD *)(v1 + 21600), *(_QWORD *)(v1 + 21536));
  if ( v2 )
  {
    ipc_log_string(*(_QWORD *)(v1 + 2528), "%s: pinctrl_select_state failed ret:%d\n", "geni_i3c_remove", v2);
    if ( *(_QWORD *)(v1 + 8) )
      i3c_trace_log();
  }
  i3c_master_unregister(v1 + 112);
  if ( *(_QWORD *)(v1 + 2528) )
    ipc_log_context_destroy();
  result = *(_QWORD *)(v1 + 2536);
  if ( result )
    result = ipc_log_context_destroy();
  i3c_nos = 0;
  return result;
}
