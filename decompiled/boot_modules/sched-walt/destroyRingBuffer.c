__int64 __fastcall destroyRingBuffer(__int64 a1)
{
  __int64 v3; // x0

  if ( !a1 )
    return printk(&unk_61D9B);
  kfree(*(_QWORD *)(a1 + 16));
  v3 = *(_QWORD *)(a1 + 8);
  *(_QWORD *)(a1 + 16) = 0;
  kfree(v3);
  *(_QWORD *)(a1 + 8) = 0;
  printk(&unk_66E4F);
  return kfree(a1);
}
