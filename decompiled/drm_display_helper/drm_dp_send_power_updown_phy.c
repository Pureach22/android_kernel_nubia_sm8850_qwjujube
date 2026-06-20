__int64 __fastcall drm_dp_send_power_updown_phy(__int64 a1, __int64 a2, char a3)
{
  __int64 v6; // x0
  unsigned int *port_validated_locked; // x0
  unsigned int v8; // w8
  unsigned int v10; // w22
  unsigned int v16; // w9
  __int64 v17; // x8
  __int64 v18; // x1
  __int64 v19; // x22
  unsigned __int8 v20; // w9
  unsigned __int8 v21; // w8
  int v22; // w0
  unsigned int v23; // w20
  __int64 result; // x0
  _QWORD v25[16]; // [xsp+0h] [xbp-80h] BYREF

  v25[15] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mutex_lock(a1 + 800);
  v6 = *(_QWORD *)(a1 + 904);
  if ( !v6 )
    goto LABEL_28;
  port_validated_locked = (unsigned int *)drm_dp_mst_topology_get_port_validated_locked(v6, a2);
  if ( !port_validated_locked )
    goto LABEL_28;
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
LABEL_28:
    mutex_unlock(a1 + 800);
    result = 4294967274LL;
    goto LABEL_29;
  }
  if ( !v10 )
    goto LABEL_28;
LABEL_14:
  v17 = *(_QWORD *)(*((_QWORD *)_X19 + 204) + 104LL);
  if ( v17 )
    v18 = *(_QWORD *)(v17 + 8);
  else
    v18 = 0;
  _drm_dev_dbg(0, v18, 1, "port %p (%d)\n", _X19, *_X19);
  mutex_unlock(a1 + 800);
  v19 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 768);
  if ( v19 )
  {
    if ( (a3 & 1) != 0 )
      v20 = 36;
    else
      v20 = 37;
    *(_QWORD *)(v19 + 312) = *((_QWORD *)_X19 + 202);
    v21 = *((_BYTE *)_X19 + 8);
    memset(&v25[2], 0, 104);
    v25[0] = v20;
    v25[1] = v21;
    ((void (__fastcall *)(_QWORD *, __int64))drm_dp_encode_sideband_req)(v25, v19);
    *(_BYTE *)(v19 + 344) = 1;
    drm_dp_queue_down_tx(a1, v19);
    v22 = drm_dp_mst_wait_tx_reply(*((_QWORD *)_X19 + 202), v19);
    if ( v22 < 1 )
    {
      v23 = v22;
    }
    else if ( *(_BYTE *)(v19 + 346) == 1 )
    {
      v23 = -22;
    }
    else
    {
      v23 = 0;
    }
    kfree(v19);
    drm_dp_mst_topology_put_port(_X19);
    result = v23;
  }
  else
  {
    drm_dp_mst_topology_put_port(_X19);
    result = 4294967284LL;
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
