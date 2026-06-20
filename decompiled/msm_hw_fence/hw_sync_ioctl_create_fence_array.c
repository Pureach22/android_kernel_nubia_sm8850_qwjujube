__int64 __fastcall hw_sync_ioctl_create_fence_array(__int64 a1, unsigned __int64 a2)
{
  __int64 *v2; // x19
  unsigned __int64 v3; // x22
  __int64 v4; // x30
  __int64 v5; // x4
  __int64 v6; // x20
  unsigned int v8; // w5
  unsigned __int64 v9; // x8
  unsigned __int64 StatusReg; // x25
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x2
  __int64 result; // x0
  unsigned __int64 v14; // x8
  unsigned __int64 v19; // x9
  unsigned __int64 v21; // x8
  unsigned __int64 v23; // x9
  __int64 v24; // x24
  __int64 fence; // x0
  __int64 v26; // x0
  __int64 v27; // x4
  __int64 v28; // x25
  int unused_fd_flags; // w19
  __int64 v30; // x0
  _QWORD *v31; // x21
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  unsigned __int64 v42; // x20
  unsigned __int64 v43; // x25
  __int64 v44; // x8
  int v47; // w8
  unsigned int v48; // w20
  unsigned __int64 v49; // x8
  unsigned __int64 v50; // x8
  char v52; // w21
  __int64 v53; // x8
  int v56; // w8
  __int64 v57; // x20
  int v59; // w8
  __int64 v60; // [xsp+0h] [xbp-70h] BYREF
  __int64 v61; // [xsp+8h] [xbp-68h]
  __int64 v62; // [xsp+10h] [xbp-60h]
  __int64 v63; // [xsp+18h] [xbp-58h]
  __int64 v64; // [xsp+20h] [xbp-50h]
  __int64 v65; // [xsp+28h] [xbp-48h]
  __int64 v66; // [xsp+30h] [xbp-40h]
  __int64 v67; // [xsp+38h] [xbp-38h]
  __int64 v68; // [xsp+40h] [xbp-30h]
  __int64 v69; // [xsp+48h] [xbp-28h]
  __int64 v70; // [xsp+50h] [xbp-20h]
  __int64 v71; // [xsp+58h] [xbp-18h]
  __int64 v72; // [xsp+60h] [xbp-10h]
  __int64 v73; // [xsp+68h] [xbp-8h]

  v73 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    result = -22;
    goto LABEL_127;
  }
  v5 = *(unsigned int *)(a1 + 8);
  v6 = v4;
  v71 = 0;
  v72 = 0;
  v69 = 0;
  v70 = 0;
  v8 = *(_DWORD *)(hw_fence_drv_data + 744);
  v67 = 0;
  v68 = 0;
  v65 = 0;
  v66 = 0;
  v63 = 0;
  v64 = 0;
  v61 = 0;
  v62 = 0;
  v60 = 0;
  if ( (unsigned int)v5 < v8 || (unsigned int)v5 >= v8 + 11 )
  {
    printk(&unk_29FBA, "_is_valid_client", 137, v4, v5);
    result = -22;
    goto LABEL_127;
  }
  v9 = *(_QWORD *)(a1 + 16);
  if ( !v9 || v9 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_2939C, "hw_sync_ioctl_create_fence_array", 331, v4, v5);
    result = -22;
    goto LABEL_127;
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v11 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v11 = a2 & ((__int64)(a2 << 8) >> 8);
  if ( v11 > 0x7FFFFFFF98LL )
  {
    v12 = 104;
LABEL_11:
    if ( v12 >= 0x69 )
    {
      while ( 1 )
      {
        _fortify_panic(15, 0, v12);
LABEL_116:
        v48 = 6;
LABEL_92:
        v49 = 8LL * v48;
        _CF = v3 >= v49;
        v50 = v3 - v49;
        v3 = v48 + 1;
        _CF = _CF && v50 >= 8;
        v52 = !_CF;
        while ( (v52 & 1) == 0 )
        {
          v53 = v2[v48];
          if ( v53 )
          {
            _X0 = (unsigned int *)(v53 + 56);
            __asm { PRFM            #0x11, [X0] }
            do
              v56 = __ldxr(_X0);
            while ( __stlxr(v56 - 1, _X0) );
            if ( v56 == 1 )
            {
              __dmb(9u);
              dma_fence_release(_X0);
            }
            else if ( v56 <= 0 )
            {
              refcount_warn_saturate(_X0, 3);
            }
          }
          _VF = __OFSUB__((_DWORD)v3, 1);
          v3 = (unsigned int)(v3 - 1);
          if ( ((v3 & 0x80000000) != 0LL) ^ _VF | ((_DWORD)v3 == 0) )
            goto LABEL_107;
        }
LABEL_114:
        __break(1u);
      }
    }
    result = -14;
    goto LABEL_127;
  }
  v14 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v19 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v19 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v19);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v14);
  v12 = _arch_copy_from_user(&v60, a2 & 0xFF7FFFFFFFFFFFFFLL, 104);
  v21 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v23 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v23 - 4096);
  _WriteStatusReg(TTBR1_EL1, v23);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v21);
  if ( v12 )
    goto LABEL_11;
  v24 = (unsigned int)v61;
  if ( (int)v61 >= 11 )
  {
    printk(&unk_24C9B, "hw_sync_ioctl_create_fence_array", 341, v6, (unsigned int)v61);
    result = -22;
    goto LABEL_127;
  }
  if ( (v61 & 0x80000000) != 0 || (v3 = 8LL * (unsigned int)v61, (v2 = (__int64 *)_kmalloc_noprof(v3, 3520)) == nullptr) )
  {
    result = -12;
    goto LABEL_127;
  }
  if ( (int)v24 >= 1 )
  {
    if ( (int)v62 <= 0 )
      goto LABEL_107;
    fence = sync_file_get_fence((unsigned int)v62);
    if ( !fence )
      goto LABEL_107;
    if ( v3 < 8 )
      goto LABEL_114;
    *v2 = fence;
    if ( (_DWORD)v24 == 1 )
      goto LABEL_23;
    if ( (int)v63 < 1 )
      goto LABEL_107;
    v33 = sync_file_get_fence((unsigned int)v63);
    if ( !v33 )
    {
      v48 = 0;
      goto LABEL_92;
    }
    if ( (v3 & 0x7FFFFFFF8LL) == 8 )
      goto LABEL_114;
    v2[1] = v33;
    if ( (_DWORD)v24 != 2 )
    {
      if ( (int)v64 < 1 )
        goto LABEL_107;
      v34 = sync_file_get_fence((unsigned int)v64);
      if ( !v34 )
      {
        v48 = 1;
        goto LABEL_92;
      }
      if ( v3 < 0x10 || (v3 & 0x7FFFFFFF8LL) == 0x10 )
        goto LABEL_114;
      v2[2] = v34;
      if ( (_DWORD)v24 != 3 )
      {
        if ( (int)v65 < 1 )
          goto LABEL_107;
        v35 = sync_file_get_fence((unsigned int)v65);
        if ( !v35 )
        {
          v48 = 2;
          goto LABEL_92;
        }
        if ( v3 < 0x18 || (v3 & 0x7FFFFFFF8LL) == 0x18 )
          goto LABEL_114;
        v2[3] = v35;
        if ( (_DWORD)v24 != 4 )
        {
          if ( (int)v66 < 1 )
            goto LABEL_107;
          v36 = sync_file_get_fence((unsigned int)v66);
          if ( !v36 )
          {
            v48 = 3;
            goto LABEL_92;
          }
          if ( v3 < 0x20 || (v3 & 0x7FFFFFFF8LL) == 0x20 )
            goto LABEL_114;
          v2[4] = v36;
          if ( (_DWORD)v24 != 5 )
          {
            if ( (int)v67 < 1 )
              goto LABEL_107;
            v37 = sync_file_get_fence((unsigned int)v67);
            if ( !v37 )
            {
              v48 = 4;
              goto LABEL_92;
            }
            if ( v3 < 0x28 || (v3 & 0x7FFFFFFF8LL) == 0x28 )
              goto LABEL_114;
            v2[5] = v37;
            if ( (_DWORD)v24 != 6 )
            {
              if ( (int)v68 < 1 )
                goto LABEL_107;
              v38 = sync_file_get_fence((unsigned int)v68);
              if ( !v38 )
              {
                v48 = 5;
                goto LABEL_92;
              }
              if ( v3 < 0x30 || (v3 & 0x7FFFFFFF8LL) == 0x30 )
                goto LABEL_114;
              v2[6] = v38;
              if ( (_DWORD)v24 != 7 )
              {
                if ( (int)v69 < 1 )
                  goto LABEL_107;
                v39 = sync_file_get_fence((unsigned int)v69);
                if ( !v39 )
                  goto LABEL_116;
                if ( v3 < 0x38 || (v3 & 0x7FFFFFFF8LL) == 0x38 )
                  goto LABEL_114;
                v2[7] = v39;
                if ( (_DWORD)v24 != 8 )
                {
                  if ( (int)v70 < 1 )
                    goto LABEL_107;
                  v40 = sync_file_get_fence((unsigned int)v70);
                  if ( !v40 )
                  {
                    v48 = 7;
                    goto LABEL_92;
                  }
                  if ( v3 < 0x40 || (v3 & 0x7FFFFFFF8LL) == 0x40 )
                    goto LABEL_114;
                  v2[8] = v40;
                  if ( (_DWORD)v24 != 9 )
                  {
                    if ( (int)v71 >= 1 )
                    {
                      v41 = sync_file_get_fence((unsigned int)v71);
                      if ( !v41 )
                      {
                        v48 = 8;
                        goto LABEL_92;
                      }
                      if ( v3 < 0x48 || (v3 & 0x7FFFFFFF8LL) == 0x48 )
                        goto LABEL_114;
                      v2[9] = v41;
                      goto LABEL_23;
                    }
LABEL_107:
                    kfree(v2);
                    result = -22;
                    goto LABEL_127;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LABEL_23:
  v26 = dma_fence_array_create((unsigned int)v24, v2, *(_QWORD *)a1, (unsigned int)v60, 0);
  if ( !v26 )
  {
    printk(&unk_2770D, "hw_sync_ioctl_create_fence_array", 368, v6, v27);
    if ( (int)v24 >= 1 )
    {
      v42 = 0;
      v43 = v3;
      do
      {
        if ( (v42 & 0x8000000000000000LL) != 0 )
          goto LABEL_114;
        if ( v3 < v42 )
          goto LABEL_114;
        _CF = v43 >= 8;
        v43 -= 8LL;
        if ( !_CF )
          goto LABEL_114;
        v44 = v2[v42 / 8];
        if ( v44 )
        {
          _X0 = (unsigned int *)(v44 + 56);
          __asm { PRFM            #0x11, [X0] }
          do
            v47 = __ldxr(_X0);
          while ( __stlxr(v47 - 1, _X0) );
          if ( v47 == 1 )
          {
            __dmb(9u);
            dma_fence_release(_X0);
          }
          else if ( v47 <= 0 )
          {
            refcount_warn_saturate(_X0, 3);
          }
        }
        v42 += 8LL;
      }
      while ( 8 * v24 != v42 );
    }
    goto LABEL_107;
  }
  v28 = v26;
  unused_fd_flags = get_unused_fd_flags(0);
  if ( unused_fd_flags <= 0 )
  {
    printk(&unk_24266, "hw_sync_ioctl_create_fence_array", 379, v6, *(unsigned int *)(a1 + 8));
    dma_fence_put_0(v28);
    result = unused_fd_flags;
  }
  else
  {
    v30 = sync_file_create(v28);
    if ( v30 )
    {
      v31 = (_QWORD *)v30;
      _X0 = (unsigned int *)(v28 + 56);
      __asm { PRFM            #0x11, [X0] }
      do
        v59 = __ldxr(_X0);
      while ( __stlxr(v59 - 1, _X0) );
      if ( v59 == 1 )
      {
        __dmb(9u);
        dma_fence_release(_X0);
      }
      else if ( v59 <= 0 )
      {
        refcount_warn_saturate(_X0, 3);
      }
      LODWORD(v72) = unused_fd_flags;
      if ( !inline_copy_to_user(a2, &v60, 104) )
      {
        fd_install((unsigned int)unused_fd_flags, *v31);
        result = 0;
        goto LABEL_127;
      }
      fput(*v31);
      dma_fence_put_0(v28);
      v57 = -14;
    }
    else
    {
      printk(&unk_24707, "hw_sync_ioctl_create_fence_array", 386, v6, (unsigned int)unused_fd_flags);
      dma_fence_put_0(v28);
      kfree(v28);
      v57 = -22;
    }
    put_unused_fd((unsigned int)unused_fd_flags);
    result = v57;
  }
LABEL_127:
  _ReadStatusReg(SP_EL0);
  return result;
}
