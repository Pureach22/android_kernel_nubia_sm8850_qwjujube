__int64 __fastcall simple_amp_resume(__int64 a1)
{
  if ( *(_QWORD *)(a1 + 152) )
    return 0;
  if ( (unsigned int)__ratelimit(&simple_amp_resume__rs, "simple_amp_resume") )
    dev_err(a1, "%s: simple_amp private data is NULL\n", "simple_amp_resume");
  return 4294967274LL;
}
