__int64 __fastcall swrm_update_clk_base_and_scale(__int64 a1, unsigned __int8 a2)
{
  __int64 v2; // x19
  __int64 result; // x0
  __int64 *v6; // x21
  __int64 *v7; // x22
  unsigned int v8; // w20
  __int16 v9; // w23
  unsigned __int8 v10; // w2
  int v11; // w3
  char v12; // w8
  int v13; // w3
  unsigned __int8 v14; // w2
  unsigned int v15; // w8
  bool v16; // zf
  unsigned int v17; // w8
  int v18; // w1
  char v19; // w8

  if ( a1 && (v2 = *(_QWORD *)(a1 + 152)) != 0 )
  {
    result = swr_master_read(*(_QWORD *)(a1 + 152), 0x1090u);
    v6 = *(__int64 **)(a1 + 984);
    v7 = (__int64 *)(a1 + 984);
    if ( v6 != (__int64 *)(a1 + 984) )
    {
      v8 = result;
      v9 = 16 * a2;
      do
      {
        v10 = *((_BYTE *)v6 + 16);
        if ( v10 && *((_BYTE *)v6 + 945) == 1 && ((v8 >> (2 * v10)) & 3) - 1 <= 1 )
        {
          v11 = *(unsigned __int8 *)(v2 + 9050);
          v12 = (v11 + 1) & 0xF;
          if ( v11 == 14 )
            v12 = 0;
          *(_BYTE *)(v2 + 9050) = v12;
          swrm_cmd_fifo_wr_cmd(v2, 1, v10, v11, 0x4Du);
          v13 = *(unsigned __int8 *)(v2 + 9050);
          v14 = *((_BYTE *)v6 + 16);
          v15 = 2 * *(_DWORD *)(v2 + 9132) / *(_DWORD *)(v2 + 9136);
          v16 = v15 == 0;
          v17 = __clz(__rbit32(v15));
          if ( v16 )
            v18 = 0;
          else
            v18 = v17 + 1;
          v19 = (v13 + 1) & 0xF;
          if ( v13 == 14 )
            v19 = 0;
          *(_BYTE *)(v2 + 9050) = v19;
          result = swrm_cmd_fifo_wr_cmd(v2, v18, v14, v13, v9 + 98);
        }
        v6 = (__int64 *)*v6;
      }
      while ( v6 != v7 );
    }
  }
  else
  {
    result = __ratelimit(&swrm_update_clk_base_and_scale__rs, "swrm_update_clk_base_and_scale");
    if ( (_DWORD)result )
      return printk(&unk_10D41, "swrm_update_clk_base_and_scale");
  }
  return result;
}
