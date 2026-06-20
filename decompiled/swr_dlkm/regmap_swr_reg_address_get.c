__int64 __fastcall regmap_swr_reg_address_get(__int64 a1, _WORD *a2, _WORD *a3, __int64 a4)
{
  unsigned int v4; // w9
  int v5; // w10
  int v6; // w19
  __int64 v7; // x8
  __int64 result; // x0
  __int16 v9; // w8
  _WORD *v10; // x21
  _WORD *v11; // x20
  _WORD *v13; // x20
  _WORD *v14; // x19
  __int64 v15; // x21
  unsigned int v16; // w19
  _BYTE v17[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v18[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a4 != 4 )
  {
    v9 = *a3;
    result = 0;
LABEL_13:
    *a2 = v9;
    goto LABEL_14;
  }
  v4 = *(_DWORD *)a3;
  v5 = *(_DWORD *)a3 >> 23;
  v6 = *(_DWORD *)a3 >> 15;
  v18[0] = v5;
  v17[0] = v4 >> 15;
  if ( v4 & 0x7F8000 | (unsigned __int8)(v4 >> 23) )
  {
    v7 = a1;
    if ( *(unsigned __int8 *)(a1 + 1010) == (unsigned __int8)v5 )
    {
      result = 0;
    }
    else
    {
      v10 = a2;
      v11 = a3;
      result = swr_write(a1, *(unsigned __int8 *)(a1 + 64), 72, v18);
      if ( (result & 0x80000000) != 0 )
      {
        v16 = result;
        dev_err(
          a1 + 72,
          "%s: write reg scp1_address failed, err %d\n",
          "regmap_swr_reg_address_get",
          (unsigned int)result);
        goto LABEL_17;
      }
      v7 = a1;
      a2 = v10;
      a3 = v11;
      *(_BYTE *)(a1 + 1010) = v18[0];
    }
    if ( *(unsigned __int8 *)(v7 + 1011) == (unsigned __int8)v6 )
    {
LABEL_12:
      v9 = *a3 | 0x8000;
      goto LABEL_13;
    }
    v13 = a2;
    v14 = a3;
    v15 = v7;
    result = swr_write(v7, *(unsigned __int8 *)(v7 + 64), 73, v17);
    if ( (result & 0x80000000) == 0 )
    {
      a2 = v13;
      a3 = v14;
      *(_BYTE *)(v15 + 1011) = v17[0];
      goto LABEL_12;
    }
    v16 = result;
    dev_err(v15 + 72, "%s: write reg scp2_address failed, err %d\n", "regmap_swr_reg_address_get", (unsigned int)result);
LABEL_17:
    result = v16;
    goto LABEL_14;
  }
  result = 0;
  *a2 = v4;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
