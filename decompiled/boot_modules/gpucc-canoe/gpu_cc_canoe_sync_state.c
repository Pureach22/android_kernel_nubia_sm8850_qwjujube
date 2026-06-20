__int64 __fastcall gpu_cc_canoe_sync_state(__int64 a1)
{
  return qcom_cc_sync_state(a1, &gpu_cc_canoe_desc);
}
