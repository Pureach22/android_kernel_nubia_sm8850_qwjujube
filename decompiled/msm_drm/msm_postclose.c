__int64 __fastcall msm_postclose(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 result; // x0
  __int64 v5; // x20
  void (*v6)(void); // x8
  int v7; // w6
  int v8; // w7
  char v9; // [xsp+0h] [xbp+0h]

  v2 = *(_QWORD *)(a1 + 56);
  result = *(_QWORD *)(v2 + 8);
  if ( result )
  {
    v5 = *(_QWORD *)(a2 + 152);
    if ( *(_QWORD *)result )
    {
      v6 = *(void (**)(void))(*(_QWORD *)result + 160LL);
      if ( v6 )
      {
        if ( *((_DWORD *)v6 - 1) != -37677341 )
          __break(0x8228u);
        v6();
      }
    }
    mutex_lock(a1 + 128);
    if ( v5 == *(_QWORD *)(v2 + 584) )
      *(_QWORD *)(v2 + 584) = 0;
    mutex_unlock(a1 + 128);
    mutex_lock(v5 + 32);
    if ( *(_WORD *)(v5 + 28) )
    {
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "msm_postclose",
        1312,
        -1,
        *(unsigned __int16 *)(v5 + 28),
        -1059143953,
        v7,
        v8,
        v9);
      _pm_runtime_idle(*(_QWORD *)(a1 + 8), 4);
    }
    mutex_unlock(v5 + 32);
    result = kfree(v5);
    if ( *(_DWORD *)(a1 + 224) == 1 )
      return msm_lastclose(a1);
  }
  return result;
}
