__int64 __fastcall qcom_smem_enumerate_partitions(_QWORD *a1)
{
  _DWORD *v1; // x19
  int v2; // w2
  unsigned int v4; // w9
  int v5; // w22
  _DWORD *v6; // x23
  unsigned int *v7; // x21
  unsigned int v8; // w2
  __int64 *v9; // x26
  __int64 v10; // x0

  v1 = (_DWORD *)a1[4];
  if ( *v1 != 1129272356 )
  {
    LODWORD(v1) = -2;
    return (unsigned int)v1;
  }
  v2 = v1[1];
  if ( v2 != 1 )
  {
    dev_err(*a1, "Unsupported partition header version %d\n", v2);
    LODWORD(v1) = -22;
    return (unsigned int)v1;
  }
  if ( (unsigned __int64)v1 <= 0xFFFFFFFFFFFFF000LL )
  {
    v4 = v1[2];
    if ( !v4 )
    {
LABEL_16:
      LODWORD(v1) = 0;
      return (unsigned int)v1;
    }
    v5 = 0;
    v6 = v1 + 8;
    while ( 1 )
    {
      v7 = &v6[12 * v5];
      if ( *v7 )
      {
        if ( v7[1] )
        {
          v8 = *((unsigned __int16 *)v7 + 7);
          if ( !*((_WORD *)v7 + 6) || (v8 = *((unsigned __int16 *)v7 + 6), !*((_WORD *)v7 + 7)) )
          {
            if ( v8 >= 0x19 )
            {
              dev_err(*a1, "bad host %u\n");
              goto LABEL_22;
            }
            v9 = &a1[4 * v8 + 9];
            if ( *v9 )
            {
              dev_err(*a1, "duplicate host %u\n");
LABEL_22:
              LODWORD(v1) = -22;
              return (unsigned int)v1;
            }
            v10 = qcom_smem_partition_header(
                    a1,
                    &v6[12 * v5],
                    *((unsigned __int16 *)v7 + 6),
                    *((unsigned __int16 *)v7 + 7));
            if ( !v10 )
            {
              LODWORD(v1) = -22;
              return (unsigned int)v1;
            }
            *v9 = v10;
            v9[1] = a1[110] + *v7;
            v9[3] = v7[1];
            v9[2] = v7[4];
            v4 = v1[2];
          }
        }
      }
      if ( ++v5 >= v4 )
        goto LABEL_16;
    }
  }
  return (unsigned int)v1;
}
