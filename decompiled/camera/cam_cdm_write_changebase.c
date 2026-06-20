int *__fastcall cam_cdm_write_changebase(int *a1, int a2)
{
  int v3; // w19
  int *v4; // x20

  if ( (debug_mdl & 1) != 0 && !debug_priority )
  {
    v3 = a2;
    v4 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_cdm_write_changebase",
      387,
      "Change to base 0x%x",
      a2);
    a1 = v4;
    a2 = v3;
  }
  *a1 = a2 & 0xFFFFFF | 0x8000000;
  return a1 + 1;
}
