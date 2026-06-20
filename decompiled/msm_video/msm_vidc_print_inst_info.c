__int64 __fastcall msm_vidc_print_inst_info(__int64 a1)
{
  __int64 **v1; // x27
  __int64 i; // x23
  __int64 **v4; // kr00_8
  __int64 *j; // x21
  unsigned int v7; // w10
  unsigned int v8; // w11
  const char *v9; // x4
  unsigned int v10; // w23
  _BYTE *v11; // x20
  __int64 k; // x25
  int v13; // w0
  __int64 v14; // x4
  __int64 v15; // x8
  const char *v16; // x3
  const char *v18; // x3
  const char *v19; // x4
  _BYTE s[400]; // [xsp+C8h] [xbp-1D8h] BYREF
  _QWORD v21[9]; // [xsp+258h] [xbp-48h] BYREF

  v21[7] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v21, 0, 56);
  memset(s, 0, sizeof(s));
  if ( a1 && (msm_vidc_debug & 1) != 0 )
  {
    if ( *(_QWORD *)(a1 + 21824) )
      v18 = "Secure";
    else
      v18 = "Non-Secure";
    if ( *(_DWORD *)(a1 + 308) == 2 )
      v19 = "Decode";
    else
      v19 = "Encode";
    printk(&unk_8D8D7, "err ", a1 + 340, v18, v19);
  }
  for ( i = 1; i != 16; ++i )
  {
    v4 = v1;
    v1 = (__int64 **)(a1 + 2504);
    switch ( (int)i )
    {
      case 1:
        goto LABEL_32;
      case 2:
        v1 = (__int64 **)(a1 + 2544);
        if ( a1 == -2544 )
          continue;
        goto LABEL_33;
      case 3:
        v1 = (__int64 **)(a1 + 2624);
        if ( a1 == -2624 )
          continue;
        goto LABEL_33;
      case 4:
        v1 = (__int64 **)(a1 + 2664);
        if ( a1 == -2664 )
          continue;
        goto LABEL_33;
      case 5:
        v1 = (__int64 **)(a1 + 2584);
        if ( a1 == -2584 )
          continue;
        goto LABEL_33;
      case 6:
        continue;
      case 7:
        v1 = (__int64 **)(a1 + 2704);
        if ( a1 == -2704 )
          continue;
        goto LABEL_33;
      case 8:
        v1 = (__int64 **)(a1 + 2744);
        if ( a1 == -2744 )
          continue;
        goto LABEL_33;
      case 9:
        v1 = (__int64 **)(a1 + 2784);
        if ( a1 == -2784 )
          continue;
        goto LABEL_33;
      case 10:
        v1 = (__int64 **)(a1 + 2824);
        if ( a1 == -2824 )
          continue;
        goto LABEL_33;
      case 11:
        v1 = (__int64 **)(a1 + 2864);
LABEL_32:
        if ( v1 )
          goto LABEL_33;
        continue;
      case 12:
        v1 = (__int64 **)(a1 + 2904);
        if ( a1 == -2904 )
          continue;
        goto LABEL_33;
      case 13:
        v1 = (__int64 **)(a1 + 2944);
        if ( a1 == -2944 )
          continue;
        goto LABEL_33;
      case 14:
        v1 = (__int64 **)(a1 + 2984);
        if ( a1 == -2984 )
          continue;
        goto LABEL_33;
      case 15:
        v1 = (__int64 **)(a1 + 3024);
        if ( a1 == -3024 )
          continue;
LABEL_33:
        if ( a1 && (msm_vidc_debug & 1) != 0 )
          printk(&unk_8A80F, "err ", a1 + 340, buf_type_name_arr[i], *((unsigned int *)v1 + 4));
        for ( j = *v1; j != (__int64 *)v1; j = (__int64 *)*j )
        {
          if ( j[11] )
          {
            v7 = *((_DWORD *)j + 7);
            if ( v7 - 1 <= 0x7E && (j[13] && j[12] || (unsigned int)(*((_DWORD *)j + 6) - 7) <= 8) )
            {
              v8 = __clz(v7);
              v21[31 - v8] += *((unsigned int *)j + 10);
            }
            if ( a1 && (msm_vidc_debug & 1) != 0 )
            {
              v9 = "NON_SECURE";
              if ( (v7 & 2) == 0 )
              {
                v9 = "NON_SECURE_BITSTREAM";
                if ( (v7 & 4) == 0 )
                {
                  v9 = "NON_SECURE_PIXEL";
                  if ( (v7 & 8) == 0 )
                  {
                    v9 = "SECURE_PIXEL";
                    if ( (v7 & 0x40) == 0 )
                    {
                      v9 = "SECURE_NONPIXEL";
                      if ( (v7 & 0x10) == 0 )
                      {
                        if ( (v7 & 0x20) != 0 )
                          v9 = "SECURE_BITSTREAM";
                        else
                          v9 = "NONE";
                      }
                    }
                  }
                }
              }
              printk(&unk_868F5, "err ", a1 + 340, buf_type_name_arr[i], v9);
            }
          }
        }
        break;
      default:
        v1 = v4;
        if ( a1 && (msm_vidc_debug & 1) != 0 )
          printk(&unk_9780D, "err ", a1 + 340, "msm_vidc_print_inst_info", (unsigned int)i);
        break;
    }
  }
  v10 = 400;
  v11 = s;
  for ( k = 1; k != 7; ++k )
  {
    v15 = 1LL << k;
    v16 = "NON_SECURE";
    if ( ((1LL << k) & 2) == 0 )
    {
      v16 = "NON_SECURE_BITSTREAM";
      if ( (v15 & 4) == 0 )
      {
        v16 = "NON_SECURE_PIXEL";
        if ( (v15 & 8) == 0 )
        {
          v16 = "SECURE_PIXEL";
          if ( (v15 & 0x40) == 0 )
          {
            v16 = "SECURE_NONPIXEL";
            if ( (v15 & 0x10) == 0 )
            {
              if ( (v15 & 0x20) != 0 )
                v16 = "SECURE_BITSTREAM";
              else
                v16 = "NONE";
            }
          }
        }
      }
    }
    v13 = scnprintf(v11, v10, "%s %lld kb ", v16, v21[k] >> 10);
    v11 += v13;
    v10 -= v13;
  }
  if ( a1 && (msm_vidc_debug & 1) != 0 )
    printk(&unk_8CC6A, "err ", a1 + 340, s, v14);
  _ReadStatusReg(SP_EL0);
  return 0;
}
