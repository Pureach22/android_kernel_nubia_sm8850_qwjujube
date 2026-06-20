__int64 __fastcall msm_cvp_session_get_smem(_QWORD *a1, _DWORD *a2, char a3, int a4)
{
  unsigned __int64 dma_buf; // x0
  unsigned __int64 v9; // x22
  __int64 v10; // x0
  __int64 v11; // x20
  int v12; // w8
  unsigned int v13; // w6
  unsigned int v14; // w8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x8
  _QWORD *i; // x8
  __int64 **j; // x8
  __int64 v20; // x10
  __int64 v21; // x10
  unsigned __int64 v22; // x9
  const char *v23; // x1
  __int64 v24; // x0
  unsigned int v25; // w6
  unsigned int v26; // w8
  unsigned int v27; // w6
  unsigned int v28; // w8
  unsigned __int64 v30; // x8
  int v31; // w0
  unsigned __int64 v32; // x8
  unsigned __int64 v33; // x8
  unsigned int v36; // w9
  unsigned int v39; // w10
  unsigned int v42; // w9
  unsigned int v45; // w9
  unsigned int v52; // w9

  dma_buf = msm_cvp_smem_get_dma_buf();
  if ( dma_buf )
  {
    v9 = dma_buf;
    if ( (a3 & 1) != 0 )
    {
      v10 = cvp_kmem_cache_zalloc(cvp_driver + 120, 3264);
      v11 = v10;
      if ( v10 )
      {
        v12 = *(_DWORD *)(v10 + 88);
        *(_QWORD *)(v10 + 48) = v9;
        *(_BYTE *)(v10 + 84) = 0;
        *(_DWORD *)(v10 + 88) = v12 | 0x100;
        *(_DWORD *)(v10 + 92) = a4;
        *(_DWORD *)(v10 + 100) = *a2;
LABEL_62:
        _X8 = (unsigned int *)(v11 + 40);
        __asm { PRFM            #0x11, [X8] }
        do
          v36 = __ldxr(_X8);
        while ( __stxr(v36 + 1, _X8) );
        if ( (unsigned int)msm_cvp_map_smem((__int64)a1, v11, (__int64)"map cpu") )
        {
LABEL_48:
          msm_cvp_smem_put_dma_buf(v9);
          cvp_kmem_cache_free(cvp_driver + 120, v11);
          return 0;
        }
        v13 = a2[1];
        v14 = *(_DWORD *)(v11 + 80);
        if ( v13 > v14 || v13 > v14 - a2[2] )
        {
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            StatusReg = _ReadStatusReg(SP_EL0);
            printk(&unk_918C3, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
          }
LABEL_44:
          if ( (unsigned int)msm_cvp_unmap_smem((__int64)a1, v11, (__int64)"unmap cpu")
            && (msm_cvp_debug & 1) != 0
            && !msm_cvp_debug_out )
          {
            v32 = _ReadStatusReg(SP_EL0);
            printk(&unk_86E2C, *(unsigned int *)(v32 + 1800), *(unsigned int *)(v32 + 1804), &unk_8E7CE);
          }
          goto LABEL_48;
        }
      }
    }
    else
    {
      mutex_lock(a1 + 67);
      v11 = a1[73];
      if ( !v11 )
      {
LABEL_20:
        mutex_unlock(a1 + 67);
        mutex_lock(a1 + 52);
        for ( i = (_QWORD *)a1[50]; i != a1 + 50; i = (_QWORD *)*i )
        {
          v11 = i[7];
          if ( v11 && *(_QWORD *)(v11 + 48) == v9 )
          {
            _X8 = (unsigned int *)(v11 + 40);
            __asm { PRFM            #0x11, [X8] }
            do
              v52 = __ldxr(_X8);
            while ( __stxr(v52 + 1, _X8) );
            mutex_unlock(a1 + 52);
            v23 = "found in persist";
LABEL_36:
            print_smem(0x40u, (__int64)v23, (__int64)a1, v11);
            goto LABEL_50;
          }
        }
        mutex_unlock(a1 + 52);
        mutex_lock(a1 + 85);
        for ( j = (__int64 **)a1[83]; j != a1 + 83; j = (__int64 **)*j )
        {
          v20 = *((unsigned int *)j + 644);
          if ( (_DWORD)v20 )
          {
            v21 = v20 << 6;
            v22 = 0;
            while ( 1 )
            {
              if ( v22 == 2560 )
              {
                __break(0x5512u);
                goto LABEL_62;
              }
              v11 = (__int64)j[v22 / 8 + 9];
              if ( v11 )
              {
                if ( *(_QWORD *)(v11 + 48) == v9 )
                  break;
              }
              v22 += 64LL;
              if ( v21 == v22 )
                goto LABEL_27;
            }
            _X8 = (unsigned int *)(v11 + 40);
            __asm { PRFM            #0x11, [X8] }
            do
              v42 = __ldxr(_X8);
            while ( __stxr(v42 + 1, _X8) );
            mutex_unlock(a1 + 85);
            v23 = "found in frame";
            goto LABEL_36;
          }
LABEL_27:
          ;
        }
        mutex_unlock(a1 + 85);
        v24 = cvp_kmem_cache_zalloc(cvp_driver + 120, 3264);
        v11 = v24;
        if ( !v24 )
          return v11;
        *(_QWORD *)(v24 + 48) = v9;
        *(_BYTE *)(v24 + 84) = 0;
        *(_DWORD *)(v24 + 92) = a4;
        *(_DWORD *)(v24 + 100) = *a2;
        if ( !(unsigned int)msm_cvp_map_smem((__int64)a1, v24, (__int64)"map cpu") )
        {
          v25 = a2[1];
          v26 = *(_DWORD *)(v11 + 80);
          if ( v25 <= v26 && v25 <= v26 - a2[2] )
          {
            v31 = msm_cvp_session_add_smem(a1, v11);
            if ( v31 == -12 || !v31 )
              return v11;
          }
          else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v33 = _ReadStatusReg(SP_EL0);
            printk(&unk_94628, *(unsigned int *)(v33 + 1800), *(unsigned int *)(v33 + 1804), &unk_8E7CE);
          }
          goto LABEL_44;
        }
        goto LABEL_48;
      }
      while ( 1 )
      {
        while ( 1 )
        {
          v17 = *(_QWORD *)(v11 + 48);
          if ( v17 <= v9 )
            break;
          v11 = *(_QWORD *)(v11 + 16);
          if ( !v11 )
            goto LABEL_20;
        }
        if ( v17 >= v9 )
          break;
        v11 = *(_QWORD *)(v11 + 8);
        if ( !v11 )
          goto LABEL_20;
      }
      *(_DWORD *)(v11 + 92) = a4;
      *(_BYTE *)(v11 + 84) = 1;
      _X8 = (unsigned int *)(v11 + 40);
      __asm { PRFM            #0x11, [X8] }
      do
        v45 = __ldxr(_X8);
      while ( __stxr(v45 + 1, _X8) );
      msm_cvp_smem_put_dma_buf(*(_QWORD *)(v11 + 48));
      print_smem(0x40u, (__int64)"found in cache", (__int64)a1, v11);
      mutex_unlock(a1 + 67);
LABEL_50:
      v27 = a2[1];
      v28 = *(_DWORD *)(v11 + 80);
      if ( v27 > v28 || v27 > v28 - a2[2] )
      {
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v30 = _ReadStatusReg(SP_EL0);
          printk(&unk_88EA4, *(unsigned int *)(v30 + 1800), *(unsigned int *)(v30 + 1804), &unk_8E7CE);
        }
        mutex_lock(a1 + 67);
        _X8 = (unsigned int *)(v11 + 40);
        __asm { PRFM            #0x11, [X8] }
        do
          v39 = __ldxr(_X8);
        while ( __stxr(v39 - 1, _X8) );
        mutex_unlock(a1 + 67);
        return 0;
      }
    }
  }
  else
  {
    v11 = 0;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v16 = _ReadStatusReg(SP_EL0);
      printk(&unk_8F7A3, *(unsigned int *)(v16 + 1800), *(unsigned int *)(v16 + 1804), &unk_8E7CE);
      return 0;
    }
  }
  return v11;
}
