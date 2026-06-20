__int64 __fastcall q6v5_pong_interrupt(__int64 a1, __int64 a2)
{
  if ( a2 )
  {
    complete(a2 + 240);
    return 1;
  }
  else
  {
    printk(&unk_7807);
    return 4294967277LL;
  }
}
