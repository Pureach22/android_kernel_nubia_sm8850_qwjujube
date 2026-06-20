__int64 __fastcall msm_vidc_synx_fence_release(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x20
  int v4; // w0
  int v5; // w8

  if ( *(_QWORD *)(a2 + 264) )
  {
    if ( *(_QWORD *)(a2 + 176) )
    {
      v2 = a1;
      v3 = a2;
      v4 = synx_release(*(_QWORD *)(a2 + 176), *(unsigned int *)(a2 + 160));
      a2 = v3;
      v5 = v4;
      a1 = v2;
      if ( v5 )
      {
        if ( (msm_vidc_debug & 1) != 0 )
        {
          printk(&unk_918FA, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_synx_fence_release");
          a1 = v2;
          a2 = v3;
        }
      }
    }
    return msm_vidc_put_sw_fence(a1, (char *)a2);
  }
  else
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_89281, "err ", a1 + 340, "msm_vidc_synx_fence_release", a2 + 16);
    return 4294967274LL;
  }
}
