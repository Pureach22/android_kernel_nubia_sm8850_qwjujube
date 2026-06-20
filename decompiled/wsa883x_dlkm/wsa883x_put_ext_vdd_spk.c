__int64 __fastcall wsa883x_put_ext_vdd_spk(__int64 a1, __int64 a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 128);
  *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(v2 + 24) + 152LL) + 34LL) = *(_DWORD *)(a2 + 72) != 0;
  return 0;
}
