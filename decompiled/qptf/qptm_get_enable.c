__int64 __fastcall qptm_get_enable(__int64 a1, char *a2)
{
  _QWORD *v2; // x20
  _QWORD *v3; // x21
  char v5; // w8
  __int64 (__fastcall *v6)(_QWORD); // x8

  v2 = *(_QWORD **)(a1 + 1168);
  v3 = (_QWORD *)(a1 + 1168);
  if ( v2 == (_QWORD *)(a1 + 1168) )
  {
LABEL_2:
    v5 = 1;
  }
  else
  {
    while ( 1 )
    {
      v6 = *(__int64 (__fastcall **)(_QWORD))(*(v2 - 5) + 8LL);
      if ( v6 )
      {
        if ( *((_DWORD *)v6 - 1) != -2085565357 )
          __break(0x8228u);
        if ( (v6(v2 - 7) & 1) == 0 )
          break;
      }
      v2 = (_QWORD *)*v2;
      if ( v2 == v3 )
        goto LABEL_2;
    }
    v5 = 0;
  }
  *a2 = v5;
  return 0;
}
