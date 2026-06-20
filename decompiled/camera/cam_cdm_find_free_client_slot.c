__int64 __fastcall cam_cdm_find_free_client_slot(__int64 a1)
{
  __int64 v1; // x19

  v1 = 0;
  while ( *(_QWORD *)(a1 + 248 + 8 * v1) )
  {
    if ( ++v1 == 256 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        1,
        1,
        "cam_cdm_find_free_client_slot",
        195,
        "No more client slots");
      LODWORD(v1) = -16;
      return (unsigned int)v1;
    }
  }
  if ( (debug_mdl & 1) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_cdm_find_free_client_slot",
      191,
      "Found client slot %d",
      v1);
  return (unsigned int)v1;
}
