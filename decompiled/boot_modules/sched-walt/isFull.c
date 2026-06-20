__int64 __fastcall isFull(_DWORD *a1)
{
  if ( a1 )
    return a1[7] == (a1[8] + 1) % a1[6];
  printk(&unk_61D9B);
  return 0xFFFFFFFFLL;
}
