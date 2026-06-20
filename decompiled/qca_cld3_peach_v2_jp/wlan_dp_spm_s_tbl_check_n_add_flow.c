__int64 __fastcall wlan_dp_spm_s_tbl_check_n_add_flow(__int64 a1, __int64 a2, int a3)
{
  __int64 result; // x0
  unsigned __int64 v7; // x8
  unsigned __int64 v13; // x8
  unsigned __int64 v15; // x9
  unsigned __int64 v17; // x9

  _X19 = a2;
  result = sched_clock(a1, a2);
  __asm { PRFM            #0x11, [X19] }
  do
    v13 = __ldxr((unsigned __int64 *)_X19);
  while ( __stlxr(v13 | 1, (unsigned __int64 *)_X19) );
  __dmb(0xBu);
  if ( (v13 & 1) == 0 )
  {
    if ( *(_DWORD *)(_X19 + 8) )
    {
      v7 = result - *(_QWORD *)(_X19 + 16);
      if ( v7 < 0xBEBC201 || 1000000000 * (unsigned __int64)*(unsigned int *)(_X19 + 12) / v7 > 9 )
      {
        __asm { PRFM            #0x11, [X19] }
        do
          v15 = __ldxr((unsigned __int64 *)_X19);
        while ( __stxr(v15 & 0xFFFFFFFFFFFFFFFELL, (unsigned __int64 *)_X19) );
        return result;
      }
      --*(_DWORD *)(a1 + 6144);
    }
    *(_QWORD *)(_X19 + 16) = result;
    *(_DWORD *)(_X19 + 8) = a3;
    *(_DWORD *)(_X19 + 12) = 1;
    ++*(_DWORD *)(a1 + 6144);
    if ( *(_DWORD *)(_X19 + 8) == a3 )
    {
      __asm { PRFM            #0x11, [X19] }
      do
        v17 = __ldxr((unsigned __int64 *)_X19);
      while ( __stxr(v17 & 0xFFFFFFFFFFFFFFFELL, (unsigned __int64 *)_X19) );
    }
  }
  return result;
}
