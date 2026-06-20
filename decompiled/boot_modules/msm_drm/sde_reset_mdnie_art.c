double __fastcall sde_reset_mdnie_art(__int64 a1)
{
  int v1; // w20
  double result; // d0

  if ( a1 )
  {
    v1 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 604LL);
    if ( v1 )
    {
      sde_reg_write(a1, v1 + 988, 0x10u, "aiqe_base + 0x3dc");
      sde_reg_write(a1, v1 + 256, 0, "aiqe_base + 0x100");
    }
    else
    {
      return _drm_dev_dbg(0, 0, 1, "AIQE not supported on DSPP idx %d", *(_DWORD *)(a1 + 64));
    }
  }
  else
  {
    _drm_err("invalid parameters ctx %pK\n", nullptr);
  }
  return result;
}
