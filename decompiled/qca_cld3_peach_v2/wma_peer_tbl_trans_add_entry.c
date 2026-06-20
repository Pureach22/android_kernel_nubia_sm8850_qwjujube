__int64 __fastcall wma_peer_tbl_trans_add_entry(__int64 result, char a2, __int64 a3)
{
  __int64 v3; // x23
  __int64 v4; // x8
  __int64 v5; // x19
  __int64 v7; // x24
  __int64 v9; // x21
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  char v18; // w8
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  char v27; // w9
  __int64 v28; // x8
  __int64 v29; // x8
  int v30; // w9
  unsigned int v31; // w9

  v3 = *(_QWORD *)(result + 96);
  if ( v3 )
  {
    v4 = *(_QWORD *)(v3 + 216);
    if ( v4 )
    {
      v5 = *(_QWORD *)(v4 + 80);
      if ( v5 )
      {
        v7 = result;
        result = _qdf_mem_malloc(0x38u, "wma_peer_tbl_trans_add_entry", 1752);
        if ( result )
        {
          __isb(0xFu);
          *(_QWORD *)(result + 16) = _ReadStatusReg(CNTVCT_EL0);
          v9 = result;
          *(_BYTE *)(result + 24) = *(_BYTE *)(v3 + 168);
          *(_DWORD *)(result + 28) = *(_DWORD *)(v3 + 16);
          qdf_ether_addr_copy((_WORD *)(result + 33), (_WORD *)(v7 + 48));
          qdf_ether_addr_copy((_WORD *)(v9 + 39), (_WORD *)(v7 + 792));
          v18 = *(_BYTE *)(v9 + 32) & 0xFE | wlan_vdev_mlme_is_mlo_vdev(v3, v10, v11, v12, v13, v14, v15, v16, v17) & 1;
          *(_BYTE *)(v9 + 32) = v18;
          *(_BYTE *)(v9 + 32) = *(_BYTE *)(v3 + 60) & 2 | v18 & 0xFD;
          if ( wlan_cm_is_vdev_roam_sync_inprogress(v3, v19, v20, v21, v22, v23, v24, v25, v26) )
          {
            *(_QWORD *)(v9 + 48) |= 0x10uLL;
            if ( (wlan_cm_check_mlo_roam_auth_status(v3) & 1) != 0 )
              v27 = 16;
            else
              v27 = 0;
            *(_BYTE *)(v9 + 32) = *(_BYTE *)(v9 + 32) & 0xCF | v27;
            *(_BYTE *)(v9 + 32) = *(_BYTE *)(v9 + 32) & 0x3F | ((unsigned __int8)mlo_mgr_num_roam_links(v3) << 6);
          }
          else
          {
            v28 = *(_QWORD *)(v9 + 48);
            if ( (*(_BYTE *)(v3 + 67) & 2) == 0 )
            {
              if ( (a2 & 1) != 0 )
              {
                v29 = v28 | 4;
LABEL_15:
                v30 = *(unsigned __int8 *)(v9 + 32);
                *(_QWORD *)(v9 + 48) = v29 | 1;
                v31 = v30 & 0xFFFFFFFB | (4 * ((*(unsigned __int8 *)(a3 + 8) >> 1) & 1));
                *(_BYTE *)(v9 + 32) = v31;
                *(_BYTE *)(v9 + 32) = (8 * (*(_BYTE *)(a3 + 8) & 1)) | v31 & 0xF7;
                goto LABEL_18;
              }
              v29 = v28 | 8;
LABEL_17:
              *(_QWORD *)(v9 + 48) = v29 | 2;
LABEL_18:
              result = wlan_mlme_psoc_peer_tbl_trans_add_entry(v5, (_QWORD *)v9);
              if ( (_DWORD)result )
                return _qdf_mem_free(v9);
              return result;
            }
            *(_QWORD *)(v9 + 48) = v28 | 0x20;
          }
          v29 = *(_QWORD *)(v9 + 48);
          if ( (a2 & 1) != 0 )
            goto LABEL_15;
          goto LABEL_17;
        }
      }
    }
  }
  return result;
}
