__int64 rtc6226_fops_release()
{
  __int64 v0; // x0
  __int64 v1; // x19
  __int64 result; // x0
  unsigned int v3; // w19
  unsigned int v10; // w10

  v0 = video_devdata();
  v1 = *(_QWORD *)(v0 + 336);
  if ( *(_DWORD *)(v1 + 1756) )
  {
    rtc6226_power_down(*(_WORD **)(v0 + 336));
    *(_DWORD *)(v1 + 1756) = 0;
  }
  rtc6226_disable_irq(v1);
  _X8 = (unsigned int *)(v1 + 1752);
  __asm { PRFM            #0x11, [X8] }
  do
    v10 = __ldxr(_X8);
  while ( __stxr(v10 - 1, _X8) );
  if ( (rtc6226_fm_vdd_reg_cfg(v1, 0) & 0x80000000) != 0 )
    printk(&unk_D5E4, "rtc6226_fm_power_cfg");
  result = rtc6226_fm_vio_reg_cfg(v1, 0);
  if ( (result & 0x80000000) != 0 )
  {
    v3 = result;
    printk(&unk_CC71, "rtc6226_fm_power_cfg");
    printk(&unk_DA9B, "rtc6226_fops_release");
    return v3;
  }
  return result;
}
