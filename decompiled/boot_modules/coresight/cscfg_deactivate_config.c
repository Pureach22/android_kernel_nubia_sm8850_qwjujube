__int64 __fastcall cscfg_deactivate_config(__int64 a1)
{
  _QWORD *v2; // x8
  __int64 v3; // x8
  unsigned int v11; // w12
  unsigned int v14; // w11

  mutex_lock(&cscfg_mutex);
  v2 = (_QWORD *)(cscfg_mgr + 944);
  while ( 1 )
  {
    v2 = (_QWORD *)*v2;
    if ( v2 == (_QWORD *)(cscfg_mgr + 944) )
      break;
    if ( *(_QWORD *)(v2[6] + 32LL) == a1 )
    {
      _X10 = (unsigned int *)(v2 + 7);
      __asm { PRFM            #0x11, [X10] }
      do
        v11 = __ldxr(_X10);
      while ( __stxr(v11 - 1, _X10) );
      _X9 = (unsigned int *)(cscfg_mgr + 976);
      __asm { PRFM            #0x11, [X9] }
      do
        v14 = __ldxr(_X9);
      while ( __stxr(v14 - 1, _X9) );
      v3 = v2[8];
      if ( *(_DWORD *)(v3 + 16) == 1 )
        module_put(*(_QWORD *)(v3 + 24));
      return mutex_unlock(&cscfg_mutex);
    }
  }
  return mutex_unlock(&cscfg_mutex);
}
