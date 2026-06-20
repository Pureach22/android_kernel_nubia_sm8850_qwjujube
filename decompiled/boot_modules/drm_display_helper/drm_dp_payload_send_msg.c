__int64 __fastcall drm_dp_payload_send_msg(_QWORD *a1, __int64 a2, char a3, __int16 a4)
{
  char v8; // w27
  __int64 v9; // x22
  __int64 v10; // x0
  unsigned int *mstb_validated_locked; // x0
  unsigned int v12; // w8
  unsigned int v14; // w24
  unsigned int v20; // w9
  __int64 v21; // x8
  __int64 v22; // x1
  __int64 v23; // x24
  __int64 last_connected_port_to_mstb; // x0
  __int64 v26; // x26
  unsigned int v27; // w8
  unsigned int v28; // w22
  unsigned int v30; // w9
  __int64 v31; // x8
  __int64 v32; // x1
  unsigned int *v33; // x28
  __int64 result; // x0
  __int64 v35; // x0
  __int64 v36; // x1
  __int64 v37; // x24
  size_t v38; // x2
  int v39; // w0
  unsigned int v40; // w19
  __int64 v41; // [xsp+0h] [xbp-90h] BYREF
  __int64 v42; // [xsp+8h] [xbp-88h]
  __int64 v43; // [xsp+10h] [xbp-80h] BYREF
  _QWORD v44[15]; // [xsp+18h] [xbp-78h] BYREF

  v44[14] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_BYTE *)(a2 + 8);
  v9 = *(_QWORD *)(a2 + 1616);
  v41 = 0;
  v42 = 0;
  mutex_lock(a1 + 100);
  v10 = a1[113];
  if ( !v10 )
    goto LABEL_19;
  mstb_validated_locked = (unsigned int *)drm_dp_mst_topology_get_mstb_validated_locked(v10, v9);
  if ( !mstb_validated_locked )
    goto LABEL_19;
  v12 = *mstb_validated_locked;
  _X22 = mstb_validated_locked;
  if ( *mstb_validated_locked )
  {
    do
    {
      __asm { PRFM            #0x11, [X22] }
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
    goto LABEL_19;
  }
  if ( !v14 )
  {
LABEL_19:
    mutex_unlock(a1 + 100);
    v23 = *(_QWORD *)(a2 + 1616);
    mutex_lock(a1 + 100);
    if ( !a1[113] )
    {
LABEL_41:
      mutex_unlock(a1 + 100);
      result = 4294967274LL;
LABEL_68:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    while ( 1 )
    {
      while ( 1 )
      {
        last_connected_port_to_mstb = drm_dp_get_last_connected_port_to_mstb(v23);
        if ( !last_connected_port_to_mstb )
          goto LABEL_41;
        _X4 = *(unsigned int **)(last_connected_port_to_mstb + 1616);
        v26 = last_connected_port_to_mstb;
        v27 = *_X4;
        if ( *_X4 )
        {
          do
          {
            __asm { PRFM            #0x11, [X4] }
            do
              v30 = __ldxr(_X4);
            while ( v30 == v27 && __stxr(v27 + 1, _X4) );
            v28 = v27;
            if ( v30 == v27 )
              break;
            v28 = 0;
            v27 = v30;
          }
          while ( v30 );
        }
        else
        {
          v28 = 0;
        }
        if ( (((v28 + 1) | v28) & 0x80000000) == 0 )
          break;
        v33 = _X4;
        refcount_warn_saturate(_X4, 0);
        _X4 = v33;
        if ( v28 )
          goto LABEL_34;
LABEL_21:
        v23 = *(_QWORD *)(v26 + 1616);
      }
      if ( !v28 )
        goto LABEL_21;
LABEL_34:
      v31 = *(_QWORD *)(*((_QWORD *)_X4 + 8) + 104LL);
      if ( v31 )
        v32 = *(_QWORD *)(v31 + 8);
      else
        v32 = 0;
      _drm_dev_dbg(0, v32, 1, "mstb %p (%d)\n", _X4, *_X4);
      _X22 = *(unsigned int **)(v26 + 1616);
      v8 = *(_BYTE *)(v26 + 8);
      if ( _X22 )
        goto LABEL_42;
    }
  }
LABEL_14:
  v21 = *(_QWORD *)(*((_QWORD *)_X22 + 8) + 104LL);
  if ( v21 )
    v22 = *(_QWORD *)(v21 + 8);
  else
    v22 = 0;
  _drm_dev_dbg(0, v22, 1, "mstb %p (%d)\n", _X22, *_X22);
LABEL_42:
  mutex_unlock(a1 + 100);
  v35 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 768);
  v37 = v35;
  if ( !v35 )
  {
    v40 = -12;
LABEL_67:
    drm_dp_mst_topology_put_mstb(_X22);
    result = v40;
    goto LABEL_68;
  }
  v38 = *(unsigned __int8 *)(a2 + 15);
  if ( !*(_BYTE *)(a2 + 15) )
    goto LABEL_60;
  LOBYTE(v41) = 0;
  if ( (_DWORD)v38 == 1 )
    goto LABEL_60;
  BYTE1(v41) = 1;
  if ( (_DWORD)v38 == 2 )
    goto LABEL_60;
  BYTE2(v41) = 2;
  if ( (_DWORD)v38 == 3 )
    goto LABEL_60;
  BYTE3(v41) = 3;
  if ( (_DWORD)v38 == 4 )
    goto LABEL_60;
  BYTE4(v41) = 4;
  if ( (_DWORD)v38 == 5 )
    goto LABEL_60;
  BYTE5(v41) = 5;
  if ( (_DWORD)v38 == 6 )
    goto LABEL_60;
  BYTE6(v41) = 6;
  if ( (_DWORD)v38 == 7 )
    goto LABEL_60;
  HIBYTE(v41) = 7;
  if ( (_DWORD)v38 == 8 )
    goto LABEL_60;
  LOBYTE(v42) = 8;
  if ( (_DWORD)v38 == 9
    || (BYTE1(v42) = 9, (_DWORD)v38 == 10)
    || (BYTE2(v42) = 10, (_DWORD)v38 == 11)
    || (BYTE3(v42) = 11, (_DWORD)v38 == 12)
    || (BYTE4(v42) = 12, (_DWORD)v38 == 13)
    || (BYTE5(v42) = 13, (_DWORD)v38 == 14)
    || (BYTE6(v42) = 14, (_DWORD)v38 == 15)
    || (HIBYTE(v42) = 15, (_DWORD)v38 == 16) )
  {
LABEL_60:
    v44[0] = 0;
    v43 = 17;
    *(_QWORD *)(v35 + 312) = _X22;
    memset(&v44[1], 0, 104);
    LOBYTE(v44[0]) = v8;
    BYTE2(v44[0]) = a3;
    WORD2(v44[0]) = a4;
    BYTE1(v44[0]) = v38;
    memcpy((char *)v44 + 6, &v41, v38);
    ((void (__fastcall *)(__int64 *, __int64))drm_dp_encode_sideband_req)(&v43, v37);
    *(_BYTE *)(v37 + 344) = 1;
    drm_dp_queue_down_tx(a1, v37);
    v39 = drm_dp_mst_wait_tx_reply((__int64)_X22, v37);
    if ( v39 < 1 )
    {
      v40 = v39;
    }
    else if ( *(_BYTE *)(v37 + 346) == 1 )
    {
      v40 = -22;
    }
    else
    {
      v40 = 0;
    }
    kfree(v37);
    goto LABEL_67;
  }
  __break(0x5512u);
  return drm_dp_mst_topology_get_mstb_validated_locked(v35, v36);
}
