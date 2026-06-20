__int64 __fastcall msm_common_get_pdata(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(a1 + 784);
  if ( v1 )
    return *(_QWORD *)(v1 + 8);
  else
    return 0;
}
