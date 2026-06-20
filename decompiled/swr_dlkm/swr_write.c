__int64 __fastcall swr_write(__int64 a1, unsigned int a2)
{
  __int64 v3; // x0
  __int64 v5; // x1
  __int64 (__fastcall *v7)(__int64, __int64); // x8

  v3 = *(_QWORD *)(a1 + 32);
  if ( !v3 )
    return 4294967274LL;
  v5 = *(unsigned __int8 *)(a1 + 992);
  if ( *(_BYTE *)(a1 + 992) )
  {
    if ( *(unsigned __int8 *)(v3 + 8411) != (unsigned __int8)a2 )
    {
      if ( *(_BYTE *)(v3 + 8411) )
        return 0;
      *(_BYTE *)(v3 + 8411) = a2;
      v5 = *(unsigned __int8 *)(a1 + 992);
    }
  }
  else
  {
    v5 = a2;
  }
  v7 = *(__int64 (__fastcall **)(__int64, __int64))(v3 + 8440);
  if ( *((_DWORD *)v7 - 1) != 2126588657 )
    __break(0x8228u);
  return v7(v3, v5);
}
