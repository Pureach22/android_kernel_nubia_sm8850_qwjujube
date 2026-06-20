__int64 __fastcall qcom_ipcc_domain_map(__int64 a1, unsigned int a2)
{
  __int64 v3; // x19

  v3 = *(_QWORD *)(a1 + 32);
  irq_set_chip_and_handler_name(a2, &qcom_ipcc_irq_chip, &handle_level_irq, 0);
  irq_set_chip_data(a2, v3);
  irq_modify_status(a2, 0, 1024);
  return 0;
}
