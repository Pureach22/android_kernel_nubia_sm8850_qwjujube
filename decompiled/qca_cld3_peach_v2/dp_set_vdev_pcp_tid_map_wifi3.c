__int64 __fastcall dp_set_vdev_pcp_tid_map_wifi3(__int64 a1, __int64 a2, unsigned __int8 a3, char a4)
{
  __int64 ref_by_id_0; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x8

  ref_by_id_0 = dp_vdev_get_ref_by_id_0();
  if ( !ref_by_id_0 )
    return 16;
  if ( a3 >= 8u )
  {
    __break(0x5512u);
    return dp_vdev_get_ref_by_id_0();
  }
  else
  {
    v16 = ref_by_id_0 + a3;
    *(_BYTE *)(v16 + 43274) = a4;
    dp_vdev_unref_delete(a1, ref_by_id_0, 7u, (unsigned int *)v16, v8, v9, v10, v11, v12, v13, v14, v15);
    return 0;
  }
}
