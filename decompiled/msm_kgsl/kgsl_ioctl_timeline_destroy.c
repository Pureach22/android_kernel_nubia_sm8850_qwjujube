__int64 __fastcall kgsl_ioctl_timeline_destroy(__int64 *a1, __int64 a2, _DWORD *a3)
{
  __int64 v3; // x21
  __int64 v6; // x0
  unsigned __int64 v7; // x19
  __int64 result; // x0
  _QWORD *v9; // x20
  _QWORD **v10; // x22
  _QWORD *v11; // x23
  unsigned int v13; // w8
  unsigned int v14; // w24
  unsigned int v20; // w9
  _QWORD *v21; // x8
  __int64 v22; // x9
  _QWORD *v23; // x8
  __int64 v24; // x1
  _QWORD **v25; // x26
  _QWORD *v26; // x25
  int v29; // w8
  int v32; // w8
  _QWORD *v33; // [xsp+8h] [xbp-18h] BYREF
  _QWORD **v34; // [xsp+10h] [xbp-10h]
  __int64 v35; // [xsp+18h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*a3 )
  {
    result = -19;
    goto LABEL_50;
  }
  v3 = *a1;
  raw_spin_lock(*a1 + 13400);
  v6 = idr_find(v3 + 13376, (unsigned int)*a3);
  if ( !v6 )
  {
    raw_spin_unlock(v3 + 13400);
    result = -19;
    goto LABEL_50;
  }
  v7 = v6;
  if ( *(__int64 **)(v6 + 104) != a1 )
  {
    raw_spin_unlock(v3 + 13400);
    result = -22;
    goto LABEL_50;
  }
  idr_remove(v3 + 13376);
  raw_spin_unlock(v3 + 13400);
  v33 = &v33;
  v34 = &v33;
  raw_spin_lock(v7 + 24);
  v10 = (_QWORD **)(v7 + 40);
  v9 = *(_QWORD **)(v7 + 40);
  if ( v9 != (_QWORD *)(v7 + 40) )
  {
    while ( 1 )
    {
      v11 = (_QWORD *)*v9;
      _X0 = (unsigned int *)(v9 - 2);
      v13 = *((_DWORD *)v9 - 4);
      if ( v13 )
      {
        do
        {
          __asm { PRFM            #0x11, [X0] }
          do
            v20 = __ldxr(_X0);
          while ( v20 == v13 && __stxr(v13 + 1, _X0) );
          v14 = v13;
          if ( v20 == v13 )
            break;
          v14 = 0;
          v13 = v20;
        }
        while ( v20 );
      }
      else
      {
        v14 = 0;
      }
      if ( (((v14 + 1) | v14) & 0x80000000) != 0 )
      {
        refcount_warn_saturate(_X0, 0);
        if ( !v14 )
        {
LABEL_23:
          v21 = (_QWORD *)v9[1];
          if ( (_QWORD *)*v21 == v9 && (v22 = *v9, *(_QWORD **)(*v9 + 8LL) == v9) )
          {
            *(_QWORD *)(v22 + 8) = v21;
            *v21 = v22;
          }
          else
          {
            _list_del_entry_valid_or_report(v9);
          }
          *v9 = v9;
          v9[1] = v9;
        }
      }
      else if ( !v14 )
      {
        goto LABEL_23;
      }
      v9 = v11;
      if ( v11 == v10 )
      {
        v9 = *v10;
        break;
      }
    }
  }
  v9[1] = &v33;
  v23 = *(_QWORD **)(v7 + 48);
  v33 = v9;
  v34 = (_QWORD **)v23;
  *v23 = &v33;
  *(_QWORD *)(v7 + 40) = v7 + 40;
  *(_QWORD *)(v7 + 48) = v10;
  raw_spin_unlock(v7 + 24);
  raw_spin_lock_irq(v7 + 28);
  v25 = (_QWORD **)v33;
  if ( v33 != &v33 )
  {
    do
    {
      v26 = *v25;
      if ( ((unsigned int)*(v25 - 3) & 1) != 0 )
        __break(0x800u);
      *((_DWORD *)v25 - 3) = -2;
      dma_fence_signal_locked(v25 - 9);
      if ( v25 != (_QWORD **)&_crc_kgsl_gpu_num_freqs )
      {
        _X0 = (unsigned int *)(v25 - 2);
        __asm { PRFM            #0x11, [X0] }
        do
          v29 = __ldxr(_X0);
        while ( __stlxr(v29 - 1, _X0) );
        if ( v29 == 1 )
        {
          __dmb(9u);
          dma_fence_release(_X0);
        }
        else if ( v29 <= 0 )
        {
          refcount_warn_saturate(_X0, 3);
        }
      }
      v25 = (_QWORD **)v26;
    }
    while ( v26 != &v33 );
  }
  raw_spin_unlock_irq(v7 + 28, v24);
  if ( v7 <= 0xFFFFFFFFFFFFF000LL )
  {
    _X0 = (unsigned int *)(v7 + 32);
    __asm { PRFM            #0x11, [X0] }
    do
      v32 = __ldxr(_X0);
    while ( __stlxr(v32 - 1, _X0) );
    if ( v32 == 1 )
    {
      __dmb(9u);
      kgsl_timeline_destroy((__int64)_X0);
    }
    else if ( v32 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
  }
  result = 0;
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return result;
}
