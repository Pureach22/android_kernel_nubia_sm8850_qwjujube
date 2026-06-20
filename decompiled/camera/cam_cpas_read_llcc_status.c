__int64 __fastcall cam_cpas_read_llcc_status(unsigned int a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  unsigned int v5; // w20

  if ( g_cpas_intf && (*(_BYTE *)(g_cpas_intf + 852) & 1) != 0 )
  {
    if ( a2 && a3 )
    {
      result = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64, __int64))cam_cpas_read_llcc_reg)(
                 *(_QWORD *)(*(_QWORD *)(g_cpas_intf + 480) + 112LL),
                 a1,
                 a2,
                 a3);
      if ( (_DWORD)result )
      {
        v5 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_read_llcc_status",
          682,
          "Failed in read llcc registers, rc = %d scid = %u",
          result,
          a1);
        return v5;
      }
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_read_llcc_status",
        673,
        "Invalid arg value llcc_config:0x%x llcc_status:0x%x",
        a2,
        a3);
      return 4294967274LL;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_read_llcc_status",
      667,
      "cpas intf not initialized");
    return 4294967277LL;
  }
  return result;
}
