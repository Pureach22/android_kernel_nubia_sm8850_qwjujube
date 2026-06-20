__int64 __fastcall nl80211_send_chandef(__int64 a1, __int64 a2)
{
  unsigned int v4; // w8
  __int64 result; // x0
  unsigned int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (cfg80211_chandef_valid((__int64 *)a2) & 1) == 0 )
  {
    __break(0x800u);
    result = 4294967274LL;
    goto LABEL_14;
  }
  v6 = *(_DWORD *)(*(_QWORD *)a2 + 4LL);
  if ( (unsigned int)nla_put(a1, 38, 4, &v6) )
    goto LABEL_13;
  v6 = *(unsigned __int16 *)(*(_QWORD *)a2 + 8LL);
  if ( (unsigned int)nla_put(a1, 290, 4, &v6) )
    goto LABEL_13;
  v4 = *(_DWORD *)(a2 + 8);
  if ( v4 <= 2 )
  {
    if ( v4 == 2 )
    {
      if ( *(_DWORD *)(a2 + 12) <= *(_DWORD *)(*(_QWORD *)a2 + 4LL) )
        v4 = 2;
      else
        v4 = 3;
    }
    v6 = v4;
    if ( (unsigned int)nla_put(a1, 39, 4, &v6) )
      goto LABEL_13;
    v4 = *(_DWORD *)(a2 + 8);
  }
  v6 = v4;
  if ( !(unsigned int)nla_put(a1, 159, 4, &v6) )
  {
    v6 = *(_DWORD *)(a2 + 12);
    if ( !(unsigned int)nla_put(a1, 160, 4, &v6) )
    {
      if ( !*(_DWORD *)(a2 + 16) || (v6 = *(_DWORD *)(a2 + 16), !(unsigned int)nla_put(a1, 161, 4, &v6)) )
      {
        if ( !*(_WORD *)(a2 + 30) || (v6 = *(unsigned __int16 *)(a2 + 30), !(unsigned int)nla_put(a1, 322, 4, &v6)) )
        {
          result = 0;
          goto LABEL_14;
        }
      }
    }
  }
LABEL_13:
  result = 4294967191LL;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
