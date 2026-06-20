unsigned __int64 __fastcall glink_spss_subdev_start(_QWORD *a1)
{
  unsigned __int64 result; // x0
  unsigned __int64 v3; // x8

  result = qcom_glink_spss_register(a1[7], a1[8]);
  v3 = result;
  if ( result <= 0xFFFFFFFFFFFFF000LL )
    result = 0;
  else
    result = (unsigned int)result;
  a1[9] = v3;
  return result;
}
