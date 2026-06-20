__int64 __fastcall msm_vidc_encoder_comv_size_iris4(__int64 a1)
{
  int v1; // w21
  int v2; // w22
  int v3; // w20
  int recon_buf_count; // w0
  int v6; // w8
  unsigned int v7; // w9
  unsigned int v8; // w8
  unsigned int v9; // w9
  unsigned int v10; // w8
  int v11; // w10
  __int64 result; // x0
  int v13; // w10
  __int64 v14; // x2
  unsigned int v15; // w19

  v1 = *(_DWORD *)(a1 + 600);
  v2 = *(_DWORD *)(a1 + 604);
  v3 = *(_DWORD *)(a1 + 35936);
  recon_buf_count = msm_vidc_get_recon_buf_count();
  v6 = *(_DWORD *)(a1 + 312);
  if ( v6 != 8 && v6 != 2 )
  {
    if ( v6 == 1 )
    {
      v7 = (unsigned int)(v2 + 15) >> 4;
      v8 = ((((unsigned int)(v1 + 15) >> 2) + 28) & 0x7FFFFFE0) * v7 + 255;
      v9 = ((48 * ((unsigned int)(v1 + 15) >> 4) * v7 + 1791) & 0xFFFFFF00) * recon_buf_count;
      v10 = v8 & 0xFFFFFF00;
      if ( v3 )
        v11 = 12;
      else
        v11 = 6;
      result = v9 + v10 * v11;
      if ( !a1 )
        return result;
    }
    else
    {
      result = 0;
      if ( !a1 )
        return result;
    }
LABEL_15:
    if ( (msm_vidc_debug & 4) != 0 )
    {
      v14 = a1 + 340;
      v15 = result;
      printk(&unk_8FA63, "low ", v14, "msm_vidc_encoder_comv_size_iris4", (unsigned int)result);
      return v15;
    }
    return result;
  }
  if ( (*(_QWORD *)(a1 + 15104) & 0xFFFFFFFELL) == 4 )
    v13 = 10;
  else
    v13 = 6;
  result = ((((((((unsigned int)(v1 + 15) >> 2) + 28) & 0x7FFFFFE0) * ((unsigned int)(v2 + 15) >> 4) + 255) & 0xFFFFFF00)
           * v13) << (v3 != 0))
         + ((((2 * v1 + 62) & 0xFFFFFFC0) * ((unsigned int)(v2 + 31) >> 5) + 767) & 0xFFFFFF00) * recon_buf_count;
  if ( a1 )
    goto LABEL_15;
  return result;
}
