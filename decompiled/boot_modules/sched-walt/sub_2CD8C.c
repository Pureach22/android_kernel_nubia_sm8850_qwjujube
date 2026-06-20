__int64 sub_2CD8C()
{
  __asm { PRFM            #0x18, 0xFFFFFFFFFFFB54BC }
  return walt_irq_work();
}
