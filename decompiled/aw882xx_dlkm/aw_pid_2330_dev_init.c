__int64 __fastcall aw_pid_2330_dev_init(__int64 result)
{
  *(_DWORD *)(result + 28) = 123;
  *(_DWORD *)(result + 1024) = 91;
  qmemcpy((void *)(result + 128), "aw882xx_pid_2330_monitor.bin", 28);
  *(_DWORD *)(result + 548) = 255;
  *(_DWORD *)(result + 576) = 255;
  *(_QWORD *)(result + 588) = 0xFFFF03FF00000062LL;
  *(_WORD *)(result + 1112) = 14648;
  *(_QWORD *)(result + 200) = 0xFFFFF3FF00000004LL;
  *(_QWORD *)(result + 208) = 2048;
  *(_QWORD *)(result + 192) = "btn pid 2330 IIC Write EN";
  *(_DWORD *)(result + 220) = 119;
  *(_DWORD *)(result + 232) = 122;
  return result;
}
