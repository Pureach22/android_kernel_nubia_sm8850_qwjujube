__int64 __fastcall trace_event_raw_event_cam_req_mgr_apply_request(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v8; // x8
  int v9; // w23
  __int64 result; // x0
  __int64 v11; // x22
  int v12; // w8
  size_t v13; // x23
  __int64 v14; // x24
  __int64 v15; // x8
  _QWORD v16[7]; // [xsp+8h] [xbp-38h] BYREF

  v16[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 72);
  memset(v16, 0, 48);
  if ( (v8 & 0x2C0) == 0 || (v8 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    v9 = strlen((const char *)(a4 + 28)) + 1;
    result = trace_event_buffer_reserve(v16, a1, v9 + 48LL);
    if ( result )
    {
      v11 = result + 48;
      v12 = (v9 << 16) | 0x30;
      v13 = (unsigned __int16)v9 - 1LL;
      v14 = result;
      *(_DWORD *)(result + 8) = v12;
      memcpy((void *)(result + 48), (const void *)(a4 + 28), v13);
      *(_BYTE *)(v11 + v13) = 0;
      *(_DWORD *)(v14 + 12) = *(_DWORD *)(a4 + 284);
      v15 = *(_QWORD *)(a3 + 8);
      *(_QWORD *)(v14 + 32) = a2;
      *(_QWORD *)(v14 + 16) = v15;
      *(_QWORD *)(v14 + 40) = *(_QWORD *)(a2 + 33160);
      *(_DWORD *)(v14 + 24) = *(_DWORD *)a3;
      result = trace_event_buffer_commit(v16);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
