_QWORD *__fastcall dspp_ad(_QWORD *result)
{
  if ( *(_DWORD *)(*(_QWORD *)(result[9] + 48LL) + 356LL) == 0x40000 )
  {
    result[65] = sde_setup_dspp_ad4;
    result[68] = sde_read_intr_resp_ad4;
    result[62] = &sde_validate_dspp_ad4;
  }
  return result;
}
