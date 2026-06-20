__int64 __fastcall swrm_initialize_clk_base_scale(__int64 result, unsigned __int8 a2)
{
  __int16 v2; // w22
  __int64 v4; // x20
  __int64 v5; // x21
  int v6; // w0
  int v7; // w3
  char v8; // w8
  int v9; // w3
  unsigned int v10; // w8
  unsigned int v11; // w9
  bool v12; // zf
  char v13; // w8
  unsigned int v14; // w9
  int v15; // w21
  int v16; // w3
  char v17; // w8

  if ( a2 )
  {
    v2 = 8 * a2;
    v4 = result;
    v5 = (unsigned int)swr_master_read(result, v2 + 1332);
    result = swr_master_read(v4, v2 + 1328);
    if ( (v5 & 0xFF00) != 0 || ((int)result | (unsigned __int64)(v5 << 32)) - 0x1001170223LL <= 1 )
    {
      if ( (swr_master_read(v4, 0x104Cu) & 1) != 0 )
      {
        v6 = swr_master_read(v4, 0x105Cu);
        swrm_cmd_fifo_wr_cmd(v4, v6, 0xFu, 0xFu, 0x70u);
      }
      v7 = *(unsigned __int8 *)(v4 + 9050);
      v8 = (v7 + 1) & 0xF;
      if ( v7 == 14 )
        v8 = 0;
      *(_BYTE *)(v4 + 9050) = v8;
      swrm_cmd_fifo_wr_cmd(v4, 1, a2, v7, 0x4Du);
      v9 = *(unsigned __int8 *)(v4 + 9050);
      v10 = 2 * *(_DWORD *)(v4 + 9132) / *(_DWORD *)(v4 + 9136);
      v11 = __rbit32(v10);
      v12 = v10 == 0;
      v13 = (v9 + 1) & 0xF;
      v14 = __clz(v11);
      if ( v12 )
        v15 = 0;
      else
        v15 = v14 + 1;
      if ( v9 == 14 )
        v13 = 0;
      *(_BYTE *)(v4 + 9050) = v13;
      swrm_cmd_fifo_wr_cmd(v4, v15, a2, v9, 0x62u);
      v16 = *(unsigned __int8 *)(v4 + 9050);
      v17 = (v16 + 1) & 0xF;
      if ( v16 == 14 )
        v17 = 0;
      *(_BYTE *)(v4 + 9050) = v17;
      return swrm_cmd_fifo_wr_cmd(v4, v15, a2, v16, 0x72u);
    }
  }
  return result;
}
