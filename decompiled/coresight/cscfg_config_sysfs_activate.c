__int64 __fastcall cscfg_config_sysfs_activate(__int64 a1, char a2)
{
  __int64 v4; // x8
  __int64 v5; // x20
  __int64 v6; // x9
  unsigned int v7; // w19
  _QWORD *v8; // x8
  __int64 v9; // x8
  __int64 v10; // x19
  __int64 v11; // x9
  unsigned int v19; // w11
  unsigned int v22; // w11
  unsigned int v25; // w9
  unsigned int v28; // w9

  mutex_lock(&cscfg_mutex);
  v4 = cscfg_mgr;
  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 64) + 32LL);
  v6 = *(unsigned int *)(cscfg_mgr + 1168);
  if ( (a2 & 1) != 0 )
  {
    if ( (_DWORD)v6 || *(_DWORD *)(cscfg_mgr + 1176) == 2 )
    {
LABEL_4:
      v7 = -16;
      goto LABEL_23;
    }
    v10 = cscfg_mgr + 944;
    while ( 1 )
    {
      v10 = *(_QWORD *)v10;
      if ( v10 == cscfg_mgr + 944 )
        break;
      if ( *(_QWORD *)(*(_QWORD *)(v10 + 48) + 32LL) == v5 )
      {
        if ( !*(_BYTE *)(v10 + 80) )
          goto LABEL_4;
        v11 = *(_QWORD *)(v10 + 64);
        if ( *(_DWORD *)(v11 + 16) == 1 )
        {
          if ( (try_module_get(*(_QWORD *)(v11 + 24)) & 1) == 0 )
            break;
          v4 = cscfg_mgr;
        }
        _X8 = (unsigned int *)(v4 + 976);
        __asm { PRFM            #0x11, [X8] }
        do
          v25 = __ldxr(_X8);
        while ( __stxr(v25 + 1, _X8) );
        _X8 = (unsigned int *)(v10 + 56);
        __asm { PRFM            #0x11, [X8] }
        do
          v28 = __ldxr(_X8);
        while ( __stxr(v28 + 1, _X8) );
        goto LABEL_13;
      }
    }
LABEL_22:
    v7 = -22;
    goto LABEL_23;
  }
  if ( v6 != v5 )
    goto LABEL_22;
  v8 = (_QWORD *)(cscfg_mgr + 944);
  while ( 1 )
  {
    v8 = (_QWORD *)*v8;
    if ( v8 == (_QWORD *)(cscfg_mgr + 944) )
      break;
    if ( *(_QWORD *)(v8[6] + 32LL) == v5 )
    {
      _X9 = (unsigned int *)(v8 + 7);
      __asm { PRFM            #0x11, [X9] }
      do
        v19 = __ldxr(_X9);
      while ( __stxr(v19 - 1, _X9) );
      _X9 = (unsigned int *)(cscfg_mgr + 976);
      __asm { PRFM            #0x11, [X9] }
      do
        v22 = __ldxr(_X9);
      while ( __stxr(v22 - 1, _X9) );
      v9 = v8[8];
      if ( *(_DWORD *)(v9 + 16) == 1 )
        module_put(*(_QWORD *)(v9 + 24));
      break;
    }
  }
  LODWORD(v5) = 0;
LABEL_13:
  v7 = 0;
  *(_DWORD *)(cscfg_mgr + 1168) = v5;
LABEL_23:
  mutex_unlock(&cscfg_mutex);
  return v7;
}
