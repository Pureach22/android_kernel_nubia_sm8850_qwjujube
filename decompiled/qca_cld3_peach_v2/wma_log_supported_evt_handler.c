__int64 __fastcall wma_log_supported_evt_handler(__int64 *a1)
{
  if ( (unsigned int)wmi_unified_log_supported_evt_cmd(*a1) )
    return 4294967274LL;
  else
    return 0;
}
