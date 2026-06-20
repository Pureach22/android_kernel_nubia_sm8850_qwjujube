__int64 __fastcall aspm_stat_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x23
  int v5; // w21
  unsigned int v6; // w20
  int v7; // w21
  int v8; // w22
  int v9; // w0
  __int64 v10; // x8
  int v11; // w23
  int v12; // w0
  __int64 result; // x0

  v3 = *(_QWORD *)(a1 + 152);
  if ( *(_QWORD *)(v3 + 912) )
  {
    mutex_lock(v3 + 1480);
    v5 = *(_DWORD *)(v3 + 1176);
    mutex_unlock(v3 + 1480);
    v6 = *(_DWORD *)(v3 + 1348);
    if ( v5 == 1 )
    {
      v7 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v3 + 912) + 3088LL));
      v8 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v3 + 912) + 3084LL));
      v9 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v3 + 912) + 3204LL));
      v10 = *(_QWORD *)(v3 + 912);
      v11 = v9;
      v12 = readl_relaxed_0((unsigned int *)(v10 + 3208));
      LODWORD(result) = scnprintf(a3, 4096, "PCIe: RC%d: L0s: %u L1: %u L1.1: %u L1.2: %u\n", v6, v7, v8, v11, v12);
    }
    else
    {
      LODWORD(result) = scnprintf(a3, 4096, "PCIe: RC%d: registers are not accessible\n", v6);
    }
  }
  else
  {
    LODWORD(result) = scnprintf(a3, 4096, "PCIe: RC%d: No dev or MHI space found\n", *(unsigned int *)(v3 + 1348));
  }
  return (int)result;
}
