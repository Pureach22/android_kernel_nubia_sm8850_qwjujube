__int64 __fastcall isEmpty(__int64 a1)
{
  if ( a1 )
    return *(_DWORD *)(a1 + 28) == *(_DWORD *)(a1 + 32);
  printk(&unk_61D9B);
  return 0xFFFFFFFFLL;
}
