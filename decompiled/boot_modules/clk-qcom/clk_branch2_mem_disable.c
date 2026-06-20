__int64 __fastcall clk_branch2_mem_disable(__int64 a1)
{
  int v2; // w8
  __int64 v3; // x2
  __int64 v4; // x1
  __int64 v5; // x3
  __int64 updated; // x0
  __int64 v7; // x0
  __int64 v8; // x20
  __int64 v9; // x21
  __int64 v10; // x0
  int v11; // w19
  const char *name; // x0
  __int64 result; // x0
  __int64 v14; // x21
  int v15; // w8
  int v16; // w9
  int v17; // [xsp+4h] [xbp-ACh] BYREF
  _QWORD dest[21]; // [xsp+8h] [xbp-A8h] BYREF

  dest[20] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memcpy(dest, (const void *)(a1 - 16), 0xA0u);
  v2 = *(unsigned __int8 *)(a1 - 24);
  v3 = *(unsigned int *)(a1 - 32);
  v4 = *(unsigned int *)(a1 - 40);
  v17 = 0;
  if ( v2 )
    v5 = (unsigned int)v3;
  else
    v5 = 0;
  updated = regmap_update_bits_base(dest[5], v4, v3, v5, 0, 0, 0);
  v7 = ktime_get(updated);
  v8 = dest[5];
  v9 = v7;
  v10 = regmap_read(dest[5], *(unsigned int *)(a1 - 36), &v17);
  if ( !(_DWORD)v10 )
  {
    v14 = v9 + 200000;
    while ( 1 )
    {
      v15 = v17;
      v16 = *(_DWORD *)(a1 - 28);
      if ( (v16 & v17) == 0 )
        break;
      if ( ktime_get(v10) > v14 )
      {
        LODWORD(v10) = regmap_read(v8, *(unsigned int *)(a1 - 36), &v17);
        if ( (_DWORD)v10 )
          goto LABEL_5;
        v15 = v17;
        v16 = *(_DWORD *)(a1 - 28);
        break;
      }
      __yield();
      v10 = regmap_read(v8, *(unsigned int *)(a1 - 36), &v17);
      if ( (_DWORD)v10 )
        goto LABEL_5;
    }
    if ( (v16 & v15) == 0 )
    {
      result = clk_branch_toggle(a1, 0, clk_branch2_check_halt);
      goto LABEL_6;
    }
    LODWORD(v10) = -110;
  }
LABEL_5:
  v11 = v10;
  name = (const char *)clk_hw_get_name(&dest[2]);
  result = _warn_printk("%s mem disable failed ret=%d regval=0x%x\n", name, v11, v17);
  __break(0x800u);
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
