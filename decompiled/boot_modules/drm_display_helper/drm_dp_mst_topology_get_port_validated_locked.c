__int64 __fastcall drm_dp_mst_topology_get_port_validated_locked(__int64 a1, _QWORD *a2)
{
  _QWORD *v2; // x19
  _QWORD *v3; // x21
  __int64 result; // x0
  __int64 v6; // x0

  v2 = (_QWORD *)(a1 + 40);
  v3 = *(_QWORD **)(a1 + 40);
  if ( v3 == (_QWORD *)(a1 + 40) )
    return 0;
  while ( 1 )
  {
    result = (__int64)(v3 - 3);
    if ( v3 - 3 == a2 )
      break;
    v6 = v3[2];
    if ( v6 )
    {
      result = drm_dp_mst_topology_get_port_validated_locked(v6, a2);
      if ( result )
        break;
    }
    v3 = (_QWORD *)*v3;
    if ( v3 == v2 )
      return 0;
  }
  return result;
}
