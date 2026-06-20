__int64 __fastcall _fastrpc_buf_alloc(__int64 a1, _QWORD *a2, int a3, __int64 a4, _QWORD *a5, int a6)
{
  _QWORD *v12; // x0
  _QWORD *v13; // x19
  __int64 v14; // x0
  __int64 v15; // x21
  bool v16; // zf
  __int64 v17; // x1
  __int64 v18; // x22
  __int64 v19; // x8
  __int64 v20; // x23
  unsigned __int64 v21; // x8
  __int64 v22; // x9
  unsigned __int64 v23; // x8
  __int64 v24; // x9
  int v25; // w10
  __int64 result; // x0
  _QWORD *v27; // x24
  __int64 v28; // x23
  unsigned __int64 v29; // x8
  __int64 v30; // x9
  unsigned __int64 v31; // x8
  __int64 v32; // x9
  int v33; // w10
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x1
  __int64 v37; // x9
  __int64 v38; // [xsp+8h] [xbp-18h] BYREF
  __int64 v39; // [xsp+10h] [xbp-10h]
  __int64 v40; // [xsp+18h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a4 )
  {
    v12 = (_QWORD *)_kmalloc_cache_noprof(_usecs_to_jiffies, 3520, 224);
    v13 = v12;
    if ( !v12 )
    {
LABEL_18:
      result = 4294967284LL;
      goto LABEL_19;
    }
    v12[16] = v12 + 16;
    v12[17] = v12 + 16;
    *v12 = v12;
    v12[1] = v12;
    _mutex_init(v12 + 10, "&buf->lock", &_fastrpc_buf_alloc___key);
    v13[2] = a1;
    v13[6] = 0;
    v13[8] = 0;
    v13[9] = a4;
    v13[18] = 0;
    *((_DWORD *)v13 + 14) = a6;
    *((_DWORD *)v13 + 39) = a3;
    v14 = ktime_get_with_offset(1);
    v15 = ns_to_timespec64(v14);
    v16 = a6 == 4;
    v18 = v17;
    if ( v16 )
    {
      v19 = *(_QWORD *)(*(_QWORD *)(a1 + 128) + 168LL);
      v13[4] = v19;
      if ( !v19 )
        goto LABEL_17;
      v20 = v13[5];
      if ( (unsigned int)_fastrpc_dma_alloc(v13) )
        goto LABEL_17;
      if ( *((_DWORD *)v13 + 14) != 4 )
      {
        v21 = v13[9];
        v22 = 4095;
        if ( v21 > 0x200000 )
          v22 = 0x1FFFFF;
        if ( v21 > 0x40000000 )
          v22 = 0x3FFFFFFF;
        v23 = (v22 + v21) & ~v22;
        v24 = *(int *)(v20 + 8);
        v25 = *(_DWORD *)(v20 + 140);
        *(_QWORD *)(v20 + 96) += v23;
        v13[8] += v24 << v25;
      }
    }
    else
    {
      v27 = a2 + 2;
      v13[4] = *a2;
      v13[5] = a2;
      mutex_lock(a2 + 2);
      if ( !v13[4] || (v28 = v13[5], (unsigned int)_fastrpc_dma_alloc(v13)) )
      {
        mutex_unlock(v27);
LABEL_17:
        kfree(v13);
        goto LABEL_18;
      }
      if ( *((_DWORD *)v13 + 14) != 4 )
      {
        v29 = v13[9];
        v30 = 4095;
        if ( v29 > 0x200000 )
          v30 = 0x1FFFFF;
        if ( v29 > 0x40000000 )
          v30 = 0x3FFFFFFF;
        v31 = (v30 + v29) & ~v30;
        v32 = *(int *)(v28 + 8);
        v33 = *(_DWORD *)(v28 + 140);
        *(_QWORD *)(v28 + 96) += v31;
        v13[8] += v32 << v33;
      }
      mutex_unlock(v27);
    }
    *a5 = v13;
    v34 = ktime_get_with_offset(1);
    v35 = ns_to_timespec64(v34);
    v38 = 0;
    v39 = 0;
    set_normalized_timespec64(&v38, v35 - v15, v36 - v18);
    v37 = v39;
    result = 0;
    v13[20] = v38;
    v13[21] = v37;
    goto LABEL_19;
  }
  result = 4294967282LL;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
