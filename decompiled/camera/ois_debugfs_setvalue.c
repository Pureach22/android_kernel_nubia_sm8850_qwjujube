__int64 __fastcall ois_debugfs_setvalue(__int64 a1, int a2)
{
  unsigned int v4; // w0
  unsigned int v6; // w20

  printk(&unk_3D7ED2);
  v4 = zte_cam_cci_i2c_write(
         *(_QWORD *)a1 + 3656LL,
         *(_DWORD *)(a1 + 16),
         a2,
         *(_DWORD *)(a1 + 12),
         *(_DWORD *)(a1 + 8));
  if ( (v4 & 0x80000000) == 0 )
    return 0;
  v6 = v4;
  printk(&unk_40BDCB);
  return v6;
}
