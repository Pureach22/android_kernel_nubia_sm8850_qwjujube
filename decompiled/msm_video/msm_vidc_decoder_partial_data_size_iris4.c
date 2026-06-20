__int64 __fastcall msm_vidc_decoder_partial_data_size_iris4(_DWORD *a1)
{
  int v1; // w8
  int v2; // w11
  unsigned int v3; // w10
  unsigned int v4; // w15
  unsigned int v5; // w13
  unsigned int v6; // w12
  unsigned int v7; // w8
  unsigned int v8; // w10
  unsigned int v9; // w8
  unsigned int v10; // w19

  if ( a1[78] != 16 )
  {
    v10 = 0;
    if ( !a1 )
      return v10;
    goto LABEL_8;
  }
  v1 = a1[99];
  v2 = a1[98];
  v3 = (unsigned int)(v1 + 1) >> 1;
  v4 = (unsigned int)(v2 + 1) >> 1;
  v5 = ((((((unsigned int)(v2 + 31) >> 5) + 63) & 0xFFFFFC0) * ((((unsigned int)(v1 + 7) >> 3) + 15) & 0x3FFFFFF0) + 4095)
      & 0xFFFFF000)
     + (((v3 + 31) & 0xFFFFFFE0) + ((v1 + 31) & 0xFFFFFFE0)) * ((v2 + 127) & 0xFFFFFF80);
  v6 = (((v3 + 3) >> 2) + 15) & 0x7FFFFFF0;
  v7 = (((((v2 + 47) / 0x30u + 63) & 0xFFFFFC0) * ((((unsigned int)(v1 + 3) >> 2) + 15) & 0x7FFFFFF0) + 4095)
      & 0xFFFFF000)
     + ((768 * ((v2 + 191) / 0xC0u) / 3 + 255) & 0x7FFFFF00) * (((v3 + 15) & 0xFFFFFFF0) + ((v1 + 15) & 0xFFFFFFF0));
  v8 = v5 + ((((((v4 + 15) >> 4) + 63) & 0x1FFFFFC0) * ((((v3 + 7) >> 3) + 15) & 0x3FFFFFF0) + 4095) & 0xFFFFF000);
  v9 = v7 + (((((v4 + 23) / 0x18 + 63) & 0x1FFFFFC0) * v6 + 4095) & 0xFFFFF000);
  if ( v8 <= v9 )
    v10 = v9;
  else
    v10 = v8;
  if ( a1 )
  {
LABEL_8:
    if ( (msm_vidc_debug & 4) != 0 )
      printk(&unk_8FA63, "low ", a1 + 85, "msm_vidc_decoder_partial_data_size_iris4", v10);
  }
  return v10;
}
