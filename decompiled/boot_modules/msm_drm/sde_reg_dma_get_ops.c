char *__fastcall sde_reg_dma_get_ops(unsigned int a1)
{
  char *v2; // x8
  char *v3; // x8
  __int64 v4; // t1

  if ( a1 < 2 )
  {
    v2 = (char *)&reg_dma + 176 * a1;
    v4 = *((_QWORD *)v2 + 3);
    v3 = v2 + 24;
    if ( v4 )
      return v3;
    else
      return nullptr;
  }
  else
  {
    _drm_err("invalid dpu idx %d\n", a1);
    return nullptr;
  }
}
