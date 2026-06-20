__int64 __fastcall noirq_msm_pinctrl_suspend(__int64 a1)
{
  __int64 v2; // x24
  __int64 v3; // x25
  unsigned __int64 i; // x20
  __int64 data; // x22
  __int64 v6; // x8
  __int64 v7; // x23
  const char *v8; // x2
  const char *v9; // x3
  char **v10; // x10
  unsigned __int64 v11; // x11
  const char **v12; // x10
  __int64 v13; // [xsp+0h] [xbp-20h] BYREF
  __int64 v14; // [xsp+8h] [xbp-18h] BYREF
  int v15; // [xsp+10h] [xbp-10h] BYREF
  int v16; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( pinctrl_msm_log_mask == 1 )
  {
    v2 = *(_QWORD *)(a1 + 152);
    printk_deferred("%s\n", *(const char **)(v2 + 16));
    if ( *(_WORD *)(v2 + 188) )
    {
      v3 = 0;
      for ( i = 0; i < *(unsigned __int16 *)(v2 + 188); ++i )
      {
        data = gpiochip_get_data(v2 + 16);
        if ( (gpiochip_line_is_valid(v2 + 16, (unsigned int)i) & 1) != 0 )
        {
          v6 = *(_QWORD *)(*(_QWORD *)(data + 968) + 32LL);
          v16 = 0;
          v7 = v6 + v3;
          v15 = 0;
          v14 = 0;
          HIDWORD(v13) = 0;
          msm_gpio_pin_status_get(data, v6 + v3, &v15, &v16, (char *)&v14 + 4, &v14, &v13, (char *)&v13 + 4);
          if ( v15 )
            v8 = "out";
          else
            v8 = "in";
          if ( HIDWORD(v13) )
            v9 = "high";
          else
            v9 = "low";
          if ( *(_BYTE *)(*(_QWORD *)(data + 968) + 48LL) == 1 )
          {
            if ( (unsigned int)v14 >= 3 )
              goto LABEL_21;
            v10 = pulls_no_keeper;
            v11 = 24;
          }
          else
          {
            if ( (unsigned int)v14 > 3 )
              goto LABEL_21;
            v10 = pulls_keeper;
            v11 = 32;
          }
          v12 = (const char **)&v10[(unsigned int)v14];
          if ( v11 <= 8 * (unsigned __int64)(unsigned int)v14 )
          {
            __break(1u);
LABEL_21:
            __break(0x5512u);
          }
          printk_deferred(
            "%s: %s, %s, func%d, %dmA, %s\n",
            *(const char **)(v7 + 24),
            v8,
            v9,
            v16,
            2 * HIDWORD(v14) + 2,
            *v12);
        }
        v3 += 112;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
