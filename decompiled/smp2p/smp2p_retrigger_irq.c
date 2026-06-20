__int64 __fastcall smp2p_retrigger_irq(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x19
  unsigned __int64 v10; // x10

  v1 = *(_QWORD *)(a1 + 48);
  v2 = *(_QWORD *)(a1 + 8);
  ipc_log_string(
    ilc,
    "[%s]: %d: %s: %lu\n",
    "smp2p_retrigger_irq",
    *(_DWORD *)(*(_QWORD *)(v1 + 16) + 52LL),
    *(const char **)(v1 + 24),
    v2);
  _X9 = (unsigned __int64 *)(v1 + 64 + 8LL * ((unsigned int)v2 >> 6));
  __asm { PRFM            #0x11, [X9] }
  do
    v10 = __ldxr(_X9);
  while ( __stxr(v10 | (1LL << v2), _X9) );
  __dsb(0xFu);
  return 0;
}
