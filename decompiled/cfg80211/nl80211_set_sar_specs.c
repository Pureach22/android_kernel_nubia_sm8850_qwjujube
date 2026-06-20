__int64 __fastcall nl80211_set_sar_specs(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x19
  _WORD *v3; // x2
  __int64 result; // x0
  _DWORD *v6; // x9
  int v7; // w24
  int v8; // w10
  unsigned int v9; // w8
  unsigned __int16 *v10; // x11
  unsigned int v11; // w12
  __int64 v12; // x12
  unsigned __int64 v13; // x21
  _DWORD *v14; // x20
  _WORD *v15; // x9
  __int64 v16; // x8
  int v17; // w26
  unsigned int v18; // w25
  unsigned __int16 *v19; // x27
  unsigned int v20; // w10
  unsigned int v21; // w9
  unsigned __int64 v22; // x13
  __int64 v23; // x11
  __int64 v24; // x12
  _DWORD *v25; // x11
  __int64 v26; // x9
  unsigned int v27; // w21
  unsigned __int64 StatusReg; // x22
  __int64 v29; // x25
  __int64 v30; // [xsp+8h] [xbp-48h] BYREF
  __int64 v31; // [xsp+10h] [xbp-40h]
  _WORD *v32; // [xsp+18h] [xbp-38h]
  __int64 v33; // [xsp+20h] [xbp-30h] BYREF
  __int64 v34; // [xsp+28h] [xbp-28h]
  __int64 v35; // [xsp+30h] [xbp-20h]
  __int64 v36; // [xsp+38h] [xbp-18h]
  __int64 v37; // [xsp+40h] [xbp-10h]
  __int64 v38; // [xsp+48h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD **)(a2 + 48);
  if ( !v2[308] )
    goto LABEL_6;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = nullptr;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  if ( *(_QWORD *)(*v2 + 928LL) )
  {
    v3 = *(_WORD **)(*(_QWORD *)(a2 + 32) + 2400LL);
    if ( !v3 )
    {
LABEL_17:
      result = 4294967274LL;
      goto LABEL_18;
    }
    if ( (__int16)v3[1] < 0 )
      _nla_parse(&v30, 2, v3 + 2, (unsigned __int16)(*v3 - 4), 0, 31, 0);
    else
      do_trace_netlink_extack("NLA_F_NESTED is missing");
    result = 4294967274LL;
    if ( v31 )
    {
      if ( v32 )
      {
        v6 = (_DWORD *)v2[308];
        v7 = *(_DWORD *)(v31 + 4);
        if ( v7 == *v6 )
        {
          v8 = (unsigned __int16)(*v32 - 4);
          if ( (unsigned int)v8 < 4 )
          {
            v9 = 0;
          }
          else
          {
            v9 = 0;
            v10 = v32 + 2;
            do
            {
              v11 = *v10;
              if ( v11 < 4 )
                break;
              if ( v8 < v11 )
                break;
              ++v9;
              v12 = (v11 + 3) & 0x1FFFC;
              v8 -= v12;
              v10 = (unsigned __int16 *)((char *)v10 + v12);
            }
            while ( v8 > 3 );
            if ( v9 > v6[1] )
              goto LABEL_17;
          }
          v13 = 8LL * v9 + 8;
          v14 = (_DWORD *)_kmalloc_noprof(v13, 3520);
          if ( v14 )
          {
LABEL_21:
            v15 = v32;
            *v14 = v7;
            v16 = a2;
            v17 = (unsigned __int16)(*v15 - 4);
            if ( (unsigned int)v17 < 4 )
            {
              v18 = 0;
            }
            else
            {
              v18 = 0;
              v19 = v15 + 2;
              do
              {
                v20 = *v19;
                if ( v20 < 4 || v17 < v20 )
                  break;
                if ( (__int16)v19[1] < 0 )
                  _nla_parse(&v33, 4, v19 + 2, (unsigned __int16)(v20 - 4), 0, 31, 0);
                else
                  do_trace_netlink_extack("NLA_F_NESTED is missing");
                if ( v7 || !v34 || !v35 || (v21 = *(_DWORD *)(v35 + 4), v21 >= *(_DWORD *)(v2[308] + 4LL)) )
                {
LABEL_46:
                  v27 = -22;
                  goto LABEL_47;
                }
                v16 = a2;
                if ( v18 )
                {
                  v22 = v13 - 12;
                  v23 = 0;
                  while ( v13 >= v23 * 4 + 12 && v22 >= 4 )
                  {
                    if ( v14[v23 + 3] == v21 )
                      goto LABEL_46;
                    v23 += 2;
                    v22 -= 8LL;
                    if ( 2LL * v18 == v23 )
                      goto LABEL_38;
                  }
LABEL_48:
                  __break(1u);
                  StatusReg = _ReadStatusReg(SP_EL0);
                  v29 = *(_QWORD *)(StatusReg + 80);
                  v13 = 8LL * (unsigned int)a2 + 8;
                  *(_QWORD *)(StatusReg + 80) = &nl80211_set_sar_specs__alloc_tag;
                  v14 = (_DWORD *)_kmalloc_noprof(v13, 3520);
                  *(_QWORD *)(StatusReg + 80) = v29;
                  if ( v14 )
                    goto LABEL_21;
                  goto LABEL_49;
                }
LABEL_38:
                v24 = 8LL * (int)v18;
                if ( v13 < v24 + 8 )
                  goto LABEL_48;
                if ( v13 - (v24 + 8) < 4 )
                  goto LABEL_48;
                v25 = &v14[2 * v18 + 2];
                *v25 = *(_DWORD *)(v34 + 4);
                if ( v13 < v24 + 12 || v13 - (v24 + 12) < 4 )
                  goto LABEL_48;
                v25[1] = v21;
                ++v18;
                v26 = (*v19 + 3) & 0x1FFFC;
                v17 -= v26;
                v19 = (unsigned __int16 *)((char *)v19 + v26);
              }
              while ( v17 > 3 );
            }
            v14[1] = v18;
            v2[37] = v16;
            v27 = rdev_set_sar_specs(v2, v14);
            v2[37] = 0;
LABEL_47:
            kfree(v14);
            result = v27;
          }
          else
          {
LABEL_49:
            result = 4294967284LL;
          }
        }
      }
    }
  }
  else
  {
LABEL_6:
    result = 4294967201LL;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
