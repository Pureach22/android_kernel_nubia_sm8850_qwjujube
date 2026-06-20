__int64 __fastcall sde_rm_check_dsc(__int64 a1, __int64 a2, __int64 a3, __int64 a4, int a5, int a6)
{
  __int64 v6; // x9
  __int64 v7; // x8
  __int64 v8; // x9
  unsigned int v9; // w6
  unsigned __int64 v10; // x4
  __int64 v11; // x8
  __int64 result; // x0

  v6 = *(_QWORD *)(a2 + 16);
  v7 = *(_QWORD *)(*(_QWORD *)(a2 + 40) + 40LL);
  if ( v6 && *(_DWORD *)(v6 + 20) != *(_DWORD *)(a1 + 20)
    || (v8 = *(_QWORD *)(a2 + 24)) != 0 && *(_DWORD *)(v8 + 20) != *(_DWORD *)(a1 + 20) )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "dsc %d already reserved\n", *(_DWORD *)(v7 + 16));
    return 0;
  }
  if ( !a4 )
  {
    if ( (_drm_debug & 4) != 0 )
    {
      v9 = -1;
LABEL_15:
      _drm_dev_dbg(0, 0, 0, "dsc %d can't match of pp %d\n", *(unsigned int *)(v7 + 16), v9);
    }
    return 0;
  }
  v9 = *(_DWORD *)(a4 + 36);
  if ( (v9 & 1) != (*(_DWORD *)(a2 + 36) & 1) )
  {
    if ( (_drm_debug & 4) != 0 )
      goto LABEL_15;
    return 0;
  }
  if ( a3 )
  {
    v10 = *(unsigned int *)(v7 + 16);
    v11 = *(_QWORD *)(*(_QWORD *)(a3 + 40) + 40LL);
    if ( ((*(_QWORD *)(v11 + ((v10 >> 3) & 0x1FFFFFF8) + 48) >> v10) & 1) != 0 )
      return 1;
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "dsc %d not peer of dsc %d\n", v10, *(unsigned int *)(v11 + 16));
    return 0;
  }
  result = 1;
  if ( (v9 & 1) == (a6 & 1) && a5 == 1 && a6 && *(_DWORD *)(a2 + 36) != a6 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "number of dsc %d, dsc %d can't match of pp %d\n", 1, a6, v9);
    return 0;
  }
  return result;
}
