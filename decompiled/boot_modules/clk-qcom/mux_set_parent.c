__int64 __fastcall mux_set_parent(__int64 a1, unsigned __int8 a2)
{
  __int64 v2; // x10

  v2 = *(_QWORD *)(a1 - 8);
  if ( v2 )
    a2 = *(_BYTE *)(v2 + 2LL * a2 + 1);
  return regmap_update_bits_base(
           *(_QWORD *)(a1 + 24),
           *(unsigned int *)(a1 - 24),
           (unsigned int)(0xFFFFFFFFFFFFFFFFLL >> -(char)(*(_DWORD *)(a1 - 20) + *(_DWORD *)(a1 - 16)))
         & (unsigned int)(-1LL << *(_DWORD *)(a1 - 20)),
           a2 << *(_DWORD *)(a1 - 20),
           0,
           0,
           0);
}
