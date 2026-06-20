__int64 __fastcall swrm_master_init(__int64 a1)
{
  int v2; // w8
  int v3; // w9
  int v4; // w21
  unsigned int *v5; // x0
  int v6; // w0
  int v7; // w9
  int v8; // w8
  int v9; // w8
  int v10; // w0
  int v11; // w9
  int v12; // w9
  unsigned int v13; // w8
  int v14; // w11
  unsigned int v15; // w14
  __int64 v16; // x20
  unsigned int v17; // w10
  int v18; // w8
  int v19; // w21
  int *v21; // x25
  int v22; // t1
  __int64 v23; // x23
  int v24; // w0
  __int64 result; // x0
  int v26; // w0
  _DWORD v27[4]; // [xsp+8h] [xbp-68h] BYREF
  __int64 v28; // [xsp+18h] [xbp-58h]
  __int64 v29; // [xsp+20h] [xbp-50h]
  __int64 v30; // [xsp+28h] [xbp-48h]
  __int64 v31; // [xsp+30h] [xbp-40h]
  _QWORD v32[2]; // [xsp+38h] [xbp-38h] BYREF
  __int64 v33; // [xsp+48h] [xbp-28h]
  __int64 v34; // [xsp+50h] [xbp-20h]
  __int64 v35; // [xsp+58h] [xbp-18h]
  __int64 v36; // [xsp+60h] [xbp-10h]
  __int64 v37; // [xsp+68h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 9052);
  v3 = *(_DWORD *)(a1 + 9128);
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v30 = 0;
  v31 = 0;
  if ( v2 == 1 )
    v4 = 1;
  else
    v4 = 3;
  v28 = 0;
  v29 = 0;
  if ( v3 > 17170431 )
  {
    v5 = *(unsigned int **)(a1 + 9040);
    if ( v5 )
    {
      v6 = readl(v5);
      writel(v6 & 0xFFFFFFFD, *(unsigned int **)(a1 + 9040));
      usleep_range_state(500, 505, 2);
      readl(*(unsigned int **)(a1 + 9040));
      v2 = *(_DWORD *)(a1 + 9052);
    }
  }
  if ( v2 == 5 )
    v7 = 24;
  else
    v7 = 8;
  if ( a1 )
  {
    if ( v2 == 5 )
      v8 = 512000;
    else
      v8 = 400000;
    v9 = ((unsigned __int8)(2 * *(_DWORD *)(a1 + 9136) / v8) << 16) - 0x10000;
  }
  else
  {
    v9 = 0;
  }
  v32[0] = 0x5000000101CLL;
  v27[0] = v9 | v7;
  v27[1] = 1;
  v10 = swr_master_read(a1, 0x1048u);
  v11 = *(_DWORD *)(a1 + 9128);
  v27[2] = v10 | 0x3E0000;
  v27[3] = v4;
  v32[1] = 0x31400001048LL;
  if ( v11 <= 17235967 )
  {
    v13 = 4;
  }
  else
  {
    v12 = *(_DWORD *)(a1 + 9056);
    LODWORD(v33) = 24;
    v13 = 5;
    LODWORD(v28) = v12;
  }
  if ( *(_DWORD *)(a1 + 9052) == 5 )
  {
    *((_DWORD *)v32 + v13) = 1812;
    v27[v13++] = 1;
  }
  v14 = *(_DWORD *)(a1 + 9056);
  v27[v13] = 2;
  v14 <<= 12;
  v27[v13 + 1] = -1;
  *((_DWORD *)v32 + v13 + 1) = v14 + 16392;
  v27[v13 + 2] = 1965565;
  *((_DWORD *)&v32[1] + v13) = v14 + 16388;
  v15 = v13 + 3;
  v16 = v13 + 5;
  *((_DWORD *)v32 + v13) = 4;
  *((_DWORD *)v32 + v15) = 4;
  v17 = v13 + 4;
  v27[v15] = 3;
  *(_DWORD *)(a1 + 15836) = 1965565;
  *((_DWORD *)v32 + v17) = v14 + 16480;
  v27[v17] = 1;
  swr_master_bulk_write(a1, v32, v27, (unsigned int)v16);
  v18 = *(_DWORD *)(a1 + 9128);
  if ( v18 < 17104898 )
  {
LABEL_32:
    if ( v18 >= 17104897 )
    {
      v26 = swr_master_read(a1, 0x314u);
      swr_master_write(a1, 0x314u, v26 | 0x80000000);
    }
    result = 0;
  }
  else
  {
    v19 = -100;
    do
    {
      if ( (swr_master_read(a1, ((unsigned __int16)*(_DWORD *)(a1 + 9056) << 12) + 16484) & 1) != 0 )
      {
        v18 = *(_DWORD *)(a1 + 9128);
        goto LABEL_32;
      }
      usleep_range_state(500, 510, 2);
    }
    while ( !__CFADD__(v19++, 1) );
    if ( (unsigned int)__ratelimit(&swrm_check_link_status__rs, "swrm_check_link_status") )
      dev_err(*(_QWORD *)(a1 + 8512), "%s: link status not %s\n", "swrm_check_link_status", "connected");
    dev_err(*(_QWORD *)(a1 + 8512), "%s: swr link failed to connect\n", "swrm_master_init");
    v21 = (int *)v32;
    do
    {
      usleep_range_state(50, 55, 2);
      v22 = *v21++;
      v23 = *(_QWORD *)(a1 + 8512);
      v24 = swr_master_read(a1, v22);
      dev_err(v23, "%s:reg:0x%x val:0x%x\n", "swrm_master_init", v22, v24);
      --v16;
      result = 4294967274LL;
    }
    while ( v16 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
