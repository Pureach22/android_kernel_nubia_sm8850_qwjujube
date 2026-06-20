__int64 __fastcall cam_cdm_set_cam_hw_version(int a1, __int64 a2)
{
  if ( a1 > 0x1FFFFFFF )
  {
    if ( a1 != 0x20000000 && a1 != 537001984 && a1 != 536936448 )
      goto LABEL_10;
LABEL_9:
    *(_DWORD *)a2 = a1 & 0xF0000000;
    *(_DWORD *)(a2 + 4) = a1 & 0xFFF0000;
    *(_QWORD *)(a2 + 8) = (unsigned __int16)a1;
    return 1;
  }
  if ( a1 == 0x10000000 || a1 == 268500992 || a1 == 268566528 )
    goto LABEL_9;
LABEL_10:
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    1,
    1,
    "cam_cdm_set_cam_hw_version",
    95,
    "CDM Version=%x not supported in util",
    a1);
  return 0;
}
