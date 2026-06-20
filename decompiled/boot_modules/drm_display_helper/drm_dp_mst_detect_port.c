__int64 __fastcall drm_dp_mst_detect_port(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v8; // x0
  unsigned int *port_validated_locked; // x0
  unsigned int v10; // w8
  unsigned int v12; // w23
  unsigned int v18; // w9
  __int64 v19; // x8
  __int64 v20; // x1
  int v21; // w0
  int v22; // w8
  unsigned int v23; // w20
  __int64 ddc; // x8

  mutex_lock(a3 + 800);
  v8 = *(_QWORD *)(a3 + 904);
  if ( v8 )
  {
    port_validated_locked = (unsigned int *)drm_dp_mst_topology_get_port_validated_locked(v8, a4);
    if ( port_validated_locked )
    {
      v10 = *port_validated_locked;
      _X19 = port_validated_locked;
      if ( *port_validated_locked )
      {
        do
        {
          __asm { PRFM            #0x11, [X19] }
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
          goto LABEL_14;
      }
      else if ( v12 )
      {
LABEL_14:
        v19 = *(_QWORD *)(*((_QWORD *)_X19 + 204) + 104LL);
        if ( v19 )
          v20 = *(_QWORD *)(v19 + 8);
        else
          v20 = 0;
        _drm_dev_dbg(0, v20, 1, "port %p (%d)\n", _X19, *_X19);
        mutex_unlock(a3 + 800);
        v21 = drm_modeset_lock(a3 + 16, a2);
        if ( v21 )
          goto LABEL_26;
        if ( *((_BYTE *)_X19 + 11) != 1 )
          goto LABEL_25;
        v22 = *((unsigned __int8 *)_X19 + 12);
        switch ( v22 )
        {
          case 4:
            if ( *((_BYTE *)_X19 + 13) )
              v21 = 1;
            else
              v21 = 2;
            break;
          case 3:
            if ( *((unsigned __int8 *)_X19 + 8) < 8u || *((_QWORD *)_X19 + 205) )
            {
              v21 = 1;
            }
            else
            {
              ddc = drm_edid_read_ddc(a1, _X19 + 14);
              v21 = 1;
              *((_QWORD *)_X19 + 205) = ddc;
            }
            break;
          case 2:
            if ( *((_BYTE *)_X19 + 10) )
              v21 = 2;
            else
              v21 = 1;
            break;
          default:
LABEL_25:
            v21 = 2;
            break;
        }
LABEL_26:
        v23 = v21;
        drm_dp_mst_topology_put_port(_X19);
        return v23;
      }
    }
  }
  mutex_unlock(a3 + 800);
  return 2;
}
