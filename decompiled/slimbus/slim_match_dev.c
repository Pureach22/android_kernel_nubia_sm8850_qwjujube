bool __fastcall slim_match_dev(__int64 a1, unsigned __int8 *a2)
{
  return *(unsigned __int16 *)(a1 + 916) == *((unsigned __int16 *)a2 + 2)
      && *(unsigned __int16 *)(a1 + 914) == *((unsigned __int16 *)a2 + 1)
      && *(unsigned __int8 *)(a1 + 913) == a2[1]
      && *(unsigned __int8 *)(a1 + 912) == *a2;
}
