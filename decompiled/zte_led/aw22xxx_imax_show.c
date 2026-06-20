__int64 __fastcall aw22xxx_imax_show(__int64 a1, int a2, char *s)
{
  __int64 v3; // x22
  __int64 v5; // x24
  __int64 v6; // x24
  __int64 v7; // x24
  __int64 v8; // x24
  __int64 v9; // x24
  __int64 v10; // x24
  __int64 v11; // x24
  __int64 v12; // x24
  __int64 v13; // x24
  __int64 v14; // x24
  __int64 v15; // x24
  __int64 v16; // x24
  __int64 v17; // x0
  __int64 v18; // x3
  int v20; // w0
  int v21; // w1
  char *v22; // x2

  v3 = *(_QWORD *)(a1 + 152);
  v5 = snprintf(s, 0x1000u, "imax[%x] = %s\n", 0, aw22xxx_imax_name);
  v6 = v5 + snprintf(&s[v5], 4096 - v5, "imax[%x] = %s\n", 1, aAw22xxxImax3ma);
  v7 = v6 + snprintf(&s[v6], 4096 - v6, "imax[%x] = %s\n", 2, aAw22xxxImax4ma);
  v8 = v7 + snprintf(&s[v7], 4096 - v7, "imax[%x] = %s\n", 3, aAw22xxxImax6ma);
  v9 = v8 + snprintf(&s[v8], 4096 - v8, "imax[%x] = %s\n", 4, aAw22xxxImax9ma);
  v10 = v9 + snprintf(&s[v9], 4096 - v9, "imax[%x] = %s\n", 5, aAw22xxxImax10m);
  v11 = v10 + snprintf(&s[v10], 4096 - v10, "imax[%x] = %s\n", 6, aAw22xxxImax15m);
  v12 = v11 + snprintf(&s[v11], 4096 - v11, "imax[%x] = %s\n", 7, aAw22xxxImax20m);
  v13 = v12 + snprintf(&s[v12], 4096 - v12, "imax[%x] = %s\n", 8, aAw22xxxImax30m);
  v14 = v13 + snprintf(&s[v13], 4096 - v13, "imax[%x] = %s\n", 9, aAw22xxxImax40m);
  v15 = v14 + snprintf(&s[v14], 4096 - v14, "imax[%x] = %s\n", 10, aAw22xxxImax45m);
  v16 = v15 + snprintf(&s[v15], 4096 - v15, "imax[%x] = %s\n", 11, aAw22xxxImax60m);
  v17 = snprintf(&s[v16], 4096 - v16, "imax[%x] = %s\n", 12, aAw22xxxImax75m);
  v18 = *(unsigned int *)(v3 + 736);
  if ( (unsigned int)v18 < 0xE )
    return v16
         + (int)v17
         + snprintf(
             &s[v16 + (int)v17],
             4096 - (v16 + (int)v17),
             "current id = 0x%02x, imax = %s\n",
             v18,
             &aw22xxx_imax_name[32 * v18]);
  __break(0x5512u);
  v20 = MEMORY[0x71109A0](v17);
  return aw22xxx_imax_store(v20, v21, v22);
}
