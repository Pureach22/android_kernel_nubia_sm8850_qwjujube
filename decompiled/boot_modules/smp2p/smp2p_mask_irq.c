__int64 __fastcall smp2p_mask_irq(__int64 result)
{
  __int64 v1; // x10
  __int64 v2; // x8
  unsigned __int64 v9; // x10

  v1 = *(_QWORD *)(result + 8);
  v2 = 1LL << v1;
  _X9 = (unsigned __int64 *)(*(_QWORD *)(result + 48) + 56LL + 8LL * ((unsigned int)v1 >> 6));
  __asm { PRFM            #0x11, [X9] }
  do
    v9 = __ldxr(_X9);
  while ( __stxr(v9 & ~v2, _X9) );
  return result;
}
