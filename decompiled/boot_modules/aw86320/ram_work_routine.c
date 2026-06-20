__int64 __fastcall ram_work_routine(__int64 a1)
{
  __int64 v1; // x3

  v1 = *(_QWORD *)(a1 - 128);
  *(_BYTE *)(a1 - 608) = 0;
  return request_firmware_nowait(&_this_module, 1, "micop_ram.bin", v1, 3264, a1 - 608, ram_load);
}
