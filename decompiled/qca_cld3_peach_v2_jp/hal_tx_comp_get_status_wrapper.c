__int64 __fastcall hal_tx_comp_get_status_wrapper(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 (__fastcall *v5)(__int64, __int64, __int64); // x9

  v4 = *(_QWORD *)(a1 + 1128);
  v5 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v4 + 74392) + 152LL);
  if ( *((_DWORD *)v5 - 1) != -1819724828 )
    __break(0x8229u);
  return v5(a3 + 104, a4, v4);
}
