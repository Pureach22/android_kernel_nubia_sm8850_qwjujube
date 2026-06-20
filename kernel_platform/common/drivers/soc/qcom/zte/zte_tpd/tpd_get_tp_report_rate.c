__int64 __fastcall tpd_get_tp_report_rate(__int64 a1)
{
  __int64 v1; // x9

  v1 = *(_QWORD *)(a1 + 3072);
  *(_DWORD *)(a1 + 1124) = *(_DWORD *)(v1 + 1528);
  return 0;
}
