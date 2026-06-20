__int64 __fastcall drm_dp_mst_link_probe_work(__int64 a1)
{
  __int64 v1; // x24
  __int64 v2; // x20
  __int64 v4; // x19
  __int64 v5; // x23
  char v6; // w25
  unsigned int v8; // w8
  unsigned int v9; // w26
  unsigned int v15; // w9
  _QWORD *v16; // x22
  __int64 v17; // x8
  __int64 v18; // x1
  __int64 v19; // x1
  __int64 v20; // x23
  __int64 v21; // x1
  int v22; // w22
  __int64 result; // x0
  _QWORD v24[16]; // [xsp+0h] [xbp-80h] BYREF

  v1 = a1 - 920;
  v2 = a1 - 176;
  v24[15] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 - 920);
  mutex_lock(a1 - 176);
  v5 = a1 - 224;
  mutex_lock(a1 - 224);
  v6 = *(_BYTE *)(a1 - 128);
  _X21 = *(unsigned int **)(a1 - 120);
  *(_BYTE *)(a1 - 128) = v6 | 2;
  if ( !_X21 )
    goto LABEL_31;
  v8 = *_X21;
  if ( *_X21 )
  {
    do
    {
      __asm { PRFM            #0x11, [X21] }
      do
        v15 = __ldxr(_X21);
      while ( v15 == v8 && __stxr(v8 + 1, _X21) );
      v9 = v8;
      if ( v15 == v8 )
        break;
      v9 = 0;
      v8 = v15;
    }
    while ( v15 );
  }
  else
  {
    v9 = 0;
  }
  if ( (((v9 + 1) | v9) & 0x80000000) != 0 )
  {
    refcount_warn_saturate(_X21, 0);
    if ( v9 )
      goto LABEL_13;
LABEL_31:
    mutex_unlock(a1 - 224);
    result = mutex_unlock(v2);
    goto LABEL_32;
  }
  if ( !v9 )
    goto LABEL_31;
LABEL_13:
  v16 = (_QWORD *)(a1 - 1024);
  v17 = *(_QWORD *)(*((_QWORD *)_X21 + 8) + 104LL);
  if ( v17 )
    v18 = *(_QWORD *)(v17 + 8);
  else
    v18 = 0;
  _drm_dev_dbg(0, v18, 1, "mstb %p (%d)\n", _X21, *_X21);
  mutex_unlock(v5);
  if ( (v6 & 2) == 0 )
  {
    v19 = v4 ? *(_QWORD *)(v4 + 8) : 0LL;
    _drm_dev_dbg(0, v19, 2, "Clearing payload ID table\n");
    v20 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 768);
    if ( v20 )
    {
      *(_QWORD *)(v20 + 312) = _X21;
      memset(&v24[1], 0, 112);
      v24[0] = 20;
      ((void (__fastcall *)(_QWORD *, __int64))drm_dp_encode_sideband_req)(v24, v20);
      *(_BYTE *)(v20 + 344) = 1;
      drm_dp_queue_down_tx(v16, v20);
      if ( (int)drm_dp_mst_wait_tx_reply((__int64)_X21, v20) >= 1 && *(_BYTE *)(v20 + 346) == 1 )
      {
        if ( *(_QWORD *)v1 )
          v21 = *(_QWORD *)(*(_QWORD *)v1 + 8LL);
        else
          v21 = 0;
        _drm_dev_dbg(0, v21, 2, "clear payload table id nak received\n");
      }
      kfree(v20);
    }
  }
  v22 = drm_dp_check_and_send_link_address(v16, _X21);
  drm_dp_mst_topology_put_mstb(_X21);
  result = mutex_unlock(v2);
  if ( v22 >= 1 )
    result = drm_kms_helper_hotplug_event(v4);
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
