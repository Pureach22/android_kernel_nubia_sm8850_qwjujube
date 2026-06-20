__int64 __fastcall dp_aux_transfer_debug(__int64 a1, int *a2)
{
  __int64 v2; // x21
  int v5; // w22
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 (*v9)(void); // x8
  __int64 v10; // x21
  __int64 (*v11)(void); // x8

  v2 = a1 - 80;
  mutex_lock(a1 - 80);
  v5 = *(_DWORD *)(a1 + 1608);
  mutex_unlock(v2);
  if ( v5 )
    return -110;
  if ( *(_BYTE *)(a1 + 1577) == 1 )
  {
    v7 = *(_QWORD *)(a1 + 1560);
    if ( !v7 || !*(_QWORD *)(v7 + 56) || *(_BYTE *)(a1 + 1576) == 1 )
      return dp_aux_transfer(a1, a2);
    *(_BYTE *)(a1 + 1576) = 1;
    v11 = *(__int64 (**)(void))(v7 + 56);
    if ( *((_DWORD *)v11 - 1) != 809469826 )
      __break(0x8228u);
    v10 = v11();
    *(_BYTE *)(a1 + 1576) = 0;
  }
  else
  {
    v8 = *(_QWORD *)(a1 + 1568);
    *(_BYTE *)(a1 + 1577) = 1;
    v9 = *(__int64 (**)(void))(v8 + 56);
    if ( *((_DWORD *)v9 - 1) != 809469826 )
      __break(0x8228u);
    v10 = v9();
    *(_BYTE *)(a1 + 1577) = 0;
  }
  dp_aux_hex_dump(a1, (unsigned int *)a2);
  return v10;
}
