__int64 __fastcall sde_dbg_dump_reg_rows(int a1, __int64 a2, int a3, __int64 a4, int a5)
{
  unsigned __int64 v5; // x23
  __int64 result; // x0
  int v10; // w24
  _DWORD *v11; // x25
  unsigned __int64 v12; // x26
  void *v13; // x0

  if ( a3 / 4 >= 512 )
    v5 = 512;
  else
    v5 = (unsigned int)(a3 / 4);
  if ( !a2 || !a4 )
  {
    v13 = &unk_2660DD;
LABEL_15:
    printk(v13, "_sde_dbg_dump_reg_rows");
    return 0;
  }
  if ( (unsigned int)a5 < 0x1000 )
  {
    v13 = &unk_23C61F;
    goto LABEL_15;
  }
  result = 0;
  if ( a3 >= 4 && a5 >= 256 )
  {
    v10 = 0;
    v11 = (_DWORD *)(a2 + 8);
    v12 = 1;
    do
    {
      v10 += snprintf(
               (char *)(a4 + v10),
               0x100u,
               "0x%.8X | %.8X %.8X %.8X %.8X\n",
               a1,
               *(v11 - 2),
               *(v11 - 1),
               *v11,
               v11[1]);
      if ( v12 >= v5 )
        break;
      v11 += 4;
      a1 += 16;
      ++v12;
    }
    while ( v10 + 256 <= a5 );
    return v10;
  }
  return result;
}
