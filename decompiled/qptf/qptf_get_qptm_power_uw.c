__int64 __fastcall qptf_get_qptm_power_uw(__int64 a1)
{
  _QWORD *v1; // x20
  _QWORD *v2; // x21
  __int64 v3; // x19
  __int64 v4; // x8
  __int64 (__fastcall *v5)(_QWORD); // x8

  v1 = *(_QWORD **)(a1 + 1168);
  v2 = (_QWORD *)(a1 + 1168);
  if ( v1 == (_QWORD *)(a1 + 1168) )
    return 0;
  v3 = 0;
  do
  {
    v4 = *(v1 - 5);
    if ( v4 )
    {
      v5 = *(__int64 (__fastcall **)(_QWORD))(v4 + 32);
      if ( v5 )
      {
        if ( *((_DWORD *)v5 - 1) != 34599772 )
          __break(0x8228u);
        v3 += v5(v1 - 7);
      }
    }
    v1 = (_QWORD *)*v1;
  }
  while ( v1 != v2 );
  return v3;
}
