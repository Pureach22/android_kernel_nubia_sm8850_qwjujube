__int64 __fastcall sub_64B4(__int64 a1, __int64 a2, __int64 a3)
{
  char v3; // cf
  __int64 v4; // x9
  __int64 v5; // x1

  if ( v3 )
    v5 = -a3;
  else
    v5 = v4;
  return qcom_mpam_get_bw_limit(a1, v5);
}
