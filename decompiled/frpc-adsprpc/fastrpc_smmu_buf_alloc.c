__int64 __fastcall fastrpc_smmu_buf_alloc(__int64 a1, unsigned __int64 a2, unsigned int a3, __int64 a4)
{
  __int64 v4; // x25
  unsigned __int64 i; // x23
  unsigned __int64 v10; // x8
  _QWORD *v11; // x9
  __int64 result; // x0

  v4 = *(_QWORD *)(a1 + 136);
  for ( i = 0; ; ++i )
  {
    v10 = *(unsigned int *)(v4 + 1016);
    if ( v10 > i )
      break;
LABEL_11:
    if ( i >= v10 )
    {
LABEL_16:
      dev_err(
        *(_QWORD *)(*(_QWORD *)(a1 + 128) + 168LL),
        "%s: No valid smmu context bank found for size 0x%llx\n",
        "fastrpc_smmu_buf_alloc",
        a2);
      return 4294967233LL;
    }
    if ( i >= 8 )
      goto LABEL_18;
    result = fastrpc_buf_alloc(a1, v4 + 144 * i, a2, a3, a4);
    if ( (_DWORD)result != -12 && (_DWORD)result != -22 )
      return result;
  }
  v11 = (_QWORD *)(v4 + 120 + 144 * i);
  while ( i != 8 )
  {
    if ( !*v11 || *(v11 - 1) <= a2 && *(v11 - 2) - *(v11 - 3) > a2 )
    {
      i = (unsigned int)i;
      goto LABEL_11;
    }
    ++i;
    v11 += 18;
    if ( v10 == i )
      goto LABEL_16;
  }
LABEL_18:
  __break(0x5512u);
  return ((__int64 (*)(void))fastrpc_buf_alloc)();
}
