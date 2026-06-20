__int64 __fastcall wsa884x_swr_resume(__int64 a1)
{
  __int64 v1; // x19
  unsigned __int64 v9; // x10

  if ( a1 && a1 != 72 && (v1 = *(_QWORD *)(a1 + 152)) != 0 )
  {
    if ( (*(_QWORD *)(v1 + 680) & 2) != 0 )
    {
      msm_cdc_set_supplies_lpm_mode();
      _X8 = (unsigned __int64 *)(v1 + 680);
      __asm { PRFM            #0x11, [X8] }
      do
        v9 = __ldxr(_X8);
      while ( __stxr(v9 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
    }
    return 0;
  }
  else
  {
    dev_err(a1, "%s: wsa884x private data is NULL\n", "wsa884x_swr_resume");
    return 4294967274LL;
  }
}
