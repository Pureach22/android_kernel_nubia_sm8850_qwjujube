__int64 __fastcall fmd_set_sdam_bit(unsigned __int8 a1)
{
  __int64 result; // x0
  __int64 v2; // x20
  unsigned __int8 *v3; // x0
  unsigned __int8 *v4; // x19
  void *v5; // x0
  __int64 v6; // [xsp+8h] [xbp-18h] BYREF
  unsigned __int8 v7; // [xsp+14h] [xbp-Ch]
  __int64 v8; // [xsp+18h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = a1;
  v6 = 0;
  if ( *(_QWORD *)(pwr_data + 776) < 0xFFFFFFFFFFFFF001LL )
  {
    v2 = *(_QWORD *)pwr_data;
    if ( (nvmem_cell_write() & 0x80000000) != 0 )
    {
      result = printk(&unk_11A81, "fmd_set_sdam_bit");
    }
    else
    {
      v3 = (unsigned __int8 *)nvmem_cell_read(*(_QWORD *)(pwr_data + 776), &v6);
      v4 = v3;
      if ( (unsigned __int64)v3 < 0xFFFFFFFFFFFFF001LL )
      {
        if ( *v3 == v7 )
        {
          dev_info(v2 + 16, "Successfully configured the fmd_set\n");
          v5 = &unk_10EB6;
        }
        else
        {
          dev_err(v2 + 16, "Failed to configure fmd_set: %ld\n", v3);
          v5 = &unk_12A37;
        }
      }
      else
      {
        dev_err(v2 + 16, "Failed to read fmd_set: %ld\n", v3);
        v5 = &unk_137DD;
      }
      printk(v5, "fmd_set_sdam_bit");
      result = kfree(v4);
    }
  }
  else
  {
    result = printk(&unk_11B7C, "fmd_set_sdam_bit");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
