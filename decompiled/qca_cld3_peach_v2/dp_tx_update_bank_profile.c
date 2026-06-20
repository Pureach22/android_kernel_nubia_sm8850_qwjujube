__int64 __fastcall dp_tx_update_bank_profile(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned int v11; // w10

  qdf_mutex_acquire(a1 + 22536);
  _X8 = (unsigned int *)(*(_QWORD *)(a1 + 22600) + 12LL * *(char *)(a2 + 46248) + 4);
  __asm { PRFM            #0x11, [X8] }
  do
    v11 = __ldxr(_X8);
  while ( __stxr(v11 - 1, _X8) );
  qdf_mutex_release(a1 + 22536);
  result = dp_tx_get_bank_profile(a1, a2);
  *(_BYTE *)(a2 + 46248) = result;
  *(_BYTE *)(a2 + 63) = result;
  return result;
}
