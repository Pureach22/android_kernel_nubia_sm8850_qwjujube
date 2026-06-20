__int64 __fastcall csr_nonscan_pending_ll_next(__int64 a1, __int64 a2)
{
  int v2; // w8
  int cmd_type; // w0
  __int64 v6; // x8
  int v7; // w1
  unsigned int *vdev_by_id_from_psoc_no_state; // x0
  __int64 v9; // x8
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 pending_list_next_node_using_psoc; // x20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 result; // x0
  _DWORD v28[2]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v29; // [xsp+10h] [xbp-30h]
  __int64 v30; // [xsp+18h] [xbp-28h]
  __int64 v31; // [xsp+20h] [xbp-20h]
  unsigned int *v32; // [xsp+28h] [xbp-18h]
  __int64 v33; // [xsp+30h] [xbp-10h]
  __int64 v34; // [xsp+38h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
    goto LABEL_8;
  v2 = *(_DWORD *)(a2 + 20);
  v32 = nullptr;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v29 = 0;
  v28[1] = v2;
  cmd_type = csr_get_cmd_type(a2);
  v6 = *(_QWORD *)(a1 + 21624);
  v7 = *(_DWORD *)(a2 + 24);
  v28[0] = cmd_type;
  vdev_by_id_from_psoc_no_state = (unsigned int *)wlan_objmgr_get_vdev_by_id_from_psoc_no_state(v6, v7, 0xBu);
  v9 = *(_QWORD *)(a1 + 21624);
  v32 = vdev_by_id_from_psoc_no_state;
  pending_list_next_node_using_psoc = wlan_serialization_get_pending_list_next_node_using_psoc(
                                        v9,
                                        (__int64)v28,
                                        0,
                                        v10,
                                        v11,
                                        v12,
                                        v13,
                                        v14,
                                        v15,
                                        v16,
                                        v17);
  if ( v32 )
    wlan_objmgr_vdev_release_ref((__int64)v32, 0xBu, v32, v19, v20, v21, v22, v23, v24, v25, v26);
  if ( pending_list_next_node_using_psoc )
  {
    while ( *(_DWORD *)(pending_list_next_node_using_psoc + 16) )
    {
      result = wlan_serialization_get_pending_list_next_node_using_psoc(
                 *(_QWORD *)(a1 + 21624),
                 pending_list_next_node_using_psoc,
                 0,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26);
      pending_list_next_node_using_psoc = result;
      if ( !result )
        goto LABEL_10;
    }
    result = *(_QWORD *)(pending_list_next_node_using_psoc + 40);
  }
  else
  {
LABEL_8:
    result = 0;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
