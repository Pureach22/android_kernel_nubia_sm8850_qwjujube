__int64 __fastcall reg_11d_vdev_delete_update(__int64 a1, unsigned int a2, int a3)
{
  __int64 psoc_obj; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x8
  __int64 result; // x0
  _BYTE *v17; // x8
  unsigned __int8 *v18; // x9
  __int64 v19; // x10
  char v20; // w11
  int v21; // w4

  psoc_obj = reg_get_psoc_obj(a1);
  if ( !psoc_obj )
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: NULL reg psoc private obj",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "reg_11d_vdev_delete_update");
    return 5;
  }
  v15 = psoc_obj;
  result = 0;
  if ( a2 > 7 || ((1 << a2) & 0x85) == 0 )
    return result;
  v17 = (_BYTE *)(v15 + 90112);
  v18 = v17 + 1048;
  if ( (unsigned __int8)v17[1048] == a3 )
  {
    v19 = 0;
LABEL_13:
    v20 = v17[1042];
    v18[v19] = -1;
    v17[1042] = v20 - 1;
    goto LABEL_14;
  }
  if ( (unsigned __int8)v17[1049] == a3 )
  {
    v19 = 1;
    goto LABEL_13;
  }
  if ( (unsigned __int8)v17[1050] == a3 )
  {
    v19 = 2;
    goto LABEL_13;
  }
  if ( (unsigned __int8)v17[1051] == a3 )
  {
    v19 = 3;
    goto LABEL_13;
  }
LABEL_14:
  if ( (unsigned __int8)v17[1041] == a3 )
  {
    if ( !v17[1042] )
    {
      v17[1039] = 0;
      v17[1041] = -1;
      return 0;
    }
    v21 = *v18;
    if ( v21 != 255
      || (v21 = (unsigned __int8)v17[1049], v21 != 255)
      || (v21 = (unsigned __int8)v17[1050], v21 != 255)
      || (v21 = (unsigned __int8)v17[1051], v21 != 255) )
    {
      v17[1041] = v21;
      v17[1039] = 0;
      qdf_trace_msg(
        0x51u,
        8u,
        "%s: running 11d state machine, vdev %d",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "reg_11d_vdev_delete_update");
      reg_run_11d_state_machine(a1);
    }
  }
  return 0;
}
