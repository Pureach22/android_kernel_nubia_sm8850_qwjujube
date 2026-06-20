__int64 __fastcall cam_csiphy_cphy_irq_disable(__int64 result)
{
  int v1; // w20
  __int64 v2; // x21
  __int64 v3; // x19
  int i; // w22

  v1 = *(_DWORD *)(**(_QWORD **)(result + 112) + 28LL);
  if ( v1 )
  {
    v2 = *(_QWORD *)(result + 1200);
    v3 = result;
    for ( i = 0; i != v1; ++i )
      result = cam_io_w_mb(0, v2 + *(int *)(*(_QWORD *)(*(_QWORD *)(v3 + 112) + 16LL) + 16LL * i));
  }
  return result;
}
