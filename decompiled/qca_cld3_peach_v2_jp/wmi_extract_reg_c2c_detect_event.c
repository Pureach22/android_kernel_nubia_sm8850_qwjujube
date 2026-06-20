__int64 __fastcall wmi_extract_reg_c2c_detect_event(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 (__fastcall *v3)(__int64, __int64); // x8

  if ( !a1 )
    return 16;
  v3 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3576LL);
  if ( !v3 )
    return 16;
  if ( *((_DWORD *)v3 - 1) != 509422213 )
    __break(0x8228u);
  return v3(a2, a3);
}
