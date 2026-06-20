__int64 __fastcall cam_csiphy_cphy_irq_config(__int64 result)
{
  int v1; // w20
  __int64 v2; // x21
  __int64 v3; // x19
  int i; // w22
  int *v5; // x23

  v1 = *(_DWORD *)(**(_QWORD **)(result + 112) + 28LL);
  if ( v1 )
  {
    v2 = *(_QWORD *)(result + 1200);
    v3 = result;
    for ( i = 0; i != v1; ++i )
    {
      v5 = (int *)(*(_QWORD *)(*(_QWORD *)(v3 + 112) + 16LL) + 16LL * i);
      cam_io_w_mb((unsigned int)v5[1], v2 + *v5);
      result = v5[2];
      if ( (_DWORD)result )
        result = usleep_range_state(result, (int)result + 5, 2);
    }
  }
  return result;
}
