__int64 __fastcall cm_prepare_roam_cmd(__int64 a1, __int64 *a2, int a3)
{
  __int64 v5; // x0
  __int64 v6; // x8

  v5 = _qdf_mem_malloc(0x380u, "cm_prepare_roam_cmd", 162);
  *a2 = v5;
  if ( !v5 )
    return 2;
  v6 = v5;
  *(_DWORD *)(v6 + 36) = a3;
  return 0;
}
