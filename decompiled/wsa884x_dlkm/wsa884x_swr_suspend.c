__int64 __fastcall wsa884x_swr_suspend(__int64 a1)
{
  __int64 v1; // x19
  __int64 v4; // x8
  unsigned __int64 v11; // x9

  if ( a1 && a1 != 72 && (v1 = *(_QWORD *)(a1 + 152)) != 0 )
  {
    if ( (*(_BYTE *)(v1 + 37) & 1) != 0 || (v4 = *(_QWORD *)(v1 + 24)) != 0 && !*(_DWORD *)(v4 + 208) )
    {
      msm_cdc_set_supplies_lpm_mode();
      _X8 = (unsigned __int64 *)(v1 + 680);
      __asm { PRFM            #0x11, [X8] }
      do
        v11 = __ldxr(_X8);
      while ( __stxr(v11 | 2, _X8) );
    }
    return 0;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&wsa884x_swr_suspend__rs, "wsa884x_swr_suspend") )
      dev_err(a1, "%s: wsa884x private data is NULL\n", "wsa884x_swr_suspend");
    return 4294967274LL;
  }
}
