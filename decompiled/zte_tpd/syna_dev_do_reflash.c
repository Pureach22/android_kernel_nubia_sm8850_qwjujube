__int64 __fastcall syna_dev_do_reflash(__int64 *a1, char a2)
{
  __int64 result; // x0
  __int64 v3; // x19
  unsigned int v5; // w0
  unsigned int v6; // w19
  __int64 v7; // x2
  unsigned int v8; // w20
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = 0;
  if ( a1 )
  {
    v3 = *a1;
    v5 = request_firmware(v9, "syna_firmware.img", *(_QWORD *)(a1[1] + 112));
    if ( (v5 & 0x80000000) != 0 )
    {
      v6 = v5;
      printk(&unk_37594, "syna_dev_do_reflash", "syna_firmware.img");
      result = v6;
    }
    else
    {
      v8 = syna_tcm_do_fw_update(v3, *(_QWORD *)(v9[0] + 8LL), *(unsigned int *)v9[0], 0, a2 & 1);
      if ( (v8 & 0x80000000) != 0 )
        printk(&unk_3240E, "syna_dev_do_reflash", v7);
      printk(&unk_346D8, "syna_dev_do_reflash", *(unsigned __int8 *)(v3 + 9));
      release_firmware(v9[0]);
      result = v8;
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
