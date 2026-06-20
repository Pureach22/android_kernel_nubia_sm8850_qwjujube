__int64 __fastcall sde_connector_roi_v1_check_roi(__int64 *a1)
{
  unsigned int v2; // w4
  __int64 v3; // x26
  unsigned int v4; // w19
  unsigned int v5; // w20
  unsigned __int64 v6; // x24
  unsigned int v7; // w22
  unsigned int v8; // w23
  unsigned __int16 *v9; // x25
  int v10; // w4
  int v11; // w7
  int v12; // w5
  int v13; // w6
  int v14; // w28
  int v15; // w27
  void *v17; // x0
  unsigned int v18; // [xsp+18h] [xbp-8h]
  unsigned int v19; // [xsp+1Ch] [xbp-4h]

  if ( !a1 )
    return 4294967274LL;
  if ( (a1[369] & 1) == 0 )
    return 0;
  v2 = *((_DWORD *)a1 + 512);
  v3 = *a1;
  if ( v2 > *((_DWORD *)a1 + 739) )
  {
    printk(&unk_21DED3, "sde_connector_roi_v1_check_roi");
    return 4294967289LL;
  }
  if ( !v2 )
    return 0;
  v4 = *((_DWORD *)a1 + 740);
  v5 = *((_DWORD *)a1 + 741);
  v6 = 0;
  v7 = *((_DWORD *)a1 + 742);
  v8 = *((_DWORD *)a1 + 743);
  v9 = (unsigned __int16 *)a1 + 1026;
  v18 = *((_DWORD *)a1 + 745);
  v19 = *((_DWORD *)a1 + 744);
  while ( v6 != 5 )
  {
    if ( v3 )
      v10 = *(_DWORD *)(v3 + 64);
    else
      v10 = -1;
    v11 = v9[2];
    v12 = *v9;
    v13 = v9[1];
    v14 = v11 - v12;
    v15 = v9[3] - v13;
    sde_evtlog_log(sde_dbg_base_evtlog, "sde_connector_roi_v1_check_roi", 2226, 4, v10, v12, v13, v11, v9[3]);
    if ( v14 < 1 || v15 <= 0 )
    {
      v17 = &unk_22E9A2;
LABEL_26:
      printk(v17, "sde_connector_roi_v1_check_roi");
      return 4294967274LL;
    }
    if ( v14 < v19 || v14 % v5 )
    {
      printk(&unk_24674A, "sde_connector_roi_v1_check_roi");
      return 4294967274LL;
    }
    if ( v15 < v18 || v15 % v8 )
    {
      printk(&unk_243363, "sde_connector_roi_v1_check_roi");
      return 4294967274LL;
    }
    if ( *v9 % v4 )
    {
      v17 = &unk_24CEAF;
      goto LABEL_26;
    }
    if ( v9[1] % v7 )
    {
      v17 = &unk_21DF16;
      goto LABEL_26;
    }
    ++v6;
    v9 += 4;
    if ( v6 >= *((unsigned int *)a1 + 512) )
      return 0;
  }
  __break(0x5512u);
  return sde_conn_timeline_status();
}
