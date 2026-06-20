__int64 __fastcall dump_stack_minidump(__int64 result)
{
  unsigned __int64 StatusReg; // x11
  unsigned int v2; // w19
  __int64 v3; // x8
  unsigned __int64 v4; // x20
  unsigned __int64 v5; // x9
  unsigned __int64 v6; // x10
  char v7; // w11
  unsigned __int64 v8; // x8
  unsigned int v9; // w28
  unsigned int v10; // w21
  signed __int64 v11; // x26
  unsigned __int64 v12; // x9
  unsigned __int64 v13; // x12
  __int64 v14; // x9
  __int64 v15; // x8
  __int64 v16; // x8
  unsigned __int64 v17; // x9
  __int64 v18; // x8
  unsigned __int64 v19; // x12
  __int64 v20; // x9
  unsigned __int64 v21; // [xsp+0h] [xbp-70h] BYREF
  _QWORD v22[3]; // [xsp+8h] [xbp-68h] BYREF
  unsigned __int64 v23; // [xsp+20h] [xbp-50h]
  __int64 v24; // [xsp+28h] [xbp-48h]
  __int64 v25; // [xsp+30h] [xbp-40h]
  _QWORD v26[3]; // [xsp+38h] [xbp-38h] BYREF
  unsigned __int64 v27; // [xsp+50h] [xbp-20h]
  __int64 v28; // [xsp+58h] [xbp-18h]
  __int64 v29; // [xsp+60h] [xbp-10h]
  __int64 v30; // [xsp+68h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = 0;
  v29 = 0;
  v27 = 0;
  memset(v26, 0, sizeof(v26));
  v24 = 0;
  v25 = 0;
  v23 = 0;
  memset(v22, 0, sizeof(v22));
  if ( stack_dump == 1 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 68) & 2) == 0 )
    {
      v2 = *(_DWORD *)(StatusReg + 40);
      is_vmap_stack = 1;
      if ( (unsigned __int64)(result + 255) <= 0xFFFFFFC0800000FELL )
        result = (__int64)&v21;
      v3 = *(_QWORD *)(StatusReg + 3272);
      v21 = StatusReg;
      v4 = result & 0xFFFFFFFFFFFFF000LL;
      v6 = *(_QWORD *)(v3 + 8);
      v5 = *(_QWORD *)(v3 + 16);
      v7 = *(_BYTE *)(v3 + 24);
      v8 = v5 - 4096;
      if ( (v7 & 0x40) != 0 )
        v8 = v5;
      if ( v4 >= v6 && v6 + (unsigned int)v8 > v4 )
      {
        v9 = (v8 >> 12) - ((v4 - v6) >> 12);
        if ( v9 )
        {
          v10 = 0;
          v11 = (result << 8) & 0xFFFFFFFFFFF00000LL;
          do
          {
            scnprintf(v26, 13, "KSTACK%d_%d", v2, v10);
            v27 = v4;
            v29 = 4096;
            if ( is_vmap_stack == 1 )
            {
              v15 = ((vmalloc_to_page(v4) - -64LL * (memstart_addr >> 12)) << 6) + 0x5000000000LL;
            }
            else
            {
              v12 = (v11 >> 8) + 0x8000000000LL;
              v13 = v12 >> 38;
              v14 = memstart_addr + v12;
              v15 = (v11 >> 8) - kimage_voffset;
              if ( !v13 )
                v15 = v14;
            }
            v28 = v15;
            if ( (msm_minidump_add_region(v26) & 0x80000000) != 0 )
              printk_deferred("Failed to add stack of entry %s in Minidump\n", (const char *)v26);
            ++v10;
            v4 += 4096LL;
            v11 += 0x100000LL;
          }
          while ( v10 < v9 );
        }
      }
      scnprintf(v22, 13, "KTASK%d", v2);
      v16 = (__int64)(v21 << 8) >> 8;
      v17 = v16 + 0x8000000000LL;
      v18 = v16 - kimage_voffset;
      v19 = v17 >> 38;
      v20 = memstart_addr + v17;
      if ( !v19 )
        v18 = v20;
      v23 = v21;
      v24 = v18;
      v25 = 5184;
      result = msm_minidump_add_region(v22);
      if ( (result & 0x80000000) != 0 )
        result = printk(&unk_112E4B, v2);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
