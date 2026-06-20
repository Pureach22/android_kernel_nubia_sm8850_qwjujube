__int64 __fastcall kgsl_timeline_signal(_QWORD *a1, unsigned __int64 a2)
{
  __int64 v4; // x1
  unsigned __int64 *v5; // x9
  unsigned __int64 *v6; // x10
  unsigned __int64 v7; // x11
  unsigned __int64 **v8; // x8
  unsigned __int64 *v9; // x12
  _QWORD *v10; // x20
  _QWORD *v11; // x23
  unsigned __int64 v12; // x9
  unsigned __int64 v13; // x8
  bool v14; // cc
  int v15; // w8
  int v16; // w9
  _BOOL4 v17; // w8
  unsigned int v19; // w8
  unsigned int v20; // w24
  unsigned int v26; // w9
  _QWORD *v27; // x8
  __int64 v28; // x9
  __int64 v29; // x2
  _QWORD **v30; // x25
  _QWORD *v31; // x24
  int v34; // w8
  __int64 result; // x0
  _QWORD v36[3]; // [xsp+8h] [xbp-18h] BYREF

  v36[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36[0] = v36;
  v36[1] = v36;
  raw_spin_lock_irq((char *)a1 + 28);
  if ( a1[2] <= a2 )
  {
    v6 = a1 + 7;
    v5 = (unsigned __int64 *)a1[7];
    a1[2] = a2;
    if ( v5 != a1 + 7 )
    {
      v7 = 0xDEAD000000000100LL;
      do
      {
        if ( *(v5 - 3) > a2 )
          break;
        v9 = (unsigned __int64 *)*v5;
        v8 = (unsigned __int64 **)v5[1];
        if ( *v8 == v5 && (unsigned __int64 *)v9[1] == v5 )
        {
          v9[1] = (unsigned __int64)v8;
          *v8 = v9;
        }
        else
        {
          _list_del_entry_valid_or_report(v5);
        }
        *v5 = v7;
        v5[1] = v7 + 34;
        v5 = v9;
      }
      while ( v9 != v6 );
    }
    raw_spin_lock(a1 + 3);
    v10 = (_QWORD *)a1[5];
    if ( v10 != a1 + 5 )
    {
      do
      {
        v11 = (_QWORD *)*v10;
        v12 = *(v10 - 4);
        v13 = *(_QWORD *)(*(v10 - 1) + 16LL);
        v14 = v12 > v13;
        v15 = v12 - v13;
        v16 = !v14;
        v17 = v15 < 1;
        if ( *(_BYTE *)*(v10 - 8) )
          v17 = v16;
        if ( !v17 )
          goto LABEL_14;
        _X0 = (unsigned int *)(v10 - 2);
        v19 = *((_DWORD *)v10 - 4);
        if ( v19 )
        {
          do
          {
            __asm { PRFM            #0x11, [X0] }
            do
              v26 = __ldxr(_X0);
            while ( v26 == v19 && __stxr(v19 + 1, _X0) );
            v20 = v19;
            if ( v26 == v19 )
              break;
            v20 = 0;
            v19 = v26;
          }
          while ( v26 );
        }
        else
        {
          v20 = 0;
        }
        if ( (((v20 + 1) | v20) & 0x80000000) != 0 )
        {
          refcount_warn_saturate(_X0, 0);
          if ( v20 )
          {
LABEL_32:
            v27 = (_QWORD *)v10[1];
            if ( (_QWORD *)*v27 == v10 && (v28 = *v10, *(_QWORD **)(*v10 + 8LL) == v10) )
            {
              *(_QWORD *)(v28 + 8) = v27;
              *v27 = v28;
            }
            else
            {
              _list_del_entry_valid_or_report(v10);
            }
            v29 = v36[0];
            if ( *(_QWORD **)(v36[0] + 8LL) != v36 || v10 == v36 || (_QWORD *)v36[0] == v10 )
            {
              _list_add_valid_or_report(v10, v36);
            }
            else
            {
              *(_QWORD *)(v36[0] + 8LL) = v10;
              *v10 = v29;
              v10[1] = v36;
              v36[0] = v10;
            }
          }
        }
        else if ( v20 )
        {
          goto LABEL_32;
        }
LABEL_14:
        v10 = v11;
      }
      while ( v11 != a1 + 5 );
    }
    raw_spin_unlock(a1 + 3);
    v30 = (_QWORD **)v36[0];
    if ( (_QWORD *)v36[0] != v36 )
    {
      do
      {
        v31 = *v30;
        dma_fence_signal_locked(v30 - 9);
        if ( v30 != (_QWORD **)&_crc_kgsl_gpu_num_freqs )
        {
          _X0 = (unsigned int *)(v30 - 2);
          __asm { PRFM            #0x11, [X0] }
          do
            v34 = __ldxr(_X0);
          while ( __stlxr(v34 - 1, _X0) );
          if ( v34 == 1 )
          {
            __dmb(9u);
            dma_fence_release(_X0);
          }
          else if ( v34 <= 0 )
          {
            refcount_warn_saturate(_X0, 3);
          }
        }
        v30 = (_QWORD **)v31;
      }
      while ( v31 != v36 );
    }
  }
  result = raw_spin_unlock_irq((char *)a1 + 28, v4);
  _ReadStatusReg(SP_EL0);
  return result;
}
