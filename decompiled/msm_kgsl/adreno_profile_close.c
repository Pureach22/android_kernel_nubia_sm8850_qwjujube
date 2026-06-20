_QWORD *__fastcall adreno_profile_close(_QWORD *result)
{
  _QWORD *v1; // x19
  _QWORD *v2; // x20
  __int64 v3; // x0
  _QWORD *v4; // x19
  _QWORD *v5; // x8
  _QWORD *v6; // x21
  _QWORD *v7; // x9

  if ( (result[3003] & 1) == 0 )
  {
    v1 = result;
    v2 = result + 2462;
    v3 = result[2463];
    *((_BYTE *)v2 + 32) = 0;
    vfree(v3);
    result = (_QWORD *)v1[2460];
    v2[6] = 0;
    *((_DWORD *)v2 + 14) = 0;
    *(_DWORD *)v2 = 0;
    v1[2463] = 0;
    v1[2464] = 0;
    v1[2465] = 0;
    if ( result )
    {
      v4 = v1 + 2460;
      if ( result != v4 )
      {
        do
        {
          v6 = (_QWORD *)*result;
          v5 = (_QWORD *)result[1];
          if ( (_QWORD *)*v5 == result && (_QWORD *)v6[1] == result )
          {
            v6[1] = v5;
            *v5 = v6;
          }
          else
          {
            _list_del_entry_valid_or_report(result);
            result = v7;
          }
          *result = 0xDEAD000000000100LL;
          result[1] = 0xDEAD000000000122LL;
          kfree(result);
          result = v6;
        }
        while ( v6 != v4 );
      }
    }
  }
  return result;
}
