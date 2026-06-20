__int64 __fastcall p2p_get_next_seq_num(_WORD *a1, __int64 a2, const void *a3)
{
  _QWORD *v6; // x8
  __int64 v7; // x1
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x20
  __int64 comp_private_obj; // x0
  unsigned int *v19; // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x23
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int *v37; // x8
  unsigned int v38; // w22
  const char *v39; // x2
  __int16 v40; // w9
  __int16 v42; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v43; // [xsp+8h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD **)(a2 + 16);
  v7 = *(unsigned int *)(a2 + 24);
  v42 = 0;
  v8 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(*v6, v7, 15);
  if ( !v8 )
  {
    v39 = "%s: vdev is null";
LABEL_10:
    qdf_trace_msg(0x4Eu, 8u, v39, v9, v10, v11, v12, v13, v14, v15, v16, "p2p_get_next_seq_num");
    v38 = 0;
    goto LABEL_13;
  }
  v17 = v8;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v8, 5u);
  if ( !comp_private_obj )
  {
    wlan_objmgr_vdev_release_ref(v17, 0xFu, v19, v20, v21, v22, v23, v24, v25, v26, v27);
    v39 = "%s: p2p vdev object is NULL";
    goto LABEL_10;
  }
  v28 = comp_private_obj;
  if ( (unsigned int)qdf_mem_cmp((const void *)(comp_private_obj + 952), a3, 6u)
    && (*(_BYTE *)(*(_QWORD *)(a2 + 16) + 272LL) & 2) != 0 )
  {
    get_random_bytes(&v42, 2);
    v40 = *a1 + (v42 & 0x3FF);
    v42 &= 0x3FFu;
    v38 = v40 & 0xFFF;
    qdf_mem_copy((void *)(v28 + 952), a3, 6u);
  }
  else
  {
    v37 = (unsigned int *)(unsigned __int16)*a1;
    if ( (unsigned int)v37 < 0x1000 )
      v38 = (_DWORD)v37 + 1;
    else
      v38 = 0;
  }
  *a1 = v38;
  wlan_objmgr_vdev_release_ref(v17, 0xFu, v37, v29, v30, v31, v32, v33, v34, v35, v36);
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return v38;
}
