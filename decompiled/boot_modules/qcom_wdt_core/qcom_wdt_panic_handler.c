__int64 __fastcall qcom_wdt_panic_handler(__int64 a1)
{
  __int64 v1; // x20
  int v2; // w21
  __int64 v3; // x8
  void (__fastcall *v4)(_QWORD); // x8
  __int64 v6; // x0
  unsigned int v7; // w21
  _DWORD *v8; // x8
  _DWORD *v9; // x8
  void (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x0

  v1 = a1 - 112;
  *(_BYTE *)(a1 - 75) = 1;
  v2 = panic_timeout;
  v3 = *(_QWORD *)(a1 - 96);
  if ( panic_timeout )
  {
    v4 = *(void (__fastcall **)(_QWORD))(v3 + 16);
    v6 = a1 - 112;
    if ( *((_DWORD *)v4 - 1) != 2060914831 )
      __break(0x8228u);
    v4(v6);
    v7 = 1000 * v2 + 10000;
    v8 = **(_DWORD ***)(a1 - 96);
    if ( *(v8 - 1) != -872624411 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD, __int64))v8)(v7, v1);
    v9 = *(_DWORD **)(*(_QWORD *)(a1 - 96) + 8LL);
    if ( *(v9 - 1) != -872624411 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD, __int64))v9)(v7, v1);
  }
  else
  {
    v10 = *(void (__fastcall **)(_QWORD))(v3 + 32);
    v11 = a1 - 112;
    if ( *((_DWORD *)v10 - 1) != 2060914831 )
      __break(0x8228u);
    v10(v11);
  }
  return 0;
}
