__int64 __fastcall reg_11d_vdev_created_update(__int64 a1)
{
  unsigned int v2; // w20
  __int64 v3; // x19
  __int64 psoc_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _BYTE *v13; // x8
  __int64 result; // x0
  _BYTE *v15; // x22
  char v16; // w21
  __int64 v17; // x8

  v2 = *(_DWORD *)(a1 + 16);
  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 80LL);
  psoc_obj = reg_get_psoc_obj(v3);
  if ( !psoc_obj )
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: reg psoc private obj is NULL",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "reg_11d_vdev_created_update");
    return 5;
  }
  v13 = (_BYTE *)psoc_obj;
  result = 0;
  if ( v2 <= 7 && ((1 << v2) & 0x85) != 0 )
  {
    v15 = v13 + 90112;
    v16 = *(_BYTE *)(a1 + 104);
    if ( !v13[91154] )
    {
      v13[91153] = v16;
      qdf_trace_msg(
        0x51u,
        8u,
        "%s: running 11d state machine, opmode %d",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "reg_11d_vdev_created_update",
        v2);
      reg_run_11d_state_machine(v3);
    }
    if ( (unsigned __int8)v15[1048] == 255 )
    {
      v17 = 0;
    }
    else if ( (unsigned __int8)v15[1049] == 255 )
    {
      v17 = 1;
    }
    else if ( (unsigned __int8)v15[1050] == 255 )
    {
      v17 = 2;
    }
    else
    {
      if ( (unsigned __int8)v15[1051] != 255 )
      {
LABEL_16:
        ++v15[1042];
        return 0;
      }
      v17 = 3;
    }
    v15[v17 + 1048] = v16;
    goto LABEL_16;
  }
  return result;
}
