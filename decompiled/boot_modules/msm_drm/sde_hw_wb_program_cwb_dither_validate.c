__int64 __fastcall sde_hw_wb_program_cwb_dither_validate(
        __int64 a1,
        unsigned int a2,
        _DWORD *a3,
        __int64 a4,
        _BYTE *a5)
{
  unsigned int v6; // w20
  _BYTE *v7; // x21

  if ( !a1 )
  {
    _drm_err("Invalid pointer ctx is null\n");
    return 4294967274LL;
  }
  if ( a2 >= 5 )
  {
    _drm_err("Invalid dcwb_idx %d\n", a2);
    return 4294967274LL;
  }
  if ( a3 )
  {
    if ( (*a5 & 1) != 0 )
    {
      if ( a4 != 1120 )
      {
        printk(&unk_250D21, "sde_hw_wb_program_cwb_dither_validate");
        return 4294967274LL;
      }
      if ( a3[3] > 8u || a3[4] > 8u || a3[5] > 8u || a3[6] >= 9u )
      {
        printk(&unk_26D8F5, "sde_hw_wb_program_cwb_dither_validate");
        return 4294967274LL;
      }
      return 0;
    }
  }
  else
  {
    if ( (_drm_debug & 4) != 0 )
    {
      v6 = a2;
      v7 = a5;
      _drm_dev_dbg(0, 0, 0, "Null dither data\n");
      a5 = v7;
      a2 = v6;
    }
    *a5 = 0;
  }
  if ( (_drm_debug & 4) == 0 )
    return 0;
  _drm_dev_dbg(0, 0, 0, "cwb dither disabled, dcwb_idx %u\n", a2);
  return 0;
}
