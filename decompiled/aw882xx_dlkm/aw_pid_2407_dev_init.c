__int64 __fastcall aw_pid_2407_dev_init(__int64 result)
{
  *(_DWORD *)(result + 28) = 126;
  qmemcpy((void *)(result + 128), "aw882xx_pid_2407_monitor.bin", 28);
  *(_QWORD *)(result + 192) = "btn pid 2407 IIC Write EN";
  *(_QWORD *)(result + 200) = 0xFFFF3FFF00000004LL;
  *(_QWORD *)(result + 1192) = aw_get_irq_nobst_type;
  *(_QWORD *)(result + 424) = 0xFFFFFF7F00000004LL;
  *(_QWORD *)(result + 432) = 128;
  *(_DWORD *)(result + 312) = 255;
  *(_QWORD *)(result + 528) = 0xFFFFBEC400000001LL;
  *(_DWORD *)(result + 408) = 255;
  *(_QWORD *)(result + 536) = 0x11100000011LL;
  *(_DWORD *)(result + 544) = 17;
  *(_QWORD *)(result + 948) = 0xFFFFF3FF00000005LL;
  *(_DWORD *)(result + 548) = 255;
  *(_QWORD *)(result + 956) = 0x80000000400LL;
  *(_DWORD *)(result + 564) = 255;
  *(_DWORD *)(result + 576) = 255;
  *(_DWORD *)(result + 588) = 255;
  *(_DWORD *)(result + 976) = 255;
  *(_DWORD *)(result + 1024) = 255;
  *(_WORD *)(result + 1112) = 14648;
  *(_QWORD *)(result + 208) = 0x8000;
  *(_QWORD *)(result + 216) = 0x7600000002LL;
  *(_DWORD *)(result + 240) = 0x8000;
  *(_QWORD *)(result + 224) = 0x8000FFFF7FFFLL;
  *(_QWORD *)(result + 232) = 0xFFFF7FFF00000078LL;
  return result;
}
