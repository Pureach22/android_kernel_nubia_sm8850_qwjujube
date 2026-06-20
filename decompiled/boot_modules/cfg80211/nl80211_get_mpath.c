__int64 __fastcall nl80211_get_mpath(__int64 a1, unsigned int *a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  __int64 v4; // x20
  __int64 v5; // x21
  _DWORD *v7; // x8
  __int64 result; // x0
  __int64 v9; // x0
  __int64 v10; // x20
  int v11; // w0
  _QWORD v12[4]; // [xsp+8h] [xbp-38h] BYREF
  int v13; // [xsp+28h] [xbp-18h]
  int v14; // [xsp+30h] [xbp-10h] BYREF
  __int16 v15; // [xsp+34h] [xbp-Ch]
  __int64 v16; // [xsp+38h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *((_QWORD *)a2 + 4);
  memset(v12, 0, sizeof(v12));
  v4 = *((_QWORD *)a2 + 6);
  v3 = *((_QWORD *)a2 + 7);
  v13 = 0;
  v5 = *(_QWORD *)(v2 + 48);
  if ( v5 )
  {
    if ( *(_QWORD *)(*(_QWORD *)v4 + 200LL) && *(_DWORD *)(*(_QWORD *)(v3 + 992) + 8LL) == 7 )
    {
      v15 = 0;
      v14 = 0;
      v7 = *(_DWORD **)(*(_QWORD *)v4 + 200LL);
      if ( *(v7 - 1) != 968807081 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, __int64, __int64, int *, _QWORD *))v7)(v4 + 992, v3, v5 + 4, &v14, v12);
      if ( !(_DWORD)result )
      {
        v9 = _alloc_skb(3712, 3264, 0, 0xFFFFFFFFLL);
        if ( v9 )
        {
          v10 = v9;
          if ( (nl80211_send_mpath(v9, a2[1], *a2, 0, v3, v5 + 4, &v14, v12) & 0x80000000) != 0 )
          {
            sk_skb_reason_drop(0, v10, 2);
            result = 4294967191LL;
          }
          else
          {
            v11 = netlink_unicast(*(_QWORD *)(*((_QWORD *)a2 + 5) + 288LL), v10, a2[1], 64);
            result = v11 & (unsigned int)(v11 >> 31);
          }
        }
        else
        {
          result = 4294967284LL;
        }
      }
    }
    else
    {
      result = 4294967201LL;
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
