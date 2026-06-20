__int64 process_delayed_rm_request()
{
  unsigned __int64 StatusReg; // x8
  __int64 i; // x9
  unsigned __int64 v2; // x8
  unsigned int v3; // w26

  mutex_lock(&unk_A2E8);
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  if ( dword_A490 == dword_A398 )
  {
    for ( i = qword_A360; StatusReg < qword_A360; i = qword_A360 )
    {
      v2 = i - StatusReg;
      if ( v2 >= (unsigned int)(19200 * dword_A39C) )
        break;
      dword_A358 = 2;
      v3 = (unsigned int)v2 / 0x4B00;
      mutex_unlock(&unk_A2E8);
      usleep_range_state(1000 * v3, 1000 * v3 + 2000LL, 2);
      mutex_lock(&unk_A2E8);
      dword_A358 = 3;
      __isb(0xFu);
      StatusReg = _ReadStatusReg(CNTVCT_EL0);
      if ( dword_A490 != dword_A398 )
        break;
    }
  }
  set_qos_latency(0x7FFFFFFF);
  dword_A490 = 0x7FFFFFFF;
  dword_A358 = 4;
  return mutex_unlock(&unk_A2E8);
}
