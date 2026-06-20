__int64 __fastcall wlan_mlo_ap_delete_assoc_list_entries(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  const char *v10; // x2
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  int v13; // w0
  _QWORD *v14; // x20
  int v15; // w21
  unsigned int v16; // w0
  __int64 v17; // x23
  int v18; // w0
  _QWORD *v19; // x24
  int v20; // w21
  __int64 v21; // x8
  __int64 v22; // x20
  _QWORD v23[2]; // [xsp+0h] [xbp-10h] BYREF

  v23[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v10 = "%s: assoc pending list is empty";
    goto LABEL_5;
  }
  if ( !qdf_list_empty((_QWORD *)a1) )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 88);
    }
    else
    {
      raw_spin_lock_bh(a1 + 88);
      *(_QWORD *)(a1 + 96) |= 1uLL;
    }
    v23[0] = 0;
    v13 = qdf_list_peek_front((_QWORD *)a1, v23);
    v14 = (_QWORD *)v23[0];
    v15 = v13;
    v16 = jiffies_to_msecs(jiffies);
    if ( v15 || !v14 )
    {
LABEL_17:
      if ( qdf_list_empty((_QWORD *)a1) && *(_BYTE *)(a1 + 24) == 1 )
      {
        *(_BYTE *)(a1 + 24) = 0;
        timer_delete((timer_t)(a1 + 32));
      }
      v21 = *(_QWORD *)(a1 + 96);
      if ( (v21 & 1) != 0 )
      {
LABEL_24:
        *(_QWORD *)(a1 + 96) = v21 & 0xFFFFFFFFFFFFFFFELL;
        result = raw_spin_unlock_bh(a1 + 88);
        goto LABEL_22;
      }
    }
    else
    {
      v17 = v16;
      while ( 1 )
      {
        v23[0] = 0;
        v18 = qdf_list_peek_next((_QWORD *)a1, v14, v23);
        v19 = (_QWORD *)v23[0];
        v20 = v18;
        if ( *(__int64 *)((char *)&off_10 + (_QWORD)v14) - v17 + 3000 >= 0 && *(_BYTE *)(a1 + 25) != 1 )
          break;
        qdf_list_remove_node(a1, v14);
        _qdf_mem_free((__int64)v14);
        if ( !v20 )
        {
          v14 = v19;
          if ( v19 )
            continue;
        }
        goto LABEL_17;
      }
      v22 = jiffies;
      *(_QWORD *)(a1 + 48) = v22 + 750LL * (unsigned int)qdf_timer_get_multiplier();
      add_timer(a1 + 32);
      v21 = *(_QWORD *)(a1 + 96);
      *(_BYTE *)(a1 + 24) = 1;
      if ( (v21 & 1) != 0 )
        goto LABEL_24;
    }
    result = raw_spin_unlock(a1 + 88);
    goto LABEL_22;
  }
  v10 = "%s: list is empty";
LABEL_5:
  result = qdf_trace_msg(0x8Fu, 8u, v10, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_mlo_ap_delete_assoc_list_entries");
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
