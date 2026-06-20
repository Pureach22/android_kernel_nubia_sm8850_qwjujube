__int64 __fastcall tmc_etr_buf_get_data(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 (__fastcall *v3)(__int64, __int64, unsigned __int64); // x9

  v3 = *(__int64 (__fastcall **)(__int64, __int64, unsigned __int64))(*(_QWORD *)(a1 + 48) + 16LL);
  if ( *(_QWORD *)(a1 + 16) - a2 < a3 )
    a3 = *(_QWORD *)(a1 + 16) - a2;
  if ( *((_DWORD *)v3 - 1) != -256312645 )
    __break(0x8229u);
  return v3(a1, a2, a3);
}
