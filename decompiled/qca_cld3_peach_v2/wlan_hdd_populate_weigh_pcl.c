__int64 __fastcall wlan_hdd_populate_weigh_pcl(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  unsigned int v4; // w19
  int connection_count; // w24
  unsigned __int64 v10; // x25
  int *v11; // x26
  int v12; // w8
  unsigned int v13; // w8
  int v14; // w23
  unsigned __int64 v15; // x24
  __int64 v16; // x25
  __int64 v17; // x26
  int v18; // w9
  __int64 v19; // x8
  __int64 v20; // x9
  _DWORD *v21; // x28
  int v22; // w8
  bool is_beaconing_mode; // w0

  v4 = *(_DWORD *)(a2 + 408);
  connection_count = policy_mgr_get_connection_count(a1);
  if ( *(_DWORD *)(a2 + 408) )
  {
    v10 = 0;
    v11 = (int *)(a3 + 8);
    while ( v10 != 102 )
    {
      *(v11 - 2) = *(_DWORD *)(a2 + 4 * v10);
      *(v11 - 1) = *(unsigned __int8 *)(a2 + v10++ + 926);
      if ( policy_mgr_is_beaconing_mode(a4) )
        v12 = 1;
      else
        v12 = 2;
      *v11 = v12;
      v11 += 3;
      if ( v10 >= *(unsigned int *)(a2 + 408) )
        goto LABEL_8;
    }
    goto LABEL_36;
  }
LABEL_8:
  if ( connection_count
    && (policy_mgr_is_hw_dbs_capable(a1) & 1) == 0
    && (policy_mgr_is_interband_mcc_supported(a1) & 1) == 0 )
  {
    return v4;
  }
  if ( !v4 )
  {
LABEL_16:
    v14 = 1;
    if ( *(_DWORD *)(a2 + 820) )
    {
LABEL_17:
      v15 = 0;
      v16 = a2 + 412;
      v17 = a2 + 824;
      while ( 1 )
      {
        v19 = *(unsigned int *)(a2 + 408);
        if ( (_DWORD)v19 )
          break;
        LODWORD(v20) = 0;
LABEL_29:
        if ( (_DWORD)v20 == (_DWORD)v19 )
        {
LABEL_30:
          if ( v15 > 0x65 )
            goto LABEL_36;
          v21 = (_DWORD *)(a3 + 12LL * v4);
          *v21 = *(_DWORD *)(v16 + 4 * v15);
          v22 = *(unsigned __int8 *)(v17 + v15);
          if ( *(_BYTE *)(v17 + v15) )
          {
            is_beaconing_mode = policy_mgr_is_beaconing_mode(a4);
            v22 = v14;
            if ( is_beaconing_mode )
              v18 = 1;
            else
              v18 = 2;
          }
          else
          {
            v18 = 8;
          }
          ++v4;
          v21[1] = v22;
          v21[2] = v18;
        }
        if ( ++v15 >= *(unsigned int *)(a2 + 820) )
          return v4;
      }
      if ( v15 <= 0x65 )
      {
        v20 = 0;
        while ( v20 != 102 )
        {
          if ( *(_DWORD *)(v16 + 4 * v15) == *(_DWORD *)(a2 + 4 * v20) )
            goto LABEL_29;
          if ( v19 == ++v20 )
            goto LABEL_30;
        }
      }
      goto LABEL_36;
    }
    return v4;
  }
  if ( v4 <= 0x66 )
  {
    v13 = *(unsigned __int8 *)(a2 + v4 - 1 + 926);
    if ( v13 >= 0x15 )
    {
      v14 = v13 - 20;
      if ( !*(_DWORD *)(a2 + 820) )
        return v4;
      goto LABEL_17;
    }
    goto LABEL_16;
  }
LABEL_36:
  __break(0x5512u);
  return hdd_pcl_info_dump();
}
