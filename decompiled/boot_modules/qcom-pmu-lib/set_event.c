__int64 __fastcall set_event(unsigned int *a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w9
  unsigned __int64 v4; // x19
  unsigned int v5; // w9
  __int64 v6; // x8
  unsigned int *v7; // x20
  __int64 v8; // x21
  unsigned int v9; // w22
  int v10; // w0
  int v11; // w8
  int v12; // w21
  unsigned __int64 kernel_counter; // x0
  int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a1[8];
  v15 = 4;
  if ( v3 < 4 )
    goto LABEL_2;
  v5 = a1[9];
  a1[8] = 4;
  if ( v5 >= 9 )
    a1[9] = 9;
  v6 = *a1;
  if ( !(_DWORD)v6 )
  {
    LODWORD(v4) = 0;
    goto LABEL_17;
  }
  *(_QWORD *)(a3 + 8) = v6;
  if ( pmu_long_counter == 1 )
    *(_QWORD *)(a3 + 56) = 1;
  if ( *a1 != 4096 )
  {
    v7 = a1;
    v11 = 4;
LABEL_14:
    *(_DWORD *)a3 = v11;
    v12 = a2;
    kernel_counter = perf_event_create_kernel_counter(a3, a2, 0, 0, 0);
    v4 = kernel_counter;
    if ( kernel_counter >= 0xFFFFFFFFFFFFF001LL )
      goto LABEL_17;
    perf_event_enable(kernel_counter);
    a1 = v7;
    LODWORD(a2) = v12;
    *((_QWORD *)v7 + 1) = v4;
    goto LABEL_2;
  }
  if ( (llcc_ignore_setup & 1) == 0 )
  {
    v7 = a1;
    v8 = a3;
    v9 = a2;
    v10 = qcom_llcc_pmu_hw_type(&v15);
    if ( v10 < 0 )
    {
      LODWORD(v4) = v10;
      goto LABEL_17;
    }
    v11 = v15;
    a2 = v9;
    a3 = v8;
    goto LABEL_14;
  }
LABEL_2:
  LODWORD(v4) = 0;
  a1[4] = a2;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v4;
}
