__int64 __fastcall sg_release(__int64 a1, __int64 a2)
{
  unsigned int *v2; // x19
  __int64 v3; // x20
  __int64 v5; // x21
  __int64 v6; // x0
  unsigned int **v7; // x8
  __int64 v8; // x9
  __int64 v9; // x10
  int v16; // w8
  int v17; // w9
  int v18; // w8
  __int64 v19; // x2

  v2 = *(unsigned int **)(a2 + 32);
  if ( !v2 )
    return 4294967290LL;
  v3 = *((_QWORD *)v2 + 2);
  if ( !v3 )
    return 4294967290LL;
  mutex_lock(v3 + 32);
  scsi_autopm_put_device(*(_QWORD *)v3);
  _X0 = v2 + 1228;
  __asm { PRFM            #0x11, [X0] }
  do
    v16 = __ldxr(_X0);
  while ( __stlxr(v16 - 1, _X0) );
  if ( v16 == 1 )
  {
    __dmb(9u);
    v5 = *((_QWORD *)v2 + 2);
    v6 = raw_write_lock_irqsave(v5 + 104);
    v7 = *((unsigned int ***)v2 + 1);
    v8 = v6;
    if ( *v7 == v2 && (v9 = *(_QWORD *)v2, *(unsigned int **)(*(_QWORD *)v2 + 8LL) == v2) )
    {
      *(_QWORD *)(v9 + 8) = v7;
      *v7 = (unsigned int *)v9;
    }
    else
    {
      _list_del_entry_valid_or_report(v2);
    }
    *(_QWORD *)v2 = 0xDEAD000000000100LL;
    *((_QWORD *)v2 + 1) = 0xDEAD000000000122LL;
    raw_write_unlock_irqrestore(v5 + 104, v8);
    *((_QWORD *)v2 + 615) = 0xFFFFFFFE00000LL;
    *((_QWORD *)v2 + 616) = v2 + 1232;
    *((_QWORD *)v2 + 617) = v2 + 1232;
    *((_QWORD *)v2 + 618) = sg_remove_sfp_usercontext;
    queue_work_on(32, system_wq, v2 + 1230);
  }
  else if ( v16 <= 0 )
  {
    refcount_warn_saturate(_X0, 3);
  }
  v17 = *(unsigned __int8 *)(v3 + 116);
  v18 = *(_DWORD *)(v3 + 120) - 1;
  *(_DWORD *)(v3 + 120) = v18;
  if ( v17 == 1 )
  {
    v19 = 0;
    *(_BYTE *)(v3 + 116) = 0;
LABEL_18:
    _wake_up(v3 + 8, 1, v19, 0);
    goto LABEL_19;
  }
  if ( !v18 )
  {
    v19 = 1;
    goto LABEL_18;
  }
LABEL_19:
  mutex_unlock(v3 + 32);
  return 0;
}
