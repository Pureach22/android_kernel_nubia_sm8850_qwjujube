__int64 __fastcall drm_dp_mst_edid_read(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x0
  unsigned int *port_validated_locked; // x0
  unsigned int v8; // w8
  unsigned int v10; // w22
  unsigned int v16; // w9
  __int64 v17; // x8
  __int64 v18; // x1
  __int64 ddc; // x0
  __int64 v20; // x20

  mutex_lock(a2 + 800);
  v6 = *(_QWORD *)(a2 + 904);
  if ( !v6 )
    goto LABEL_22;
  port_validated_locked = (unsigned int *)drm_dp_mst_topology_get_port_validated_locked(v6, a3);
  if ( !port_validated_locked )
    goto LABEL_22;
  v8 = *port_validated_locked;
  _X19 = port_validated_locked;
  if ( *port_validated_locked )
  {
    do
    {
      __asm { PRFM            #0x11, [X19] }
      do
        v16 = __ldxr(port_validated_locked);
      while ( v16 == v8 && __stxr(v8 + 1, port_validated_locked) );
      v10 = v8;
      if ( v16 == v8 )
        break;
      v10 = 0;
      v8 = v16;
    }
    while ( v16 );
  }
  else
  {
    v10 = 0;
  }
  if ( (((v10 + 1) | v10) & 0x80000000) != 0 )
  {
    refcount_warn_saturate(port_validated_locked, 0);
    if ( v10 )
      goto LABEL_14;
LABEL_22:
    mutex_unlock(a2 + 800);
    return 0;
  }
  if ( !v10 )
    goto LABEL_22;
LABEL_14:
  v17 = *(_QWORD *)(*((_QWORD *)_X19 + 204) + 104LL);
  if ( v17 )
    v18 = *(_QWORD *)(v17 + 8);
  else
    v18 = 0;
  _drm_dev_dbg(0, v18, 1, "port %p (%d)\n", _X19, *_X19);
  mutex_unlock(a2 + 800);
  if ( *((_QWORD *)_X19 + 205) )
    ddc = drm_edid_dup();
  else
    ddc = drm_edid_read_ddc(a1, _X19 + 14);
  v20 = ddc;
  drm_dp_mst_topology_put_port(_X19);
  return v20;
}
