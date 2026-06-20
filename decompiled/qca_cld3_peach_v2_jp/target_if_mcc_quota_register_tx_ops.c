__int64 __fastcall target_if_mcc_quota_register_tx_ops(__int64 result)
{
  *(_QWORD *)(result + 248) = target_if_register_mcc_quota_event_handler;
  return result;
}
