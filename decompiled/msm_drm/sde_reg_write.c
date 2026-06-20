__int64 __fastcall sde_reg_write(__int64 a1, unsigned int a2, unsigned int a3, const char *a4)
{
  unsigned int v7; // w8
  unsigned int v8; // w9
  __int64 v9; // x0

  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", a4, *(_DWORD *)(a1 + 8) + a2, a3);
  writel_relaxed_8(a3, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + a2));
  v7 = *(_DWORD *)(a1 + 24);
  v8 = 32 - __clz(v7);
  if ( v7 )
    v9 = v8;
  else
    v9 = 0;
  return sde_reglog_log(v9, a3, *(_DWORD *)(a1 + 8) + a2);
}
