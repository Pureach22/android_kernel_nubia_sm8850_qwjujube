__int64 __fastcall zcomp_available_show(const char *a1, __int64 a2)
{
  int v4; // w21
  const char *v5; // x2
  __int64 v6; // x24
  int v7; // w22
  const char *v8; // x2
  __int64 v9; // x28
  int v10; // w23
  const char *v11; // x2
  __int64 v12; // x24
  int v13; // w0
  __int64 v14; // x1
  __int64 v15; // x3
  __int64 v16; // x0
  const char *v17; // x3

  v4 = strcmp(a1, "lzo");
  if ( v4 )
    v5 = (const char *)&unk_B394;
  else
    v5 = "[%s] ";
  v6 = (int)scnprintf(a2, 4094, v5, "lzo");
  v7 = strcmp(a1, "lzo-rle");
  if ( v7 )
    v8 = (const char *)&unk_B394;
  else
    v8 = "[%s] ";
  v9 = v6 + (int)scnprintf(a2 + v6, 4094 - v6, v8, "lzo-rle");
  v10 = strcmp(a1, "lz4");
  if ( v10 )
    v11 = (const char *)&unk_B394;
  else
    v11 = "[%s] ";
  v12 = v9 + (int)scnprintf(a2 + v9, 4094 - v9, v11, "lz4");
  v13 = strcmp(a1, "zstd");
  v14 = 4094 - v12;
  if ( !v13 )
  {
    v17 = "zstd";
    v16 = a2 + v12;
    goto LABEL_17;
  }
  v12 += (int)scnprintf(a2 + v12, v14, &unk_B394, "zstd");
  if ( v10 && v7 && v4 && (unsigned int)crypto_has_alg(a1, 2, 15) == 1 )
  {
    v14 = 4094 - v12;
    v16 = a2 + v12;
    v17 = a1;
LABEL_17:
    v12 += (int)scnprintf(v16, v14, "[%s] ", v17);
  }
  return v12 + (int)scnprintf(a2 + v12, 4096 - v12, "\n", v15);
}
