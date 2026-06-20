__int64 __fastcall fastrpc_device_register(__int64 a1, __int64 a2, char a3, char a4, const char *a5)
{
  __int64 v10; // x0
  __int64 v11; // x22
  __int64 v12; // x24
  const char *v13; // x4
  __int64 v14; // x0
  __int64 result; // x0
  __int64 v16; // x8
  __int64 v17; // x0

  v10 = devm_kmalloc(a1, 96, 3520);
  if ( !v10 )
    return 4294967284LL;
  v11 = v10;
  *(_BYTE *)(v10 + 88) = a3 & 1;
  *(_DWORD *)(v10 + 8) = 255;
  v12 = v10 + 8;
  *(_QWORD *)v10 = a2;
  *(_QWORD *)(a2 + 168) = a1;
  *(_QWORD *)(v10 + 24) = &fastrpc_fops;
  if ( (a4 & 1) == 0 )
  {
    v17 = devm_kasprintf(a1, 3264, "fastrpc-%s", a5);
    *(_QWORD *)(v11 + 16) = v17;
    if ( v17 )
      goto LABEL_7;
    return 4294967284LL;
  }
  if ( (a3 & 1) != 0 )
    v13 = "-secure";
  else
    v13 = (const char *)&unk_23C68;
  v14 = devm_kasprintf(a1, 3264, "fastrpc-%s%s", a5, v13);
  *(_QWORD *)(v11 + 16) = v14;
  if ( !v14 )
    return 4294967284LL;
LABEL_7:
  result = misc_register(v12);
  if ( !(_DWORD)result )
  {
    v16 = 52712;
    if ( (a3 & 1) != 0 )
      v16 = 52720;
    if ( (a4 & 1) == 0 )
      v16 = 52704;
    *(_QWORD *)(a2 + v16) = v11;
  }
  return result;
}
