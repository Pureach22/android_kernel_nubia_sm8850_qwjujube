size_t __fastcall sde_dbg_recovery_dump_reg_blk(__int64 a1, char *a2, unsigned int a3)
{
  size_t result; // x0
  int v7; // w22
  __int64 *v8; // x28
  int v9; // w0
  __int64 *v10; // x23
  int v11; // w27
  int v12; // w8
  unsigned int v13; // w8
  char *v14; // x22
  int v15; // w24
  __int64 v16; // x0

  if ( a3 <= 0xFFF )
    return printk(&unk_23C61F, "_sde_dbg_recovery_dump_reg_blk");
  result = strnlen((const char *)(a1 + 32), 0x50u);
  if ( result >= 0x51 )
  {
    _fortify_panic(2, 80, result + 1);
LABEL_21:
    v16 = _fortify_panic(4, 80, 81);
    return sde_dbg_dump_reg_rows(v16);
  }
  if ( !result )
  {
    strcpy(a2, "Found one invalid block - skip dump\n");
    HIDWORD(qword_2945B8) = 36;
    return result;
  }
  if ( result == 80 )
    goto LABEL_21;
  strcpy(a2, "******************************************\n==========================================\n");
  v7 = snprintf(
         a2 + 86,
         0x100u,
         "****** DUMP of %s block (0x%08lx) ******\n",
         (const char *)(a1 + 32),
         *(_QWORD *)(a1 + 120))
     + 86;
  v8 = (__int64 *)(a1 + 16);
  v9 = snprintf(
         &a2[v7],
         0x100u,
         "count:%ld max-off:0x%lx has_sub_blk:%d\n",
         *(_QWORD *)(a1 + 136),
         *(_QWORD *)(a1 + 144),
         *(_QWORD *)(a1 + 16) != a1 + 16);
  v10 = *(__int64 **)(a1 + 16);
  v11 = v9 + v7;
  if ( (__int64 *)*v8 != v8 )
  {
    while ( 1 )
    {
      if ( v10 && a3 - v11 > 0xFFF )
      {
        v13 = *((_DWORD *)v10 + 17) - *((_DWORD *)v10 + 16);
        if ( v13 > 0xF )
        {
          v14 = &a2[v11];
          strcpy(v14, "------------------------------------------\n");
          v15 = snprintf(v14 + 43, 0x100u, "**** sub block [%s] - size:%d ****\n", (const char *)v10 + 24, v13 >> 2)
              + 43;
          result = sde_dbg_dump_reg_rows(*((unsigned int *)v10 + 16));
          v12 = v15 + result;
          goto LABEL_9;
        }
        result = printk(&unk_2778CE, "_sde_dbg_recovery_dump_sub_blk");
      }
      else
      {
        result = printk(&unk_249D41, "_sde_dbg_recovery_dump_sub_blk");
      }
      v12 = 0;
LABEL_9:
      v10 = (__int64 *)*v10;
      v11 += v12;
      if ( v10 == v8 )
        goto LABEL_17;
    }
  }
  result = sde_dbg_dump_reg_rows(0);
  v11 += result;
LABEL_17:
  HIDWORD(qword_2945B8) = v11;
  return result;
}
