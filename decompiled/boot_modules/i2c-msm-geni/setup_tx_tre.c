__int64 __fastcall setup_tx_tre(
        __int64 a1,
        __int64 a2,
        int a3,
        int a4,
        unsigned __int8 *a5,
        unsigned int a6,
        char a7,
        unsigned int a8)
{
  __int64 v8; // x10
  unsigned int v11; // w8
  _QWORD *v12; // x20
  __int64 v13; // x11
  char *v14; // x12
  _BYTE *v15; // x13
  char v16; // t1
  int v17; // w4
  __int64 v18; // x11
  int v19; // w5
  int v20; // w9
  int v21; // w10
  int v22; // w10
  int v23; // w10

  if ( a8 >= 4 )
    goto LABEL_31;
  v8 = a2 + 16LL * a3;
  v11 = *(unsigned __int16 *)(v8 + 4);
  v12 = (_QWORD *)(a1 + 16LL * a8 + 5216);
  if ( *(_BYTE *)(a1 + 1360) == 1 )
  {
    *a5 = (((_BYTE)a3 + 1) & 0x3F) != 0;
    if ( a4 - 1 == a3 )
      *a5 = *(_BYTE *)(a1 + 9085);
  }
  if ( v11 <= 8 )
  {
    *v12 = 0;
    v13 = *(unsigned __int16 *)(v8 + 4);
    if ( *(_WORD *)(v8 + 4) )
    {
      v14 = *(char **)(v8 + 8);
      v15 = (_BYTE *)(a1 + 16LL * a8 + 5216);
      do
      {
        v16 = *v14++;
        --v13;
        *v15++ = v16;
      }
      while ( v13 );
      v17 = *(_WORD *)(v8 + 4) & 0xF;
    }
    else
    {
      v17 = 0;
    }
    v22 = *(unsigned __int8 *)(a1 + 9122);
    *(_DWORD *)(a1 + 16LL * a8 + 5224) = v17;
    if ( v22 == 1 )
    {
      if ( (a7 & 1) != 0 )
        v19 = 1114113;
      else
        v19 = (*a5 << 10) | 0x110200;
    }
    else
    {
      v23 = *a5 << 10;
      if ( a4 - 1 == a3 && (*(_BYTE *)(a1 + 9085) & 1) != 0 )
        v19 = v23 + 1114625;
      else
        v19 = v23 | 0x110200;
    }
    goto LABEL_28;
  }
  if ( a6 > 0x1BF )
  {
LABEL_31:
    __break(0x5512u);
    return gi2c_gsi_tre_process(a1, a2);
  }
  v18 = a1 + 8LL * a6;
  v19 = 1048577;
  *(_DWORD *)v12 = *(_QWORD *)(v18 + 5280);
  *(_DWORD *)(a1 + 16LL * a8 + 5220) = *(_DWORD *)(v18 + 5284);
  LODWORD(v18) = *(unsigned __int8 *)(a1 + 9122);
  v17 = *(unsigned __int16 *)(v8 + 4);
  *(_DWORD *)(a1 + 16LL * a8 + 5224) = v17;
  if ( (_DWORD)v18 == 1 )
  {
    if ( (a7 & 1) == 0 )
    {
      v20 = (*a5 << 10) + 1048577;
LABEL_27:
      v19 = v20 + 511;
    }
  }
  else
  {
    v21 = *a5 << 10;
    if ( a4 - 1 != a3 || (*(_BYTE *)(a1 + 9085) & 1) == 0 )
    {
      v20 = v21 + 1048577;
      goto LABEL_27;
    }
    v19 = v21 + 1049089;
  }
LABEL_28:
  *(_DWORD *)(a1 + 16LL * a8 + 5228) = v19;
  ipc_log_string(
    *(_QWORD *)(a1 + 5096),
    "tx_tre 0x%x 0x%x 0x%x 0x%x imm_dma:%d bei:%d\n",
    *(_DWORD *)(a1 + 16LL * a8 + 5216),
    *(_DWORD *)(a1 + 16LL * a8 + 5220),
    v17,
    v19,
    v11 < 9,
    *a5);
  if ( *(_QWORD *)a1 )
    i2c_trace_log();
  return (__int64)v12;
}
