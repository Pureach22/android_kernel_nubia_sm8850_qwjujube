__int64 __fastcall sde_vbif_clear_errors(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  unsigned int v3; // w8
  unsigned int v4; // w8
  __int64 v5; // x20
  __int64 v6; // x8
  __int64 v7; // x8
  void (__fastcall *v8)(__int64, char *, char *); // x8
  __int64 v9; // x19
  __int64 v10; // x8
  __int64 v11; // x8
  void (__fastcall *v12)(__int64, char *, char *); // x8
  char v13[8]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)v13 = 0;
  if ( !result )
  {
    result = printk(&unk_215A31, "sde_vbif_clear_errors");
    goto LABEL_34;
  }
  v1 = *(_QWORD *)(result + 152);
  v2 = result;
  if ( (*(_QWORD *)(v1 + 22008) & 0x100000000LL) != 0 && v1 )
  {
    mutex_lock(result + 3696);
    if ( (*(_QWORD *)(*(_QWORD *)(v2 + 152) + 22008LL) & 0x400000000LL) != 0
      && *(_DWORD *)(v2 + 3664) == 1
      && (v3 = *(_DWORD *)(v2 + 3656), v3 <= 6)
      && ((1 << v3) & 0x64) != 0
      || (v4 = *(_DWORD *)(v2 + 3656), v4 <= 4) && ((1 << v4) & 0x1A) != 0 )
    {
      result = mutex_unlock(v2 + 3696);
      if ( (_drm_debug & 4) != 0 )
        result = _drm_dev_dbg(0, 0, 0, "vbif operations not permitted\n");
      goto LABEL_34;
    }
    result = mutex_unlock(v2 + 3696);
  }
  v5 = *(_QWORD *)(v2 + 3512);
  if ( v5 )
  {
    v6 = *(unsigned int *)(v5 + 28);
    if ( (unsigned int)v6 > 2 )
      goto LABEL_35;
    if ( *(_QWORD *)(v5 + 240 + 8 * v6) )
    {
      mutex_lock(v5 + 288);
      v7 = *(unsigned int *)(v5 + 28);
      if ( (unsigned int)v7 > 2 )
        goto LABEL_35;
      v8 = *(void (__fastcall **)(__int64, char *, char *))(v5 + 240 + 8 * v7);
      if ( *((_DWORD *)v8 - 1) != -1796015307 )
        __break(0x8228u);
      v8(v5, &v13[4], v13);
      if ( *(_QWORD *)v13 )
      {
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "sde_vbif_clear_errors",
          630,
          -1,
          0,
          *(int *)&v13[4],
          *(int *)v13,
          -1059143953,
          v13[0]);
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "VBIF %d: pnd 0x%X, src 0x%X\n",
            *(_DWORD *)(v5 + 32),
            *(_DWORD *)&v13[4],
            *(_DWORD *)v13);
      }
      result = mutex_unlock(v5 + 288);
    }
  }
  v9 = *(_QWORD *)(v2 + 3520);
  if ( !v9 )
    goto LABEL_34;
  v10 = *(unsigned int *)(v9 + 28);
  if ( (unsigned int)v10 > 2 )
    goto LABEL_35;
  if ( !*(_QWORD *)(v9 + 240 + 8 * v10) )
    goto LABEL_34;
  mutex_lock(v9 + 288);
  v11 = *(unsigned int *)(v9 + 28);
  if ( (unsigned int)v11 > 2 )
LABEL_35:
    __break(0x5512u);
  v12 = *(void (__fastcall **)(__int64, char *, char *))(v9 + 240 + 8 * v11);
  if ( *((_DWORD *)v12 - 1) != -1796015307 )
    __break(0x8228u);
  v12(v9, &v13[4], v13);
  if ( *(_QWORD *)v13 )
  {
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_vbif_clear_errors",
      630,
      -1,
      1,
      *(int *)&v13[4],
      *(int *)v13,
      -1059143953,
      v13[0]);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "VBIF %d: pnd 0x%X, src 0x%X\n", *(_DWORD *)(v9 + 32), *(_DWORD *)&v13[4], *(_DWORD *)v13);
  }
  result = mutex_unlock(v9 + 288);
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
