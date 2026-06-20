char *__fastcall firmware_request_from_smcinvoke(const char *a1, _QWORD *a2, __int64 a3)
{
  unsigned int v6; // w0
  __int64 v7; // x24
  __int64 v8; // x2
  __int64 v9; // x25
  unsigned __int64 v10; // x22
  __int64 v11; // x0
  __int64 v12; // x21
  __int64 v13; // x9
  __int64 v14; // x8
  __int64 v15; // x10
  __int64 v16; // x12
  __int64 v17; // x0
  __int64 v18; // x8
  unsigned __int64 v19; // x11
  __int64 v20; // x10
  __int64 v21; // x12
  int v22; // w24
  __int64 v23; // x2
  unsigned __int64 v24; // x8
  bool v25; // cf
  unsigned __int64 v26; // x8
  __int64 v27; // x2
  char *v28; // x23
  __int64 v29; // x28
  unsigned __int64 v30; // x19
  int v31; // w25
  unsigned __int64 v32; // x24
  __int64 v33; // x2
  __int64 v34; // x27
  __int64 v35; // x10
  __int64 v37; // [xsp+0h] [xbp-140h]
  __int64 v38; // [xsp+8h] [xbp-138h]
  __int64 v39; // [xsp+10h] [xbp-130h] BYREF
  __int64 v40; // [xsp+18h] [xbp-128h] BYREF
  __int64 v41; // [xsp+20h] [xbp-120h] BYREF
  char s[261]; // [xsp+2Bh] [xbp-115h] BYREF
  __int64 v43; // [xsp+130h] [xbp-10h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v40 = 0;
  v41 = 0;
  v39 = 0;
  memset(s, 0, sizeof(s));
  snprintf(s, 0x105u, "%s.b00", a1);
  v6 = firmware_request_nowarn(&v40, s, smci_dev);
  if ( !v6 )
  {
    v7 = *(_QWORD *)(v40 + 8);
    v8 = *(unsigned __int8 *)(v7 + 4);
    if ( (_DWORD)v8 == 2 )
    {
      v9 = *(unsigned __int16 *)(v7 + 56);
      v10 = 8 * v9;
      v17 = _kmalloc_noprof(8 * v9, print_fmt_cbo_dispatch_wait);
      v12 = v17;
      if ( !v17 )
        goto LABEL_37;
      if ( (unsigned int)v9 >= 2 )
      {
        v18 = v40;
        v19 = 8;
        v20 = *(_QWORD *)(v7 + 32) + 64LL;
        do
        {
          if ( v10 <= v19 )
            goto LABEL_41;
          v21 = *(_QWORD *)(*(_QWORD *)(v18 + 8) + v20);
          v20 += 56;
          *(_QWORD *)(v17 + v19) = v21;
          v19 += 8LL;
        }
        while ( 8 * v9 != v19 );
      }
    }
    else
    {
      if ( (_DWORD)v8 != 1 )
      {
        printk(&unk_10375, a1, v8);
        v12 = 0;
        goto LABEL_37;
      }
      v9 = *(unsigned __int16 *)(v7 + 44);
      v10 = 8 * v9;
      v11 = _kmalloc_noprof(8 * v9, print_fmt_cbo_dispatch_wait);
      v12 = v11;
      if ( !v11 )
      {
LABEL_37:
        v28 = nullptr;
LABEL_38:
        release_firmware(v40);
        kfree(v12);
        goto LABEL_39;
      }
      if ( (unsigned int)v9 >= 2 )
      {
        v13 = v40;
        v14 = 0;
        v15 = *(unsigned int *)(v7 + 28) + 36LL;
        do
        {
          v16 = v14 + 8;
          if ( v10 <= v14 + 8 )
            goto LABEL_41;
          *(_QWORD *)(v11 + v14 + 8) = *(unsigned int *)(*(_QWORD *)(v13 + 8) + v15 + 4 * v14);
          v14 += 8;
        }
        while ( 8 * v9 - 8 != v16 );
      }
    }
    v22 = v9 - 1;
    snprintf(s, 0x105u, "%s.b%02d", a1, v9 - 1);
    if ( !(unsigned int)firmware_request_nowarn(&v39, s, smci_dev) )
    {
      v24 = 8LL * v22;
      v25 = v10 >= v24;
      v26 = v10 - v24;
      if ( !v25 || v26 < 8 )
        goto LABEL_41;
      *a2 = *(_QWORD *)(v12 + 8LL * v22) + *(_QWORD *)v39;
      if ( (unsigned int)qtee_shmbridge_allocate_shm() )
      {
        printk(&unk_108D2, *a2, v27);
        v28 = nullptr;
      }
      else
      {
        v28 = *(char **)(a3 + 8);
        memcpy(v28, *(const void **)(v40 + 8), *(_QWORD *)v40);
        if ( (unsigned int)v9 < 3 )
        {
          v35 = 1;
          goto LABEL_29;
        }
        v29 = 8LL * (unsigned int)(v9 - 1);
        v37 = a3;
        v38 = (unsigned int)(v9 - 1);
        v30 = v10 - 8;
        v31 = 1;
        v32 = 8;
        while ( 1 )
        {
          snprintf(s, 0x105u, "%s.b%02d", a1, v31);
          if ( (unsigned int)firmware_request_nowarn(&v41, s, smci_dev) )
            break;
          if ( v10 < v32 )
            goto LABEL_41;
          v25 = v30 >= 8;
          v30 -= 8LL;
          if ( !v25 )
            goto LABEL_41;
          v34 = v41;
          memcpy(&v28[*(_QWORD *)(v12 + v32)], *(const void **)(v41 + 8), *(_QWORD *)v41);
          release_firmware(v34);
          v32 += 8LL;
          ++v31;
          v41 = 0;
          if ( v29 == v32 )
          {
            v35 = v38;
LABEL_29:
            if ( v10 >= 8 * v35 && v10 - 8 * v35 >= 8 )
            {
              memcpy(&v28[*(_QWORD *)(v12 + 8 * v35)], *(const void **)(v39 + 8), *(_QWORD *)v39);
              goto LABEL_32;
            }
LABEL_41:
            __break(1u);
          }
        }
        printk(&unk_1040D, s, v33);
        qtee_shmbridge_free_shm(v37);
        v28 = nullptr;
      }
LABEL_32:
      release_firmware(v39);
      goto LABEL_38;
    }
    printk(&unk_1040D, s, v23);
    goto LABEL_37;
  }
  printk(&unk_10927, s, v6);
  v28 = nullptr;
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return v28;
}
