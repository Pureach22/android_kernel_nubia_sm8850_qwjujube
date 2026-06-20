__int64 __fastcall hdd_ml_generate_link_state_resp_nlmsg(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  __int64 result; // x0
  __int64 v8; // x22
  __int64 v9; // x23
  int v10; // w8
  _WORD *v11; // x22
  __int64 v12; // x23
  __int64 v13; // x24
  int v14; // w8
  _WORD *v15; // x23
  __int64 v16; // x23
  __int64 v17; // x24
  int v18; // w8
  _WORD *v19; // x23
  __int64 v20; // x23
  __int64 v21; // x24
  int v22; // w8
  _WORD *v23; // x23
  __int64 v24; // x20
  __int64 v25; // x21
  int v26; // w8
  int ml_link_control_mode; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+8h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  ml_link_control_mode = (unsigned __int8)ucfg_mlme_get_ml_link_control_mode(a2, *(unsigned __int8 *)(a3 + 34));
  result = nla_put(a1, 2, 4, &ml_link_control_mode);
  if ( !(_DWORD)result )
  {
    ml_link_control_mode = 0;
    result = nla_put(a1, 5, 4, &ml_link_control_mode);
    if ( !(_DWORD)result )
    {
      v8 = *(_QWORD *)(a1 + 216);
      v9 = *(unsigned int *)(a1 + 208);
      v10 = nla_put(a1, 32771, 0, 0);
      result = 4294967274LL;
      if ( (v10 & 0x80000000) == 0 )
      {
        v11 = (_WORD *)(v8 + v9);
        if ( v11 )
        {
          if ( !a4 )
          {
LABEL_12:
            result = 0;
            *v11 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v11;
            goto LABEL_3;
          }
          v12 = *(_QWORD *)(a1 + 216);
          v13 = *(unsigned int *)(a1 + 208);
          v14 = nla_put(a1, 32771, 0, 0);
          result = 4294967274LL;
          if ( (v14 & 0x80000000) == 0 )
          {
            v15 = (_WORD *)(v12 + v13);
            if ( v15 )
            {
              LOBYTE(ml_link_control_mode) = BYTE1(*(_DWORD *)(a3 + 8));
              result = nla_put(a1, 1, 1, &ml_link_control_mode);
              if ( !(_DWORD)result )
              {
                ml_link_control_mode = *(_WORD *)(a3 + 10) & 3;
                result = nla_put(a1, 2, 4, &ml_link_control_mode);
                if ( !(_DWORD)result )
                {
                  *v15 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v15;
                  if ( a4 == 1 )
                    goto LABEL_12;
                  v16 = *(_QWORD *)(a1 + 216);
                  v17 = *(unsigned int *)(a1 + 208);
                  v18 = nla_put(a1, 32770, 0, 0);
                  result = 4294967274LL;
                  if ( (v18 & 0x80000000) == 0 )
                  {
                    v19 = (_WORD *)(v16 + v17);
                    if ( v19 )
                    {
                      LOBYTE(ml_link_control_mode) = BYTE1(*(_DWORD *)(a3 + 16));
                      result = nla_put(a1, 1, 1, &ml_link_control_mode);
                      if ( !(_DWORD)result )
                      {
                        ml_link_control_mode = *(_WORD *)(a3 + 18) & 3;
                        result = nla_put(a1, 2, 4, &ml_link_control_mode);
                        if ( !(_DWORD)result )
                        {
                          *v19 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v19;
                          if ( a4 == 2 )
                            goto LABEL_12;
                          v20 = *(_QWORD *)(a1 + 216);
                          v21 = *(unsigned int *)(a1 + 208);
                          v22 = nla_put(a1, 32770, 0, 0);
                          result = 4294967274LL;
                          if ( (v22 & 0x80000000) == 0 )
                          {
                            v23 = (_WORD *)(v20 + v21);
                            if ( v23 )
                            {
                              LOBYTE(ml_link_control_mode) = BYTE1(*(_DWORD *)(a3 + 24));
                              result = nla_put(a1, 1, 1, &ml_link_control_mode);
                              if ( !(_DWORD)result )
                              {
                                ml_link_control_mode = *(_WORD *)(a3 + 26) & 3;
                                result = nla_put(a1, 2, 4, &ml_link_control_mode);
                                if ( !(_DWORD)result )
                                {
                                  *v23 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v23;
                                  if ( a4 == 3 )
                                    goto LABEL_12;
                                  v24 = *(_QWORD *)(a1 + 216);
                                  v25 = *(unsigned int *)(a1 + 208);
                                  v26 = nla_put(a1, 32770, 0, 0);
                                  result = 4294967274LL;
                                  if ( (v26 & 0x80000000) == 0 && v24 + v25 )
                                    __break(0x5512u);
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
            }
          }
        }
      }
    }
  }
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
