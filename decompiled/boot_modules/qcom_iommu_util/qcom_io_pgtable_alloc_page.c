__int64 __fastcall qcom_io_pgtable_alloc_page(unsigned int a1, int a2)
{
  __int64 v2; // x19
  __int64 v3; // x22
  __int64 v4; // x23
  _QWORD *v7; // x9
  _QWORD *v8; // x8
  __int64 v9; // x10
  __int64 v10; // x8
  __int64 v11; // x0
  unsigned __int64 StatusReg; // x22
  int v18; // w0
  int v20; // w19
  unsigned __int64 v23; // x10
  __int64 v24; // [xsp+10h] [xbp-20h] BYREF
  __int64 v25; // [xsp+18h] [xbp-18h] BYREF
  unsigned int v26; // [xsp+20h] [xbp-10h]
  int v27; // [xsp+24h] [xbp-Ch]
  __int64 v28; // [xsp+28h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && (a2 & 0x400) == 0 )
  {
    __break(0x800u);
LABEL_19:
    _X9 = &page_pool_count;
    __asm { PRFM            #0x11, [X9] }
    do
      v23 = __ldxr((unsigned __int64 *)&page_pool_count);
    while ( __stxr(v23 - 1, (unsigned __int64 *)&page_pool_count) );
    dec_node_page_state(v2, 34);
    raw_spin_unlock_irqrestore(v3 + 8, v4);
    goto LABEL_15;
  }
  v3 = xa_load(&page_pool_xa, a1);
  v4 = raw_spin_lock_irqsave(v3 + 8);
  v7 = *(_QWORD **)(v3 + 16);
  if ( v7 != (_QWORD *)(v3 + 16) )
  {
    v2 = (__int64)(v7 - 1);
    if ( v7 != (_QWORD *)&unk_8 )
    {
      v8 = (_QWORD *)v7[1];
      if ( (_QWORD *)*v8 == v7 && (v9 = *v7, *(_QWORD **)(*v7 + 8LL) == v7) )
      {
        *(_QWORD *)(v9 + 8) = v8;
        *v8 = v9;
      }
      else
      {
        _list_del_entry_valid_or_report(*(_QWORD *)(v3 + 16));
      }
      *v7 = 0xDEAD000000000100LL;
      v7[1] = 0xDEAD000000000122LL;
      goto LABEL_19;
    }
  }
  raw_spin_unlock_irqrestore(v3 + 8, v4);
  v2 = _alloc_pages_noprof(a2 | 0x100u, 0, 0, 0);
  if ( v2 )
  {
    mod_node_page_state(&contig_page_data, 41, 1);
    v10 = *(_QWORD *)(v2 + 8);
    v11 = v2;
    if ( (v10 & 1) != 0 )
      v11 = v10 - 1;
    StatusReg = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    _lruvec_stat_mod_folio(v11, 40, 1);
    _WriteStatusReg(DAIF, StatusReg);
    if ( a1
      && (v25 = 0x600000003LL,
          v26 = a1,
          v27 = 4,
          v24 = 8,
          (v18 = qcom_scm_assign_mem(((v2 - -64LL * (memstart_addr >> 12)) << 6) + 0x5000000000LL, 4096, &v24, &v25)) != 0) )
    {
      v20 = v18;
      printk(&unk_11A90);
      _warn_printk("failed to assign memory to VMID: %u rc:%d\n", a1, v20);
      v2 = 0;
      __break(0x800u);
    }
    else
    {
      *(_QWORD *)(v2 + 40) = a1;
    }
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return v2;
}
