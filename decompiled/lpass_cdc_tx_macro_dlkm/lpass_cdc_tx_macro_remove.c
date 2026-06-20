__int64 __fastcall lpass_cdc_tx_macro_remove(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19

  v1 = *(_QWORD *)(result + 168);
  if ( v1 )
  {
    v2 = result;
    cancel_delayed_work_sync(v1 + 144);
    cancel_delayed_work_sync(v1 + 264);
    cancel_delayed_work_sync(v1 + 384);
    cancel_delayed_work_sync(v1 + 504);
    _pm_runtime_disable(v2 + 16, 1);
    _pm_runtime_set_status(v2 + 16, 2);
    return lpass_cdc_unregister_macro(v2 + 16, 0);
  }
  return result;
}
