bool __fastcall hif_max_num_receives_reached(__int64 a1, unsigned int a2)
{
  unsigned int v2; // w8

  if ( !a1 )
    return a2 > 0x400;
  if ( *(_DWORD *)(a1 + 2552) == 8 )
    v2 = 120;
  else
    v2 = 1024;
  return v2 < a2;
}
