__int64 __fastcall nl80211_parse_fils_discovery(__int64 a1, _WORD *a2, __int64 a3)
{
  __int64 result; // x0
  int v4; // w8
  __int64 v6; // x8
  __int64 v7; // x9
  __int16 v8; // t1
  int v9; // w8
  __int64 v10; // [xsp+8h] [xbp-28h] BYREF
  __int64 v11; // [xsp+10h] [xbp-20h]
  __int64 v12; // [xsp+18h] [xbp-18h]
  __int16 *v13; // [xsp+20h] [xbp-10h]
  __int64 v14; // [xsp+28h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a1 + 1110) & 0x10) != 0 )
  {
    v4 = (__int16)a2[1];
    v12 = 0;
    v13 = nullptr;
    v10 = 0;
    v11 = 0;
    if ( v4 < 0 )
    {
      result = _nla_parse(&v10, 3, a2 + 2, (unsigned __int16)(*a2 - 4), 0, 31, 0);
      if ( !(_DWORD)result )
      {
        v7 = v11;
        v6 = v12;
        if ( v11 || v12 || v13 )
        {
          result = 4294967274LL;
          if ( v11 && v12 && v13 )
          {
            v8 = *v13;
            *(_QWORD *)(a3 + 24) = v13 + 2;
            result = 0;
            *(_QWORD *)(a3 + 16) = (unsigned __int16)(v8 - 4);
            *(_DWORD *)(a3 + 4) = *(_DWORD *)(v7 + 4);
            v9 = *(_DWORD *)(v6 + 4);
            *(_BYTE *)a3 = 1;
            *(_DWORD *)(a3 + 8) = v9;
          }
        }
        else
        {
          result = 0;
          *(_BYTE *)a3 = 1;
        }
      }
    }
    else
    {
      do_trace_netlink_extack("NLA_F_NESTED is missing");
      result = 4294967274LL;
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
