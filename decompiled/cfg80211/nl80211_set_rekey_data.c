__int64 __fastcall nl80211_set_rekey_data(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x19
  _DWORD *v3; // x20
  __int64 v4; // x8
  __int64 v5; // x21
  _WORD *v6; // x2
  __int64 result; // x0
  __int16 v8; // w10
  __int16 v9; // w12
  int v10; // w13
  _QWORD v11[3]; // [xsp+0h] [xbp-50h] BYREF
  __int64 v12; // [xsp+18h] [xbp-38h]
  __int64 v13; // [xsp+20h] [xbp-30h] BYREF
  _WORD *v14; // [xsp+28h] [xbp-28h]
  _WORD *v15; // [xsp+30h] [xbp-20h]
  __int64 v16; // [xsp+38h] [xbp-18h]
  __int64 v17; // [xsp+40h] [xbp-10h]
  __int64 v18; // [xsp+48h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = (_DWORD *)a2[6];
  v2 = a2[7];
  v4 = a2[4];
  v16 = 0;
  v17 = 0;
  v14 = nullptr;
  v15 = nullptr;
  v12 = 0;
  v13 = 0;
  v5 = *(_QWORD *)(v2 + 992);
  v6 = *(_WORD **)(v4 + 976);
  if ( v6 )
  {
    result = _nla_parse(&v13, 4, v6 + 2, (unsigned __int16)(*v6 - 4), &nl80211_rekey_policy, 0, a2[8]);
    if ( !(_DWORD)result )
    {
      result = 4294967274LL;
      if ( v16 )
      {
        if ( v14 )
        {
          if ( v15 )
          {
            v8 = *v14 - 4;
            if ( *v14 == 20 || (result = 4294967262LL, (unsigned __int16)(*v14 - 4) == 32) && (v3[273] & 1) != 0 )
            {
              if ( (v9 = *v15 - 4, *v15 == 20)
                || (v10 = v3[273], (unsigned __int16)(*v15 - 4) == 24) && (v10 & 1) != 0
                || (result = 4294967262LL, (unsigned __int16)(*v15 - 4) == 32) && (v10 & 0x800) != 0 )
              {
                v11[2] = v16 + 4;
                v11[0] = v14 + 2;
                v11[1] = v15 + 2;
                BYTE4(v12) = v8;
                BYTE5(v12) = v9;
                if ( v17 )
                  LODWORD(v12) = *(_DWORD *)(v17 + 4);
                if ( (*(_BYTE *)(v5 + 164) & 1) != 0 )
                {
                  if ( *(_QWORD *)(*(_QWORD *)v3 + 608LL) )
                    result = rdev_set_rekey_data(v3, v2, v11);
                  else
                    result = 4294967201LL;
                }
                else
                {
                  result = 4294967189LL;
                }
              }
            }
          }
        }
      }
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
