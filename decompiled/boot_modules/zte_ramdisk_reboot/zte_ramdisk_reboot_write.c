__int64 __fastcall zte_ramdisk_reboot_write(unsigned __int8 *a1, int a2)
{
  __int64 result; // x0
  __int64 v4; // x19
  unsigned __int64 v5; // x1
  unsigned int v6; // w8

  result = 0xFFFFFFFFLL;
  if ( a2 == 1 )
  {
    if ( a1 )
    {
      v4 = ramdisk_rb;
      if ( ramdisk_rb )
      {
        v5 = *(_QWORD *)(ramdisk_rb + 104);
        v6 = *a1;
        saved_ramdisk_buf = v6;
        if ( v5 < 0xFFFFFFFFFFFFF001LL )
        {
          printk(&unk_6F3F, v6);
          nvmem_cell_write(*(_QWORD *)(v4 + 104), &saved_ramdisk_buf, 1);
        }
        else
        {
          printk(&unk_6B8B, v5);
        }
        return 0;
      }
    }
  }
  return result;
}
