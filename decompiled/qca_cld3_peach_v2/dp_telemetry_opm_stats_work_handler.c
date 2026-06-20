__int64 __fastcall dp_telemetry_opm_stats_work_handler(__int64 result)
{
  __int64 *v1; // x9
  __int64 (__fastcall *v2)(__int64, __int64); // x8
  __int64 v3; // x0
  __int64 v4; // x1

  if ( result )
  {
    v1 = *(__int64 **)result;
    v2 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)result + 832LL);
    if ( v2 )
    {
      v3 = *v1;
      v4 = *(unsigned __int8 *)(v1[1] + 40);
      if ( *((_DWORD *)v2 - 1) != -132374536 )
        __break(0x8228u);
      return v2(v3, v4);
    }
  }
  return result;
}
