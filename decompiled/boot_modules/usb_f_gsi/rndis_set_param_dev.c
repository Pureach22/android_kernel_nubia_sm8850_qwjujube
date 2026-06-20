__int64 __fastcall rndis_set_param_dev(__int64 a1, __int64 a2, __int64 a3)
{
  if ( !a2 )
    return 4294967274LL;
  if ( !a1 )
    return 0xFFFFFFFFLL;
  *(_QWORD *)(a1 + 32) = a3;
  *(_QWORD *)(a1 + 40) = a2;
  return 0;
}
