__int64 __fastcall ind_notif_timeout_handler(__int64 a1)
{
  __int64 v1; // x8
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 - 24);
  if ( (unsigned int)(system_state - 7) <= 0xFFFFFFFC && (qcom_device_shutdown_in_progress & 1) == 0 )
    panic(
      "PDR: Indication notifier %s, state: 0x%x, trans-id: %d\n taking too long",
      (const char *)(v1 + 65),
      *(_DWORD *)(v1 + 160),
      *(unsigned __int16 *)(a1 - 28));
  result = _warn_printk(
             "PDR: Indication notifier %s, state: 0x%x, trans-id: %d\n taking too long",
             (const char *)(v1 + 65),
             *(_DWORD *)(v1 + 160),
             *(unsigned __int16 *)(a1 - 28));
  __break(0x800u);
  return result;
}
