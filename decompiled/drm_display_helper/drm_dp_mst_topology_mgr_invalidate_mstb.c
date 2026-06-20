__int64 __fastcall drm_dp_mst_topology_mgr_invalidate_mstb(__int64 result)
{
  _QWORD *v1; // x19
  _QWORD *v2; // x20

  v1 = (_QWORD *)(result + 40);
  v2 = *(_QWORD **)(result + 40);
  *(_BYTE *)(result + 72) = 0;
  if ( v2 != (_QWORD *)(result + 40) )
  {
    do
    {
      result = v2[2];
      if ( result )
        result = drm_dp_mst_topology_mgr_invalidate_mstb();
      v2 = (_QWORD *)*v2;
    }
    while ( v2 != v1 );
  }
  return result;
}
