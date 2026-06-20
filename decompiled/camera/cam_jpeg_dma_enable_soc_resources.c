__int64 __fastcall cam_jpeg_dma_enable_soc_resources(__int64 a1)
{
  unsigned int v1; // w19

  v1 = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, __int64))cam_soc_util_enable_platform_resource)(
         a1,
         0xFFFFFFFFLL,
         1,
         5,
         1);
  if ( v1 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_dma_enable_soc_resources",
      80,
      "enable platform failed %d",
      v1);
  return v1;
}
