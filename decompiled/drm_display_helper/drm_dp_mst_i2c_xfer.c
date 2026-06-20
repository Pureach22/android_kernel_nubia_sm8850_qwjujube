__int64 __fastcall drm_dp_mst_i2c_xfer(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v5; // x24
  __int64 v6; // x22
  __int64 v7; // x20
  __int64 v8; // x0
  unsigned int *mstb_validated_locked; // x0
  unsigned int v10; // w8
  unsigned int v12; // w23
  unsigned int v18; // w9
  __int64 v19; // x8
  __int64 v20; // x1
  int v21; // w8
  unsigned __int16 *v22; // x9
  __int64 v23; // x10
  __int64 v24; // x9
  _QWORD *v25; // x22
  unsigned int v26; // w10
  char v27; // w11
  __int64 v28; // x9
  unsigned int v29; // w10
  char v30; // w11
  __int64 v31; // x9
  unsigned int v32; // w10
  char v33; // w11
  __int64 v34; // x9
  unsigned int v35; // w10
  char v36; // w11
  __int64 v37; // x9
  __int64 v38; // x23
  char v39; // w9
  __int64 v40; // x21
  int v41; // w0
  unsigned __int16 *v42; // x9
  __int64 v43; // x10
  __int64 v44; // x8
  __int64 v45; // x23
  __int64 v46; // x25
  _QWORD *v47; // x21
  char v48; // w9
  char v49; // w8
  __int64 v50; // x9
  char v51; // w8
  int v52; // w0
  __int64 v53; // x8
  __int64 v54; // x1
  size_t v55; // x2
  unsigned __int64 StatusReg; // x25
  __int64 v58; // x26
  __int64 v59; // [xsp+0h] [xbp-80h] BYREF
  __int64 v60; // [xsp+8h] [xbp-78h]
  __int64 v61; // [xsp+10h] [xbp-70h]
  __int64 v62; // [xsp+18h] [xbp-68h]
  __int64 v63; // [xsp+20h] [xbp-60h]
  __int64 v64; // [xsp+28h] [xbp-58h]
  __int64 v65; // [xsp+30h] [xbp-50h]
  __int64 v66; // [xsp+38h] [xbp-48h]
  __int64 v67; // [xsp+40h] [xbp-40h]
  __int64 v68; // [xsp+48h] [xbp-38h]
  __int64 v69; // [xsp+50h] [xbp-30h]
  __int64 v70; // [xsp+58h] [xbp-28h]
  __int64 v71; // [xsp+60h] [xbp-20h]
  __int64 v72; // [xsp+68h] [xbp-18h]
  __int64 v73; // [xsp+70h] [xbp-10h]
  __int64 v74; // [xsp+78h] [xbp-8h]

  v74 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 24);
  v6 = *(_QWORD *)(v5 + 1584);
  v7 = *(_QWORD *)(v5 + 1568);
  mutex_lock(v6 + 800);
  v8 = *(_QWORD *)(v6 + 904);
  if ( !v8 )
    goto LABEL_60;
  mstb_validated_locked = (unsigned int *)drm_dp_mst_topology_get_mstb_validated_locked(v8, v7);
  if ( !mstb_validated_locked )
    goto LABEL_60;
  v10 = *mstb_validated_locked;
  _X20 = mstb_validated_locked;
  if ( *mstb_validated_locked )
  {
    do
    {
      __asm { PRFM            #0x11, [X20] }
      do
        v18 = __ldxr(mstb_validated_locked);
      while ( v18 == v10 && __stxr(v10 + 1, mstb_validated_locked) );
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
  if ( (((v12 + 1) | v12) & 0x80000000) == 0 )
  {
    if ( v12 )
      goto LABEL_14;
LABEL_60:
    mutex_unlock(v6 + 800);
    a3 = -121;
    goto LABEL_61;
  }
  refcount_warn_saturate(mstb_validated_locked, 0);
  if ( !v12 )
    goto LABEL_60;
LABEL_14:
  v19 = *(_QWORD *)(*((_QWORD *)_X20 + 8) + 104LL);
  if ( v19 )
    v20 = *(_QWORD *)(v19 + 8);
  else
    v20 = 0;
  _drm_dev_dbg(0, v20, 1, "mstb %p (%d)\n", _X20, *_X20);
  mutex_unlock(v6 + 800);
  v21 = a3 - 1;
  if ( (int)(a3 - 1) > 4 )
  {
LABEL_35:
    v42 = (unsigned __int16 *)(a2 + 4);
    v43 = a3 - 1;
    while ( (*(v42 - 1) & 0x8001) == 0x8000 && *v42 <= 0xFFu )
    {
      --v43;
      v42 += 8;
      if ( !v43 )
        goto LABEL_39;
    }
    goto LABEL_48;
  }
  if ( v21 < 1 )
  {
LABEL_23:
    v24 = a2 + 16LL * v21;
    if ( (*(_WORD *)(v24 + 2) & 1) != 0 && *(unsigned __int16 *)(v24 + 4) <= 0xFFu )
    {
      v25 = *(_QWORD **)(v5 + 1584);
      v72 = 0;
      v73 = 0;
      v70 = 0;
      v71 = 0;
      v68 = 0;
      v69 = 0;
      v66 = 0;
      v67 = 0;
      v64 = 0;
      v65 = 0;
      v62 = 0;
      v63 = 0;
      v61 = 0;
      v59 = 34;
      v60 = (unsigned __int8)v21;
      BYTE1(v60) = *(_BYTE *)(v5 - 40);
      if ( a3 == 1 )
        goto LABEL_30;
      v26 = *(unsigned __int16 *)(a2 + 2);
      v27 = *(_BYTE *)(a2 + 4);
      LOBYTE(v61) = *(_BYTE *)a2;
      v28 = *(_QWORD *)(a2 + 8);
      BYTE1(v61) = v27;
      v62 = v28;
      LOBYTE(v63) = (v26 >> 15) ^ 1;
      if ( a3 == 2 )
        goto LABEL_30;
      v29 = *(unsigned __int16 *)(a2 + 18);
      v30 = *(_BYTE *)(a2 + 20);
      LOBYTE(v64) = *(_BYTE *)(a2 + 16);
      v31 = *(_QWORD *)(a2 + 24);
      BYTE1(v64) = v30;
      v65 = v31;
      LOBYTE(v66) = (v29 >> 15) ^ 1;
      if ( a3 == 3 )
        goto LABEL_30;
      v32 = *(unsigned __int16 *)(a2 + 34);
      v33 = *(_BYTE *)(a2 + 36);
      LOBYTE(v67) = *(_BYTE *)(a2 + 32);
      v34 = *(_QWORD *)(a2 + 40);
      BYTE1(v67) = v33;
      v68 = v34;
      LOBYTE(v69) = (v32 >> 15) ^ 1;
      if ( a3 == 4
        || (v35 = *(unsigned __int16 *)(a2 + 50),
            v36 = *(_BYTE *)(a2 + 52),
            LOBYTE(v70) = *(_BYTE *)(a2 + 48),
            v37 = *(_QWORD *)(a2 + 56),
            BYTE1(v70) = v36,
            v71 = v37,
            LOBYTE(v72) = (v35 >> 15) ^ 1,
            a3 == 5) )
      {
LABEL_30:
        v38 = a2 + 16LL * (unsigned int)v21;
        v39 = *(_BYTE *)(v38 + 4);
        LOBYTE(v73) = *(_BYTE *)v38;
        BYTE1(v73) = v39;
        v40 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 768);
        if ( v40 )
        {
          *(_QWORD *)(v40 + 312) = _X20;
          ((void (__fastcall *)(__int64 *, __int64))drm_dp_encode_sideband_req)(&v59, v40);
          drm_dp_queue_down_tx(v25, v40);
          v41 = drm_dp_mst_wait_tx_reply((__int64)_X20, v40);
          if ( v41 < 1 )
          {
            a3 = v41;
          }
          else if ( *(_BYTE *)(v40 + 346) == 1 )
          {
            a3 = -121;
          }
          else
          {
            v55 = *(unsigned __int16 *)(v38 + 4);
            if ( (_DWORD)v55 == *(unsigned __int8 *)(v40 + 349) )
              memcpy(*(void **)(v38 + 8), (const void *)(v40 + 350), v55);
            else
              a3 = -5;
          }
        }
        else
        {
          a3 = -12;
        }
        kfree(v40);
        goto LABEL_52;
      }
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v58 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &drm_dp_mst_i2c_write__alloc_tag;
      v45 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 768);
      *(_QWORD *)(StatusReg + 80) = v58;
      if ( v45 )
        goto LABEL_42;
      goto LABEL_63;
    }
  }
  else
  {
    v22 = (unsigned __int16 *)(a2 + 4);
    v23 = a3 - 1;
    while ( (*(v22 - 1) & 1) == 0 && *v22 <= 0xFFu )
    {
      --v23;
      v22 += 8;
      if ( !v23 )
        goto LABEL_23;
    }
  }
  if ( v21 >= 1 )
    goto LABEL_35;
LABEL_39:
  v44 = a2 + 16LL * v21;
  if ( (*(_WORD *)(v44 + 2) & 1) != 0 || *(unsigned __int16 *)(v44 + 4) > 0xFFu )
  {
LABEL_48:
    v53 = *(_QWORD *)(v6 + 104);
    if ( v53 )
      v54 = *(_QWORD *)(v53 + 8);
    else
      v54 = 0;
    _drm_dev_dbg(0, v54, 2, "Unsupported I2C transaction for MST device\n");
    a3 = -5;
    goto LABEL_52;
  }
  v25 = *(_QWORD **)(v5 + 1584);
  v72 = 0;
  v73 = 0;
  v70 = 0;
  v71 = 0;
  v68 = 0;
  v69 = 0;
  v66 = 0;
  v67 = 0;
  v64 = 0;
  v65 = 0;
  v62 = 0;
  v63 = 0;
  v60 = 0;
  v61 = 0;
  v59 = 0;
  v45 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 768);
  if ( v45 )
  {
LABEL_42:
    if ( a3 )
    {
      v46 = a3;
      v47 = (_QWORD *)(a2 + 8);
      while ( 1 )
      {
        v72 = 0;
        v73 = 0;
        v48 = *((_BYTE *)v47 - 8);
        v70 = 0;
        v71 = 0;
        v68 = 0;
        v69 = 0;
        v66 = 0;
        v67 = 0;
        v64 = 0;
        v65 = 0;
        v62 = 0;
        v63 = 0;
        v60 = 0;
        v61 = 0;
        v59 = 35;
        v49 = *(_BYTE *)(v5 - 40);
        BYTE1(v60) = v48;
        v50 = *v47;
        LOBYTE(v60) = v49;
        v51 = *((_BYTE *)v47 - 4);
        v61 = v50;
        BYTE2(v60) = v51;
        memset((void *)v45, 0, 0x300u);
        *(_QWORD *)(v45 + 312) = _X20;
        ((void (__fastcall *)(__int64 *, __int64))drm_dp_encode_sideband_req)(&v59, v45);
        drm_dp_queue_down_tx(v25, v45);
        v52 = drm_dp_mst_wait_tx_reply((__int64)_X20, v45);
        if ( v52 < 1 )
        {
          a3 = v52;
          goto LABEL_64;
        }
        if ( *(_BYTE *)(v45 + 346) == 1 )
          break;
        --v46;
        v47 += 2;
        if ( !v46 )
          goto LABEL_64;
      }
      a3 = -121;
    }
    goto LABEL_64;
  }
LABEL_63:
  a3 = -12;
LABEL_64:
  kfree(v45);
LABEL_52:
  drm_dp_mst_topology_put_mstb(_X20);
LABEL_61:
  _ReadStatusReg(SP_EL0);
  return a3;
}
