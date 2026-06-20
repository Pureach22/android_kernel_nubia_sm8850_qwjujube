__int64 __fastcall ipcmem_tx_avail(__int64 a1)
{
  unsigned int v1; // w8
  unsigned int v2; // w9
  bool v3; // cf
  unsigned int v4; // w8
  unsigned int v5; // w8

  v1 = **(_DWORD **)(a1 + 16);
  v2 = **(_DWORD **)(a1 + 8);
  v3 = v2 >= v1;
  v4 = v2 - v1;
  if ( v4 == 0 || !v3 )
    v4 += *(_DWORD *)a1;
  v3 = v4 >= 8;
  v5 = v4 - 8;
  if ( !v3 )
    v5 = 0;
  if ( v5 <= *(_DWORD *)a1 )
    return v5;
  __break(0x800u);
  return 0;
}
