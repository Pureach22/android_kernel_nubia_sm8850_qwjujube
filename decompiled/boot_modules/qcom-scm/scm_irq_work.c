__int64 __fastcall scm_irq_work(__int64 result)
{
  int v1; // w23
  _QWORD *v2; // x19
  _DWORD *v3; // x22
  unsigned __int64 v4; // x0
  __int64 v5; // x1
  int v6; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v7; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v8; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = 0;
  if ( qcom_scm_convention == 3 )
  {
    v1 = *(_DWORD *)(result + 48);
    v2 = (_QWORD *)(result - 224);
    v8 = 0;
    v7 = 0;
    while ( 1 )
    {
      result = scm_get_wq_ctx(&v8, &v7, &v6, v1 == 1);
      if ( (_DWORD)result )
      {
        result = printk(&unk_12C8E, "scm_irq_work", (unsigned int)result);
        goto LABEL_15;
      }
      if ( !v7 )
        goto LABEL_15;
      v4 = qcom_scm_lookup_wq(v2, v8);
      if ( !v4 || v4 >= 0xFFFFFFFFFFFFF001LL )
        break;
      if ( v7 == 2 )
      {
        v3 = (_DWORD *)v4;
        result = complete_all();
        *v3 = 0;
      }
      else if ( v7 == 1 )
      {
        result = complete(v4, v5, 1);
      }
      else
      {
        result = printk(&unk_12A88, "scm_waitq_flag_handler", v7);
      }
      if ( !v6 )
        goto LABEL_15;
    }
    result = printk(&unk_1244C, "scm_irq_work", v8);
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
