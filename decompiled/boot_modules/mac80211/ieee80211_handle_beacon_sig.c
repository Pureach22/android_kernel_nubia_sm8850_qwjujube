__int64 __fastcall ieee80211_handle_beacon_sig(__int64 result, __int64 a2, _DWORD *a3, __int64 a4, __int64 a5)
{
  unsigned int v5; // w8
  __int64 v6; // x19
  __int64 v7; // x10
  unsigned __int64 v8; // x11
  int v9; // w10
  int v10; // w9
  unsigned __int64 v11; // x8
  int v12; // w11
  int v13; // w8
  _DWORD *v14; // x20
  __int64 v15; // x21
  int v16; // w9
  int v17; // w10
  int v18; // w11
  int v19; // w8
  _DWORD *v20; // x20
  __int64 v21; // x21
  int v22; // w9
  int v23; // w10
  int v24; // w11
  int v25; // w8

  _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(result + 564) & 1) != 0 )
  {
    v5 = *(_DWORD *)(result + 860) + 1;
    *(_DWORD *)(result + 860) = v5;
  }
  else
  {
    v5 = 1;
    *(_QWORD *)(result + 848) = 0;
    *(_BYTE *)(result + 564) = 1;
    *(_DWORD *)(result + 868) = 0;
    *(_QWORD *)(result + 856) = 0x100000000LL;
  }
  v6 = *(_QWORD *)result;
  v7 = *(_QWORD *)(result + 848);
  if ( v7 )
    v8 = (unsigned __int64)(3 * v7 - 16LL * *(char *)(a5 + 38)) >> 2;
  else
    v8 = -16LL * *(char *)(a5 + 38);
  *(_QWORD *)(result + 848) = v8;
  v9 = *(_DWORD *)(a2 + 264);
  v10 = *(_DWORD *)(a2 + 268);
  if ( v9 != v10 && v5 >= 4 )
  {
    v11 = v8 >> 4;
    v12 = *(_DWORD *)(result + 856);
    v13 = -(int)v11;
    if ( v10 < v13 && (v12 <= v9 || !v12) )
    {
      v14 = a3;
      v15 = result;
      *(_DWORD *)(result + 856) = v13;
      goto LABEL_17;
    }
    if ( v9 > v13 && (v12 >= v10 || !v12) )
    {
      v14 = a3;
      v15 = result;
      *(_DWORD *)(result + 856) = v13;
LABEL_17:
      drv_event_callback(a4);
      result = v15;
      a3 = v14;
    }
  }
  v16 = a3[29];
  if ( v16 && *(_DWORD *)(result + 860) >= 4u && (*(_BYTE *)(v6 + 5872) & 2) == 0 )
  {
    v17 = *(_DWORD *)(result + 868);
    v18 = a3[30];
    v19 = -(int)(*(_QWORD *)(result + 848) >> 4);
    if ( v16 > v19 && (!v17 || v17 - v18 > v19) )
    {
      v20 = a3;
      *(_DWORD *)(result + 868) = v19;
      v21 = result;
      goto LABEL_29;
    }
    if ( v16 < v19 && (!v17 || v18 + v17 < v19) )
    {
      v20 = a3;
      *(_DWORD *)(result + 868) = v19;
      v21 = result;
LABEL_29:
      cfg80211_cqm_rssi_notify(*(_QWORD *)(v6 + 1608));
      result = v21;
      a3 = v20;
    }
  }
  v22 = a3[31];
  if ( v22 && *(_DWORD *)(result + 860) >= 4u )
  {
    v23 = *(_DWORD *)(result + 868);
    v24 = a3[32];
    v25 = -(int)(*(_QWORD *)(result + 848) >> 4);
    if ( v22 > v25 && (!v23 || v23 >= v22) )
    {
      *(_DWORD *)(result + 868) = v25;
      goto LABEL_40;
    }
    if ( v24 < v25 && (!v23 || v23 <= v24) )
    {
      *(_DWORD *)(result + 868) = v25;
LABEL_40:
      result = cfg80211_cqm_rssi_notify(*(_QWORD *)(v6 + 1608));
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
