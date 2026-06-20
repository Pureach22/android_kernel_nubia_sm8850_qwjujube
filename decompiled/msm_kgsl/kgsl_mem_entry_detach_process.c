__int64 __fastcall kgsl_mem_entry_detach_process(__int64 a1)
{
  __int64 v2; // x8
  void (__fastcall *v3)(_QWORD); // x8
  int v4; // w8
  __int64 result; // x0
  unsigned int v12; // w10

  raw_spin_lock(*(_QWORD *)(a1 + 256) + 32LL);
  if ( *(_DWORD *)(a1 + 248) )
    idr_remove(*(_QWORD *)(a1 + 256) + 40LL);
  v2 = *(_QWORD *)(a1 + 256);
  *(_DWORD *)(a1 + 248) = 0;
  raw_spin_unlock(v2 + 32);
  v3 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 72) + 40LL);
  if ( v3 )
  {
    if ( *((_DWORD *)v3 - 1) != 1555154090 )
      __break(0x8228u);
    v3(a1 + 8);
  }
  if ( (*(_DWORD *)(a1 + 56) & 0x800) != 0 )
  {
    v4 = *(_DWORD *)(a1 + 112);
    _X9 = (unsigned int *)(*(_QWORD *)(a1 + 256) + 400LL);
    __asm { PRFM            #0x11, [X9] }
    do
      v12 = __ldxr(_X9);
    while ( __stxr(v12 - v4, _X9) );
  }
  result = kgsl_process_private_put(*(_QWORD *)(a1 + 256));
  *(_QWORD *)(a1 + 256) = 0;
  return result;
}
