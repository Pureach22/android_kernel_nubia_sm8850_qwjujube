__int64 __fastcall firmware_upgrade_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x5
  __int64 v5; // x19

  v4 = *(_QWORD *)(a1 + 152);
  if ( v4 )
  {
    v5 = a4;
    if ( (unsigned int)request_firmware_nowait(
                         &_this_module,
                         1,
                         "lt9611uxc_fw.bin",
                         *(_QWORD *)(v4 + 3160) + 32LL,
                         3264,
                         v4,
                         lt9611uxc_firmware_cb) )
      printk(&unk_A78F, "firmware_upgrade_store");
    else
      printk(&unk_AE56, "firmware_upgrade_store");
  }
  else
  {
    printk(&unk_B00B, "firmware_upgrade_store");
    return -22;
  }
  return v5;
}
