__int64 __fastcall getSize(__int64 a1)
{
  if ( a1 )
    return *(unsigned int *)(a1 + 24);
  printk(&unk_61D9B);
  return 0xFFFFFFFFLL;
}
