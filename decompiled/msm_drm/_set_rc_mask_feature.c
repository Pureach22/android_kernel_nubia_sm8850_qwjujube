__int64 __fastcall set_rc_mask_feature(__int64 a1, _QWORD *a2, __int64 a3)
{
  __int64 v4; // x8
  __int64 v5; // x21
  __int64 v8; // x8
  _DWORD *v9; // x8
  int v10; // w0
  unsigned int v11; // w19
  __int64 result; // x0
  int v13; // w8
  unsigned int v14; // w8
  __int64 v15; // x0

  if ( !a1 || !a2 || !a3 )
  {
    _drm_err("invalid arguments\n");
    return 4294967274LL;
  }
  v4 = *(unsigned int *)(a1 + 28);
  if ( (unsigned int)v4 >= 3 )
  {
LABEL_21:
    __break(0x5512u);
    v15 = MEMORY[0x2526C08]();
    return set_spr_init_feature(v15);
  }
  v5 = a1 + 808;
  if ( !*(_QWORD *)(a1 + 808 + 8 * v4) )
  {
    if ( (_DWORD)v4 == 1 )
      return 0;
    _drm_err("invalid rc ops\n");
    return 4294967274LL;
  }
  _drm_dev_dbg(
    0,
    0,
    1,
    "dspp %d setup mask for rc instance %u\n",
    *(_DWORD *)(a1 + 64),
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 536LL));
  v8 = *(unsigned int *)(a1 + 28);
  if ( (unsigned int)v8 > 2 )
    goto LABEL_21;
  v9 = *(_DWORD **)(v5 + 8 * v8);
  if ( *(v9 - 1) != 905945830 )
    __break(0x8228u);
  v10 = ((__int64 (__fastcall *)(__int64, _QWORD *))v9)(a1, a2);
  if ( v10 )
  {
    v11 = v10;
    _drm_err("failed to setup rc mask, ret %d\n", v10);
    return v11;
  }
  else
  {
    v13 = *(_DWORD *)(a3 + 7588);
    result = 0;
    if ( *a2 )
      v14 = v13 | 1;
    else
      v14 = v13 & 0xFFFFFFFE;
    *(_DWORD *)(a3 + 7588) = v14;
  }
  return result;
}
