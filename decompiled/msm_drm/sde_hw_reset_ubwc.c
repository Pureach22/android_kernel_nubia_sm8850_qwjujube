__int64 *__fastcall sde_hw_reset_ubwc(__int64 *result, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x8
  __int64 v5; // x10
  unsigned int v6; // w0
  unsigned int v7; // w8
  unsigned int v8; // w2
  unsigned int v9; // w19
  unsigned int v10; // w2
  unsigned int v11; // w8
  int v12; // w9
  const char *v13; // x3
  unsigned int v14; // w1
  __int64 v15; // [xsp+8h] [xbp-28h] BYREF
  __int64 v16; // [xsp+10h] [xbp-20h]
  __int64 v17; // [xsp+18h] [xbp-18h]
  __int64 v18; // [xsp+20h] [xbp-10h]
  __int64 v19; // [xsp+28h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result && a2 )
  {
    v3 = result[1];
    v15 = *result;
    v16 = v3;
    v4 = result[2];
    v5 = result[3];
    LODWORD(v16) = 0;
    v17 = v4;
    v18 = v5;
    v6 = sde_reg_read((__int64)&v15, 0x58u);
    v7 = *(_DWORD *)(a2 + 4);
    if ( v6 >> 30 )
    {
      v8 = *(_DWORD *)(a2 + 704) & 7
         | (8 * (*(_BYTE *)(a2 + 700) & 1)) & 0x8F
         | (unsigned __int8)(16 * (*(_BYTE *)(a2 + 696) & 7))
         | ((*(_DWORD *)(a2 + 21600) & 1) << 12);
      if ( v6 >> 28 == 6 )
      {
        v9 = 5;
      }
      else if ( v6 >> 28 == 5 )
      {
        v9 = 4;
      }
      else if ( HIWORD(v7) == 16387 )
      {
        v9 = 3;
      }
      else
      {
        v9 = 2;
      }
      sde_reg_write((__int64)&v15, 0x144u, v8, "UBWC_STATIC");
      sde_reg_write((__int64)&v15, 0x150u, v9, "UBWC_CTRL_2");
      v13 = "UBWC_PREDICTION_MODE";
      v14 = 340;
      v10 = 1;
    }
    else
    {
      if ( HIWORD(v6) == 12288 )
      {
        v11 = HIWORD(v7);
        v12 = *(_DWORD *)(a2 + 704) & 1
            | *(_DWORD *)(a2 + 700)
            | (16 * (*(_DWORD *)(a2 + 696) & 3))
            | ((*(_DWORD *)(a2 + 21600) & 1) << 12);
        if ( v11 == 12288 )
          v12 |= 0x400u;
        if ( v11 == 4096 )
          v10 = v12 | 0x100;
        else
          v10 = v12;
      }
      else
      {
        if ( HIWORD(v6) != 0x2000 )
        {
          result = (__int64 *)printk(&unk_27E7B0, "sde_hw_reset_ubwc");
          goto LABEL_22;
        }
        v10 = *(_DWORD *)(a2 + 700);
      }
      v13 = "UBWC_STATIC";
      v14 = 324;
    }
    result = (__int64 *)sde_reg_write((__int64)&v15, v14, v10, v13);
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
