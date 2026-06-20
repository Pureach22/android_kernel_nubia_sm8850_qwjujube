__int64 __fastcall aw_pid_2116_dev_init(__int64 result)
{
  *(_QWORD *)(result + 1192) = aw_get_irq_nobst_type;
  *(_DWORD *)(result + 28) = 114;
  *(_QWORD *)(result + 532) = 0x11FFFFBEC4LL;
  *(_DWORD *)(result + 540) = 273;
  *(_QWORD *)(result + 304) = 0x61FF000061FFLL;
  *(_QWORD *)(result + 360) = 0xFFFFFFFD00000004LL;
  *(_QWORD *)(result + 368) = 0x200000000LL;
  *(_DWORD *)(result + 312) = 255;
  *(_QWORD *)(result + 352) = "btn 2116 amppd";
  *(_DWORD *)(result + 564) = 255;
  *(_DWORD *)(result + 576) = 255;
  *(_DWORD *)(result + 588) = 255;
  *(_QWORD *)(result + 400) = "btn 2116 uls hmute";
  *(_QWORD *)(result + 408) = 0xFFFFBFFF00000004LL;
  *(_QWORD *)(result + 976) = 0xFFFFBFFF00000005LL;
  *(_QWORD *)(result + 968) = "btn 2116 bop";
  *(_QWORD *)(result + 416) = 0x4000;
  *(_QWORD *)(result + 424) = 0xFFFFFFBF00000008LL;
  *(_QWORD *)(result + 432) = 64;
  *(_QWORD *)(result + 1024) = 0xFFFFDFFF00000016LL;
  *(_QWORD *)(result + 548) = 0xFFFFDFFF00000054LL;
  *(_QWORD *)(result + 1032) = 0x2000;
  *(_QWORD *)(result + 556) = 0x200000000000LL;
  *(_QWORD *)(result + 984) = 0x4000;
  *(_QWORD *)(result + 1016) = "btn 2116 noise gate";
  *(_DWORD *)(result + 216) = 0;
  return result;
}
