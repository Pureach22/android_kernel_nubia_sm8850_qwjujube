_QWORD *__fastcall dspp_hist(_QWORD *result)
{
  if ( *(_DWORD *)(*(_QWORD *)(result[9] + 48LL) + 320LL) == 65543 )
  {
    result[11] = sde_setup_dspp_hist_v1_7;
    result[14] = sde_read_dspp_hist_v1_7;
    result[17] = sde_lock_dspp_hist_v1_7;
  }
  return result;
}
