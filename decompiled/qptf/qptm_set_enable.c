__int64 __fastcall qptm_set_enable(__int64 a1, int a2)
{
  _QWORD *v2; // x21
  _QWORD *v3; // x22
  _QWORD *v5; // x9
  unsigned int (__fastcall *v6)(_QWORD); // x8
  _DWORD *v7; // x8
  __int64 result; // x0
  __int64 v9; // x3
  const char *v10; // x2
  unsigned int v11; // w19

  v2 = *(_QWORD **)(a1 + 1168);
  v3 = (_QWORD *)(a1 + 1168);
  if ( v2 == (_QWORD *)(a1 + 1168) )
    return 0;
  while ( 1 )
  {
    v5 = (_QWORD *)*(v2 - 5);
    v6 = (unsigned int (__fastcall *)(_QWORD))v5[1];
    if ( v6 )
    {
      if ( *v5 )
      {
        if ( *((_DWORD *)v6 - 1) != -2085565357 )
          __break(0x8228u);
        if ( ((v6(v2 - 7) ^ a2) & 1) != 0 )
          break;
      }
    }
    v2 = (_QWORD *)*v2;
    if ( v2 == v3 )
      return 0;
  }
  v7 = *(_DWORD **)*(v2 - 5);
  if ( *(v7 - 1) != 1709499886 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(_QWORD *, _QWORD))v7)(v2 - 7, a2 & 1);
  if ( (_DWORD)result )
  {
    if ( (a2 & 1) != 0 )
      v10 = "disable";
    else
      v10 = "enable";
    v11 = result;
    printk(&unk_80A1, "qptm_set_enable", v10, v9);
    return v11;
  }
  return result;
}
