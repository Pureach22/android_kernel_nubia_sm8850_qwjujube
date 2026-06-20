__int64 __fastcall ram_work_routine(__int64 a1)
{
  __int64 v1; // x3

  v1 = *(_QWORD *)(a1 - 160);
  *(_WORD *)(a1 - 955) = 0;
  return request_firmware_nowait(&_this_module, 1, aw_ram_name, v1, 3264, a1 - 960, ram_load);
}
