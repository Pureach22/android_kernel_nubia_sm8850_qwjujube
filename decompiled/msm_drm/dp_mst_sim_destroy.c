__int64 __fastcall dp_mst_sim_destroy(__int64 a1)
{
  unsigned __int64 v2; // x20
  __int64 v3; // x21

  if ( !a1 )
    return 4294967274LL;
  if ( *(_DWORD *)(a1 + 32) )
  {
    v2 = 0;
    v3 = 32;
    do
    {
      kfree(*(_QWORD *)(*(_QWORD *)(a1 + 24) + v3));
      ++v2;
      v3 += 48;
    }
    while ( v2 < *(unsigned int *)(a1 + 32) );
  }
  kfree(*(_QWORD *)(a1 + 24));
  destroy_workqueue(*(_QWORD *)(a1 + 768));
  return 0;
}
