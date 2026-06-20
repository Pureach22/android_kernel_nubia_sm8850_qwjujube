__int64 __fastcall hdcp1_stop_smcinvoke(__int64 result)
{
  __int64 v1; // x19
  _DWORD *v2; // x8
  __int64 v3; // x0
  _DWORD *v4; // x8
  __int64 v5; // x0
  _DWORD *v6; // x8
  __int64 v7; // x0
  _DWORD *v8; // x8
  __int64 v9; // x0
  int v10; // w8

  if ( !result )
    return printk(&unk_C470);
  v1 = result;
  if ( (*(_BYTE *)(result + 72) & 1) == 0 )
    return printk(&unk_C57F);
  v2 = *(_DWORD **)result;
  if ( *(_QWORD *)result )
  {
    v3 = *(_QWORD *)(result + 8);
    if ( *(v2 - 1) != 816020464 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v2)(v3, 0xFFFF, 0, 0);
  }
  *(_QWORD *)v1 = 0;
  *(_QWORD *)(v1 + 8) = 0;
  v4 = *(_DWORD **)(v1 + 16);
  if ( v4 )
  {
    v5 = *(_QWORD *)(v1 + 24);
    if ( *(v4 - 1) != 816020464 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v4)(v5, 0xFFFF, 0, 0);
  }
  *(_QWORD *)(v1 + 16) = 0;
  *(_QWORD *)(v1 + 24) = 0;
  v6 = *(_DWORD **)(v1 + 32);
  if ( v6 )
  {
    v7 = *(_QWORD *)(v1 + 40);
    if ( *(v6 - 1) != 816020464 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v6)(v7, 0xFFFF, 0, 0);
  }
  *(_QWORD *)(v1 + 32) = 0;
  *(_QWORD *)(v1 + 40) = 0;
  v8 = *(_DWORD **)(v1 + 48);
  if ( v8 )
  {
    v9 = *(_QWORD *)(v1 + 56);
    if ( *(v8 - 1) != 816020464 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v8)(v9, 0xFFFF, 0, 0);
  }
  v10 = *(_DWORD *)(v1 + 72);
  *(_QWORD *)(v1 + 48) = 0;
  *(_QWORD *)(v1 + 56) = 0;
  *(_DWORD *)(v1 + 72) = v10 & 0xFFFFFFFE;
  return result;
}
