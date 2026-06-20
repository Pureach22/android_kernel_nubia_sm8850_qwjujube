__int64 __fastcall cam_cdm_write_wait_event(
        __int64 a1,
        char a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        int a5,
        int a6)
{
  *(_DWORD *)(a1 + 8) = a6;
  *(_QWORD *)a1 = ((a2 & 1) << 23) | (a3 << 8) | ((unsigned __int64)(a5 & 0xFFFFFF) << 32) | a4 | 0x7000000u;
  return a1 + 12;
}
