__int64 __fastcall printAttr(__int64 a1)
{
  void *v1; // x0
  __int64 v3; // x21

  if ( a1 )
  {
    printk(&unk_61DB7);
    if ( *(int *)(a1 + 24) < 1 )
    {
      v1 = &unk_640C4;
    }
    else
    {
      v3 = 0;
      do
      {
        printk(&unk_65C5F);
        ++v3;
      }
      while ( v3 < *(int *)(a1 + 24) );
      v1 = &unk_640C4;
    }
  }
  else
  {
    v1 = &unk_61D9B;
  }
  return printk(v1);
}
