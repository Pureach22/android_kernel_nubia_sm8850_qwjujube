__int64 __fastcall ieee80211_del_station(__int64 a1, __int64 a2, __int64 a3)
{
  if ( *(_QWORD *)a3 )
    return sta_info_destroy_addr_bss(a2 + 2688, *(_QWORD *)a3);
  _sta_info_flush(a2 + 2688, 0, *(unsigned int *)(a3 + 12));
  return 0;
}
