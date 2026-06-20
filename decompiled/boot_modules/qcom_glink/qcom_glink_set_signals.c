__int64 __fastcall qcom_glink_set_signals(__int64 a1, char a2, char a3)
{
  __int64 v3; // x19
  unsigned int v4; // w8
  int v5; // w9
  __int64 v6; // x0
  __int64 result; // x0
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v3 = *(_QWORD *)(a1 + 112);
    v4 = *(_DWORD *)(a1 + 436) | a2 & 0xC6;
    if ( (a3 & 2) != 0 )
      v4 = *(_DWORD *)(a1 + 436) & 0xFFFFFFFD | a2 & 0xC4;
    if ( (a3 & 4) != 0 )
      v4 &= ~4u;
    if ( (a3 & 0x40) != 0 )
      v4 &= ~0x40u;
    if ( a3 < 0 )
      v4 &= ~0x80u;
    *(_DWORD *)(a1 + 436) = v4;
    v8[0] = 15;
    v5 = *(_DWORD *)(a1 + 136);
    v6 = *(_QWORD *)(v3 + 256);
    WORD1(v8[0]) = v5;
    HIDWORD(v8[0]) = v4 & 0xFFF
                   | (((v4 >> 2) & 1) << 30) & 0x4FFFFFFF
                   | ((unsigned __int8)(v4 >> 1) << 31)
                   | (((v4 >> 6) & 1) << 29)
                   | (((v4 >> 7) & 1) << 28);
    ipc_log_string(v6, "[%s]: signals:%d\n", "qcom_glink_send_signals");
    result = qcom_glink_tx(v3, v8, 8, 0, 0, 1);
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
