__int64 __fastcall sde_setup_dspp_ltm_hist_ctrl_common(__int64 a1, __int64 a2, int a3, __int64 a4)
{
  __int64 v4; // x8
  int v8; // w22
  int v9; // w23
  int v10; // w24

  v4 = *(unsigned int *)(a1 + 64);
  if ( (unsigned int)v4 >= 5 )
    return _drm_err("Invalid idx %d\n", v4);
  v8 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 380LL);
  v9 = a3 & 0x1FFFFFA;
  if ( *(_BYTE *)(a4 + 32) )
    v10 = 4;
  else
    v10 = 0;
  sde_reg_write(a1, (unsigned int)(v8 + 8), *(_DWORD *)(a4 + 4 * v4) & 0x7FFFFFF, "offset");
  sde_reg_write(a1, (unsigned int)(v8 + 12), *(_DWORD *)(a4 + 20) & 0xFFFFFF, "offset");
  sde_reg_write(a1, (unsigned int)(v8 + 16), *(_DWORD *)(a4 + 24) & 0xFFFFFF, "offset");
  sde_reg_write(a1, (unsigned int)(v8 + 20), *(_DWORD *)(a4 + 28) & 0xFFFFFF, "offset");
  sde_setup_dspp_ltm_hist_bufferv1((_QWORD *)a1, a2);
  return sde_reg_write(
           a1,
           (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 380LL) + 4),
           v9 | v10 | 1u,
           "ctx->cap->sblk->ltm.base + 0x4");
}
