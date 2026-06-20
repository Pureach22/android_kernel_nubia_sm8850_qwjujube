__int64 __fastcall glink_smem_tx_avail(__int64 a1)
{
  unsigned int v1; // w8
  unsigned int v2; // w9
  bool v3; // cf
  unsigned int v4; // w8
  unsigned __int64 v5; // x8

  v1 = **(_DWORD **)(a1 + 56);
  v2 = **(_DWORD **)(a1 + 48);
  v3 = v2 >= v1;
  v4 = v2 - v1;
  if ( v4 == 0 || !v3 )
    v4 += *(_QWORD *)a1;
  v3 = v4 >= 0x10;
  LODWORD(v5) = v4 - 16;
  if ( v3 )
    v5 = (unsigned int)v5;
  else
    v5 = 0;
  if ( *(_QWORD *)a1 >= v5 )
    return (unsigned int)v5;
  __break(0x800u);
  return 0;
}
