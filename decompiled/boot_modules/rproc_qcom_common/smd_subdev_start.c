unsigned __int64 __fastcall smd_subdev_start(_QWORD *a1)
{
  unsigned __int64 result; // x0
  unsigned __int64 v3; // x8

  result = qcom_smd_register_edge(a1[6], a1[7]);
  v3 = result;
  if ( result <= 0xFFFFFFFFFFFFF000LL )
    result = 0;
  else
    result = (unsigned int)result;
  a1[8] = v3;
  return result;
}
