__int64 __fastcall msm_vidc_encoder_dpb_size_iris4(_DWORD *a1)
{
  int v1; // w10
  int v2; // w9
  unsigned int v3; // w8
  unsigned int v4; // w19
  int v5; // w10

  v1 = a1[78];
  v2 = a1[150];
  v3 = a1[151];
  if ( v1 != 8 && v1 != 2 )
  {
    if ( v1 != 1 )
    {
      v4 = 0;
      if ( !a1 )
        return v4;
      goto LABEL_15;
    }
    goto LABEL_4;
  }
  v5 = a1[4532];
  if ( v5 > 127 )
  {
    if ( v5 != 128 && v5 != 256 )
    {
LABEL_4:
      v4 = ((((((v3 + 7) >> 2) + 30) & 0x7FFFFFE0) * ((((unsigned int)(v2 + 31) >> 5) + 63) & 0xFFFFFC0) + 8190)
          & 0xFFFFE000)
         + ((((v3 >> 1) + 31) & 0xFFFFFFE0) + ((v3 + 31) & 0xFFFFFFE0)) * ((v2 + 127) & 0xFFFFFF80);
      if ( !a1 )
        return v4;
      goto LABEL_15;
    }
  }
  else if ( v5 != 8 && v5 != 16 )
  {
    goto LABEL_4;
  }
  v4 = ((((((v3 + 3) >> 1) + 30) & 0xFFFFFFE0) * (((v2 + 47) / 0x30u + 63) & 0xFFFFFC0) + 8190) & 0xFFFFE000)
     + ((((2 * ((2863311531u * (unsigned __int64)(192 * ((v2 + 191) / 0xC0u))) >> 32)) & 0xFFFFFFFC) + 127) & 0xFFFFFF80)
     * (((((v3 + 1) >> 1) + 31) & 0xFFFFFFE0) + ((v3 + 31) & 0xFFFFFFE0));
  if ( !a1 )
    return v4;
LABEL_15:
  if ( (msm_vidc_debug & 4) != 0 )
    printk(&unk_8FA63, "low ", a1 + 85, "msm_vidc_encoder_dpb_size_iris4", v4);
  return v4;
}
