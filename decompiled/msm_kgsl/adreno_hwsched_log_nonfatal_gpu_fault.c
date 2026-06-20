__int64 __fastcall adreno_hwsched_log_nonfatal_gpu_fault(__int64 a1, __int64 a2, int a3)
{
  __int64 result; // x0
  _DWORD *v6; // x9
  unsigned int v7; // w8
  unsigned int v8; // w10
  _DWORD *v9; // x9
  _WORD *v10; // x11
  _WORD *v11; // x12
  __int64 v12; // x20
  unsigned __int64 v13; // x21
  _DWORD *v14; // x9
  unsigned int v15; // w8
  unsigned int v16; // w10
  _DWORD *v17; // x9
  _WORD *v18; // x11
  _WORD *v19; // x12
  int v20; // w21
  int v21; // w20

  result = 0;
  if ( a3 > 652 )
  {
    switch ( a3 )
    {
      case 653:
        if ( (unsigned int)__ratelimit(
                             &adreno_hwsched_log_nonfatal_gpu_fault__rs_28,
                             "adreno_hwsched_log_nonfatal_gpu_fault") )
          dev_crit(a2, "UCHE: Out of bounds access\n");
        break;
      case 654:
        if ( (unsigned int)__ratelimit(
                             &adreno_hwsched_log_nonfatal_gpu_fault__rs_30,
                             "adreno_hwsched_log_nonfatal_gpu_fault") )
          dev_crit(a2, "UCHE: Trap interrupt\n");
        break;
      case 655:
        v6 = *(_DWORD **)(a1 + 22792);
        if ( !*v6 || (v7 = ((*v6 >> 6) & 0x3FC) - 36, ((*v6 >> 6) & 0x3FC) == 0x24) )
        {
LABEL_33:
          v13 = 0;
          v12 = 0;
        }
        else
        {
          v8 = 0;
          v9 = v6 + 9;
          while ( 1 )
          {
            v10 = (_WORD *)((char *)v9 + v8);
            if ( *v10 == 1 )
            {
              v11 = v10 + 2;
              if ( *(_DWORD *)&v10[2 * v8 + 2] == 31 )
                break;
            }
            v8 += 4 * (unsigned __int16)v10[1] + 4;
            if ( v8 >= v7 )
              goto LABEL_33;
          }
          v12 = *(unsigned int *)&v11[2 * v8 + 2];
          v13 = *(unsigned int *)&v11[2 * v8 + 4];
        }
        if ( (unsigned int)__ratelimit(
                             &adreno_hwsched_log_nonfatal_gpu_fault__rs_32,
                             "adreno_hwsched_log_nonfatal_gpu_fault") )
          dev_crit(
            a2,
            "TSB: Write error interrupt: Address: 0x%lx MID: %lu\n",
            v12 & 0xFFFE0000FFFFFFFFLL | ((v13 & 0x1FFFF) << 32),
            v13 >> 23);
        break;
      default:
        return result;
    }
  }
  else
  {
    switch ( a3 )
    {
      case 650:
        v14 = *(_DWORD **)(a1 + 22792);
        if ( !*v14 || (v15 = ((*v14 >> 6) & 0x3FC) - 36, ((*v14 >> 6) & 0x3FC) == 0x24) )
        {
LABEL_30:
          v21 = 0;
          v20 = 0;
        }
        else
        {
          v16 = 0;
          v17 = v14 + 9;
          while ( 1 )
          {
            v18 = (_WORD *)((char *)v17 + v16);
            if ( *v18 == 1 )
            {
              v19 = v18 + 2;
              if ( *(_DWORD *)&v18[2 * v16 + 2] == 30 )
                break;
            }
            v16 += 4 * (unsigned __int16)v18[1] + 4;
            if ( v16 >= v15 )
              goto LABEL_30;
          }
          v20 = *(_DWORD *)&v19[2 * v16 + 2];
          v21 = *(_DWORD *)&v19[2 * v16 + 4];
        }
        if ( (unsigned int)__ratelimit(
                             &adreno_hwsched_log_nonfatal_gpu_fault__rs,
                             "adreno_hwsched_log_nonfatal_gpu_fault") )
          dev_crit(a2, "CP: AHB bus error, CP_RL_ERROR_DETAILS_0:0x%x CP_RL_ERROR_DETAILS_1:0x%x\n", v20, v21);
        break;
      case 651:
        if ( (unsigned int)__ratelimit(
                             &adreno_hwsched_log_nonfatal_gpu_fault__rs_24,
                             "adreno_hwsched_log_nonfatal_gpu_fault") )
          dev_crit(a2, "RBBM: ATB ASYNC overflow\n");
        break;
      case 652:
        if ( (unsigned int)__ratelimit(
                             &adreno_hwsched_log_nonfatal_gpu_fault__rs_26,
                             "adreno_hwsched_log_nonfatal_gpu_fault") )
          dev_crit(a2, "RBBM: ATB bus overflow\n");
        break;
      default:
        return result;
    }
  }
  return 1;
}
