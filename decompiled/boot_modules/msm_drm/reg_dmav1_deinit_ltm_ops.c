__int64 __fastcall reg_dmav1_deinit_ltm_ops(__int64 a1)
{
  __int64 v1; // d14
  __int64 v3; // x21
  __int64 v4; // x15
  unsigned __int64 ops; // x20
  __int64 v6; // d3
  __int64 result; // x0
  __int64 v8; // x21
  __int64 v9; // x22
  char *v10; // x23
  __int64 v11; // x1
  __int64 (*v12)(void); // x8
  __int64 v13; // x8
  __int64 v14; // x8

  v3 = *(unsigned int *)(a1 + 64);
  ops = sde_reg_dma_get_ops(*(unsigned int *)(a1 + 1496));
  result = 4294966772LL;
  if ( ops && ops <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( (unsigned int)v3 <= 4 )
    {
      v8 = 16 * v3;
      v9 = 0;
      v10 = (char *)&ltm_buf + v8;
      while ( 1 )
      {
        v11 = *(unsigned int *)(a1 + 1496);
        if ( (unsigned int)v11 > 1 )
          break;
        if ( (unsigned __int64)(v8 + v9 + 8 * v11) > 0x7CF )
          goto LABEL_15;
        result = *(_QWORD *)&v10[8 * v11 + v9];
        if ( result )
        {
          v12 = *(__int64 (**)(void))(ops + 56);
          if ( *((_DWORD *)v12 - 1) != 1800240171 )
            __break(0x8228u);
          result = v12();
          v13 = *(unsigned int *)(a1 + 1496);
          if ( (unsigned int)v13 > 1 )
            break;
          v14 = 8 * v13;
          if ( (unsigned __int64)(v8 + v9 + v14) > 0x7CF )
          {
LABEL_15:
            __break(1u);
            return 0;
          }
          *(_QWORD *)&v10[v14 + v9] = 0;
        }
        v9 += 80;
        if ( v9 == 2000 )
          return 0;
      }
      __break(0x5512u);
      *(_QWORD *)(v4 - 24) = v1;
      *(_QWORD *)(v4 - 16) = v6;
      return reg_dmav1_setup_ltm_initv1(result);
    }
    else
    {
      _drm_dev_dbg(0, 0, 0, "invalid ltm idx %x max %xd\n", v3, 5);
      return 4294967274LL;
    }
  }
  return result;
}
