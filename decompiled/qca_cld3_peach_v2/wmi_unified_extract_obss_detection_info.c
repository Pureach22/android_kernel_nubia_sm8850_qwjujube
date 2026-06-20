__int64 __fastcall wmi_unified_extract_obss_detection_info(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 (__fastcall *v3)(__int64, __int64); // x8

  v3 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3896LL);
  if ( !v3 )
    return 16;
  if ( *((_DWORD *)v3 - 1) != 425957044 )
    __break(0x8228u);
  return v3(a2, a3);
}
