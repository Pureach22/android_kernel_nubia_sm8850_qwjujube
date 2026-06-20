__int64 __fastcall wsa883x_swr_suspend(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x8
  unsigned __int64 v10; // x9

  if ( a1 && a1 != 72 && (v1 = *(_QWORD *)(a1 + 152)) != 0 )
  {
    if ( (*(_BYTE *)(v1 + 35) & 1) != 0 || (v2 = *(_QWORD *)(v1 + 24)) != 0 && !*(_DWORD *)(v2 + 208) )
    {
      msm_cdc_set_supplies_lpm_mode();
      _X8 = (unsigned __int64 *)(v1 + 376);
      __asm { PRFM            #0x11, [X8] }
      do
        v10 = __ldxr(_X8);
      while ( __stxr(v10 | 2, _X8) );
    }
    return 0;
  }
  else
  {
    dev_err(a1, "%s: wsa883x private data is NULL\n", "wsa883x_swr_suspend");
    return 4294967274LL;
  }
}
