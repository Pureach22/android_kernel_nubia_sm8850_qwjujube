__int64 __fastcall wlan_log_to_user(int a1, const void *a2, int a3)
{
  unsigned __int64 StatusReg; // x22
  unsigned __int64 v7; // x8
  const char *v8; // x3
  __int16 v9; // w9
  const char *v10; // x8
  signed int v11; // w0
  __int64 v12; // x3
  signed int v13; // w23
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x22
  unsigned int *v17; // x26
  unsigned __int64 v18; // x24
  unsigned __int64 v19; // x25
  __int64 v20; // x27
  unsigned int v21; // w8
  __int64 result; // x0
  unsigned __int64 v29; // x9
  _QWORD v30[7]; // [xsp+0h] [xbp-60h] BYREF
  int v31; // [xsp+38h] [xbp-28h]
  _QWORD v32[2]; // [xsp+40h] [xbp-20h] BYREF
  int v33; // [xsp+50h] [xbp-10h]
  __int64 v34; // [xsp+58h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  memset(v30, 0, sizeof(v30));
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v33 = 0;
  v32[0] = 0;
  v32[1] = 0;
  qdf_get_time_of_the_day_in_hr_min_sec_usec((__int64)v32, 20);
  v7 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v7 + 16) & 0xF0000) != 0 )
  {
    v8 = "irq";
  }
  else
  {
    v9 = *(_DWORD *)(v7 + 16);
    v10 = (const char *)(v7 + 2320);
    if ( (v9 & 0xFF00) != 0 )
      v8 = "soft_irq";
    else
      v8 = v10;
  }
  scnprintf(v30, 60, "[%.6s][0x%llx]%s", v8, StatusReg, (const char *)v32);
  if ( (word_76E1D8 & 1) == 0 )
  {
LABEL_15:
    if ( (unsigned int)(a1 - 1) <= 3 )
      printk(*(&off_9E6758 + (unsigned int)(a1 - 1)), v30, a2, v12);
    goto LABEL_17;
  }
  v13 = v11;
  v14 = raw_spin_lock_irqsave((char *)&qword_76E148 + 4);
  v15 = qword_76E1C8;
  v16 = v14;
  if ( !qword_76E1C8 )
  {
    raw_spin_unlock_irqrestore((char *)&qword_76E148 + 4, v14);
    result = 4294967291LL;
    goto LABEL_18;
  }
  v17 = (unsigned int *)(qword_76E1C8 + 24);
  v18 = a3 + v13 + 2;
  v19 = 2024LL - *(unsigned int *)(qword_76E1C8 + 24);
  if ( v19 < v18 )
  {
    wlan_queue_logmsg_for_app();
    v15 = qword_76E1C8;
    v17 = (unsigned int *)(qword_76E1C8 + 24);
  }
  if ( v18 - 2025 <= 0xFFFFFFFFFFFFF7FELL )
    a3 = 2022 - v13;
  if ( (unsigned int)v13 >= 0x3D )
  {
    _fortify_panic(16, -1, v13);
  }
  else
  {
    v20 = v15 + 32;
    memcpy((void *)(v15 + 32 + *v17), v30, v13);
    memcpy((void *)(v20 + *v17 + v13), a2, a3);
    v21 = a3 + v13 + *v17;
    *v17 = v21;
    *(_BYTE *)(v20 + v21) = 10;
    ++*v17;
    raw_spin_unlock_irqrestore((char *)&qword_76E148 + 4, v16);
    if ( v19 >= v18 )
      goto LABEL_14;
  }
  _X8 = &qword_76E1D0;
  __asm { PRFM            #0x11, [X8] }
  do
    v29 = __ldxr((unsigned __int64 *)&qword_76E1D0);
  while ( __stxr(v29 | 2, (unsigned __int64 *)&qword_76E1D0) );
  _wake_up(&unk_76E180, 1, 1, 0);
LABEL_14:
  if ( (((unsigned __int64)(unsigned int)gwlan_logging >> a1) & 1) != 0 )
    goto LABEL_15;
LABEL_17:
  result = 0;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
