__int64 __fastcall wmi_register_event_handler_with_ctx(
        _QWORD *a1,
        unsigned int a2,
        __int64 a3,
        int a4,
        int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  const char *v14; // x2
  unsigned int v15; // w1
  __int64 v16; // x4
  unsigned int v18; // w19
  __int64 v19; // x20
  unsigned int v20; // w8
  __int64 v21; // x9
  __int64 v22; // x11
  __int64 v27; // x23
  unsigned __int64 StatusReg; // x8
  __int64 v29; // x8

  if ( a1 )
  {
    if ( a2 >= 0x11D )
    {
      v14 = "%s: Event id %d is unavailable";
      v15 = 4;
      v16 = a2;
LABEL_4:
      qdf_trace_msg(0x31u, v15, v14, a6, a7, a8, a9, a10, a11, a12, a13, "wmi_register_event_handler_with_ctx", v16);
      return 16;
    }
    v18 = *(_DWORD *)(a1[93] + 4LL * a2);
    if ( v18 )
    {
      v19 = a1[95];
      v20 = *(_DWORD *)(v19 + 3112);
      if ( v20 )
      {
        v21 = 0;
        if ( v20 >= 0x100 )
          v22 = 256;
        else
          v22 = v20;
        while ( *(_DWORD *)(a1[5] + 4 * v21) != v18 || !*(_QWORD *)(a1[6] + 8 * v21) )
        {
          if ( v22 == ++v21 )
            goto LABEL_15;
        }
        if ( v21 != 0xFFFFFFFFLL )
        {
          v14 = "%s: event handler already registered 0x%x";
          v15 = 4;
          goto LABEL_26;
        }
LABEL_15:
        if ( v20 != 256 )
          goto LABEL_17;
        v14 = "%s: no more event handlers 0x%x";
        v15 = 2;
LABEL_26:
        v16 = v18;
        goto LABEL_4;
      }
LABEL_17:
      qdf_trace_msg(0x31u, 8u, "Registered event handler for event 0x%8x", a6, a7, a8, a9, a10, a11, a12, a13, v18);
      v27 = *(unsigned int *)(v19 + 3112);
      *(_QWORD *)(a1[6] + 8 * v27) = a3;
      *(_DWORD *)(a1[5] + 4 * v27) = v18;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v19 + 5168);
      }
      else
      {
        raw_spin_lock_bh(v19 + 5168);
        *(_QWORD *)(v19 + 5176) |= 1uLL;
      }
      *(_DWORD *)(a1[7] + 8 * v27) = a4;
      *(_DWORD *)(a1[7] + 8 * v27 + 4) = a5;
      v29 = *(_QWORD *)(v19 + 5176);
      if ( (v29 & 1) != 0 )
      {
        *(_QWORD *)(v19 + 5176) = v29 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v19 + 5168);
      }
      else
      {
        raw_spin_unlock(v19 + 5168);
      }
      ++*(_DWORD *)(v19 + 3112);
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: Event id %d is not supported",
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        "wmi_register_event_handler_with_ctx",
        a2);
      return 11;
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: WMI handle is NULL",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "wmi_register_event_handler_with_ctx");
    return 16;
  }
}
