__int64 __fastcall policy_mgr_is_conn_lead_to_dbs_sbs(__int64 a1, unsigned __int8 a2, unsigned int a3)
{
  __int64 result; // x0
  unsigned int v7; // w21
  char v8; // w8
  char v9; // w8
  char v10; // w8
  char v11; // w8
  __int64 v12; // [xsp+0h] [xbp-30h] BYREF
  __int64 v13; // [xsp+8h] [xbp-28h]
  __int64 v14; // [xsp+10h] [xbp-20h]
  __int64 v15; // [xsp+18h] [xbp-18h]
  __int64 v16; // [xsp+20h] [xbp-10h]
  __int64 v17; // [xsp+28h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  v12 = 0;
  result = policy_mgr_get_connection_info(a1, &v12);
  if ( (_DWORD)result )
  {
    v7 = result;
    if ( BYTE1(v12) != a2 && (policy_mgr_2_freq_always_on_same_mac(a1, a3, HIDWORD(v12)) & 1) == 0 )
      goto LABEL_18;
    result = v7 != 1;
    if ( v7 != 1 )
    {
      if ( BYTE1(v13) == a2
        || (v8 = policy_mgr_2_freq_always_on_same_mac(a1, a3, HIDWORD(v13)), result = v7 != 1, (v8 & 1) != 0) )
      {
        result = v7 > 2;
        if ( v7 != 2 )
        {
          if ( BYTE1(v14) == a2
            || (v9 = policy_mgr_2_freq_always_on_same_mac(a1, a3, HIDWORD(v14)), result = v7 > 2, (v9 & 1) != 0) )
          {
            result = v7 > 3;
            if ( v7 != 3 )
            {
              if ( BYTE1(v15) == a2
                || (v10 = policy_mgr_2_freq_always_on_same_mac(a1, a3, HIDWORD(v15)), result = v7 > 3, (v10 & 1) != 0) )
              {
                result = v7 > 4;
                if ( v7 != 4 )
                {
                  if ( BYTE1(v16) == a2
                    || (v11 = policy_mgr_2_freq_always_on_same_mac(a1, a3, HIDWORD(v16)), result = v7 > 4,
                                                                                          (v11 & 1) != 0) )
                  {
                    result = v7 > 5;
                    if ( v7 != 5 )
                    {
                      __break(0x5512u);
LABEL_18:
                      result = 1;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
