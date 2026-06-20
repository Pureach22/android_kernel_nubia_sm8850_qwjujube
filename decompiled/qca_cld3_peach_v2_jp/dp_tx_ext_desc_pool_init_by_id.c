__int64 __fastcall dp_tx_ext_desc_pool_init_by_id(__int64 a1, unsigned __int16 a2, unsigned __int8 a3)
{
  __int64 v3; // x29
  __int64 v4; // x30
  __int64 v6; // x20
  __int64 v7; // x0
  _QWORD *v8; // x8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  const char *v17; // x2
  _QWORD *v19; // x12
  _QWORD *v20; // x10
  unsigned int v21; // w9
  _QWORD *v22; // x11
  __int64 v23; // x12
  _QWORD *v24; // x13
  __int64 v25; // [xsp+8h] [xbp-18h]

  if ( a3 >= 7u )
  {
    __break(0x5512u);
    JUMPOUT(0x59DB824);
  }
  v25 = v4;
  v6 = a1 + 136LL * a3;
  v7 = *(_QWORD *)(a1 + 24);
  *(_DWORD *)(v6 + 4088) = 56;
  v8 = *(_QWORD **)(v6 + 4112);
  *(_DWORD *)(v6 + 4036) = 136;
  *(_WORD *)(v6 + 4032) = a2;
  *(_QWORD *)(v6 + 4136) = *v8;
  if ( (unsigned int)qdf_mem_multi_page_link(v7, (unsigned __int16 *)(v6 + 4096), 0x38u, a2, 1) )
  {
    v17 = "ext link desc page linking fail";
    goto LABEL_4;
  }
  if ( !*(_WORD *)(v6 + 4032) )
  {
LABEL_13:
    *(_WORD *)(v6 + 4040) = a2;
    *(_DWORD *)(v6 + 4144) = 0;
    *(_QWORD *)(v6 + 4152) = 0;
    return 0;
  }
  v19 = *(_QWORD **)(v6 + 4136);
  v20 = *(_QWORD **)(v6 + 4056);
  v21 = 0;
  v22 = v19;
  while ( 1 )
  {
    if ( (unsigned __int16)v21 % (unsigned int)*(unsigned __int16 *)(v6 + 4048) )
    {
      v22[1] = v19[1] + *(int *)(v6 + 4036);
      v23 = v19[2] + *(int *)(v6 + 4036);
      goto LABEL_11;
    }
    if ( !**(_QWORD **)(v6 + 4056) )
      break;
    v22[1] = *v20;
    v23 = v20[2];
    v20 += 3;
LABEL_11:
    v24 = (_QWORD *)*v22;
    v22[2] = v23;
    if ( v24 )
    {
      ++v21;
      v19 = v22;
      v22 = v24;
      if ( v21 < *(unsigned __int16 *)(v6 + 4032) )
        continue;
    }
    goto LABEL_13;
  }
  v17 = "link over flow";
LABEL_4:
  qdf_trace_msg(0x45u, 2u, v17, v9, v10, v11, v12, v13, v14, v15, v16, v3, v25);
  return 5;
}
