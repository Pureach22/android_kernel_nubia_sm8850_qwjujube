__int64 __fastcall msm_cvp_deinit_clocks(__int64 result)
{
  __int64 v1; // x8
  unsigned __int64 v2; // x10
  unsigned __int64 v3; // x20
  __int64 v4; // x19

  v1 = *(_QWORD *)(result + 2208);
  *(_DWORD *)(result + 24) = 0;
  v2 = *(_QWORD *)(v1 + 280);
  v3 = v2 + 32LL * (unsigned int)(*(_DWORD *)(v1 + 288) - 1);
  if ( v3 >= v2 )
  {
    v4 = result;
    do
    {
      result = *(_QWORD *)(v3 + 16);
      if ( result )
      {
        result = clk_put(result);
        *(_QWORD *)(v3 + 16) = 0;
        v1 = *(_QWORD *)(v4 + 2208);
      }
      v3 -= 32LL;
    }
    while ( v3 >= *(_QWORD *)(v1 + 280) );
  }
  return result;
}
