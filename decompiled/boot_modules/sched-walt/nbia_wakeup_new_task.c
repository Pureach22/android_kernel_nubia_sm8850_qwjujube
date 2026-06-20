void __fastcall nbia_wakeup_new_task(__int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x22
  _BYTE *v3; // x20
  _DWORD *v4; // x8
  __int64 v5; // x21
  unsigned int v6; // w8
  int v7; // w19
  int v8; // w20
  int v9; // w8
  __int64 v10; // x24
  int *v11; // x26
  __int64 v12; // x26
  int v13; // w19
  __int64 v15; // x24
  unsigned __int64 v21; // x9
  int v22; // w22

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (_UNKNOWN *)a2 == &init_task )
    v3 = &vendor_data_pad;
  else
    v3 = (_BYTE *)(a2 + 5184);
  if ( (_UNKNOWN *)StatusReg == &init_task )
    v4 = &vendor_data_pad;
  else
    v4 = (_DWORD *)(StatusReg + 5184);
  if ( a2 )
  {
    if ( *((_BYTE *)v4 + 456) == 1
      && v4[120] == 1
      && (unsigned int)(*(_DWORD *)(a2 + 1352) - 3) >= 0xFFFFFFFE
      && (unsigned int)(*(_DWORD *)(StatusReg + 1352) - 3) >= 0xFFFFFFFE )
    {
      v5 = a2;
      q_restore_cfs_task(*(_DWORD *)(a2 + 1800), v4[121]);
      a2 = v5;
      if ( byte_6A5A8 == 1 )
      {
        printk(&unk_65F57);
        a2 = v5;
      }
    }
  }
  if ( prio_adj_info_data_changed == 1 )
  {
    v6 = *(_DWORD *)(a2 + 1352);
    if ( (v6 > 7 || ((1 << v6) & 0x89) == 0) && v3[456] == 1 )
    {
      v7 = *(_DWORD *)(a2 + 1804);
      v8 = *(_DWORD *)(StatusReg + 1800);
      v9 = sched_nbia_debug;
      v10 = 0;
      while ( 1 )
      {
        if ( v9 )
        {
          v12 = a2;
          printk(&unk_61BFE);
          v9 = sched_nbia_debug;
          a2 = v12;
        }
        if ( sched_prio_adjusted_info[v10] == v7 )
        {
          v11 = &sched_prio_adjusted_info[v10];
          if ( sched_prio_adjusted_info[v10 + 1] == v8 )
            break;
        }
        v10 += 5;
        if ( v10 == 500 )
          return;
      }
      q_restore_cfs_task(*(_DWORD *)(a2 + 1800), v11[3]);
      v13 = v11[4];
      _X20 = (unsigned __int64 *)_kmalloc_cache_noprof(root_task_group, 3520, 8);
      if ( _X20 )
      {
        v15 = 0;
        while ( 1 )
        {
          v22 = dword_6C708[v15] & v13;
          if ( sched_nbia_debug )
          {
            printk(&unk_6598B);
            if ( v22 )
            {
LABEL_31:
              __asm { PRFM            #0x11, [X20] }
              do
                v21 = __ldxr(_X20);
              while ( __stxr(v21 | (1LL << v15), _X20) );
            }
          }
          else if ( v22 )
          {
            goto LABEL_31;
          }
          if ( ++v15 == 8 )
          {
            kfree(_X20);
            if ( sched_nbia_debug )
              printk(&unk_63F9D);
            return;
          }
        }
      }
    }
  }
}
