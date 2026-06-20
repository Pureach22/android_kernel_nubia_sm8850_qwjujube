__int64 __fastcall _qcom_secure_system_heap_resize(__int64 a1, unsigned __int64 a2, char a3)
{
  __int64 v5; // x28
  _UNKNOWN **v6; // x26
  int v7; // w22
  char v8; // w25
  _UNKNOWN **v9; // x24
  __int64 v10; // x0
  _QWORD *v11; // x8
  unsigned __int64 v12; // x9
  __int64 *v13; // x1
  unsigned int v14; // w20
  _QWORD *v15; // x0
  _QWORD *v16; // x8
  _QWORD *v17; // x22
  _QWORD *v18; // x9
  __int64 v19; // x0
  _QWORD *v20; // x9
  __int64 v21; // x20
  __int64 *v22; // x12
  _QWORD *v23; // x11
  __int64 v24; // x3
  __int64 result; // x0
  _QWORD *v27; // [xsp+18h] [xbp-18h] BYREF
  __int64 *v28; // [xsp+20h] [xbp-10h]
  __int64 v29; // [xsp+28h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = &v27;
  v28 = (__int64 *)&v27;
  if ( a1 && a2 <= 0x20 )
  {
    if ( a2 )
    {
      v5 = 0;
      v6 = nullptr;
      v7 = 0;
      v8 = a3 & 1;
      _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        v9 = &secure_heaps;
        while ( 1 )
        {
          v9 = (_UNKNOWN **)*v9;
          if ( v9 == &secure_heaps )
            break;
          if ( v9 - 2 == (_UNKNOWN **)dma_heap_get_drvdata(*(_QWORD *)(a1 + 8)) )
          {
            v6 = v9 - 2;
            break;
          }
        }
        if ( !v6 )
          break;
        v10 = _kmalloc_cache_noprof(of_dma_configure_id, 3264, 40);
        if ( !v10 )
        {
          v14 = -12;
          goto LABEL_18;
        }
        v11 = (_QWORD *)(a1 + 16 * v5);
        *(_BYTE *)(v10 + 32) = v8;
        v12 = (*v11 + 4095LL) & 0xFFFFFFFFFFFFF000LL;
        *(_QWORD *)(v10 + 16) = v11[1];
        *(_QWORD *)(v10 + 24) = v12;
        *(_QWORD *)v10 = v10;
        *(_QWORD *)(v10 + 8) = v10;
        v13 = v28;
        if ( v28 == (__int64 *)v10 || (_QWORD **)*v28 != &v27 )
        {
          _list_add_valid_or_report(v10);
        }
        else
        {
          v28 = (__int64 *)v10;
          *(_QWORD *)v10 = &v27;
          *(_QWORD *)(v10 + 8) = v13;
          *v13 = v10;
        }
        v5 = ++v7;
        if ( v7 >= a2 )
          goto LABEL_25;
      }
      dma_heap_get_name(*(_QWORD *)(a1 + 8));
      printk(&unk_E1EE, "__qcom_secure_system_heap_resize");
      v14 = -22;
LABEL_18:
      v15 = v27;
      if ( v27 != &v27 )
      {
        do
        {
          v17 = (_QWORD *)*v15;
          v16 = (_QWORD *)v15[1];
          if ( (_QWORD *)*v16 == v15 && (_QWORD *)v17[1] == v15 )
          {
            v17[1] = v16;
            *v16 = v17;
          }
          else
          {
            _list_del_entry_valid_or_report(v15);
            v15 = v18;
          }
          *v15 = 0xDEAD000000000100LL;
          v15[1] = 0xDEAD000000000122LL;
          kfree(v15);
          v15 = v17;
        }
        while ( v17 != &v27 );
      }
      result = v14;
    }
    else
    {
LABEL_25:
      v19 = raw_spin_lock_irqsave(&work_lock);
      v20 = v27;
      v21 = v19;
      if ( v27 != &v27 )
      {
        v22 = v28;
        v23 = off_680;
        v27[1] = off_680;
        *v23 = v20;
        *v22 = (__int64)&prefetch_list;
        off_680 = v22;
        v27 = &v27;
        v28 = (__int64 *)&v27;
      }
      if ( (a3 & 1) != 0 )
        v24 = 250;
      else
        v24 = 0;
      queue_delayed_work_on(32, prefetch_wq, &prefetch_work, v24);
      raw_spin_unlock_irqrestore(&work_lock, v21);
      result = 0;
    }
  }
  else
  {
    printk(&unk_E3E4, "__qcom_secure_system_heap_resize");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
