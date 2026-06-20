__int64 __fastcall msm_vidc_adjust_ltr_count(__int64 a1, __int64 a2)
{
  unsigned int v3; // w20
  __int64 v4; // x4
  int v5; // w8
  int v7; // w8
  unsigned __int64 v8; // x8
  unsigned int v9; // w8
  unsigned int v10; // w8
  bool v11; // cf
  unsigned int v12; // w8

  if ( a2 )
    v3 = *(_DWORD *)(a2 + 196);
  else
    v3 = *(_DWORD *)(a1 + 11744);
  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
          a1,
          44,
          119,
          "msm_vidc_adjust_ltr_count")
      & 1) == 0 )
    return 4294967274LL;
  v4 = *(unsigned int *)(a1 + 1828);
  if ( (unsigned int)v4 <= 4 && ((1 << v4) & 0x1A) != 0 )
  {
    if ( (is_valid_cap(a1, 70) & 1) == 0 )
      goto LABEL_10;
    if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
            a1,
            44,
            70,
            "msm_vidc_adjust_ltr_count")
        & 1) != 0 )
    {
      if ( !*(_QWORD *)(a1 + 16112) )
      {
LABEL_10:
        if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
                a1,
                44,
                82,
                "msm_vidc_adjust_ltr_count")
            & 1) == 0 )
          goto LABEL_22;
        v5 = *(_DWORD *)(a1 + 18128);
        if ( v5 > 127 )
        {
          if ( v5 != 256 && v5 != 128 )
          {
LABEL_22:
            if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
                    a1,
                    44,
                    65,
                    "msm_vidc_adjust_ltr_count")
                & 1) != 0
              && (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
                    a1,
                    44,
                    139,
                    "msm_vidc_adjust_ltr_count")
                & 1) != 0 )
            {
              if ( *(_DWORD *)(a1 + 1832) == 1 )
              {
                v7 = *(_DWORD *)(a1 + 312);
                if ( v7 == 1 )
                {
                  v8 = *(_QWORD *)(a1 + 15272);
                  if ( (__int64)(v8 + 1) > 3 )
                    LODWORD(v8) = v8 + 1;
                }
                else if ( v7 == 2 )
                {
                  v8 = (unsigned __int64)(*(_QWORD *)(a1 + 15272) + 2LL) >> 1;
                }
                else
                {
                  LODWORD(v8) = 0;
                }
                v9 = v8 + v3;
                if ( v9 >= 8 )
                {
                  v10 = v9 - 7;
                  v11 = v3 >= v10;
                  v12 = v3 - v10;
                  if ( v11 )
                    v3 = v12;
                  else
                    v3 = 0;
                }
              }
              if ( a1 )
              {
                if ( (msm_vidc_debug & 2) != 0 )
                  printk(&unk_84977, "high", a1 + 340, "msm_vidc_adjust_ltr_count", v3);
              }
            }
            goto LABEL_39;
          }
        }
        else if ( v5 != 8 && v5 != 16 )
        {
          goto LABEL_22;
        }
        v3 = 0;
        goto LABEL_22;
      }
      goto LABEL_18;
    }
    return 4294967274LL;
  }
  if ( a1 && (msm_vidc_debug & 2) != 0 )
  {
    printk(&unk_96881, "high", a1 + 340, "msm_vidc_adjust_ltr_count", v4);
    v3 = 0;
    goto LABEL_39;
  }
LABEL_18:
  v3 = 0;
LABEL_39:
  ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
    a1,
    44,
    (int)v3,
    "msm_vidc_adjust_ltr_count");
  return 0;
}
