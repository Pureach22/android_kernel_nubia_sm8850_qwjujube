__int64 __fastcall lpass_cdc_update_wcd_event(_QWORD *a1, unsigned __int16 a2)
{
  int v2; // w19
  void (__fastcall *v3)(__int64, __int64); // x8
  __int64 v4; // x0
  __int64 v5; // x1

  if ( !a1 )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_update_wcd_event__rs, "lpass_cdc_update_wcd_event") )
      printk(&unk_D22A, "lpass_cdc_update_wcd_event");
    return 4294967274LL;
  }
  v2 = a2;
  if ( a2 <= 4u )
  {
    if ( a2 > 2u )
    {
      if ( a2 == 3 )
      {
        v3 = (void (__fastcall *)(__int64, __int64))a1[49];
        if ( v3 )
        {
          v4 = a1[1];
          v5 = 3;
          goto LABEL_32;
        }
        return 0;
      }
      if ( a2 == 4 )
      {
        v3 = (void (__fastcall *)(__int64, __int64))a1[49];
        if ( v3 )
        {
          v4 = a1[1];
          v5 = 9;
          goto LABEL_32;
        }
        return 0;
      }
    }
    else
    {
      if ( a2 == 1 )
      {
        v3 = (void (__fastcall *)(__int64, __int64))a1[49];
        if ( v3 )
        {
          v4 = a1[1];
          v5 = 1;
          goto LABEL_32;
        }
        return 0;
      }
      if ( a2 == 2 )
      {
        v3 = (void (__fastcall *)(__int64, __int64))a1[49];
        if ( v3 )
        {
          v4 = a1[1];
          v5 = 2;
LABEL_32:
          if ( *((_DWORD *)v3 - 1) != -511372407 )
            __break(0x8228u);
          v3(v4, v5);
          return 0;
        }
        return 0;
      }
    }
    goto LABEL_36;
  }
  if ( a2 > 6u )
  {
    if ( a2 == 7 )
    {
      v3 = (void (__fastcall *)(__int64, __int64))a1[49];
      if ( v3 )
      {
        v4 = a1[1];
        v5 = 14;
        goto LABEL_32;
      }
      return 0;
    }
    if ( a2 == 8 )
    {
      v3 = (void (__fastcall *)(__int64, __int64))a1[49];
      if ( v3 )
      {
        v4 = a1[1];
        v5 = 15;
        goto LABEL_32;
      }
      return 0;
    }
    goto LABEL_36;
  }
  if ( a2 == 5 )
  {
    v3 = (void (__fastcall *)(__int64, __int64))a1[35];
    if ( v3 )
    {
      v4 = a1[1];
      v5 = 10;
      goto LABEL_32;
    }
    return 0;
  }
  if ( a2 != 6 )
  {
LABEL_36:
    if ( (unsigned int)__ratelimit(&lpass_cdc_update_wcd_event__rs_89, "lpass_cdc_update_wcd_event") )
      dev_err(*a1, "%s: Invalid event %d trigger from wcd\n", "lpass_cdc_update_wcd_event", v2);
    return 4294967274LL;
  }
  v3 = (void (__fastcall *)(__int64, __int64))a1[49];
  if ( v3 )
  {
    v4 = a1[1];
    v5 = 13;
    goto LABEL_32;
  }
  return 0;
}
