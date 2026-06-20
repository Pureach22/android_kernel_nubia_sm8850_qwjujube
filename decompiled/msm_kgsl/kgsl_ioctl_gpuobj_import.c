__int64 __fastcall kgsl_ioctl_gpuobj_import(const char ****a1, __int64 a2, __int64 *a3)
{
  const char ***v4; // x20
  const char ***v5; // x22
  __int64 v6; // x0
  const char **v7; // x24
  __int64 v9; // x8
  unsigned __int64 v10; // x25
  __int64 result; // x0
  __int64 v12; // x8
  unsigned __int64 v13; // x8
  __int64 v14; // x23
  __int64 v15; // x9
  size_t v16; // x25
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x9
  unsigned __int64 v19; // x8
  int v20; // w0
  __int64 v21; // x8
  int v22; // w24
  __int64 v23; // x1
  __int64 v24; // x9
  __int64 v25; // x10
  const char **v27; // x0
  const char *v28; // x0
  const char *v29; // x2
  unsigned __int64 v32; // x8
  unsigned __int64 v33; // x8
  unsigned __int64 v35; // x9
  unsigned __int64 v36; // x9
  unsigned int v43; // w9
  int v45; // w8
  _QWORD v46[2]; // [xsp+0h] [xbp-10h] BYREF

  v46[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a3[3] & 0xFFFFFFFE) == 2 )
  {
    if ( (*((_BYTE *)a3 + 20) & 4) != 0 )
    {
      result = -22;
    }
    else
    {
      v5 = *a1;
      v4 = a1[1];
      v6 = kgsl_mem_entry_create();
      if ( v6 )
      {
        v7 = v4[8];
        _X19 = v6;
        if ( *((_DWORD *)a3 + 6) == 2 )
        {
          v9 = a3[2];
          v46[0] = 0;
          a3[2] = v9 & 0x19D00FF00LL;
          kgsl_memdesc_init(v5, v6 + 8, v9 & 0x19D00FF00LL);
          if ( inline_copy_from_user_0((int)v46, *a3, 8u) )
          {
LABEL_6:
            LODWORD(v10) = -22;
            goto LABEL_29;
          }
          LODWORD(v10) = kgsl_setup_useraddr(v5, v7, _X19, v46[0], 0, a3[1]);
LABEL_29:
          if ( (_DWORD)v10 )
          {
LABEL_37:
            kfree(_X19);
            result = (int)v10;
            goto LABEL_38;
          }
          v18 = *(_QWORD *)(_X19 + 48);
          if ( v18 < 0x100000 )
          {
            v19 = *(_QWORD *)(_X19 + 80);
            if ( v18 < 0x10000 )
              goto LABEL_35;
            v19 = v19 & 0xFFFFFFFFFF00FFFFLL | 0x100000;
          }
          else
          {
            v19 = *(_QWORD *)(_X19 + 80) & 0xFFFFFFFFFF00FFFFLL | 0x140000;
          }
          *(_QWORD *)(_X19 + 80) = v19;
LABEL_35:
          a3[2] = v19;
          LODWORD(v10) = kgsl_mem_entry_attach_to_process(v5, v4, _X19);
          if ( (_DWORD)v10 )
          {
LABEL_36:
            kgsl_sharedmem_free(_X19 + 8);
            goto LABEL_37;
          }
          if ( *(_QWORD *)(_X19 + 32) )
          {
            v20 = kgsl_mmu_map(*(_QWORD *)(_X19 + 8), _X19 + 8);
            if ( v20 )
            {
              LODWORD(v10) = v20;
              kgsl_mem_entry_detach_process(_X19);
              goto LABEL_36;
            }
            v23 = *(_QWORD *)(_X19 + 32);
          }
          else
          {
            v23 = 0;
          }
          kgsl_memfree_purge(*(_QWORD *)(_X19 + 8), v23, *(_QWORD *)(_X19 + 48));
          *((_DWORD *)a3 + 7) = *(_DWORD *)(_X19 + 248);
          v24 = *(_QWORD *)(_X19 + 48);
          _X10 = &qword_3A8E8;
          __asm { PRFM            #0x11, [X10] }
          do
          {
            v32 = __ldxr((unsigned __int64 *)&qword_3A8E8);
            v33 = v32 + v24;
          }
          while ( __stlxr(v33, (unsigned __int64 *)&qword_3A8E8) );
          __dmb(0xBu);
          if ( v33 > qword_3A8F0 )
            qword_3A8F0 = v33;
          v25 = *(_QWORD *)(_X19 + 48);
          _X8 = (unsigned __int64 *)&v4[2 * ((unsigned __int8)*(_QWORD *)(_X19 + 80) >> 5) + 26];
          __asm { PRFM            #0x11, [X8] }
          do
          {
            v35 = __ldxr(_X8);
            v36 = v35 + v25;
          }
          while ( __stlxr(v36, _X8) );
          __dmb(0xBu);
          if ( v36 > _X8[1] )
            _X8[1] = v36;
          raw_spin_lock(*(_QWORD *)(_X19 + 256) + 32LL);
          idr_replace(*(_QWORD *)(_X19 + 256) + 40LL, _X19, *(unsigned int *)(_X19 + 248));
          raw_spin_unlock(*(_QWORD *)(_X19 + 256) + 32LL);
          if ( _X19 <= 0xFFFFFFFFFFFFF000LL )
          {
            __asm { PRFM            #0x11, [X19] }
            do
              v45 = __ldxr((unsigned int *)_X19);
            while ( __stlxr(v45 - 1, (unsigned int *)_X19) );
            if ( v45 == 1 )
            {
              __dmb(9u);
              kgsl_mem_entry_destroy((_QWORD *)_X19);
              result = 0;
              goto LABEL_38;
            }
            if ( v45 <= 0 )
            {
              refcount_warn_saturate(_X19, 3);
              result = 0;
              goto LABEL_38;
            }
          }
          result = 0;
          goto LABEL_38;
        }
        v12 = a3[2];
        LODWORD(v46[0]) = 0;
        a3[2] = v12 & 0x301FFFF08LL;
        kgsl_memdesc_init(v5, v6 + 8, v12 & 0x301FFFF08LL);
        if ( (*(_BYTE *)(_X19 + 80) & 8) != 0 )
        {
          if ( *((_BYTE *)v5 + 96) != 1 || (v17 = (unsigned __int64)v5[10]) == 0 || v17 >= 0xFFFFFFFFFFFFF001LL )
          {
            if ( (check_and_warn_secured___already_done & 1) == 0 )
            {
              v27 = *v5;
              check_and_warn_secured___already_done = 1;
              v28 = (const char *)dev_driver_string(v27);
              v29 = (*v5)[14];
              if ( !v29 )
                v29 = **v5;
              _warn_printk("%s %s: Secure buffers are not supported\n", v28, v29);
              __break(0x800u);
            }
            LODWORD(v10) = -524;
            goto LABEL_29;
          }
          _X8 = (unsigned int *)(_X19 + 56);
          __asm { PRFM            #0x11, [X8] }
          do
            v43 = __ldxr(_X8);
          while ( __stxr(v43 | 0x10, _X8) );
        }
        v14 = *a3;
        v13 = a3[1];
        v15 = 4;
        if ( v13 >= 4 )
          v16 = 4;
        else
          v16 = a3[1];
        if ( v13 > 4 )
          v15 = a3[1];
        if ( v13 > 3 )
        {
          if ( v13 != 4 && (int)check_zeroed_user(v14 + v16, v15 - v16) < 1 )
            goto LABEL_28;
        }
        else
        {
          memset((char *)v46 + v16, 0, v15 - v16);
        }
        _check_object_size(v46, v16, 0);
        if ( !inline_copy_from_user_0((int)v46, v14, v16) )
        {
          if ( (v46[0] & 0x80000000) != 0 )
            goto LABEL_6;
          v10 = dma_buf_get(LODWORD(v46[0]));
          if ( v10 < 0xFFFFFFFFFFFFF001LL )
          {
            v21 = *(_QWORD *)(_X19 + 80);
            *(_QWORD *)(_X19 + 80) = v21 | 0xC000000;
            if ( ((unsigned int)v5[13] & 8) != 0 )
              *(_QWORD *)(_X19 + 80) = v21 | 0x8C000000LL;
            v22 = kgsl_setup_dma_buf(v5, v7, _X19, v10);
            if ( v22 )
              dma_buf_put(v10);
            LODWORD(v10) = v22;
          }
          goto LABEL_29;
        }
LABEL_28:
        LODWORD(v10) = -14;
        goto LABEL_29;
      }
      result = -12;
    }
  }
  else
  {
    result = -524;
  }
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
