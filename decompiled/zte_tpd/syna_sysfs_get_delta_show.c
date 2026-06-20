__int64 __fastcall syna_sysfs_get_delta_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x8
  _QWORD *v5; // x22
  __int64 v6; // x20
  __int64 v7; // x2
  __int64 v8; // x21
  _DWORD *v9; // x8
  unsigned int v10; // w19
  unsigned int v11; // w26
  __int16 *v12; // x23
  unsigned int v13; // w19
  int v14; // w19
  __int64 v15; // x0
  __int64 v16; // x2
  void *v17; // x0
  size_t v18; // x22
  const char *v19; // x27
  __int64 v20; // x0
  __int64 v21; // x2
  unsigned int v22; // w19
  unsigned int v23; // w19
  size_t v24; // x21
  size_t v25; // x25
  size_t v26; // x24
  size_t v27; // x0
  size_t v28; // x2
  __int64 v29; // x2
  __int64 v30; // x21
  __int64 v31; // x19
  void (__fastcall *v32)(__int64, __int64); // x8
  __int16 *v33; // x20
  __int64 v34; // x0
  __int64 v35; // x2
  __int64 result; // x0
  void *v37; // x0
  _QWORD *v38; // [xsp+0h] [xbp-70h]
  __int64 v39; // [xsp+8h] [xbp-68h]
  unsigned int v40; // [xsp+10h] [xbp-60h]
  unsigned int v41; // [xsp+14h] [xbp-5Ch]
  char s[4]; // [xsp+18h] [xbp-58h] BYREF
  __int16 v43; // [xsp+1Ch] [xbp-54h]
  __int16 *v44; // [xsp+20h] [xbp-50h] BYREF
  __int64 v45; // [xsp+28h] [xbp-48h]
  _QWORD v46[6]; // [xsp+30h] [xbp-40h] BYREF
  __int64 v47; // [xsp+60h] [xbp-10h]
  __int64 v48; // [xsp+68h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 24);
  v47 = 0;
  v5 = *(_QWORD **)(v4 + 152);
  memset(v46, 0, sizeof(v46));
  v6 = *v5;
  if ( (syna_tcm_enable_report(*v5, 18, 1, 10) & 0x80000000) != 0 )
  {
    LODWORD(result) = scnprintf(a3, 4096, "Fail to enable report %x\n", 18);
    goto LABEL_59;
  }
  v38 = v5;
  v39 = a3;
  if ( v6 )
  {
    v8 = *(_QWORD *)(v6 + 72);
    if ( v8 )
    {
      if ( *(_QWORD *)(v8 + 56) )
      {
        mutex_lock(v6 + 80);
        v9 = *(_DWORD **)(v8 + 56);
        if ( *(v9 - 1) != 875454897 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v9)(v8, 0);
        mutex_unlock(v6 + 80);
      }
      goto LABEL_8;
    }
    v37 = &unk_37DFA;
  }
  else
  {
    v37 = &unk_3365A;
  }
  printk(v37, "syna_tcm_enable_irq", v7);
