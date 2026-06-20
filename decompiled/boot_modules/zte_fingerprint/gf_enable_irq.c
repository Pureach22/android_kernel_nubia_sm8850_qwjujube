__int64 gf_enable_irq()
{
  __int64 result; // x0

  if ( dword_83BC )
    return printk(&unk_8A78);
  result = enable_irq((unsigned int)dword_83B8);
  dword_83BC = 1;
  return result;
}
