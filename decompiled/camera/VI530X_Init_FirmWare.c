__int64 __fastcall VI530X_Init_FirmWare(__int64 a1)
{
  unsigned int v2; // w0
  __int64 result; // x0
  unsigned int v4; // w20
  __int64 v5; // x23
  __int64 v6; // x21
  unsigned int v7; // w22
  unsigned int v8; // w21
  _BYTE v9[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v10[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[0] = 0;
  v9[0] = 0;
  v2 = ((__int64 (*)(void))LoadFirmware)();
  if ( !(_WORD)v2 )
  {
    printk(&unk_4424C0);
LABEL_3:
    result = 4294967285LL;
    goto LABEL_13;
  }
  v4 = v2;
  printk(&unk_427308);
  result = vi530x_write_byte(a1, 7, 8);
  if ( !(_DWORD)result )
  {
    result = vi530x_write_byte(a1, 7, 10);
    if ( !(_DWORD)result )
    {
      result = vi530x_write_byte(a1, 0, 6);
      if ( !(_DWORD)result )
      {
        result = vi530x_read_byte(a1, 1, v10);
        if ( !(_DWORD)result )
        {
          result = vi530x_write_byte(a1, 1, v10[0] | 1u);
          if ( !(_DWORD)result )
          {
            result = vi530x_write_byte(a1, 10, 1);
            if ( !(_DWORD)result )
            {
              result = vi530x_write_byte(a1, 11, 2);
              if ( !(_DWORD)result )
              {
                result = vi530x_write_reg_offset(a1, 12, 0, 0);
                if ( !(_DWORD)result )
                {
                  result = vi530x_write_reg_offset(a1, 12, 1, 0);
                  if ( !(_DWORD)result )
                  {
                    if ( (unsigned __int16)v4 > 0x1Fu )
                    {
                      v5 = -32;
                      v6 = (unsigned __int16)(v4 - 32) & 0xFFE0;
                      v7 = ((unsigned __int16)(v4 - 32) >> 5) + 1;
                      while ( 1 )
                      {
                        result = vi530x_write_reg_offset(a1, 10, 0, 3);
                        if ( (_DWORD)result )
                          goto LABEL_13;
                        result = vi530x_write_reg_offset(a1, 11, 0, 32);
                        if ( (_DWORD)result )
                          goto LABEL_13;
                        if ( v5 == 0x2000 )
                          goto LABEL_38;
                        result = vi530x_write_multibytes(a1, 12, (char *)&Firmware + v5 + 32, 32);
                        if ( (_DWORD)result )
                          goto LABEL_13;
                        _const_udelay(byte_A7C6);
                        v5 += 32;
                        v4 -= 32;
                        if ( v6 == v5 )
                        {
                          v8 = (unsigned __int16)v4;
                          if ( (_WORD)v4 )
                            goto LABEL_24;
                          goto LABEL_28;
                        }
                      }
                    }
                    v7 = 0;
                    v8 = v4 & 0x1F;
LABEL_24:
                    result = vi530x_write_reg_offset(a1, 10, 0, 3);
                    if ( (_DWORD)result )
                      goto LABEL_13;
                    result = vi530x_write_reg_offset(a1, 11, 0, v4);
                    if ( (_DWORD)result )
                      goto LABEL_13;
                    if ( v7 > 0x100 )
                    {
LABEL_38:
                      __break(0x5512u);
                    }
                    else
                    {
                      result = vi530x_write_multibytes(a1, 12, (char *)&Firmware + 32 * (v7 & 0x7FF), v8);
                      if ( (_DWORD)result )
                        goto LABEL_13;
LABEL_28:
                      result = vi530x_write_byte(a1, 1, v10[0] & 0xFE);
                      if ( (_DWORD)result )
                        goto LABEL_13;
                      result = vi530x_write_byte(a1, 0, 6);
                      if ( (_DWORD)result )
                        goto LABEL_13;
                      result = vi530x_write_byte(a1, 59, 160);
                      if ( (_DWORD)result )
                        goto LABEL_13;
                      result = vi530x_write_byte(a1, 59, 128);
                      if ( (_DWORD)result )
                        goto LABEL_13;
                      result = vi530x_write_byte(a1, 0, 7);
                      if ( (_DWORD)result )
                        goto LABEL_13;
                      result = vi530x_write_byte(a1, 7, 2);
                      if ( (_DWORD)result )
                        goto LABEL_13;
                      result = vi530x_write_byte(a1, 7, 0);
                      if ( (_DWORD)result )
                        goto LABEL_13;
                      _const_udelay((const char *)0x147AEB8);
                      result = vi530x_read_byte(a1, 8, v9);
                      if ( (_DWORD)result )
                        goto LABEL_13;
                      if ( v9[0] == 102 )
                      {
                        result = 0;
                        goto LABEL_13;
                      }
                    }
                    printk(&unk_446371);
                    goto LABEL_3;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
