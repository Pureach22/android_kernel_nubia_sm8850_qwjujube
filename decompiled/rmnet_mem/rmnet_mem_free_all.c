__int64 rmnet_mem_free_all()
{
  __int64 v0; // x22
  _QWORD *v1; // x28
  _QWORD *v2; // x20
  _QWORD *v3; // x8
  _QWORD *v4; // x26
  _QWORD *v5; // x8
  _QWORD *v6; // x9
  _QWORD *v7; // x10
  unsigned int v8; // w8
  __int64 v9; // x0
  __int64 v10; // x8
  unsigned int v11; // w8
  unsigned int v18; // w19
  unsigned int v19; // w19
  __int64 v21; // [xsp+8h] [xbp-8h]

  v0 = 0;
  v21 = raw_spin_lock_irqsave(&rmnet_mem_lock);
  do
  {
    v1 = (_QWORD *)((char *)&rmnet_mem_pool + 16 * v0);
    v2 = (_QWORD *)*v1;
    if ( (_QWORD *)*v1 != v1 )
    {
      do
      {
        v4 = (_QWORD *)*v2;
        v3 = (_QWORD *)v2[1];
        if ( (_QWORD *)*v3 == v2 && (_QWORD *)v4[1] == v2 )
        {
          v4[1] = v3;
          *v3 = v4;
        }
        else
        {
          _list_del_entry_valid_or_report(v2);
        }
        *v2 = v2;
        v2[1] = v2;
        v6 = v2 + 2;
        v5 = (_QWORD *)v2[2];
        if ( v5 != v2 + 2 )
        {
          v7 = (_QWORD *)v2[3];
          if ( (_QWORD *)*v7 == v6 && (_QWORD *)v5[1] == v6 )
          {
            v5[1] = v7;
            *v7 = v5;
          }
          else
          {
            _list_del_entry_valid_or_report(v2 + 2);
          }
          v2[2] = v2 + 2;
          v2[3] = v6;
          v8 = *((unsigned __int8 *)v2 + 32);
          if ( v8 > 4 )
            goto LABEL_28;
          if ( v8 == 4 )
            goto LABEL_29;
          --*((_DWORD *)&cache_pool_size + *((unsigned __int8 *)v2 + 32));
        }
        v9 = *(v2 - 1);
        v10 = *(_QWORD *)(v9 + 8);
        if ( (v10 & 1) != 0 )
          v9 = v10 - 1;
        _X8 = (unsigned int *)(v9 + 52);
        __asm { PRFM            #0x11, [X8] }
        do
        {
          v18 = __ldxr(_X8);
          v19 = v18 - 1;
        }
        while ( __stlxr(v19, _X8) );
        __dmb(0xBu);
        if ( !v19 )
          _folio_put();
        v11 = *((unsigned __int8 *)v2 + 32);
        if ( v11 > 4 )
        {
LABEL_28:
          __break(0x5512u);
LABEL_29:
          __break(1u);
          JUMPOUT(0xFFFFFFFFFD763C84LL);
        }
        if ( v11 == 4 )
          goto LABEL_29;
        --*((_DWORD *)&static_pool_size + *((unsigned __int8 *)v2 + 32));
        kfree(v2 - 1);
        v2 = v4;
      }
      while ( v4 != v1 );
    }
    ++v0;
  }
  while ( v0 != 4 );
  return raw_spin_unlock_irqrestore(&rmnet_mem_lock, v21);
}
