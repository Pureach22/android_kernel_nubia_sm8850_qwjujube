__int64 __fastcall drm_dp_mst_aux_for_parent(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x8

  v1 = *(_QWORD *)(a1 + 1616);
  if ( !v1 )
    return 0;
  v2 = *(_QWORD *)(v1 + 56);
  if ( v2 )
    return v2 + 48;
  else
    return 0;
}
