__int64 __fastcall wlan_dp_svc_deinit(
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
  __int64 v9; // x20
  unsigned __int64 StatusReg; // x8
  __int64 i; // x21
  _QWORD *v13; // x1
  __int64 v14; // x8
  __int64 v15; // x0
  const char *v16; // x2
  unsigned int v17; // w1
  const char *v18; // x2
  const char *v19; // x3
  unsigned int v20; // w0
  __int64 result; // x0
  __int64 v22; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v23[2]; // [xsp+10h] [xbp-20h] BYREF
  __int64 v24; // [xsp+20h] [xbp-10h]
  __int64 v25; // [xsp+28h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 1552);
    v22 = 0;
    if ( v9 )
    {
      v23[0] = v23;
      v23[1] = v23;
      v24 = 0;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v9 + 264);
      }
      else
      {
        raw_spin_lock_bh(v9 + 264);
        *(_QWORD *)(v9 + 272) |= 1uLL;
      }
      for ( i = 0; i != 256; i += 8 )
      {
        v13 = *(_QWORD **)(v9 + i);
        if ( v13 )
        {
          *(_QWORD *)(v9 + i) = 0;
          --*(_DWORD *)(v9 + 256);
          qdf_list_insert_back(v23, v13);
        }
      }
      v14 = *(_QWORD *)(v9 + 272);
      if ( (v14 & 1) != 0 )
      {
        *(_QWORD *)(v9 + 272) = v14 & 0xFFFFFFFFFFFFFFFELL;
        v15 = raw_spin_unlock_bh(v9 + 264);
      }
      else
      {
        v15 = raw_spin_unlock(v9 + 264);
      }
      synchronize_rcu(v15);
      while ( !qdf_list_empty(v23) )
      {
        qdf_list_remove_front(v23, &v22);
        _qdf_mem_free(v22);
      }
      if ( !(_DWORD)v24 )
        goto LABEL_22;
      v18 = "%s: list length not equal to zero";
      v19 = "qdf_list_destroy";
      v20 = 51;
    }
    else
    {
      v18 = "%s: svc_ctx is not initialised";
      v19 = "dp_svc_delete_all";
      v20 = 69;
    }
    qdf_trace_msg(v20, 2u, v18, a2, a3, a4, a5, a6, a7, a8, a9, v19);
LABEL_22:
    _qdf_mem_free(v9);
    v16 = "%s: service_class deinit successful";
    v17 = 5;
    *(_QWORD *)(a1 + 1552) = 0;
    goto LABEL_23;
  }
  v16 = "%s: DP context not found";
  v17 = 2;
LABEL_23:
  result = qdf_trace_msg(0x45u, v17, v16, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_dp_svc_deinit");
  _ReadStatusReg(SP_EL0);
  return result;
}
