__int64 __fastcall aw_pid_2329_dev_init(__int64 result)
{
  *(_DWORD *)(result + 28) = 126;
  qmemcpy((void *)(result + 128), "aw882xx_pid_2329_monitor.bin", 28);
  *(_DWORD *)(result + 548) = 255;
  *(_QWORD *)(result + 588) = 0xFFFF03FF00000060LL;
  *(_WORD *)(result + 1112) = 14648;
  *(_QWORD *)(result + 200) = 0xFFFFF3FF00000004LL;
  *(_QWORD *)(result + 208) = 2048;
  *(_QWORD *)(result + 192) = "btn pid 2329 IIC Write EN";
  return result;
}
