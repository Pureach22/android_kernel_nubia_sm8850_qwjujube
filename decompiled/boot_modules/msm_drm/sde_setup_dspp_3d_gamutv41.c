__int64 __fastcall sde_setup_dspp_3d_gamutv41(_QWORD *a1, unsigned int **a2)
{
  int v4; // w0
  unsigned int *v5; // x1
  __int64 result; // x0
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    v4 = sde_reg_read(a1, *(unsigned int *)(*(_QWORD *)(a1[9] + 48LL) + 236LL));
    v5 = *a2;
    v7 = v4;
    if ( v5 )
    {
      result = sde_write_3d_gamut(a1, v5, *(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 236LL), &v7, 0x10u);
    }
    else
    {
      _drm_dev_dbg(0, 0, 1, "disable gamut feature\n");
      result = sde_reg_write(a1, *(unsigned int *)(*(_QWORD *)(a1[9] + 48LL) + 236LL), 0, "ctx->cap->sblk->gamut.base");
    }
  }
  else
  {
    result = _drm_err("invalid param ctx %pK cfg %pK\n", a1, a2);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
