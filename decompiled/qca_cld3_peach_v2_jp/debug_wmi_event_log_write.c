__int64 __fastcall debug_wmi_event_log_write(__int64 a1, unsigned __int64 a2, size_t a3)
{
  __int64 v3; // x8
  __int64 result; // x0
  __int64 v5; // x21
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned __int64 StatusReg; // x8
  _DWORD *v17; // x8
  __int64 v18; // x8
  int v19; // [xsp+Ch] [xbp-44h] BYREF
  char s[8]; // [xsp+10h] [xbp-40h] BYREF
  __int64 v21; // [xsp+18h] [xbp-38h]
  __int64 v22; // [xsp+20h] [xbp-30h]
  __int64 v23; // [xsp+28h] [xbp-28h]
  __int64 v24; // [xsp+30h] [xbp-20h]
  __int64 v25; // [xsp+38h] [xbp-18h]
  __int16 v26; // [xsp+40h] [xbp-10h]
  __int64 v27; // [xsp+48h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 32);
  result = -14;
  v26 = 0;
  v24 = 0;
  v25 = 0;
  v5 = *(_QWORD *)(v3 + 128);
  v22 = 0;
  v23 = 0;
  *(_QWORD *)s = 0;
  v21 = 0;
  if ( a2 && a3 <= 0x32 )
  {
    v19 = 0;
    _check_object_size(s, a3, 0);
    if ( inline_copy_from_user_0((__int64)s, a2, a3) )
    {
      result = -14;
    }
    else if ( sscanf(s, "%d", &v19) != 1 || v19 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Wrong input, echo 0 to clear the wmi buffer",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "debug_wmi_event_log_write");
      result = -22;
    }
    else
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v5 + 664);
      }
      else
      {
        raw_spin_lock_bh(v5 + 664);
        *(_QWORD *)(v5 + 672) |= 1uLL;
      }
      qdf_mem_set(*(void **)(v5 + 472), (unsigned int)(32 * wmi_event_log_max_entry), 0);
      v17 = *(_DWORD **)(v5 + 488);
      *(_DWORD *)(v5 + 480) = 0;
      *v17 = 0;
      v18 = *(_QWORD *)(v5 + 672);
      if ( (v18 & 1) != 0 )
      {
        *(_QWORD *)(v5 + 672) = v18 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v5 + 664);
      }
      else
      {
        raw_spin_unlock(v5 + 664);
      }
      result = a3;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
