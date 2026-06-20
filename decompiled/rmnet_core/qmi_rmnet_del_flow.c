__int64 __fastcall qmi_rmnet_del_flow(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x19
  __int64 *v6; // x21
  __int64 *v7; // x24
  __int64 *v8; // x22
  int v9; // w8
  __int64 v10; // x23
  __int64 v11; // x26
  __int64 **v12; // x8
  __int64 *v13; // x9
  __int64 **v14; // x8
  __int64 *v15; // x9
  __int64 v16; // x21
  unsigned __int64 v17; // x22
  __int64 v18; // x8

  result = rmnet_get_qos_pt(a1);
  if ( result )
  {
    v5 = result;
    if ( !(unsigned int)rtnl_is_locked(result) && (qmi_rmnet_del_flow___already_done & 1) == 0 )
    {
      qmi_rmnet_del_flow___already_done = 1;
      _warn_printk("RTNL: assertion failed at %s (%d)\n", "../vendor/qcom/opensource/datarmnet/core/qmi_rmnet.c", 550);
      __break(0x800u);
    }
    raw_spin_lock_bh(v5 + 332);
    v7 = (__int64 *)(v5 + 40);
    v6 = *(__int64 **)(v5 + 40);
    if ( v6 != (__int64 *)(v5 + 40) )
    {
      while ( *((_DWORD *)v6 + 5) != *(_DWORD *)(a2 + 12) || *((_DWORD *)v6 + 6) != *(_DWORD *)(a2 + 4) )
      {
        v6 = (__int64 *)*v6;
        if ( v6 == v7 )
          goto LABEL_26;
      }
      if ( v6 )
      {
        v8 = (__int64 *)v6[4];
        if ( v8 )
        {
          v9 = *((_DWORD *)v8 + 5) - 1;
          *((_DWORD *)v8 + 5) = v9;
          if ( !v9 )
          {
            v10 = 0;
            v11 = v5 + 72;
            do
            {
              if ( *(__int64 **)v11 == v8 )
              {
                *(_QWORD *)v11 = 0;
                *(_WORD *)(v11 + 8) = 256;
                __dmb(0xBu);
                qmi_rmnet_flow_control(a1, v10, 1);
                if ( dfc_mode == 4 )
                  qmi_rmnet_flow_control(a1, v10 + 15, 1);
              }
              ++v10;
              v11 += 16;
            }
            while ( v10 != 16 );
            v12 = (__int64 **)v8[1];
            if ( *v12 == v8 && (v13 = (__int64 *)*v8, *(__int64 **)(*v8 + 8) == v8) )
            {
              v13[1] = (__int64)v12;
              *v12 = v13;
            }
            else
            {
              _list_del_entry_valid_or_report(v8);
            }
            *v8 = 0xDEAD000000000100LL;
            v8[1] = 0xDEAD000000000122LL;
            *(_QWORD *)(v5 + 336) = v8;
          }
        }
        v14 = (__int64 **)v6[1];
        if ( *v14 == v6 && (v15 = (__int64 *)*v6, *(__int64 **)(*v6 + 8) == v6) )
        {
          v15[1] = (__int64)v14;
          *v14 = v15;
        }
        else
        {
          _list_del_entry_valid_or_report(v6);
        }
        *v6 = 0xDEAD000000000100LL;
        v6[1] = 0xDEAD000000000122LL;
        kfree(v6);
      }
    }
LABEL_26:
    if ( (__int64 *)*v7 == v7 && *(_DWORD *)(a1 + 1096) )
    {
      v16 = 0;
      v17 = 0;
      do
      {
        netif_tx_wake_queue(*(_QWORD *)(a1 + 24) + v16);
        ++v17;
        v16 += 384;
      }
      while ( v17 < *(unsigned int *)(a1 + 1096) );
    }
    result = raw_spin_unlock_bh(v5 + 332);
    v18 = *(_QWORD *)(v5 + 336);
    if ( v18 )
    {
      *(_BYTE *)(v18 + 121) = 1;
      timer_delete_sync(*(_QWORD *)(v5 + 336) + 80LL);
      *(_BYTE *)(*(_QWORD *)(v5 + 336) + 148LL) = 1;
      timer_delete_sync(*(_QWORD *)(v5 + 336) + 152LL);
      result = kfree(*(_QWORD *)(v5 + 336));
      *(_QWORD *)(v5 + 336) = 0;
    }
  }
  return result;
}
