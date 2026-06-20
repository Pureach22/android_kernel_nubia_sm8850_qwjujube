unsigned __int64 __fastcall qcom_smem_set_global_partition(_QWORD *a1)
{
  unsigned __int64 result; // x0
  int v3; // w2
  int v4; // w9
  int v5; // w10
  unsigned int *v6; // x19
  _QWORD *v7; // x20
  __int64 v8; // x0

  if ( a1[5] )
  {
    dev_err(*a1, "Already found the global partition\n");
    return 4294967274LL;
  }
  result = a1[4];
  if ( *(_DWORD *)result != 1129272356 )
    return -2;
  v3 = *(_DWORD *)(result + 4);
  if ( v3 != 1 )
  {
    dev_err(*a1, "Unsupported partition header version %d\n", v3);
    return -22;
  }
  if ( result <= 0xFFFFFFFFFFFFF000LL )
  {
    v4 = *(_DWORD *)(result + 8);
    if ( v4 )
    {
      v5 = 0;
      while ( 1 )
      {
        v6 = (unsigned int *)(result + 32 + 48LL * v5);
        if ( *v6 )
        {
          if ( v6[1] && *((__int16 *)v6 + 6) == -2 && *((__int16 *)v6 + 7) == -2 )
            break;
        }
        if ( v4 == ++v5 )
          goto LABEL_16;
      }
      v7 = a1;
      v8 = qcom_smem_partition_header(a1, result + 32 + 48LL * v5, 65534, 65534);
      if ( v8 )
      {
        v7[5] = v8;
        v7[6] = v7[110] + *v6;
        v7[8] = v6[1];
        v7[7] = v6[4];
        return 0;
      }
    }
    else
    {
LABEL_16:
      dev_err(*a1, "Missing entry for global partition\n");
    }
    return 4294967274LL;
  }
  return result;
}
