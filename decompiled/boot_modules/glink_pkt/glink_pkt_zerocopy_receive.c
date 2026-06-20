__int64 __fastcall glink_pkt_zerocopy_receive(__int64 a1, unsigned __int64 *a2)
{
  unsigned __int64 v2; // x21
  __int64 v5; // x0
  _QWORD *v6; // x8
  unsigned __int64 v7; // x9
  unsigned __int64 StatusReg; // x28
  __int64 v9; // x0
  unsigned int v10; // w20
  int v12; // w25
  __int64 v13; // x23
  __int64 v14; // x22
  char *v15; // x26
  __int64 v16; // x27
  __int64 v17; // x23
  __int64 zeroed_page_noprof; // x0
  char *v19; // x25
  const void *v20; // x1
  __int64 v21; // x26
  unsigned int v22; // w22
  int v23; // w8
  unsigned int v24; // w23
  __int64 v25; // x0
  unsigned __int64 v26; // x25
  size_t v27; // x27
  void *v28; // x0
  void *v29; // x26
  int v30; // w21
  __int64 v31; // x27
  _BOOL4 v32; // w9
  int inserted; // w0
  int v34; // w23
  unsigned __int64 v35; // x26
  __int64 v42; // x21
  __int64 v43; // x20
  int v44; // [xsp+8h] [xbp-28h]
  int v45; // [xsp+8h] [xbp-28h]
  char *v46; // [xsp+10h] [xbp-20h]
  int v47; // [xsp+18h] [xbp-18h]
  void *v48; // [xsp+18h] [xbp-18h]
  __int64 v49; // [xsp+20h] [xbp-10h]
  __int64 v50; // [xsp+28h] [xbp-8h]

  v2 = *a2;
  if ( (*a2 & 0xFFF) != 0 || *(_BYTE *)(a1 + 1144) != 1 )
    return 4294967274LL;
  a2[1] = 0;
  v5 = raw_spin_lock_irqsave(a1 + 1148);
  v6 = *(_QWORD **)(a1 + 1176);
  if ( v6 == (_QWORD *)(a1 + 1176) || !v6 )
  {
LABEL_9:
    raw_spin_unlock_irqrestore(a1 + 1148, v5);
    StatusReg = _ReadStatusReg(SP_EL0);
    down_read(*(_QWORD *)(StatusReg + 1672) + 136LL);
    v9 = mtree_load(*(_QWORD *)(StatusReg + 1672) + 64LL, v2);
    if ( !v9 || *(_UNKNOWN **)(v9 + 72) != &glink_pkt_vm_ops )
    {
      v10 = -22;
LABEL_12:
      up_read(*(_QWORD *)(StatusReg + 1672) + 136LL);
      return v10;
    }
    v50 = v9;
    v12 = *(_DWORD *)(v9 + 8);
    v13 = raw_spin_lock_irqsave(a1 + 1148);
    v14 = skb_dequeue(a1 + 1152);
    raw_spin_unlock_irqrestore(a1 + 1148, v13);
    if ( !v14 )
    {
      v10 = -5;
      goto LABEL_12;
    }
    v15 = *(char **)(v14 + 224);
    v16 = *(unsigned int *)(v14 + 112);
    v17 = (unsigned __int16)v15 & 0xFFF;
    if ( ((unsigned __int16)v15 & 0xFFF) != 0 )
    {
      zeroed_page_noprof = get_zeroed_page_noprof(3264);
      if ( !zeroed_page_noprof )
      {
        v30 = -12;
LABEL_47:
        v43 = raw_spin_lock_irqsave(a1 + 1148);
        skb_queue_head(a1 + 1152, v14);
        raw_spin_unlock_irqrestore(a1 + 1148, v43);
        v10 = v30;
        goto LABEL_12;
      }
      v47 = v12;
      v19 = v15;
      v49 = zeroed_page_noprof;
      v20 = v15;
      v44 = (unsigned __int16)v15 & 0xFFF;
      v21 = v14;
      v22 = (unsigned int)v20 | 0xFFFFF000;
      memcpy((void *)(zeroed_page_noprof + v17), v20, 4096 - v17);
      v23 = v16 + v22;
      v14 = v21;
      v15 = v19;
      v24 = v23 + 4096;
      *((_DWORD *)a2 + 3) = v44;
    }
    else
    {
      v47 = v12;
      v24 = *(_DWORD *)(v14 + 112);
      v49 = 0;
    }
    v25 = v50;
    v26 = (unsigned __int64)&v15[v16];
    v45 = v16;
    v46 = v15;
    v27 = (unsigned __int64)&v15[v16] & 0xFFF;
    if ( v27 )
    {
      v28 = (void *)get_zeroed_page_noprof(3264);
      v29 = v28;
      if ( !v28 )
      {
        v30 = -12;
LABEL_45:
        if ( v49 )
          free_pages(v49, 0);
        goto LABEL_47;
      }
      memcpy(v28, (const void *)(v26 & 0xFFFFFFFFFFFFF000LL), v27);
      v25 = v50;
      v24 = v24 - (v26 & 0xFFF) + 4096;
    }
    else
    {
      v29 = nullptr;
    }
    if ( v24 > v47 - (int)v2 )
    {
      v30 = -28;
      goto LABEL_41;
    }
    v31 = v24;
    if ( (v24 & 0xFFF) != 0 )
    {
      v30 = -22;
      goto LABEL_41;
    }
    zap_vma_ptes(v25, v2, v24);
    v32 = v49 != 0;
    if ( v49 )
    {
      inserted = vm_insert_page(
                   v50,
                   v2,
                   ((unsigned __int64)((v49 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL);
      if ( inserted )
      {
LABEL_40:
        v30 = inserted;
        zap_vma_ptes(v50, *a2, v31);
LABEL_41:
        if ( v29 )
          free_pages(v29, 0);
        goto LABEL_45;
      }
      v32 = v49 != 0;
      v2 += 4096LL;
    }
    v48 = v29;
    v34 = (v24 >> 12) - v32 - (v29 != nullptr);
    if ( v34 )
    {
      v35 = (unsigned __int64)(v46 + 4095) & 0xFFFFFFFFFFFFF000LL;
      while ( 1 )
      {
        _X0 = glink_pkt_vaddr_to_page(v35);
        __asm { PRFM            #0x10, [X0] }
        inserted = vm_insert_page(v50, v2, _X0);
        if ( inserted )
          break;
        --v34;
        v2 += 4096LL;
        v35 += 4096LL;
        if ( !v34 )
          goto LABEL_36;
      }
      v29 = v48;
    }
    else
    {
LABEL_36:
      v29 = v48;
      if ( !v48
        || (inserted = vm_insert_page(
                         v50,
                         v2,
                         ((unsigned __int64)(((__int64)((_QWORD)v48 << 8) >> 8) + 0x8000000000LL) >> 12 << 6)
                       - 0x140000000LL)) == 0 )
      {
        *((_DWORD *)a2 + 2) = v45;
        v42 = raw_spin_lock_irqsave(a1 + 1148);
        *(_QWORD *)(v14 + 40) = v49;
        *(_QWORD *)(v14 + 48) = v48;
        *(_QWORD *)(v14 + 56) = *a2;
        *(_QWORD *)(v14 + 64) = v31;
        skb_queue_tail(a1 + 1176, v14);
        raw_spin_unlock_irqrestore(a1 + 1148, v42);
        mmap_read_unlock(*(_QWORD *)(StatusReg + 1672));
        return 0;
      }
    }
    goto LABEL_40;
  }
  while ( 1 )
  {
    v7 = v6[7];
    if ( v2 >= v7 && v2 <= v6[8] + v7 )
      break;
    v6 = (_QWORD *)*v6;
    if ( v6 == (_QWORD *)(a1 + 1176) || !v6 )
      goto LABEL_9;
  }
  raw_spin_unlock_irqrestore(a1 + 1148, v5);
  return 4294967274LL;
}
