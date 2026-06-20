__int64 __fastcall coresight_make_links(__int64 a1, int *a2, __int64 a3)
{
  int v3; // w3
  __int64 result; // x0
  __int64 v8; // x0
  __int64 v9; // x22
  __int64 v10; // x0
  __int64 v11; // x24
  __int64 *v12; // x0
  __int64 *v13; // x23

  v3 = *a2;
  if ( a2[1] == -1 && v3 == -1 )
    return 0;
  v8 = devm_kasprintf(a1 + 56, 3264, "out:%d", v3);
  if ( !v8 )
    return 4294967284LL;
  v9 = v8;
  v10 = devm_kasprintf(a3 + 56, 3264, "in:%d", a2[1]);
  if ( !v10 )
    return 4294967284LL;
  v11 = v10;
  v12 = (__int64 *)devm_kmalloc(a1 + 56, 32, 3520);
  if ( !v12 )
    return 4294967284LL;
  v13 = v12;
  *v12 = a1;
  v12[1] = v9;
  v12[2] = a3;
  v12[3] = v11;
  result = coresight_add_sysfs_link(v12);
  if ( !(_DWORD)result )
    *((_QWORD *)a2 + 3) = v13;
  return result;
}
