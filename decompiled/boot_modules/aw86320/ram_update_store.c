size_t __fastcall ram_update_store(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v4; // x20
  size_t v5; // x19
  __int64 v6; // x6
  __int64 v8; // x3
  unsigned int v9; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-18h] BYREF
  __int16 v11; // [xsp+10h] [xbp-10h]
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = g_aw86320;
  v9 = 0;
  if ( a3 >= 9 )
    v5 = 9;
  else
    v5 = a3;
  v11 = 0;
  v10 = 0;
  _check_object_size(&v10, v5, 0);
  if ( (unsigned int)inline_copy_from_user((__int64)&v10, a2, v5) || (unsigned int)kstrtouint(&v10, 0, &v9) )
  {
    v5 = -22;
  }
  else
  {
    printk(&unk_9C32, "aw86320", 724, "ram_update_store", "ram_update_store", v9, v6);
    if ( v9 )
    {
      v8 = *(_QWORD *)(v4 + 480);
      *(_BYTE *)v4 = 0;
      request_firmware_nowait(&_this_module, 1, "micop_ram.bin", v8, 3264, v4, ram_load);
    }
  }
  _ReadStatusReg(SP_EL0);
  return v5;
}
