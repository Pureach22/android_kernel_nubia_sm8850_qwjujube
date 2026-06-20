__int64 __fastcall aw882xx_voltage_offset_info(__int64 a1, __int64 a2)
{
  *(_DWORD *)(a2 + 64) = 2;
  *(_DWORD *)(a2 + 72) = 1;
  *(_QWORD *)(a2 + 80) = -255;
  *(_QWORD *)(a2 + 88) = 0xFFFF;
  return 0;
}
