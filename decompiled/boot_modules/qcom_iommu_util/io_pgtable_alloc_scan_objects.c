unsigned __int64 __fastcall io_pgtable_alloc_scan_objects(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x22
  __int64 v3; // x0
  __int64 v4; // x21
  unsigned __int64 v5; // x19
  unsigned __int64 v7; // x25
  __int64 v8; // x0
  __int64 v9; // x1
  unsigned __int64 v10; // x20
  _QWORD *v11; // x22
  _QWORD *v12; // x23
  _QWORD *v13; // x0
  _QWORD *v14; // x8
  __int64 v15; // x9
  __int64 v16; // x2
  _QWORD *v17; // x9
  unsigned __int64 v23; // x8
  _QWORD *v24; // x28
  int v25; // w23
  _QWORD *v26; // x23
  _QWORD *v27; // x8
  _QWORD *v28; // t2
  __int64 v29; // x24
  _QWORD *v30; // x25
  int v31; // w0
  __int64 v32; // x0
  unsigned __int64 StatusReg; // x23
  unsigned __int64 v36; // [xsp+8h] [xbp-48h]
  __int64 v37; // [xsp+10h] [xbp-40h]
  _QWORD v38[2]; // [xsp+18h] [xbp-38h] BYREF
  __int64 v39; // [xsp+28h] [xbp-28h] BYREF
  __int64 v40; // [xsp+30h] [xbp-20h]
  __int64 v41; // [xsp+38h] [xbp-18h] BYREF
  _QWORD v42[2]; // [xsp+40h] [xbp-10h] BYREF

  v42[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a2 + 8);
  v38[0] = v38;
  v38[1] = v38;
  mutex_lock(&page_pool_xa_lock);
  v39 = 0;
  v3 = xa_find(&page_pool_xa, &v39, -1, 8);
  if ( v3 )
  {
    v4 = v3;
    v5 = 0;
    _X28 = &page_pool_count;
    v36 = v2;
    do
    {
      v7 = v2 - v5;
      v8 = raw_spin_lock_irqsave(v4 + 8);
      v9 = v8;
      if ( v2 == v5 )
      {
        v10 = 0;
      }
      else
      {
        v10 = 0;
        v11 = (_QWORD *)(v4 + 16);
        v37 = v8;
        while ( 1 )
        {
          v12 = (_QWORD *)*v11;
          if ( (_QWORD *)*v11 == v11 )
            break;
          v13 = v12 - 1;
          if ( v12 == (_QWORD *)&unk_8 )
            break;
          v14 = (_QWORD *)v12[1];
          if ( (_QWORD *)*v14 == v12 && (v15 = *v12, *(_QWORD **)(*v12 + 8LL) == v12) )
          {
            *(_QWORD *)(v15 + 8) = v14;
            *v14 = v15;
          }
          else
          {
            _list_del_entry_valid_or_report(*v11);
            v13 = v17;
          }
          *v12 = 0xDEAD000000000100LL;
          v12[1] = 0xDEAD000000000122LL;
          __asm { PRFM            #0x11, [X28] }
          do
            v23 = __ldxr((unsigned __int64 *)&page_pool_count);
          while ( __stxr(v23 - 1, (unsigned __int64 *)&page_pool_count) );
          dec_node_page_state(v13, 34);
          v16 = v38[0];
          if ( *(_QWORD **)(v38[0] + 8LL) != v38 || v12 == v38 || (_QWORD *)v38[0] == v12 )
          {
            _list_add_valid_or_report(v12, v38);
          }
          else
          {
            *(_QWORD *)(v38[0] + 8LL) = v12;
            *v12 = v16;
            v12[1] = v38;
            v38[0] = v12;
          }
          if ( v7 == ++v10 )
          {
            v10 = v7;
            break;
          }
        }
        v2 = v36;
        v9 = v37;
      }
      raw_spin_unlock_irqrestore(v4 + 8, v9);
      v5 += v10;
      if ( v5 >= v2 )
        break;
      v4 = xa_find_after(&page_pool_xa, &v39, -1, 8);
    }
    while ( v4 );
  }
  else
  {
    v5 = 0;
  }
  mutex_unlock(&page_pool_xa_lock);
  v24 = (_QWORD *)v38[0];
  while ( v24 != v38 )
  {
    v26 = v24;
    v28 = v24;
    v24 = (_QWORD *)*v24;
    v27 = (_QWORD *)v28[1];
    v29 = v26[4];
    if ( (_QWORD *)*v27 == v26 && (_QWORD *)v24[1] == v26 )
    {
      v24[1] = v27;
      *v27 = v24;
    }
    else
    {
      _list_del_entry_valid_or_report(v26);
    }
    v30 = v26 - 1;
    *v26 = 0xDEAD000000000100LL;
    v26[1] = 0xDEAD000000000122LL;
    if ( (_DWORD)v29
      && (v41 = (1LL << v29) | 8,
          v42[0] = 0x700000003LL,
          v40 = ((_QWORD)&v30[8 * (memstart_addr >> 12)] << 6) + 0x5000000000LL,
          (v31 = qcom_scm_assign_mem(v40, 4096, &v41, v42)) != 0) )
    {
      v25 = v31;
      printk(&unk_11D37);
      _warn_printk("failed to unassign memory from VMID: %u rc: %d\n", v29, v25);
      --v5;
      __break(0x800u);
    }
    else if ( v26 != (_QWORD *)&unk_8 )
    {
      mod_node_page_state(&contig_page_data, 41, -1);
      v32 = (__int64)(v26 - 1);
      if ( (*v26 & 1) != 0 )
        v32 = *v26 - 1LL;
      StatusReg = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      _lruvec_stat_mod_folio(v32, 40, 0xFFFFFFFFLL);
      _WriteStatusReg(DAIF, StatusReg);
      _free_pages(v30, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return v5;
}
