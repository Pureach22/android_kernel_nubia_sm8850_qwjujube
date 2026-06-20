__int64 __fastcall hif_exec_event(__int64 a1, int a2, unsigned __int64 a3)
{
  unsigned __int64 StatusReg; // x8
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  int v16; // w8
  unsigned int v17; // w21
  unsigned __int64 v18; // x8
  __int64 v19; // x8
  _DWORD *v20; // x20
  __int64 v21; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 752);
    if ( a2 > 3 )
      goto LABEL_5;
LABEL_24:
    if ( (unsigned int)(a2 - 1) < 3 )
      goto LABEL_26;
    goto LABEL_25;
  }
  raw_spin_lock_bh(a1 + 752);
  *(_QWORD *)(a1 + 760) |= 1uLL;
  if ( a2 <= 3 )
    goto LABEL_24;
LABEL_5:
  if ( a2 > 5 )
  {
    if ( a2 == 6 )
    {
      v17 = ((__int64 (__fastcall *)(__int64, __int64, __int64))hif_exec_cpu_migrate)(a1 + 744, 0xFFFFFFFFLL, 1);
      if ( a3 || v17 )
        goto LABEL_27;
      goto LABEL_22;
    }
    if ( a2 == 7 )
    {
      v16 = *(_DWORD *)(a1 + 780);
      v17 = 0;
      *(_DWORD *)(a1 + 2424) = 0;
      if ( v16 )
        goto LABEL_27;
      goto LABEL_12;
    }
LABEL_25:
    qdf_trace_msg(
      0x3Du,
      2u,
      "%s: Unknown event: %d (data=0x%0lx)",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "hif_exec_event",
      (unsigned int)a2,
      a3);
    goto LABEL_26;
  }
  if ( a2 == 4 )
  {
    if ( (unsigned __int8)a3 == 1 && *(_DWORD *)(a1 + 2424) == 2 )
    {
      v18 = (int)(a3 >> 16);
      if ( v18 >= 0x20 )
      {
        __break(0x5512u);
        __asm { PRFM            #0x13, [X5,#0x4938] }
        JUMPOUT(0x7198DC);
      }
      v19 = a1 + 48LL * (int)v18;
      if ( *(_DWORD *)(v19 + 916) )
      {
        v20 = (_DWORD *)(v19 + 916);
        v17 = ((__int64 (__fastcall *)(__int64))hif_exec_cpu_migrate)(a1 + 744);
        *v20 = 0;
        goto LABEL_27;
      }
    }
    goto LABEL_26;
  }
  if ( (_DWORD)a3 != 1 )
  {
    v17 = ((__int64 (__fastcall *)(__int64, __int64, __int64))hif_exec_cpu_migrate)(
            a1 + 744,
            0xFFFFFFFFLL,
            0xFFFFFFFFLL);
    *(_DWORD *)(a1 + 2424) = a3;
LABEL_22:
    hif_napi_cpu_denylist(a1 + 744, 2);
    goto LABEL_27;
  }
  *(_DWORD *)(a1 + 2424) = 1;
LABEL_12:
  hif_napi_cpu_denylist(a1 + 744, 1);
LABEL_26:
  v17 = 0;
LABEL_27:
  v21 = *(_QWORD *)(a1 + 760);
  if ( (v21 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 760) = v21 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 752);
  }
  else
  {
    raw_spin_unlock(a1 + 752);
  }
  return v17;
}
