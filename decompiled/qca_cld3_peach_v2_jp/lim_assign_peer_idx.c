__int64 __fastcall lim_assign_peer_idx(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  int v4; // w9

  if ( *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 3207LL) <= (unsigned int)(unsigned __int8)pe_get_current_stas_count(a1) )
    return 0;
  result = *(unsigned __int8 *)(a2 + 7248);
  if ( *(_BYTE *)(a2 + 7248) )
  {
    v4 = *(unsigned __int8 *)(*(_QWORD *)(a2 + 7240) + result);
    *(_BYTE *)(a2 + 7248) = v4;
    if ( !v4 )
      *(_BYTE *)(a2 + 7249) = 0;
    ++*(_WORD *)(a2 + 7250);
  }
  return result;
}
