__int64 __fastcall drm_dp_mst_port_downstream_of_parent(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x21
  __int64 port_validated_locked; // x0
  __int64 v8; // x22
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x9
  unsigned int v13; // w20

  mutex_lock(a1 + 800);
  v6 = *(_QWORD *)(a1 + 904);
  if ( v6 )
  {
    port_validated_locked = drm_dp_mst_topology_get_port_validated_locked(*(_QWORD *)(a1 + 904), a2);
    if ( port_validated_locked )
    {
      if ( !a3 )
      {
LABEL_12:
        v13 = 1;
        goto LABEL_11;
      }
      v8 = port_validated_locked;
      v9 = drm_dp_mst_topology_get_port_validated_locked(v6, a3);
      if ( v9 )
      {
        v10 = *(_QWORD *)(v9 + 40);
        if ( v10 )
        {
          v11 = v8;
          do
          {
            v12 = *(_QWORD *)(v11 + 1616);
            if ( !v12 )
              break;
            if ( v12 == v10 )
              goto LABEL_12;
            v11 = *(_QWORD *)(v12 + 56);
          }
          while ( v11 );
        }
      }
    }
  }
  v13 = 0;
LABEL_11:
  mutex_unlock(a1 + 800);
  return v13;
}
