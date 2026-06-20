__int64 __fastcall dw9784_code_pt_off(_QWORD *a1)
{
  int v2; // w1
  int v3; // w2

  printk(&unk_413D22);
  if ( (zte_cam_cci_i2c_write(*a1 + 3656LL, 64768, 21074, 2, 2) & 0x80000000) != 0 )
    printk(&unk_41BA38);
  _const_udelay("d: %u rc: %d", v2, v3);
  return printk(&unk_42B0F5);
}
