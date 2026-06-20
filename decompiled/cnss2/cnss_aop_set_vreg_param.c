__int64 __fastcall cnss_aop_set_vreg_param(__int64 a1, const char *a2, unsigned int a3, unsigned int a4, int a5)
{
  int v5; // w8
  __int64 v11; // x26
  const char *v12; // x24
  size_t v13; // x0
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  const char *v16; // x1
  __int16 v17; // w9
  const char *v18; // x8
  __int64 v19; // x2
  __int64 v20; // x3
  __int64 v21; // x4
  __int64 v22; // x5
  __int64 v23; // x6
  __int64 v24; // x7
  char v25; // [xsp+0h] [xbp-50h]
  char s[8]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v27; // [xsp+10h] [xbp-40h]
  __int64 v28; // [xsp+18h] [xbp-38h]
  __int64 v29; // [xsp+20h] [xbp-30h]
  __int64 v30; // [xsp+28h] [xbp-28h]
  __int64 v31; // [xsp+30h] [xbp-20h]
  __int64 v32; // [xsp+38h] [xbp-18h]
  __int64 v33; // [xsp+40h] [xbp-10h]
  __int64 v34; // [xsp+48h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v5 = *(_DWORD *)(a1 + 7700);
    v32 = 0;
    v33 = 0;
    v30 = 0;
    v31 = 0;
    v28 = 0;
    v29 = 0;
    *(_QWORD *)s = 0;
    v27 = 0;
    if ( v5 >= 1 && *(_QWORD *)(a1 + 7680) )
    {
      v11 = 0;
      v12 = "rf";
      while ( 1 )
      {
        v13 = strlen(*(const char **)(*(_QWORD *)(a1 + 7680) + 8 * v11));
        if ( strnstr(*(_QWORD *)(*(_QWORD *)(a1 + 7680) + 8 * v11), a2, v13) )
          break;
        if ( ++v11 >= (unsigned __int64)*(unsigned int *)(a1 + 7700) )
          goto LABEL_11;
      }
      v12 = *(const char **)(*(_QWORD *)(a1 + 7680) + 8 * v11 + 8);
    }
    else
    {
      v12 = "rf";
    }
LABEL_11:
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v16 = "irq";
    }
    else
    {
      v17 = *(_DWORD *)(StatusReg + 16);
      v18 = (const char *)(StatusReg + 2320);
      if ( (v17 & 0xFF00) != 0 )
        v16 = "soft_irq";
      else
        v16 = v18;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v16,
      "cnss_aop_pdc_name_str",
      7u,
      7u,
      "%s mapped to %s\n",
      (__int64)a2,
      (__int64)v12,
      v25);
    if ( a3 > 2 || a4 > 2 )
      __break(1u);
    snprintf(
      s,
      0x40u,
      "{class: wlan_pdc, ss: %s, res: %s.%s, %s: %d}",
      v12,
      a2,
      cnss_aop_set_vreg_param_aop_vreg_param_str[a3],
      cnss_aop_set_vreg_param_aop_tcs_seq_str[a4],
      a5);
    result = cnss_aop_send_msg(a1, s, v19, v20, v21, v22, v23, v24);
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
