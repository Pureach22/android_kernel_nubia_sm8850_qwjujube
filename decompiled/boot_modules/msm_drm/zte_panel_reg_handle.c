size_t __fastcall zte_panel_reg_handle(__int64 a1, char *string, size_t maxlen, int a4)
{
  size_t result; // x0
  size_t v9; // x2
  unsigned __int64 v10; // x8
  size_t v11; // x8
  int v12; // w10
  char v13; // w13
  __int64 v14; // x13
  char v15; // w14
  __int64 v16; // x9
  unsigned __int64 v17; // x10
  char *v18; // x12
  char *v19; // x13
  __int64 v20; // x21
  __int64 v21; // x19
  unsigned __int64 v22; // x8
  char *v23; // x8
  __int64 v24; // x20
  __int64 v25; // x19
  _QWORD v26[17]; // [xsp+8h] [xbp-88h] BYREF

  v26[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v26, 0, 128);
  if ( maxlen >= 0x80 )
  {
    result = printk(&unk_255971, maxlen);
    goto LABEL_28;
  }
  result = strnlen(string, maxlen);
  if ( result == -1 )
    goto LABEL_46;
  if ( result == maxlen )
    v9 = maxlen;
  else
    v9 = result + 1;
  if ( v9 >= 0x81 )
LABEL_47:
    _fortify_panic(7, 128, v9);
  result = sized_strscpy(v26, string);
  qword_29BB25 = 0;
  qword_29BB2D = 0;
  qword_29BB35 = 0;
  qword_29BB3D = 0;
  qword_29BB45 = 0;
  qword_29BB4D = 0;
  qword_29BB55 = 0;
  qword_29BB5D = 0;
  qword_29BB65 = 0;
  qword_29BB6D = 0;
  qword_29BB75 = 0;
  qword_29BB7D = 0;
  qword_29BB85 = 0;
  qword_29BB8D = 0;
  qword_29BB95 = 0;
  qword_29BB9D = 0;
  if ( !maxlen )
  {
    v10 = -1;
    goto LABEL_23;
  }
  v11 = 0;
  v12 = 1;
  do
  {
    if ( v11 > 0x7F )
      goto LABEL_44;
    v14 = *((unsigned __int8 *)v26 + v11);
    if ( (unsigned int)(v14 - 58) >= 0xFFFFFFF6 )
    {
      v13 = v14 - 48;
LABEL_12:
      *((_BYTE *)v26 + v11) = v13;
      goto LABEL_13;
    }
    if ( (*((_BYTE *)&ctype + v14) & 3) != 0 )
    {
      if ( (*((_BYTE *)&ctype + v14) & 1) != 0 )
        v15 = -55;
      else
        v15 = -87;
      v13 = v15 + v14;
      goto LABEL_12;
    }
LABEL_13:
    v11 = v12++;
  }
  while ( v11 < maxlen );
  v10 = maxlen - 1;
  if ( maxlen != 1 )
  {
LABEL_23:
    v16 = 0;
    v17 = 0;
    while ( v16 != 64 )
    {
      if ( v17 > 0x7F )
        goto LABEL_44;
      v18 = (char *)v26 + v17;
      v17 += 2LL;
      v19 = (char *)&zte_lcd_reg_debug + v16++;
      v19[69] = v18[1] + 16 * *v18;
      if ( v10 <= v17 )
        goto LABEL_27;
    }
    goto LABEL_45;
  }
  LOBYTE(v16) = 0;
LABEL_27:
  byte_29BB24 = v16;
LABEL_28:
  if ( ((1 << a4) & 0x15) == 0 )
  {
    if ( ((1 << a4) & 0xA) != 0 )
    {
      v20 = BYTE1(qword_29BB65);
      if ( BYTE1(qword_29BB65) )
      {
        zte_lcd_reg_debug = a4;
        printk(&unk_225EBE, (unsigned __int8)qword_29BB65);
        result = ((__int64 (__fastcall *)(__int64))zte_lcd_reg_rw_func)(a1);
        v21 = 0;
        byte_29BB24 = v20;
        while ( v21 != 64 )
        {
          result = printk(&unk_22CB51, (unsigned int)v21++);
          if ( v20 == v21 )
            goto LABEL_43;
        }
        goto LABEL_45;
      }
LABEL_39:
      result = printk(&unk_2590C6, "zte_panel_reg_handle");
      goto LABEL_43;
    }
    v22 = (unsigned __int8)byte_29BB24 - 1LL;
    if ( v22 <= 0x3F )
    {
      if ( (unsigned __int8)byte_29BB24 <= 0x43u )
      {
        v23 = (char *)&zte_lcd_reg_debug + v22;
        v24 = (unsigned __int8)v23[69];
        if ( v23[69] )
        {
          zte_lcd_reg_debug = 5;
          printk(&unk_251E63, (unsigned __int8)qword_29BB65);
          result = ((__int64 (__fastcall *)(__int64))zte_lcd_reg_rw_func)(a1);
          v25 = 0;
          byte_29BB24 = v24;
          while ( v25 != 64 )
          {
            result = printk(&unk_22CB51, (unsigned int)v25++);
            if ( v24 == v25 )
              goto LABEL_43;
          }
          goto LABEL_45;
        }
        goto LABEL_39;
      }
LABEL_44:
      __break(1u);
    }
LABEL_45:
    __break(0x5512u);
LABEL_46:
    _fortify_panic(2, -1, result + 1);
    goto LABEL_47;
  }
  zte_lcd_reg_debug = a4;
  ((void (__fastcall *)(__int64))zte_lcd_reg_rw_func)(a1);
  result = printk(&unk_26B06B, (unsigned __int8)qword_29BB65);
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return result;
}
