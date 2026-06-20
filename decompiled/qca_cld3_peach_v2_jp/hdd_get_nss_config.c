__int64 __fastcall hdd_get_nss_config(__int64 *a1, __int64 a2)
{
  __int64 v3; // x8
  int command; // w0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  const char *v13; // x2
  __int64 result; // x0
  __int64 v15; // [xsp+0h] [xbp-10h] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a1;
  LOBYTE(v15) = 0;
  if ( *(_DWORD *)(v3 + 40) == 1 )
  {
    command = wma_cli_get_command(*((unsigned __int8 *)a1 + 8), 34, 1);
    if ( (command & 0x80000000) == 0 )
    {
      LOBYTE(v15) = command;
      goto LABEL_7;
    }
LABEL_5:
    v13 = "%s: Failed to get nss";
LABEL_9:
    qdf_trace_msg(0x33u, 2u, v13, v5, v6, v7, v8, v9, v10, v11, v12, "hdd_get_nss_config", v15);
    result = 4294967274LL;
    goto LABEL_10;
  }
  if ( (unsigned int)hdd_get_nss(v3, &v15) )
    goto LABEL_5;
  LOBYTE(command) = v15;
LABEL_7:
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: nss %d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "hdd_get_nss_config",
    (unsigned __int8)command,
    v15,
    v16);
  BYTE4(v15) = v15;
  result = nla_put(a2, 70, 1, (char *)&v15 + 4);
  if ( (_DWORD)result )
  {
    v13 = "%s: nla_put failure";
    goto LABEL_9;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
