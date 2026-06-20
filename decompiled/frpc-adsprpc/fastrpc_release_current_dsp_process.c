__int64 __fastcall fastrpc_release_current_dsp_process(__int64 a1)
{
  __int64 result; // x0
  int v2; // [xsp+4h] [xbp-9Ch] BYREF
  _QWORD v3[15]; // [xsp+8h] [xbp-98h] BYREF
  _QWORD v4[4]; // [xsp+80h] [xbp-20h] BYREF

  v4[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 244);
  v4[0] = &v2;
  v4[1] = 4;
  v4[2] = 0xFFFFFFFFLL;
  v3[0] = 0x101000000000001LL;
  v3[1] = v4;
  memset(&v3[2], 0, 104);
  result = fastrpc_internal_invoke(a1, 2, v3);
  _ReadStatusReg(SP_EL0);
  return result;
}
