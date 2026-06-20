__int64 __fastcall fan_speed_irq_proc(__int64 a1, __int64 a2)
{
  unsigned int v8; // w9

  _X8 = (unsigned int *)(*(_QWORD *)(a2 + 8) + 4LL);
  __asm { PRFM            #0x11, [X8] }
  do
    v8 = __ldxr(_X8);
  while ( __stxr(v8 + 1, _X8) );
  return 1;
}
