__int64 __fastcall sde_rm_reserve_pp(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        _QWORD *a6,
        _QWORD *a7,
        __int64 *a8)
{
  __int64 v16; // x1
  __int64 result; // x0
  __int64 v18; // x8
  __int64 v19; // [xsp+0h] [xbp-20h] BYREF
  __int64 v20; // [xsp+8h] [xbp-18h]
  int v21; // [xsp+10h] [xbp-10h]
  int v22; // [xsp+14h] [xbp-Ch]
  __int64 v23; // [xsp+18h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  v21 = 0;
  v19 = 0;
  v22 = 7;
  do
  {
    if ( (sde_rm_get_hw_locked(a1, (__int64)&v19, 1) & 1) == 0 )
    {
      v16 = *a8;
      if ( !*a8 )
        goto LABEL_5;
      goto LABEL_7;
    }
    v16 = v20;
  }
  while ( *(_DWORD *)(v20 + 36) != *(_DWORD *)(a4 + 60) );
  *a8 = v20;
  if ( !v16 )
  {
LABEL_5:
    printk(&unk_23BD79, "_sde_rm_reserve_pp");
    result = 0;
    goto LABEL_16;
  }
LABEL_7:
  if ( (sde_rm_is_blk_available(a1, v16, a2, a3) & 1) != 0 )
  {
    if ( **(_DWORD **)(a3 + 8) != 10
      || (v18 = *(_QWORD *)(*(_QWORD *)(*a8 + 40) + 40LL), (*(_QWORD *)(v18 + 32) & 8) != 0) )
    {
      result = 1;
      goto LABEL_16;
    }
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "pp %d doesn't support ppsplit\n", *(_DWORD *)(v18 + 16));
  }
  else if ( (_drm_debug & 4) != 0 )
  {
    _drm_dev_dbg(0, 0, 0, "lm %d pp %d already reserved\n", *(_DWORD *)(a5 + 36), *(_DWORD *)(*a8 + 36));
  }
  result = 0;
  *a6 = 0;
  *a7 = 0;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
