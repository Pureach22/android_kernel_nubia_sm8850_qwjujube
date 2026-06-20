__int64 __fastcall dp_mon_filter_set_status_cmn(__int64 result, __int64 a2)
{
  unsigned __int64 v2; // x9
  unsigned __int64 v3; // x8

  v2 = *(_QWORD *)(a2 + 4) & 0xFFFF0000FFFF2020LL | 0xFFFF00005F81LL;
  *(_QWORD *)(a2 + 12) |= 0xFFFF0000FFFFuLL;
  *(_QWORD *)(a2 + 4) = v2 & 0xFFFFFFFFFFDF7FA1LL;
  if ( (*(_BYTE *)(result + 37072) & 2) != 0 )
  {
    *(_QWORD *)(a2 + 12) = -1;
    v3 = v2 & 0xFFFFFFDE7FA1LL | 0xFFFF000000010000LL;
  }
  else
  {
    v3 = v2 & 0xFFFFFFFFFFDE7FA1LL;
  }
  *(_QWORD *)(a2 + 4) = v3;
  return result;
}
