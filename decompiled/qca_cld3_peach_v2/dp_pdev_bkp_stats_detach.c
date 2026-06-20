__int64 __fastcall dp_pdev_bkp_stats_detach(__int64 a1)
{
  _QWORD *v1; // x20
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x0
  __int64 v6; // x23
  _QWORD *v7; // x8
  _QWORD *v8; // x9
  __int64 v9; // x8

  v1 = (_QWORD *)(a1 + 94208);
  result = *(_QWORD *)(a1 + 96408);
  if ( result )
  {
    _flush_workqueue(result);
    destroy_workqueue(v1[275]);
    flush_work(a1 + 96360);
    cancel_work_sync(a1 + 96360);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 96424);
      v5 = v1[279];
      if ( v5 )
        goto LABEL_6;
    }
    else
    {
      raw_spin_lock_bh(a1 + 96424);
      v1[278] |= 1uLL;
      v5 = v1[279];
      if ( v5 )
      {
        do
        {
LABEL_6:
          v6 = *(_QWORD *)(v5 + 1288);
          v7 = *(_QWORD **)(v5 + 1296);
          v8 = (_QWORD *)(v6 + 1296);
          if ( !v6 )
            v8 = v1 + 280;
          *v8 = v7;
          *v7 = *(_QWORD *)(v5 + 1288);
          *(_QWORD *)(v5 + 1296) = 0;
          *(_QWORD *)(v5 + 1288) = 0;
          _qdf_mem_free(v5);
          v5 = v6;
        }
        while ( v6 );
      }
    }
    v9 = v1[278];
    if ( (v9 & 1) != 0 )
    {
      v1[278] = v9 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(a1 + 96424);
    }
    else
    {
      return raw_spin_unlock(a1 + 96424);
    }
  }
  return result;
}
