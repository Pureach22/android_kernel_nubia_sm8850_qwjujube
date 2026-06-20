__int64 __fastcall cvp_allocate_dsp_bufs(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 result; // x0
  unsigned int v5; // w20
  __int64 v7; // x8
  unsigned int v8; // w0
  unsigned int v9; // w20
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v11; // x8
  int v12; // w8
  unsigned __int64 v13; // x8
  unsigned int v20; // w9

  result = 4294967274LL;
  if ( a1 && a2 )
  {
    if ( a3 >= 3 )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_970F3, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
        return 4294967274LL;
      }
    }
    else
    {
      v5 = dword_6AD28[a3];
      if ( (msm_cvp_debug & 0x40) != 0 && !msm_cvp_debug_out )
        printk(&unk_8846F, &unk_84256, "cvp_allocate_dsp_bufs", v5);
      result = cvp_kmem_cache_zalloc(cvp_driver + 120, 3264);
      *(_QWORD *)(a1 + 56) = result;
      if ( result )
      {
        v7 = cvp_driver;
        *(_DWORD *)(result + 88) = v5;
        v8 = msm_cvp_smem_alloc(a2, 1, 0, *(_QWORD *)(v7 + 48) + 608LL, *(_QWORD *)(a1 + 56), 0);
        if ( v8 )
        {
          v9 = v8;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v13 = _ReadStatusReg(SP_EL0);
            printk(&unk_8AB20, *(unsigned int *)(v13 + 1800), *(unsigned int *)(v13 + 1804), &unk_8E7CE);
          }
          cvp_kmem_cache_free(cvp_driver + 120, *(_QWORD *)(a1 + 56));
          return v9;
        }
        else
        {
          *(_DWORD *)(*(_QWORD *)(a1 + 56) + 96LL) = 0;
          *(_DWORD *)(*(_QWORD *)(a1 + 56) + 92LL) = 0;
          _X8 = (unsigned int *)(*(_QWORD *)(a1 + 56) + 40LL);
          __asm { PRFM            #0x11, [X8] }
          do
            v20 = __ldxr(_X8);
          while ( __stxr(v20 + 1, _X8) );
          if ( (msm_cvp_debug & 0x40) != 0 && !msm_cvp_debug_out )
            printk(&unk_8F6EC, &unk_84256, "cvp_allocate_dsp_bufs", *(_QWORD *)(*(_QWORD *)(a1 + 56) + 48LL));
          result = 0;
          v12 = *(_DWORD *)(*(_QWORD *)(a1 + 56) + 80LL);
          *(_DWORD *)(a1 + 28) = 5;
          *(_DWORD *)(a1 + 48) = 2;
          *(_DWORD *)(a1 + 20) = v12;
        }
      }
      else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v11 = _ReadStatusReg(SP_EL0);
        printk(&unk_8D304, *(unsigned int *)(v11 + 1800), *(unsigned int *)(v11 + 1804), &unk_8E7CE);
        return 0;
      }
    }
  }
  return result;
}
