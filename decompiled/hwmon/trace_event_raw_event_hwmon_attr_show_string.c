__int64 __fastcall trace_event_raw_event_hwmon_attr_show_string(__int64 a1, int a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x8
  int offsets_hwmon_attr_show_string; // w0
  __int64 result; // x0
  int v9; // w8
  int v10; // w9
  const char *v11; // x10
  __int64 v12; // x19
  __int64 v13; // x22
  const char *v14; // x1
  size_t v15; // x20
  int v16; // w8
  void *v17; // x19
  const char *v18; // x1
  size_t v19; // x20
  __int64 v20; // [xsp+8h] [xbp-68h]
  __int64 v21; // [xsp+10h] [xbp-60h]
  _QWORD v22[6]; // [xsp+18h] [xbp-58h] BYREF
  __int64 v23; // [xsp+48h] [xbp-28h] BYREF
  const char *v24; // [xsp+50h] [xbp-20h]
  __int64 v25; // [xsp+58h] [xbp-18h]
  const char *v26; // [xsp+60h] [xbp-10h]
  __int64 v27; // [xsp+68h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 72);
  memset(v22, 0, sizeof(v22));
  if ( (v6 & 0x2C0) == 0
    || (v6 & 0x100) != 0
    || (v20 = a3, v21 = a4, result = _trace_trigger_soft_disabled(a1), a3 = v20, a4 = v21, (result & 1) == 0) )
  {
    v25 = 0;
    v26 = nullptr;
    v23 = 0;
    v24 = nullptr;
    offsets_hwmon_attr_show_string = trace_event_get_offsets_hwmon_attr_show_string(&v23, a3, a4);
    result = trace_event_buffer_reserve(v22, a1, offsets_hwmon_attr_show_string + 20LL);
    if ( result )
    {
      v9 = v23;
      v10 = v25;
      v11 = v24;
      *(_DWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 12) = v9;
      *(_DWORD *)(result + 16) = v10;
      v12 = result + (unsigned __int16)v9;
      v13 = result;
      if ( v11 )
        v14 = v11;
      else
        v14 = "(null)";
      v15 = HIWORD(v9) - 1LL;
      memcpy((void *)(result + (unsigned __int16)v9), v14, v15);
      *(_BYTE *)(v12 + v15) = 0;
      v16 = *(_DWORD *)(v13 + 16);
      v17 = (void *)(v13 + (unsigned __int16)v16);
      if ( v26 )
        v18 = v26;
      else
        v18 = "(null)";
      v19 = HIWORD(v16) - 1LL;
      memcpy(v17, v18, v19);
      *((_BYTE *)v17 + v19) = 0;
      result = trace_event_buffer_commit(v22);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
