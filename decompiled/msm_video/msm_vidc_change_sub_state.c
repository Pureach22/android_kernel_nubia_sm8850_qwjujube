__int64 __fastcall msm_vidc_change_sub_state(__int64 result, unsigned int a2, unsigned int a3, __int64 a4, __int64 a5)
{
  int v5; // w8
  int v6; // w9
  int v7; // w8
  __int64 v8; // x19
  __int64 v9; // x9
  __int64 v10; // x8
  const char *v11; // x4
  __int64 v12; // x19
  unsigned int v13; // w8
  __int64 v14; // x20
  int v16; // w8
  __int64 v17; // x8
  const char *v18; // x4
  void *v19; // x0
  __int64 v20; // x9
  _QWORD v21[17]; // [xsp+8h] [xbp-88h] BYREF

  v21[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_DWORD *)(result + 160);
  if ( v5 != 5 )
  {
    if ( !(a3 | a2) )
      goto LABEL_37;
    if ( a2 > 0x7F || ((a2 | 0xFFFFFF80) & a3) != 0 )
    {
      if ( result && (msm_vidc_debug & 1) != 0 )
      {
        printk(&unk_89E5E, "err ", result + 340, a4, a2);
        result = 4294967274LL;
        goto LABEL_38;
      }
LABEL_30:
      result = 4294967274LL;
      goto LABEL_38;
    }
    v6 = *(_DWORD *)(result + 176);
    if ( !a3 )
    {
      v7 = *(_DWORD *)(result + 176);
      goto LABEL_33;
    }
    memset(v21, 0, 128);
    switch ( v5 )
    {
      case 2:
        if ( (a3 & 0x13) == 0 )
        {
          if ( a3 < 0x40 )
          {
LABEL_32:
            v7 = v6 | a3;
LABEL_33:
            v13 = v7 & ~a2;
            *(_DWORD *)(result + 176) = v13;
            if ( v13 != v6 )
            {
              v14 = result;
              v16 = ((__int64 (__fastcall *)(_QWORD, __int64))prepare_sub_state_name)(v13, result + 180);
              result = 0;
              if ( v14 && !v16 )
              {
                if ( (msm_vidc_debug & 2) != 0 )
                {
                  v17 = *(unsigned int *)(v14 + 160);
                  if ( (unsigned int)v17 <= 5 )
                    v18 = state_name_arr[v17];
                  else
                    v18 = "UNKNOWN STATE";
                  printk(&unk_7FBF2, "high", v14 + 340, a4, v18);
                }
                goto LABEL_37;
              }
              goto LABEL_38;
            }
LABEL_37:
            result = 0;
            goto LABEL_38;
          }
          goto LABEL_28;
        }
        break;
      case 1:
        if ( (a3 & 0x2C) == 0 )
        {
          if ( a3 < 0x80 )
            goto LABEL_32;
          goto LABEL_28;
        }
        break;
      case 0:
        if ( (a3 & 0x3F) == 0 )
          goto LABEL_32;
        break;
      default:
        if ( a3 < 0x40 || (unsigned int)(v5 - 3) >= 2 )
          goto LABEL_32;
LABEL_28:
        v12 = result;
        ((void (__fastcall *)(_QWORD, _QWORD *))prepare_sub_state_name)(a3, v21);
        if ( !v12 || (msm_vidc_debug & 1) == 0 )
          goto LABEL_30;
        v20 = *(unsigned int *)(v12 + 160);
        v10 = v12;
        if ( (unsigned int)v20 <= 5 )
        {
          v19 = &unk_90D8A;
          v11 = state_name_arr[v20];
        }
        else
        {
          v11 = "UNKNOWN STATE";
          v19 = &unk_90D8A;
        }
LABEL_43:
        printk(v19, "err ", v10 + 340, "msm_vidc_change_sub_state", v11);
        goto LABEL_30;
    }
    v8 = result;
    ((void (__fastcall *)(_QWORD, _QWORD *))prepare_sub_state_name)(a3, v21);
    if ( !v8 || (msm_vidc_debug & 1) == 0 )
      goto LABEL_30;
    v9 = *(unsigned int *)(v8 + 160);
    v10 = v8;
    if ( (unsigned int)v9 <= 5 )
      v11 = state_name_arr[v9];
    else
      v11 = "UNKNOWN STATE";
    v19 = &unk_8255C;
    goto LABEL_43;
  }
  if ( result )
  {
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_83982, "high", result + 340, a4, a5);
    goto LABEL_37;
  }
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
