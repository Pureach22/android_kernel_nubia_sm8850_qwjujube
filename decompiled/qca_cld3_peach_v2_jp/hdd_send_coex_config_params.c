__int64 __fastcall hdd_send_coex_config_params(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x20
  _DWORD *v12; // x19
  const char *v13; // x2
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w3
  int v24; // w8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w6
  __int64 v34; // x5
  int v35; // w9
  int v36; // w9
  int v37; // w9
  int v38; // w8
  __int64 vdev_by_user; // x0
  __int64 v40; // x20
  unsigned int v41; // [xsp+Ch] [xbp-24h] BYREF
  _QWORD v42[4]; // [xsp+10h] [xbp-20h] BYREF

  v42[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a1;
  memset(v42, 0, 22);
  v41 = 0;
  if ( !a2 )
  {
    v12 = nullptr;
    v13 = "%s: adapter is invalid";
    goto LABEL_7;
  }
  if ( !v10 )
  {
    v12 = nullptr;
    v13 = "%s: HDD psoc is invalid";
    goto LABEL_7;
  }
  if ( !(unsigned int)ucfg_fwol_get_coex_config_params(v10, v42) )
  {
    v12 = (_DWORD *)_qdf_mem_malloc(0x388u, "hdd_send_coex_config_params", 8925);
    if ( !v12 )
      goto LABEL_8;
    *v12 = *(unsigned __int8 *)(*(_QWORD *)(a2 + 52824) + 8LL);
    v23 = WORD1(v42[0]);
    v12[2] = 12;
    v12[3] = v23;
    qdf_trace_msg(0x36u, 8u, "TXP[W][send_coex_cfg]: %d", v15, v16, v17, v18, v19, v20, v21, v22);
    v12[9] = 19;
    v24 = SWORD2(v42[0]);
    v12[16] = 24;
    v12[10] = v24;
    if ( (unsigned int)ucfg_coex_psoc_get_btc_chain_mode(v10, &v41) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to get btc chain mode",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "hdd_send_coex_config_params");
      v33 = 255;
      v41 = 255;
    }
    else
    {
      v33 = v41;
      v34 = v41;
      if ( v41 < 3 )
      {
LABEL_15:
        v12[17] = v33;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Configured BTC mode is %d, BTC chain mode is 0x%x, set BTC mode to %d",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "hdd_send_coex_config_params",
          LOBYTE(v42[0]),
          v34);
        v12[23] = 25;
        v35 = BYTE1(v42[0]);
        v12[30] = 26;
        v12[24] = v35;
        v36 = SHIWORD(v42[0]);
        v12[37] = 27;
        v12[31] = v36;
        v12[38] = SLOWORD(v42[1]);
        v12[39] = SWORD1(v42[1]);
        v12[40] = SWORD2(v42[1]);
        v12[41] = SHIWORD(v42[1]);
        v12[42] = SLOWORD(v42[2]);
        v12[43] = SWORD1(v42[2]);
        v12[44] = 42;
        v37 = BYTE4(v42[2]);
        v12[51] = 48;
        v12[45] = v37;
        v38 = BYTE5(v42[2]);
        v12[1] = 8;
        v12[52] = v38;
        vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a2 + 52824), 106, "hdd_send_coex_config_params");
        if ( vdev_by_user )
        {
          v40 = vdev_by_user;
          ucfg_coex_send_multi_config(vdev_by_user, v12);
          _hdd_objmgr_put_vdev_by_user(v40, 106, "hdd_send_coex_config_params");
          _qdf_mem_free((__int64)v12);
          result = 0;
          goto LABEL_9;
        }
        v13 = "%s: vdev is null";
        goto LABEL_7;
      }
    }
    v34 = v33;
    v33 = LOBYTE(v42[0]);
    goto LABEL_15;
  }
  v12 = nullptr;
  v13 = "%s: Unable to get coex config params";
LABEL_7:
  qdf_trace_msg(0x33u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "hdd_send_coex_config_params");
LABEL_8:
  _qdf_mem_free((__int64)v12);
  result = 4294967274LL;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
