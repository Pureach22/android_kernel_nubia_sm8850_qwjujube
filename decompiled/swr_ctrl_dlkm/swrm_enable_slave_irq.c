__int64 __fastcall swrm_enable_slave_irq(__int64 a1)
{
  __int64 result; // x0
  int v3; // w8
  int v4; // w20
  unsigned int v5; // w21
  int v6; // w3
  char v7; // w8
  int v8; // w3
  char v9; // w8
  int v10; // w3
  char v11; // w8
  unsigned int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = swr_master_read(a1, 0x1090u);
  if ( (_DWORD)result )
  {
    v3 = *(_DWORD *)(a1 + 9140);
    if ( v3 != -1 )
    {
      v4 = result;
      v5 = 0;
      v12 = 0;
      do
      {
        if ( (v4 & 3) != 0 )
        {
          if ( (*(_BYTE *)(a1 + 15908) & 1) == 0 )
          {
            v8 = *(unsigned __int8 *)(a1 + 9050);
            v9 = (v8 + 1) & 0xF;
            if ( v8 == 14 )
              v9 = 0;
            *(_BYTE *)(a1 + 9050) = v9;
            swrm_cmd_fifo_rd_cmd(a1, &v12, v5, v8, 0x40u, 1);
            v10 = *(unsigned __int8 *)(a1 + 9050);
            v11 = (v10 + 1) & 0xF;
            if ( v10 == 14 )
              v11 = 0;
            *(_BYTE *)(a1 + 9050) = v11;
            swrm_cmd_fifo_wr_cmd(a1, 255, v5, v10, 0x40u);
          }
          v6 = *(unsigned __int8 *)(a1 + 9050);
          v7 = (v6 + 1) & 0xF;
          if ( v6 == 14 )
            v7 = 0;
          *(_BYTE *)(a1 + 9050) = v7;
          result = swrm_cmd_fifo_wr_cmd(a1, 4, v5, v6, 0x41u);
          v3 = *(_DWORD *)(a1 + 9140);
        }
        ++v5;
        v4 >>= 2;
      }
      while ( v5 < v3 + 1 );
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
