__int64 __fastcall nl80211_pmsr_send_ftm_res(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int16 v5; // w8
  __int16 v6; // w8
  __int64 v7; // x3
  __int64 v8; // x2
  __int64 v9; // x3
  __int64 v10; // x2
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a2 + 16) == 3 )
  {
    LODWORD(v11[0]) = *(_DWORD *)(a2 + 56);
    if ( !(unsigned int)nla_put(a1, 1, 4, v11) )
    {
      if ( *(_DWORD *)(a2 + 56) == 6 && *(_BYTE *)(a2 + 70) )
      {
        LODWORD(v11[0]) = *(unsigned __int8 *)(a2 + 70);
        result = nla_put(a1, 5, 4, v11);
        if ( !(_DWORD)result )
          goto LABEL_18;
        goto LABEL_17;
      }
LABEL_55:
      result = 0;
      goto LABEL_18;
    }
  }
  else
  {
    if ( (*(__int16 *)(a2 + 68) & 0x80000000) == 0 )
    {
      LODWORD(v11[0]) = *(__int16 *)(a2 + 68);
      if ( (unsigned int)nla_put(a1, 2, 4, v11) )
        goto LABEL_17;
    }
    v5 = *(_WORD *)(a2 + 160);
    if ( (v5 & 1) != 0 )
    {
      LODWORD(v11[0]) = *(_DWORD *)(a2 + 60);
      if ( (unsigned int)nla_put(a1, 3, 4, v11) )
        goto LABEL_17;
      v5 = *(_WORD *)(a2 + 160);
    }
    if ( (v5 & 2) != 0 )
    {
      LODWORD(v11[0]) = *(_DWORD *)(a2 + 64);
      if ( (unsigned int)nla_put(a1, 4, 4, v11) )
        goto LABEL_17;
    }
    LOBYTE(v11[0]) = *(_BYTE *)(a2 + 71);
    if ( (unsigned int)nla_put(a1, 6, 1, v11) )
      goto LABEL_17;
    LOBYTE(v11[0]) = *(_BYTE *)(a2 + 72);
    if ( (unsigned int)nla_put(a1, 7, 1, v11) )
      goto LABEL_17;
    LOBYTE(v11[0]) = *(_BYTE *)(a2 + 73);
    if ( (unsigned int)nla_put(a1, 8, 1, v11) )
      goto LABEL_17;
    v6 = *(_WORD *)(a2 + 160);
    if ( (v6 & 4) != 0 )
    {
      LODWORD(v11[0]) = *(_DWORD *)(a2 + 76);
      if ( (unsigned int)nla_put(a1, 9, 4, v11) )
        goto LABEL_17;
      v6 = *(_WORD *)(a2 + 160);
    }
    if ( (v6 & 8) != 0 )
    {
      LODWORD(v11[0]) = *(_DWORD *)(a2 + 80);
      if ( (unsigned int)nla_put(a1, 10, 4, v11) )
        goto LABEL_17;
      v6 = *(_WORD *)(a2 + 160);
    }
    if ( (v6 & 0x10) != 0 )
    {
      if ( (nl80211_put_sta_rate(a1, (__int16 *)(a2 + 84), 0xBu) & 1) == 0 )
        goto LABEL_17;
      v6 = *(_WORD *)(a2 + 160);
    }
    if ( (v6 & 0x20) != 0 )
    {
      if ( (nl80211_put_sta_rate(a1, (__int16 *)(a2 + 98), 0xCu) & 1) == 0 )
        goto LABEL_17;
      v6 = *(_WORD *)(a2 + 160);
    }
    if ( (v6 & 0x40) != 0 )
    {
      v11[0] = *(_QWORD *)(a2 + 112);
      if ( (unsigned int)nla_put_64bit(a1, 13, 8, v11, 21) )
        goto LABEL_17;
      v6 = *(_WORD *)(a2 + 160);
    }
    if ( (v6 & 0x80) != 0 )
    {
      v11[0] = *(_QWORD *)(a2 + 120);
      if ( (unsigned int)nla_put_64bit(a1, 14, 8, v11, 21) )
        goto LABEL_17;
      v6 = *(_WORD *)(a2 + 160);
    }
    if ( (v6 & 0x100) != 0 )
    {
      v11[0] = *(_QWORD *)(a2 + 128);
      if ( (unsigned int)nla_put_64bit(a1, 15, 8, v11, 21) )
        goto LABEL_17;
      v6 = *(_WORD *)(a2 + 160);
    }
    if ( (v6 & 0x200) != 0 )
    {
      v11[0] = *(_QWORD *)(a2 + 136);
      if ( (unsigned int)nla_put_64bit(a1, 16, 8, v11, 21) )
        goto LABEL_17;
      v6 = *(_WORD *)(a2 + 160);
    }
    if ( (v6 & 0x400) != 0 )
    {
      v11[0] = *(_QWORD *)(a2 + 144);
      if ( (unsigned int)nla_put_64bit(a1, 17, 8, v11, 21) )
        goto LABEL_17;
      v6 = *(_WORD *)(a2 + 160);
    }
    if ( (v6 & 0x800) == 0 || (v11[0] = *(_QWORD *)(a2 + 152), !(unsigned int)nla_put_64bit(a1, 18, 8, v11, 21)) )
    {
      v7 = *(_QWORD *)(a2 + 32);
      if ( !v7 || (v8 = *(unsigned int *)(a2 + 48), !(_DWORD)v8) || !(unsigned int)nla_put(a1, 19, v8, v7) )
      {
        v9 = *(_QWORD *)(a2 + 40);
        if ( !v9 )
          goto LABEL_55;
        v10 = *(unsigned int *)(a2 + 52);
        if ( !(_DWORD)v10 )
          goto LABEL_55;
        result = nla_put(a1, 20, v10, v9);
        if ( !(_DWORD)result )
          goto LABEL_18;
      }
    }
  }
LABEL_17:
  result = 4294967268LL;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
