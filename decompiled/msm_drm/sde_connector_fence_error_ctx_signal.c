__int64 __fastcall sde_connector_fence_error_ctx_signal(__int64 result, int a2, char a3)
{
  __int64 v3; // x19
  int v4; // w2
  __int64 v5; // x0
  __int64 v6; // x0

  if ( result && (*(_BYTE *)(result + 5129) & 1) == 0 )
  {
    v3 = *(_QWORD *)(result + 2864);
    if ( (a3 & 1) != 0 )
      v4 = 3;
    else
      v4 = 2;
    v5 = sde_fence_error_ctx_update(*(_QWORD *)(result + 2864), a2, v4);
    v6 = ktime_get(v5);
    sde_fence_signal(v3, v6, 0, 0);
    return sde_fence_error_ctx_update(v3, 0, 0);
  }
  return result;
}
