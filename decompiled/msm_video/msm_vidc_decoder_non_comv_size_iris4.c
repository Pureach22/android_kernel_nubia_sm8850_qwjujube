__int64 __fastcall msm_vidc_decoder_non_comv_size_iris4(_DWORD *a1)
{
  int v1; // w9
  int v2; // w8
  unsigned int v3; // w8
  unsigned int v4; // w19
  unsigned int v5; // w8
  unsigned int v6; // w9
  int v7; // w8

  v1 = a1[78];
  v2 = a1[99];
  if ( v1 != 8 && v1 != 2 )
  {
    if ( v1 == 1 )
    {
      v3 = 48 * (((unsigned int)(v2 + 31) >> 4) & 0xFFFFFFE);
      if ( v3 >= 0x708 )
        v3 = 1800;
      v4 = (640 * v3 + 65791) & 0x3FFC00;
      if ( !a1 )
        return v4;
    }
    else
    {
      v4 = 0;
      if ( !a1 )
        return v4;
    }
LABEL_13:
    if ( (msm_vidc_debug & 4) != 0 )
      printk(&unk_8FA63, "low ", a1 + 85, "msm_vidc_decoder_non_comv_size_iris4", v4);
    return v4;
  }
  v5 = (((unsigned int)(v2 + 63) >> 4) & 0xFFFFFFC) * (((unsigned int)(a1[98] + 63) >> 4) & 0xFFFFFFC);
  v6 = 32 * v5;
  v7 = 4 * v5 + 255;
  if ( v6 >= 0x4B1 )
    v6 = 1201;
  v4 = ((v7 & 0xFFFFFF00) + (((v6 << 9) + 1536) & 0xFF800) + (((v6 << 7) + 255) & 0x3FF00) + 126207) & 0xFFFFFF00;
  if ( a1 )
    goto LABEL_13;
  return v4;
}
