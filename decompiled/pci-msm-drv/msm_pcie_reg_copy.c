__int64 __fastcall msm_pcie_reg_copy(__int64 a1, char *a2, unsigned int a3, unsigned __int8 a4, int a5)
{
  int v9; // w25
  __int64 v11; // x8
  __int64 v12; // x9
  unsigned int *v13; // x27
  int v14; // w28
  int v15; // w9
  __int64 v16; // x25
  __int64 v17; // x23
  __int64 result; // x0
  unsigned int v19; // [xsp+0h] [xbp-10h]
  int src; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v9 = a4;
  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  ipc_log_string(
    *(_QWORD *)(a1 + 1712),
    "DUMP:%s: RC%d buf=%p size=%u, reg_len=%u\n",
    "msm_pcie_reg_copy",
    *(_DWORD *)(a1 + 1348),
    a2,
    a3,
    a4);
  if ( a5 )
  {
    if ( a5 == 1 )
    {
      v11 = 904;
      v12 = 3104;
      v13 = *(unsigned int **)(a1 + 3112);
      if ( !v13 )
        goto LABEL_14;
    }
    else
    {
      v11 = 880;
      v12 = 3072;
      v13 = *(unsigned int **)(a1 + 3080);
      if ( !v13 )
      {
LABEL_14:
        result = 0;
        goto LABEL_16;
      }
    }
  }
  else
  {
    v11 = 872;
    v12 = 3088;
    v13 = *(unsigned int **)(a1 + 3096);
    if ( !v13 )
      goto LABEL_14;
  }
  v14 = *(_DWORD *)(a1 + v12);
  if ( !v14 )
    goto LABEL_14;
  v15 = v14 * v9;
  v16 = *(_QWORD *)(a1 + v11);
  v17 = 0;
  v19 = v15;
  while ( a4 + (unsigned int)v17 <= a3 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 1712), "DUMP:%s: RC%d *seq:%u\n", "msm_pcie_reg_copy", *(_DWORD *)(a1 + 1348), *v13);
    src = readl_relaxed_0(v16 + *v13);
    if ( a4 >= 5u )
      _fortify_panic(16, -1, a4);
    memcpy(&a2[v17], &src, a4);
    --v14;
    ++v13;
    v17 += a4;
    if ( !v14 )
    {
      result = v19;
      goto LABEL_16;
    }
  }
  result = (unsigned int)v17;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
