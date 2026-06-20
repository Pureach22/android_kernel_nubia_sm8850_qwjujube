__int64 __fastcall sde_hw_sspp_setup_pre_downscale(__int64 result, _DWORD *a2)
{
  if ( result )
  {
    if ( a2 )
      return sde_reg_write(
               result,
               *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 56) + 48LL) + 72LL) + 80,
               *a2 | (unsigned int)(16 * a2[1]) | (a2[2] << 8) | (a2[3] << 12),
               "SSPP_PRE_DOWN_SCALE + idx");
  }
  return result;
}
