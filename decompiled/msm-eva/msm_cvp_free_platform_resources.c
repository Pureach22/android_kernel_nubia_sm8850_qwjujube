__int64 __fastcall msm_cvp_free_platform_resources(__int64 a1)
{
  int v1; // w8
  unsigned int v3; // w8
  __int64 v4; // x10
  __int64 v5; // x0
  __int64 result; // x0

  v1 = *(_DWORD *)(a1 + 272);
  *(_QWORD *)(a1 + 280) = 0;
  *(_DWORD *)(a1 + 288) = 0;
  if ( v1 )
  {
    v3 = 0;
    do
    {
      v4 = *(_QWORD *)(a1 + 264) + 24LL * (int)v3++;
      *(_QWORD *)(v4 + 16) = 0;
    }
    while ( v3 < *(_DWORD *)(a1 + 272) );
  }
  v5 = *(_QWORD *)(a1 + 296);
  *(_QWORD *)(a1 + 264) = 0;
  *(_DWORD *)(a1 + 272) = 0;
  *(_QWORD *)(a1 + 160) = 0;
  *(_QWORD *)(a1 + 216) = 0;
  *(_QWORD *)(a1 + 232) = 0;
  result = kfree(v5);
  *(_QWORD *)(a1 + 296) = 0;
  *(_DWORD *)(a1 + 304) = 0;
  return result;
}
