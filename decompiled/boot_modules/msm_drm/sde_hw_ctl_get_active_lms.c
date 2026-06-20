__int64 __fastcall sde_hw_ctl_get_active_lms(__int64 a1)
{
  __int16 v1; // w0
  unsigned int v2; // w8

  if ( a1 )
  {
    v1 = sde_reg_read(a1, 304);
    v2 = v1 & 1 | 2;
    if ( (v1 & 2) == 0 )
      v2 = v1 & 1;
    if ( (v1 & 4) != 0 )
      v2 |= 4u;
    if ( (v1 & 8) != 0 )
      v2 |= 8u;
    if ( (v1 & 0x10) != 0 )
      v2 |= 0x10u;
    if ( (v1 & 0x20) != 0 )
      v2 |= 0x20u;
    if ( (v1 & 0x40) != 0 )
      v2 |= 0x40u;
    if ( (v1 & 0x80LL) != 0 )
      v2 |= 0x80u;
    if ( (v1 & 0x100LL) != 0 )
      v2 |= 1u;
    if ( (v1 & 0x200LL) != 0 )
      v2 |= 1u;
    if ( (v1 & 0x400LL) != 0 )
      v2 |= 1u;
    if ( (v1 & 0x800) != 0 )
      return v2 | 1;
    else
      return v2;
  }
  else
  {
    _drm_err("invalid args - ctx invalid\n");
    return 0;
  }
}
