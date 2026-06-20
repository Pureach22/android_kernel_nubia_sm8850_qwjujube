__int64 __fastcall aw22xxx_fw_work_routine(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x3

  v2 = a1 - 528;
  printk(&unk_130E1, "aw22xxx_fw_work_routine");
  printk(&unk_130E1, "aw22xxx_fw_update");
  v3 = *(_QWORD *)(a1 - 520);
  *(_BYTE *)(a1 + 223) = 1;
  return request_firmware_nowait(&_this_module, 1, &aw22xxx_fw_name, v3, 3264, v2, aw22xxx_fw_loaded);
}
