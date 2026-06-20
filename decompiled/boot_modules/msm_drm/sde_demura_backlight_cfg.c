__int64 __fastcall sde_demura_backlight_cfg(_QWORD *a1, _QWORD *a2)
{
  _QWORD *v2; // x19
  __int64 v3; // x2
  int v4; // w8

  v2 = a1;
  if ( !a1 || !a2 )
    return _drm_err("invalid parameter ctx %pK hw_cfg %pK\n", a1, a2);
  if ( *a2 )
  {
    v3 = *(unsigned int *)*a2;
    v4 = *(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 568LL);
  }
  else
  {
    _drm_dev_dbg(0, 0, 1, "disable demura backlight feature\n");
    a1 = v2;
    v3 = 0;
    v4 = *(_DWORD *)(*(_QWORD *)(v2[9] + 48LL) + 568LL);
  }
  return sde_reg_write(a1, (unsigned int)(v4 + 8), v3, "ctx->cap->sblk->demura.base + 0x8");
}
