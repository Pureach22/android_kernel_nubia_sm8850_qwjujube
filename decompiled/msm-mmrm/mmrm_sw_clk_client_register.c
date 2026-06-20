_DWORD *__fastcall mmrm_sw_clk_client_register(__int64 a1, __int64 a2, int a3, __int64 a4, __int64 a5)
{
  _DWORD *v10; // x8
  __int64 v11; // x0
  _DWORD *v12; // x27
  _DWORD *v13; // x9
  __int64 v15; // x19
  _DWORD *v16; // x8
  __int64 v17; // x20
  _DWORD *v18; // x0
  size_t v19; // x0
  unsigned __int64 v20; // x2
  __int64 v21; // x8
  unsigned int v22; // w3
  unsigned int v23; // w4
  _DWORD *v24; // x0
  void *v25; // x8
  __int64 v26; // x9
  __int64 v27; // x0
  __int64 v28; // x21
  __int64 v29; // x0
  __int64 v30; // x20
  unsigned __int64 StatusReg; // x28
  __int64 (__fastcall *v32)(_QWORD, _QWORD, _QWORD); // x0
  __int64 v33; // [xsp+18h] [xbp-8h]

  mutex_lock();
  v10 = (_DWORD *)*(unsigned int *)(a1 + 72);
  v11 = a1;
  if ( (_DWORD)v10 == *(_DWORD *)(a1 + 76) )
  {
    if ( (~msm_mmrm_debug & 0x10001) != 0 )
      goto LABEL_12;
    printk(&unk_DEEE, "err ", "mmrm_sw_clk_client_register");
    goto LABEL_37;
  }
  if ( (_DWORD)v10 )
  {
    v12 = nullptr;
    v13 = (_DWORD *)(*(_QWORD *)(a1 + 64) + 160LL);
    while ( (*(_DWORD *)(a2 + 4) | (*(_DWORD *)a2 << 16)) != *v13 )
    {
      v12 = (_DWORD *)((char *)v12 + 1);
      v13 += 180;
      if ( v10 == v12 )
        goto LABEL_11;
    }
  }
  else
  {
    LODWORD(v12) = 0;
  }
  if ( (_DWORD)v12 == (_DWORD)v10 )
  {
LABEL_11:
    if ( (~msm_mmrm_debug & 0x10001) != 0 )
      goto LABEL_12;
    v25 = &unk_D9C6;
LABEL_36:
    a1 = v11;
    printk(v25, "err ", "mmrm_sw_clk_client_register");
LABEL_37:
    v11 = a1;
    goto LABEL_12;
  }
  v15 = *(_QWORD *)(a1 + 64) + 720LL * (unsigned int)v12;
  v16 = *(_DWORD **)(v15 + 656);
  if ( v16 )
  {
    if ( !msm_mmrm_allow_multiple_register )
    {
      if ( (~msm_mmrm_debug & 0x10001) != 0 )
        goto LABEL_12;
      v25 = &unk_CA5F;
      goto LABEL_36;
    }
    ++*(_DWORD *)(v15 + 680);
    if ( (~msm_mmrm_debug & 0x10002) == 0 )
    {
      v30 = v11;
      printk(&unk_C23D, "high", "mmrm_sw_clk_client_register");
      v16 = *(_DWORD **)(v15 + 656);
      v11 = v30;
    }
    v17 = v11;
    v12 = v16;
    mmrm_sw_print_client_data(v11 + 56, v15);
LABEL_20:
    mutex_unlock(v17);
    return v12;
  }
  v17 = v11;
  v18 = (_DWORD *)_kmalloc_cache_noprof(_mutex_init, 3520, 8);
  if ( !v18 )
  {
LABEL_52:
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
      printk(&unk_CC31, "err ", "mmrm_sw_clk_client_register");
    goto LABEL_54;
  }
  while ( 1 )
  {
    *v18 = 0;
    v18[1] = (_DWORD)v12;
    v12 = v18;
    *(_QWORD *)(v15 + 656) = v18;
    *(_DWORD *)(v15 + 680) = 1;
    v19 = strnlen((const char *)(a2 + 8), 0x80u);
    if ( v19 < 0x81 )
      break;
    _fortify_panic(2, 128, v19 + 1);
LABEL_51:
    _fortify_panic(7, 128, v20);
    StatusReg = _ReadStatusReg(SP_EL0);
    v32 = _mutex_init;
    v33 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &mmrm_sw_clk_client_register__alloc_tag;
    v18 = (_DWORD *)_kmalloc_cache_noprof(v32, 3520, 8);
    *(_QWORD *)(StatusReg + 80) = v33;
    if ( !v18 )
      goto LABEL_52;
  }
  if ( v19 == 128 )
    v20 = 128;
  else
    v20 = v19 + 1;
  if ( v20 >= 0x81 )
    goto LABEL_51;
  sized_strscpy(v15, a2 + 8);
  v21 = *(_QWORD *)(a2 + 136);
  *(_DWORD *)(v15 + 136) = a3;
  *(_QWORD *)(v15 + 144) = a4;
  *(_QWORD *)(v15 + 152) = a5;
  *(_QWORD *)(v15 + 128) = v21;
  v22 = *(_DWORD *)(a2 + 144);
  if ( v22 <= 6 )
  {
    v23 = *(_DWORD *)(a2 + 148);
    if ( v23 < 6 )
    {
      v26 = v17;
      if ( v22 && v23 )
      {
        if ( (~msm_mmrm_debug & 0x10002) == 0 )
        {
          printk(&unk_D54A, "high", "mmrm_sw_clk_client_register");
          v22 = *(_DWORD *)(a2 + 144);
          v23 = *(_DWORD *)(a2 + 148);
        }
        *(_DWORD *)(v15 + 704) = v23 * v22 + 1;
        v27 = _kmalloc_noprof(8LL * *(unsigned int *)(v15 + 704), 3520);
        *(_QWORD *)(v15 + 712) = v27;
        if ( !v27 )
        {
          if ( (~msm_mmrm_debug & 0x10001) == 0 )
            printk(&unk_D59F, "err ", "mmrm_sw_clk_client_register");
          v24 = v12;
          goto LABEL_58;
        }
        *(_DWORD *)(v15 + 700) = 0;
        v26 = v17;
        *(_BYTE *)(v15 + 688) = 1;
        *(_DWORD *)(v15 + 692) = *(_DWORD *)(a2 + 144);
        *(_DWORD *)(v15 + 696) = *(_DWORD *)(a2 + 148);
      }
      if ( (~msm_mmrm_debug & 0x10002) == 0 )
      {
        printk(&unk_DB95, "high", "mmrm_sw_clk_client_register");
        v26 = v17;
      }
      v28 = v26;
      mmrm_sw_update_freq(v26 + 56, v15);
      if ( !(unsigned int)mmrm_sw_update_curr(v28 + 56, v15) )
        goto LABEL_20;
      if ( (~msm_mmrm_debug & 0x10001) == 0 )
        printk(&unk_D706, "err ", "mmrm_sw_clk_client_register");
      v29 = *(_QWORD *)(v15 + 712);
      *(_BYTE *)(v15 + 688) = 0;
      *(_DWORD *)(v15 + 700) = 0;
      *(_QWORD *)(v15 + 692) = 0;
      kfree(v29);
      v24 = v12;
      *(_QWORD *)(v15 + 712) = 0;
LABEL_58:
      *(_DWORD *)(v15 + 704) = 0;
      goto LABEL_32;
    }
  }
  if ( (~msm_mmrm_debug & 0x10001) == 0 )
    printk(&unk_D203, "err ", "mmrm_sw_clk_client_register");
  v24 = v12;
LABEL_32:
  kfree(v24);
LABEL_54:
  v11 = v17;
  *(_QWORD *)(v15 + 656) = 0;
  *(_QWORD *)(v15 + 128) = 0;
  *(_DWORD *)(v15 + 136) = 0;
  *(_QWORD *)(v15 + 144) = 0;
  *(_QWORD *)(v15 + 152) = 0;
LABEL_12:
  mutex_unlock(v11);
  if ( (~msm_mmrm_debug & 0x10001) == 0 )
    printk(&unk_DA62, "err ", "mmrm_sw_clk_client_register");
  return nullptr;
}
