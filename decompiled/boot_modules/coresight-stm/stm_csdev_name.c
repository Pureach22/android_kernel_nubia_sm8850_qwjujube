const char *__fastcall stm_csdev_name(__int64 a1)
{
  __int64 v1; // x8
  int v2; // w19
  __int64 v3; // x8
  int v4; // w20
  __int64 v5; // x8
  int v6; // w21
  _DWORD *v7; // x8
  int v8; // w8
  _QWORD *v9; // x8
  __int64 v11; // x20
  __int64 v12; // x21
  __int64 v13; // x22

  v1 = *(_QWORD *)(a1 + 40);
  if ( *(_BYTE *)(a1 + 32) == 1 )
  {
    v2 = *(_DWORD *)(v1 + 4064);
  }
  else
  {
    v11 = a1;
    if ( *(_DWORD *)(v1 - 4) != -340433967 )
      __break(0x8228u);
    v2 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v1)(4064, 1, 0);
    a1 = v11;
  }
  v3 = *(_QWORD *)(a1 + 40);
  if ( (*(_BYTE *)(a1 + 32) & 1) != 0 )
  {
    v4 = *(_DWORD *)(v3 + 4068);
  }
  else
  {
    v12 = a1;
    if ( *(_DWORD *)(v3 - 4) != -340433967 )
      __break(0x8228u);
    v4 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v3)(4068, 1, 0);
    a1 = v12;
  }
  v5 = *(_QWORD *)(a1 + 40);
  if ( (*(_BYTE *)(a1 + 32) & 1) != 0 )
  {
    v6 = *(_DWORD *)(v5 + 4072);
  }
  else
  {
    v13 = a1;
    if ( *(_DWORD *)(v5 - 4) != -340433967 )
      __break(0x8228u);
    v6 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v5)(4072, 1, 0);
    a1 = v13;
  }
  v7 = *(_DWORD **)(a1 + 40);
  if ( (*(_BYTE *)(a1 + 32) & 1) == 0 )
  {
    if ( *(v7 - 1) != -340433967 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, _QWORD))v7)(4076, 1, 0);
  }
  v8 = (v2 | (v4 << 8) | (v6 << 16)) & 0xFFFFF;
  if ( v8 == 768354 )
  {
    v9 = &compoundliteral;
    if ( !&compoundliteral )
      goto LABEL_15;
    goto LABEL_13;
  }
  if ( v8 != 768355 )
  {
    v9 = nullptr;
    goto LABEL_15;
  }
  v9 = &compoundliteral_2;
  if ( &compoundliteral_2 )
LABEL_13:
    v9 = (_QWORD *)v9[2];
LABEL_15:
  if ( v9 )
    return (const char *)v9;
  else
    return "STM";
}
