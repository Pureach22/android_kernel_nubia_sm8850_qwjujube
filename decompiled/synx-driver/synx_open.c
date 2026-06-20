__int64 __fastcall synx_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v7; // x19

  if ( (synx_debug & 0x10) != 0 )
  {
    v7 = a2;
    printk(&unk_299C4, "verb", "synx_open", 3800, *(unsigned int *)(_ReadStatusReg(SP_EL0) + 1800), a6);
    a2 = v7;
  }
  *(_QWORD *)(a2 + 32) = 0;
  return 0;
}
