__int64 __fastcall gunyah_trace_release(__int64 a1, __int64 a2)
{
  unsigned int v11; // w8
  unsigned int v12; // w8

  _X10 = &dword_7E08;
  __asm { PRFM            #0x11, [X10] }
  do
  {
    v11 = __ldxr((unsigned int *)&dword_7E08);
    v12 = v11 - 1;
  }
  while ( __stlxr(v12, (unsigned int *)&dword_7E08) );
  __dmb(0xBu);
  if ( !v12 )
  {
    __asm { HVC             #0 }
    printk(&unk_76F0, 3321921599LL, 0, 1);
  }
  kfree(*(_QWORD *)(a2 + 32));
  return 0;
}
