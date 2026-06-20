__int64 __fastcall nan_is_peer_migrated(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  __int64 comp_private_obj; // x0
  unsigned int *v15; // x8
  unsigned int v22; // w20

  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 20);
  if ( !v4 )
    goto LABEL_35;
  v13 = v4;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v4, 0xFu);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(0x53u, 2u, "%s: NAN vdev priv obj is null", v5, v6, v7, v8, v9, v10, v11, v12, "nan_is_peer_migrated");
    goto LABEL_37;
  }
  v15 = (unsigned int *)*(unsigned __int8 *)(comp_private_obj + 107);
  if ( !*(_BYTE *)(comp_private_obj + 107) )
    goto LABEL_37;
  if ( *(_DWORD *)a3 == *(_DWORD *)(comp_private_obj + 108)
    && *(unsigned __int16 *)(a3 + 4) == *(unsigned __int16 *)(comp_private_obj + 112) )
  {
    goto LABEL_38;
  }
  v15 = (unsigned int *)*(unsigned __int8 *)(comp_private_obj + 107);
  if ( (unsigned int)v15 < 2 )
    goto LABEL_37;
  if ( *(_DWORD *)a3 == *(_DWORD *)(comp_private_obj + 114)
    && *(unsigned __int16 *)(a3 + 4) == *(unsigned __int16 *)(comp_private_obj + 118) )
  {
    goto LABEL_38;
  }
  v15 = (unsigned int *)*(unsigned __int8 *)(comp_private_obj + 107);
  if ( (unsigned int)v15 < 3 )
    goto LABEL_37;
  if ( *(_DWORD *)a3 == *(_DWORD *)(comp_private_obj + 120)
    && *(unsigned __int16 *)(a3 + 4) == *(unsigned __int16 *)(comp_private_obj + 124) )
  {
    goto LABEL_38;
  }
  v15 = (unsigned int *)*(unsigned __int8 *)(comp_private_obj + 107);
  if ( (unsigned int)v15 < 4 )
    goto LABEL_37;
  if ( *(_DWORD *)a3 == *(_DWORD *)(comp_private_obj + 126)
    && *(unsigned __int16 *)(a3 + 4) == *(unsigned __int16 *)(comp_private_obj + 130) )
  {
    goto LABEL_38;
  }
  v15 = (unsigned int *)*(unsigned __int8 *)(comp_private_obj + 107);
  if ( (unsigned int)v15 < 5 )
    goto LABEL_37;
  if ( *(_DWORD *)a3 == *(_DWORD *)(comp_private_obj + 132)
    && *(unsigned __int16 *)(a3 + 4) == *(unsigned __int16 *)(comp_private_obj + 136) )
  {
    goto LABEL_38;
  }
  v15 = (unsigned int *)*(unsigned __int8 *)(comp_private_obj + 107);
  if ( (unsigned int)v15 < 6 )
  {
LABEL_37:
    v22 = 0;
LABEL_39:
    wlan_objmgr_vdev_release_ref(v13, 0x14u, v15, v5, v6, v7, v8, v9, v10, v11, v12);
    return v22;
  }
  if ( *(_DWORD *)a3 == *(_DWORD *)(comp_private_obj + 138)
    && *(unsigned __int16 *)(a3 + 4) == *(unsigned __int16 *)(comp_private_obj + 142) )
  {
LABEL_38:
    qdf_trace_msg(0x53u, 8u, "%s: peer found", v5, v6, v7, v8, v9, v10, v11, v12, "nan_is_peer_migrated");
    v22 = 1;
    goto LABEL_39;
  }
  v15 = (unsigned int *)*(unsigned __int8 *)(comp_private_obj + 107);
  if ( (unsigned int)v15 < 7 )
    goto LABEL_37;
  __break(0x5512u);
LABEL_35:
  qdf_trace_msg(0x53u, 2u, "%s: vdev is null", v5, v6, v7, v8, v9, v10, v11, v12, "nan_is_peer_migrated");
  return 0;
}
