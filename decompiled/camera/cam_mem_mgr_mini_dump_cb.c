__int64 __fastcall cam_mem_mgr_mini_dump_cb(char *a1, unsigned __int64 a2)
{
  char *v3; // x20

  if ( a1 )
  {
    if ( a2 >= 0x94010 )
    {
      v3 = a1 + 606208;
      memcpy(a1, &unk_2FDBA0, 0x94000u);
      *(_QWORD *)v3 = qword_391BA0;
      v3[8] = byte_391C18;
      v3[9] = byte_391BB8;
      v3[10] = byte_391BB9;
      return 606224;
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x400000,
        1,
        "cam_mem_mgr_mini_dump_cb",
        114,
        "Insufficient length %u",
        a2);
      return 0;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_mgr_mini_dump_cb",
      109,
      "Invalid  params");
    return 0;
  }
}
