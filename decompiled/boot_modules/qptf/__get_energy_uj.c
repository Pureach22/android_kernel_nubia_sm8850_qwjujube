__int64 __fastcall _get_energy_uj(__int64 result, __int64 *a2)
{
  __int64 v3; // x8
  __int64 (*v4)(void); // x8
  _QWORD *v5; // x21
  _QWORD *v6; // x20
  _QWORD v7[2]; // [xsp+0h] [xbp-10h] BYREF

  v7[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(result + 1112);
  if ( v3 )
  {
    v4 = *(__int64 (**)(void))(v3 + 24);
    if ( *((_DWORD *)v4 - 1) != 1558388383 )
      __break(0x8228u);
    result = v4();
    *a2 = result;
  }
  else
  {
    *a2 = 0;
    v5 = (_QWORD *)(result + 1096);
    v6 = *(_QWORD **)(result + 1096);
    if ( v6 != (_QWORD *)(result + 1096) )
    {
      v7[0] = 0;
      do
      {
        result = _get_energy_uj(v6 - 135, v7);
        *a2 += v7[0];
        v6 = (_QWORD *)*v6;
      }
      while ( v6 != v5 );
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
