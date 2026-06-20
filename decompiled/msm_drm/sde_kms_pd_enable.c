__int64 __fastcall sde_kms_pd_enable(__int64 a1)
{
  __int64 v2; // x21
  unsigned int v3; // w0
  int v4; // w7
  unsigned int v5; // w20
  unsigned int v7; // w8
  unsigned int v14; // w10
  char v15; // [xsp+0h] [xbp+0h]

  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "\n");
  v2 = *(_QWORD *)(*(_QWORD *)(a1 - 24) + 8LL);
  v3 = _pm_runtime_resume(v2, 4);
  if ( (v3 & 0x80000000) != 0 )
  {
    v7 = *(_DWORD *)(v2 + 480);
    v5 = v3;
    do
    {
      if ( !v7 )
        break;
      _X12 = (unsigned int *)(v2 + 480);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v14 = __ldxr(_X12);
        if ( v14 != v7 )
          break;
        if ( !__stlxr(v7 - 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v14 == v7;
      v7 = v14;
    }
    while ( !_ZF );
  }
  else
  {
    v5 = 0;
  }
  sde_evtlog_log(sde_dbg_base_evtlog, "sde_kms_pd_enable", 5462, -1, v5, *(_DWORD *)(a1 + 1304), -1059143953, v4, v15);
  return v5;
}
