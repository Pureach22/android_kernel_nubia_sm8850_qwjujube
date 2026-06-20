__int64 __fastcall cfg80211_conn_work(__int64 a1)
{
  _QWORD *v2; // x20
  int *v3; // x23
  __int64 v4; // x8
  __int64 v5; // x8
  int *v6; // x8
  __int16 v7; // w9
  int v8; // w8
  __int64 result; // x0
  int v10; // [xsp+Ch] [xbp-264h] BYREF
  int v11; // [xsp+10h] [xbp-260h] BYREF
  __int16 v12; // [xsp+14h] [xbp-25Ch]
  _QWORD s[75]; // [xsp+18h] [xbp-258h] BYREF

  s[74] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  v11 = 0;
  mutex_lock(a1 + 688);
  v2 = *(_QWORD **)(a1 + 2024);
  if ( v2 != (_QWORD *)(a1 + 2024) )
  {
    v3 = nullptr;
    do
    {
      v4 = v2[2];
      if ( v4 )
      {
        if ( (*(_QWORD *)(v4 + 168) & 1) != 0 )
        {
          v5 = v2[8];
          if ( v5 )
          {
            if ( *(_DWORD *)(v5 + 400) != 11 )
            {
              v6 = *(int **)(v5 + 16);
              if ( v6 )
              {
                v7 = *((_WORD *)v6 + 2);
                v8 = *v6;
                v3 = &v11;
                v12 = v7;
                v11 = v8;
              }
              v10 = 0;
              if ( (unsigned int)cfg80211_conn_do_work(v2 - 2, &v10) )
              {
                memset(s, 0, 0x250u);
                s[15] = v3;
                LODWORD(s[0]) = -1;
                LODWORD(s[11]) = v10;
                _cfg80211_connect_result(v2[2], s, 0);
              }
            }
          }
        }
      }
      v2 = (_QWORD *)*v2;
    }
    while ( v2 != (_QWORD *)(a1 + 2024) );
  }
  result = mutex_unlock(a1 + 688);
  _ReadStatusReg(SP_EL0);
  return result;
}
