__int64 __fastcall msm_gpio_dbg_show(__int64 result, __int64 a2)
{
  __int64 v3; // x20
  __int64 v4; // x22
  unsigned __int64 i; // x21
  __int64 data; // x27
  __int64 v7; // x8
  __int64 v8; // x28
  const char *v9; // x2
  const char *v10; // x3
  const char *v11; // x2
  char **v12; // x9
  unsigned __int64 v13; // x10
  const char **v14; // x9
  __int64 v15; // [xsp+0h] [xbp-20h] BYREF
  __int64 v16; // [xsp+8h] [xbp-18h] BYREF
  int v17; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v18; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+18h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_WORD *)(a2 + 172) )
  {
    v3 = result;
    v4 = 0;
    for ( i = 0; i < *(unsigned __int16 *)(a2 + 172); ++i )
    {
      data = gpiochip_get_data(a2);
      result = gpiochip_line_is_valid(a2, (unsigned int)i);
      if ( (result & 1) != 0 )
      {
        v7 = *(_QWORD *)(*(_QWORD *)(data + 968) + 32LL);
        v18 = 0;
        v8 = v7 + v4;
        v17 = 0;
        v15 = 0;
        v16 = 0;
        msm_gpio_pin_status_get(
          data,
          v7 + v4,
          &v17,
          (int *)&v18,
          (int *)&v16 + 1,
          (int *)&v16,
          &v15,
          (_DWORD *)&v15 + 1);
        v9 = *(const char **)(v8 + 24);
        if ( (_DWORD)v15 )
        {
          result = seq_printf(v3, " %-8s: egpio\n", v9);
        }
        else
        {
          if ( v17 )
            v10 = "out";
          else
            v10 = "in";
          seq_printf(v3, " %-8s: %-3s", v9, v10);
          if ( HIDWORD(v15) )
            v11 = "high";
          else
            v11 = "low";
          seq_printf(v3, " %-4s func%d", v11, v18);
          seq_printf(v3, " %dmA", 2 * HIDWORD(v16) + 2);
          if ( *(_BYTE *)(*(_QWORD *)(data + 968) + 48LL) == 1 )
          {
            if ( (unsigned int)v16 >= 3 )
              goto LABEL_21;
            v12 = pulls_no_keeper;
            v13 = 24;
          }
          else
          {
            if ( (unsigned int)v16 > 3 )
            {
LABEL_21:
              __break(0x5512u);
LABEL_22:
              __break(1u);
            }
            v12 = pulls_keeper;
            v13 = 32;
          }
          v14 = (const char **)&v12[(unsigned int)v16];
          if ( v13 <= 8 * (unsigned __int64)(unsigned int)v16 )
            goto LABEL_22;
          seq_printf(v3, " %s", *v14);
          result = seq_putc(v3, 10);
        }
      }
      v4 += 112;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
