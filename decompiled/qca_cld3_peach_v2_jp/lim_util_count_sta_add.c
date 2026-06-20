__int64 __fastcall lim_util_count_sta_add(__int64 result, _WORD *a2, __int64 a3)
{
  int v3; // w8

  if ( a2 )
  {
    if ( (*a2 & 0x201) == 1 )
    {
      *a2 |= 0x200u;
      v3 = *(unsigned __int16 *)(result + 3994);
      *(_WORD *)(result + 3994) = v3 + 1;
      if ( !v3 && !*(_DWORD *)(*(_QWORD *)(result + 8) + 5456LL) )
        return sch_edca_profile_update(result, a3, 0);
    }
  }
  return result;
}
