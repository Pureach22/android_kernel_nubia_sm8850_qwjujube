__int64 __fastcall handle_release_output_buffer(__int64 a1, __int64 a2)
{
  __int64 v2; // x4
  int v3; // w10

  v2 = *(_QWORD *)(a1 + 2584);
  if ( v2 == a1 + 2584 )
  {
LABEL_7:
    if ( a1 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_847D3, "err ", a1 + 340, "handle_release_output_buffer", *(unsigned int *)(a2 + 4));
    }
    return 4294967274LL;
  }
  else
  {
    while ( 1 )
    {
      if ( *(_QWORD *)(v2 + 56) == *(_QWORD *)(a2 + 8) )
      {
        v3 = *(_DWORD *)(v2 + 80);
        if ( (v3 & 4) != 0 )
          break;
      }
      v2 = *(_QWORD *)v2;
      if ( v2 == a1 + 2584 )
        goto LABEL_7;
    }
    *(_DWORD *)(v2 + 80) = v3 & 0xFFFFFFF9;
    print_vidc_buffer(4, (__int64)"low ", (__int64)"release done", a1, v2);
    return 0;
  }
}
