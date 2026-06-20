__int64 __fastcall msm_dss_mmrm_deregister(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  _QWORD *v3; // x20
  __int64 result; // x0

  v2 = *(unsigned int *)(a2 + 32);
  if ( (int)v2 >= 1 )
  {
    v3 = (_QWORD *)(*(_QWORD *)(a2 + 40) + 80LL);
    do
    {
      if ( *((_DWORD *)v3 - 10) == 2 )
        result = kfree(*v3);
      --v2;
      v3 += 15;
    }
    while ( v2 );
  }
  return result;
}
