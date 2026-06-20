__int64 __fastcall wmi_unified_wow_patterns_to_fw_cmd(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v2)(__int64, __int64); // x8

  v2 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 1160LL);
  if ( !v2 )
    return 16;
  if ( *((_DWORD *)v2 - 1) != 1650487948 )
    __break(0x8228u);
  return v2(a1, a2);
}
