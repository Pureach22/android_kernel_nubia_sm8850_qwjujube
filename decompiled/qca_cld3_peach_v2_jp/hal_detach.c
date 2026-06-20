__int64 __fastcall hal_detach(__int64 a1)
{
  __int64 *v2; // x21

  v2 = (__int64 *)(a1 + 73728);
  ((void (__fastcall *)(__int64))hif_rtpm_deregister)(1);
  flush_work(a1 + 74472);
  cancel_work_sync(a1 + 74472);
  _flush_workqueue(v2[99]);
  destroy_workqueue(v2[99]);
  _qdf_mem_free(v2[92]);
  qdf_ssr_driver_dump_unregister_region("hal_soc");
  _qdf_minidump_remove(a1, 74584, "hal_soc");
  _qdf_mem_free(v2[83]);
  _qdf_mem_free_consistent(*(_QWORD *)(a1 + 8), *(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), 948);
  _qdf_mem_free_consistent(*(_QWORD *)(a1 + 8), *(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), 216);
  return _qdf_mem_free(a1);
}
