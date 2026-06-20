__int64 __fastcall sme_init_chan_list(__int64 a1, __int64 a2)
{
  __int64 v2; // x8

  if ( (_DWORD)a2 == 4 )
  {
    v2 = *(_QWORD *)(a1 + 8);
    if ( *(_BYTE *)(v2 + 3225) == 1 )
      *(_BYTE *)(v2 + 1062) = 0;
  }
  return csr_init_chan_list(a1, a2);
}
