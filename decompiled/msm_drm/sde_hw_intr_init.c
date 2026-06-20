__int64 __fastcall sde_hw_intr_init(__int64 a1, int *a2)
{
  __int64 result; // x0
  __int64 v5; // x22
  int v6; // w8
  int v7; // w9
  __int64 v8; // x23
  int *v9; // x20
  __int64 v10; // x1
  int *v11; // x24
  bool v12; // zf
  unsigned int v13; // w19
  int v14; // w8
  int v15; // w4
  __int64 v16; // x8
  __int64 v17; // x8
  int *v18; // x26
  unsigned __int64 v19; // x27
  unsigned int v20; // w2
  void *v21; // x15
  const char *v22; // x5
  int v23; // w11
  int v24; // w10
  __int64 v25; // x1
  unsigned int v26; // w21
  void *v27; // x20
  const char *v28; // x19
  unsigned int v29; // w8
  __int64 v30; // x1
  __int64 v31; // x1
  __int64 v32; // x9
  unsigned int v33; // w3
  unsigned int v34; // w4
  const char *v35; // x10
  unsigned int v36; // w10
  int v37; // w11
  const char *v38; // x12
  unsigned int v39; // w13
  _QWORD *v40; // x13
  __int64 v41; // x14
  unsigned int v42; // w9
  _DWORD *v43; // x8
  __int64 v44; // x1
  int v45; // w9
  void *v46; // x19
  const char *v47; // x20
  int v48; // w19
  void *v49; // x0
  unsigned int v50; // w21
  void *v51; // x0
  int *v52; // x0
  int **v53; // x8
  int *v54; // x21
  int *v55; // x9
  __int64 v56; // x8
  __int64 v57; // x19
  void *v58; // x0

  result = -22;
  if ( !a1 || !a2 )
    return result;
  result = _kmalloc_cache_noprof(msleep, 3520, 352);
  if ( !result )
    return -12;
  v5 = 0xFFFFFFEA00000000LL;
  if ( !a2[161] )
    goto LABEL_118;
  v6 = a2[21];
  v7 = *a2;
  v8 = result;
  *(_QWORD *)result = a1;
  v9 = *((int **)a2 + 2749);
  v10 = 0;
  *(_DWORD *)(result + 8) = v6;
  *(_DWORD *)(result + 20) = v7;
  *(_QWORD *)(result + 32) = sde_hw_intr_irqidx_lookup;
  *(_QWORD *)(result + 56) = sde_hw_intr_enable_irq_nolock;
  *(_QWORD *)(result + 80) = sde_hw_intr_disable_irq_nolock;
  *(_QWORD *)(result + 152) = &sde_hw_intr_dispatch_irq;
  *(_QWORD *)(result + 104) = sde_hw_intr_clear_irqs;
  *(_QWORD *)(result + 128) = sde_hw_intr_disable_irqs;
  *(_QWORD *)(result + 272) = sde_hw_intr_get_interrupt_sources;
  *(_QWORD *)(result + 176) = sde_hw_intr_clear_interrupt_status;
  *(_QWORD *)(result + 200) = sde_hw_intr_clear_intr_status_nolock;
  v11 = a2 + 5498;
  v12 = v9 == a2 + 5498;
  v13 = 0;
  *(_QWORD *)(result + 224) = sde_hw_intr_get_interrupt_status;
  *(_QWORD *)(result + 248) = sde_hw_intr_get_intr_status_nolock;
  if ( v12 )
    goto LABEL_97;
  do
  {
    v14 = v9[4];
    if ( v14 > 2 )
    {
      switch ( v14 )
      {
        case 3:
          v15 = 6;
          goto LABEL_20;
        case 4:
          v15 = 2;
          goto LABEL_20;
        case 5:
LABEL_14:
          v15 = 1;
          goto LABEL_20;
      }
LABEL_98:
      v49 = &unk_22B9C0;
LABEL_100:
      v50 = v10;
      printk(v49, (unsigned int)v14);
      v10 = v50;
LABEL_101:
      printk(&unk_250DD9, v10);
LABEL_102:
      result = v8;
      goto LABEL_118;
    }
    if ( !v14 )
    {
      v14 = v9[5];
      if ( (unsigned int)(v14 - 1) < 3 )
      {
        v15 = dword_28C5A8[v14 - 1];
        goto LABEL_20;
      }
      v49 = &unk_235F0E;
      goto LABEL_100;
    }
    if ( v14 != 1 )
    {
      if ( v14 != 2 )
        goto LABEL_98;
      goto LABEL_14;
    }
    v15 = 12;
LABEL_20:
    if ( v13 >= ~v15 )
      goto LABEL_101;
    v9 = *(int **)v9;
    v10 = (unsigned int)(v10 + 1);
    v13 += v15;
  }
  while ( v9 != v11 );
  if ( !(_DWORD)v10 || !v13 )
  {
LABEL_97:
    printk(&unk_239428, v10);
    goto LABEL_102;
  }
  *(_DWORD *)(result + 312) = v10;
  v16 = _kmalloc_noprof(20LL * (unsigned int)v10, 3520);
  result = v8;
  *(_QWORD *)(v8 + 320) = v16;
  if ( !v16
    || (*(_DWORD *)(v8 + 328) = v13,
        v17 = _kmalloc_noprof(16LL * v13, 3520),
        result = v8,
        (*(_QWORD *)(v8 + 336) = v17) == 0) )
  {
    v5 = 0xFFFFFFF400000000LL;
    goto LABEL_118;
  }
  v18 = *(int **)v11;
  if ( *(int **)v11 == v11 )
  {
LABEL_96:
    v5 = 0;
    v48 = 1;
    goto LABEL_108;
  }
  v19 = 0;
  v20 = 0;
  v21 = &unk_235F0E;
  v22 = (const char *)&sde_irq_ad4_map;
  while ( 2 )
  {
    v25 = (unsigned int)v18[4];
    v26 = v20;
    if ( (int)v25 > 2 )
    {
      switch ( (_DWORD)v25 )
      {
        case 3:
          v29 = 6;
          if ( (v19 & 0x80000000) != 0 )
            goto LABEL_107;
          goto LABEL_49;
        case 4:
          v29 = 2;
          if ( (v19 & 0x80000000) != 0 )
            goto LABEL_107;
          goto LABEL_49;
        case 5:
          goto LABEL_39;
      }
LABEL_35:
      v27 = v21;
      v28 = v22;
      printk(&unk_22B9C0, v25);
      v22 = v28;
      v21 = v27;
      goto LABEL_94;
    }
    switch ( (_DWORD)v25 )
    {
      case 0:
        v30 = (unsigned int)v18[5];
        if ( (unsigned int)(v30 - 1) < 3 )
        {
          v29 = dword_28C5A8[(unsigned int)(v30 - 1)];
          if ( (v19 & 0x80000000) != 0 )
            goto LABEL_107;
          break;
        }
        v46 = v21;
        v47 = v22;
        printk(v21, v30);
        v22 = v47;
        v21 = v46;
LABEL_94:
        result = v8;
        v29 = 0;
        if ( (v19 & 0x80000000) != 0 )
          goto LABEL_107;
        break;
      case 1:
        v29 = 12;
        if ( (v19 & 0x80000000) != 0 )
          goto LABEL_107;
        break;
      case 2:
LABEL_39:
        v29 = 1;
        if ( (v19 & 0x80000000) != 0 )
          goto LABEL_107;
        break;
      default:
        goto LABEL_35;
    }
LABEL_49:
    if ( v19 >= *(unsigned int *)(result + 312) )
      goto LABEL_107;
    v31 = (unsigned int)v18[4];
    v32 = *(_QWORD *)(result + 336);
    v33 = *(_DWORD *)(result + 328);
    if ( (int)v31 > 2 )
    {
      switch ( (_DWORD)v31 )
      {
        case 3:
          v34 = 6;
          v35 = (const char *)&sde_irq_intf_te_map;
          break;
        case 4:
          v34 = 2;
          v35 = (const char *)&sde_irq_ltm_map;
          break;
        case 5:
          v34 = 1;
          v35 = "%";
          break;
        default:
LABEL_104:
          v51 = &unk_22B9C0;
          goto LABEL_106;
      }
      goto LABEL_64;
    }
    if ( (_DWORD)v31 )
    {
      if ( (_DWORD)v31 == 1 )
      {
        v34 = 12;
        v35 = (const char *)&sde_irq_intf_map;
      }
      else
      {
        if ( (_DWORD)v31 != 2 )
          goto LABEL_104;
        v34 = 1;
        v35 = v22;
      }
      goto LABEL_64;
    }
    v31 = (unsigned int)v18[5];
    v36 = v31 - 1;
    if ( (unsigned int)(v31 - 1) < 3 )
    {
      v34 = dword_28C5A8[v36];
      v35 = (const char *)*(&off_28C5B8 + v36);
LABEL_64:
      v20 = v29 + v26;
      if ( v26 >= v33 || v20 > v33 || v29 > v34 )
      {
        printk(&unk_235F25, v26);
        v48 = 0;
        goto LABEL_108;
      }
      if ( v26 < v20 )
      {
        v37 = 0;
        do
        {
          v38 = &v35[16 * v37];
          v39 = v26 + v37++;
          v40 = (_QWORD *)(v32 + 16LL * (int)v39);
          v41 = *((_QWORD *)v38 + 1);
          *v40 = *(_QWORD *)v38;
          v40[1] = v41;
        }
        while ( v29 != v37 );
        v42 = v26;
        do
        {
          *(_DWORD *)(*(_QWORD *)(result + 336) + 16LL * (int)v42 + 12) = v19;
          if ( v18[4] )
            *(_DWORD *)(*(_QWORD *)(result + 336) + 16LL * (int)v42 + 4) = v18[5];
          --v29;
          ++v42;
        }
        while ( v29 );
      }
      *(_DWORD *)(*(_QWORD *)(result + 320) + 20 * v19 + 12) = v26;
      *(_DWORD *)(*(_QWORD *)(result + 320) + 20 * v19 + 16) = v20;
      if ( !v18 )
        goto LABEL_107;
      v43 = (_DWORD *)(*(_QWORD *)(result + 320) + 20 * v19);
      if ( !v43 )
        goto LABEL_107;
      v44 = (unsigned int)v18[4];
      v45 = v18[6];
      if ( (int)v44 > 2 )
      {
        switch ( (_DWORD)v44 )
        {
          case 3:
            v23 = 4;
            *v43 = v45 + 8;
            v24 = v45;
            break;
          case 4:
            v23 = 84;
            *v43 = v45 + 88;
            v24 = v45 + 80;
            break;
          case 5:
            v23 = 400;
            *v43 = v45 + 404;
            v24 = v45 + 396;
            break;
          default:
LABEL_119:
            v58 = &unk_240106;
            goto LABEL_124;
        }
      }
      else if ( (_DWORD)v44 )
      {
        if ( (_DWORD)v44 == 1 )
        {
          v23 = 452;
          *v43 = v45 + 456;
          v24 = v45 + 448;
        }
        else
        {
          if ( (_DWORD)v44 != 2 )
            goto LABEL_119;
          v23 = 1056;
          *v43 = v45 + 1060;
          v24 = v45 + 1052;
        }
      }
      else
      {
        v44 = (unsigned int)v18[5];
        switch ( (_DWORD)v44 )
        {
          case 3:
            v23 = 32;
            *v43 = v45 + 36;
            v24 = v45 + 28;
            break;
          case 2:
            v23 = 12;
            *v43 = v45 + 44;
            v24 = v45 + 8;
            break;
          case 1:
            v23 = 20;
            *v43 = v45 + 24;
            v24 = v45 + 16;
            break;
          default:
            v58 = &unk_2283F5;
            goto LABEL_124;
        }
      }
      ++v19;
      v43[1] = v24;
      v43[2] = v23 + v45;
      v18 = *(int **)v18;
      if ( v18 == v11 )
        goto LABEL_96;
      continue;
    }
    break;
  }
  v51 = &unk_235F0E;
LABEL_106:
  printk(v51, v31);
  v44 = (unsigned int)v18[4];
  if ( (unsigned int)(v44 - 1) < 5 )
  {
LABEL_107:
    v48 = 0;
    goto LABEL_108;
  }
  if ( !(_DWORD)v44 )
  {
    v44 = (unsigned int)v18[5];
    if ( (unsigned int)(v44 - 1) >= 3 )
    {
      v58 = &unk_235F0E;
      goto LABEL_124;
    }
    goto LABEL_107;
  }
  v58 = &unk_22B9C0;
LABEL_124:
  printk(v58, v44);
  v48 = 0;
LABEL_108:
  v52 = *(int **)v11;
  if ( *(int **)v11 != v11 )
  {
    do
    {
      v54 = *(int **)v52;
      v53 = *((int ***)v52 + 1);
      if ( *v53 == v52 && *((int **)v54 + 1) == v52 )
      {
        *((_QWORD *)v54 + 1) = v53;
        *v53 = v54;
      }
      else
      {
        _list_del_entry_valid_or_report(v52);
        v52 = v55;
      }
      *(_QWORD *)v52 = 0xDEAD000000000100LL;
      *((_QWORD *)v52 + 1) = 0xDEAD000000000122LL;
      kfree(v52);
      v52 = v54;
    }
    while ( v54 != v11 );
  }
  result = v8;
  if ( v48 )
  {
    v56 = _kmalloc_noprof(4LL * *(unsigned int *)(v8 + 312), 3520);
    result = v8;
    *(_QWORD *)(v8 + 296) = v56;
    v5 = 0xFFFFFFF400000000LL;
    if ( v56 )
    {
      *(_DWORD *)(v8 + 344) = 0;
      return result;
    }
  }
LABEL_118:
  v57 = result;
  kfree(*(_QWORD *)(result + 320));
  kfree(*(_QWORD *)(v57 + 336));
  kfree(*(_QWORD *)(v57 + 296));
  kfree(v57);
  return v5 >> 32;
}
