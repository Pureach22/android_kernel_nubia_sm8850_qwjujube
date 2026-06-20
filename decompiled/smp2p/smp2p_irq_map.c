__int64 __fastcall smp2p_irq_map(__int64 a1, unsigned int a2)
{
  __int64 v3; // x19

  v3 = *(_QWORD *)(a1 + 32);
  irq_set_chip_and_handler_name(a2, &smp2p_irq_chip, &handle_level_irq, 0);
  irq_set_chip_data(a2, v3);
  irq_modify_status(a2, 0, 0x8000);
  irq_modify_status(a2, 0, 1024);
  irq_set_parent(a2, *(unsigned int *)(*(_QWORD *)(v3 + 16) + 56LL));
  irq_modify_status(a2, 0, 0x80000);
  return 0;
}
