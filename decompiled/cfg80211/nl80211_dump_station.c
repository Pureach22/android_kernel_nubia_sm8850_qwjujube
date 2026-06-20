__int64 __fastcall nl80211_dump_station(__int64 a1, __int64 a2)
{
  unsigned int v4; // w21
  __int64 result; // x0
  __int64 v6; // x26
  __int64 v7; // x22
  __int64 v8; // x1
  _DWORD *v9; // x8
  unsigned int v10; // w0
  unsigned int v11; // w19
  __int64 v12; // [xsp+18h] [xbp-128h] BYREF
  __int64 v13; // [xsp+20h] [xbp-120h] BYREF
  int v14; // [xsp+28h] [xbp-118h] BYREF
  __int16 v15; // [xsp+2Ch] [xbp-114h]
  __int64 s[34]; // [xsp+30h] [xbp-110h] BYREF

  s[33] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x108u);
  v4 = *(_DWORD *)(a2 + 96);
  v12 = 0;
  v13 = 0;
  v15 = 0;
  v14 = 0;
  result = nl80211_prepare_wdev_dump(a2, &v13, &v12, 0);
  if ( !(_DWORD)result )
  {
    v6 = v12;
    if ( *(_QWORD *)(v12 + 32) )
    {
      v7 = v13;
      if ( *(_QWORD *)(*(_QWORD *)v13 + 168LL) )
      {
        _ReadStatusReg(SP_EL0);
        while ( 1 )
        {
          memset(s, 0, 0x108u);
          v8 = *(_QWORD *)(v6 + 32);
          v9 = *(_DWORD **)(*(_QWORD *)v7 + 168LL);
          if ( *(v9 - 1) != -555105929 )
            __break(0x8228u);
          v10 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, int *, __int64 *))v9)(v7 + 992, v8, v4, &v14, s);
          if ( v10 )
            break;
          v6 = v12;
          v7 = v13;
          if ( (nl80211_send_station(
                  a1,
                  0x13u,
                  *(_DWORD *)(*(_QWORD *)a2 + 52LL),
                  *(_DWORD *)(*(_QWORD *)(a2 + 8) + 8LL),
                  2,
                  v13,
                  *(_QWORD *)(v12 + 32),
                  (__int64)&v14,
                  s)
              & 0x80000000) != 0 )
            goto LABEL_12;
          ++v4;
        }
        if ( v10 == -2 )
        {
LABEL_12:
          *(_QWORD *)(a2 + 96) = (int)v4;
          v11 = *(_DWORD *)(a1 + 112);
          goto LABEL_15;
        }
        v11 = v10;
      }
      else
      {
        v11 = -95;
      }
    }
    else
    {
      v11 = -22;
    }
LABEL_15:
    mutex_unlock(v13 + 992);
    result = v11;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
