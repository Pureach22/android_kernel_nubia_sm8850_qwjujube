__int64 __fastcall hif_get_target_ce_config(
        __int64 a1,
        _QWORD *a2,
        _DWORD *a3,
        _QWORD *a4,
        int *a5,
        _QWORD *a6,
        _DWORD *a7)
{
  __int64 result; // x0

  *a2 = *(_QWORD *)(a1 + 27392);
  *a3 = *(_DWORD *)(a1 + 27408);
  result = hif_select_service_to_pipe_map(a1, a4, a5);
  if ( a6 )
    *a6 = target_shadow_reg_cfg;
  if ( a7 )
    *a7 = 36;
  return result;
}
