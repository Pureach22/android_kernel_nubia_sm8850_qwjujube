__int64 __fastcall qcom_glink_advertise_intent(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x1
  __int64 result; // x0
  int v8; // w3
  __int64 v9; // x7
  int v10; // w8
  __int64 v11; // x9
  _WORD v12[2]; // [xsp+8h] [xbp-18h] BYREF
  int v13; // [xsp+Ch] [xbp-14h]
  int v14; // [xsp+10h] [xbp-10h]
  int v15; // [xsp+14h] [xbp-Ch]
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = raw_spin_lock_irqsave(a2 + 144);
  if ( *(_BYTE *)(a3 + 26) == 1 )
  {
    result = raw_spin_unlock_irqrestore(a2 + 144, v6);
  }
  else
  {
    *(_BYTE *)(a3 + 26) = 1;
    raw_spin_unlock_irqrestore(a2 + 144, v6);
    v8 = *(_DWORD *)(a2 + 136);
    v9 = *(_QWORD *)(a3 + 16);
    v12[0] = 5;
    v10 = *(_DWORD *)(a3 + 8);
    v11 = *(_QWORD *)(a2 + 112);
    v12[1] = v8;
    v13 = 1;
    v14 = v9;
    v15 = v10;
    if ( v11 )
      ipc_log_string(
        *(_QWORD *)(v11 + 256),
        "%s[%d:%d] %s: count:%d size:%zd liid:%d\n",
        *(const char **)(a2 + 128),
        v8,
        *(_DWORD *)(a2 + 140),
        "qcom_glink_advertise_intent",
        1,
        v9,
        v10);
    result = qcom_glink_tx(a1, (__int64)v12, 16, 0, 0, 1);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
