const char *__fastcall sde_dump_reg(
        const char *result,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        _QWORD *a6)
{
  unsigned __int64 v7; // x27
  __int64 v8; // x9
  __int64 v9; // x21
  _DWORD *v10; // x20
  unsigned int v11; // w22
  __int64 v12; // x23
  __int64 v13; // x24
  __int64 v14; // x21
  _BOOL4 v15; // w10
  unsigned __int64 v16; // x22
  int v17; // w28
  __int64 v18; // x24
  int v19; // w23
  int v20; // w24
  __int64 v21; // x26
  unsigned __int64 v22; // x0
  int v23; // w25
  int v24; // w26
  const char *v25; // x22
  unsigned int v26; // w23
  __int64 v27; // x24
  __int64 v28; // x25
  int v29; // [xsp+0h] [xbp-80h]
  __int64 v30; // [xsp+8h] [xbp-78h]
  int v31; // [xsp+14h] [xbp-6Ch]
  _BOOL4 v32; // [xsp+18h] [xbp-68h]
  int v33; // [xsp+1Ch] [xbp-64h]

  if ( !a5 || !a6 || (a2 & 0xF) == 0 )
    return result;
  v7 = (unsigned __int64)(a5 + 15) >> 4;
  v8 = qword_2942C0;
  v9 = (unsigned int)(16 * v7);
  *a6 = qword_2942C0;
  qword_2942C0 = v8 + v9;
  v10 = (_DWORD *)*a6;
  v33 = a2 & 5;
  if ( (a2 & 5) != 0 )
  {
    v25 = result;
    v26 = a2;
    v27 = a3;
    v28 = a5;
    dev_err(qword_2942C8, "%s: start_addr:0x%pK len:0x%zx offset=0x%x\n", result, v10, (unsigned int)(16 * v7), a4 - a3);
    result = v25;
    a5 = v28;
    a3 = v27;
    a2 = v26;
    if ( (v26 & 8) == 0 )
      goto LABEL_8;
  }
  else if ( (a2 & 8) == 0 )
  {
    goto LABEL_8;
  }
  if ( HIBYTE(word_294380) == 1 )
  {
    v11 = a2;
    v12 = a3;
    v13 = a5;
    result = (const char *)drm_printf(
                             qword_2945A8,
                             "%s: start_addr:0x%pK len:0x%x reg_offset=0x%lx\n",
                             result,
                             v10,
                             v9,
                             a4 - a3);
    a5 = v13;
    a3 = v12;
    a2 = v11;
  }
LABEL_8:
  if ( (_DWORD)v7 )
  {
    v14 = 0;
    v29 = a4 - a3;
    v30 = a4 - a3;
    if ( v10 )
      v15 = (a2 & 0xA) != 0;
    else
      v15 = 0;
    v16 = a4 + a5;
    v17 = 3;
    v31 = (v10 != nullptr) & (a2 >> 3);
    v32 = v15;
    while ( 1 )
    {
      v18 = a4 + v14;
      v19 = a4 + v14 >= v16 ? 0 : readl_relaxed_6(a4 + v14);
      v20 = v18 + 4 >= v16 ? 0 : readl_relaxed_6(v18 + 4);
      v21 = a4 + v14;
      v22 = a4 + v14 + 8;
      v23 = v22 >= v16 ? 0 : readl_relaxed_6(v22);
      result = (const char *)(v21 + 12);
      if ( v21 + 12 < v16 )
        break;
      v24 = 0;
      if ( v33 )
        goto LABEL_25;
LABEL_27:
      if ( v32 && (word_294380 & 0x100) == 0 )
      {
        v10[v17] = v24;
        v10[v17 - 3] = v19;
        v10[v17 - 2] = v20;
        v10[v17 - 1] = v23;
      }
      if ( v31 )
      {
        if ( HIBYTE(word_294380) == 1 )
          result = (const char *)drm_printf(
                                   qword_2945A8,
                                   "0x%08lx| %08x %08x %08x %08x\n",
                                   v30 + v14,
                                   v10[v17 - 3],
                                   v10[v17 - 2],
                                   v10[v17 - 1],
                                   v10[v17]);
      }
      LODWORD(v7) = v7 - 1;
      v14 += 16;
      v17 += 4;
      if ( !(_DWORD)v7 )
        return result;
    }
    result = (const char *)readl_relaxed_6(result);
    v24 = (int)result;
    if ( !v33 )
      goto LABEL_27;
LABEL_25:
    result = (const char *)dev_err(qword_2942C8, "0x%08x| %08x %08x %08x %08x\n", v29 + (int)v14, v19, v20, v23, v24);
    goto LABEL_27;
  }
  return result;
}
