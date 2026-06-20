__int64 __fastcall hdd_get_tx_ampdu(__int64 a1, __int64 a2)
{
  int command; // w0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 result; // x0
  const char *v13; // x2
  _BYTE v14[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  command = wma_cli_get_command(*(unsigned __int8 *)(a1 + 8), 7, 3);
  if ( command < 0 )
  {
    v13 = "%s: Failed to get tx_ampdu";
    goto LABEL_5;
  }
  v14[0] = command;
  result = nla_put(a2, 8, 1, v14);
  if ( (_DWORD)result )
  {
    v13 = "%s: nla_put failure";
LABEL_5:
    qdf_trace_msg(0x33u, 2u, v13, v4, v5, v6, v7, v8, v9, v10, v11, "hdd_get_tx_ampdu");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
