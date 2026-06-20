__int64 __fastcall cscfg_csdev_enable_active_config(__int64 a1, __int64 a2, int a3)
{
  _QWORD *v6; // x22
  unsigned int v7; // w20
  __int64 v8; // x9

  if ( !*(_DWORD *)(cscfg_mgr + 976) )
    return 0;
  raw_spin_lock_irqsave(a1 + 1040);
  v6 = *(_QWORD **)(a1 + 1024);
  if ( v6 == (_QWORD *)(a1 + 1024) )
  {
LABEL_3:
    v7 = 0;
    goto LABEL_4;
  }
  while ( 1 )
  {
    v8 = *(v6 - 3);
    if ( *(_DWORD *)(v8 + 72) )
    {
      if ( *(_QWORD *)(*(_QWORD *)(v8 + 64) + 32LL) == a2 )
        break;
    }
    v6 = (_QWORD *)*v6;
    if ( v6 == (_QWORD *)(a1 + 1024) )
      goto LABEL_3;
  }
  *(_QWORD *)(a1 + 1048) = v6 - 3;
  raw_spin_unlock_irqrestore(a1 + 1040);
  if ( v6 == &_ksymtab_coresight_add_out_conn )
    return 0;
  v7 = cscfg_csdev_enable_config((_DWORD *)v6 - 6, a3);
  if ( v7 )
    return v7;
  raw_spin_lock_irqsave(a1 + 1040);
  if ( *(_QWORD *)(a1 + 1048) )
  {
    v7 = 0;
    *((_BYTE *)v6 - 8) = 1;
  }
  else
  {
    v7 = -16;
  }
LABEL_4:
  raw_spin_unlock_irqrestore(a1 + 1040);
  return v7;
}
