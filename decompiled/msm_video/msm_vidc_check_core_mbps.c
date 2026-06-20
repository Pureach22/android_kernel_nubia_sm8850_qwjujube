__int64 __fastcall msm_vidc_check_core_mbps(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x23
  __int64 v3; // x24
  _QWORD *v4; // x20
  _QWORD *v5; // x25
  unsigned __int64 v6; // x19
  _QWORD *v7; // x21
  unsigned __int64 v8; // x20
  unsigned __int64 v9; // x19
  unsigned __int64 v10; // x22
  int inst_load; // w0
  __int64 v12; // x8
  int v13; // w9
  __int64 v14; // x8
  unsigned __int64 v15; // x5
  void *v16; // x0
  __int64 v17; // x2
  unsigned __int64 v18; // x4
  _QWORD *v19; // x26
  __int64 v20; // x8

  v1 = *(_QWORD *)(result + 33416);
  if ( !v1 && !*(_QWORD *)(result + 32576) && *(_DWORD *)(result + 312) != 8 && *(_DWORD *)(result + 160) != 5 )
  {
    v2 = *(_QWORD *)(result + 320);
    v3 = result;
    mutex_lock(v2 + 3856);
    v4 = *(_QWORD **)(v2 + 3528);
    v5 = (_QWORD *)(v2 + 3528);
    if ( v4 == (_QWORD *)(v2 + 3528) )
    {
      v6 = 0;
    }
    else
    {
      v6 = 0;
      do
      {
        if ( v4[4219] )
          v6 += (int)msm_vidc_get_inst_load(v4);
        v4 = (_QWORD *)*v4;
      }
      while ( v4 != v5 );
    }
    mutex_unlock(v2 + 3856);
    if ( v6 > *(_QWORD *)(v2 + 4144) )
    {
      if ( !v3 || (msm_vidc_debug & 1) == 0 )
        return 4294967284LL;
      v16 = &unk_86A41;
      v17 = v3 + 340;
      v18 = v6;
LABEL_56:
      printk(v16, "err ", v17, "msm_vidc_check_core_mbps", v18);
      return 4294967284LL;
    }
    mutex_lock(v2 + 3856);
    v7 = (_QWORD *)*v5;
    if ( (_QWORD *)*v5 == v5 )
    {
      v10 = 0;
      v9 = 0;
      v8 = 0;
    }
    else
    {
      v8 = 0;
      v9 = 0;
      v10 = 0;
      do
      {
        if ( !v7[4177] && !v7[4072] && *((_DWORD *)v7 + 78) != 8 && *((_DWORD *)v7 + 40) != 5 )
        {
          inst_load = msm_vidc_get_inst_load(v7);
          v8 = inst_load;
          v9 += inst_load;
          if ( *((_DWORD *)v7 + 77) == 1 )
            v12 = inst_load;
          else
            v12 = 0;
          v10 += v12;
        }
        v7 = (_QWORD *)*v7;
      }
      while ( v7 != v5 );
    }
    mutex_unlock(v2 + 3856);
    v13 = *(_DWORD *)(v3 + 308);
    v14 = v3;
    if ( v13 == 2 )
    {
      if ( v9 > *(_QWORD *)(v2 + 4144) )
      {
        *(_DWORD *)(v3 + 38708) = 1;
        if ( !v3 )
          return 0;
        if ( (msm_vidc_debug & 2) != 0 )
        {
          printk(&unk_89138, "high", v3 + 340, "msm_vidc_check_core_mbps", 1);
          v14 = v3;
        }
LABEL_53:
        if ( (msm_vidc_debug & 2) != 0 )
          printk(&unk_875E7, "high", v14 + 340, "msm_vidc_check_core_mbps", v9);
        return 0;
      }
    }
    else if ( v13 == 1 )
    {
      v15 = *(_QWORD *)(v2 + 4144);
      if ( v10 > v15 )
      {
        if ( !v3 || (msm_vidc_debug & 1) == 0 )
          return 4294967284LL;
        v16 = &unk_96E36;
        v17 = v3 + 340;
        v18 = v8;
        goto LABEL_56;
      }
      if ( v9 > v15 )
      {
        mutex_lock(v2 + 3856);
        v19 = (_QWORD *)*v5;
        if ( (_QWORD *)*v5 != v5 )
        {
          v20 = v3;
          do
          {
            if ( *((_DWORD *)v19 + 77) == 2 && !v19[4177] )
            {
              *((_DWORD *)v19 + 9677) = 1;
              if ( v20 )
              {
                if ( (msm_vidc_debug & 2) != 0 )
                {
                  printk(&unk_89138, "high", v20 + 340, "msm_vidc_check_core_mbps", 1);
                  v20 = v3;
                }
              }
            }
            v19 = (_QWORD *)*v19;
          }
          while ( v19 != v5 );
        }
        mutex_unlock(v2 + 3856);
        v14 = v3;
      }
    }
    if ( !v14 )
      return 0;
    goto LABEL_53;
  }
  if ( !result )
    return result;
  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_836A2, "high", result + 340, "msm_vidc_check_core_mbps", v1 != 0);
  return 0;
}
