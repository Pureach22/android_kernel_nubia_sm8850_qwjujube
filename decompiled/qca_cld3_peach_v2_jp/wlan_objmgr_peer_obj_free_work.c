__int64 __fastcall wlan_objmgr_peer_obj_free_work(
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
  unsigned __int64 StatusReg; // x8
  __int64 v11; // x8
  __int64 result; // x0
  unsigned __int64 v13; // x23
  __int64 v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x7
  int v24; // w8
  int v25; // w10
  int v26; // w11
  __int64 v27; // x22
  __int64 v28; // [xsp+0h] [xbp-30h]
  __int64 v29; // [xsp+8h] [xbp-28h]
  __int64 v30; // [xsp+10h] [xbp-20h]
  _QWORD v31[2]; // [xsp+20h] [xbp-10h] BYREF

  v31[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31[0] = 0;
  if ( a1 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 1256);
    }
    else
    {
      raw_spin_lock_bh(a1 + 1256);
      *(_QWORD *)(a1 + 1264) |= 1uLL;
    }
    if ( !qdf_list_empty((_QWORD *)(a1 + 1272)) )
    {
      v13 = _ReadStatusReg(SP_EL0);
      do
      {
        qdf_list_remove_front((_DWORD *)(a1 + 1272), v31);
        v14 = *(_QWORD *)(a1 + 1264);
        if ( (v14 & 1) != 0 )
        {
          *(_QWORD *)(a1 + 1264) = v14 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 1256);
        }
        else
        {
          raw_spin_unlock(a1 + 1256);
        }
        if ( v31[0] == -16 )
        {
          v25 = 0;
          v23 = 0;
          v24 = 0;
          v26 = 0;
        }
        else
        {
          v23 = *(unsigned __int8 *)(v31[0] + 16LL);
          v24 = *(unsigned __int8 *)(v31[0] + 17LL);
          v25 = *(unsigned __int8 *)(v31[0] + 18LL);
          v26 = *(unsigned __int8 *)(v31[0] + 21LL);
        }
        v27 = v31[0] - 32LL;
        LODWORD(v30) = v26;
        LODWORD(v29) = v25;
        LODWORD(v28) = v24;
        qdf_trace_msg(
          0x57u,
          8u,
          "%s: active_work_cnt %u list size %u peer 0x%pK(%02x:%02x:%02x:**:**:%02x)",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "wlan_objmgr_peer_obj_free_work",
          *(unsigned int *)(a1 + 1344),
          *(unsigned int *)(a1 + 1288),
          v31[0] - 32LL,
          v23,
          v28,
          v29,
          v30);
        _wlan_objmgr_peer_obj_destroy(v27);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v13 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v13 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(a1 + 1256);
        }
        else
        {
          raw_spin_lock_bh(a1 + 1256);
          *(_QWORD *)(a1 + 1264) |= 1uLL;
        }
      }
      while ( !qdf_list_empty((_QWORD *)(a1 + 1272)) );
    }
    v11 = *(_QWORD *)(a1 + 1264);
    --*(_DWORD *)(a1 + 1344);
    if ( (v11 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1264) = v11 & 0xFFFFFFFFFFFFFFFELL;
      result = raw_spin_unlock_bh(a1 + 1256);
    }
    else
    {
      result = raw_spin_unlock(a1 + 1256);
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x57u,
               2u,
               "%s: pdev is NULL",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "wlan_objmgr_peer_obj_free_work");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
