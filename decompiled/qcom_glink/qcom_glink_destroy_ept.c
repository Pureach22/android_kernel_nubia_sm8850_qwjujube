__int64 __fastcall qcom_glink_destroy_ept(__int64 a1)
{
  __int64 v2; // x19
  __int64 v3; // x1
  int v4; // w3
  __int64 v5; // x8
  __int64 result; // x0
  _QWORD v7[2]; // [xsp+0h] [xbp-10h] BYREF

  v7[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 112);
  v3 = raw_spin_lock_irqsave(a1 + 124);
  if ( *(_QWORD *)(a1 + 16) )
  {
    *(_QWORD *)(a1 + 16) = 0;
    raw_spin_unlock_irqrestore(a1 + 124, v3);
    v4 = *(_DWORD *)(a1 + 136);
    v5 = *(_QWORD *)(a1 + 112);
    v7[0] = 3;
    WORD1(v7[0]) = v4;
    if ( v5 )
      ipc_log_string(
        *(_QWORD *)(v5 + 256),
        "%s[%d:%d] %s: \n",
        *(const char **)(a1 + 128),
        v4,
        *(_DWORD *)(a1 + 140),
        "qcom_glink_send_close_req");
    result = qcom_glink_tx(v2, (__int64)v7, 8, 0, 0, 1);
  }
  else
  {
    result = raw_spin_unlock_irqrestore(a1 + 124, v3);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
