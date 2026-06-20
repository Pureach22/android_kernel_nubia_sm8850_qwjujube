__int64 __fastcall i2c_pmic_irq_bus_lock(__int64 a1)
{
  return mutex_lock(*(_QWORD *)(a1 + 48) + 24LL);
}