LABEL_8:
  LOBYTE(v47) = 0;
  v44 = nullptr;
  v45 = 0;
  _mutex_init(v46, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_2);
  v10 = 0;
  v11 = 0;
  do
  {
    if ( (syna_tcm_wait_for_report(v6, 18, &v44, 100, 1000) & 0x80000000) == 0 && HIDWORD(v45) )
    {
      printk(&unk_3D2DB, "syna_sysfs_get_delta_show", ++v10);
      if ( !*(_DWORD *)(v6 + 28) )
        continue;
      v12 = v44;
      v40 = v10;
      v13 = 0;
      while ( 1 )
      {
        v41 = v13;
        v14 = *(_DWORD *)(v6 + 32);
        v15 = syna_request_managed_device();
        if ( v15 )
        {
          v18 = (unsigned int)(6 * v14);
          if ( (int)v18 > 0 )
          {
            v19 = (const char *)devm_kmalloc(v15, (unsigned int)(6 * v14), 3520);
            if ( *(_DWORD *)(v6 + 32) )
            {
LABEL_29:
              v23 = 0;
              while ( 1 )
              {
                v43 = 0;
                *(_DWORD *)s = 0;
                snprintf(s, 6u, "%4d ", *v12);
                v24 = *(unsigned int *)(v6 + 32);
                v25 = (unsigned int)(6 * v24);
                v26 = strnlen(v19, v25);
                if ( v26 == -1 )
                  break;
                v27 = strnlen(s, 6u);
                if ( v27 >= 7 )
                  goto LABEL_67;
                if ( v27 == 6 )
                  goto LABEL_68;
                if ( v26 < v25 )
                {
                  if ( v27 + v26 >= v25 )
                    v24 = v25 - 1;
                  else
                    v24 = v27 + v26;
                  if ( v24 == -1 )
                    goto LABEL_69;
                  if ( v27 + v26 >= v25 )
                    v28 = ~v26 + v25;
                  else
                    v28 = v27;
                  memcpy((void *)&v19[v26], s, v28);
                  if ( v18 <= v24 )
                    goto LABEL_70;
                  v19[v24] = 0;
                  LODWORD(v24) = *(_DWORD *)(v6 + 32);
                }
                ++v23;
                ++v12;
                if ( v23 >= (unsigned int)v24 )
                  goto LABEL_24;
              }
              v27 = _fortify_panic(2, -1, 0);
LABEL_67:
              _fortify_panic(2, 6, v27 + 1);
LABEL_68:
              _fortify_panic(4, 6, 7);
LABEL_69:
              _fortify_panic(9, -1, v24 + 1);
LABEL_70:
              __break(1u);
            }
            goto LABEL_24;
          }
          v17 = &unk_38286;
        }
        else
        {
          v17 = &unk_3BE43;
        }
        printk(v17, "syna_pal_mem_alloc", v16);
        v18 = 0;
        v19 = nullptr;
        if ( *(_DWORD *)(v6 + 32) )
          goto LABEL_29;
LABEL_24:
        printk(&unk_36715, "syna_sysfs_get_delta_show", v19);
        v20 = syna_request_managed_device();
        if ( v20 )
        {
          v22 = v41;
          if ( v19 )
            devm_kfree(v20, v19);
        }
        else
        {
          printk(&unk_3BE43, "syna_pal_mem_free", v21);
          v22 = v41;
        }
        v13 = v22 + 1;
        if ( v13 >= *(_DWORD *)(v6 + 28) )
        {
          v10 = v40;
          goto LABEL_12;
        }
      }
    }
    ++v11;
LABEL_12:
    ;
  }
  while ( v10 <= 1 && v11 < 5 );
  syna_tcm_enable_report(*v38, 18, 0, 10);
  if ( v6 )
  {
    v30 = *(_QWORD *)(v6 + 72);
    v31 = v39;
    if ( v30 )
    {
      if ( *(_QWORD *)(v30 + 56) )
      {
        mutex_lock(v6 + 80);
        v32 = *(void (__fastcall **)(__int64, __int64))(v30 + 56);
        if ( *((_DWORD *)v32 - 1) != 875454897 )
          __break(0x8228u);
        v32(v30, 1);
        mutex_unlock(v6 + 80);
      }
    }
    else
    {
      printk(&unk_37DFA, "syna_tcm_enable_irq", v29);
    }
  }
  else
  {
    printk(&unk_3365A, "syna_tcm_enable_irq", v29);
    v31 = v39;
  }
  if ( (_BYTE)v47 )
    printk(&unk_34845, "syna_tcm_buf_release", (unsigned __int8)v47);
  v33 = v44;
  v34 = syna_request_managed_device();
  if ( v34 )
  {
    if ( v33 )
      devm_kfree(v34, v33);
  }
  else
  {
    printk(&unk_3BE43, "syna_pal_mem_free", v35);
  }
  v45 = 0;
  LOBYTE(v47) = 0;
  LODWORD(result) = scnprintf(v31, 4096, "Done\n");
LABEL_59:
  _ReadStatusReg(SP_EL0);
  return (int)result;
}
