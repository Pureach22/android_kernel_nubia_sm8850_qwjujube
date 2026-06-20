__int64 __fastcall sg_remove_sfp_usercontext(__int64 a1)
{
  unsigned int *v2; // x20
  __int64 v3; // x19
  __int64 v4; // x22
  _QWORD **v5; // x25
  _QWORD *v6; // x23
  _QWORD *v7; // x8
  __int64 v8; // x9
  __int64 v9; // x0
  _WORD *v10; // x22
  unsigned __int64 v11; // x25
  __int64 v13; // x22
  int v19; // w8

  v2 = *(unsigned int **)(a1 - 4904);
  v3 = *(_QWORD *)v2;
  v4 = raw_write_lock_irqsave(a1 - 4872);
  v5 = (_QWORD **)(a1 - 4776);
  v6 = *(_QWORD **)(a1 - 4776);
  if ( v6 != (_QWORD *)(a1 - 4776) )
  {
    do
    {
      sg_finish_rem_req((__int64)v6);
      v7 = (_QWORD *)v6[1];
      if ( (_QWORD *)*v7 == v6 && (v8 = *v6, *(_QWORD **)(*v6 + 8LL) == v6) )
      {
        *(_QWORD *)(v8 + 8) = v7;
        *v7 = v8;
      }
      else
      {
        _list_del_entry_valid_or_report(v6);
      }
      v6[2] = 0;
      *v6 = 0xDEAD000000000100LL;
      v6[1] = 0xDEAD000000000122LL;
      v6 = *v5;
    }
    while ( *v5 != v5 );
  }
  raw_write_unlock_irqrestore(a1 - 4872, v4);
  if ( *(_DWORD *)(a1 - 4800) )
  {
    v9 = *(_QWORD *)(a1 - 4792);
    v10 = (_WORD *)(a1 - 4808);
    if ( v9 && *(_DWORD *)(a1 - 4804) && !*(_BYTE *)(a1 - 4780) )
    {
      if ( *v10 )
      {
        v11 = 0;
        while ( 1 )
        {
          v9 = *(_QWORD *)(a1 - 4792);
          if ( !*(_QWORD *)(v9 + 8 * v11) )
            break;
          _free_pages(*(_QWORD *)(v9 + 8 * v11++), *(unsigned int *)(a1 - 4784));
          if ( v11 >= (unsigned __int16)*v10 )
          {
            v9 = *(_QWORD *)(a1 - 4792);
            break;
          }
        }
      }
      kfree(v9);
    }
    *(_QWORD *)(a1 - 4792) = 0;
    *(_QWORD *)(a1 - 4784) = 0;
    *(_QWORD *)v10 = 0;
    *(_QWORD *)(a1 - 4800) = 0;
  }
  kfree(a1 - 4920);
  _X0 = v2 + 42;
  __asm { PRFM            #0x11, [X0] }
  do
    v19 = __ldxr(_X0);
  while ( __stlxr(v19 - 1, _X0) );
  if ( v19 == 1 )
  {
    __dmb(9u);
    blk_put_queue(*(_QWORD *)(*(_QWORD *)v2 + 8LL));
    v13 = raw_write_lock_irqsave(&sg_index_lock);
    idr_remove(&sg_index_idr, v2[21]);
    raw_write_unlock_irqrestore(&sg_index_lock, v13);
    kfree(v2);
  }
  else if ( v19 <= 0 )
  {
    refcount_warn_saturate(_X0, 3);
  }
  scsi_device_put(v3);
  return module_put(&_this_module);
}
