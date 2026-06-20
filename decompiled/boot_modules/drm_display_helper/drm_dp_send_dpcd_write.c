__int64 __fastcall drm_dp_send_dpcd_write(__int64 a1, __int64 a2, int a3, unsigned int a4, __int64 a5)
{
  __int64 v10; // x20
  __int64 v11; // x0
  unsigned int *mstb_validated_locked; // x0
  unsigned int v13; // w8
  unsigned int v15; // w25
  unsigned int v21; // w9
  __int64 v22; // x8
  __int64 v23; // x1
  __int64 v24; // x25
  unsigned __int8 v25; // w8
  int v26; // w0
  __int64 result; // x0
  __int64 v28; // [xsp+0h] [xbp-80h] BYREF
  int v29; // [xsp+8h] [xbp-78h]
  int v30; // [xsp+Ch] [xbp-74h]
  __int64 v31; // [xsp+10h] [xbp-70h]
  __int64 v32; // [xsp+18h] [xbp-68h]
  __int64 v33; // [xsp+20h] [xbp-60h]
  __int64 v34; // [xsp+28h] [xbp-58h]
  __int64 v35; // [xsp+30h] [xbp-50h]
  __int64 v36; // [xsp+38h] [xbp-48h]
  __int64 v37; // [xsp+40h] [xbp-40h]
  __int64 v38; // [xsp+48h] [xbp-38h]
  __int64 v39; // [xsp+50h] [xbp-30h]
  __int64 v40; // [xsp+58h] [xbp-28h]
  __int64 v41; // [xsp+60h] [xbp-20h]
  __int64 v42; // [xsp+68h] [xbp-18h]
  __int64 v43; // [xsp+70h] [xbp-10h]
  __int64 v44; // [xsp+78h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a2 + 1616);
  mutex_lock(a1 + 800);
  v11 = *(_QWORD *)(a1 + 904);
  if ( !v11 )
    goto LABEL_25;
  mstb_validated_locked = (unsigned int *)drm_dp_mst_topology_get_mstb_validated_locked(v11, v10);
  if ( !mstb_validated_locked )
    goto LABEL_25;
  v13 = *mstb_validated_locked;
  _X20 = mstb_validated_locked;
  if ( *mstb_validated_locked )
  {
    do
    {
      __asm { PRFM            #0x11, [X20] }
      do
        v21 = __ldxr(mstb_validated_locked);
      while ( v21 == v13 && __stxr(v13 + 1, mstb_validated_locked) );
      v15 = v13;
      if ( v21 == v13 )
        break;
      v15 = 0;
      v13 = v21;
    }
    while ( v21 );
  }
  else
  {
    v15 = 0;
  }
  if ( (((v15 + 1) | v15) & 0x80000000) != 0 )
  {
    refcount_warn_saturate(mstb_validated_locked, 0);
    if ( v15 )
      goto LABEL_14;
LABEL_25:
    mutex_unlock(a1 + 800);
    result = 4294967274LL;
    goto LABEL_28;
  }
  if ( !v15 )
    goto LABEL_25;
LABEL_14:
  v22 = *(_QWORD *)(*((_QWORD *)_X20 + 8) + 104LL);
  if ( v22 )
    v23 = *(_QWORD *)(v22 + 8);
  else
    v23 = 0;
  _drm_dev_dbg(0, v23, 1, "mstb %p (%d)\n", _X20, *_X20);
  mutex_unlock(a1 + 800);
  v24 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 768);
  if ( v24 )
  {
    v25 = *(_BYTE *)(a2 + 8);
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
    v32 = a5;
    v33 = 0;
    v28 = 33;
    v29 = v25;
    v30 = a3;
    v31 = (unsigned __int8)a4;
    ((void (__fastcall *)(__int64 *, __int64))drm_dp_encode_sideband_req)(&v28, v24);
    *(_QWORD *)(v24 + 312) = _X20;
    drm_dp_queue_down_tx(a1, v24);
    v26 = drm_dp_mst_wait_tx_reply(_X20, v24);
    if ( v26 < 1 )
    {
      a4 = v26;
    }
    else if ( *(_BYTE *)(v24 + 346) == 1 )
    {
      a4 = -5;
    }
    kfree(v24);
  }
  else
  {
    a4 = -12;
  }
  drm_dp_mst_topology_put_mstb(_X20);
  result = a4;
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
