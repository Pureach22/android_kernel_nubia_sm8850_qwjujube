unsigned __int64 __fastcall mmrm_sw_get_max_crm_rate(__int64 a1, _DWORD *a2, unsigned __int64 a3, int *a4)
{
  int v4; // w6
  unsigned __int64 v5; // x19
  int v6; // w4
  int v7; // w8
  unsigned int v8; // w8
  unsigned int i; // w9
  unsigned __int64 v10; // x10

  v4 = *(_DWORD *)(a1 + 700);
  v5 = *(_QWORD *)(a1 + 664);
  *a4 = v4;
  if ( a2[2] )
    v6 = a2[4] + a2[3] * *(_DWORD *)(a1 + 696);
  else
    v6 = *(_DWORD *)(a1 + 704) - 1;
  v7 = v6;
  if ( v5 < a3 )
    goto LABEL_14;
  if ( v6 == v4 )
  {
    v8 = *(_DWORD *)(a1 + 704);
    if ( !v8 )
      goto LABEL_13;
    v5 = 0;
    for ( i = 0; i < v8; ++i )
    {
      if ( i != *(_DWORD *)(a1 + 700) )
      {
        v10 = *(_QWORD *)(*(_QWORD *)(a1 + 712) + 8LL * (int)i);
        if ( v10 > v5 )
        {
          *a4 = i;
          v5 = v10;
          v8 = *(_DWORD *)(a1 + 704);
        }
      }
    }
    if ( v5 <= a3 )
    {
LABEL_13:
      v7 = *(_DWORD *)(a1 + 700);
LABEL_14:
      v5 = a3;
      *a4 = v7;
    }
  }
  if ( (~msm_mmrm_debug & 0x10002) == 0 )
    printk(&unk_DC37, "high", "mmrm_sw_get_max_crm_rate");
  return v5;
}
