__int64 __fastcall show_simlock_status(__int64 a1, __int64 a2, char *a3)
{
  __int64 v4; // x8
  int v5; // w20
  __int64 result; // x0
  _QWORD v7[11]; // [xsp+8h] [xbp-78h] BYREF
  __int64 v8; // [xsp+60h] [xbp-20h]
  __int64 v9; // [xsp+68h] [xbp-18h]
  __int64 v10; // [xsp+70h] [xbp-10h]
  __int64 v11; // [xsp+78h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  v10 = 0;
  v8 = 0;
  v4 = 48;
  memset(&v7[8], 0, 24);
  if ( ftm_sysdev_priv_data_0 )
    v4 = 360496;
  v7[1] = v4;
  memset(&v7[2], 0, 48);
  v7[0] = 2;
  if ( (unsigned int)qcom_scm_qseecom_call(33556487, v7, 1) )
  {
    printk(&unk_6805, 6);
    v5 = 0;
  }
  else
  {
    v5 = v8;
  }
  printk(&unk_678D, "show_simlock_status");
  LODWORD(result) = snprintf(a3, 0x1000u, "%d\n", (~v5 & 0xC0000000) == 0);
  _ReadStatusReg(SP_EL0);
  return (int)result;
}
