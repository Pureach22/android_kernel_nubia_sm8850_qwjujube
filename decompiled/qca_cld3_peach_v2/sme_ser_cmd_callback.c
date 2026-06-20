__int64 __fastcall sme_ser_cmd_callback(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x0
  const char *v22; // x2
  const char *v23; // x3
  unsigned int v24; // w1
  __int64 v25; // x21
  _QWORD *v26; // x20
  int v27; // w9
  int *v28; // x9
  int v29; // w10
  __int64 result; // x0
  __int64 v31; // x1
  int v32; // w4
  unsigned int *v33; // x8
  _QWORD *v34; // x20
  unsigned __int16 v35; // w10
  int v36; // [xsp+20h] [xbp-60h]
  unsigned __int16 v37; // [xsp+24h] [xbp-5Ch]
  int v38; // [xsp+28h] [xbp-58h] BYREF
  unsigned __int16 v39; // [xsp+2Ch] [xbp-54h]
  _QWORD v40[3]; // [xsp+58h] [xbp-28h] BYREF
  __int16 v41; // [xsp+70h] [xbp-10h]
  __int64 v42; // [xsp+78h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(52, (__int64)"sme_ser_cmd_callback", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
    goto LABEL_19;
  if ( !a1 )
  {
    v22 = "%s: serialization command is null";
    v23 = "sme_ser_cmd_callback";
LABEL_9:
    v24 = 2;
LABEL_18:
    qdf_trace_msg(0x34u, v24, v22, v13, v14, v15, v16, v17, v18, v19, v20, v23);
LABEL_19:
    result = 16;
    goto LABEL_49;
  }
  if ( a2 > 1 )
  {
    if ( a2 == 2 )
    {
      v33 = *(unsigned int **)(a1 + 32);
      if ( v33 )
      {
        v34 = context;
        wlan_objmgr_vdev_release_ref(*(_QWORD *)(a1 + 32), 0xBu, v33, v13, v14, v15, v16, v17, v18, v19, v20);
        context = v34;
      }
      csr_release_command_buffer(context, *(_QWORD *)(a1 + 40));
      goto LABEL_48;
    }
    if ( a2 != 3 )
    {
LABEL_17:
      v22 = "%s: unknown reason code";
      v23 = "sme_ser_cmd_callback";
      v24 = 8;
      goto LABEL_18;
    }
    v25 = *(_QWORD *)(a1 + 40);
    v26 = context;
    if ( !v25 || (v27 = *(_DWORD *)(v25 + 16), (unsigned int)(v27 - 65537) > 1) )
    {
LABEL_45:
      if ( *(_DWORD *)a1 == 16 )
      {
        v21 = v26[2703];
        goto LABEL_47;
      }
LABEL_48:
      result = 0;
      goto LABEL_49;
    }
    v39 = 0;
    v38 = 0;
    v37 = 0;
    v36 = 0;
    v41 = 0;
    memset(v40, 0, sizeof(v40));
    if ( v27 == 65538 )
    {
      if ( *(_DWORD *)(v25 + 32) <= 1u )
      {
        v35 = *(_WORD *)(v25 + 58);
        v38 = *(_DWORD *)(v25 + 54);
        v39 = v35;
        v28 = (int *)(v25 + 60);
        v29 = *(_DWORD *)(v25 + 60);
LABEL_38:
        if ( v29 | *((unsigned __int16 *)v28 + 2) )
        {
          v36 = *v28;
          v37 = *((_WORD *)v28 + 2);
        }
      }
    }
    else if ( (unsigned int)(*(_DWORD *)(v25 + 32) - 1) <= 1 )
    {
      qdf_mem_copy(&v38, (const void *)(v25 + 36), 6u);
      v28 = (int *)(v25 + 42);
      v29 = *(_DWORD *)(v25 + 42);
      goto LABEL_38;
    }
    if ( v36 | v37 )
      v13 = scnprintf(
              v40,
              26,
              " mld: %02x:%02x:%02x:**:**:%02x",
              (unsigned __int8)v36,
              BYTE1(v36),
              BYTE2(v36),
              HIBYTE(v37));
    if ( v38 | v39 )
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: vdev %d cmd %d timeout for peer %02x:%02x:%02x:**:**:%02x%s",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "sme_dump_peer_disconnect_timeout_info",
        *(unsigned int *)(v25 + 24),
        *(unsigned int *)(v25 + 16),
        (unsigned __int8)v38,
        BYTE1(v38),
        BYTE2(v38),
        HIBYTE(v39),
        v40);
    _qdf_trigger_self_recovery();
    goto LABEL_45;
  }
  if ( a2 )
  {
    if ( a2 == 1 )
    {
      if ( *(_DWORD *)a1 == 16 )
      {
        v21 = context[2703];
LABEL_47:
        policy_mgr_reset_hw_mode_change(v21, v13, v14, v15, v16, v17, v18, v19, v20);
        goto LABEL_48;
      }
      goto LABEL_48;
    }
    goto LABEL_17;
  }
  if ( !_cds_get_context(52, (__int64)"sme_ser_handle_active_cmd", v13, v14, v15, v16, v17, v18, v19, v20) )
    goto LABEL_19;
  v31 = *(_QWORD *)(a1 + 40);
  if ( !v31 )
  {
    v22 = "%s: No SME command found";
    v23 = "sme_ser_handle_active_cmd";
    goto LABEL_9;
  }
  v32 = *(_DWORD *)(v31 + 16);
  if ( v32 <= 262147 )
  {
    if ( v32 > 0x40000 )
    {
      if ( (unsigned int)(v32 - 262145) >= 2 )
      {
        csr_process_set_hw_mode();
        result = 0;
      }
      else if ( (qos_process_command() & 1) != 0 )
      {
        result = 16;
      }
      else
      {
        result = 0;
      }
      goto LABEL_49;
    }
    if ( v32 == 65537 )
    {
      result = csr_roam_process_command();
      goto LABEL_49;
    }
    if ( v32 == 65538 )
    {
      csr_roam_process_wm_status_change_command();
      result = 0;
      goto LABEL_49;
    }
LABEL_60:
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: unknown command %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "sme_ser_handle_active_cmd");
    goto LABEL_19;
  }
  if ( v32 > 262149 )
  {
    if ( v32 == 262150 )
    {
      csr_process_set_antenna_mode();
      result = 0;
      goto LABEL_49;
    }
    if ( v32 == 262151 )
    {
      csr_process_sap_ch_width_update();
      result = 0;
      goto LABEL_49;
    }
    goto LABEL_60;
  }
  if ( v32 == 262148 )
    csr_process_nss_update_req();
  else
    csr_process_set_dual_mac_config();
  result = 0;
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return result;
}
