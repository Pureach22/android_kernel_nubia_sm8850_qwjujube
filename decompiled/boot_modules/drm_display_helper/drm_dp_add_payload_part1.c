__int64 __fastcall drm_dp_add_payload_part1(__int64 a1, __int64 a2, const void **a3)
{
  char v5; // w8
  char v6; // w9
  const void *v7; // x21
  __int64 v8; // x0
  unsigned int *port_validated_locked; // x0
  unsigned int v10; // w8
  unsigned int v12; // w22
  unsigned int v18; // w9
  __int64 v19; // x8
  __int64 v20; // x1
  unsigned int v21; // w0
  unsigned int v22; // w20
  __int64 v23; // x8
  __int64 v24; // x1
  __int64 v26; // x8
  __int64 v27; // x1

  if ( *(_BYTE *)(a1 + 897) )
  {
    v5 = *(_BYTE *)(a1 + 898);
  }
  else
  {
    v5 = *(_BYTE *)(a2 + 73);
    *(_BYTE *)(a1 + 898) = v5;
  }
  *((_BYTE *)a3 + 8) = v5;
  v6 = *(_BYTE *)(a1 + 898);
  ++*(_BYTE *)(a1 + 897);
  *(_BYTE *)(a1 + 898) = v6 + *((_BYTE *)a3 + 12);
  v7 = *a3;
  *((_DWORD *)a3 + 6) = 1;
  mutex_lock(a1 + 800);
  v8 = *(_QWORD *)(a1 + 904);
  if ( v8 )
  {
    port_validated_locked = (unsigned int *)drm_dp_mst_topology_get_port_validated_locked(v8, v7);
    if ( port_validated_locked )
    {
      v10 = *port_validated_locked;
      _X21 = port_validated_locked;
      if ( *port_validated_locked )
      {
        do
        {
          __asm { PRFM            #0x11, [X21] }
          do
            v18 = __ldxr(port_validated_locked);
          while ( v18 == v10 && __stxr(v10 + 1, port_validated_locked) );
          v12 = v10;
          if ( v18 == v10 )
            break;
          v12 = 0;
          v10 = v18;
        }
        while ( v18 );
      }
      else
      {
        v12 = 0;
      }
      if ( (((v12 + 1) | v12) & 0x80000000) != 0 )
      {
        refcount_warn_saturate(port_validated_locked, 0);
        if ( v12 )
          goto LABEL_17;
      }
      else if ( v12 )
      {
LABEL_17:
        v19 = *(_QWORD *)(*((_QWORD *)_X21 + 204) + 104LL);
        if ( v19 )
          v20 = *(_QWORD *)(v19 + 8);
        else
          v20 = 0;
        _drm_dev_dbg(0, v20, 1, "port %p (%d)\n", _X21, *_X21);
        mutex_unlock(a1 + 800);
        v21 = drm_dp_dpcd_write_payload(
                a1,
                *((unsigned __int8 *)a3 + 9),
                *((unsigned __int8 *)a3 + 8),
                *((unsigned int *)a3 + 3));
        if ( (v21 & 0x80000000) != 0 )
        {
          v23 = *(_QWORD *)(a1 + 104);
          if ( v23 )
          {
            v24 = *(_QWORD *)(v23 + 8);
            v22 = v21;
          }
          else
          {
            v22 = v21;
            v24 = 0;
          }
          _drm_dev_dbg(0, v24, 2, "Failed to create MST payload for port %p: %d\n", *a3, v22);
        }
        else
        {
          v22 = v21;
          *((_DWORD *)a3 + 6) = 2;
        }
        drm_dp_mst_topology_put_port(_X21);
        return v22;
      }
    }
  }
  mutex_unlock(a1 + 800);
  v26 = *(_QWORD *)(a1 + 104);
  if ( v26 )
    v27 = *(_QWORD *)(v26 + 8);
  else
    v27 = 0;
  _drm_dev_dbg(
    0,
    v27,
    2,
    "VCPI %d for port %p not in topology, not creating a payload to remote\n",
    *((unsigned __int8 *)a3 + 9),
    *a3);
  return 4294967291LL;
}
