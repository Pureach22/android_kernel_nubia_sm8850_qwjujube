__int64 __fastcall simple_amp_prepare(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  _QWORD *v3; // x20
  unsigned int *v4; // x8
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x3
  __int64 v10; // x4
  __int64 v11; // x8
  __int64 v12; // x21
  __int64 result; // x0
  __int64 v14; // x8
  const char *v15; // x1
  unsigned int v16; // w19
  char v17[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a2 + 96);
  v3 = *(_QWORD **)(*(_QWORD *)(v2 + 24) + 152LL);
  v17[0] = 2;
  if ( !v3 )
    goto LABEL_8;
  v4 = *(unsigned int **)(a2 + 48);
  if ( !v4 )
    goto LABEL_8;
  LODWORD(v6) = swr_connect_port_v2(v3[2], v4 + 1, *v4, v4 + 2, v4 + 9, v4 + 4, v4 + 3, v4 + 5);
  if ( (_DWORD)v6 )
  {
    v14 = *(_QWORD *)(v2 + 24);
    v15 = "%s: swr connect port failed: %d\n";
LABEL_12:
    v16 = v6;
    dev_err(v14, v15, "simple_amp_prepare", (unsigned int)v6);
    result = v16;
    goto LABEL_9;
  }
  v6 = swr_slvdev_datapath_control(v3[2], *(unsigned __int8 *)(v3[2] + 64LL), 1);
  if ( (_DWORD)v6 )
  {
    v14 = *(_QWORD *)(v2 + 24);
    v15 = "%s: slvdev datapath control error: %d\n";
    goto LABEL_12;
  }
  v11 = *(unsigned int *)(a2 + 8);
  if ( (unsigned int)v11 < 4 )
  {
    v12 = v3[v11 + 6];
    if ( v12 )
    {
      regmap_write(
        *v3,
        (*(_DWORD *)(v12 + 192) << 15) & 0x200000
      | ((_DWORD)v11 << 22)
      | ((*(_WORD *)(v12 + 192) & 0x3F) << 7) & 0x7FF8
      | (((*(_DWORD *)(*(_QWORD *)(v12 + 208) + 4LL) >> 3) & 7) << 15)
      | *(_DWORD *)(*(_QWORD *)(v12 + 208) + 4LL) & 7
      | 0x40004008u);
      regmap_write(
        *v3,
        (*(_DWORD *)(v12 + 192) << 15) & 0x200000
      | ((*(_DWORD *)(a2 + 8) & 7) << 22)
      | ((*(_WORD *)(v12 + 192) & 0x3F) << 7) & 0x7FFF
      | *(_DWORD *)(*(_QWORD *)(v12 + 208) + 8LL) & 7
      | (((*(_DWORD *)(*(_QWORD *)(v12 + 208) + 8LL) >> 3) & 7) << 15)
      | 0x40004008u);
      swr_write(v3[2], *(unsigned __int8 *)(v3[2] + 64LL), 76, v17);
      result = 0;
LABEL_9:
      _ReadStatusReg(SP_EL0);
      return result;
    }
LABEL_8:
    result = 4294967274LL;
    goto LABEL_9;
  }
  __break(0x5512u);
  return wait_for_pde_state(v6, v7, v8, v9, v10);
}
