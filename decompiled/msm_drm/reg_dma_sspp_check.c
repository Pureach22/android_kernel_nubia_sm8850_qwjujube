__int64 __fastcall reg_dma_sspp_check(unsigned int *a1, _QWORD *a2, unsigned int a3, unsigned int a4)
{
  const void *v6; // x1
  __int64 v7; // x2
  __int64 v8; // x9

  if ( a1 && a2 )
  {
    if ( a4 < 3 )
    {
      v6 = (const void *)a2[2];
      v7 = a1[12];
      if ( v6 && (unsigned int)(v7 - 15) > 0xFFFFFFF1 )
      {
        v8 = a1[348];
        if ( (unsigned int)v8 > 1 )
        {
          __break(0x5512u);
        }
        else if ( ((240LL * a3 + 6000LL * a4 + 16 * v7) | (unsigned __int64)(8 * v8)) >> 4 <= 0x464 )
        {
          if ( sspp_buf[750 * a4 + 30 * a3 + 2 * v7 + v8] )
            return 0;
          _drm_err("invalid dma_buf for rect idx %d sspp idx %d\n", a4, v7);
          return 4294967274LL;
        }
        __break(1u);
        return vig_gamutv5_off(a1, v6);
      }
      _drm_err("invalid ctl %pK sspp idx %d feature %d\n", v6, v7, a3);
    }
    else
    {
      _drm_err("invalid multirect idx %d\n", a4);
    }
  }
  else
  {
    _drm_err("invalid cfg %pK ctx %pK\n", a2, a1);
  }
  return 4294967274LL;
}
