__int64 __fastcall dump_regs_v1(__int64 result)
{
  int v1; // w19
  __int64 v2; // x9
  __int64 v3; // x8
  int v4; // w11
  int v5; // w10
  int v6; // w8
  unsigned int v7; // w20
  unsigned int v8; // w24
  int v9; // w0
  __int64 v10; // x10
  int v11; // w9
  int v12; // w10
  unsigned int v13; // w19
  unsigned int v14; // w21
  int v15; // w0
  __int64 v16; // [xsp+8h] [xbp-28h] BYREF
  __int64 v17; // [xsp+10h] [xbp-20h]
  __int64 v18; // [xsp+18h] [xbp-18h]
  __int64 v19; // [xsp+20h] [xbp-10h]
  __int64 v20; // [xsp+28h] [xbp-8h]

  v1 = result;
  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)result <= 1 )
  {
    v18 = 0;
    v19 = 0;
    v2 = reg_dma_0[(unsigned int)result];
    v17 = 0;
    v3 = *(_QWORD *)(v2 + 16);
    if ( (*(_BYTE *)v3 & 1) != 0 )
    {
      v4 = *(_DWORD *)(v3 + 24);
      v16 = *(_QWORD *)(v2 + 160);
      v5 = *(_DWORD *)(v3 + 4);
      v6 = reg_dma_register_count;
      LODWORD(v17) = v5;
      HIDWORD(v18) = v4;
      LODWORD(v19) = 0x4000;
      if ( v4 && reg_dma_register_count )
      {
        v7 = 0;
        v8 = 0;
        do
        {
          v9 = sde_reg_read((__int64)&v16, v7);
          result = _drm_err("offset %x val %x\n", v7, v9);
          v6 = reg_dma_register_count;
          ++v8;
          v7 += 4;
        }
        while ( v8 < reg_dma_register_count );
        v2 = reg_dma_0[v1];
      }
    }
    else
    {
      v6 = reg_dma_register_count;
    }
    v18 = 0;
    v19 = 0;
    v10 = *(_QWORD *)(v2 + 16);
    v16 = 0;
    v17 = 0;
    if ( *(_BYTE *)(v10 + 12) )
    {
      v16 = *(_QWORD *)(v2 + 160);
      v11 = *(_DWORD *)(v10 + 16);
      v12 = *(_DWORD *)(v10 + 24);
      LODWORD(v17) = v11;
      HIDWORD(v18) = v12;
      LODWORD(v19) = 0x4000;
      if ( v12 )
      {
        if ( v6 )
        {
          v13 = 0;
          v14 = 0;
          do
          {
            v15 = sde_reg_read((__int64)&v16, v13);
            result = _drm_err("offset %x val %x\n", v13, v15);
            ++v14;
            v13 += 4;
          }
          while ( v14 < reg_dma_register_count );
        }
      }
    }
  }
  else
  {
    result = _drm_err("invalid dpu idx %d\n", result);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
