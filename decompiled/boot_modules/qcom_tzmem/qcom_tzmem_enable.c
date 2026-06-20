__int64 __fastcall qcom_tzmem_enable(__int64 a1)
{
  if ( qcom_tzmem_dev )
    return 4294967280LL;
  qcom_tzmem_dev = a1;
  return 0;
}
