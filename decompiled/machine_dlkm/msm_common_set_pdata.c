__int64 __fastcall msm_common_set_pdata(__int64 result, __int64 a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(result + 784);
  if ( v2 )
    *(_QWORD *)(v2 + 8) = a2;
  return result;
}
