__int64 __fastcall ufs_qcom_phy_write_tbl(__int64 result, __int64 a2, int a3)
{
  __int64 v3; // x19
  __int64 v4; // x20
  unsigned int *v5; // x21

  if ( a3 >= 1 )
  {
    v3 = result;
    v4 = (unsigned int)a3;
    v5 = (unsigned int *)(a2 + 4);
    do
    {
      result = writel_relaxed(*v5, *(_QWORD *)(v3 + 24) + *(v5 - 1));
      --v4;
      v5 += 2;
    }
    while ( v4 );
  }
  return result;
}
