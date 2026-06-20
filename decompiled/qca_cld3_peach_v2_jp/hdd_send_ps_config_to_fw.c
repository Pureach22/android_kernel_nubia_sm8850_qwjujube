__int64 __fastcall hdd_send_ps_config_to_fw(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0

  result = _hdd_validate_adapter(a1, (__int64)"hdd_send_ps_config_to_fw", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !(_DWORD)result )
    return sme_ps_update(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 16LL), *(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL));
  return result;
}
