__int64 __fastcall sde_core_irqdomain_map(__int64 a1, unsigned int a2)
{
  __int64 v2; // x20

  if ( a1 && (v2 = *(_QWORD *)(a1 + 32)) != 0 )
  {
    irq_set_chip_and_handler_name(a2, &sde_core_irq_chip, &handle_level_irq, 0);
    return irq_set_chip_data(a2, v2);
  }
  else
  {
    printk(&unk_22766D, "sde_core_irqdomain_map");
    return 4294967274LL;
  }
}
