_BYTE *__fastcall pre_cac_get_vdev_id_handler(__int64 a1, __int64 a2, _BYTE *a3)
{
  _BYTE *result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7

  result = (_BYTE *)wlan_objmgr_vdev_get_comp_private_obj(a2, 0x2Du);
  if ( !result )
    return (_BYTE *)qdf_trace_msg(
                      0x98u,
                      2u,
                      "%s:%u: vdev id: %d, vdev_priv is NULL",
                      v6,
                      v7,
                      v8,
                      v9,
                      v10,
                      v11,
                      v12,
                      v13,
                      "pre_cac_get_vdev_id_handler",
                      271,
                      *(unsigned __int8 *)(a2 + 104));
  if ( *result == 1 )
    *a3 = *(_BYTE *)(a2 + 104);
  return result;
}
