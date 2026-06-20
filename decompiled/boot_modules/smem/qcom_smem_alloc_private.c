__int64 __fastcall qcom_smem_alloc_private(_QWORD *a1, unsigned __int64 *a2, int a3, __int64 a4)
{
  unsigned __int64 v4; // x8
  unsigned __int64 v5; // x11
  unsigned __int64 v6; // x10
  bool v7; // cc
  unsigned __int16 *v10; // x9
  unsigned __int64 v11; // x12

  v4 = *a2;
  v5 = *a2 + *(unsigned int *)(*a2 + 12);
  v6 = *a2 + *(unsigned int *)(*a2 + 16);
  v7 = v5 < *a2 || v5 > v6;
  if ( v7 || v6 > *a2 + a2[3] )
  {
LABEL_9:
    __break(0x800u);
    return 4294967274LL;
  }
  else
  {
    v10 = (unsigned __int16 *)(v4 + 32);
    while ( (unsigned __int64)v10 < v5 && (unsigned __int64)(v10 + 8) < v5 )
    {
      if ( *v10 != 42405 )
      {
        dev_err(
          *a1,
          "Found invalid canary in hosts %hu:%hu partition\n",
          *(unsigned __int16 *)(v4 + 4),
          *(unsigned __int16 *)(v4 + 6));
        return 4294967274LL;
      }
      if ( v10[1] == a3 )
        return 4294967279LL;
      v7 = (unsigned __int16 *)((char *)v10 + v10[5] + *((unsigned int *)v10 + 1) + 16) > v10;
      v10 = (unsigned __int16 *)((char *)v10 + v10[5] + *((unsigned int *)v10 + 1) + 16);
      if ( !v7 )
        goto LABEL_9;
    }
    if ( (unsigned __int64)v10 > v5 )
      goto LABEL_9;
    v11 = (a4 + 7) & 0xFFFFFFFFFFFFFFF8LL;
    if ( (unsigned __int64)v10 + v11 + 16 > v6 )
    {
      dev_err(*a1, "Out of memory\n");
      return 4294967268LL;
    }
    else
    {
      v10[1] = a3;
      *v10 = -23131;
      *((_DWORD *)v10 + 1) = v11;
      v10[4] = ((a4 + 7) & 0xFFF8) - a4;
      v10[5] = 0;
      __dsb(0xEu);
      *(_DWORD *)(v4 + 12) += v11 + 16;
      return 0;
    }
  }
}
