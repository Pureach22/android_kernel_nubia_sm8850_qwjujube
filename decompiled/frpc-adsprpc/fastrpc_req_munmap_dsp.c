__int64 __fastcall fastrpc_req_munmap_dsp(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w8
  __int64 result; // x0
  _QWORD v5[3]; // [xsp+0h] [xbp-B0h] BYREF
  _QWORD v6[15]; // [xsp+18h] [xbp-98h] BYREF
  _QWORD v7[4]; // [xsp+90h] [xbp-20h] BYREF

  v7[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a1 + 244);
  v5[1] = a2;
  v7[2] = 0;
  v5[0] = v3;
  v7[0] = v5;
  v7[1] = 24;
  v5[2] = a3;
  v6[0] = 0x501000000000001LL;
  v6[1] = v7;
  memset(&v6[2], 0, 104);
  result = fastrpc_internal_invoke(a1, 1, v6);
  _ReadStatusReg(SP_EL0);
  return result;
}
