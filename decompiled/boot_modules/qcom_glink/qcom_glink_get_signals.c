__int64 __fastcall qcom_glink_get_signals(__int64 result)
{
  if ( result )
    return *(unsigned int *)(result + 440);
  return result;
}
