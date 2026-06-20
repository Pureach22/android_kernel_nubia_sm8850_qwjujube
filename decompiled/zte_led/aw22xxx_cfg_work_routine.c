__int64 __fastcall aw22xxx_cfg_work_routine(__int64 a1)
{
  printk(&unk_130E1, "aw22xxx_cfg_work_routine");
  printk(&unk_130E1, "aw22xxx_cfg_update_from_dyn_name");
  if ( *(_BYTE *)(a1 + 191) == 2 )
  {
    if ( *(_DWORD *)(a1 + 208) == 2 )
    {
      *(_BYTE *)(a1 + 280) = 0;
      if ( (g_init_flg & 1) != 0 )
        return request_firmware_nowait(
                 &_this_module,
                 1,
                 aw22xxx_dyn_name,
                 *(_QWORD *)(a1 - 552),
                 3264,
                 a1 - 560,
                 &aw22xxx_cfg_loaded);
    }
    else
    {
      *(_BYTE *)(a1 + 280) = 1;
      if ( (g_init_flg & 1) != 0 )
        return request_firmware_nowait(
                 &_this_module,
                 1,
                 aw22xxx_dyn_name,
                 *(_QWORD *)(a1 - 552),
                 3264,
                 a1 - 560,
                 &aw22xxx_cfg_loaded);
    }
    g_init_flg = 1;
    aw22xxx_init_cfg_update_array(a1 - 560);
    return request_firmware_nowait(
             &_this_module,
             1,
             aw22xxx_dyn_name,
             *(_QWORD *)(a1 - 552),
             3264,
             a1 - 560,
             &aw22xxx_cfg_loaded);
  }
  return printk(&unk_12EC6, "aw22xxx_cfg_update_from_dyn_name");
}
