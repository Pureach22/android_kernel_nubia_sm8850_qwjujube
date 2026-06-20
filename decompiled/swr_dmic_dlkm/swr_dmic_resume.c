__int64 __fastcall swr_dmic_resume(__int64 a1)
{
  if ( a1 && a1 != 72 && *(_QWORD *)(a1 + 152) )
    return 0;
  if ( (unsigned int)__ratelimit(&swr_dmic_resume__rs, "swr_dmic_resume") )
    dev_err(a1, "%s: swr_dmic private data is NULL\n", "swr_dmic_resume");
  return 4294967274LL;
}
