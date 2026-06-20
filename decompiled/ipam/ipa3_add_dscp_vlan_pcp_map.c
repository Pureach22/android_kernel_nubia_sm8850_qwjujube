__int64 __fastcall ipa3_add_dscp_vlan_pcp_map(__int64 *a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 v8; // x10
  __int64 v9; // x8
  __int64 v10; // x10
  __int64 v11; // x11
  __int64 v12; // x9
  __int64 v13; // x11
  __int64 v14; // x10
  unsigned int v15; // w19
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // [xsp+20h] [xbp-20h]
  __int64 v30; // [xsp+28h] [xbp-18h] BYREF
  __int64 v31; // [xsp+30h] [xbp-10h]
  __int64 v32; // [xsp+38h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  v31 = 0;
  if ( a1 )
  {
    v2 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v3 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v3 )
      {
        ipc_log_string(
          v3,
          "ipa %s:%d map add attempt. num_vlan: %u\n",
          "ipa3_add_dscp_vlan_pcp_map",
          2020,
          *((unsigned __int8 *)a1 + 80));
        v2 = ipa3_ctx;
      }
      v4 = *(_QWORD *)(v2 + 34160);
      if ( v4 )
      {
        ipc_log_string(
          v4,
          "ipa %s:%d map add attempt. num_vlan: %u\n",
          "ipa3_add_dscp_vlan_pcp_map",
          2020,
          *((unsigned __int8 *)a1 + 80));
        v2 = ipa3_ctx;
      }
    }
    v5 = *(_QWORD *)(v2 + 34224);
    LODWORD(v31) = 82;
    v6 = dma_alloc_attrs(v5, 82, &v30, 3264, 0);
    v29 = v6;
    if ( v6 )
    {
      v7 = a1[2];
      v8 = *a1;
      *(_QWORD *)(v6 + 8) = a1[1];
      *(_QWORD *)(v6 + 16) = v7;
      *(_QWORD *)v6 = v8;
      v9 = a1[6];
      v10 = a1[3];
      v11 = a1[4];
      *(_QWORD *)(v6 + 40) = a1[5];
      *(_QWORD *)(v6 + 48) = v9;
      *(_QWORD *)(v6 + 24) = v10;
      *(_QWORD *)(v6 + 32) = v11;
      v13 = a1[8];
      v12 = a1[9];
      v14 = a1[7];
      *(_WORD *)(v6 + 80) = *((_WORD *)a1 + 40);
      *(_QWORD *)(v6 + 64) = v13;
      *(_QWORD *)(v6 + 72) = v12;
      *(_QWORD *)(v6 + 56) = v14;
      ipa3_inc_client_enable_clks();
      v15 = ipa3_uc_send_cmd_64b_param(v30, 0, 21, 0, 1, 2500);
      if ( v15 )
      {
        printk(&unk_3D039E, "ipa3_add_dscp_vlan_pcp_map");
        v26 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v27 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v27 )
          {
            ipc_log_string(v27, "ipa %s:%d ipa3_uc_send_cmd failed %d\n", "ipa3_add_dscp_vlan_pcp_map", 2045, v15);
            v26 = ipa3_ctx;
          }
          v28 = *(_QWORD *)(v26 + 34160);
          if ( v28 )
            ipc_log_string(v28, "ipa %s:%d ipa3_uc_send_cmd failed %d\n", "ipa3_add_dscp_vlan_pcp_map", 2045, v15);
        }
      }
      else
      {
        v16 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v17 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v17 )
          {
            ipc_log_string(v17, "ipa %s:%d map add success\n", "ipa3_add_dscp_vlan_pcp_map", 2049);
            v16 = ipa3_ctx;
          }
          v18 = *(_QWORD *)(v16 + 34160);
          if ( v18 )
            ipc_log_string(v18, "ipa %s:%d map add success\n", "ipa3_add_dscp_vlan_pcp_map", 2049);
        }
      }
      dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34224), (unsigned int)v31, v29, v30, 0);
      ipa3_dec_client_disable_clks();
    }
    else
    {
      printk(&unk_3B2CAB, "ipa3_add_dscp_vlan_pcp_map");
      v23 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_32;
      v24 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v24 )
      {
        ipc_log_string(v24, "ipa %s:%d Fail to alloc DMA buff of size %d\n", "ipa3_add_dscp_vlan_pcp_map", 2029, v31);
        v23 = ipa3_ctx;
      }
      v25 = *(_QWORD *)(v23 + 34160);
      if ( v25 )
      {
        ipc_log_string(v25, "ipa %s:%d Fail to alloc DMA buff of size %d\n", "ipa3_add_dscp_vlan_pcp_map", 2029, v31);
        v15 = -12;
      }
      else
      {
LABEL_32:
        v15 = -12;
      }
    }
  }
  else
  {
    printk(&unk_3B5885, "ipa3_add_dscp_vlan_pcp_map");
    v20 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_31;
    v21 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v21 )
    {
      ipc_log_string(v21, "ipa %s:%d null argument (ie. map) passed\n", "ipa3_add_dscp_vlan_pcp_map", 2016);
      v20 = ipa3_ctx;
    }
    v22 = *(_QWORD *)(v20 + 34160);
    if ( v22 )
    {
      ipc_log_string(v22, "ipa %s:%d null argument (ie. map) passed\n", "ipa3_add_dscp_vlan_pcp_map", 2016);
      v15 = -22;
    }
    else
    {
LABEL_31:
      v15 = -22;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v15;
}
