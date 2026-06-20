__int64 __fastcall dp_bridge_hpd_register(__int64 a1)
{
  __int64 v1; // x2
  __int64 (__fastcall *v2)(__int64, __int64 (__fastcall *)(), __int64); // x9
  __int64 v3; // x0

  if ( !a1 )
    return 4294967274LL;
  v1 = a1 - 8;
  v2 = *(__int64 (__fastcall **)(__int64, __int64 (__fastcall *)(), __int64))(*(_QWORD *)(a1 + 72) + 48LL);
  v3 = *(_QWORD *)(a1 + 72);
  if ( *((_DWORD *)v2 - 1) != 461496586 )
    __break(0x8229u);
  return v2(v3, dp_bridge_hpd_cb, v1);
}
