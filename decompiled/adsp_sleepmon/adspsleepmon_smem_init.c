__int64 adspsleepmon_smem_init()
{
  unsigned __int64 v0; // x0
  unsigned __int64 v1; // x0
  unsigned __int64 v2; // x0
  unsigned int *v3; // x0
  unsigned __int64 v4; // x2
  unsigned int *v5; // x1
  unsigned __int64 v6; // x10
  unsigned __int64 v7; // x9
  unsigned __int64 v8; // x11
  unsigned __int64 v9; // x10
  unsigned __int64 v10; // x11
  __int64 result; // x0
  void *v12; // x0
  _QWORD v13[2]; // [xsp+0h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[0] = 0;
  v0 = qcom_smem_get(2, 606, v13);
  qword_A7C0 = v0;
  if ( !v0 || v0 > 0xFFFFFFFFFFFFF000LL || v13[0] <= 0x1Fu )
  {
    v12 = &unk_A1D8;
LABEL_28:
    printk(v12);
    goto LABEL_29;
  }
  v1 = qcom_smem_get(2, 613, v13);
  qword_A7C8 = v1;
  if ( !v1 || v1 > 0xFFFFFFFFFFFFF000LL || v13[0] <= 0x1Fu )
  {
    v12 = &unk_92EA;
    goto LABEL_28;
  }
  v2 = qcom_smem_get(2, 624, v13);
  qword_A7D0 = v2;
  if ( !v2 || v2 > 0xFFFFFFFFFFFFF000LL || v13[0] <= 0x33u )
  {
    v12 = &unk_90FA;
    goto LABEL_28;
  }
  v3 = (unsigned int *)qcom_smem_get(2, 634, v13);
  v4 = v13[0];
  v5 = v3;
  if ( !v3 || (unsigned __int64)v3 > 0xFFFFFFFFFFFFF000LL || !v13[0] )
  {
    v12 = &unk_9712;
    goto LABEL_28;
  }
  qword_A7D8 = 0;
  v6 = *v3;
  v7 = (v6 >> 16) & 0xFFF;
  if ( v13[0] < v7 )
    goto LABEL_23;
  v8 = v6 >> 28;
  v9 = 0;
  do
  {
    while ( v8 != 2 )
    {
      v5 = (unsigned int *)((char *)v5 + v7);
      v4 -= v7;
      v10 = *v5;
      v7 = (v10 >> 16) & 0xFFF;
      v8 = v10 >> 28;
      if ( v4 < v7 )
        goto LABEL_18;
    }
    v9 = (unsigned __int64)(v5 + 1);
    v4 = 0;
    qword_A7D8 = (__int64)(v5 + 1);
  }
  while ( !v7 );
LABEL_18:
  if ( !v9 || v9 >= 0xFFFFFFFFFFFFF001LL )
  {
LABEL_23:
    printk(&unk_A006);
LABEL_29:
    result = 4294967284LL;
    goto LABEL_30;
  }
  if ( (byte_A62D & 1) == 0 )
  {
    register_pm_notifier(&adsp_sleepmon_pm_nb);
    byte_A62D = 1;
  }
  result = 0;
  byte_A62C = 1;
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
