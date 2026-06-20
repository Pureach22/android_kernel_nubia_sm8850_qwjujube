_QWORD *__fastcall adreno_profile_submit_time(_QWORD *result)
{
  __int64 v1; // x20
  _QWORD *v2; // x19
  unsigned __int64 v3; // x21
  unsigned __int64 v4; // x8
  __int64 v5; // x8
  void (__fastcall *v6)(_QWORD); // x8
  _QWORD *v7; // x22
  __int64 v8; // x8
  unsigned __int64 *v9; // x8
  unsigned __int64 v10; // x9
  unsigned __int64 v11; // x9
  unsigned __int64 v12; // x10
  __int64 v13; // x8
  __int64 (__fastcall *v14)(_QWORD); // x8

  if ( result )
  {
    v1 = result[4];
    if ( v1 )
    {
      v2 = *(_QWORD **)(v1 + 128);
      if ( v2 )
      {
        v3 = *(_QWORD *)(v1 + 136);
        v4 = v2[4];
        if ( v4 <= v3 && v2[6] + v4 > v3 )
        {
          v5 = v2[9];
          if ( v5 )
          {
            v6 = *(void (__fastcall **)(_QWORD))(v5 + 24);
            if ( v6 )
            {
              v7 = result;
              if ( *((_DWORD *)v6 - 1) != -441828660 )
                __break(0x8228u);
              v6(v2 + 1);
              result = v7;
            }
          }
          v8 = v2[2];
          if ( v8 )
          {
            v9 = (unsigned __int64 *)(v8 + v3 - v2[4]);
            if ( v9 )
            {
              if ( (*(_BYTE *)(v1 + 24) & 0x20) != 0 )
              {
                v11 = result[1];
                v12 = v11 / 0x3B9ACA00;
                v10 = v11 % 0x3B9ACA00;
                *v9 = v12;
              }
              else
              {
                *v9 = result[2];
                v10 = result[3];
              }
              v9[1] = v10;
              v9[2] = *result;
              v13 = v2[9];
              if ( v13 )
              {
                v14 = *(__int64 (__fastcall **)(_QWORD))(v13 + 32);
                if ( v14 )
                {
                  if ( *((_DWORD *)v14 - 1) != 1555154090 )
                    __break(0x8228u);
                  return (_QWORD *)v14(v2 + 1);
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}
