__int64 __fastcall qmp_sdca_dmic_resume(__int64 a1)
{
  if ( a1 && a1 != 72 && *(_QWORD *)(a1 + 152) )
    return 0;
  if ( (unsigned int)__ratelimit(&qmp_sdca_dmic_resume__rs, "qmp_sdca_dmic_resume") )
    dev_err(a1, "%s: qmp private data is NULL\n", "qmp_sdca_dmic_resume");
  return 4294967274LL;
}
