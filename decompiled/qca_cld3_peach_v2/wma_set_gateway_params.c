__int64 __fastcall wma_set_gateway_params(
        _QWORD *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  if ( (unsigned int)_wma_validate_handle(
                       (__int64)a1,
                       (__int64)"wma_set_gateway_params",
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       a10) )
    return 4;
  else
    return wmi_unified_set_gateway_params_cmd(*a1, a2);
}
