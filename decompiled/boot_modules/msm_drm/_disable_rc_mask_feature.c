__int64 __fastcall disable_rc_mask_feature(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x8
  __int64 v5; // x20
  __int64 v8; // x8
  __int64 (__fastcall *v9)(__int64, __int64); // x8
  __int64 result; // x0
  unsigned int v11; // w20
  __int64 v12; // x0

  if ( !a1 || !a2 || !a3 )
  {
    _drm_err("invalid arguments");
    return 4294967274LL;
  }
  v4 = *(unsigned int *)(a1 + 28);
  if ( (unsigned int)v4 >= 3 )
  {
LABEL_18:
    __break(0x5512u);
    v12 = MEMORY[0x2527314]();
    return set_rc_pu_feature(v12);
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
  *(_DWORD *)(a2 + 8) = 0;
  *(_QWORD *)a2 = 0;
  v8 = *(unsigned int *)(a1 + 28);
  if ( (unsigned int)v8 > 2 )
    goto LABEL_18;
  v9 = *(__int64 (__fastcall **)(__int64, __int64))(v5 + 8 * v8);
  if ( *((_DWORD *)v9 - 1) != 905945830 )
    __break(0x8228u);
  result = v9(a1, a2);
  if ( (_DWORD)result )
  {
    v11 = result;
    _drm_err("failed to disable rc feature, ret %d\n", result);
    result = v11;
  }
  *(_DWORD *)(a3 + 7588) &= ~1u;
  return result;
}
