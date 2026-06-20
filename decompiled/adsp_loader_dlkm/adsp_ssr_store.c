__int64 __fastcall adsp_ssr_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x22
  __int64 *v5; // x21
  int v7; // w8
  __int64 result; // x0
  __int64 v9; // x19
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = adsp_private;
  v10 = 0;
  v5 = *(__int64 **)(adsp_private + 168);
  if ( v5 )
  {
    v7 = kstrtoint(a3, 10, &v10);
    result = -22;
    if ( (v7 & 0x80000000) == 0 && v10 == 1 )
    {
      v9 = *v5;
      if ( *v5 )
      {
        dev_err(v4 + 16, "requesting for ADSP restart\n");
        *((_BYTE *)v5 + 32) = 1;
        rproc_shutdown(v9);
        queue_work_on(32, system_wq, &adsp_ldr_work);
        result = a4;
      }
    }
  }
  else
  {
    result = -22;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
