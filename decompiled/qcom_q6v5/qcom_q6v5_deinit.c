__int64 __fastcall qcom_q6v5_deinit(__int64 a1)
{
  wakeup_source_unregister(*(_QWORD *)(a1 + 336));
  return qmp_put(*(_QWORD *)(a1 + 32));
}
