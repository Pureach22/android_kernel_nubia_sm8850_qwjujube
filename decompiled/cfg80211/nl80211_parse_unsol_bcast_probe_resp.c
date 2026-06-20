__int64 __fastcall nl80211_parse_unsol_bcast_probe_resp(__int64 a1, _WORD *a2, __int64 a3)
{
  __int64 result; // x0
  int v4; // w8
  __int128 v6; // kr00_16
  int v7; // w8
  __int64 v8; // [xsp+0h] [xbp-20h] BYREF
  __int128 v9; // [xsp+8h] [xbp-18h]
  __int64 v10; // [xsp+18h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a1 + 1110) & 0x20) != 0 )
  {
    v4 = (__int16)a2[1];
    v9 = 0u;
    v8 = 0;
    if ( v4 < 0 )
    {
      result = _nla_parse(&v8, 2, a2 + 2, (unsigned __int16)(*a2 - 4), 0, 31, 0);
      if ( !(_DWORD)result )
      {
        v6 = v9;
        if ( v9 == 0 )
        {
          result = 0;
          *(_BYTE *)a3 = 1;
        }
        else
        {
          result = 4294967274LL;
          if ( (_QWORD)v9 && *((_QWORD *)&v9 + 1) )
          {
            result = 0;
            *(_QWORD *)(a3 + 16) = *((_QWORD *)&v9 + 1) + 4LL;
            *(_QWORD *)(a3 + 8) = (unsigned __int16)(**((_WORD **)&v6 + 1) - 4);
            v7 = *(_DWORD *)(v6 + 4);
            *(_BYTE *)a3 = 1;
            *(_DWORD *)(a3 + 4) = v7;
          }
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
