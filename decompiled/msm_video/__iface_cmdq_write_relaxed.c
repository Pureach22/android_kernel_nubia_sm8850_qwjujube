__int64 __fastcall _iface_cmdq_write_relaxed(__int64 a1, unsigned int *a2, _BYTE *a3)
{
  __int64 result; // x0
  __int64 v7; // x4
  _DWORD *v8; // x23
  unsigned int v9; // w8
  unsigned int v10; // w5
  unsigned int v11; // w10
  void *v12; // x0
  unsigned int v13; // w9
  unsigned int v14; // w11
  bool v15; // cf
  unsigned int v16; // w11
  __int64 v17; // x11
  unsigned __int64 v18; // x10
  void *v19; // x0
  __int64 v20; // x11
  char v21; // w8
  unsigned int v22; // w22
  unsigned int v23; // w24
  size_t v24; // x22

  result = _strict_check(a1, (__int64)"__iface_cmdq_write_relaxed");
  if ( !(_DWORD)result )
  {
    if ( core_in_valid_state(a1) )
    {
      if ( *(_QWORD *)(a1 + 5672) )
      {
        if ( !a2 )
        {
          if ( (msm_vidc_debug & 1) != 0 )
            printk(&unk_834D4, "err ", 0xFFFFFFFFLL, "codec", "__write_queue");
          goto LABEL_21;
        }
        v8 = *(_DWORD **)(a1 + 5656);
        if ( v8 )
        {
          if ( (msm_vidc_debug & 0x10) != 0 )
            _dump_packet(a2, "__write_queue", a1 + 5656);
          v9 = *a2;
          if ( *a2 >= 4 && (v10 = v9 >> 2, v11 = *(_DWORD *)(a1 + 5680) >> 2, v9 >> 2 <= v11) )
          {
            v14 = v8[12];
            v13 = v8[13];
            v15 = v14 >= v13;
            v16 = v14 - v13;
            if ( v16 != 0 && v15 )
              v11 = 0;
            v7 = v11 + v16;
            if ( (unsigned int)v7 <= v10 )
            {
              v21 = msm_vidc_debug;
              v8[9] = 1;
              if ( (v21 & 1) != 0 )
                printk(&unk_97D64, "err ", 0xFFFFFFFFLL, "codec", v7);
              goto LABEL_21;
            }
            v8[9] = 0;
            v17 = 4 * v13;
            v18 = *(_QWORD *)(a1 + 5672);
            v19 = (void *)(v18 + v17);
            if ( v18 + v17 >= v18 )
            {
              v20 = *(unsigned int *)(a1 + 5680);
              if ( (unsigned __int64)v19 <= v18 + v20 )
              {
                v22 = v13 + v10;
                v23 = v13 + v10 - ((unsigned int)v20 >> 2);
                if ( v13 + v10 >= (unsigned int)v20 >> 2 )
                {
                  v24 = ((unsigned int)v20 >> 2) - v13;
                  memcpy(v19, a2, v24 * 4);
                  memcpy(*(void **)(a1 + 5672), &a2[v24], 4 * v23);
                  v22 = v23;
                }
                else
                {
                  memcpy(v19, a2, v9 & 0xFFFFFFFC);
                }
                __dsb(0xFu);
                v8[13] = v22;
                if ( a3 )
                  *a3 = 1;
                __dsb(0xFu);
                return 0;
              }
            }
            if ( (msm_vidc_debug & 1) == 0 )
            {
LABEL_21:
              if ( (msm_vidc_debug & 1) != 0 )
                printk(&unk_85F4F, "err ", 0xFFFFFFFFLL, "codec", v7);
              return 0;
            }
            v12 = &unk_91C22;
          }
          else
          {
            if ( (msm_vidc_debug & 1) == 0 )
              goto LABEL_21;
            v12 = &unk_83CB8;
          }
        }
        else
        {
          if ( (msm_vidc_debug & 1) == 0 )
            goto LABEL_21;
          v12 = &unk_889A8;
        }
        printk(v12, "err ", 0xFFFFFFFFLL, "codec", v7);
        goto LABEL_21;
      }
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_8C54A, "err ", 0xFFFFFFFFLL, "codec", v7);
      return 4294967235LL;
    }
    else
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_95D30, "err ", 0xFFFFFFFFLL, "codec", "__iface_cmdq_write_relaxed");
      return 4294967274LL;
    }
  }
  return result;
}
