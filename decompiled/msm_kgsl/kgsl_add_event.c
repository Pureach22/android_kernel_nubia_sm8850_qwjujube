__int64 __fastcall kgsl_add_event(__int64 a1, __int64 *a2, unsigned int a3, __int64 a4, __int64 a5)
{
  __int64 v11; // x1
  void (__fastcall *v12)(__int64, __int64, __int64, unsigned int *); // x8
  __int64 v13; // x22
  unsigned int v14; // w8
  unsigned int v15; // w9
  unsigned int v21; // w10
  __int64 result; // x0
  int v23; // w8
  __int64 v24; // x1
  void (__fastcall *v25)(__int64, __int64, __int64, unsigned int *); // x8
  __int64 v26; // x0
  _QWORD *v27; // x0
  _QWORD *v28; // x2
  _QWORD *v29; // x1
  unsigned int v30; // [xsp+Ch] [xbp-14h]
  unsigned int v31; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v32; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v33; // [xsp+18h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a4 )
    goto LABEL_21;
  _X24 = *a2;
  v32 = 0;
  v31 = 0;
  if ( !_X24 || (*(_BYTE *)(_X24 + 200) & 0x80) == 0 )
  {
    v12 = (void (__fastcall *)(__int64, __int64, __int64, unsigned int *))a2[15];
    v11 = a2[16];
    if ( *((_DWORD *)v12 - 1) != -362688460 )
      __break(0x8228u);
    v12(a1, v11, 3, &v32);
    if ( a3 != v32
      && (a3 > v32 && ((a3 - v32) & 0x80000000) == 0
       || (a3 ^ 0x80000000) > (v32 ^ 0x80000000) && (a3 ^ 0x80000000) - (v32 ^ 0x80000000) < 0x80000001) )
    {
LABEL_21:
      result = 4294967274LL;
      goto LABEL_41;
    }
  }
  v13 = kmem_cache_alloc_noprof(events_cache, 3264);
  if ( !v13 )
  {
    result = 4294967284LL;
    goto LABEL_41;
  }
  if ( _X24 )
  {
    v14 = *(_DWORD *)_X24;
    if ( *(_DWORD *)_X24 )
    {
      do
      {
        __asm { PRFM            #0x11, [X24] }
        do
          v21 = __ldxr((unsigned int *)_X24);
        while ( v21 == v14 && __stxr(v14 + 1, (unsigned int *)_X24) );
        v15 = v14;
        if ( v21 == v14 )
          break;
        v15 = 0;
        v14 = v21;
      }
      while ( v21 );
    }
    else
    {
      v15 = 0;
    }
    if ( (((v15 + 1) | v15) & 0x80000000) != 0 )
    {
      v30 = v15;
      refcount_warn_saturate(_X24, 0);
      if ( v30 )
        goto LABEL_25;
    }
    else if ( v15 )
    {
      goto LABEL_25;
    }
    kmem_cache_free(events_cache, v13);
    result = 4294967294LL;
    goto LABEL_41;
  }
LABEL_25:
  *(_QWORD *)v13 = a1;
  *(_QWORD *)(v13 + 8) = _X24;
  *(_DWORD *)(v13 + 16) = a3;
  *(_QWORD *)(v13 + 24) = a4;
  *(_QWORD *)(v13 + 32) = a5;
  v23 = jiffies;
  *(_QWORD *)(v13 + 112) = a2;
  *(_QWORD *)(v13 + 88) = 0;
  *(_QWORD *)(v13 + 96) = 0;
  *(_DWORD *)(v13 + 56) = v23;
  *(_QWORD *)(v13 + 64) = v13 + 64;
  *(_QWORD *)(v13 + 72) = v13 + 64;
  *(_QWORD *)(v13 + 80) = kgsl_event_worker;
  raw_spin_lock(a2 + 1);
  v25 = (void (__fastcall *)(__int64, __int64, __int64, unsigned int *))a2[15];
  v24 = a2[16];
  if ( *((_DWORD *)v25 - 1) != -362688460 )
    __break(0x8228u);
  v25(a1, v24, 2, &v31);
  if ( v31 != a3
    && (v31 <= a3 || ((v31 - a3) & 0x80000000) != 0)
    && ((v31 ^ 0x80000000) <= (a3 ^ 0x80000000) || (v31 ^ 0x80000000) - (a3 ^ 0x80000000) > 0x80000000) )
  {
    v27 = (_QWORD *)(v13 + 40);
    v28 = a2 + 2;
    v29 = (_QWORD *)a2[3];
    if ( (__int64 *)(v13 + 40) == a2 + 2 || v29 == v27 || (_QWORD *)*v29 != v28 )
    {
      _list_add_valid_or_report(v27, v29);
    }
    else
    {
      a2[3] = (__int64)v27;
      *(_QWORD *)(v13 + 40) = v28;
      *(_QWORD *)(v13 + 48) = v29;
      *v29 = v27;
    }
  }
  else
  {
    v26 = *(_QWORD *)(a1 + 12976);
    *(_DWORD *)(v13 + 104) = 1;
    kthread_queue_work(v26, v13 + 64);
  }
  raw_spin_unlock(a2 + 1);
  result = 0;
LABEL_41:
  _ReadStatusReg(SP_EL0);
  return result;
}
