__int64 __fastcall reboot_mode_notify(__int64 a1, __int64 a2, const char *a3)
{
  _QWORD *v3; // x22
  __int64 v5; // x20
  const char *v6; // x21
  _QWORD *v7; // x23
  void (__fastcall *v8)(_QWORD); // x8

  v3 = (_QWORD *)(a1 - 24);
  v5 = a1 - 32;
  if ( a3 )
    v6 = a3;
  else
    v6 = "normal";
  v7 = (_QWORD *)(a1 - 24);
  while ( 1 )
  {
    v7 = (_QWORD *)*v7;
    if ( v7 == v3 )
      break;
    if ( !strcmp((const char *)*(v7 - 2), v6) )
    {
      if ( *((_DWORD *)v7 - 2) )
      {
        v8 = *(void (__fastcall **)(_QWORD))(a1 - 8);
        if ( *((_DWORD *)v8 - 1) != -726670107 )
          __break(0x8228u);
        v8(v5);
      }
      return 0;
    }
  }
  return 0;
}
