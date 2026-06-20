__int64 __fastcall wmi_unified_unregister_event(
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
  int v10; // w4
  __int64 v11; // x19
  __int64 v12; // x10
  __int64 v13; // x20
  __int64 v14; // x8
  __int64 v15; // x11
  const char *v16; // x2
  unsigned int v17; // w1
  unsigned int v20; // w9
  unsigned __int64 StatusReg; // x8
  __int64 v22; // x8

  if ( !a1 )
  {
    qdf_trace_msg(0x31u, 2u, "%s: WMI handle is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "wmi_unified_unregister_event");
    return 16;
  }
  if ( a2 > 0x10E || (v10 = *(_DWORD *)(a1[93] + 4LL * a2)) == 0 )
  {
    v16 = "%s: Event id %d is unavailable";
    v17 = 4;
    goto LABEL_14;
  }
  v11 = a1[95];
  LODWORD(v12) = *(_DWORD *)(v11 + 3112);
  if ( !(_DWORD)v12 )
    goto LABEL_12;
  v13 = 0;
  v14 = 0;
  v12 = (unsigned int)v12 >= 0x100 ? 256LL : (unsigned int)v12;
  while ( 1 )
  {
    if ( *(_DWORD *)(a1[5] + 4 * v14) == v10 )
    {
      v15 = a1[6];
      if ( *(_QWORD *)(v15 + 8 * v14) )
        break;
    }
    ++v14;
    v13 += 8;
    if ( v12 == v14 )
      goto LABEL_12;
  }
  if ( v14 == 0xFFFFFFFFLL )
  {
LABEL_12:
    v16 = "%s: event handler is not registered: evt id 0x%x";
    v17 = 3;
LABEL_14:
    qdf_trace_msg(0x31u, v17, v16, a3, a4, a5, a6, a7, a8, a9, a10, "wmi_unified_unregister_event");
    return 16;
  }
  *(_QWORD *)(v15 + 8 * v14) = 0;
  *(_DWORD *)(a1[5] + 4 * v14) = 0;
  v20 = *(_DWORD *)(v11 + 3112) - 1;
  *(_DWORD *)(v11 + 3112) = v20;
  *(_QWORD *)(a1[6] + 8 * v14) = *(_QWORD *)(a1[6] + 8LL * v20);
  *(_DWORD *)(a1[5] + 4 * v14) = *(_DWORD *)(a1[5] + 4LL * *(unsigned int *)(v11 + 3112));
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v11 + 5168);
  }
  else
  {
    raw_spin_lock_bh(v11 + 5168);
    *(_QWORD *)(v11 + 5176) |= 1uLL;
  }
  *(_DWORD *)(a1[7] + v13) = *(_DWORD *)(a1[7] + 8LL * *(unsigned int *)(v11 + 3112));
  *(_DWORD *)(a1[7] + v13 + 4) = *(_DWORD *)(a1[7] + 8LL * *(unsigned int *)(v11 + 3112) + 4);
  v22 = *(_QWORD *)(v11 + 5176);
  if ( (v22 & 1) != 0 )
  {
    *(_QWORD *)(v11 + 5176) = v22 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v11 + 5168);
  }
  else
  {
    raw_spin_unlock(v11 + 5168);
  }
  return 0;
}
