__int64 __fastcall wlan_dp_get_tsf_time(__int64 a1)
{
  _QWORD *v1; // x8
  __int64 v2; // x0
  void (__fastcall *v3)(_QWORD); // x9

  v1 = *(_QWORD **)(a1 + 32);
  v2 = v1[7];
  v3 = *(void (__fastcall **)(_QWORD))(*v1 + 408LL);
  if ( *((_DWORD *)v3 - 1) != -239780719 )
    __break(0x8229u);
  v3(v2);
  return 0;
}
