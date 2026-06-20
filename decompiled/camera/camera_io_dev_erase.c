__int64 __fastcall camera_io_dev_erase(int *a1, __int64 a2, int a3)
{
  int v3; // w6
  const char *v5; // x5
  __int64 v6; // x4

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "camera_io_dev_erase",
      54,
      "Invalid Args");
    return 4294967274LL;
  }
  if ( !a3 )
    return 0;
  v3 = *a1;
  if ( (unsigned int)(*a1 - 1) < 2 || v3 == 4 )
  {
    v5 = "Erase not supported on Master Type: %d";
    v6 = 69;
LABEL_14:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "camera_io_dev_erase",
      v6,
      v5);
    return 4294967274LL;
  }
  if ( v3 != 3 )
  {
    v5 = "Invalid Master Type: %d";
    v6 = 72;
    goto LABEL_14;
  }
  if ( (debug_mdl & 0x4000000000LL) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x4000000000LL,
      4,
      "camera_io_dev_erase",
      63,
      "Calling SPI Erase");
  return cam_spi_erase();
}
