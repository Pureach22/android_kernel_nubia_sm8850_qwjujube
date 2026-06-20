__int64 __fastcall drm_dp_add_payload_part2(__int64 a1, __int64 *a2)
{
  __int64 v4; // x21
  __int64 v5; // x0
  unsigned int v7; // w8
  unsigned int v8; // w22
  unsigned int v14; // w9
  __int64 v15; // x8
  __int64 v16; // x1
  __int64 v18; // x8
  __int64 v19; // x1
  unsigned int *v20; // x21
  unsigned int v21; // w22
  unsigned int *v22; // x21
  __int64 v23; // x9
  __int64 v24; // x0

  if ( *((_DWORD *)a2 + 6) == 2 )
  {
    v4 = *a2;
    mutex_lock(a1 + 800);
    v5 = *(_QWORD *)(a1 + 904);
    if ( v5 )
    {
      _X0 = (unsigned int *)drm_dp_mst_topology_get_port_validated_locked(v5, v4);
      if ( _X0 )
      {
        v7 = *_X0;
        if ( *_X0 )
        {
          do
          {
            __asm { PRFM            #0x11, [X0] }
            do
              v14 = __ldxr(_X0);
            while ( v14 == v7 && __stxr(v7 + 1, _X0) );
            v8 = v7;
            if ( v14 == v7 )
              break;
            v8 = 0;
            v7 = v14;
          }
          while ( v14 );
        }
        else
        {
          v8 = 0;
        }
        if ( (((v8 + 1) | v8) & 0x80000000) != 0 )
        {
          v22 = _X0;
          refcount_warn_saturate(_X0, 0);
          _X0 = v22;
          if ( v8 )
          {
LABEL_19:
            v18 = *(_QWORD *)(*((_QWORD *)_X0 + 204) + 104LL);
            if ( v18 )
              v19 = *(_QWORD *)(v18 + 8);
            else
              v19 = 0;
            v20 = _X0;
            _drm_dev_dbg(0, v19, 1, "port %p (%d)\n", _X0, *_X0);
            mutex_unlock(a1 + 800);
            v21 = drm_dp_payload_send_msg(a1, v20, *((unsigned __int8 *)a2 + 9), *((unsigned int *)a2 + 4));
            drm_dp_mst_topology_put_port(v20);
            if ( (v21 & 0x80000000) == 0 )
            {
              *((_DWORD *)a2 + 6) = 3;
              return 0;
            }
            goto LABEL_26;
          }
        }
        else if ( v8 )
        {
          goto LABEL_19;
        }
      }
    }
    mutex_unlock(a1 + 800);
    v21 = -5;
LABEL_26:
    v23 = *(_QWORD *)(a1 + 104);
    if ( v23 )
      v24 = *(_QWORD *)(v23 + 8);
    else
      v24 = 0;
    dev_err(v24, "[drm] *ERROR* Step 2 of creating MST payload for %p failed: %d\n", (const void *)*a2, v21);
    return v21;
  }
  v15 = *(_QWORD *)(a1 + 104);
  if ( v15 )
    v16 = *(_QWORD *)(v15 + 8);
  else
    v16 = 0;
  _drm_dev_dbg(
    0,
    v16,
    2,
    "Part 1 of payload creation for %s failed, skipping part 2\n",
    *(const char **)(*(_QWORD *)(*a2 + 1624) + 96LL));
  return 4294967291LL;
}
