__int64 __fastcall qcom_adc_tm5_temp_volt_scale(unsigned int a1, int a2, int a3)
{
  __int64 v3; // x9
  int *v4; // x8
  int v5; // w9
  unsigned __int64 v7; // x9
  int *v8; // x9
  int v9; // w10
  int v10; // w13
  int v11; // w14
  int v12; // w9
  int v13; // w8
  bool v14; // zf

  if ( a1 > 0x13 )
  {
LABEL_23:
    __break(0x5512u);
    JUMPOUT(0x68AC);
  }
  v3 = 0;
  v4 = (int *)&unk_8094;
  while ( *v4 < a3 )
  {
    --v3;
    v4 += 2;
    if ( v3 == -34 )
      goto LABEL_8;
  }
  if ( (_DWORD)v3 )
  {
    if ( -(int)v3 == 34 )
    {
LABEL_8:
      v5 = 46;
    }
    else
    {
      v7 = (unsigned int)~(_DWORD)v3;
      if ( ((8LL * (unsigned int)v7) | 4uLL) > 0x110 || v7 > 0x21 )
        goto LABEL_22;
      v8 = (int *)((char *)&adcmap_100k_104ef_104fb_1875_vref + 8 * (unsigned int)v7);
      v9 = *v8;
      v10 = v8[1];
      if ( a3 == v10 )
      {
        v5 = *v8;
      }
      else
      {
        v11 = *(v4 - 1);
        v5 = *v8;
        if ( v11 != v9 )
        {
          v12 = *v4;
          v13 = *v4 - v10;
          if ( v12 == v10 )
          {
            v5 = v11;
          }
          else
          {
            v14 = v12 == a3;
            v5 = v11;
            if ( !v14 )
              v5 = (v11 - v9) * (a3 - v10) / v13 + v9;
          }
        }
      }
    }
  }
  else
  {
    v5 = 1831;
  }
  if ( a1 == 19 || ((8LL * a1) | 4uLL) > 0x98 )
  {
LABEL_22:
    __break(1u);
    goto LABEL_23;
  }
  return (unsigned int)(1000 * a2 * *((_DWORD *)&adc5_prescale_ratios + 2 * a1))
       * (__int64)v5
       / (1875000LL
        * *((unsigned int *)&adc5_prescale_ratios + 2 * a1 + 1));
}
