__int64 __fastcall pm8xxx_rtc_shutdown(__int64 a1)
{
  return devm_free_irq(*(_QWORD *)(*(_QWORD *)(a1 + 168) + 32LL), *(unsigned int *)(*(_QWORD *)(a1 + 168) + 20LL));
}
