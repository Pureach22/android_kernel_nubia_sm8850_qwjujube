__int64 __fastcall msm_msi_irq_compose_msi_msg(__int64 a1, _DWORD *a2)
{
  _DWORD *v2; // x20
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x10
  int v7; // w8

  v2 = *(_DWORD **)(a1 + 48);
  result = irq_get_irq_data(*(unsigned int *)(a1 + 8));
  if ( result )
  {
    v5 = *(_QWORD *)v2;
    v6 = *(_QWORD *)(*(_QWORD *)v2 + 16LL);
    *a2 = *(_QWORD *)(*(_QWORD *)v2 + 40LL);
    a2[1] = *(_DWORD *)(v5 + 44);
    if ( *(_DWORD *)(v6 + 140) )
      v7 = v2[7];
    else
      v7 = *(_DWORD *)(result + 8);
    a2[2] = v7;
  }
  return result;
}
