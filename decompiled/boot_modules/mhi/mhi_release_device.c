__int64 __fastcall mhi_release_device(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x8

  v1 = *(_QWORD *)(a1 - 16);
  if ( v1 )
    *(_QWORD *)(v1 + 272) = 0;
  v2 = *(_QWORD *)(a1 - 8);
  if ( v2 )
    *(_QWORD *)(v2 + 272) = 0;
  return kfree(a1 - 40);
}
