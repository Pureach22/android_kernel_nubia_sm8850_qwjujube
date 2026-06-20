__int64 __fastcall reg_dmav1_deinit_dspp_ops(__int64 a1)
{
  __int64 v1; // d14
  __int64 v2; // x1
  unsigned int v3; // w3
  __int64 v5; // x15
  unsigned __int64 ops; // x20
  __int64 v7; // d3
  __int64 result; // x0
  __int64 v9; // x21
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 (*v12)(void); // x8
  __int64 v13; // x8
  __int64 v14; // x9
  __int64 v15; // x8

  LODWORD(v2) = *(_DWORD *)(a1 + 64);
  v3 = *(_DWORD *)(a1 + 1496);
  if ( (unsigned int)v2 > 4 || v3 >= 2 )
  {
LABEL_18:
    _drm_err("invalid dspp idx %x max %xd dpu idx %x max %xd\n", v2, 5, v3, 2);
    return 4294967274LL;
  }
  else
  {
    ops = sde_reg_dma_get_ops(v3);
    result = 4294967201LL;
    if ( ops && ops <= 0xFFFFFFFFFFFFF000LL )
    {
      v9 = 0;
      while ( 1 )
      {
        v10 = *(unsigned int *)(a1 + 64);
        if ( (unsigned int)v10 > 4 )
          break;
        v2 = *(unsigned int *)(a1 + 1496);
        if ( (unsigned int)v2 > 1 )
          break;
        v11 = 16 * v10 + 8 * v2;
        if ( (unsigned __int64)(v9 + v11) > 0x7CF )
          goto LABEL_17;
        result = *(unsigned __int64 *)((char *)dspp_buf + v11 + v9);
        if ( result )
        {
          v12 = *(__int64 (**)(void))(ops + 56);
          if ( *((_DWORD *)v12 - 1) != 1800240171 )
            __break(0x8228u);
          result = v12();
          v13 = *(unsigned int *)(a1 + 64);
          if ( (unsigned int)v13 > 4 )
            break;
          v14 = *(unsigned int *)(a1 + 1496);
          if ( (unsigned int)v14 > 1 )
            break;
          v15 = 16 * v13 + 8 * v14;
          if ( (unsigned __int64)(v9 + v15) > 0x7CF )
          {
LABEL_17:
            __break(1u);
            goto LABEL_18;
          }
          *(unsigned __int64 *)((char *)dspp_buf + v15 + v9) = 0;
        }
        v9 += 80;
        if ( v9 == 2000 )
          return 0;
      }
      __break(0x5512u);
      *(_QWORD *)(v5 - 24) = v1;
      *(_QWORD *)(v5 - 16) = v7;
      return reg_dmav1_setup_dspp_memcol_skinv17(result);
    }
  }
  return result;
}
