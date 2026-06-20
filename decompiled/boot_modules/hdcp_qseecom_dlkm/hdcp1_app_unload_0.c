__int64 __fastcall hdcp1_app_unload_0(__int64 a1)
{
  __int64 result; // x0
  __int64 (*v3)(void); // x8
  _DWORD *v4; // x8
  __int64 v5; // x0
  _DWORD *v6; // x8
  __int64 v7; // x0
  _DWORD *v8; // x8
  __int64 v9; // x0
  int v10; // w8

  result = *(_QWORD *)(a1 + 8);
  if ( !result )
    return printk(&unk_C81E);
  if ( (*(_BYTE *)(a1 + 72) & 1) == 0 )
    return printk(&unk_C42D);
  v3 = *(__int64 (**)(void))a1;
  if ( *(_QWORD *)a1 )
  {
    if ( *((_DWORD *)v3 - 1) != 816020464 )
      __break(0x8228u);
    result = v3();
  }
  *(_QWORD *)a1 = 0;
  *(_QWORD *)(a1 + 8) = 0;
  v4 = *(_DWORD **)(a1 + 16);
  if ( v4 )
  {
    v5 = *(_QWORD *)(a1 + 24);
    if ( *(v4 - 1) != 816020464 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v4)(v5, 0xFFFF, 0, 0);
  }
  *(_QWORD *)(a1 + 16) = 0;
  *(_QWORD *)(a1 + 24) = 0;
  v6 = *(_DWORD **)(a1 + 32);
  if ( v6 )
  {
    v7 = *(_QWORD *)(a1 + 40);
    if ( *(v6 - 1) != 816020464 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v6)(v7, 0xFFFF, 0, 0);
  }
  *(_QWORD *)(a1 + 32) = 0;
  *(_QWORD *)(a1 + 40) = 0;
  v8 = *(_DWORD **)(a1 + 48);
  if ( v8 )
  {
    v9 = *(_QWORD *)(a1 + 56);
    if ( *(v8 - 1) != 816020464 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v8)(v9, 0xFFFF, 0, 0);
  }
  v10 = *(_DWORD *)(a1 + 72);
  *(_QWORD *)(a1 + 48) = 0;
  *(_QWORD *)(a1 + 56) = 0;
  *(_DWORD *)(a1 + 72) = v10 & 0xFFFFFFFE;
  return result;
}
