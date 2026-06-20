__int64 __fastcall trace_event_raw_event_cam_icp_fw_dbg(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x8
  int offsets_cam_icp_fw_dbg; // w0
  __int64 result; // x0
  int v8; // w8
  const char *v9; // x11
  __int64 v10; // x23
  __int64 v11; // x20
  const char *v12; // x1
  size_t v13; // x21
  const char *v14; // x10
  int v15; // w8
  void *v16; // x20
  const char *v17; // x1
  size_t v18; // x19
  _QWORD v19[6]; // [xsp+8h] [xbp-58h] BYREF
  __int64 v20; // [xsp+38h] [xbp-28h] BYREF
  const char *v21; // [xsp+40h] [xbp-20h]
  __int64 v22; // [xsp+48h] [xbp-18h]
  const char *v23; // [xsp+50h] [xbp-10h]
  __int64 v24; // [xsp+58h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 72);
  memset(v19, 0, sizeof(v19));
  if ( (v5 & 0x2C0) == 0 || (v5 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    v22 = 0;
    v23 = nullptr;
    v20 = 0;
    v21 = nullptr;
    offsets_cam_icp_fw_dbg = trace_event_get_offsets_cam_icp_fw_dbg(&v20);
    result = trace_event_buffer_reserve(v19, a1, offsets_cam_icp_fw_dbg + 32LL);
    if ( result )
    {
      v8 = v20;
      v9 = v21;
      v10 = result;
      *(_DWORD *)(result + 24) = v22;
      v11 = result + (unsigned __int16)v8;
      *(_DWORD *)(result + 8) = v8;
      if ( v9 )
        v12 = v9;
      else
        v12 = "(null)";
      v13 = HIWORD(v8) - 1LL;
      memcpy((void *)(result + (unsigned __int16)v8), v12, v13);
      *(_BYTE *)(v11 + v13) = 0;
      v14 = v23;
      v15 = *(_DWORD *)(v10 + 24);
      *(_QWORD *)(v10 + 16) = a3;
      v16 = (void *)(v10 + (unsigned __int16)v15);
      if ( v14 )
        v17 = v14;
      else
        v17 = "(null)";
      v18 = HIWORD(v15) - 1LL;
      memcpy(v16, v17, v18);
      *((_BYTE *)v16 + v18) = 0;
      result = trace_event_buffer_commit(v19);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
