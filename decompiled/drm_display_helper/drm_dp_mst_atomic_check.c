__int64 __fastcall drm_dp_mst_atomic_check(__int64 result)
{
  int v1; // w8
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 i; // x21
  __int64 v5; // x9
  __int64 v6; // x1
  _QWORD v7[2]; // [xsp+0h] [xbp-10h] BYREF

  v7[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_DWORD *)(result + 56);
  if ( v1 >= 1 )
  {
    v2 = result;
    v3 = 0;
    for ( i = 0; i < v1; ++i )
    {
      v5 = *(_QWORD *)(v2 + 64);
      v6 = *(_QWORD *)(v5 + v3);
      if ( *(__int64 (__fastcall ***)())(v6 + 96) == drm_dp_mst_topology_state_funcs )
      {
        result = drm_dp_mst_atomic_check_mgr(result, v6, *(_QWORD *)(v5 + v3 + 24), v7);
        if ( (_DWORD)result )
          goto LABEL_8;
        v1 = *(_DWORD *)(v2 + 56);
      }
      v3 += 32;
    }
  }
  result = 0;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
