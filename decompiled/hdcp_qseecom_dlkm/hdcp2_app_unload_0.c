__int64 __fastcall hdcp2_app_unload_0(__int64 a1)
{
  __int64 v3; // x0
  _DWORD *v4; // x8
  __int64 v5; // x21
  unsigned int v6; // w20
  _DWORD *v7; // x8
  __int64 v8; // x0
  _DWORD *v9; // x8
  __int64 v10; // x0
  _DWORD *v11; // x8
  __int64 v12; // x0
  _DWORD *v13; // x8
  __int64 v14; // x0
  int v15; // w8

  v4 = *(_DWORD **)(a1 + 56);
  v3 = *(_QWORD *)(a1 + 64);
  v5 = a1 + 56;
  if ( *(v4 - 1) != 816020464 )
    __break(0x8228u);
  v6 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v4)(v3, 9, 0, 0);
  if ( v6 )
  {
    printk(&unk_C71E);
  }
  else
  {
    v7 = *(_DWORD **)v5;
    if ( *(_QWORD *)v5 )
    {
      v8 = *(_QWORD *)(a1 + 64);
      if ( *(v7 - 1) != 816020464 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v7)(v8, 0xFFFF, 0, 0);
    }
    *(_QWORD *)v5 = 0;
    *(_QWORD *)(v5 + 8) = 0;
    v9 = *(_DWORD **)(a1 + 72);
    if ( v9 )
    {
      v10 = *(_QWORD *)(a1 + 80);
      if ( *(v9 - 1) != 816020464 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v9)(v10, 0xFFFF, 0, 0);
    }
    *(_QWORD *)(a1 + 72) = 0;
    *(_QWORD *)(a1 + 80) = 0;
    v11 = *(_DWORD **)(a1 + 88);
    if ( v11 )
    {
      v12 = *(_QWORD *)(a1 + 96);
      if ( *(v11 - 1) != 816020464 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v11)(v12, 0xFFFF, 0, 0);
    }
    *(_QWORD *)(a1 + 88) = 0;
    *(_QWORD *)(a1 + 96) = 0;
    v13 = *(_DWORD **)(a1 + 104);
    if ( v13 )
    {
      v14 = *(_QWORD *)(a1 + 112);
      if ( *(v13 - 1) != 816020464 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v13)(v14, 0xFFFF, 0, 0);
    }
    v15 = *(_DWORD *)(a1 + 48);
    *(_QWORD *)(a1 + 104) = 0;
    *(_QWORD *)(a1 + 112) = 0;
    *(_DWORD *)(a1 + 48) = v15 & 0xFFFFFFFE;
  }
  return v6;
}
