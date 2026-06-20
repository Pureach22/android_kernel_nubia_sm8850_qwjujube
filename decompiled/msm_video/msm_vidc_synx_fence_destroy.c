__int64 __fastcall msm_vidc_synx_fence_destroy(__int64 a1, __int64 a2, char a3)
{
  __int64 result; // x0
  char v6; // w21
  int v7; // w0
  int v8; // w0
  __int64 v9; // x4
  unsigned int v10; // w19

  if ( *(_QWORD *)(a2 + 264) )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_89281, "err ", a1 + 340, "msm_vidc_synx_fence_destroy", a2 + 16);
      return 4294967274LL;
    }
    else
    {
      return 4294967274LL;
    }
  }
  else
  {
    if ( *(_QWORD *)(a2 + 176) )
    {
      v6 = a3;
      if ( (a3 & 1) != 0 )
      {
        v7 = synx_signal();
        if ( a1 )
        {
          if ( v7 && (msm_vidc_debug & 1) != 0 )
            printk(&unk_825FB, "err ", a1 + 340, "msm_vidc_synx_fence_destroy", a2 + 16);
        }
      }
      v8 = synx_release(*(_QWORD *)(a2 + 176), *(unsigned int *)(a2 + 160));
      a3 = v6;
      if ( v8 && (msm_vidc_debug & 1) != 0 )
      {
        printk(&unk_918FA, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_synx_fence_destroy");
        a3 = v6;
      }
    }
    result = msm_vidc_fence_signal(a1, a2, a3 & 1);
    if ( (_DWORD)result )
    {
      if ( a1 && (msm_vidc_debug & 1) != 0 )
      {
        v9 = a2 + 16;
        v10 = result;
        printk(&unk_81818, "err ", a1 + 340, "msm_vidc_synx_fence_destroy", v9);
        return v10;
      }
    }
    else
    {
      return msm_vidc_put_sw_fence(a1, (char *)a2);
    }
  }
  return result;
}
