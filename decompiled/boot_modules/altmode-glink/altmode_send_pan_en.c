__int64 __fastcall altmode_send_pan_en(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  int v4; // w0
  __int64 result; // x0
  int v6; // w21
  _QWORD v7[4]; // [xsp+0h] [xbp-20h] BYREF

  v7[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_DWORD *)(a1 + 216) = 0;
  v2 = a1 + 216;
  v3 = *(_QWORD *)(a1 - 120);
  v7[1] = 0x1000000015LL;
  v7[2] = 0;
  v7[0] = 0x10000800CLL;
  v4 = pmic_glink_write(v3, v7, 24);
  if ( v4 )
  {
    v6 = v4;
    printk(&unk_73E5, "altmode_write");
    if ( (v6 & 0x80000000) == 0 )
      goto LABEL_3;
LABEL_8:
    result = printk(&unk_7254, "altmode_send_pan_en");
    goto LABEL_4;
  }
  if ( !(unsigned int)wait_for_completion_timeout(v2, 250) )
  {
    printk(&unk_73E5, "altmode_write");
    goto LABEL_8;
  }
LABEL_3:
  *(_DWORD *)(a1 - 8) = 1;
  result = ipc_log_string(altmode_ipc_log, "Sent PAN EN\n");
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
