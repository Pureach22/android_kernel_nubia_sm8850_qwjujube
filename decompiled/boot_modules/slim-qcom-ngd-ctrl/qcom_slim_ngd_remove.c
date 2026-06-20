__int64 __fastcall qcom_slim_ngd_remove(__int64 a1)
{
  _QWORD *v1; // x19
  __int64 result; // x0

  v1 = *(_QWORD **)(a1 + 168);
  _pm_runtime_disable(a1 + 16, 1);
  pdr_handle_release(v1[672]);
  qcom_unregister_ssr_notifier(v1[671], v1 + 668);
  slim_unregister_controller(v1 + 116);
  qcom_slim_ngd_exit_dma((__int64)v1);
  qmi_handle_release(v1 + 201);
  if ( v1[626] )
    destroy_workqueue();
  result = kfree(v1[245]);
  v1[245] = 0;
  return result;
}
