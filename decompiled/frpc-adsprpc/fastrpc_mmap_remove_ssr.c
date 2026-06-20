__int64 __fastcall fastrpc_mmap_remove_ssr(__int64 a1, char a2)
{
  __int64 v3; // x24
  __int64 v5; // x0
  _QWORD *v6; // x22
  _QWORD *v7; // x20
  __int64 v8; // x9
  __int64 v9; // x0
  _QWORD *v10; // x8
  __int64 v11; // x10
  unsigned int v12; // w0
  _QWORD *v13; // x28
  unsigned __int64 v14; // x8
  __int64 v15; // x9
  unsigned int v16; // w21
  __int64 v18; // x0
  _QWORD *v19; // x1

  v3 = a1 + 49152;
  v5 = raw_spin_lock_irqsave(a1 + 51600);
  v6 = *(_QWORD **)(v3 + 3592);
  v7 = (_QWORD *)(v3 + 3592);
  v8 = v5;
  if ( v6 == (_QWORD *)(v3 + 3592) )
  {
LABEL_20:
    v16 = 0;
  }
  else
  {
    _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v10 = (_QWORD *)v6[1];
      if ( (_QWORD *)*v10 == v6 && (v11 = *v6, *(_QWORD **)(*v6 + 8LL) == v6) )
      {
        *(_QWORD *)(v11 + 8) = v10;
        *v10 = v11;
      }
      else
      {
        _list_del_entry_valid_or_report(v6);
      }
      *v6 = 0xDEAD000000000100LL;
      v6[1] = 0xDEAD000000000122LL;
      raw_spin_unlock_irqrestore(a1 + 51600, v8);
      if ( !v6 )
        return 0;
      if ( (a2 & 1) != 0 )
      {
        v12 = ((__int64 (__fastcall *)(__int64, _QWORD *))fastrpc_remote_heap_unassign)(a1, v6);
        if ( v12 )
          break;
      }
      if ( *((_DWORD *)v6 + 14) == 4 )
      {
        _fastrpc_dma_buf_free(v6);
        kfree(v6);
      }
      else
      {
        v13 = (_QWORD *)v6[5];
        mutex_lock(v13 + 2);
        if ( *v13 )
        {
          v14 = v6[9];
          v15 = 4095;
          if ( v14 > 0x200000 )
            v15 = 0x1FFFFF;
          if ( v14 > 0x40000000 )
            v15 = 0x3FFFFFFF;
          v13[12] -= (v15 + v14) & ~v15;
          _fastrpc_dma_buf_free(v6);
          kfree(v6);
        }
        mutex_unlock(v13 + 2);
      }
      v9 = raw_spin_lock_irqsave(a1 + 51600);
      v6 = (_QWORD *)*v7;
      v8 = v9;
      if ( (_QWORD *)*v7 == v7 )
        goto LABEL_20;
    }
    v16 = v12;
    v18 = raw_spin_lock_irqsave(a1 + 51600);
    v19 = *(_QWORD **)(v3 + 3600);
    v8 = v18;
    if ( v6 == v7 || v6 == v19 || (_QWORD *)*v19 != v7 )
    {
      _list_add_valid_or_report(v6, v19, v3 + 3592);
    }
    else
    {
      *(_QWORD *)(v3 + 3600) = v6;
      *v6 = v7;
      v6[1] = v19;
      *v19 = v6;
    }
  }
  raw_spin_unlock_irqrestore(a1 + 51600, v8);
  return v16;
}
