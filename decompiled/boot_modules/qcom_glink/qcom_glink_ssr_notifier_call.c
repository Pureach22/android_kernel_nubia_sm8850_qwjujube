__int64 __fastcall qcom_glink_ssr_notifier_call(__int64 a1, int a2, char *s)
{
  __int64 v5; // x20
  int v6; // w8
  size_t v7; // x0
  unsigned __int64 v8; // x2
  __int64 v10; // [xsp+8h] [xbp-38h] BYREF
  int v11; // [xsp+10h] [xbp-30h]
  int v12; // [xsp+14h] [xbp-2Ch]
  _QWORD v13[5]; // [xsp+18h] [xbp-28h] BYREF

  v13[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_DWORD *)(a1 + 32) = 0;
  v5 = a1 + 32;
  v6 = *(_DWORD *)(a1 + 24);
  v10 = 0;
  ++v6;
  v13[0] = 0;
  v13[1] = 0;
  *(_DWORD *)(a1 + 24) = v6;
  v13[2] = 0;
  v13[3] = 0;
  v11 = v6;
  v12 = strlen(s);
  v7 = strnlen(s, 0x20u);
  if ( v7 == -1 )
  {
    _fortify_panic(2, -1, 0);
    goto LABEL_12;
  }
  if ( v7 == 32 )
    v8 = 32;
  else
    v8 = v7 + 1;
  if ( v8 >= 0x21 )
LABEL_12:
    _fortify_panic(7, 32, v8);
  sized_strscpy(v13, s);
  if ( (rpmsg_send(*(_QWORD *)(a1 - 8), &v10, 48) & 0x80000000) != 0 )
    dev_err(*(_QWORD *)(a1 - 16), "failed to send cleanup message\n");
  if ( !(unsigned int)wait_for_completion_timeout(v5, 250) )
    dev_err(*(_QWORD *)(a1 - 16), "timeout waiting for cleanup done message\n");
  _ReadStatusReg(SP_EL0);
  return 0;
}
