__int64 __fastcall qcom_cpucp_remove(__int64 a1)
{
  return mbox_controller_unregister(*(_QWORD *)(a1 + 168));
}
