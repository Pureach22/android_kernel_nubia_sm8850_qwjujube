__int64 __fastcall adreno_irq_handler(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 (__fastcall *v4)(_QWORD); // x8
  __int64 result; // x0
  unsigned int v12; // w10
  unsigned int v15; // w10

  v3 = *(_QWORD *)(*(_QWORD *)(a2 + 14264) + 40LL);
  _X9 = (unsigned int *)(a2 + 20416);
  __asm { PRFM            #0x11, [X9] }
  do
    v12 = __ldxr(_X9);
  while ( __stxr(v12 + 1, _X9) );
  __dmb(0xBu);
  v4 = *(__int64 (__fastcall **)(_QWORD))(v3 + 24);
  if ( *((_DWORD *)v4 - 1) != -1094258930 )
    __break(0x8228u);
  result = v4(a2);
  __dmb(0xBu);
  _X8 = (unsigned int *)(a2 + 20416);
  __asm { PRFM            #0x11, [X8] }
  do
    v15 = __ldxr(_X8);
  while ( __stxr(v15 - 1, _X8) );
  __dmb(0xBu);
  return result;
}
