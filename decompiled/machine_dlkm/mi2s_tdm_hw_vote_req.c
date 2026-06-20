__int64 __fastcall mi2s_tdm_hw_vote_req(__int64 a1, int a2, __int64 a3)
{
  __int64 result; // x0
  unsigned int v5; // w19
  unsigned int v7; // w8
  unsigned int v13; // w9

  if ( !a1 || !*(_QWORD *)(a1 + 616) )
  {
    printk(&unk_128BB, "mi2s_tdm_hw_vote_req", a3);
    return 4294967274LL;
  }
  _X19 = (unsigned int *)(a1 + 612);
  if ( a2 )
  {
    if ( *(_DWORD *)(a1 + 612) )
    {
      result = 0;
    }
    else
    {
      result = digital_cdc_rsc_mgr_hw_vote_enable(*(_QWORD *)(a1 + 616), 0);
      if ( (result & 0x80000000) != 0 )
      {
        v5 = result;
        printk(&unk_13B69, "mi2s_tdm_hw_vote_req", (unsigned int)result);
        return v5;
      }
    }
    __asm { PRFM            #0x11, [X19] }
    do
      v7 = __ldxr(_X19);
    while ( __stxr(v7 + 1, _X19) );
  }
  else
  {
    __asm { PRFM            #0x11, [X19] }
    do
      v13 = __ldxr(_X19);
    while ( __stxr(v13 - 1, _X19) );
    if ( *(_DWORD *)(a1 + 612) )
    {
      if ( (*(_DWORD *)(a1 + 612) & 0x80000000) != 0 )
        *(_DWORD *)(a1 + 612) = 0;
      return 0;
    }
    else
    {
      digital_cdc_rsc_mgr_hw_vote_disable(*(_QWORD *)(a1 + 616), 0);
      return 0;
    }
  }
  return result;
}
