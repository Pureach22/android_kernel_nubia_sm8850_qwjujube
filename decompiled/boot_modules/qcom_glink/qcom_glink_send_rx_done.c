__int64 __fastcall qcom_glink_send_rx_done(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  int v6; // w19
  int v7; // w8
  int v8; // w20
  __int16 v9; // w8
  __int64 result; // x0
  __int64 v11; // x8
  const char *v12; // x2
  int v13; // w3
  int v14; // w4
  unsigned int v15; // w21
  _WORD v16[2]; // [xsp+0h] [xbp-10h] BYREF
  int v17; // [xsp+4h] [xbp-Ch]
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(unsigned __int8 *)(a3 + 24);
  v7 = *(_DWORD *)(a2 + 136);
  v8 = *(_DWORD *)(a3 + 8);
  *(_DWORD *)(a3 + 28) = 0;
  v16[1] = v7;
  if ( v6 )
    v9 = 14;
  else
    v9 = 6;
  v17 = v8;
  v16[0] = v9;
  result = qcom_glink_tx(a1, v16, 8, 0, 0, a4);
  if ( (_DWORD)result )
    goto LABEL_9;
  if ( *(_QWORD *)(a3 + 16) )
  {
    if ( (v6 & 1) != 0 )
      goto LABEL_7;
LABEL_11:
    kfree(*(_QWORD *)a3);
    kfree(a3);
    result = 0;
    v11 = *(_QWORD *)(a2 + 112);
    if ( !v11 )
      goto LABEL_9;
    goto LABEL_8;
  }
  *(_QWORD *)a3 = 0;
  if ( (v6 & 1) == 0 )
    goto LABEL_11;
LABEL_7:
  v11 = *(_QWORD *)(a2 + 112);
  if ( v11 )
  {
LABEL_8:
    v12 = *(const char **)(a2 + 128);
    v13 = *(_DWORD *)(a2 + 136);
    v14 = *(_DWORD *)(a2 + 140);
    v15 = result;
    ipc_log_string(
      *(_QWORD *)(v11 + 256),
      "%s[%d:%d] %s: reuse:%d liid:%d",
      v12,
      v13,
      v14,
      "qcom_glink_send_rx_done",
      v6,
      v8);
    result = v15;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
