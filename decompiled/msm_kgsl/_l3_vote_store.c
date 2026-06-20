__int64 __fastcall l3_vote_store(__int64 a1, char a2)
{
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 33LL) & 0x20) != 0 )
    *(_BYTE *)(a1 + 13416) = a2 & 1;
  return 0;
}
