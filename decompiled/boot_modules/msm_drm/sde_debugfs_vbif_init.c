__int64 __fastcall sde_debugfs_vbif_init(__int64 a1, __int64 a2)
{
  __int64 dir; // x0
  __int64 v4; // x8
  unsigned __int64 v5; // x23
  __int64 v6; // x21
  __int64 v7; // x24
  __int64 v8; // x20
  unsigned int v9; // w21
  __int64 v10; // x22
  unsigned int v11; // w21
  __int64 v12; // x22
  __int64 result; // x0
  char s[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v15; // [xsp+10h] [xbp-20h]
  __int64 v16; // [xsp+18h] [xbp-18h]
  __int64 v17; // [xsp+20h] [xbp-10h]
  __int64 v18; // [xsp+28h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v17 = 0;
  *(_QWORD *)s = 0;
  v15 = 0;
  dir = debugfs_create_dir("vbif", a2);
  *(_QWORD *)(a1 + 1744) = dir;
  if ( dir )
  {
    v4 = *(_QWORD *)(a1 + 152);
    if ( *(_DWORD *)(v4 + 15336) )
    {
      v5 = 0;
      do
      {
        if ( v5 == 13 )
          __break(0x5512u);
        v6 = v4 + 280 * v5;
        v7 = v6 + 15344;
        snprintf(s, 0x20u, "%d", *(_DWORD *)(v6 + 15360));
        v8 = debugfs_create_dir(s, *(_QWORD *)(a1 + 1744));
        debugfs_create_u32("features", 256, v8, v6 + 15376);
        debugfs_create_u32("xin_halt_timeout", 256, v8, v6 + 15400);
        debugfs_create_u32("default_rd_ot_limit", 256, v8, v6 + 15392);
        debugfs_create_u32("default_wr_ot_limit", 256, v8, v6 + 15396);
        if ( *(_DWORD *)(v6 + 15408) )
        {
          v9 = 0;
          do
          {
            v10 = *(_QWORD *)(v7 + 72) + 16LL * (int)v9;
            snprintf(s, 0x20u, "dynamic_ot_rd_%d_pps", v9);
            debugfs_create_u64(s, 256, v8, v10);
            snprintf(s, 0x20u, "dynamic_ot_rd_%d_ot_limit", v9);
            debugfs_create_u32(s, 256, v8, v10 + 8);
            ++v9;
          }
          while ( v9 < *(_DWORD *)(v7 + 64) );
        }
        if ( *(_DWORD *)(v7 + 80) )
        {
          v11 = 0;
          do
          {
            v12 = *(_QWORD *)(v7 + 88) + 16LL * (int)v11;
            snprintf(s, 0x20u, "dynamic_ot_wr_%d_pps", v11);
            debugfs_create_u64(s, 256, v8, v12);
            snprintf(s, 0x20u, "dynamic_ot_wr_%d_ot_limit", v11);
            debugfs_create_u32(s, 256, v8, v12 + 8);
            ++v11;
          }
          while ( v11 < *(_DWORD *)(v7 + 80) );
        }
        v4 = *(_QWORD *)(a1 + 152);
        ++v5;
      }
      while ( v5 < *(unsigned int *)(v4 + 15336) );
    }
    result = 0;
  }
  else
  {
    printk(&unk_22B4FA, "sde_debugfs_vbif_init");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
