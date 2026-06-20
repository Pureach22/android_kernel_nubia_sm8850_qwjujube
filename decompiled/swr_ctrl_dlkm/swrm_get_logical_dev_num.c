__int64 __fastcall swrm_get_logical_dev_num(__int64 a1, __int64 a2, _BYTE *a3)
{
  __int64 v3; // x19
  int v5; // w27
  int v7; // w23
  _QWORD *v8; // x28
  _QWORD *v9; // x23
  unsigned int v10; // w22
  int v11; // w25
  unsigned __int16 v13; // w26
  unsigned int v14; // w0
  _QWORD *v15; // x24
  unsigned __int64 v16; // x21
  int v17; // w0
  __int64 v18; // x0
  __int64 v19; // x20

  if ( a1 && (v3 = *(_QWORD *)(a1 + 152)) != 0 )
  {
    v5 = *(_DWORD *)(v3 + 9140);
    mutex_lock(v3 + 8736);
    v7 = *(unsigned __int8 *)(v3 + 15748);
    mutex_unlock(v3 + 8736);
    if ( v7 == 1 )
    {
      _pm_runtime_resume(*(_QWORD *)(v3 + 8512), 4);
      mutex_lock(&enumeration_lock);
      if ( (unsigned int)(v5 - 1) > 0xFFFFFFFD )
      {
        v10 = -22;
      }
      else
      {
        v8 = nullptr;
        v9 = (_QWORD *)(a1 + 984);
        v10 = -22;
        v11 = 1;
        do
        {
          v13 = swr_master_read(v3, 8 * (unsigned __int16)v11 + 1332);
          v14 = swr_master_read(v3, 8 * (unsigned __int16)v11 + 1328);
          v15 = (_QWORD *)*v9;
          if ( (_QWORD *)*v9 != v9 )
          {
            v16 = v14 | ((unsigned __int64)v13 << 32);
            do
            {
              if ( v15[117] == v16 )
              {
                v17 = swr_master_read(v3, 0x1090u);
                *(_DWORD *)(v3 + 9144) = v17;
                if ( ((v17 >> (2 * v11)) & 3u) - 1 <= 1 )
                {
                  *((_BYTE *)v15 + 16) = v11;
                  if ( v16 == a2 )
                  {
                    *a3 = v11;
                    v8 = v15 - 6;
                    dev_info(
                      *(_QWORD *)(v3 + 8512),
                      "%s: devnum %d assigned for dev %llx\n",
                      "swrm_get_logical_dev_num",
                      v11,
                      v15[117]);
                    v10 = 0;
                  }
                }
              }
              v15 = (_QWORD *)*v15;
            }
            while ( v15 != v9 );
          }
        }
        while ( v11++ != v5 );
        if ( !v10 && v8 )
        {
          if ( (*((_BYTE *)v8 + 1009) & 1) == 0 )
            swrm_initialize_clk_base_scale(v3, (unsigned __int8)*a3);
          v10 = 0;
          goto LABEL_25;
        }
        if ( !v10 )
        {
LABEL_25:
          v18 = mutex_unlock(&enumeration_lock);
          v19 = *(_QWORD *)(v3 + 8512);
          *(_QWORD *)(v19 + 520) = ktime_get_mono_fast_ns(v18);
          _pm_runtime_suspend(*(_QWORD *)(v3 + 8512), 13);
          return v10;
        }
      }
      dev_err(*(_QWORD *)(v3 + 8512), "%s: device 0x%llx is not ready\n", "swrm_get_logical_dev_num", a2);
      goto LABEL_25;
    }
    return (unsigned int)-22;
  }
  else
  {
    printk(&unk_1079B, "swrm_get_logical_dev_num");
    return (unsigned int)-22;
  }
}
