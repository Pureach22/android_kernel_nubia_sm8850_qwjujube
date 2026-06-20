__int64 __fastcall sub_61C8D4(__int64 *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  _QWORD *v9; // x0

  _T1 = *a1;
  v9 = a1 + 21;
  __asm { STGP            X19, X26, [X0],#0xA8 }
  return wlan_connectivity_disconnect_event(v9, a2, a3, a4, a5);
}
