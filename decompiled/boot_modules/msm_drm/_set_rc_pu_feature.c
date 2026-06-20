__int64 __fastcall set_rc_pu_feature(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x19
  __int64 v7; // x8
  __int64 (__fastcall *v8)(__int64, __int64); // x8
  __int64 result; // x0
  unsigned int v10; // w19
  __int64 v11; // x0

  if ( !a1 || !a2 || !a3 )
  {
    _drm_err("invalid arguments\n");
    return 4294967274LL;
  }
  v3 = *(unsigned int *)(a1 + 28);
  if ( (unsigned int)v3 >= 3 )
  {
LABEL_17:
    __break(0x5512u);
    v11 = MEMORY[0x252741C]();
    return set_spr_pu_feature(v11);
  }
  v4 = a1 + 856;
  if ( !*(_QWORD *)(a1 + 856 + 8 * v3) )
  {
    if ( (_DWORD)v3 == 1 )
      return 0;
    _drm_err("invalid rc ops\n");
    return 4294967274LL;
  }
  _drm_dev_dbg(
    0,
    0,
    1,
    "dspp %d setup pu roi for rc instance %u\n",
    *(_DWORD *)(a1 + 64),
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 536LL));
  v7 = *(unsigned int *)(a1 + 28);
  if ( (unsigned int)v7 > 2 )
    goto LABEL_17;
  v8 = *(__int64 (__fastcall **)(__int64, __int64))(v4 + 8 * v7);
  if ( *((_DWORD *)v8 - 1) != 905945830 )
    __break(0x8228u);
  result = v8(a1, a2);
  if ( (result & 0x80000000) != 0 )
  {
    v10 = result;
    _drm_err("failed to setup rc pu roi, ret %d\n", result);
    return v10;
  }
  return result;
}
