__int64 __fastcall dfc_qmap_cmd_handler(__int64 a1)
{
  __int64 v1; // x20
  int v2; // w8
  int v3; // w9
  __int64 *v5; // x19
  unsigned int v6; // w20
  __int64 v7; // x21
  char v8; // w9
  unsigned int v9; // w10
  __int16 v10; // w8
  char v11; // w11
  char v12; // w8
  __int64 v13; // x21
  char v14; // w9
  char v15; // w10
  char v16; // w8
  unsigned int v17; // w9
  unsigned int v18; // w8
  char v19; // w10
  char v20; // w8
  char v21; // w8
  char v22; // w9
  char v23; // w8
  __int64 v24; // x22
  __int64 v25; // x8
  unsigned int v26; // w20
  unsigned int v27; // w22
  unsigned int v28; // w21
  __int64 rmnet_dev; // x0
  __int64 qos_pt; // x0
  __int64 v31; // x19
  __int64 bearer_map; // x0
  unsigned int v33; // w3

  v1 = *(_QWORD *)(a1 + 224);
  v2 = *(unsigned __int8 *)(v1 + 4);
  v3 = *(_BYTE *)(v1 + 5) & 3;
  if ( v2 == 12 )
  {
    if ( v3 != 1 )
      return 0xFFFFFFFFLL;
  }
  else if ( (*(_BYTE *)(v1 + 5) & 3) != 0 )
  {
    if ( v3 == 1 && v2 == 10 )
    {
      dfc_config_acked = 1;
      return 0xFFFFFFFFLL;
    }
    return 0xFFFFFFFFLL;
  }
  v5 = (__int64 *)qmap_dfc_data;
  if ( !qmap_dfc_data || *(_DWORD *)(qmap_dfc_data + 432) )
    return 0xFFFFFFFFLL;
  if ( (dfc_config_acked & 1) != 0 )
  {
    if ( v2 != 13 )
      goto LABEL_13;
  }
  else
  {
    v24 = a1;
    dfc_qmap_send_config(qmap_dfc_data);
    v2 = *(unsigned __int8 *)(v1 + 4);
    a1 = v24;
    dfc_config_acked = 1;
    if ( v2 != 13 )
    {
LABEL_13:
      if ( v2 == 12 )
      {
        if ( *(_DWORD *)(a1 + 112) < 0x1Cu )
          return 0xFFFFFFFFLL;
        v7 = *(_QWORD *)(a1 + 224);
        if ( (*(_WORD *)(v7 + 14) & 0x100) != 0 )
          return 0xFFFFFFFFLL;
        memset(&qmap_flow_ind, 0, 0x308u);
        v8 = *(_BYTE *)(v7 + 13);
        v9 = *(_DWORD *)(v7 + 16);
        qmap_flow_ind = 257;
        v10 = *(_WORD *)(v7 + 14);
        v11 = *(_BYTE *)(v7 + 1);
        byte_2FA32 = v8;
        dword_2FA34 = bswap32(v9);
        byte_2FA31 = v11;
        word_2FA38 = -1;
        if ( (v10 & 2) != 0 )
        {
          byte_2FA4C = 1;
          dword_2FA50 = bswap32(*(_DWORD *)(v7 + 20));
          v10 = *(_WORD *)(v7 + 14);
        }
        if ( (v10 & 1) != 0 )
        {
          word_2FCB2 = 257;
          byte_2FCB5 = *(_BYTE *)(v7 + 1);
          v12 = *(_BYTE *)(v7 + 13);
          dword_2FCB8 = 1;
          byte_2FCB6 = v12;
        }
        dfc_do_burst_flow_control(v5, &qmap_flow_ind, 1);
        return 0xFFFFFFFFLL;
      }
      else
      {
        if ( v2 == 11 )
        {
          if ( *(_DWORD *)(a1 + 112) >= 0x20u )
          {
            v13 = *(_QWORD *)(a1 + 224);
            if ( (*(_BYTE *)(v13 + 17) & 1) != 0 )
            {
              dword_2FA28 = 0;
              qword_2FA18 = 0;
              qword_2FA20 = 0;
              qword_2FA08 = 0;
              qword_2FA10 = 0;
              qword_2F9F8 = 0;
              qword_2FA00 = 0;
              qword_2F9E8 = 0;
              qword_2F9F0 = 0;
              qword_2F9D8 = 0;
              qword_2F9E0 = 0;
              qword_2F9C8 = 0;
              qword_2F9D0 = 0;
              qword_2F9B8 = 0;
              qword_2F9C0 = 0;
              v21 = *(_BYTE *)(v13 + 17);
              qmap_tx_ind = 65792;
              qword_2F9B0 = 0;
              v22 = *(_BYTE *)(v13 + 1);
              LOBYTE(qmap_tx_ind) = (v21 & 2) != 0;
              v23 = *(_BYTE *)(v13 + 18);
              BYTE5(qmap_tx_ind) = v22;
              BYTE6(qmap_tx_ind) = v23;
              ((void (__fastcall *)(__int64 *))dfc_handle_tx_link_status_ind)(v5);
            }
            else
            {
              memset(&qmap_flow_ind, 0, 0x308u);
              v14 = *(_BYTE *)(v13 + 18);
              v15 = *(_BYTE *)(v13 + 19);
              qmap_flow_ind = 257;
              v16 = *(_BYTE *)(v13 + 1);
              byte_2FA32 = v14;
              v17 = *(unsigned __int16 *)(v13 + 14);
              byte_2FA31 = v16;
              v18 = *(_DWORD *)(v13 + 20);
              byte_2FA54 = (v15 & 0x10) != 0;
              v19 = *(_BYTE *)(v13 + 17);
              dword_2FA34 = bswap32(v18);
              word_2FA38 = bswap32(v17) >> 16;
              if ( (v19 & 4) != 0 )
              {
                byte_2FA4C = 1;
                dword_2FA50 = bswap32(*(_DWORD *)(v13 + 24));
              }
              if ( (*(_BYTE *)(v13 + 19) & 1) != 0 )
              {
                word_2FCB2 = 257;
                byte_2FCB5 = *(_BYTE *)(v13 + 1);
                v20 = *(_BYTE *)(v13 + 18);
                dword_2FCB8 = 1;
                byte_2FCB6 = v20;
              }
              dfc_do_burst_flow_control(v5, &qmap_flow_ind, 0);
            }
            v6 = 1;
          }
          else
          {
            v6 = 3;
          }
          qmi_rmnet_set_dl_msg_active(*v5);
          return v6;
        }
        if ( (*(_BYTE *)(v1 + 5) & 3) != 0 )
          return 0xFFFFFFFFLL;
        else
          return 2;
      }
    }
  }
  if ( *(_DWORD *)(a1 + 112) < 0x18u )
    return 3;
  v25 = *(_QWORD *)(a1 + 224);
  v26 = *(unsigned __int8 *)(v25 + 14);
  v27 = *(unsigned __int16 *)(v25 + 18);
  v28 = *(_DWORD *)(v25 + 8);
  rmnet_dev = rmnet_get_rmnet_dev(*v5, *(_BYTE *)(v25 + 1));
  if ( rmnet_dev )
  {
    qos_pt = rmnet_get_qos_pt(rmnet_dev);
    if ( qos_pt )
    {
      v31 = qos_pt;
      raw_spin_lock_bh(qos_pt + 332);
      bearer_map = qmi_rmnet_get_bearer_map(v31, v26);
      if ( bearer_map )
      {
        v33 = bswap32(v28);
        if ( *(unsigned __int16 *)(bearer_map + 40) == bswap32(v27) >> 16 && *(_DWORD *)(bearer_map + 24) )
        {
          *(_DWORD *)(bearer_map + 56) = v33;
          *(_BYTE *)(bearer_map + 34) = 1;
        }
        else
        {
          dfc_qmap_send_end_marker_cnf(v31, bearer_map);
        }
        v6 = -1;
      }
      else
      {
        v6 = 1;
      }
      raw_spin_unlock_bh(v31 + 332);
      return v6;
    }
  }
  return 1;
}
