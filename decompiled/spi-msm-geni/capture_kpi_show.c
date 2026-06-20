__int64 __fastcall capture_kpi_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8

  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 152LL);
  if ( v3 )
    return (int)scnprintf(a3, 4, "%d\n", *(_DWORD *)(v3 + 496));
  else
    return -22;
}
