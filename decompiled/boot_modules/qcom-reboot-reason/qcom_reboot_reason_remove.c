__int64 __fastcall qcom_reboot_reason_remove(__int64 a1)
{
  return unregister_reboot_notifier(*(_QWORD *)(a1 + 168) + 8LL);
}
