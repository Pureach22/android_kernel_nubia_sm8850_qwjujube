__int64 __fastcall policy_mgr_update_nss_req(__int64 a1, unsigned int a2)
{
  unsigned int *v2; // x18
  __int64 context; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _DWORD *v14; // x22
  __int64 v15; // x21
  __int64 macid_by_vdev_id; // x0
  __int64 v17; // x1
  const char *v18; // x2
  __int64 result; // x0
  int v20; // w8
  _DWORD *v21; // x0
  __int64 v22; // x2
  __int64 v23; // x3
  _DWORD *v24; // x8
  _QWORD v25[2]; // [xsp+0h] [xbp-20h] BYREF
  int v26; // [xsp+10h] [xbp-10h]
  __int64 v27; // [xsp+18h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v18 = "%s: Invalid Context";
    goto LABEL_8;
  }
  if ( !a1 || (v14 = *(_DWORD **)(a1 + 2800)) == nullptr )
  {
    v18 = "%s: tgt_hdl not found";
    goto LABEL_8;
  }
  v15 = context;
  macid_by_vdev_id = policy_mgr_mode_get_macid_by_vdev_id(a1, (unsigned __int8)a2);
  if ( (_DWORD)macid_by_vdev_id == 255 )
  {
    v18 = "%s: mac_id not found";
LABEL_8:
    qdf_trace_msg(0x4Fu, 2u, v18, v6, v7, v8, v9, v10, v11, v12, v13, "policy_mgr_update_nss_req");
LABEL_9:
    result = 16;
LABEL_10:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v20 = *(_DWORD *)(v15 + 1184);
  if ( !v20 )
    goto LABEL_18;
  if ( v14[322] == (_DWORD)macid_by_vdev_id )
  {
    v21 = v14 + 268;
LABEL_14:
    v26 = 0;
    v25[0] = 0;
    v25[1] = 0;
    policy_mgr_get_hw_mode_params(v21, v25);
    v22 = LODWORD(v25[0]);
    v23 = HIDWORD(v25[0]);
    v24 = *(_DWORD **)(v15 + 384);
    if ( *(v24 - 1) != -112247927 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64))v24)(a1, a2, v22, v23);
    goto LABEL_10;
  }
  if ( v20 == 1 )
    goto LABEL_18;
  if ( v14[386] == (_DWORD)macid_by_vdev_id )
  {
    v21 = v14 + 332;
    goto LABEL_14;
  }
  if ( v20 == 2 )
    goto LABEL_18;
  if ( v14[450] == (_DWORD)macid_by_vdev_id )
  {
    v21 = v14 + 396;
    goto LABEL_14;
  }
  if ( v20 == 3 )
    goto LABEL_18;
  if ( v14[514] == (_DWORD)macid_by_vdev_id )
  {
    v21 = v14 + 460;
    goto LABEL_14;
  }
  if ( v20 == 4 )
    goto LABEL_18;
  if ( v14[578] == (_DWORD)macid_by_vdev_id )
  {
    v21 = v14 + 524;
    goto LABEL_14;
  }
  if ( v20 == 5 )
    goto LABEL_18;
  if ( v14[642] == (_DWORD)macid_by_vdev_id )
  {
    v21 = v14 + 588;
    goto LABEL_14;
  }
  if ( v20 == 6 )
    goto LABEL_18;
  if ( v14[706] == (_DWORD)macid_by_vdev_id )
  {
    v21 = v14 + 652;
    goto LABEL_14;
  }
  if ( v20 == 7 )
    goto LABEL_18;
  if ( v14[770] == (_DWORD)macid_by_vdev_id )
  {
    v21 = v14 + 716;
    goto LABEL_14;
  }
  if ( v20 == 8 )
    goto LABEL_18;
  if ( v14[834] == (_DWORD)macid_by_vdev_id )
  {
    v21 = v14 + 780;
    goto LABEL_14;
  }
  if ( v20 == 9 )
  {
LABEL_18:
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: mac_id : %d not found",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "policy_mgr_update_nss_req",
      (unsigned int)macid_by_vdev_id);
    goto LABEL_9;
  }
  __break(0x5512u);
  __ldaxr(v2);
  return policy_mgr_mode_get_macid_by_vdev_id(macid_by_vdev_id, v17);
}
