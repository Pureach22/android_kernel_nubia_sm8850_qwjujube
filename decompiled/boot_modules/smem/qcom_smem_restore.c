__int64 __fastcall qcom_smem_restore(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // w20

  result = qcom_smem_probe(a1 - 16);
  if ( (_DWORD)result )
  {
    v3 = result;
    dev_err(a1, "Error getting SMEM information\n");
    return v3;
  }
  return result;
}
