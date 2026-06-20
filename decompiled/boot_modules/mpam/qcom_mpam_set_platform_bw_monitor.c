__int64 __fastcall qcom_mpam_set_platform_bw_monitor(__int64 a1)
{
  __int64 (__fastcall *v2)(__int64, __int64, __int64, __int64, __int64); // x8
  __int64 v3; // x0

  if ( !ops )
    return 0xFFFFFFFFLL;
  v2 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64, __int64))ops;
  v3 = ph;
  if ( *(_DWORD *)(*(_QWORD *)ops - 4LL) != 1737159351 )
    __break(0x8228u);
  return v2(v3, a1, 0x4D50414D4558544ELL, 5, 24);
}
