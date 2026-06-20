__int64 __fastcall dp_tx_get_link_id_from_ppdu_id_wrapper(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0

  if ( (*(_BYTE *)(a3 + 10) & 8) == 0 || (*(_BYTE *)(*(_QWORD *)(a4 + 24) + 17LL) & 2) == 0 )
    return 0;
  result = (((*(_DWORD *)(a2 + 12) & 0xFFFFFFu) >> *(_BYTE *)(a1 + 20145)) & ~(-1 << *(_BYTE *)(a1 + 20146))) + 1;
  if ( (unsigned __int8)result >= 5u )
  {
    result = 0;
    if ( a3 )
      ++*(_DWORD *)(a3 + 2836);
  }
  return result;
}
