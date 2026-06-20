__int64 __fastcall drm_dp_mst_dpcd_read(__int64 a1, int a2, void *a3, int a4)
{
  __int64 v5; // x19
  __int64 v8; // x24
  __int64 v9; // x20
  __int64 v10; // x0
  unsigned int *mstb_validated_locked; // x0
  unsigned int v12; // w8
  unsigned int v14; // w25
  unsigned int v20; // w9
  __int64 v21; // x8
  __int64 v22; // x1
  __int64 v23; // x25
  unsigned __int8 v24; // w8
  int v25; // w0
  __int64 v26; // x8
  __int64 v27; // x1
  size_t v28; // x2
  __int64 result; // x0
  __int64 v30; // [xsp+0h] [xbp-80h] BYREF
  int v31; // [xsp+8h] [xbp-78h]
  int v32; // [xsp+Ch] [xbp-74h]
  __int64 v33; // [xsp+10h] [xbp-70h]
  __int64 v34; // [xsp+18h] [xbp-68h]
  __int64 v35; // [xsp+20h] [xbp-60h]
  __int64 v36; // [xsp+28h] [xbp-58h]
  __int64 v37; // [xsp+30h] [xbp-50h]
  __int64 v38; // [xsp+38h] [xbp-48h]
  __int64 v39; // [xsp+40h] [xbp-40h]
  __int64 v40; // [xsp+48h] [xbp-38h]
  __int64 v41; // [xsp+50h] [xbp-30h]
  __int64 v42; // [xsp+58h] [xbp-28h]
  __int64 v43; // [xsp+60h] [xbp-20h]
  __int64 v44; // [xsp+68h] [xbp-18h]
  __int64 v45; // [xsp+70h] [xbp-10h]
  __int64 v46; // [xsp+78h] [xbp-8h]

  LODWORD(v5) = a4;
  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 1584);
  v9 = *(_QWORD *)(a1 + 1568);
  mutex_lock(v8 + 800);
  v10 = *(_QWORD *)(v8 + 904);
  if ( !v10 )
    goto LABEL_30;
  mstb_validated_locked = (unsigned int *)drm_dp_mst_topology_get_mstb_validated_locked(v10, v9);
  if ( !mstb_validated_locked )
    goto LABEL_30;
  v12 = *mstb_validated_locked;
  _X20 = mstb_validated_locked;
  if ( *mstb_validated_locked )
  {
    do
    {
      __asm { PRFM            #0x11, [X20] }
      do
        v20 = __ldxr(mstb_validated_locked);
      while ( v20 == v12 && __stxr(v12 + 1, mstb_validated_locked) );
      v14 = v12;
      if ( v20 == v12 )
        break;
      v14 = 0;
      v12 = v20;
    }
    while ( v20 );
  }
  else
  {
    v14 = 0;
  }
  if ( (((v14 + 1) | v14) & 0x80000000) != 0 )
  {
    refcount_warn_saturate(mstb_validated_locked, 0);
    if ( v14 )
      goto LABEL_14;
LABEL_30:
    mutex_unlock(v8 + 800);
    result = -22;
    goto LABEL_33;
  }
  if ( !v14 )
    goto LABEL_30;
LABEL_14:
  v21 = *(_QWORD *)(*((_QWORD *)_X20 + 8) + 104LL);
  if ( v21 )
    v22 = *(_QWORD *)(v21 + 8);
  else
    v22 = 0;
  _drm_dev_dbg(0, v22, 1, "mstb %p (%d)\n", _X20, *_X20);
  mutex_unlock(v8 + 800);
  v23 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 768);
  if ( v23 )
  {
    v24 = *(_BYTE *)(a1 - 40);
    v44 = 0;
    v45 = 0;
    v42 = 0;
    v43 = 0;
    v40 = 0;
    v41 = 0;
    v38 = 0;
    v39 = 0;
    v36 = 0;
    v37 = 0;
    v34 = 0;
    v35 = 0;
    v30 = 32;
    v31 = v24;
    v32 = a2;
    v33 = (unsigned __int8)v5;
    ((void (__fastcall *)(__int64 *, __int64))drm_dp_encode_sideband_req)(&v30, v23);
    *(_QWORD *)(v23 + 312) = *(_QWORD *)(a1 + 1568);
    drm_dp_queue_down_tx(v8, v23);
    v25 = drm_dp_mst_wait_tx_reply(_X20, v23);
    if ( v25 < 0 )
    {
      LODWORD(v5) = v25;
    }
    else if ( *(_BYTE *)(v23 + 346) == 1 )
    {
      v26 = *(_QWORD *)(v8 + 104);
      if ( v26 )
        v27 = *(_QWORD *)(v26 + 8);
      else
        v27 = 0;
      _drm_dev_dbg(
        0,
        v27,
        2,
        "mstb %p port %d: DPCD read on addr 0x%x for %d bytes NAKed\n",
        _X20,
        *(unsigned __int8 *)(a1 - 40),
        a2,
        v5);
      LODWORD(v5) = -5;
    }
    else
    {
      v28 = *(unsigned __int8 *)(v23 + 349);
      if ( (_DWORD)v28 == (_DWORD)v5 )
        memcpy(a3, (const void *)(v23 + 350), v28);
      else
        LODWORD(v5) = -71;
    }
    kfree(v23);
    v5 = (int)v5;
  }
  else
  {
    v5 = -12;
  }
  drm_dp_mst_topology_put_mstb(_X20);
  result = v5;
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
