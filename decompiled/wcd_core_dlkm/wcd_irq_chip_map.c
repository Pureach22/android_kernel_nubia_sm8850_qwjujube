__int64 __fastcall wcd_irq_chip_map(__int64 a1, unsigned int a2)
{
  irq_set_chip_and_handler_name(a2, &wcd_irq_chip, &handle_simple_irq, 0);
  irq_modify_status(a2, 0, 0x8000);
  irq_modify_status(a2, 0, 1024);
  return 0;
}
