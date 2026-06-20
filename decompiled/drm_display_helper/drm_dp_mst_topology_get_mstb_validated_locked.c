__int64 __fastcall drm_dp_mst_topology_get_mstb_validated_locked(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  _QWORD *v3; // x19
  _QWORD *v4; // x21
  __int64 v6; // x0
  __int64 mstb_validated_locked; // x0

  v2 = a1;
  if ( a2 != a1 )
  {
    v3 = (_QWORD *)(a1 + 40);
    v4 = *(_QWORD **)(a1 + 40);
    if ( v4 == (_QWORD *)(a1 + 40) )
    {
      return 0;
    }
    else
    {
      while ( 1 )
      {
        v6 = v4[2];
        if ( v6 )
        {
          mstb_validated_locked = drm_dp_mst_topology_get_mstb_validated_locked(v6, a2);
          if ( mstb_validated_locked )
            break;
        }
        v4 = (_QWORD *)*v4;
        if ( v4 == v3 )
          return 0;
      }
      return mstb_validated_locked;
    }
  }
  return v2;
}
