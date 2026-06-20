__int64 __fastcall wmi_unified_extract_ani_level(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 (__fastcall *v4)(__int64, __int64, __int64); // x8

  v4 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 728) + 4416LL);
  if ( !v4 )
    return 16;
  if ( *((_DWORD *)v4 - 1) != 1021338257 )
    __break(0x8228u);
  return v4(a2, a3, a4);
}
