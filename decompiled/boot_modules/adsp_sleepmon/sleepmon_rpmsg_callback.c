__int64 __fastcall sleepmon_rpmsg_callback(__int64 a1, _DWORD *a2, unsigned int a3)
{
  int v3; // w8
  __int64 v6; // x10
  __int64 v7; // x8
  __int64 v8; // x11

  if ( a2 && a3 > 0x92F )
  {
    v3 = a2[2];
    if ( v3 == 1 )
    {
      dword_A678 = a2[1];
      printk(&unk_A04C);
      if ( byte_A62C != 1 )
        return 0;
      qword_A760 = 0;
      timer_delete(&adspsleep_timer);
      HIBYTE(word_A629) = 0;
      qword_A650 = 0;
      dword_A648 = 0;
      v6 = *(_QWORD *)(qword_A7C0 + 8);
      v7 = *(_QWORD *)(qword_A7C0 + 16);
      v8 = *(_QWORD *)(qword_A7C0 + 24);
      qword_A770 = *(_QWORD *)qword_A7C0;
      qword_A778 = v6;
      qword_A780 = v7;
      qword_A788 = v8;
      __isb(0xFu);
      qword_A790 = _ReadStatusReg(CNTVCT_EL0);
      v3 = a2[2];
      if ( v3 == 2 )
        goto LABEL_5;
    }
    else if ( v3 == 2 )
    {
LABEL_5:
      byte_B0D0 = 0;
      memcpy(&unk_A7E0, a2 + 4, 0x920u);
      complete(&dword_A658);
      v3 = a2[2];
    }
    if ( v3 == 5 )
    {
      if ( HIBYTE(word_A62E) == 1 )
      {
        printk(&unk_98C6);
        panic("ADSP_SLEEPMON: ADSP LPI issue detected");
      }
      if ( byte_A633 != 1 )
        return 0;
      sleepmon_send_ssr_command();
      v3 = a2[2];
    }
    if ( v3 == 6 )
      printk(&unk_A30F);
    return 0;
  }
  dev_err(a1, "Invalid message in rpmsg callback, length: %d, expected: %lu\n", a3, 2352);
  return 4294967274LL;
}
