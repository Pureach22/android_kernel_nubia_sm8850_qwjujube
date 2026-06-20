void pld_deinit()
{
  __int64 v0; // x19
  __int64 v1; // x20
  _QWORD *v2; // x9
  _QWORD **v3; // x22
  _QWORD *v4; // x8
  __int64 v5; // x10

  v0 = pld_ctx;
  if ( pld_ctx )
  {
    v1 = raw_spin_lock_irqsave(pld_ctx + 8);
    v3 = (_QWORD **)(v0 + 16);
    v2 = *(_QWORD **)(v0 + 16);
    if ( v2 != (_QWORD *)(v0 + 16) )
    {
      do
      {
        v4 = (_QWORD *)v2[1];
        if ( (_QWORD *)*v4 == v2 && (v5 = *v2, *(_QWORD **)(*v2 + 8LL) == v2) )
        {
          *(_QWORD *)(v5 + 8) = v4;
          *v4 = v5;
        }
        else
        {
          _list_del_entry_valid_or_report(v2);
        }
        *v2 = 0xDEAD000000000100LL;
        v2[1] = 0xDEAD000000000122LL;
        kfree(v2 - 2);
        v2 = *v3;
      }
      while ( *v3 != v3 );
    }
    raw_spin_unlock_irqrestore(v0 + 8, v1);
    kfree(v0);
  }
  pld_ctx = 0;
}
