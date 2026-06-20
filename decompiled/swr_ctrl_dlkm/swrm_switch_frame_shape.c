__int64 __fastcall swrm_switch_frame_shape(__int64 a1, int a2)
{
  int v3; // w20
  int v4; // w22
  int v5; // w23
  int v6; // w24
  int v7; // w21
  char v8; // w0
  int v9; // w8
  char v10; // w22

  if ( a2 == 11289600 )
  {
    v4 = 3675;
    v5 = 16;
    v6 = 64;
    v3 = 7;
    v7 = 3;
  }
  else
  {
    v3 = 0;
    v4 = 4000;
    v5 = 2;
    if ( a2 == 12288000 )
    {
      v6 = 64;
      v7 = 3;
    }
    else
    {
      v6 = 50;
      v7 = 1;
    }
  }
  v8 = swr_master_read(a1, 4172);
  if ( a1 )
    v9 = ((unsigned __int8)(2 * *(_DWORD *)(a1 + 9136) / (v5 * v6 * v4)) << 16) - 0x10000;
  else
    v9 = 0;
  v10 = ~v8;
  swr_master_write(a1, (((v8 & 1) == 0) << 6) | 0x101Cu, (unsigned int)(v9 + v3 + 8 * v7));
  return swrm_cmd_fifo_wr_cmd(a1, v3 & 0xFFFFFFE7 | (8 * (v7 & 3)), 15, 15, (16 * (v10 & 1)) | 0x60u);
}
