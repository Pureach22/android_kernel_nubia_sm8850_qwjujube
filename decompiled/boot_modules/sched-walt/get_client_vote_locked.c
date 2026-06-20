__int64 __fastcall get_client_vote_locked(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, __int64 _X4)
{
  unsigned int v5; // w8

  v5 = -22;
  if ( !a1 || (a2 & 0x80000000) != 0 )
    return v5;
  if ( *(_DWORD *)(a1 + 92) == 2 )
  {
    if ( a2 > 7 )
      goto LABEL_11;
    return *(unsigned int *)(a1 + 8LL * a2 + 28);
  }
  if ( a2 < 8 )
  {
    if ( (*(_BYTE *)(a1 + 8LL * a2 + 24) & 1) == 0 )
      return 4294967274LL;
    return *(unsigned int *)(a1 + 8LL * a2 + 28);
  }
LABEL_11:
  __break(0x5512u);
  __asm { STZG            X4, [X21],#0xFA0 }
  return get_client_vote();
}
