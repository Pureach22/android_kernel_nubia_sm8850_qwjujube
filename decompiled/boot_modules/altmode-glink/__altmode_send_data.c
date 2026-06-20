__int64 __fastcall _altmode_send_data(__int64 a1, const void *a2, size_t a3)
{
  __int64 v4; // x0
  unsigned int v5; // w0
  __int64 result; // x0
  unsigned int v7; // w19
  __int64 v8; // [xsp+0h] [xbp-20h] BYREF
  int v9; // [xsp+8h] [xbp-18h]
  __int64 v10; // [xsp+Ch] [xbp-14h] BYREF
  int v11; // [xsp+14h] [xbp-Ch]
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  v10 = 0;
  if ( a3 >= 9 )
  {
    printk(&unk_7315, "__altmode_send_data");
    result = 4294967274LL;
    goto LABEL_5;
  }
  v9 = 21;
  v8 = 0x10000800CLL;
  memcpy(&v10, a2, a3);
  v4 = *(_QWORD *)(a1 + 8);
  *(_DWORD *)(a1 + 344) = 0;
  v5 = pmic_glink_write(v4, &v8, 24);
  if ( v5 )
  {
    v7 = v5;
LABEL_9:
    printk(&unk_73E5, "altmode_write");
    result = v7;
    goto LABEL_5;
  }
  if ( !(unsigned int)wait_for_completion_timeout(a1 + 344, 250) )
  {
    v7 = -110;
    goto LABEL_9;
  }
  result = 0;
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
