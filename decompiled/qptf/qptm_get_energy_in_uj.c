__int64 __fastcall qptm_get_energy_in_uj(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x21
  _QWORD *v5; // x21
  __int64 v6; // x23
  __int64 v7; // x8
  __int64 (__fastcall *v8)(_QWORD); // x8

  if ( !a1 )
    return 4294967277LL;
  v3 = *(_QWORD *)(a1 + 1112);
  mutex_lock(a1 + 1200);
  if ( v3 )
  {
    v5 = *(_QWORD **)(a1 + 1168);
    if ( v5 == (_QWORD *)(a1 + 1168) )
    {
      v6 = 0;
    }
    else
    {
      v6 = 0;
      do
      {
        v7 = *(v5 - 5);
        if ( v7 )
        {
          v8 = *(__int64 (__fastcall **)(_QWORD))(v7 + 16);
          if ( v8 )
          {
            if ( *((_DWORD *)v8 - 1) != 34599772 )
              __break(0x8228u);
            v6 += v8(v5 - 7);
          }
        }
        v5 = (_QWORD *)*v5;
      }
      while ( v5 != (_QWORD *)(a1 + 1168) );
    }
    *a2 = v6;
  }
  else
  {
    _get_energy_uj(a1, a2);
  }
  mutex_unlock(a1 + 1200);
  return 0;
}
