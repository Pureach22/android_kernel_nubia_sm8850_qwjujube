__int64 __fastcall reg_dma_dspp_check(unsigned int *a1, _QWORD *a2, unsigned int a3)
{
  const void *v4; // x1
  __int64 v5; // x2

  if ( a1 && a2 )
  {
    v4 = (const void *)a2[2];
    v5 = a1[16];
    if ( v4 && a3 <= 0x18 && (unsigned int)v5 <= 4 && a1[374] < 2 )
    {
      if ( (char *)&dspp_buf + 80 * a3 + 16 * v5 )
        return 0;
      _drm_err("invalid dma_buf\n");
    }
    else
    {
      _drm_err("invalid ctl %pK dspp idx %d feature %d dpu idx %d\n", v4, v5, a3, a1[374]);
    }
  }
  else
  {
    _drm_err("invalid cfg %pK ctx %pK\n", a2, a1);
  }
  return 4294967274LL;
}
