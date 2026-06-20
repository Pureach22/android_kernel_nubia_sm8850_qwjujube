__int64 __fastcall pm8xxx_remove(__int64 a1)
{
  return dev_pm_clear_wake_irq(a1 + 16);
}
