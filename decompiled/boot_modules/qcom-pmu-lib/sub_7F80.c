__int64 __fastcall sub_7F80(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  int v8; // s17

  *(_DWORD *)(a8 + 2948) = v8;
  return qcom_pmu_idle_exit_notif();
}
