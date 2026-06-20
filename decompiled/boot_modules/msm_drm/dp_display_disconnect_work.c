__int64 __fastcall dp_display_disconnect_work(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  _QWORD *v8; // x21
  __int64 v10; // x20
  void (*v11)(void); // x8
  _BYTE *v12; // x0
  __int64 (*v13)(void); // x8

  v8 = (_QWORD *)(a1 - 1504);
  v10 = a1 - 1696;
  if ( **(_BYTE **)(a1 - 1504) == 1 && (*(_BYTE *)(a1 - 1683) & 1) != 0 )
  {
    v11 = *(void (**)(void))(*(_QWORD *)(a1 - 1552) + 72LL);
    if ( *((_DWORD *)v11 - 1) != 139933102 )
      __break(0x8228u);
    v11();
  }
  dp_display_handle_disconnect(v10, a2, a3, a4, a5, a6, a7, a8);
  v12 = (_BYTE *)*v8;
  if ( *(_BYTE *)*v8 == 1 && (*(_BYTE *)(a1 - 1683) & 1) != 0 )
  {
    dp_display_host_deinit(v10);
    v12 = (_BYTE *)*v8;
  }
  v13 = *((__int64 (**)(void))v12 + 21);
  if ( *((_DWORD *)v13 - 1) != -112381402 )
    __break(0x8228u);
  return v13();
}
