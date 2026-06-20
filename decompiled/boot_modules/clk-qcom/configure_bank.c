__int64 __fastcall configure_bank(__int64 a1, __int64 a2)
{
  int v4; // w23
  int v5; // w24
  __int64 v6; // x0
  unsigned __int8 is_enabled; // w20
  __int64 result; // x0
  __int64 v9; // x25
  unsigned int v10; // w22
  __int64 v11; // x0
  _BYTE *v12; // x26
  unsigned int v13; // w23
  char v14; // w9
  int v15; // w8
  __int64 v16; // x2
  __int64 v17; // x0
  char v18; // w8
  int v19; // w9
  __int64 v20; // x2
  __int64 v21; // x0
  char v22; // w8
  __int64 v23; // x9
  int v24; // w11
  int v25; // w9
  unsigned int v26; // w8
  int v27; // w9
  __int64 v28; // x0
  __int64 v29; // x1
  int v30; // w9
  __int64 v31; // x2
  __int64 v32; // x0
  __int64 v33; // x23
  __int64 v34; // x8
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x1
  unsigned int v38; // [xsp+Ch] [xbp-14h] BYREF
  int v39; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v40; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v41; // [xsp+18h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned __int8 *)(a1 + 33);
  v5 = *(unsigned __int8 *)(a1 + 38);
  v6 = *(_QWORD *)(a1 + 88);
  v40 = 0;
  v38 = 0;
  v39 = 0;
  is_enabled = _clk_is_enabled(v6);
  result = regmap_read(*(_QWORD *)(a1 + 104), *(unsigned int *)(a1 + 16), &v38);
  if ( !(_DWORD)result )
  {
    v9 = (is_enabled ^ ((v38 & (unsigned int)(1LL << *(_BYTE *)(a1 + 20))) != 0)) & 1;
    v10 = *(_DWORD *)(a1 + 4 * v9);
    result = regmap_read(*(_QWORD *)(a1 + 104), v10, &v40);
    if ( !(_DWORD)result )
    {
      if ( !v4 )
        goto LABEL_21;
      v11 = *(_QWORD *)(a1 + 104);
      v12 = (_BYTE *)(a1 + 21 - v9 + 8 * v9);
      v13 = *(_DWORD *)(a1 + 4 * v9 + 8);
      v40 |= 1LL << v12[1];
      result = regmap_write(v11, v10, v40);
      if ( !(_DWORD)result )
      {
        result = regmap_read(*(_QWORD *)(a1 + 104), v13, &v39);
        if ( !(_DWORD)result )
        {
          v14 = v12[4];
          v15 = ~(-1 << v12[5]);
          v16 = v39 & ~(v15 << v14) & (unsigned int)(-1LL << v12[5]);
          if ( *(_WORD *)(a2 + 12) )
            v16 = v15 & ~*(unsigned __int16 *)(a2 + 12) | (*(unsigned __int16 *)(a2 + 10) << v14) | (unsigned int)v16;
          v17 = *(_QWORD *)(a1 + 104);
          v39 = v16;
          result = regmap_write(v17, v13, v16);
          if ( !(_DWORD)result )
          {
            v18 = v12[3];
            v19 = ~(-1 << v12[5]);
            v20 = v40 & ~(v19 << v18);
            if ( *(_WORD *)(a2 + 12) )
              v20 = (((*(unsigned __int16 *)(a2 + 10) + ~*(unsigned __int16 *)(a2 + 12)) & v19) << v18)
                  | (unsigned int)v20;
            v21 = *(_QWORD *)(a1 + 104);
            v40 = v20;
            result = regmap_write(v21, v10, v20);
            if ( !(_DWORD)result )
            {
              v22 = v12[2];
              v23 = 1LL << *v12;
              v24 = (2 << v22) | v23;
              v25 = (3 << v22) | v23;
              v26 = *(_WORD *)(a2 + 12) ? v24 : 0;
              v27 = ~v25;
              v28 = *(_QWORD *)(a1 + 104);
              if ( *(_DWORD *)a1 == *(_DWORD *)(a1 + 4) )
              {
                v29 = *(unsigned int *)(a1 + 16);
                v30 = v38 & v27;
                v31 = v30 | v26;
                v38 = v30 | v26;
              }
              else
              {
                v29 = v10;
                v31 = v40 & v27 | v26;
                v40 = v40 & v27 | v26;
              }
              result = regmap_write(v28, v29, v31);
              if ( !(_DWORD)result )
              {
                v32 = *(_QWORD *)(a1 + 104);
                v40 &= ~(unsigned int)(1LL << v12[1]);
                result = regmap_write(v32, v10, v40);
                if ( !(_DWORD)result )
                {
LABEL_21:
                  if ( v5 )
                    v40 = v40
                        & ~(~(unsigned int)(-1LL << *(_BYTE *)(a1 + 35 + 2 * v9 + 1)) << *(_BYTE *)(a1 + 35 + 2 * v9))
                        | ((unsigned __int8)(*(_BYTE *)(a2 + 9) - 1) << *(_BYTE *)(a1 + 35 + 2 * v9));
                  v33 = a1 + 16 * v9;
                  result = qcom_find_src_index(a1 + 80, *(_QWORD *)(v33 + 48), *(unsigned __int8 *)(a2 + 8));
                  if ( (result & 0x80000000) == 0 )
                  {
                    v34 = *(_QWORD *)(v33 + 48) + 2LL * (unsigned int)result;
                    v35 = *(_QWORD *)(a1 + 104);
                    v40 = v40 & ~(7 << *(_BYTE *)(v33 + 40)) | (*(unsigned __int8 *)(v34 + 1) << *(_BYTE *)(v33 + 40));
                    result = regmap_write(v35, v10, v40);
                    if ( !(_DWORD)result )
                    {
                      if ( (is_enabled & 1) == 0
                        || (result = regmap_read(*(_QWORD *)(a1 + 104), *(unsigned int *)(a1 + 16), &v38),
                            !(_DWORD)result)
                        && (v36 = *(_QWORD *)(a1 + 104),
                            v37 = *(unsigned int *)(a1 + 16),
                            v38 ^= 1LL << *(_BYTE *)(a1 + 20),
                            result = regmap_write(v36, v37, v38),
                            !(_DWORD)result) )
                      {
                        result = 0;
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
  _ReadStatusReg(SP_EL0);
  return result;
}
