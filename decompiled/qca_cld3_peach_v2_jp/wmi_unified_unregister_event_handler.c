__int64 __fastcall wmi_unified_unregister_event_handler(
        _QWORD *a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  const char *v10; // x2
  __int64 v11; // x4
  __int64 v12; // x19
  __int64 v13; // x10
  __int64 v14; // x20
  __int64 v15; // x8
  __int64 v16; // x11
  unsigned int v19; // w9
  unsigned __int64 StatusReg; // x8
  __int64 v21; // x8

  if ( !a1 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: WMI handle is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wmi_unified_unregister_event_handler");
    return 16;
  }
  if ( a2 >= 0x10F )
  {
    v10 = "%s: Event id %d is unavailable";
    v11 = a2;
LABEL_15:
    qdf_trace_msg(0x31u, 2u, v10, a3, a4, a5, a6, a7, a8, a9, a10, "wmi_unified_unregister_event_handler", v11);
    return 16;
  }
  v11 = *(unsigned int *)(a1[93] + 4LL * a2);
  if ( (_DWORD)v11 )
  {
    v12 = a1[95];
    LODWORD(v13) = *(_DWORD *)(v12 + 3112);
    if ( !(_DWORD)v13 )
      goto LABEL_14;
    v14 = 0;
    v15 = 0;
    v13 = (unsigned int)v13 >= 0x100 ? 256LL : (unsigned int)v13;
    while ( 1 )
    {
      if ( *(_DWORD *)(a1[5] + 4 * v15) == (_DWORD)v11 )
      {
        v16 = a1[6];
        if ( *(_QWORD *)(v16 + 8 * v15) )
          break;
      }
      ++v15;
      v14 += 8;
      if ( v13 == v15 )
        goto LABEL_14;
    }
    if ( v15 == 0xFFFFFFFFLL )
    {
LABEL_14:
      v10 = "%s: event handler is not registered: evt id 0x%x";
      goto LABEL_15;
    }
    *(_QWORD *)(v16 + 8 * v15) = 0;
    *(_DWORD *)(a1[5] + 4 * v15) = 0;
    v19 = *(_DWORD *)(v12 + 3112) - 1;
    *(_DWORD *)(v12 + 3112) = v19;
    *(_QWORD *)(a1[6] + 8 * v15) = *(_QWORD *)(a1[6] + 8LL * v19);
    *(_DWORD *)(a1[5] + 4 * v15) = *(_DWORD *)(a1[5] + 4LL * *(unsigned int *)(v12 + 3112));
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v12 + 5168);
    }
    else
    {
      raw_spin_lock_bh(v12 + 5168);
      *(_QWORD *)(v12 + 5176) |= 1uLL;
    }
    *(_DWORD *)(a1[7] + v14) = *(_DWORD *)(a1[7] + 8LL * *(unsigned int *)(v12 + 3112));
    *(_DWORD *)(a1[7] + v14 + 4) = *(_DWORD *)(a1[7] + 8LL * *(unsigned int *)(v12 + 3112) + 4);
    v21 = *(_QWORD *)(v12 + 5176);
    if ( (v21 & 1) != 0 )
    {
      *(_QWORD *)(v12 + 5176) = v21 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v12 + 5168);
    }
    else
    {
      raw_spin_unlock(v12 + 5168);
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Event id %d is not supported",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wmi_unified_unregister_event_handler",
      a2);
    return 11;
  }
}
