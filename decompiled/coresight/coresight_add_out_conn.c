__int64 __fastcall coresight_add_out_conn(__int64 a1, __int64 a2, _QWORD *a3)
{
  int v3; // w8
  int **v7; // x9
  __int64 v8; // x10
  int v9; // w2
  __int64 result; // x0
  int v11; // w8
  __int64 v12; // x0
  __int64 v13; // x9
  __int64 v14; // x11
  __int64 v15; // x10
  __int64 v16; // x8
  __int64 v17; // x8

  v3 = *(_DWORD *)(a2 + 4);
  if ( v3 < 1 )
  {
LABEL_7:
    v11 = v3 + 1;
    *(_DWORD *)(a2 + 4) = v11;
    if ( v11 < 0 )
    {
      *(_QWORD *)(a2 + 8) = 0;
    }
    else
    {
      v12 = devm_krealloc(a1, *(_QWORD *)(a2 + 8), 8LL * (unsigned int)v11, 3264);
      *(_QWORD *)(a2 + 8) = v12;
      if ( v12 )
      {
        result = devm_kmalloc(a1, 64, 3264);
        if ( result )
        {
          v13 = a3[5];
          v14 = *(_QWORD *)(a2 + 8);
          *(_QWORD *)(result + 32) = a3[4];
          *(_QWORD *)(result + 40) = v13;
          v15 = a3[7];
          *(_QWORD *)(result + 48) = a3[6];
          *(_QWORD *)(result + 56) = v15;
          v16 = a3[1];
          *(_QWORD *)result = *a3;
          *(_QWORD *)(result + 8) = v16;
          v17 = a3[3];
          LODWORD(v13) = *(_DWORD *)(a2 + 4) - 1;
          *(_QWORD *)(result + 16) = a3[2];
          *(_QWORD *)(result + 24) = v17;
          *(_QWORD *)(v14 + 8LL * (int)v13) = result;
          return result;
        }
      }
    }
    return -12;
  }
  else
  {
    v7 = *(int ***)(a2 + 8);
    v8 = *(unsigned int *)(a2 + 4);
    while ( 1 )
    {
      v9 = **v7;
      if ( v9 != -1 && v9 == *(_DWORD *)a3 )
        break;
      --v8;
      ++v7;
      if ( !v8 )
        goto LABEL_7;
    }
    dev_warn(a1, "Duplicate output port %d\n", v9);
    return -22;
  }
}
