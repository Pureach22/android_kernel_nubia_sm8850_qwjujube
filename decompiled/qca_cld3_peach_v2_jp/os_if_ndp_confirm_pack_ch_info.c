__int64 __fastcall os_if_ndp_confirm_pack_ch_info(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  __int64 v4; // x22
  int v6; // w8
  __int64 result; // x0
  _WORD *v8; // x21
  unsigned __int64 v9; // x22
  int *v10; // x23
  __int64 v11; // x24
  __int64 v12; // x25
  int v13; // w8
  _WORD *v14; // x24
  int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a2 + 32) )
  {
    v3 = *(_QWORD *)(a1 + 216);
    v4 = *(unsigned int *)(a1 + 208);
    v6 = nla_put(a1, 32794, 0, 0);
    result = 5;
    if ( (v6 & 0x80000000) == 0 )
    {
      v8 = (_WORD *)(v3 + v4);
      if ( v8 )
      {
        if ( *(_DWORD *)(a2 + 32) )
        {
          v9 = 0;
          v10 = (int *)(a2 + 48);
          while ( 1 )
          {
            v11 = *(_QWORD *)(a1 + 216);
            v12 = *(unsigned int *)(a1 + 208);
            v13 = nla_put(a1, (unsigned int)v9 | 0x8000, 0, 0);
            result = 5;
            if ( v13 < 0 )
              break;
            v14 = (_WORD *)(v11 + v12);
            if ( !v14 )
              break;
            if ( v9 == 4 )
              __break(0x5512u);
            v15 = *(v10 - 2);
            if ( (unsigned int)nla_put(a1, 4, 4, &v15)
              || (v15 = *(v10 - 1), (unsigned int)nla_put(a1, 25, 4, &v15))
              || (v15 = *v10, (unsigned int)nla_put(a1, 23, 4, &v15)) )
            {
              result = 5;
              break;
            }
            ++v9;
            v10 += 5;
            *v14 = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v14;
            if ( v9 >= *(unsigned int *)(a2 + 32) )
              goto LABEL_13;
          }
        }
        else
        {
LABEL_13:
          result = 0;
          *v8 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v8;
        }
      }
    }
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
