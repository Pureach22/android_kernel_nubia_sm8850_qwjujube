__int64 __fastcall synx_recover(unsigned int a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  unsigned int v7; // w19

  if ( (synx_debug & 2) != 0 )
  {
    v7 = a1;
    printk(&unk_29470, "warn", "synx_recover", 142, a1, a6);
    a1 = v7;
  }
  if ( a1 - 1024 > 0xBFF )
    return synx_internal_recover(a1);
  else
    return synx_hwfence_recover();
}
