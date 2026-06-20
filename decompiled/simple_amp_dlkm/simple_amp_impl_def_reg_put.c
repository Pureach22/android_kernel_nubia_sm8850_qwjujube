__int64 __fastcall simple_amp_impl_def_reg_put(__int64 a1, __int64 a2)
{
  __int64 v5; // x8
  __int64 v6; // x23
  char *v7; // x0
  char *v8; // x19
  char *v9; // x0
  char *v10; // x22
  unsigned __int64 v11; // x24
  __int64 v12; // x3
  char *v13; // x0
  __int64 v14; // x3
  __int64 result; // x0
  char *v16; // x0
  char *v17; // x0
  unsigned __int64 v18; // x21
  char *v19; // x0
  _DWORD *v20; // x9
  unsigned int v21; // w20
  __int64 v27; // [xsp+8h] [xbp-18h] BYREF
  char *stringp[2]; // [xsp+10h] [xbp-10h] BYREF

  stringp[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 128);
  v27 = 0;
  v6 = *(_QWORD *)(*(_QWORD *)(v5 + 24) + 152LL);
  v7 = (char *)kstrdup(a2 + 72, 3264);
  stringp[0] = v7;
  if ( !v7 )
    goto LABEL_20;
  v8 = v7;
  v9 = strsep(stringp, " ");
  if ( v9 )
  {
    v10 = v9;
    v11 = 0;
    do
    {
      if ( (unsigned int)kstrtouint(v10, 0, (char *)&v27 + 4) )
      {
        printk(&unk_C67E, "parse_and_store_registers", v10, v12);
        v21 = -22;
LABEL_22:
        kfree(v8);
        result = v21;
LABEL_23:
        _ReadStatusReg(SP_EL0);
        return result;
      }
      v13 = strsep(stringp, " ");
      if ( !v13 || (unsigned int)kstrtouint(v13, 0, &v27) )
      {
        printk(&unk_CC36, "parse_and_store_registers", HIDWORD(v27), v14);
        v21 = -22;
        goto LABEL_22;
      }
      ++v11;
      v10 = strsep(stringp, " ");
    }
    while ( v10 );
    kfree(v8);
    if ( v11 > 0xF )
    {
      result = 4294967274LL;
      goto LABEL_23;
    }
  }
  else
  {
    kfree(v8);
    v11 = 0;
  }
  *(_QWORD *)(v6 + 360) = v11;
  v16 = (char *)kstrdup(a2 + 72, 3264);
  stringp[0] = v16;
  if ( !v16 )
  {
LABEL_20:
    result = 4294967284LL;
    goto LABEL_23;
  }
  v8 = v16;
  v17 = strsep(stringp, " ");
  if ( !v17 )
  {
LABEL_21:
    v21 = 0;
    goto LABEL_22;
  }
  v18 = 0;
  while ( 1 )
  {
    if ( (unsigned int)kstrtouint(v17, 0, (char *)&v27 + 4) )
      goto LABEL_14;
    v19 = strsep(stringp, " ");
    if ( !v19 || (unsigned int)kstrtouint(v19, 0, &v27) )
      goto LABEL_14;
    if ( v18 >= 0x10 )
      break;
    v20 = (_DWORD *)(v6 + 232 + 8 * v18++);
    *v20 = HIDWORD(v27);
    v20[1] = v27;
LABEL_14:
    v17 = strsep(stringp, " ");
    if ( !v17 )
      goto LABEL_21;
  }
  __break(0x5512u);
  __asm { SM3TT2A         V13.4S, V13.4S, V11.S[1] }
  return simple_amp_trigger_die_temp_get();
}
