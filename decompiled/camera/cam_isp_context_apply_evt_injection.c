__int64 __fastcall cam_isp_context_apply_evt_injection(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x20
  __int64 result; // x0
  int v5; // w6
  int v6; // w7
  unsigned int v7; // w19
  _QWORD v8[3]; // [xsp+8h] [xbp-18h] BYREF

  v8[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 256);
  v3 = v2 + 45056;
  v8[0] = 0;
  v8[1] = v2 + 45624;
  result = cam_context_apply_evt_injection((unsigned int *)a1, (__int64)v8);
  if ( (_DWORD)result )
  {
    v5 = *(_DWORD *)(a1 + 32);
    v6 = *(_DWORD *)(a1 + 64);
    v7 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_context_apply_evt_injection",
      5731,
      "Fail to apply event injection ctx_id: %u link: 0x%x req_id: %u",
      v5,
      v6,
      *(_QWORD *)(v3 + 576));
    result = v7;
  }
  *(_BYTE *)(v3 + 596) = 0;
  _ReadStatusReg(SP_EL0);
  return result;
}
