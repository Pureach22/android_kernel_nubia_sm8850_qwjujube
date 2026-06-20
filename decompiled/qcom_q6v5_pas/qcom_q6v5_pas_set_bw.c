__int64 __fastcall qcom_q6v5_pas_set_bw(_QWORD *a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0

  result = a1[6];
  if ( result )
  {
    result = icc_set_bw(result, a2, a3);
    if ( (result & 0x80000000) != 0 )
    {
      dev_err(*a1, "failed to set crypto_path bandwidth request\n");
      return icc_set_bw(a1[6], 0, 0);
    }
  }
  return result;
}
