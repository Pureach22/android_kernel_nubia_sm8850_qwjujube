__int64 __fastcall msm_vidc_decoder_comv_size_iris4(__int64 a1)
{
  unsigned int v1; // w21
  unsigned int v3; // w20
  char is_greater_than; // w0
  int v5; // w8
  unsigned int v6; // w22
  unsigned int v7; // w8
  int v8; // w9
  __int64 result; // x0
  unsigned int v10; // w9
  unsigned int v11; // w9
  __int64 v12; // x2
  unsigned int v13; // w19

  v1 = *(_DWORD *)(a1 + 392);
  v3 = *(_DWORD *)(a1 + 396);
  if ( *(_DWORD *)(a1 + 312) == 16 )
  {
    is_greater_than = res_is_greater_than(v1, v3, 4096, 2176);
    v5 = *(_DWORD *)(a1 + 38716);
    if ( (is_greater_than & 1) != 0 )
    {
      if ( !v5 )
        v5 = *(_DWORD *)(a1 + 2560);
      v6 = v5 + 3;
    }
    else
    {
      if ( !v5 )
        v5 = *(_DWORD *)(a1 + 2560);
      v6 = v5 + 7;
    }
  }
  else
  {
    v6 = *(_DWORD *)(a1 + 2560);
  }
  ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
    a1,
    190,
    v6,
    "msm_vidc_decoder_comv_size_iris4");
  if ( *(_BYTE *)(a1 + 3792) == 1 )
    v7 = *(_DWORD *)(a1 + 3796) + 1;
  else
    v7 = 3;
  v8 = *(_DWORD *)(a1 + 312);
  result = 0;
  if ( v7 <= v6 )
    v7 = v6;
  if ( v8 <= 7 )
  {
    if ( v8 == 1 )
    {
      v10 = ((((((v1 + 15) >> 4) * ((((v3 + 15) >> 4) + 1) >> 1)) << 8) + 511) & 0xFFFFFE00)
          + ((((((((v3 + 15) >> 4) + 1) & 0x1FFFFFFE) * ((4 * ((v1 + 15) >> 4) + 15) & 0x7FFFFFF0) + 126) & 0xFFFFFF80)
            + 511)
           & 0xFFFFFE00)
          + 512;
      goto LABEL_26;
    }
    if ( v8 != 2 )
    {
LABEL_27:
      if ( !a1 )
        return result;
      goto LABEL_28;
    }
LABEL_24:
    v10 = (((16 * v1 + 240) & 0xFFFFFF00) * ((v3 + 15) >> 4) + 511) & 0xFFFFFE00;
LABEL_26:
    result = v7 * v10 + 512;
    goto LABEL_27;
  }
  if ( v8 == 8 )
    goto LABEL_24;
  if ( v8 != 16 )
    goto LABEL_27;
  if ( *(_QWORD *)(a1 + 34424) )
  {
    result = 0;
    if ( !a1 )
      return result;
    goto LABEL_28;
  }
  v11 = 2816 * ((v1 + 127) >> 7) * ((v3 + 127) >> 7);
  if ( ((8 * v1 + 504) & 0xFFFFFE00) * ((v3 + 63) >> 6) > v11 )
    v11 = ((8 * v1 + 504) & 0xFFFFFE00) * ((v3 + 63) >> 6);
  result = 2 * v11 * v7;
  if ( a1 )
  {
LABEL_28:
    if ( (msm_vidc_debug & 4) != 0 )
    {
      v12 = a1 + 340;
      v13 = result;
      printk(&unk_8FA63, "low ", v12, "msm_vidc_decoder_comv_size_iris4", (unsigned int)result);
      return v13;
    }
  }
  return result;
}
