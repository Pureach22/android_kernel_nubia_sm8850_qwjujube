__int64 __fastcall venus_hfi_queue_dbg_read(__int64 a1, char *a2, __int64 a3, __int64 a4, __int64 a5)
{
  void *v5; // x0
  __int64 result; // x0
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = 0;
  if ( a2 )
  {
    if ( *(_QWORD *)(a1 + 5976) )
    {
      if ( !(unsigned int)_read_queue(a1 + 5960, a2, &v7, a4, a5) )
      {
        if ( !v7 )
        {
          result = 0;
          goto LABEL_12;
        }
        if ( (msm_vidc_debug & 1) == 0 )
          goto LABEL_8;
        v5 = &unk_8F72F;
        goto LABEL_15;
      }
    }
    else if ( (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_85F13, "err ", 0xFFFFFFFFLL, "codec", a5);
    }
    result = 4294967235LL;
    goto LABEL_12;
  }
  if ( (msm_vidc_debug & 1) != 0 )
  {
    v5 = &unk_83321;
LABEL_15:
    printk(v5, "err ", 0xFFFFFFFFLL, "codec", "venus_hfi_queue_dbg_read");
  }
LABEL_8:
  result = 4294967274LL;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
