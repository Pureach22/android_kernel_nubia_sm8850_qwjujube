__int64 __fastcall syna_dev_isr(__int64 a1, __int64 *a2)
{
  int v3; // w8
  __int64 v4; // x20
  __int64 v5; // x2
  __int64 v6; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v8; // x0
  void *v10; // x0
  _BYTE v11[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *((_DWORD *)a2 + 351);
  v4 = a2[78];
  v11[0] = 0;
  if ( v3 != 1 && *((_BYTE *)a2 + 1400) == 1 && !(unsigned int)wait_for_completion_timeout(a2 + 171, 175) )
  {
    v10 = &unk_33570;
    goto LABEL_9;
  }
  v6 = gpio_to_desc(*(unsigned int *)(v4 + 168));
  if ( (unsigned int)gpiod_get_raw_value(v6) == *(_DWORD *)(v4 + 172) )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v8 = *a2;
    *((_DWORD *)a2 + 188) = *(_DWORD *)(StatusReg + 1800);
    if ( (syna_tcm_get_event_data(v8, v11, a2 + 85) & 0x80000000) != 0 )
    {
      v10 = &unk_35A19;
LABEL_9:
      printk(v10, "syna_dev_isr", v5);
    }
  }
  _ReadStatusReg(SP_EL0);
  return 1;
}
