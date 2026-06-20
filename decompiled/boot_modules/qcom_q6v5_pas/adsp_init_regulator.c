__int64 __fastcall adsp_init_regulator(_QWORD *a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  int string_helper; // w8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x23
  __int64 v8; // x20
  int v9; // w0
  __int64 result; // x0
  __int64 v11; // x8
  unsigned int v12; // w19
  const char *v13; // [xsp+8h] [xbp-58h] BYREF
  int v14; // [xsp+14h] [xbp-4Ch] BYREF
  __int64 v15; // [xsp+18h] [xbp-48h] BYREF
  char s[8]; // [xsp+20h] [xbp-40h] BYREF
  __int64 v17; // [xsp+28h] [xbp-38h]
  __int64 v18; // [xsp+30h] [xbp-30h]
  __int64 v19; // [xsp+38h] [xbp-28h]
  __int64 v20; // [xsp+40h] [xbp-20h]
  __int64 v21; // [xsp+48h] [xbp-18h]
  __int16 v22; // [xsp+50h] [xbp-10h]
  __int64 v23; // [xsp+58h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v14 = 0;
  v22 = 0;
  v3 = *(_QWORD *)(v2 + 744);
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  *(_QWORD *)s = 0;
  v17 = 0;
  v15 = 0;
  v13 = nullptr;
  string_helper = of_property_read_string_helper(v3, "reg-names", 0, 0, 0);
  v5 = *a1;
  *((_DWORD *)a1 + 102) = string_helper;
  if ( string_helper <= 0 )
  {
    dev_err(v5, "No regulators added!\n");
LABEL_15:
    result = 0;
    goto LABEL_16;
  }
  v6 = devm_kmalloc(v5, 16LL * (unsigned int)string_helper, 3520);
  a1[50] = v6;
  if ( v6 )
  {
    if ( *((int *)a1 + 102) >= 1 )
    {
      v7 = 0;
      v8 = 0;
      while ( 1 )
      {
        of_property_read_string_helper(*(_QWORD *)(*a1 + 744LL), "reg-names", &v13, 1, (unsigned int)v8);
        *(_QWORD *)(a1[50] + v7) = devm_regulator_get(*a1, v13);
        if ( *(_QWORD *)(a1[50] + v7) >= 0xFFFFFFFFFFFFF001LL )
        {
          dev_err(*a1, "failed to get %s reg\n", v13);
          result = *(unsigned int *)(a1[50] + v7);
          goto LABEL_16;
        }
        snprintf(s, 0x32u, "%s-uV-uA", v13);
        if ( of_find_property(*(_QWORD *)(*a1 + 744LL), s, &v14) )
        {
          v9 = of_property_read_variable_u32_array(*(_QWORD *)(*a1 + 744LL), s, &v15, 2, 0);
          if ( v9 < 0 )
          {
            v11 = *a1;
            v12 = v9;
            dev_err(v11, "Failed to read uVuA value(rc:%d)\n", v9);
            result = v12;
            goto LABEL_16;
          }
          if ( (_DWORD)v15 )
            *(_DWORD *)(a1[50] + v7 + 8) = v15;
          if ( HIDWORD(v15) )
            *(_DWORD *)(a1[50] + v7 + 12) = HIDWORD(v15);
        }
        ++v8;
        v7 += 16;
        if ( v8 >= *((int *)a1 + 102) )
          goto LABEL_15;
      }
    }
    goto LABEL_15;
  }
  result = 4294967284LL;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
