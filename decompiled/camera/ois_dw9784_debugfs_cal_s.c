__int64 __fastcall ois_dw9784_debugfs_cal_s(__int64 a1)
{
  unsigned int v2; // w19
  char v3; // w8
  char v4; // w26
  int v5; // w1
  int v6; // w2
  int v7; // w1
  int v8; // w2
  int v9; // w1
  int v10; // w2
  int v11; // w8
  void *v12; // x0
  void *v13; // x0
  __int64 v15; // [xsp+0h] [xbp-20h] BYREF
  __int64 v16; // [xsp+8h] [xbp-18h] BYREF
  int v17; // [xsp+10h] [xbp-10h] BYREF
  int v18; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+18h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  v17 = 0;
  v15 = 0;
  v16 = 0;
  printk(&unk_3D3DAD);
  v2 = 0;
  v3 = 1;
  *(_DWORD *)(a1 + 24) = 0;
  do
  {
    v4 = v3;
    if ( (zte_cam_cci_i2c_write(*(_QWORD *)a1 + 3656LL, 28690, 6, 2, 2) & 0x80000000) != 0 )
      printk(&unk_41BA38);
    _const_udelay("d: %u rc: %d", v5, v6);
    if ( (zte_cam_cci_i2c_write(*(_QWORD *)a1 + 3656LL, 28688, 24576, 2, 2) & 0x80000000) != 0 )
      printk(&unk_41BA38);
    _const_udelay("d: %u rc: %d", v7, v8);
    if ( (unsigned int)dw9784_wait_check_register((_QWORD *)a1, 0x7010u, 24576) )
    {
      v13 = &unk_43683B;
LABEL_41:
      printk(v13);
      v2 = -1;
      goto LABEL_44;
    }
    if ( (zte_cam_cci_i2c_write(*(_QWORD *)a1 + 3656LL, 28689, 1, 2, 2) & 0x80000000) != 0 )
      printk(&unk_41BA38);
    _const_udelay("d: %u rc: %d", v9, v10);
    if ( (unsigned int)dw9784_wait_check_register((_QWORD *)a1, 0x7010u, 24577) )
    {
      v13 = &unk_3CFD40;
      goto LABEL_41;
    }
    if ( (camera_io_dev_read(*(_QWORD *)a1 + 3656LL, 29056, (__int64)&v17, 2, 2, 0) & 0x80000000) != 0 )
      printk(&unk_3E416B);
    if ( (camera_io_dev_read(*(_QWORD *)a1 + 3656LL, 29057, (__int64)&v16 + 4, 2, 2, 0) & 0x80000000) != 0 )
      printk(&unk_3E416B);
    if ( (camera_io_dev_read(*(_QWORD *)a1 + 3656LL, 28944, (__int64)&v16, 2, 2, 0) & 0x80000000) != 0 )
      printk(&unk_3E416B);
    if ( (camera_io_dev_read(*(_QWORD *)a1 + 3656LL, 28992, (__int64)&v15 + 4, 2, 2, 0) & 0x80000000) != 0 )
      printk(&unk_3E416B);
    if ( (camera_io_dev_read(*(_QWORD *)a1 + 3656LL, 28704, (__int64)&v15, 2, 2, 0) & 0x80000000) != 0 )
      printk(&unk_3E416B);
    if ( (camera_io_dev_read(*(_QWORD *)a1 + 3656LL, 29077, (__int64)&v18, 2, 2, 0) & 0x80000000) != 0 )
      printk(&unk_3E416B);
    if ( (v18 & 0x8000) == 0 )
    {
      printk(&unk_407B2B);
      v2 = 255;
      goto LABEL_44;
    }
    if ( (~v18 & 3) == 0 )
    {
      printk(&unk_3E7E1B);
LABEL_3:
      v2 = calibration_save_ois_dw9784((__int64 *)a1);
      *(_DWORD *)(a1 + 24) = 1;
      goto LABEL_4;
    }
    if ( (v18 & 0x10) != 0 )
    {
      v11 = 16;
      v12 = &unk_3EC4E5;
    }
    else if ( (v18 & 0x20) != 0 )
    {
      v11 = 32;
      v12 = &unk_42F124;
    }
    else
    {
      if ( (v18 & 0x800) != 0 )
        v11 = 2048;
      else
        v11 = 1;
      if ( (v18 & 0x800) != 0 )
        v12 = &unk_43A782;
      else
        v12 = &unk_432C7D;
    }
    v2 += v11;
    printk(v12);
    if ( !v2 )
      goto LABEL_3;
LABEL_4:
    v3 = 0;
  }
  while ( (v4 & 1) != 0 );
  printk(&unk_40FB79);
  printk(&unk_3FC595);
  printk(&unk_41F74E);
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return v2;
}
