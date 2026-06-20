__int64 sub_A7E4()
{
  __asm { PRFM            #0x1A, 0xFFFFFFFFFFFF1C1C }
  return aw9620x_irq_handle_func();
}
