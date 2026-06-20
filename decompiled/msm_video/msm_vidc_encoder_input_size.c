__int64 __fastcall msm_vidc_encoder_input_size(_DWORD *a1)
{
  unsigned int v1; // w20
  unsigned int v2; // w19
  int v4; // w0
  int v5; // w8
  int v6; // w9
  int v7; // w8

  v1 = a1[98];
  v2 = a1[99];
  v4 = v4l2_colorformat_to_driver(a1, (unsigned int)a1[100], "msm_vidc_encoder_input_size");
  if ( a1[78] == 8 )
  {
    v5 = a1[6632];
    v6 = v5 - 1;
    v7 = -v5;
    v1 = (v6 + v1) & v7;
    v2 = (v6 + v2) & v7;
  }
  return video_buffer_size(v4, v1, v2);
}
