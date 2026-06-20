__int64 __fastcall dp_aux_bridge_transfer(__int64 a1, int *a2)
{
  __int64 v3; // x8
  __int64 (__fastcall *v6)(__int64, __int64, int *); // x9
  __int64 v7; // x21

  if ( *(_BYTE *)(a1 + 1576) == 1 )
    return dp_aux_transfer(a1, a2);
  v3 = *(_QWORD *)(a1 + 1560);
  *(_BYTE *)(a1 + 1576) = 1;
  v6 = *(__int64 (__fastcall **)(__int64, __int64, int *))(v3 + 56);
  if ( *((_DWORD *)v6 - 1) != 809469826 )
    __break(0x8229u);
  v7 = v6(v3, a1, a2);
  *(_BYTE *)(a1 + 1576) = 0;
  dp_aux_hex_dump(a1, a2);
  return v7;
}
