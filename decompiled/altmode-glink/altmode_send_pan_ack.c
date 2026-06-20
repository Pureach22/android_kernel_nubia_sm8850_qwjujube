__int64 __fastcall altmode_send_pan_ack(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x0
  int v4; // w0
  __int64 result; // x0
  int v6; // w21
  __int64 v7; // [xsp+0h] [xbp-20h] BYREF
  int v8; // [xsp+8h] [xbp-18h]
  __int64 v9; // [xsp+Ch] [xbp-14h]
  int v10; // [xsp+14h] [xbp-Ch]
  __int64 v11; // [xsp+18h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(unsigned __int8 *)(a1 + 144);
  v8 = 21;
  v7 = 0x10000800CLL;
  *(_DWORD *)(a1 + 112) = 0;
  v2 = a1 + 112;
  v3 = *(_QWORD *)(a1 - 224);
  v10 = 0;
  v9 = (v1 << 32) | 0x11;
  v4 = pmic_glink_write(v3, &v7, 24);
  if ( v4 )
  {
    v6 = v4;
    printk(&unk_73E5, "altmode_write");
    if ( (v6 & 0x80000000) == 0 )
      goto LABEL_3;
LABEL_8:
    result = printk(&unk_7469, "altmode_send_ack");
    goto LABEL_4;
  }
  if ( !(unsigned int)wait_for_completion_timeout(v2, 250) )
  {
    printk(&unk_73E5, "altmode_write");
    goto LABEL_8;
  }
LABEL_3:
  result = ipc_log_string(altmode_ipc_log, "port %u: Sent PAN ACK\n", v1);
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
