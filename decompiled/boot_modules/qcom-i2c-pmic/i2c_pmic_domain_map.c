__int64 __fastcall i2c_pmic_domain_map(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v3; // x20
  __int64 v4; // x9
  __int64 v5; // x8

  v3 = *(_QWORD *)(a1 + 32);
  v4 = *(unsigned int *)(v3 + 96);
  if ( (int)v4 < 1 )
  {
LABEL_5:
    if ( (unsigned int)__ratelimit(&i2c_pmic_find_periph__rs, "i2c_pmic_find_periph") )
      dev_err(*(_QWORD *)v3, "Couldn't find periph struct for hwirq 0x%04lx\n", a3);
    return 4294967277LL;
  }
  v5 = *(_QWORD *)(v3 + 24);
  while ( (a3 & 0xFF00) != *(unsigned __int16 *)(v5 + 8) )
  {
    --v4;
    v5 += 72;
    if ( !v4 )
      goto LABEL_5;
  }
  if ( !v5 )
    return 4294967277LL;
  irq_set_chip_data(a2, v5);
  irq_set_chip_and_handler_name(a2, &i2c_pmic_irq_chip, &handle_level_irq, 0);
  irq_modify_status(a2, 0, 0x8000);
  irq_modify_status(a2, 0, 1024);
  return 0;
}
