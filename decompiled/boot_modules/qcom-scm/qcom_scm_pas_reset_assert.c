__int64 __fastcall qcom_scm_pas_reset_assert(__int64 a1, __int64 a2)
{
  if ( a2 )
    return 4294967274LL;
  else
    return _qcom_scm_pas_mss_reset(1);
}
