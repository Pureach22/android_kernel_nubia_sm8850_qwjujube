__int64 __fastcall dp_ctrl_mst_stream_setup(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x23
  void (*v6)(void); // x8
  void (*v7)(void); // x8
  int v8; // w0
  __int64 v9; // x11
  __int64 v10; // x9
  __int64 v11; // x8
  char v12; // w10
  char v13; // w10
  __int64 v14; // x9
  __int64 v15; // x10
  int v16; // w21
  int v17; // w22
  __int64 (*v18)(void); // x8
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  _QWORD v23[4]; // [xsp+8h] [xbp-68h] BYREF
  __int64 v24; // [xsp+28h] [xbp-48h]
  __int64 v25; // [xsp+30h] [xbp-40h] BYREF
  __int64 v26; // [xsp+38h] [xbp-38h]
  __int64 v27; // [xsp+40h] [xbp-30h]
  __int64 v28; // [xsp+48h] [xbp-28h]
  __int64 v29; // [xsp+50h] [xbp-20h]
  __int64 v30; // [xsp+58h] [xbp-18h]
  __int64 v31; // [xsp+60h] [xbp-10h]
  __int64 v32; // [xsp+68h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(result + 258) == 1 )
  {
    v2 = result;
    v30 = 0;
    v31 = 0;
    v28 = 0;
    v29 = 0;
    v26 = 0;
    v27 = 0;
    v24 = 0;
    v25 = 0;
    memset(v23, 0, sizeof(v23));
    ipc_log_context = get_ipc_log_context(result);
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(ipc_log_context, "[d][%-4d]mst stream channel allocation\n", *(_DWORD *)(StatusReg + 1800));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]mst stream channel allocation\n", *(_DWORD *)(StatusReg + 1800));
    v6 = *(void (**)(void))(*(_QWORD *)(v2 + 176) + 216LL);
    if ( *((_DWORD *)v6 - 1) != -739885351 )
      __break(0x8228u);
    v6();
    v7 = *(void (**)(void))(*(_QWORD *)(v2 + 176) + 216LL);
    if ( *((_DWORD *)v7 - 1) != -739885351 )
      __break(0x8228u);
    v7();
    v8 = drm_dp_bw_code_to_link_rate(*(unsigned int *)(*(_QWORD *)(v2 + 152) + 132LL));
    v9 = *(unsigned int *)(a2 + 152);
    v10 = *(_QWORD *)(v2 + 152);
    BYTE1(v27) = *(_DWORD *)(a2 + 156);
    v11 = *(_QWORD *)(a2 + 1000);
    LODWORD(v10) = *(_DWORD *)(v10 + 128);
    v25 = v8;
    v26 = v9;
    v12 = *(_DWORD *)(a2 + 184);
    LOBYTE(v27) = v10;
    BYTE2(v27) = v12;
    v13 = *(_BYTE *)(a2 + 168);
    BYTE3(v27) = v11 != 0;
    v14 = *(_QWORD *)(a2 + 856);
    BYTE4(v27) = v13;
    v15 = *(unsigned int *)(a2 + 864);
    v28 = v11;
    v29 = v14;
    v30 = v15;
    dp_tu_mst_rg_calc(&v25, (__int64)v23);
    v16 = v24;
    v17 = HIDWORD(v24);
    v18 = *(__int64 (**)(void))(*(_QWORD *)(v2 + 176) + 224LL);
    if ( *((_DWORD *)v18 - 1) != -739885351 )
      __break(0x8228u);
    v19 = v18();
    v20 = get_ipc_log_context(v19);
    v21 = ipc_log_string(
            v20,
            "[d][%-4d]mst stream:%d, start_slot:%d, tot_slots:%d\n",
            *(_DWORD *)(StatusReg + 1800),
            *(_DWORD *)(a2 + 912),
            *(_DWORD *)(a2 + 920),
            *(_DWORD *)(a2 + 924));
    if ( (_drm_debug & 4) != 0 )
      v21 = _drm_dev_dbg(
              0,
              0,
              0,
              "[msm-dp-debug][%-4d]mst stream:%d, start_slot:%d, tot_slots:%d\n",
              *(_DWORD *)(StatusReg + 1800),
              *(_DWORD *)(a2 + 912),
              *(_DWORD *)(a2 + 920),
              *(_DWORD *)(a2 + 924));
    v22 = get_ipc_log_context(v21);
    result = ipc_log_string(
               v22,
               "[d][%-4d]mst lane_cnt:%d, bw:%d, x_int:%d, y_frac:%d\n",
               *(_DWORD *)(StatusReg + 1800),
               *(_DWORD *)(*(_QWORD *)(v2 + 152) + 128LL),
               *(_DWORD *)(*(_QWORD *)(v2 + 152) + 132LL),
               v16,
               v17);
    if ( (_drm_debug & 4) != 0 )
      result = _drm_dev_dbg(
                 0,
                 0,
                 0,
                 "[msm-dp-debug][%-4d]mst lane_cnt:%d, bw:%d, x_int:%d, y_frac:%d\n",
                 *(_DWORD *)(StatusReg + 1800),
                 *(_DWORD *)(*(_QWORD *)(v2 + 152) + 128LL),
                 *(_DWORD *)(*(_QWORD *)(v2 + 152) + 132LL),
                 v16,
                 v17);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
