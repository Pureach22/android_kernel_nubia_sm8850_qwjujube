__int64 __fastcall sub_69C058(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v7; // x2

  _T1 = *(_QWORD *)(a3 + 100);
  v7 = a3 + 100;
  __asm { STGP            X18, X7, [X2,#0x64]! }
  return os_if_dp_send_flow_status_event(a1, a2, v7);
}
