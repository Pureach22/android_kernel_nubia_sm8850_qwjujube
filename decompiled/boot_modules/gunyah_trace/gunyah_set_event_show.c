__int64 gunyah_set_event_show()
{
  __asm { HVC             #0 }
  printk(&unk_79A5, 3321921599LL, 0, 0);
  return 4294967274LL;
}
