const char *__fastcall _cam_isp_ctx_notify_cpas(const char *result, unsigned int a2)
{
  const char *v3; // x19
  __int64 v4; // x22
  const char *v5; // x8
  __int64 v6; // x21
  const char *v7; // x8
  const char *v8; // x5
  const char *v9; // x8
  char v10; // w23
  __int64 v11; // x0
  __int64 v12; // x24
  const char *v13; // x22
  const char *v14; // x0
  char s[8]; // [xsp+18h] [xbp-88h] BYREF
  __int64 v16; // [xsp+20h] [xbp-80h]
  __int64 v17; // [xsp+28h] [xbp-78h]
  __int64 v18; // [xsp+30h] [xbp-70h]
  __int64 v19; // [xsp+38h] [xbp-68h]
  __int64 v20; // [xsp+40h] [xbp-60h]
  __int64 v21; // [xsp+48h] [xbp-58h]
  __int64 v22; // [xsp+50h] [xbp-50h]
  __int64 v23; // [xsp+58h] [xbp-48h]
  __int64 v24; // [xsp+60h] [xbp-40h]
  __int64 v25; // [xsp+68h] [xbp-38h]
  __int64 v26; // [xsp+70h] [xbp-30h]
  __int64 v27; // [xsp+78h] [xbp-28h]
  __int64 v28; // [xsp+80h] [xbp-20h]
  __int64 v29; // [xsp+88h] [xbp-18h]
  __int64 v30; // [xsp+90h] [xbp-10h]
  __int64 v31; // [xsp+98h] [xbp-8h]

  v3 = result;
  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *((_QWORD *)result + 32);
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  *(_QWORD *)s = 0;
  v16 = 0;
  if ( a2 == 4 )
  {
    v9 = *((const char **)result + 16);
    if ( v9 == result + 128 )
      v6 = 0;
    else
      v6 = *((_QWORD *)v9 + 3);
    v8 = "EOF";
    goto LABEL_22;
  }
  if ( a2 == 3 )
  {
    v7 = *((const char **)result + 20);
    if ( v7 == result + 160 )
    {
      if ( *((const char **)result + 16) == result + 128 )
      {
        v6 = 0;
        goto LABEL_10;
      }
      v7 = *((const char **)result + 17);
    }
    v6 = *((_QWORD *)v7 + 3);
LABEL_10:
    v8 = "EPOCH";
    goto LABEL_22;
  }
  if ( a2 != 1 )
    goto LABEL_26;
  v5 = *((const char **)result + 20);
  if ( v5 == result + 160 )
    v6 = 0;
  else
    v6 = *((_QWORD *)v5 + 3);
  if ( *(_DWORD *)(v4 + 20) == 2 && *((const char **)result + 16) != result + 128 )
  {
    v8 = "SOF";
    v6 = *(_QWORD *)(*((_QWORD *)result + 17) + 24LL);
    if ( (debug_mdl & 8) == 0 || debug_priority )
      goto LABEL_22;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_notify_cpas",
      10319,
      "EPCR notify cpas");
  }
  v8 = "SOF";
LABEL_22:
  snprintf(s, 0x80u, "%s_frame[%llu]_%s", v3 + 276, *(_QWORD *)(v4 + 8), v8);
  v10 = debug_mdl;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v11 = _cam_isp_ctx_substate_val_to_type(*(unsigned int *)(v4 + 20));
    v12 = *(_QWORD *)(v4 + 8);
    v13 = (const char *)v11;
    v14 = (const char *)cam_isp_hw_evt_type_to_string_0(a2);
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v10 & 8,
      4,
      "__cam_isp_ctx_notify_cpas",
      10356,
      "Substate[%s] ctx: %s frame: %llu evt: %s req: %llu",
      v13,
      v3 + 276,
      v12,
      v14,
      v6);
  }
  result = (const char *)cam_cpas_notify_event((__int64)s, v6);
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
