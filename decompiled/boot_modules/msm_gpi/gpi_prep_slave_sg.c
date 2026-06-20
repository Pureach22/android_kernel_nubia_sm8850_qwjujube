__int64 __fastcall gpi_prep_slave_sg(__int64 a1, __int64 a2, int a3, unsigned int a4, int a5, __int64 a6, __int64 a7)
{
  __int64 v7; // x20
  __int64 v8; // x28
  __int64 v12; // x6
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x9
  unsigned int v15; // w23
  unsigned int v16; // w24
  __int64 result; // x0
  int v18; // w25
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x4
  __int64 v22; // x5
  __int64 v23; // x6
  int v24; // w27
  __int64 v25; // x26
  unsigned __int64 v26; // x24
  unsigned int v27; // w23
  __int64 v28; // x10
  unsigned __int64 v29; // x10
  __int64 v30; // x9
  __int64 v31; // x8
  __int64 v32; // x9
  _QWORD *v33; // x8
  unsigned __int64 v34; // x11
  __int64 v35; // x0
  __int64 v36; // x8
  __int64 v37; // x0
  _QWORD *v38; // x8
  __int64 v39; // x2
  _QWORD *v40; // x1
  __int64 v41; // x9
  __int64 v42; // x4
  __int64 v43; // x5
  __int64 v44; // x6
  unsigned int v45; // w21
  __int64 v46; // [xsp+8h] [xbp-18h]

  v7 = *(_QWORD *)(a1 + 280);
  v8 = *(_QWORD *)(a1 + 352);
  *(_DWORD *)(a1 + 388) = a3;
  if ( a4 - 1 >= 3 )
  {
    if ( *(_DWORD *)(v7 + 1068) >= 2u )
    {
      v45 = a4;
      printk(&unk_12203, v7 + 1076, *(unsigned int *)(a1 + 256), "gpi_prep_slave_sg", a4, a6, a7);
      a4 = v45;
      result = *(_QWORD *)(v7 + 1056);
      if ( !result )
        return result;
    }
    else
    {
      result = *(_QWORD *)(v7 + 1056);
      if ( !result )
        return result;
    }
    if ( *(_DWORD *)(v7 + 1064) >= 2u )
      ipc_log_string(result, "ch:%u %s: invalid dma direction: %d\n", *(_DWORD *)(a1 + 256), "gpi_prep_slave_sg", a4);
    return 0;
  }
  if ( (~(unsigned int)readl_relaxed(*(_QWORD *)(a1 + 296)) & 0xF00000) == 0 )
    gpi_dump_debug_reg((unsigned int *)v7);
  v13 = *(_QWORD *)(v8 + 40);
  v14 = *(_QWORD *)(v8 + 48);
  if ( v13 >= v14 )
  {
    v15 = (__int64)(v14 - *(_QWORD *)(v8 + 32)) / *(unsigned int *)(v8 + 60)
        + (__int64)(*(_QWORD *)(v8 + 32) + *(unsigned int *)(v8 + 56) - v13) / *(unsigned int *)(v8 + 60)
        - 1;
    v16 = 0;
    if ( !a3 )
      goto LABEL_14;
  }
  else
  {
    v15 = (__int64)(v14 - v13) / *(unsigned int *)(v8 + 60) - 1;
    v16 = 0;
    if ( !a3 )
      goto LABEL_14;
  }
  v18 = a3;
  v19 = a2;
  do
  {
    v16 += *(_DWORD *)(v19 + 12) / *(_DWORD *)(v8 + 60);
    v19 = ((__int64 (*)(void))sg_next)();
    --v18;
  }
  while ( v18 );
LABEL_14:
  if ( v15 < v16 )
  {
    if ( *(_DWORD *)(v7 + 1068) >= 2u )
    {
      printk(&unk_13B84, v7 + 1076, *(unsigned int *)(a1 + 256), "gpi_prep_slave_sg", v15, v16, v12);
      result = *(_QWORD *)(v7 + 1056);
      if ( !result )
        return result;
    }
    else
    {
      result = *(_QWORD *)(v7 + 1056);
      if ( !result )
        return result;
    }
    if ( *(_DWORD *)(v7 + 1064) >= 2u )
      ipc_log_string(
        result,
        "ch:%u %s: not enough space in ring, avail:%u required:%u\n",
        *(_DWORD *)(a1 + 256),
        "gpi_prep_slave_sg",
        v15,
        v16);
    return 0;
  }
  v20 = _kmalloc_cache_noprof(printk, 2336, 192);
  if ( !v20 )
  {
    if ( *(_DWORD *)(v7 + 1068) >= 2u )
    {
      printk(&unk_13BC0, v7 + 1076, *(unsigned int *)(a1 + 256), "gpi_prep_slave_sg", v21, v22, v23);
      result = *(_QWORD *)(v7 + 1056);
      if ( !result )
        return result;
    }
    else
    {
      result = *(_QWORD *)(v7 + 1056);
      if ( !result )
        return result;
    }
    if ( *(_DWORD *)(v7 + 1064) >= 2u )
      ipc_log_string(
        result,
        "ch:%u %s: out of memory for descriptor\n",
        *(unsigned int *)(a1 + 256),
        "gpi_prep_slave_sg");
    return 0;
  }
  v46 = v20;
  if ( a3 )
  {
    v24 = 0;
    v25 = 0;
    while ( 1 )
    {
      v26 = (((*(_QWORD *)a2 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
          + *(unsigned int *)(a2 + 8);
      if ( !v26 )
      {
        kfree(v46);
        if ( *(_DWORD *)(v7 + 1068) >= 2u )
        {
          printk(&unk_12455, v7 + 1076, *(unsigned int *)(a1 + 256), "gpi_prep_slave_sg", v42, v43, v44);
          result = *(_QWORD *)(v7 + 1056);
          if ( !result )
            return result;
        }
        else
        {
          result = *(_QWORD *)(v7 + 1056);
          if ( !result )
            return result;
        }
        if ( *(_DWORD *)(v7 + 1064) >= 2u )
          ipc_log_string(result, "ch:%u %s: TRE address is null\n", *(unsigned int *)(a1 + 256), "gpi_prep_slave_sg");
        return 0;
      }
      if ( a3 == 1 )
        *(_DWORD *)(a1 + 384) = byte_E[(((*(_QWORD *)a2 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL
                                      | 0xFF00000000000000LL)
                                     + *(unsigned int *)(a2 + 8)] << 16 == 3145728;
      if ( v24 == a3 - 1 )
        *(_BYTE *)(v7 + 1472) = *(unsigned __int8 *)(v26 + 14) << 16 == 3211264;
      if ( *(_DWORD *)(a2 + 12) )
        break;
LABEL_22:
      ++v24;
      a2 = sg_next(a2);
      if ( v24 == a3 )
        goto LABEL_44;
    }
    v27 = 0;
    while ( 1 )
    {
      v32 = *(_QWORD *)(a1 + 352);
      v33 = *(_QWORD **)(v32 + 40);
      v34 = *(_QWORD *)(v32 + 48);
      if ( (unsigned __int64)v33 >= v34 )
      {
        v28 = *(unsigned int *)(v32 + 60);
        if ( (int)((__int64)(v34 - *(_QWORD *)(v32 + 32)) / v28
                 + (*(_QWORD *)(v32 + 32) + *(unsigned int *)(v32 + 56) - (_QWORD)v33) / v28
                 - 1) > 0 )
          goto LABEL_31;
      }
      else
      {
        v28 = *(unsigned int *)(v32 + 60);
        if ( (int)((__int64)(v34 - (_QWORD)v33) / v28 - 1) > 0 )
        {
LABEL_31:
          v29 = (unsigned __int64)v33 + v28;
          v25 = *(_QWORD *)(v32 + 40);
          if ( v29 >= *(_QWORD *)(v32 + 32) + (unsigned __int64)*(unsigned int *)(v32 + 56) )
            v29 = *(_QWORD *)(v32 + 32);
          *(_QWORD *)(v32 + 40) = v29;
          __dmb(0xAu);
          v30 = *(_QWORD *)(v26 + 8);
          *v33 = *(_QWORD *)v26;
          v33[1] = v30;
          goto LABEL_34;
        }
      }
      if ( *(_DWORD *)(v7 + 1068) )
      {
        printk(&unk_11D45, v7 + 1076, *(unsigned int *)(a1 + 256), "gpi_queue_xfer", v21, v22, v23);
        v35 = *(_QWORD *)(v7 + 1056);
        if ( v35 )
        {
LABEL_39:
          if ( *(_DWORD *)(v7 + 1064) )
            ipc_log_string(
              v35,
              "ch:%u %s: Error adding ring element to xfer ring\n",
              *(_DWORD *)(a1 + 256),
              "gpi_queue_xfer");
        }
      }
      else
      {
        v35 = *(_QWORD *)(v7 + 1056);
        if ( v35 )
          goto LABEL_39;
      }
LABEL_34:
      v31 = *(unsigned int *)(v8 + 60);
      v27 += v31;
      v26 += v31;
      if ( v27 >= *(_DWORD *)(a2 + 12) )
        goto LABEL_22;
    }
  }
  v25 = 0;
LABEL_44:
  v36 = *(_QWORD *)(v8 + 40);
  *(_QWORD *)(v46 + 168) = v25;
  *(_QWORD *)(v46 + 176) = v36;
  *(_QWORD *)(v46 + 184) = a1;
  dma_async_tx_descriptor_init(v46, a1);
  *(_QWORD *)(v46 + 144) = 0;
  *(_DWORD *)(v46 + 4) = a5;
  *(_QWORD *)(v46 + 24) = &vchan_tx_submit;
  *(_QWORD *)(v46 + 32) = &vchan_tx_desc_free;
  v37 = raw_spin_lock_irqsave(a1 + 160);
  v38 = (_QWORD *)(v46 + 152);
  v39 = a1 + 168;
  v40 = *(_QWORD **)(a1 + 176);
  v41 = v37;
  if ( v46 + 152 == a1 + 168 || v40 == v38 || *v40 != v39 )
  {
    _list_add_valid_or_report(v46 + 152, v40);
  }
  else
  {
    *(_QWORD *)(a1 + 176) = v38;
    *(_QWORD *)(v46 + 152) = v39;
    *(_QWORD *)(v46 + 160) = v40;
    *v40 = v38;
  }
  raw_spin_unlock_irqrestore(a1 + 160, v41);
  return v46;
}
