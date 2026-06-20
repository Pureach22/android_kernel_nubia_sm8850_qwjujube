__int64 __fastcall target_if_ftm_process_utf_event(__int64 a1)
{
  __int64 psoc_from_scn_hdl; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  __int64 v20; // x8
  __int64 v21; // x0
  unsigned int v22; // w20
  __int64 pdev_by_id; // x0
  __int64 v24; // x8
  unsigned __int64 v25; // x8
  __int64 v26; // x20
  int v27; // w8

  _ReadStatusReg(SP_EL0);
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
    goto LABEL_3;
  v10 = psoc_from_scn_hdl;
  if ( (unsigned int)wlan_objmgr_psoc_try_get_ref(psoc_from_scn_hdl, 0x20u, v2, v3, v4, v5, v6, v7, v8, v9) )
    goto LABEL_3;
  v20 = *(_QWORD *)(v10 + 2800);
  if ( !v20
    || (v21 = *(_QWORD *)(v20 + 16)) == 0
    || (unsigned int)wmi_extract_pdev_utf_event(v21)
    || (pdev_by_id = wlan_objmgr_get_pdev_by_id(v10, 0, 0x20u)) == 0
    && (pdev_by_id = wlan_objmgr_get_pdev_by_id(v10, 0, 0x20u)) == 0 )
  {
    v22 = 4;
LABEL_8:
    wlan_objmgr_psoc_release_ref(v10, 0x20u, v11, v12, v13, v14, v15, v16, v17, v18);
    result = v22;
    goto LABEL_9;
  }
  v24 = *(_QWORD *)(v10 + 2136);
  if ( v24 )
  {
    v25 = *(_QWORD *)(v24 + 1224);
    if ( v25 )
    {
      v26 = pdev_by_id;
      if ( *(_DWORD *)(v25 - 4) != 207391177 )
        __break(0x8228u);
      v27 = ((__int64 (*)(void))v25)();
      pdev_by_id = v26;
      v25 = v27 != 0;
      v22 = 4 * v25;
    }
    else
    {
      v22 = 4;
    }
    wlan_objmgr_pdev_release_ref(pdev_by_id, 0x20u, (unsigned int *)v25, v11, v12, v13, v14, v15, v16, v17, v18);
    goto LABEL_8;
  }
LABEL_3:
  result = 4;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
