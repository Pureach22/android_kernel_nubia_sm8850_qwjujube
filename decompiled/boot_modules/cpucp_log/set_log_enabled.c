__int64 __fastcall set_log_enabled(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  unsigned int v4; // w0
  __int64 result; // x0
  unsigned int v6; // w19
  _BOOL4 v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 72);
  v7 = a2 != 0;
  v4 = mbox_send_message(v3, &v7);
  if ( (v4 & 0x80000000) != 0 )
  {
    v6 = v4;
    printk(&unk_8739);
    result = v6;
  }
  else
  {
    mbox_client_txdone(*(_QWORD *)(a1 + 72), 0);
    result = 0;
    *(_DWORD *)(a1 + 196) = v7;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
