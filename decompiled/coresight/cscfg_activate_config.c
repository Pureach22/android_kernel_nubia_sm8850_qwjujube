__int64 __fastcall cscfg_activate_config(__int64 a1)
{
  __int64 v2; // x8
  unsigned int v3; // w19
  __int64 v4; // x20
  __int64 v5; // x9
  unsigned int v13; // w9
  unsigned int v16; // w9

  mutex_lock(&cscfg_mutex);
  v2 = cscfg_mgr;
  if ( *(_DWORD *)(cscfg_mgr + 1176) == 2 )
  {
LABEL_2:
    v3 = -16;
  }
  else
  {
    v4 = cscfg_mgr + 944;
    do
    {
      v4 = *(_QWORD *)v4;
      if ( v4 == cscfg_mgr + 944 )
        goto LABEL_11;
    }
    while ( *(_QWORD *)(*(_QWORD *)(v4 + 48) + 32LL) != a1 );
    if ( !*(_BYTE *)(v4 + 80) )
      goto LABEL_2;
    v5 = *(_QWORD *)(v4 + 64);
    if ( *(_DWORD *)(v5 + 16) == 1 )
    {
      if ( (try_module_get(*(_QWORD *)(v5 + 24)) & 1) == 0 )
      {
LABEL_11:
        v3 = -22;
        goto LABEL_12;
      }
      v2 = cscfg_mgr;
    }
    _X8 = (unsigned int *)(v2 + 976);
    __asm { PRFM            #0x11, [X8] }
    do
      v13 = __ldxr(_X8);
    while ( __stxr(v13 + 1, _X8) );
    _X8 = (unsigned int *)(v4 + 56);
    __asm { PRFM            #0x11, [X8] }
    do
      v16 = __ldxr(_X8);
    while ( __stxr(v16 + 1, _X8) );
    v3 = 0;
  }
LABEL_12:
  mutex_unlock(&cscfg_mutex);
  return v3;
}
