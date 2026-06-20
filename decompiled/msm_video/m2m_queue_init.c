__int64 __fastcall m2m_queue_init(_QWORD *a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  char v4; // w8
  __int16 v5; // w9
  __int64 v9; // x8
  __int16 v10; // w9
  __int64 v11; // x8
  __int64 result; // x0
  char *v13; // x2
  unsigned int v14; // w19
  __int64 v15; // x9
  __int16 v16; // w10
  __int64 v17; // x9
  unsigned int v18; // w20

  if ( a1 && a3 && a2 && (v3 = a1[40]) != 0 )
  {
    v4 = *(_WORD *)(v3 + 4608);
    v5 = *(_WORD *)(a2 + 24);
    *(_QWORD *)(a2 + 32) = a1 + 8;
    *(_WORD *)(a2 + 24) = (32 * (v4 & 1)) | v5 & 0xFFDF;
    *(_QWORD *)(a2 + 8) = *(_QWORD *)v3 + 16LL;
    v9 = a1[40];
    *(_QWORD *)a2 = 0x110000000ALL;
    *(_DWORD *)(a2 + 88) = 0x4000;
    *(_QWORD *)(a2 + 48) = *(_QWORD *)(v9 + 6520);
    v10 = *(_WORD *)(a2 + 320);
    v11 = *(_QWORD *)(v9 + 6528);
    *(_QWORD *)(a2 + 72) = a1;
    *(_QWORD *)(a2 + 56) = v11;
    *(_WORD *)(a2 + 320) = v10 | 0x100;
    result = vb2_queue_init(a2);
    if ( (_DWORD)result )
    {
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v13 = (char *)a1 + 340;
        v14 = result;
        printk(&unk_94A6E, "err ", v13, "vb2q_init", 10);
        return v14;
      }
    }
    else
    {
      a1[230] = a2;
      *(_QWORD *)(a3 + 32) = *(_QWORD *)(a2 + 32);
      *(_QWORD *)(a3 + 8) = *(_QWORD *)v3 + 16LL;
      v15 = a1[40];
      *(_QWORD *)a3 = 0x1100000009LL;
      *(_DWORD *)(a3 + 88) = 0x4000;
      *(_QWORD *)(a3 + 48) = *(_QWORD *)(v15 + 6520);
      v16 = *(_WORD *)(a3 + 320);
      v17 = *(_QWORD *)(v15 + 6528);
      *(_QWORD *)(a3 + 72) = a1;
      *(_QWORD *)(a3 + 56) = v17;
      *(_WORD *)(a3 + 320) = v16 | 0x100;
      result = vb2_queue_init(a3);
      if ( (_DWORD)result )
      {
        v18 = result;
        if ( (msm_vidc_debug & 1) != 0 )
          printk(&unk_94A6E, "err ", (char *)a1 + 340, "vb2q_init", 9);
        vb2_queue_release(a1[230]);
        return v18;
      }
      else
      {
        a1[231] = a3;
      }
    }
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "m2m_queue_init");
    return 4294967274LL;
  }
  return result;
}
