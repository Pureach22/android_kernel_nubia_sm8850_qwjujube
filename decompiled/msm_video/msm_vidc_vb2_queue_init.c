unsigned __int64 __fastcall msm_vidc_vb2_queue_init(_QWORD *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  unsigned __int64 result; // x0
  __int64 v7; // x4
  __int64 v8; // x0
  __int64 v9; // x4
  __int64 v10; // x0
  __int64 v11; // x4
  __int64 v12; // x8
  __int16 v13; // w9
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x20
  __int64 v17; // x1
  __int64 v18; // x4

  if ( a1[226] )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_8F0D3, "err ", (char *)a1 + 340, "msm_vidc_vb2_queue_init", a5);
      return 4294967274LL;
    }
    else
    {
      return 4294967274LL;
    }
  }
  else
  {
    result = v4l2_m2m_init(*(_QWORD *)(a1[40] + 6536LL));
    a1[226] = result;
    if ( result < 0xFFFFFFFFFFFFF001LL )
    {
      v8 = v4l2_m2m_ctx_init();
      a1[227] = v8;
      if ( v8 )
      {
        a1[225] = v8;
        v10 = vzalloc_noprof(376);
        a1[232] = v10;
        if ( v10 )
        {
          *(_QWORD *)(v10 + 32) = a1 + 8;
          *(_QWORD *)v10 = 0x110000000ELL;
          v12 = a1[40];
          *(_DWORD *)(v10 + 88) = 0x4000;
          *(_QWORD *)(v10 + 48) = *(_QWORD *)(v12 + 6520);
          v13 = *(_WORD *)(v10 + 320);
          v14 = *(_QWORD *)(v12 + 6528);
          *(_QWORD *)(v10 + 72) = a1;
          *(_QWORD *)(v10 + 56) = v14;
          *(_WORD *)(v10 + 320) = v13 | 0x100;
          v15 = vb2_queue_init();
          if ( a1 && (_DWORD)v15 )
          {
            v16 = v15;
            if ( (msm_vidc_debug & 1) != 0 )
              printk(&unk_94A6E, "err ", (char *)a1 + 340, "vb2q_init", 14);
          }
          else
          {
            v16 = v15;
            if ( !(_DWORD)v15 )
            {
              v17 = vzalloc_noprof(376);
              a1[233] = v17;
              if ( v17 )
              {
                *(_QWORD *)(v17 + 32) = a1 + 8;
                result = vb2q_init(a1);
                if ( !(_DWORD)result )
                  return result;
                v16 = result;
                vfree(a1[233]);
                a1[233] = 0;
              }
              else
              {
                if ( a1 && (msm_vidc_debug & 1) != 0 )
                  printk(&unk_92E2A, "err ", (char *)a1 + 340, "msm_vidc_vb2_queue_init", v18);
                v16 = 4294967284LL;
              }
              vb2_queue_release(a1[232]);
            }
          }
          vfree(a1[232]);
          a1[232] = 0;
        }
        else if ( a1 && (msm_vidc_debug & 1) != 0 )
        {
          printk(&unk_92E2A, "err ", (char *)a1 + 340, "msm_vidc_vb2_queue_init", v11);
          v16 = 4294967284LL;
        }
        else
        {
          v16 = 4294967284LL;
        }
        v4l2_m2m_ctx_release(a1[227]);
        a1[227] = 0;
        a1[225] = 0;
        a1[230] = 0;
        a1[231] = 0;
      }
      else if ( a1 && (msm_vidc_debug & 1) != 0 )
      {
        printk(&unk_82BAD, "err ", (char *)a1 + 340, "msm_vidc_vb2_queue_init", v9);
        v16 = 4294967274LL;
      }
      else
      {
        v16 = 4294967274LL;
      }
      v4l2_m2m_release(a1[226]);
      a1[226] = 0;
      return v16;
    }
    else if ( a1 && (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_8F101, "err ", (char *)a1 + 340, "msm_vidc_vb2_queue_init", v7);
      return a1[226];
    }
  }
  return result;
}
