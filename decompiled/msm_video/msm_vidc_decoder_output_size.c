__int64 __fastcall msm_vidc_decoder_output_size(unsigned int *a1)
{
  __int64 v2; // x0

  v2 = v4l2_colorformat_to_driver(a1, a1[152], "msm_vidc_decoder_output_size");
  return video_buffer_size(v2, a1[150], a1[151]);
}
