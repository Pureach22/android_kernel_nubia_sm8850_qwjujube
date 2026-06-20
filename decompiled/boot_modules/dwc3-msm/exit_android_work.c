__int64 __fastcall exit_android_work(__int64 a1)
{
  __int64 v1; // x8
  void *v2; // x0

  v1 = *(_QWORD *)(a1 + 48);
  if ( (*(_BYTE *)(v1 - 3) & 1) != 0 )
  {
    v2 = &unk_17B44;
  }
  else if ( *(_BYTE *)(v1 - 2) )
  {
    v2 = &unk_16C53;
  }
  else
  {
    v2 = &unk_18530;
  }
  printk(v2);
  return 0;
}
