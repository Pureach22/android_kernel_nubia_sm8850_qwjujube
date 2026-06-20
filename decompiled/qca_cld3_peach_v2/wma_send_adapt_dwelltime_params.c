__int64 __fastcall wma_send_adapt_dwelltime_params(__int64 *a1, __int64 a2)
{
  char v2; // w8
  int v3; // w9
  __int64 v4; // x0
  char v5; // w8
  int v6; // w0
  __int64 v8; // [xsp+8h] [xbp-18h] BYREF
  __int64 v9; // [xsp+10h] [xbp-10h]
  __int64 v10; // [xsp+18h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_BYTE *)(a2 + 4);
  v3 = *(unsigned __int8 *)(a2 + 5);
  v8 = 0;
  v9 = 0;
  v4 = *a1;
  BYTE4(v8) = v2;
  v5 = *(_BYTE *)(a2 + 6);
  LODWORD(v9) = v3;
  LOWORD(v3) = *(_WORD *)(a2 + 7);
  BYTE4(v9) = v5;
  *(_WORD *)((char *)&v9 + 5) = v3;
  v6 = wmi_unified_send_adapt_dwelltime_params_cmd(v4, &v8);
  _ReadStatusReg(SP_EL0);
  return 16 * (unsigned int)(v6 != 0);
}
