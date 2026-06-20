__int64 __fastcall msm_vidc_encoder_output_size_iris4(_DWORD *a1)
{
  int v2; // w0
  unsigned int v3; // w8
  unsigned int v4; // w9
  unsigned int v5; // w8
  int v6; // w9
  int v7; // w10
  int v8; // w8
  int v10; // w8
  char v11; // w9
  unsigned int v12; // w10
  unsigned int v13; // w11
  unsigned int v14; // w12
  unsigned int v15; // w10
  unsigned int v16; // w9
  unsigned int v17; // w8

  v2 = v4l2_codec_to_driver();
  if ( v2 == 2 || v2 == 8 )
  {
    v10 = 1;
  }
  else
  {
    if ( v2 == 64 )
    {
      v3 = ((a1[151] + 31) & 0xFFFFFFE0) * ((a1[150] + 31) & 0xFFFFFFE0);
      v4 = 29 * v3;
      v5 = 4 * v3;
      v6 = (v4 >> 6) + (v4 >> 7);
      if ( v5 >= 0x63000 )
        v7 = 6;
      else
        v7 = 24;
      if ( v5 >= 0x384000 )
        v8 = 3;
      else
        v8 = v7;
      return (v8 * v6 + 4095) & 0xFFFFF000;
    }
    v10 = 0;
  }
  v11 = !a1[6212] && a1[78] != 8 || a1[6086] == 2;
  v12 = ((a1[151] + 31) & 0xFFFFFFE0) * ((a1[150] + 31) & 0xFFFFFFE0);
  v13 = 3 * v12;
  if ( v12 <= 0xE1000 )
    v14 = 3 * v12;
  else
    v14 = (3 * v12) >> 2;
  if ( v12 <= 0x880000 )
    v15 = v14;
  else
    v15 = (3 * v12) >> 3;
  if ( v15 >= v13 >> 1 )
    v11 = 0;
  v16 = v15 << v11;
  if ( v10 )
    v17 = v16 >> 2;
  else
    v17 = 0;
  return msm_vidc_enc_delivery_mode_based_output_buf_size(a1, (v16 + v17 + 4095) & 0xFFFFF000);
}
