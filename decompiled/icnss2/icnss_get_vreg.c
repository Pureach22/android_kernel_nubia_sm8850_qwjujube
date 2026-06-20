__int64 __fastcall icnss_get_vreg(_QWORD *a1)
{
  __int64 v2; // x20
  char **v3; // x24
  unsigned __int64 v4; // x25
  __int64 v5; // x23
  __int64 v6; // x28
  _QWORD *v7; // x26
  unsigned int v8; // w22
  _QWORD *v9; // x0
  char **v10; // x8
  __int64 v11; // x20
  _QWORD *v12; // x21
  char *v13; // x9
  char *v14; // x10
  char *v15; // x8
  char *v16; // x11
  unsigned __int64 optional; // x0
  const char *v18; // x3
  unsigned int *property; // x22
  signed int v20; // w8
  int v21; // w20
  const char *v22; // x3
  _QWORD *v23; // x1
  const char *v24; // x20
  __int64 v26; // [xsp+8h] [xbp-38h]
  unsigned int v27; // [xsp+14h] [xbp-2Ch] BYREF
  char s[8]; // [xsp+18h] [xbp-28h] BYREF
  __int64 v29; // [xsp+20h] [xbp-20h]
  __int64 v30; // [xsp+28h] [xbp-18h]
  __int64 v31; // [xsp+30h] [xbp-10h]
  __int64 v32; // [xsp+38h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[38];
  v26 = a1[1];
  if ( v2 > 30543 )
  {
    if ( v2 == 30544 )
    {
      v3 = &icnss_wcn7750_vreg_list;
      goto LABEL_10;
    }
    if ( v2 == 43981 )
    {
      v3 = &icnss_adrestea_vreg_list;
      goto LABEL_10;
    }
LABEL_12:
    printk("%sUnsupported device_id 0x%lx\n", byte_130B32, v2);
    ipc_log_string(icnss_ipc_log_context, "%sUnsupported device_id 0x%lx\n", (const char *)&unk_12DBF3, v2);
    v8 = -22;
    goto LABEL_54;
  }
  if ( v2 != 25680 )
  {
    if ( v2 == 26448 )
    {
      v3 = &icnss_wcn6750_vreg_list;
LABEL_10:
      v4 = 160;
      v5 = 5;
      goto LABEL_11;
    }
    goto LABEL_12;
  }
  v3 = &icnss_wcn6450_vreg_list;
  v4 = 224;
  v5 = 7;
LABEL_11:
  v6 = 0;
  v7 = a1 + 27;
  while ( 1 )
  {
    v9 = (_QWORD *)devm_kmalloc(v26 + 16, 64, 3520);
    if ( !v9 )
    {
      v8 = -12;
      goto LABEL_54;
    }
    if ( v4 <= 32 * v6 )
      _fortify_panic(16, 40, 32);
    v10 = &v3[4 * v6];
    v11 = a1[1];
    v12 = v9;
    v30 = 0;
    v31 = 0;
    v13 = *v10;
    v14 = v10[1];
    *(_QWORD *)s = 0;
    v29 = 0;
    v16 = v10[2];
    v15 = v10[3];
    v27 = 0;
    v9[3] = v13;
    v9[4] = v14;
    v9[5] = v16;
    v9[6] = v15;
    optional = devm_regulator_get_optional(v11 + 16, v13);
    if ( optional < 0xFFFFFFFFFFFFF001LL )
    {
      v18 = (const char *)v12[3];
      v12[2] = optional;
      snprintf(s, 0x20u, "qcom,%s-config", v18);
      property = (unsigned int *)of_get_property(*(_QWORD *)(v11 + 760), s, &v27);
      ipc_log_string(icnss_ipc_log_context, "Got regulator config, prop: %s, len: %d\n", s, v27);
      if ( !property || (v20 = v27, v27 < 8) )
      {
        if ( property )
          v22 = "invalid format";
        else
          v22 = "doesn't exist";
        ipc_log_string(icnss_ipc_log_context, "Property %s %s, use default\n", s, v22);
        goto LABEL_45;
      }
      v21 = 0;
      while ( 1 )
      {
        if ( v21 <= 1 )
        {
          if ( v21 )
          {
            if ( v21 != 1 )
              goto LABEL_39;
            *((_DWORD *)v12 + 9) = bswap32(property[1]);
          }
          else
          {
            *((_DWORD *)v12 + 8) = bswap32(*property);
          }
        }
        else
        {
          switch ( v21 )
          {
            case 2:
              *((_DWORD *)v12 + 10) = bswap32(property[2]);
              break;
            case 3:
              *((_DWORD *)v12 + 11) = bswap32(property[3]);
              break;
            case 4:
              if ( (a1[38] | 0x1000LL) == 0x7750 )
                *((_DWORD *)v12 + 12) = bswap32(property[4]);
              else
                *((_DWORD *)v12 + 12) = 0;
              break;
            default:
LABEL_39:
              ipc_log_string(icnss_ipc_log_context, "Property %s, ignoring value at %d\n", s, v21);
              v20 = v27;
              break;
          }
        }
        if ( v20 <= (unsigned __int64)(4LL * ++v21) )
          goto LABEL_45;
      }
    }
    if ( (_DWORD)optional != -19 )
      break;
LABEL_14:
    if ( ++v6 == v5 )
    {
      v8 = 0;
      goto LABEL_54;
    }
  }
  if ( (_DWORD)optional == -517 )
  {
    printk("%sEPROBE_DEFER for regulator: %s\n", byte_13289B, (const char *)v12[3]);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sEPROBE_DEFER for regulator: %s\n",
      (const char *)&unk_12DBF3,
      (const char *)v12[3]);
    v8 = -517;
    goto LABEL_54;
  }
  if ( a1[38] != 43981 )
  {
    v8 = optional;
    v24 = "%sFailed to get regulator %s, err = %d\n";
    printk("%sFailed to get regulator %s, err = %d\n", byte_130B32, v12[3], (unsigned int)optional);
    goto LABEL_51;
  }
  if ( (*((_BYTE *)v12 + 52) & 1) == 0 )
  {
    ipc_log_string(icnss_ipc_log_context, "Optional regulator %s doesn't exist: %d\n", (const char *)v12[3], optional);
LABEL_45:
    ipc_log_string(
      icnss_ipc_log_context,
      "Got regulator: %s, min_uv: %u, max_uv: %u, load_ua: %u, delay_us: %u, need_unvote: %u\n",
      (const char *)v12[3],
      *((_DWORD *)v12 + 8),
      *((_DWORD *)v12 + 9),
      *((_DWORD *)v12 + 10),
      *((_DWORD *)v12 + 11),
      *((_DWORD *)v12 + 12));
    v23 = (_QWORD *)a1[28];
    if ( v12 == v7 || v23 == v12 || (_QWORD *)*v23 != v7 )
    {
      _list_add_valid_or_report(v12, v23);
    }
    else
    {
      a1[28] = v12;
      *v12 = v7;
      v12[1] = v23;
      *v23 = v12;
    }
    goto LABEL_14;
  }
  v8 = optional;
  v24 = "%sRegulator %s doesn't exist: %d\n";
  printk("%sRegulator %s doesn't exist: %d\n", byte_130B32, v12[3], (unsigned int)optional);
LABEL_51:
  ipc_log_string(icnss_ipc_log_context, v24, &unk_12DBF3, v12[3], v8);
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return v8;
}
