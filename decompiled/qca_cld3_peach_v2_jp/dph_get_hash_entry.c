__int64 __fastcall dph_get_hash_entry(__int64 a1, unsigned __int16 a2, __int64 a3)
{
  __int64 v3; // x10

  if ( *(unsigned __int16 *)(a3 + 16) <= (unsigned int)a2 )
    return 0;
  v3 = *(_QWORD *)(a3 + 8);
  if ( (*(_WORD *)(v3 + 952LL * a2) & 8) != 0 )
    return v3 + 952LL * a2;
  else
    return 0;
}
