__int64 __fastcall reg_fixed_under_voltage_irq_handler(__int64 a1, __int64 a2)
{
  regulator_notifier_call_chain(*(_QWORD *)(a2 + 320), 1, 0);
  return 1;
}
