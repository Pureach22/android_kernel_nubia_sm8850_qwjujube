__int64 __fastcall msm_vidc_memory_unmap_free_ext(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v5; // w8
  int v6; // w8
  char v7; // w9
  __int64 v8; // x8
  void (__fastcall *v9)(_QWORD); // x9
  __int64 v10; // x21
  __int64 v11; // x19
  void (__fastcall *v12)(__int64, __int64, __int64); // x9
  __int64 v13; // x2
  __int64 v14; // x19
  __int64 v15; // x1
  __int64 result; // x0
  void *v17; // x0
  __int64 v18; // x19
  __int64 v19; // x21

  if ( a2 )
  {
    v5 = *(_DWORD *)(a2 + 80);
    if ( v5 )
    {
      v6 = v5 - 1;
      v7 = msm_vidc_debug;
      *(_DWORD *)(a2 + 80) = v6;
      if ( (v7 & 4) != 0 )
      {
        v18 = a1;
        v19 = a2;
        buf_name(*(_DWORD *)(a2 + 16));
        printk(&unk_806EB, "low ", 0xFFFFFFFFLL, "codec", "msm_vidc_memory_unmap_ext");
        a1 = v18;
        a2 = v19;
        if ( *(_DWORD *)(v19 + 80) )
          goto LABEL_16;
      }
      else if ( v6 )
      {
        goto LABEL_16;
      }
      if ( a1 )
      {
        v8 = *(_QWORD *)(a1 + 6568);
        if ( v8 )
        {
          v9 = *(void (__fastcall **)(_QWORD))(v8 + 48);
          if ( !v9 )
            goto LABEL_11;
          v10 = a2;
          v11 = a1;
          if ( *((_DWORD *)v9 - 1) != -792689463 )
            __break(0x8229u);
          v9(a1);
          v8 = *(_QWORD *)(v11 + 6568);
          a1 = v11;
          a2 = v10;
          if ( v8 )
          {
LABEL_11:
            v12 = *(void (__fastcall **)(__int64, __int64, __int64))(v8 + 32);
            if ( v12 )
            {
              v13 = *(_QWORD *)(a2 + 96);
              v14 = a2;
              v15 = *(_QWORD *)(a2 + 32);
              if ( *((_DWORD *)v12 - 1) != 248590048 )
                __break(0x8229u);
              v12(a1, v15, v13);
              a2 = v14;
            }
          }
        }
      }
      *(_QWORD *)(a2 + 64) = 0;
      *(_QWORD *)(a2 + 88) = 0;
      *(_QWORD *)(a2 + 96) = 0;
LABEL_16:
      result = msm_vidc_memory_free_ext(a2);
      if ( !(_DWORD)result )
        return result;
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v17 = &unk_96F17;
LABEL_27:
        printk(v17, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_memory_unmap_free_ext");
        return 4294967274LL;
      }
      return 4294967274LL;
    }
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8B70E, "err ", 0xFFFFFFFFLL, "codec", a5);
  }
  else if ( (msm_vidc_debug & 1) != 0 )
  {
    printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_memory_unmap_ext");
  }
  if ( (msm_vidc_debug & 1) != 0 )
  {
    v17 = &unk_8C1E3;
    goto LABEL_27;
  }
  return 4294967274LL;
}
