__int64 __fastcall synx_register_hw_fence(
        unsigned __int64 a1,
        unsigned int **a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  unsigned int *v6; // x8
  __int64 (__fastcall *v7)(unsigned int **, __int64, int *); // x9
  unsigned int v8; // w19
  __int64 v12; // x1
  __int64 result; // x0
  __int64 v14; // x4
  __int64 v15; // x5
  __int64 v16; // x4
  unsigned int v17; // w20
  __int64 v18; // x4
  unsigned int v19; // w20
  __int64 v20; // x4
  void *v21; // x0
  __int64 v22; // x5
  __int64 v23; // x3
  int v24; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+18h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = 1;
  if ( a1 )
  {
    if ( a1 <= 0xFFFFFFFFFFFFF000LL )
    {
      if ( a2 )
      {
        if ( (unsigned __int64)a2 <= 0xFFFFFFFFFFFFF000LL )
        {
          v6 = *a2;
          if ( *a2 )
          {
            if ( (unsigned __int64)v6 <= 0xFFFFFFFFFFFFF000LL )
            {
              v7 = (__int64 (__fastcall *)(unsigned int **, __int64, int *))hwfence_shared_ops;
              if ( hwfence_shared_ops )
              {
                if ( (unsigned __int64)hwfence_shared_ops < 0xFFFFFFFFFFFFF001LL )
                {
                  v8 = *v6;
                  v12 = *v6;
                  if ( *((_DWORD *)hwfence_shared_ops - 1) != 1500435254 )
                    __break(0x8229u);
                  result = v7(a2, v12, &v24);
                  if ( (_DWORD)result )
                  {
                    if ( (synx_debug & 1) != 0 )
                    {
                      v16 = *(_QWORD *)(a1 + 104);
                      v17 = result;
                      printk(&unk_27991, &unk_29207, "synx_register_hw_fence", 2343, v16, a2[2]);
                      result = v17;
                    }
                    goto LABEL_17;
                  }
                  if ( v24 == 1 )
                  {
                    result = synx_internal_get_handle_status((unsigned __int64)a2, **a2, &v24, 0, v14, v15);
                    if ( (_DWORD)result )
                    {
                      if ( (synx_debug & 1) != 0 )
                      {
                        v18 = *(_QWORD *)(a1 + 104);
                        v19 = result;
                        printk(&unk_2778E, &unk_29207, "synx_register_hw_fence", 2366, v18, **a2);
                        result = v19;
                      }
                      goto LABEL_17;
                    }
                    if ( (synx_debug & 8) == 0 )
                    {
LABEL_25:
                      result = 0;
                      goto LABEL_17;
                    }
                    v20 = *(_QWORD *)(a1 + 104);
                    v21 = &unk_2530B;
                    v22 = **a2;
                    v23 = 2374;
                  }
                  else
                  {
                    synx_global_update_status((unsigned __int16)v8);
                    if ( (synx_debug & 8) == 0 )
                      goto LABEL_25;
                    v20 = *(_QWORD *)(a1 + 104);
                    v21 = &unk_2A63D;
                    v22 = **a2;
                    v23 = 2354;
                  }
                  printk(v21, &unk_2A972, "synx_register_hw_fence", v23, v20, v22);
                  goto LABEL_25;
                }
              }
            }
          }
        }
      }
    }
  }
  if ( (synx_debug & 1) != 0 )
    printk(&unk_2A5F2, &unk_29207, "synx_register_hw_fence", 2331, a5, a6);
  result = 4294967274LL;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
