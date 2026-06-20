__int64 __fastcall dp_soc_handle_pdev_mode_change(_QWORD *a1, char a2, unsigned int a3)
{
  unsigned __int8 *v4; // x22
  int dp_soc_nss_cfg; // w0
  int v7; // w20
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  char target_pdev_id; // w0
  __int64 v17; // x4
  __int64 v18; // x5
  int v19; // w21
  _DWORD *v20; // x8
  __int64 v21; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v23; // x23
  unsigned int v24; // w8
  __int64 result; // x0
  __int64 v26; // x8
  unsigned __int8 v27[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v28[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v29[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v30; // [xsp+18h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29[0] = a2;
  v27[0] = 0;
  if ( a2 )
  {
    wlan_cfg_get_dp_soc_nss_cfg(a1[5]);
    result = 16;
    goto LABEL_28;
  }
  v4 = (unsigned __int8 *)a1[9];
  dp_soc_nss_cfg = wlan_cfg_get_dp_soc_nss_cfg(a1[5]);
  if ( !v4 )
  {
LABEL_31:
    result = 16;
    goto LABEL_28;
  }
  v4[1] = a3;
  v7 = dp_soc_nss_cfg;
  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(a1[5]) )
    target_pdev_id = wlan_cfg_get_target_pdev_id(a1[5], *(unsigned __int8 *)(a1[9] + 1LL));
  else
    target_pdev_id = 1;
  v17 = *v4;
  v18 = v4[1];
  v4[2] = target_pdev_id;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: mode change %d %d",
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    "dp_soc_handle_pdev_mode_change",
    v17,
    v18);
  ((void (__fastcall *)(_QWORD, _QWORD, _QWORD))wlan_cfg_set_pdev_idx)(a1[5], *v4, a3);
  v19 = *v4;
  if ( !(unsigned int)wlan_cfg_per_pdev_lmac_ring(a1[5]) )
  {
    v28[0] = v19 + 1;
    if ( !v7 )
      goto LABEL_15;
    goto LABEL_11;
  }
  if ( v19 )
  {
    __break(0x5512u);
    goto LABEL_31;
  }
  v28[0] = *(_BYTE *)(a1[9] + 2LL);
  if ( !v7 )
    goto LABEL_15;
LABEL_11:
  v20 = *(_DWORD **)(a1[1] + 184LL);
  v27[0] = v4[1];
  if ( v20 )
  {
    v21 = a1[2];
    if ( *(v20 - 1) != 583947813 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _BYTE *, unsigned __int8 *, _BYTE *))v20)(v21, v29, v27, v28);
  }
LABEL_15:
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v4 + 312);
    v23 = *((_QWORD *)v4 + 37);
    if ( v23 )
      goto LABEL_19;
  }
  else
  {
    raw_spin_lock_bh(v4 + 312);
    *((_QWORD *)v4 + 40) |= 1uLL;
    v23 = *((_QWORD *)v4 + 37);
    if ( v23 )
    {
LABEL_19:
      v24 = v28[0];
      do
      {
        if ( v24 >= 4 )
        {
          printk(
            &unk_94DB9D,
            "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_main.c",
            12612,
            "!((hw_pdev_id) & ~((HTT_TX_TCL_METADATA_PDEV_ID_M) >> (HTT_TX_TCL_METADATA_PDEV_ID_S)))");
          v24 = v28[0];
        }
        *(_WORD *)(v23 + 60) |= (_WORD)v24 << 10;
        *(_BYTE *)(v23 + 62) = v4[1];
        v23 = *(_QWORD *)(v23 + 112);
      }
      while ( v23 );
    }
  }
  v26 = *((_QWORD *)v4 + 40);
  if ( (v26 & 1) != 0 )
  {
    *((_QWORD *)v4 + 40) = v26 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v4 + 312);
  }
  else
  {
    raw_spin_unlock(v4 + 312);
  }
  result = 0;
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
