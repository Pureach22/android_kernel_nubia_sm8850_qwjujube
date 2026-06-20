__int64 __fastcall rmnet_perf_tether_egress(__int64 result)
{
  __int64 v1; // x19
  int v2; // w21
  __int64 v3; // x20
  _QWORD *v4; // x22
  void **v5; // x8
  void *v6; // x9
  __int64 *v7; // x8
  __int64 v8; // x10
  char *v9; // x9
  unsigned __int64 v10; // x8
  __int64 *v11; // x23
  bool v12; // zf
  bool v13; // w9
  _QWORD *v15; // x8
  __int64 v16; // x9
  __int64 *v17; // x8
  __int64 v18; // x9
  int v19; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  if ( configure_knob1 | configure_knob2 )
  {
    v1 = result;
    if ( *(_DWORD *)(result + 148) )
    {
      result = _dev_get_by_index(&init_net);
      if ( result )
      {
        result = rmnet_perf_tether_get_hash_from_skb(v1, &v19, 0, 1);
        if ( v19 )
        {
          v2 = result;
          v3 = raw_spin_lock_irqsave(&rmnet_perf_tether_lock);
          v4 = rmnet_perf_tether_free_list;
          if ( rmnet_perf_tether_free_list == (_UNKNOWN *)&rmnet_perf_tether_free_list || !rmnet_perf_tether_free_list )
          {
            v10 = 0;
            while ( 1 )
            {
              v11 = (__int64 *)rmnet_perf_tether_flow_table[v10];
              v12 = !v11 || v11 == &qword_10;
              v13 = v12;
              if ( !v12 )
                break;
              if ( v10++ >= 0x1F )
                v13 = 0;
              if ( !v13 )
                goto LABEL_33;
            }
            v15 = (_QWORD *)v11[1];
            if ( v15 )
            {
              v16 = *v11;
              *v15 = *v11;
              if ( v16 )
                *(_QWORD *)(v16 + 8) = v15;
              *v11 = 0;
              v11[1] = 0;
            }
            *((_DWORD *)v11 + 4) = v2;
            ((void (*)(void))rmnet_perf_populate_node)();
            v17 = &rmnet_perf_tether_flow_table[(unsigned int)(1640531527 * *((_DWORD *)v11 + 4)) >> 27];
            v18 = *v17;
            *v11 = *v17;
            if ( v18 )
              *(_QWORD *)(v18 + 8) = v11;
            *v17 = (__int64)v11;
            v11[1] = (__int64)v17;
          }
          else
          {
            v5 = *(void ***)((char *)&unk_8 + (_QWORD)rmnet_perf_tether_free_list);
            if ( *v5 == rmnet_perf_tether_free_list
              && (v6 = *(void **)rmnet_perf_tether_free_list,
                  *(_UNKNOWN **)((char *)&unk_8 + *(_QWORD *)rmnet_perf_tether_free_list) == rmnet_perf_tether_free_list) )
            {
              *(_QWORD *)((char *)&unk_8 + (_QWORD)v6) = v5;
              *v5 = v6;
            }
            else
            {
              _list_del_entry_valid_or_report(rmnet_perf_tether_free_list);
            }
            *(_DWORD *)((char *)&off_20 + (_QWORD)v4) = v2;
            *v4 = 0xDEAD000000000100LL;
            v4[1] = 0xDEAD000000000122LL;
            rmnet_perf_populate_node(v4, v1);
            v7 = &rmnet_perf_tether_flow_table[(unsigned int)(1640531527 * *(_DWORD *)((char *)&off_20 + (_QWORD)v4)) >> 27];
            v8 = *v7;
            *(_QWORD *)((char *)&qword_10 + (_QWORD)v4) = *v7;
            v9 = (char *)&qword_10 + (_QWORD)v4;
            if ( v8 )
              *(_QWORD *)(v8 + 8) = v9;
            *v7 = (__int64)v9;
            *(_QWORD *)((char *)&unk_18 + (_QWORD)v4) = v7;
          }
LABEL_33:
          result = raw_spin_unlock_irqrestore(&rmnet_perf_tether_lock, v3);
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
