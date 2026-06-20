__int64 __fastcall stm_data_write(__int64 a1, __int64 a2, __int64 a3, char a4, __int64 a5, __int64 a6)
{
  unsigned __int64 v6; // x19
  __int64 v8; // x4
  unsigned int v9; // w21
  unsigned int v10; // w22
  __int64 v12; // x0
  __int64 v13; // x23
  __int64 v14; // x5
  __int64 v15; // x0
  __int64 v16; // x8

  if ( !a6 )
    return 0;
  v6 = a6;
  if ( (a4 & 1) != 0 )
    v8 = 2;
  else
    v8 = 0;
  if ( (unsigned int)a6 >= 8 )
    a6 = 8;
  else
    a6 = (unsigned int)a6;
  v9 = a3;
  v10 = a2;
  v12 = (*(__int64 (__fastcall **)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64))(a1 + 40))(
          a1,
          a2,
          a3,
          0,
          v8,
          a6,
          a5);
  v13 = v12;
  if ( v12 < 1 )
  {
    v16 = 0;
  }
  else
  {
    if ( v12 >= v6 )
      return v13;
    while ( 1 )
    {
      v14 = (unsigned int)(v6 - v13) >= 8 ? 8LL : (unsigned int)(v6 - v13);
      v15 = (*(__int64 (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, __int64, __int64))(a1 + 40))(
              a1,
              v10,
              v9,
              0,
              0,
              v14,
              a5 + v13);
      if ( v15 < 1 )
        break;
      v13 += v15;
      if ( v13 >= v6 )
        return v13;
    }
    v16 = v13;
    v13 = v15;
  }
  if ( v13 >= 0 )
    return v16;
  return v13;
}
