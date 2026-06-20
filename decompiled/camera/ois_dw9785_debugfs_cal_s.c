__int64 __fastcall ois_dw9785_debugfs_cal_s(__int64 *a1)
{
  __int64 v2; // x8
  int v3; // w1
  int v4; // w2
  int v5; // w1
  int v6; // w2
  int v7; // w1
  int v8; // w2
  __int64 result; // x0
  void *v10; // x0
  unsigned int v11; // w20
  __int64 v12; // [xsp+0h] [xbp-20h] BYREF
  __int64 v13; // [xsp+8h] [xbp-18h] BYREF
  int v14; // [xsp+10h] [xbp-10h] BYREF
  int v15; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v14 = 0;
  v12 = 0;
  v13 = 0;
  printk(&unk_43A7D9);
  v2 = *a1;
  *((_DWORD *)a1 + 6) = 0;
  if ( (zte_cam_cci_i2c_write(v2 + 3656, 28690, 6, 2, 2) & 0x80000000) != 0 )
    printk(&unk_41BA38);
  _const_udelay("d: %u rc: %d", v3, v4);
  if ( (zte_cam_cci_i2c_write(*a1 + 3656, 28688, 24576, 2, 2) & 0x80000000) != 0 )
    printk(&unk_41BA38);
  _const_udelay("d: %u rc: %d", v5, v6);
  if ( (unsigned int)dw9785_wait_check_register(a1, 0x7010u, 24576) )
  {
    v10 = &unk_442454;
LABEL_25:
    printk(v10);
    result = 0xFFFFFFFFLL;
    goto LABEL_26;
  }
  if ( (zte_cam_cci_i2c_write(*a1 + 3656, 28689, 1, 2, 2) & 0x80000000) != 0 )
    printk(&unk_41BA38);
  _const_udelay("d: %u rc: %d", v7, v8);
  if ( (unsigned int)dw9785_wait_check_register(a1, 0x7010u, 24577) )
  {
    v10 = &unk_407B6E;
    goto LABEL_25;
  }
  if ( (camera_io_dev_read(*a1 + 3656, 30464, (__int64)&v14, 2, 2, 0) & 0x80000000) != 0 )
    printk(&unk_3E416B);
  if ( (camera_io_dev_read(*a1 + 3656, 30465, (__int64)&v13 + 4, 2, 2, 0) & 0x80000000) != 0 )
    printk(&unk_3E416B);
  if ( (camera_io_dev_read(*a1 + 3656, 28960, (__int64)&v13, 2, 2, 0) & 0x80000000) != 0 )
    printk(&unk_3E416B);
  if ( (camera_io_dev_read(*a1 + 3656, 29088, (__int64)&v12 + 4, 2, 2, 0) & 0x80000000) != 0 )
    printk(&unk_3E416B);
  if ( (camera_io_dev_read(*a1 + 3656, 28704, (__int64)&v12, 2, 2, 0) & 0x80000000) != 0 )
    printk(&unk_3E416B);
  if ( (camera_io_dev_read(*a1 + 3656, 30481, (__int64)&v15, 2, 2, 0) & 0x80000000) != 0 )
    printk(&unk_3E416B);
  if ( (v15 & 0x8000) != 0 )
  {
    if ( (~v15 & 3) != 0 )
    {
      if ( (v15 & 0x10) != 0 )
      {
        printk(&unk_3E002C);
        v11 = 16;
      }
      else if ( (v15 & 0x20) != 0 )
      {
        printk(&unk_436865);
        v11 = 32;
      }
      else if ( (v15 & 0x800) != 0 )
      {
        printk(&unk_3E4194);
        v11 = 2048;
      }
      else
      {
        printk(&unk_3F83A5);
        v11 = 1;
      }
    }
    else
    {
      printk(&unk_407BA8);
      v11 = calibration_save_ois_dw9785(a1);
      *((_DWORD *)a1 + 6) = 1;
    }
    printk(&unk_3DC09E);
    printk(&unk_3D3DF5);
    printk(&unk_3D3E73);
    result = v11;
  }
  else
  {
    printk(&unk_3FC613);
    result = 255;
  }
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
