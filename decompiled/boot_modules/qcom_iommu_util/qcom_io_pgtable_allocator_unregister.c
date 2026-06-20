__int64 __fastcall qcom_io_pgtable_allocator_unregister(unsigned int a1)
{
  unsigned int *v2; // x19
  int v4; // w20
  unsigned int *v5; // x9
  _QWORD *v6; // x26
  unsigned int *v7; // x21
  unsigned int **v8; // x8
  __int64 v9; // x10
  int v11; // w25
  int v12; // w0
  __int64 v13; // x8
  unsigned int *v14; // x0
  unsigned __int64 StatusReg; // x25
  _QWORD *v17; // x9
  _QWORD *v18; // x8
  __int64 v19; // x10
  int v20; // w21
  unsigned __int64 v22; // x8
  int v28; // w8
  __int64 result; // x0
  unsigned __int64 v32; // x10
  __int64 v33; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v34[2]; // [xsp+10h] [xbp-10h] BYREF

  v34[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mutex_lock(&page_pool_xa_lock);
  v2 = (unsigned int *)xa_load(&page_pool_xa, a1);
  _X0 = v2 + 1;
  __asm { PRFM            #0x11, [X0] }
  do
    v28 = __ldxr(_X0);
  while ( __stlxr(v28 - 1, _X0) );
  if ( v28 == 1 )
  {
    __dmb(9u);
    v4 = *v2;
    xa_erase(&page_pool_xa, *v2);
    v6 = v2 + 4;
    v5 = *((unsigned int **)v2 + 2);
    if ( v5 != v2 + 4 )
    {
      v7 = v5 - 2;
      if ( v5 != (unsigned int *)&unk_8 )
      {
        v8 = *((unsigned int ***)v5 + 1);
        if ( *v8 == v5 && (v9 = *(_QWORD *)v5, *(unsigned int **)(*(_QWORD *)v5 + 8LL) == v5) )
        {
          *(_QWORD *)(v9 + 8) = v8;
          *v8 = (unsigned int *)v9;
        }
        else
        {
          _list_del_entry_valid_or_report(*((_QWORD *)v2 + 2));
        }
        *(_QWORD *)v5 = 0xDEAD000000000100LL;
        *((_QWORD *)v5 + 1) = 0xDEAD000000000122LL;
        _X9 = &page_pool_count;
        __asm { PRFM            #0x11, [X9] }
        do
          v32 = __ldxr((unsigned __int64 *)&page_pool_count);
        while ( __stxr(v32 - 1, (unsigned __int64 *)&page_pool_count) );
        _X28 = &page_pool_count;
        while ( 1 )
        {
          dec_node_page_state(v7, 34);
          if ( v4
            && (v11 = *v2,
                v33 = (1LL << *v2) | 8,
                v34[0] = 0x700000003LL,
                (v12 = qcom_scm_assign_mem(
                         ((_QWORD)&v7[16 * (memstart_addr >> 12)] << 6) + 0x5000000000LL,
                         4096,
                         &v33,
                         v34)) != 0) )
          {
            v20 = v12;
            printk(&unk_11D37);
            _warn_printk("failed to unassign memory from VMID: %u rc: %d\n", v11, v20);
            __break(0x800u);
          }
          else
          {
            mod_node_page_state(&contig_page_data, 41, -1);
            v13 = *((_QWORD *)v7 + 1);
            v14 = v7;
            if ( (v13 & 1) != 0 )
              v14 = (unsigned int *)(v13 - 1);
            StatusReg = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            _lruvec_stat_mod_folio(v14, 40, 0xFFFFFFFFLL);
            _WriteStatusReg(DAIF, StatusReg);
            _free_pages(v7, 0);
          }
          v17 = (_QWORD *)*v6;
          if ( (_QWORD *)*v6 == v6 )
            break;
          v7 = (unsigned int *)(v17 - 1);
          if ( v17 == (_QWORD *)&unk_8 )
            break;
          v18 = (_QWORD *)v17[1];
          if ( (_QWORD *)*v18 == v17 && (v19 = *v17, *(_QWORD **)(*v17 + 8LL) == v17) )
          {
            *(_QWORD *)(v19 + 8) = v18;
            *v18 = v19;
          }
          else
          {
            _list_del_entry_valid_or_report(*v6);
          }
          *v17 = 0xDEAD000000000100LL;
          v17[1] = 0xDEAD000000000122LL;
          __asm { PRFM            #0x11, [X28] }
          do
            v22 = __ldxr((unsigned __int64 *)&page_pool_count);
          while ( __stxr(v22 - 1, (unsigned __int64 *)&page_pool_count) );
        }
      }
    }
    kfree(v2);
  }
  else if ( v28 <= 0 )
  {
    refcount_warn_saturate();
  }
  result = mutex_unlock(&page_pool_xa_lock);
  _ReadStatusReg(SP_EL0);
  return result;
}
