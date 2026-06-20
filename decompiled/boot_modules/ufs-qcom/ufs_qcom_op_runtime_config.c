__int64 __fastcall ufs_qcom_op_runtime_config(_QWORD *a1)
{
  __int64 v1; // x9
  __int64 *v3; // x10
  __int64 *v4; // x11
  __int64 v6; // x13
  __int64 v7; // x14
  __int64 v8; // x13
  __int64 v9; // x14
  __int64 v10; // x13
  __int64 v11; // x14
  __int64 v12; // x10
  __int64 v13; // x11

  if ( !a1[614] )
    return 4294967274LL;
  v1 = a1[620];
  if ( !v1 )
    return 4294967274LL;
  v3 = (__int64 *)a1[619];
  v4 = (__int64 *)a1[613];
  v6 = *v3;
  v7 = *v4;
  a1[637] = 256;
  a1[638] = v1;
  a1[636] = v6 - v7;
  v8 = *v3;
  v9 = *v4;
  a1[640] = 256;
  a1[641] = v1 + 64;
  a1[639] = v8 - v9 + 64;
  v10 = *v3;
  v11 = *v4;
  a1[644] = v1 + 128;
  a1[643] = 256;
  a1[642] = v10 - v11 + 128;
  v12 = *v3;
  v13 = *v4;
  a1[646] = 256;
  a1[647] = v1 + 192;
  a1[645] = v12 - v13 + 192;
  return 0;
}
