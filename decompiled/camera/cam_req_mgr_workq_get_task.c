int *__fastcall cam_req_mgr_workq_get_task(__int64 a1)
{
  __int64 v2; // x9
  int *v3; // x20
  int *v4; // x10
  int **v5; // x8
  __int64 v6; // x11
  unsigned int v14; // w12

  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 44) )
    {
      v2 = raw_spin_lock_irqsave(a1 + 40);
    }
    else
    {
      raw_spin_lock_bh(a1 + 40);
      v2 = 0;
    }
    v4 = *(int **)(a1 + 280);
    if ( v4 == (int *)(a1 + 280) )
    {
      v3 = nullptr;
      if ( *(_DWORD *)(a1 + 44) )
      {
LABEL_14:
        raw_spin_unlock_irqrestore(a1 + 40, v2);
        return v3;
      }
    }
    else
    {
      v3 = v4 - 8;
      if ( v4 != &dword_20 )
      {
        _X8 = (unsigned int *)(a1 + 244);
        __asm { PRFM            #0x11, [X8] }
        do
          v14 = __ldxr(_X8);
        while ( __stxr(v14 - 1, _X8) );
        v5 = *((int ***)v4 + 1);
        if ( *v5 == v4 && (v6 = *(_QWORD *)v4, *(int **)(*(_QWORD *)v4 + 8LL) == v4) )
        {
          *(_QWORD *)(v6 + 8) = v5;
          *v5 = (int *)v6;
        }
        else
        {
          _list_del_entry_valid_or_report(v4);
        }
        *(_QWORD *)v4 = v4;
        *((_QWORD *)v4 + 1) = v4;
      }
      if ( *(_DWORD *)(a1 + 44) )
        goto LABEL_14;
    }
    raw_spin_unlock_bh(a1 + 40);
    return v3;
  }
  return nullptr;
}
