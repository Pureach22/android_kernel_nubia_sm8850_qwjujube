__int64 sub_46FD8()
{
  __asm { PRFM            #0x18, 0xFFFFFFFFFFFCF708 }
  return waltgov_irq_work();
}
