__int64 __fastcall hdd_wlan_tsf_show(__int64 a1, __int64 a2, const char *a3)
{
  int v5; // w21
  _QWORD *v6; // x23
  __int64 v7; // x21
  int v8; // w0
  unsigned __int64 StatusReg; // x9
  __int64 v10; // x26
  __int64 v11; // x8
  unsigned __int64 v12; // x22
  unsigned __int64 v13; // x9
  unsigned __int64 v14; // x10
  unsigned __int64 v15; // x9
  unsigned __int64 v16; // x11
  unsigned __int64 v17; // x10
  bool v18; // cf
  unsigned __int64 v19; // x9
  int v20; // w27
  __int64 v21; // x25
  bool v22; // cf
  unsigned __int64 v23; // x9
  __int64 v24; // x10
  __int64 v26; // x4
  int v27; // w6
  int v28; // w7
  int v29; // w9
  int v30; // w10
  __int64 *v31[2]; // [xsp+30h] [xbp-10h] BYREF

  v31[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v31[0] = nullptr;
  v5 = _osif_vdev_sync_op_start(a1 - 1376, v31, (__int64)"hdd_wlan_tsf_show");
  if ( !v5 )
  {
    if ( *(_DWORD *)(a1 + 1312) != 1885692259 )
    {
      scnprintf(a3, 4096, "Invalid device\n");
      goto LABEL_40;
    }
    v6 = (_QWORD *)(a1 + 40264);
    if ( !*(_DWORD *)(a1 + 40696) )
    {
      scnprintf(a3, 4096, "TSF sync is not initialized\n");
      goto LABEL_40;
    }
    v7 = *(_QWORD *)(a1 + 54136);
    if ( !hdd_cm_is_vdev_associated((_DWORD *)v7) && (*(_DWORD *)(a1 + 1352) | 2) == 2 )
    {
      scnprintf(a3, 4096, "NOT connected\n");
LABEL_40:
      v5 = v8;
      _osif_vdev_sync_op_stop((__int64)v31[0], (__int64)"hdd_wlan_tsf_show");
      goto LABEL_41;
    }
    if ( !*(_QWORD *)(a1 + 1336) )
    {
      scnprintf(a3, 4096, "Invalid HDD context\n");
      goto LABEL_40;
    }
    __isb(0xFu);
    StatusReg = _ReadStatusReg(CNTVCT_EL0);
    v10 = *(_QWORD *)(a1 + 54120);
    v11 = *(_QWORD *)(a1 + 1336);
    if ( 10 * StatusReg < StatusReg )
      v12 = 10 * (StatusReg / 0xC0);
    else
      v12 = 10 * StatusReg / 0xC0;
    if ( v11 )
    {
      if ( *(int *)(v11 + 3236) < 1 )
      {
        LODWORD(v11) = 0;
      }
      else
      {
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (v13 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v13 + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(v13 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(a1 + 40472);
        }
        else
        {
          raw_spin_lock_bh(a1 + 40472);
          *(_QWORD *)(a1 + 40480) |= 1uLL;
        }
        LODWORD(v11) = 1;
      }
    }
    v14 = *v6 / 0x3E8uLL;
    v15 = *(_QWORD *)(a1 + 40680);
    v16 = v14 - v12;
    if ( v14 >= v12 )
    {
      v22 = v15 >= v16;
      v23 = v15 - v16;
      v20 = !v22;
      if ( v22 )
        v21 = v23;
      else
        v21 = 0;
    }
    else
    {
      v17 = v12 - v14;
      v18 = __CFADD__(v17, v15);
      v19 = v17 + v15;
      v20 = v18;
      if ( v18 )
        v21 = 0;
      else
        v21 = v19;
    }
    if ( (_DWORD)v11 )
    {
      v24 = *(_QWORD *)(a1 + 40480);
      if ( (v24 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 40480) = v24 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 40472);
        if ( v20 )
          goto LABEL_39;
        goto LABEL_43;
      }
      raw_spin_unlock(a1 + 40472);
    }
    if ( v20 )
    {
LABEL_39:
      scnprintf(a3, 4096, "Invalid timestamp\n");
      goto LABEL_40;
    }
LABEL_43:
    if ( (*(_DWORD *)(a1 + 1352) | 2) == 2 )
    {
      v26 = *(_QWORD *)(a1 + 40680);
      if ( v7 != -300 )
      {
        v27 = *(unsigned __int8 *)(v7 + 300);
        v28 = *(unsigned __int8 *)(v7 + 301);
        v29 = *(unsigned __int8 *)(v7 + 302);
        v30 = *(unsigned __int8 *)(v7 + 305);
LABEL_49:
        scnprintf(
          a3,
          4096,
          "%s%llu %llu %02x:%02x:%02x:**:**:%02x %llu %llu %llu\n",
          a3,
          v26,
          *v6 / 0x3E8uLL,
          v27,
          v28,
          v29,
          v30,
          v12,
          (1000 * v12 - v10) / 0x3E8,
          v21);
        goto LABEL_40;
      }
    }
    else
    {
      v26 = *(_QWORD *)(a1 + 40680);
      if ( a1 != -2929 )
      {
        v27 = *(unsigned __int8 *)(a1 + 2929);
        v28 = *(unsigned __int8 *)(a1 + 2930);
        v29 = *(unsigned __int8 *)(a1 + 2931);
        v30 = *(unsigned __int8 *)(a1 + 2934);
        goto LABEL_49;
      }
    }
    v29 = 0;
    v27 = 0;
    v28 = 0;
    v30 = 0;
    goto LABEL_49;
  }
LABEL_41:
  _ReadStatusReg(SP_EL0);
  return v5;
}
