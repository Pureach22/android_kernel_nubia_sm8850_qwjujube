__int64 __fastcall rmnet_shs_wq_cleanup_hash_tbl(char a1, int a2)
{
  _QWORD *v4; // x21
  int v5; // w27
  unsigned __int64 v12; // x8
  __int64 v13; // x23
  _UNKNOWN **v14; // x22
  _QWORD *v15; // x8
  __int64 v16; // x9
  _QWORD *v17; // x8
  __int64 v18; // x9
  unsigned __int64 v21; // x8

  raw_spin_lock_bh(&rmnet_shs_ht_splock);
  v4 = rmnet_shs_wq_hstat_tbl;
  if ( rmnet_shs_wq_hstat_tbl != (_UNKNOWN *)&rmnet_shs_wq_hstat_tbl )
  {
    v5 = 0;
    _ReadStatusReg(SP_EL0);
    do
    {
      v13 = v4[2];
      v14 = (_UNKNOWN **)*v4;
      if ( v13 && (!a2 || *((_DWORD *)v4 + 57) == a2) && (a1 || !byte_1949F) )
      {
        if ( rmnet_shs_max_flow_inactivity_sec >= (unsigned __int64)(v4[7] / 1000000000LL) )
        {
          if ( a1 )
            goto LABEL_19;
        }
        else if ( !*(_BYTE *)(v13 + 216) || (rmnet_module_hook_is_set(4) & 1) == 0 || a1 || !*(_BYTE *)(v13 + 216) )
        {
LABEL_19:
          if ( *(_BYTE *)(v13 + 223) == 3 )
            v5 = 1;
          if ( v5 )
          {
            raw_spin_lock_bh(&rmnet_shs_ll_ht_splock);
            ((void (__fastcall *)(__int64, __int64))rmnet_shs_clear_node)(v13, 1);
            rmnet_shs_cpu_list_remove((__int64)(v4 - 9));
            rmnet_shs_cpu_node_remove(v13);
            rmnet_shs_hstat_tbl_remove((__int64)(v4 - 9));
            v15 = *(_QWORD **)(v13 + 136);
            if ( v15 )
            {
              v16 = *(_QWORD *)(v13 + 128);
              *v15 = v16;
              if ( v16 )
                *(_QWORD *)(v16 + 8) = v15;
              *(_QWORD *)(v13 + 136) = 0;
            }
            _X10 = &qword_19470;
            __asm { PRFM            #0x11, [X10] }
            do
              v12 = __ldxr((unsigned __int64 *)&qword_19470);
            while ( __stxr(v12 - 1, (unsigned __int64 *)&qword_19470) );
            raw_spin_unlock_bh(&rmnet_shs_ll_ht_splock);
          }
          else
          {
            ((void (__fastcall *)(__int64, __int64))rmnet_shs_clear_node)(v13, 1);
            rmnet_shs_cpu_list_remove((__int64)(v4 - 9));
            rmnet_shs_cpu_node_remove(v13);
            rmnet_shs_hstat_tbl_remove((__int64)(v4 - 9));
            v17 = *(_QWORD **)(v13 + 136);
            if ( v17 )
            {
              v18 = *(_QWORD *)(v13 + 128);
              *v17 = v18;
              if ( v18 )
                *(_QWORD *)(v18 + 8) = v17;
              *(_QWORD *)(v13 + 136) = 0;
            }
            _X10 = &qword_19470;
            __asm { PRFM            #0x11, [X10] }
            do
              v21 = __ldxr((unsigned __int64 *)&qword_19470);
            while ( __stxr(v21 - 1, (unsigned __int64 *)&qword_19470) );
          }
          call_rcu(v4 + 3, rmnet_shs_hnode_free);
        }
      }
      v4 = v14;
    }
    while ( v14 != &rmnet_shs_wq_hstat_tbl );
  }
  return raw_spin_unlock_bh(&rmnet_shs_ht_splock);
}
