__int64 __fastcall nl80211_parse_mbssid_config(__int64 a1, __int64 a2, _WORD *a3, __int64 a4, unsigned __int8 a5)
{
  int v5; // w8
  __int64 result; // x0
  int v11; // w8
  __int64 v12; // x11
  __int64 v13; // x13
  unsigned int v14; // w11
  int v15; // w1
  int v16; // w12
  __int64 v17; // x0
  __int64 v18; // x1
  __int64 v19; // x2
  __int64 v20; // x8
  _QWORD v21[3]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v22; // [xsp+20h] [xbp-20h]
  __int64 v23; // [xsp+28h] [xbp-18h]
  __int64 v24; // [xsp+30h] [xbp-10h]
  __int64 v25; // [xsp+38h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_BYTE *)(a1 + 1488) )
    goto LABEL_19;
  v5 = (__int16)a3[1];
  v23 = 0;
  v24 = 0;
  v22 = 0;
  memset(v21, 0, sizeof(v21));
  if ( (v5 & 0x80000000) == 0 )
  {
    do_trace_netlink_extack("NLA_F_NESTED is missing");
    result = 4294967274LL;
    goto LABEL_20;
  }
  v11 = _nla_parse(v21, 5, a3 + 2, (unsigned __int16)(*a3 - 4), 0, 31, 0);
  result = 4294967274LL;
  if ( !v11 )
  {
    v12 = v22;
    if ( v22 )
    {
      v13 = v24;
      *(_BYTE *)(a4 + 9) = v24 != 0;
      if ( !v13 )
        goto LABEL_9;
      if ( *(_BYTE *)(a1 + 1489) )
      {
        if ( *(unsigned __int8 *)(a1 + 1489) < (unsigned int)a5 )
          goto LABEL_20;
LABEL_9:
        v14 = *(unsigned __int8 *)(v12 + 4);
        *(_BYTE *)(a4 + 8) = v14;
        if ( v14 >= *(unsigned __int8 *)(a1 + 1488) || !(v14 | a5) )
          goto LABEL_20;
        if ( v23 )
        {
          v15 = *(_DWORD *)(v23 + 4);
          v16 = *(_DWORD *)(a2 + 224);
          if ( v14 )
          {
            if ( v15 != v16 )
            {
              v17 = dev_get_by_index(*(_QWORD *)(a1 + 1352));
              if ( v17 && (v20 = *(_QWORD *)(v17 + 992)) != 0 && *(_QWORD *)v20 == a1 && *(_DWORD *)(v20 + 8) == 3 )
              {
                result = 0;
                *(_QWORD *)a4 = v20;
              }
              else
              {
                dev_put(v17, v18, v19);
                result = 4294967274LL;
              }
            }
            goto LABEL_20;
          }
          if ( v15 != v16 )
            goto LABEL_20;
        }
        else if ( v14 )
        {
          goto LABEL_20;
        }
        result = 0;
        *(_QWORD *)a4 = *(_QWORD *)(a2 + 992);
        goto LABEL_20;
      }
LABEL_19:
      result = 4294967201LL;
    }
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
