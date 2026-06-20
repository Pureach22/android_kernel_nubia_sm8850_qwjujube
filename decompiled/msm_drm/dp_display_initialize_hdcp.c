__int64 __fastcall dp_display_initialize_hdcp(__int64 a1)
{
  __int64 v1; // x9
  __int64 v2; // x20
  __int64 v3; // x10
  __int64 v5; // x9
  __int64 (__fastcall *v6)(__int64, const char *); // x9
  __int64 v7; // x0
  __int64 (__fastcall *v8)(__int64, const char *); // x8
  __int64 v9; // x0
  __int64 (__fastcall *v10)(__int64, const char *); // x8
  __int64 v11; // x0
  __int64 (__fastcall *v12)(__int64, const char *); // x8
  __int64 v13; // x0
  __int64 (__fastcall *v14)(__int64, const char *); // x8
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x10
  unsigned __int64 v18; // x0
  __int64 v19; // x0
  unsigned __int64 StatusReg; // x19
  __int64 result; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  unsigned __int64 v24; // x20
  unsigned __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  _QWORD v28[2]; // [xsp+0h] [xbp-90h] BYREF
  __int64 v29; // [xsp+10h] [xbp-80h]
  __int64 v30; // [xsp+18h] [xbp-78h]
  __int64 v31; // [xsp+20h] [xbp-70h]
  __int64 v32; // [xsp+28h] [xbp-68h]
  __int64 v33; // [xsp+30h] [xbp-60h]
  __int64 v34; // [xsp+38h] [xbp-58h]
  __int64 v35; // [xsp+40h] [xbp-50h]
  __int64 v36; // [xsp+48h] [xbp-48h]
  __int64 v37; // [xsp+50h] [xbp-40h]
  __int64 v38; // [xsp+58h] [xbp-38h]
  __int64 (__fastcall *v39)(); // [xsp+60h] [xbp-30h]
  __int64 v40; // [xsp+68h] [xbp-28h]
  __int64 v41; // [xsp+70h] [xbp-20h]
  __int64 v42; // [xsp+78h] [xbp-18h]
  __int64 v43; // [xsp+80h] [xbp-10h]
  __int64 v44; // [xsp+88h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = nullptr;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28[1] = 0;
  v29 = 0;
  v28[0] = 0;
  if ( !a1 )
  {
    if ( !g_dp_display || (v22 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v22 = 0;
    ipc_log_string(v22, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_display_initialize_hdcp");
    goto LABEL_19;
  }
  v1 = *(_QWORD *)(a1 + 160);
  v2 = *(_QWORD *)(a1 + 136);
  LODWORD(v43) = 1;
  v3 = *(_QWORD *)(a1 + 1520);
  v5 = *(_QWORD *)(v1 + 24);
  BYTE4(v42) = 1;
  v37 = v3;
  v38 = a1;
  v35 = v5;
  v6 = *(__int64 (__fastcall **)(__int64, const char *))(v2 + 848);
  v39 = dp_display_notify_hdcp_status_cb;
  if ( *((_DWORD *)v6 - 1) != -816176389 )
    __break(0x8229u);
  v7 = v6(v2, "dp_ahb");
  v8 = *(__int64 (__fastcall **)(__int64, const char *))(v2 + 848);
  v29 = v7 + 16;
  if ( *((_DWORD *)v8 - 1) != -816176389 )
    __break(0x8228u);
  v9 = v8(v2, "dp_aux");
  v10 = *(__int64 (__fastcall **)(__int64, const char *))(v2 + 848);
  v30 = v9 + 16;
  if ( *((_DWORD *)v10 - 1) != -816176389 )
    __break(0x8228u);
  v11 = v10(v2, "dp_link");
  v12 = *(__int64 (__fastcall **)(__int64, const char *))(v2 + 848);
  v31 = v11 + 16;
  if ( *((_DWORD *)v12 - 1) != -816176389 )
    __break(0x8228u);
  v13 = v12(v2, "dp_p0");
  v14 = *(__int64 (__fastcall **)(__int64, const char *))(v2 + 848);
  v32 = v13 + 16;
  if ( *((_DWORD *)v14 - 1) != -816176389 )
    __break(0x8228u);
  v15 = v14(v2, "hdcp_physical");
  v16 = *(_QWORD *)(a1 + 176);
  v17 = *(_QWORD *)(a1 + 136);
  v34 = v15 + 16;
  v41 = v16 + 72;
  v28[0] = *(_QWORD *)(v17 + 8);
  v18 = sde_hdcp_1x_init((__int64)v28);
  if ( !v18 || v18 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( !g_dp_display || (v19 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v19 = 0;
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(v19, "[d][%-4d]Error initializing HDCP 1.x\n", *(_DWORD *)(StatusReg + 1800));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]Error initializing HDCP 1.x\n", *(_DWORD *)(StatusReg + 1800));
LABEL_19:
    result = 4294967274LL;
    goto LABEL_20;
  }
  *(_QWORD *)(a1 + 272) = v18;
  *(_QWORD *)(a1 + 280) = sde_hdcp_1x_get(v18);
  *(_DWORD *)(a1 + 288) = 1;
  if ( !g_dp_display || (v23 = *(_QWORD *)(g_dp_display + 56)) == 0 )
    v23 = 0;
  v24 = _ReadStatusReg(SP_EL0);
  ipc_log_string(v23, "[i][%-4d]HDCP 1.3 initialized\n", *(_DWORD *)(v24 + 1800));
  if ( (_drm_debug & 4) != 0 )
    printk(&unk_2152CF, *(unsigned int *)(v24 + 1800));
  else
    printk(&unk_2763DE, "dp_display_initialize_hdcp");
  v25 = sde_dp_hdcp2p2_init(v28);
  if ( !v25 || v25 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( !g_dp_display || (v26 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v26 = 0;
    ipc_log_string(v26, "[d][%-4d]Error initializing HDCP 2.x\n", *(_DWORD *)(v24 + 1800));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]Error initializing HDCP 2.x\n", *(_DWORD *)(v24 + 1800));
    sde_hdcp_1x_deinit(*(_QWORD **)(a1 + 272));
    goto LABEL_19;
  }
  *(_QWORD *)(a1 + 296) = v25;
  *(_QWORD *)(a1 + 304) = sde_dp_hdcp2p2_get(v25);
  *(_DWORD *)(a1 + 312) = 2;
  if ( !g_dp_display || (v27 = *(_QWORD *)(g_dp_display + 56)) == 0 )
    v27 = 0;
  ipc_log_string(v27, "[i][%-4d]HDCP 2.2 initialized\n", *(_DWORD *)(v24 + 1800));
  if ( (_drm_debug & 4) != 0 )
    printk(&unk_245565, *(unsigned int *)(v24 + 1800));
  else
    printk(&unk_218E8E, "dp_display_initialize_hdcp");
  result = 0;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
