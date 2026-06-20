__int64 __fastcall dfc_clnt_ind_cb(__int64 result, __int64 a2, __int64 a3, unsigned __int8 *a4)
{
  __int64 v5; // x19
  _QWORD *v6; // x21
  __int64 v7; // x0
  __int64 v8; // x2
  _QWORD *v9; // x1
  __int64 v10; // x9

  if ( *a4 )
  {
    if ( a4[1] >= 0x11u )
    {
      return printk(&unk_2CFC0, "dfc_clnt_ind_cb");
    }
    else
    {
      v5 = result;
      result = _kmalloc_cache_noprof(netdev_rx_handler_register, 2336, 800);
      v6 = (_QWORD *)result;
      if ( result )
      {
        *(_WORD *)(result + 16) = 34;
        memcpy((void *)(result + 20), a4, 0x308u);
        v7 = raw_spin_lock_irqsave(v5 + 376);
        v8 = v5 + 360;
        v9 = *(_QWORD **)(v5 + 368);
        v10 = v7;
        if ( v6 == (_QWORD *)(v5 + 360) || v9 == v6 || *v9 != v8 )
        {
          _list_add_valid_or_report(v6, v9, v8);
        }
        else
        {
          *(_QWORD *)(v5 + 368) = v6;
          *v6 = v8;
          v6[1] = v9;
          *v9 = v6;
        }
        raw_spin_unlock_irqrestore(v5 + 376, v10);
        return queue_work_on(32, *(_QWORD *)(v5 - 40), v5 + 328);
      }
    }
  }
  return result;
}
