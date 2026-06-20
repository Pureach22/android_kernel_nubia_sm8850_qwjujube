__int64 __fastcall mhi_uci_release(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  int v3; // w8
  _QWORD *v4; // x9
  _QWORD *v5; // x8
  _QWORD *v6; // x22
  __int64 v7; // x0
  _QWORD *v8; // x8
  char v9; // w8
  unsigned __int64 v11; // x8
  __int64 v12; // x9
  __int64 v13; // x8
  unsigned __int64 v20; // x10

  v2 = *(_QWORD *)(a2 + 32);
  mutex_lock(v2 + 48);
  v3 = *(_DWORD *)(v2 + 336) - 1;
  *(_DWORD *)(v2 + 336) = v3;
  if ( v3 )
    goto LABEL_18;
  if ( *(_QWORD *)(v2 + 352) && *(_DWORD *)(v2 + 360) <= 1u )
    ipc_log_string();
  if ( *(_BYTE *)(v2 + 340) == 1 )
    mhi_unprepare_from_transfer(*(_QWORD *)(v2 + 32));
  v4 = *(_QWORD **)(v2 + 240);
  if ( v4 != (_QWORD *)(v2 + 240) )
  {
    do
    {
      v6 = (_QWORD *)*v4;
      v5 = (_QWORD *)v4[1];
      if ( (_QWORD *)*v5 == v4 && (_QWORD *)v6[1] == v4 )
      {
        v6[1] = v5;
        *v5 = v6;
      }
      else
      {
        _list_del_entry_valid_or_report(v4);
      }
      v7 = *(v4 - 2);
      *v4 = 0xDEAD000000000100LL;
      v4[1] = 0xDEAD000000000122LL;
      kfree(v7);
      v4 = v6;
    }
    while ( v6 != (_QWORD *)(v2 + 240) );
  }
  v8 = *(_QWORD **)(v2 + 256);
  if ( v8 )
    kfree(*v8);
  v9 = *(_BYTE *)(v2 + 340);
  *(_QWORD *)(v2 + 256) = 0;
  if ( (v9 & 1) != 0 )
  {
LABEL_18:
    if ( *(_QWORD *)(v2 + 352) && *(_DWORD *)(v2 + 360) <= 1u )
      ipc_log_string();
    mutex_unlock(v2 + 48);
  }
  else
  {
    if ( *(_QWORD *)(v2 + 352) && *(_DWORD *)(v2 + 360) <= 1u )
      ipc_log_string();
    mutex_unlock(v2 + 48);
    v11 = *(unsigned int *)(v2 + 16);
    v12 = (v11 >> 6) & 0x3FFF;
    v13 = 1LL << v11;
    _X9 = (unsigned __int64 *)&uci_minors[v12];
    __asm { PRFM            #0x11, [X9] }
    do
      v20 = __ldxr(_X9);
    while ( __stxr(v20 & ~v13, _X9) );
    kfree(v2);
  }
  return 0;
}
