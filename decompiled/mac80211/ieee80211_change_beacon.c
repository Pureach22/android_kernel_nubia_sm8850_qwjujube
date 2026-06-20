__int64 __fastcall ieee80211_change_beacon(__int64 a1, __int64 a2, unsigned int *a3)
{
  __int64 v3; // x8
  __int64 v4; // x19
  _BYTE *v5; // x20
  __int64 result; // x0
  int v9; // w8
  __int64 v10; // x2
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a3;
  v11[0] = 0;
  if ( (unsigned int)v3 >= 0xF )
    __break(0x5512u);
  v4 = *(_QWORD *)(a2 + 8 * v3 + 7256);
  if ( v4 )
  {
    v5 = *(_BYTE **)(v4 + 944);
    if ( (v5[830] & 1) != 0 || (v5[840] & 1) != 0 )
    {
      result = 4294967280LL;
    }
    else if ( *(_QWORD *)(v4 + 536) )
    {
      result = ieee80211_assign_beacon(a2 + 2688, v4, a3, 0, 0, v11);
      if ( (result & 0x80000000) == 0 )
      {
        result = ieee80211_set_fils_discovery(a3 + 44, v4, v5, v11);
        if ( (result & 0x80000000) == 0 )
        {
          result = ieee80211_set_unsol_bcast_probe_resp(a3 + 52, v4, v5, v11);
          if ( (result & 0x80000000) == 0 )
          {
            if ( (*((_BYTE *)a3 + 163) & 1) != 0 )
            {
              v9 = *((unsigned __int8 *)a3 + 161);
              v10 = v11[0];
              if ( v9 != (unsigned __int8)v5[346] )
              {
                v10 = v11[0] | 0x20000000LL;
                v5[346] = v9;
              }
            }
            else
            {
              v10 = v11[0];
            }
            ieee80211_link_info_change_notify(a2 + 2688, v4, v10);
            result = 0;
          }
        }
      }
    }
    else
    {
      result = 4294967294LL;
    }
  }
  else
  {
    result = 4294967229LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
