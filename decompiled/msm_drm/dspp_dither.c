_QWORD *__fastcall dspp_dither(_QWORD *result)
{
  if ( *(_DWORD *)(*(_QWORD *)(result[9] + 48LL) + 284LL) == 65543 )
  {
    result[50] = sde_setup_dspp_dither_v1_7;
    result[51] = hfi_setup_dspp_pa_dither_v1_7;
  }
  return result;
}
