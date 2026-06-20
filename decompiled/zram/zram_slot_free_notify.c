__int64 __fastcall zram_slot_free_notify(__int64 a1, __int64 a2)
{
  _QWORD *v3; // x19
  __int64 result; // x0
  unsigned __int64 v11; // x9
  unsigned __int64 v14; // x9

  v3 = *(_QWORD **)(*(_QWORD *)(a1 + 16) + 88LL);
  _X8 = v3 + 16;
  __asm { PRFM            #0x11, [X8] }
  do
    v11 = __ldxr(_X8);
  while ( __stxr(v11 + 1, _X8) );
  result = raw_spin_trylock(*v3 + 16LL * (unsigned int)a2 + 12);
  if ( (_DWORD)result )
  {
    zram_free_page(v3, a2);
    return raw_spin_unlock(*v3 + 16LL * (unsigned int)a2 + 12);
  }
  else
  {
    _X8 = v3 + 23;
    __asm { PRFM            #0x11, [X8] }
    do
      v14 = __ldxr(_X8);
    while ( __stxr(v14 + 1, _X8) );
  }
  return result;
}
