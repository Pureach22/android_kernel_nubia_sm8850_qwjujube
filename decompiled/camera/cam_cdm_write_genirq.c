unsigned int *__fastcall cam_cdm_write_genirq(unsigned int *result, int a2, char a3, int a4)
{
  unsigned int v4; // w8
  int v5; // w19
  int v6; // w20
  unsigned int *v7; // x21
  char v8; // w22

  if ( (debug_mdl & 1) != 0 && !debug_priority )
  {
    v5 = a2;
    v6 = a4;
    v7 = result;
    v8 = a3;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_cdm_write_genirq",
      351,
      "userdata 0x%x, fifo_idx %d",
      a2,
      a4);
    a3 = v8;
    result = v7;
    a4 = v6;
    a2 = v5;
  }
  v4 = *result;
  if ( (a3 & 1) != 0 )
    v4 = *result & 0xFF000000 | (2 * (a4 & 0x7FFFFF)) | 1;
  *result = v4 & 0xFFFFFF | 0x6000000;
  result[1] = a2 << (8 * a4);
  return result;
}
