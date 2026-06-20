__int64 __fastcall trace_event_raw_event_cam_req_mgr_connect_device(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x8
  int v7; // w22
  __int64 result; // x0
  __int64 v9; // x21
  int v10; // w8
  size_t v11; // x22
  __int64 v12; // x23
  int v13; // w8
  _QWORD v14[7]; // [xsp+8h] [xbp-38h] BYREF

  v14[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 72);
  memset(v14, 0, 48);
  if ( (v6 & 0x2C0) == 0 || (v6 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    v7 = strlen((const char *)(a3 + 4)) + 1;
    result = trace_event_buffer_reserve(v14, a1, v7 + 40LL);
    if ( result )
    {
      v9 = result + 40;
      v10 = (v7 << 16) | 0x28;
      v11 = (unsigned __int16)v7 - 1LL;
      v12 = result;
      *(_DWORD *)(result + 8) = v10;
      memcpy((void *)(result + 40), (const void *)(a3 + 4), v11);
      *(_BYTE *)(v9 + v11) = 0;
      *(_DWORD *)(v12 + 12) = *(_DWORD *)(a3 + 260);
      v13 = *(_DWORD *)(a3 + 264);
      *(_QWORD *)(v12 + 24) = a2;
      *(_DWORD *)(v12 + 16) = v13;
      *(_QWORD *)(v12 + 32) = *(_QWORD *)(a2 + 33160);
      result = trace_event_buffer_commit(v14);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
