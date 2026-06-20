char *__fastcall _cam_isp_ctx_convert_hw_id_to_string(char *result, int a2)
{
  char *v3; // x19
  int v4; // w22
  int v5; // w21
  char s[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v7; // [xsp+10h] [xbp-20h]
  _WORD v8[7]; // [xsp+18h] [xbp-18h] BYREF
  __int64 v9; // [xsp+28h] [xbp-8h]

  v3 = result;
  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a2 & 1) != 0 )
  {
    v5 = 5;
    v4 = 1;
    strcpy(result, "IFE0 ");
  }
  else
  {
    v4 = 0;
    v5 = 0;
  }
  v7 = 0;
  memset(v8, 0, sizeof(v8));
  *(_QWORD *)s = 0;
  if ( (a2 & 2) != 0 )
  {
    result = (char *)snprintf(&result[v5], 8LL - (unsigned int)v5, "IFE1 ");
    ++v4;
    v5 += (int)result;
    if ( (a2 & 0x100) == 0 )
    {
LABEL_6:
      if ( (a2 & 4) == 0 )
        goto LABEL_7;
      goto LABEL_19;
    }
  }
  else if ( (a2 & 0x100) == 0 )
  {
    goto LABEL_6;
  }
  result = (char *)snprintf(&v3[v5], 8LL - v5, "IFE2 ");
  ++v4;
  v5 += (int)result;
  if ( (a2 & 4) == 0 )
  {
LABEL_7:
    if ( (a2 & 8) == 0 )
      goto LABEL_8;
    goto LABEL_20;
  }
LABEL_19:
  result = (char *)snprintf(&v3[v5], 8LL - v5, "IFE0_LITE ");
  ++v4;
  v5 += (int)result;
  if ( (a2 & 8) == 0 )
  {
LABEL_8:
    if ( (a2 & 0x10) == 0 )
      goto LABEL_9;
    goto LABEL_21;
  }
LABEL_20:
  result = (char *)snprintf(&v3[v5], 8LL - v5, "IFE1_LITE ");
  ++v4;
  v5 += (int)result;
  if ( (a2 & 0x10) == 0 )
  {
LABEL_9:
    if ( (a2 & 0x20) == 0 )
      goto LABEL_10;
    goto LABEL_22;
  }
LABEL_21:
  result = (char *)snprintf(&v3[v5], 8LL - v5, "IFE2_LITE ");
  ++v4;
  v5 += (int)result;
  if ( (a2 & 0x20) == 0 )
  {
LABEL_10:
    if ( (a2 & 0x40) == 0 )
      goto LABEL_11;
    goto LABEL_23;
  }
LABEL_22:
  result = (char *)snprintf(&v3[v5], 8LL - v5, "IFE3_LITE ");
  ++v4;
  v5 += (int)result;
  if ( (a2 & 0x40) == 0 )
  {
LABEL_11:
    if ( (a2 & 0x1000) == 0 )
      goto LABEL_12;
    goto LABEL_24;
  }
LABEL_23:
  result = (char *)snprintf(&v3[v5], 8LL - v5, "IFE4_LITE ");
  ++v4;
  v5 += (int)result;
  if ( (a2 & 0x1000) == 0 )
  {
LABEL_12:
    if ( (a2 & 0x2000) == 0 )
      goto LABEL_13;
    goto LABEL_25;
  }
LABEL_24:
  result = (char *)snprintf(&v3[v5], 8LL - v5, "SFE0 ");
  ++v4;
  v5 += (int)result;
  if ( (a2 & 0x2000) == 0 )
  {
LABEL_13:
    if ( (a2 & 0x4000) == 0 )
      goto LABEL_15;
    goto LABEL_14;
  }
LABEL_25:
  result = (char *)snprintf(&v3[v5], 8LL - v5, "SFE1 ");
  ++v4;
  v5 += (int)result;
  if ( (a2 & 0x4000) != 0 )
  {
LABEL_14:
    result = (char *)snprintf(&v3[v5], 8LL - v5, "SFE2 ");
    ++v4;
    v5 += (int)result;
  }
LABEL_15:
  if ( (unsigned int)(v4 - 3) > 0xFFFFFFFD )
  {
    if ( v4 == 2 )
    {
      snprintf(s, 0x1Eu, "Dual: %s", v3);
      result = (char *)snprintf(v3, 8u, "%s", s);
      v5 = (int)result;
    }
    if ( (unsigned int)(v5 - 1) <= 6 )
      v3[v5 - 1] = 0;
  }
  else
  {
    result = (char *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       3,
                       8,
                       2,
                       "__cam_isp_ctx_convert_hw_id_to_string",
                       8855,
                       "Wrong hw id, hw id: 0x%x, num_hw: %d",
                       a2,
                       v4);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
