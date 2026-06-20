__int64 __fastcall qti_qpt_set_enable(__int64 a1, char a2)
{
  __int64 v2; // x19
  char v3; // w20
  __int64 result; // x0

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 120) + 16LL);
  if ( *(_BYTE *)(v2 + 85) == (a2 & 1) )
    return 0;
  if ( (a2 & 1) == 0 )
    return qti_qpt_start_stop_telemetry(v2, a2 & 1);
  v3 = a2;
  result = qti_qpt_sync_common_telemetry_config(*(_QWORD **)(*(_QWORD *)(a1 + 120) + 16LL));
  a2 = v3;
  if ( !(_DWORD)result )
    return qti_qpt_start_stop_telemetry(v2, a2 & 1);
  return result;
}
