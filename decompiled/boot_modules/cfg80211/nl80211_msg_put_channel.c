__int64 __fastcall nl80211_msg_put_channel(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  __int64 result; // x0
  int v9; // w8
  int v10; // w22
  int v11; // w8
  unsigned __int64 v12; // x0
  int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a4 & 1) == 0 && ((*(_BYTE *)(a3 + 13) & 0x18) != 0 || *(_WORD *)(a3 + 8)) )
    goto LABEL_7;
  v13 = *(_DWORD *)(a3 + 4);
  if ( (unsigned int)nla_put(a1, 1, 4, &v13) )
    goto LABEL_4;
  v13 = *(unsigned __int16 *)(a3 + 8);
  if ( (unsigned int)nla_put(a1, 20, 4, &v13) )
    goto LABEL_4;
  v9 = *(_DWORD *)(a3 + 12);
  if ( (v9 & 4) != 0 )
  {
    LOBYTE(v13) = *(_BYTE *)(a3 + 60);
    if ( (unsigned int)nla_put(a1, 28, 1, &v13) )
      goto LABEL_4;
    v9 = *(_DWORD *)(a3 + 12);
  }
  if ( (v9 & 1) != 0 )
  {
    if ( (unsigned int)nla_put(a1, 2, 0, 0) )
      goto LABEL_4;
    v9 = *(_DWORD *)(a3 + 12);
  }
  if ( (v9 & 2) != 0 )
  {
    if ( (unsigned int)nla_put(a1, 3, 0, 0) || (unsigned int)nla_put(a1, 4, 0, 0) )
      goto LABEL_4;
    v9 = *(_DWORD *)(a3 + 12);
    if ( (v9 & 8) == 0 )
    {
LABEL_17:
      if ( (a4 & 1) != 0 )
      {
        if ( (v9 & 0x20) != 0 )
        {
LABEL_19:
          if ( (unsigned int)nla_put(a1, 9, 0, 0) )
            goto LABEL_4;
          v9 = *(_DWORD *)(a3 + 12);
        }
LABEL_21:
        if ( (v9 & 0x10) != 0 )
        {
          if ( (unsigned int)nla_put(a1, 10, 0, 0) )
            goto LABEL_4;
          v9 = *(_DWORD *)(a3 + 12);
        }
        if ( (v9 & 0x80) != 0 )
        {
          if ( (unsigned int)nla_put(a1, 11, 0, 0) )
            goto LABEL_4;
          v9 = *(_DWORD *)(a3 + 12);
        }
        if ( (v9 & 0x100) != 0 )
        {
          if ( (unsigned int)nla_put(a1, 12, 0, 0) )
            goto LABEL_4;
          v9 = *(_DWORD *)(a3 + 12);
        }
        if ( (v9 & 0x200) != 0 )
        {
          if ( (unsigned int)nla_put(a1, 14, 0, 0) )
            goto LABEL_4;
          v9 = *(_DWORD *)(a3 + 12);
        }
        if ( (v9 & 0x400) != 0 )
        {
          if ( (unsigned int)nla_put(a1, 15, 0, 0) )
            goto LABEL_4;
          v9 = *(_DWORD *)(a3 + 12);
        }
        if ( (v9 & 0x800) != 0 )
        {
          if ( (unsigned int)nla_put(a1, 16, 0, 0) )
            goto LABEL_4;
          v9 = *(_DWORD *)(a3 + 12);
        }
        if ( (v9 & 0x1000) != 0 )
        {
          if ( (unsigned int)nla_put(a1, 17, 0, 0) )
            goto LABEL_4;
          v9 = *(_DWORD *)(a3 + 12);
        }
        if ( (v9 & 0x2000) != 0 )
        {
          if ( (unsigned int)nla_put(a1, 19, 0, 0) )
            goto LABEL_4;
          v9 = *(_DWORD *)(a3 + 12);
        }
        if ( (v9 & 0x4000) != 0 )
        {
          if ( (unsigned int)nla_put(a1, 21, 0, 0) )
            goto LABEL_4;
          v9 = *(_DWORD *)(a3 + 12);
        }
        if ( (v9 & 0x8000) != 0 )
        {
          if ( (unsigned int)nla_put(a1, 22, 0, 0) )
            goto LABEL_4;
          v9 = *(_DWORD *)(a3 + 12);
        }
        if ( (v9 & 0x10000) != 0 )
        {
          if ( (unsigned int)nla_put(a1, 23, 0, 0) )
            goto LABEL_4;
          v9 = *(_DWORD *)(a3 + 12);
        }
        if ( (v9 & 0x20000) != 0 )
        {
          if ( (unsigned int)nla_put(a1, 24, 0, 0) )
            goto LABEL_4;
          v9 = *(_DWORD *)(a3 + 12);
        }
        if ( (v9 & 0x40000) != 0 )
        {
          if ( (unsigned int)nla_put(a1, 25, 0, 0) )
            goto LABEL_4;
          v9 = *(_DWORD *)(a3 + 12);
        }
        if ( (v9 & 0x80000) != 0 )
        {
          if ( (unsigned int)nla_put(a1, 26, 0, 0) )
            goto LABEL_4;
          v9 = *(_DWORD *)(a3 + 12);
        }
        if ( (v9 & 0x100000) != 0 )
        {
          if ( (unsigned int)nla_put(a1, 27, 0, 0) )
            goto LABEL_4;
          v9 = *(_DWORD *)(a3 + 12);
        }
        if ( (v9 & 0x200000) != 0 )
        {
          if ( (unsigned int)nla_put(a1, 29, 0, 0) )
            goto LABEL_4;
          v9 = *(_DWORD *)(a3 + 12);
        }
        if ( (v9 & 0x400000) != 0 )
        {
          if ( (unsigned int)nla_put(a1, 30, 0, 0) )
            goto LABEL_4;
          v9 = *(_DWORD *)(a3 + 12);
        }
        if ( (v9 & 0x800000) != 0 )
        {
          if ( (unsigned int)nla_put(a1, 31, 0, 0) )
            goto LABEL_4;
          v9 = *(_DWORD *)(a3 + 12);
        }
        if ( (v9 & 0x1000000) != 0 )
        {
          if ( (unsigned int)nla_put(a1, 32, 0, 0) )
            goto LABEL_4;
          v9 = *(_DWORD *)(a3 + 12);
        }
        if ( (v9 & 0x2000000) == 0 || !(unsigned int)nla_put(a1, 33, 0, 0) )
          goto LABEL_91;
LABEL_4:
        result = 4294967191LL;
        goto LABEL_8;
      }
      goto LABEL_91;
    }
  }
  else if ( (v9 & 8) == 0 )
  {
    goto LABEL_17;
  }
  if ( (unsigned int)nla_put(a1, 5, 0, 0) )
    goto LABEL_4;
  if ( (a4 & 1) != 0 )
  {
    v10 = jiffies_to_msecs(jiffies - *(_QWORD *)(a3 + 48));
    v13 = *(_DWORD *)(a3 + 44);
    if ( (unsigned int)nla_put(a1, 7, 4, &v13) )
      goto LABEL_4;
    v13 = v10;
    if ( (unsigned int)nla_put(a1, 8, 4, &v13) )
      goto LABEL_4;
    v13 = *(_DWORD *)(a3 + 56);
    if ( (unsigned int)nla_put(a1, 13, 4, &v13) )
      goto LABEL_4;
    v9 = *(_DWORD *)(a3 + 12);
    if ( (v9 & 0x20) != 0 )
      goto LABEL_19;
    goto LABEL_21;
  }
LABEL_91:
  v13 = 100 * *(_DWORD *)(a3 + 20);
  v11 = nla_put(a1, 6, 4, &v13);
  if ( v11 )
    result = 4294967191LL;
  else
    result = 0;
  if ( !v11 && (a4 & 1) != 0 )
  {
    v12 = freq_reg_info(a2, (unsigned int)(1000 * *(_DWORD *)(a3 + 4)));
    if ( !v12
      || v12 > 0xFFFFFFFFFFFFF000LL
      || *(_BYTE *)(v12 + 92) != 1
      || !(unsigned int)nl80211_msg_put_wmm_rules(a1, v12) )
    {
LABEL_7:
      result = 0;
      goto LABEL_8;
    }
    goto LABEL_4;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
