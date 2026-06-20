__int64 __fastcall qcom_dump(_QWORD *a1, __int64 a2)
{
  _QWORD *v2; // x23
  unsigned __int64 v5; // x20
  __int64 v6; // x8
  __int64 v7; // x22
  _QWORD *v8; // x24
  unsigned __int64 v9; // x25
  __int64 v10; // x0
  __int64 v11; // x8
  size_t v12; // x2
  size_t v13; // x1
  size_t v14; // x2
  size_t v15; // x1
  __int64 result; // x0
  unsigned __int64 StatusReg; // x23
  __int64 v18; // x24
  __int64 v19; // [xsp+0h] [xbp-30h] BYREF
  __int64 v20; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v21[4]; // [xsp+10h] [xbp-20h] BYREF

  v21[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v2 = (_QWORD *)*a1;
    if ( (_QWORD *)*a1 != a1 )
    {
      v5 = 0;
      do
      {
        printk(&unk_6F59, v2[4]);
        v6 = v2[4];
        v2 = (_QWORD *)*v2;
        v5 += v6;
      }
      while ( v2 != a1 );
      v7 = vmalloc_noprof(v5);
      if ( !v7 )
        goto LABEL_26;
      while ( 1 )
      {
        v8 = (_QWORD *)*a1;
        if ( (_QWORD *)*a1 == a1 )
        {
LABEL_23:
          v20 = 0;
          memset(v21, 0, 24);
          v19 = v7;
          _init_swait_queue_head(v21, "&x->wait", &init_completion___key);
          dev_coredumpm_timeout(a2, 0, &v19, v5, 3264, qcom_devcd_readv, qcom_devcd_freev, 75000);
          wait_for_completion(&v20);
          result = (completion_done(&v20) & 1) == 0;
          goto LABEL_27;
        }
        v9 = 0;
        while ( !v8[3] )
        {
          v10 = devm_ioremap(a2, v8[2], v8[4]);
          if ( v10 )
          {
            _memcpy_fromio(v7 + v9, v10, v8[4]);
          }
          else
          {
            dev_err(a2, "invalid coredump segment (%pad, %zu)\n", v8 + 2, v8[4]);
            v14 = v8[4];
            if ( v5 >= v9 )
              v15 = v5 - v9;
            else
              v15 = 0;
            if ( v15 < v14 )
              goto LABEL_25;
            memset((void *)(v7 + v9), 255, v14);
          }
LABEL_10:
          v11 = v8[4];
          v8 = (_QWORD *)*v8;
          v9 += v11;
          if ( v8 == a1 )
            goto LABEL_23;
        }
        v12 = v8[4];
        v13 = v5 >= v9 ? v5 - v9 : 0LL;
        if ( v13 >= v12 )
          break;
        _fortify_panic(17);
LABEL_25:
        _fortify_panic(15);
        StatusReg = _ReadStatusReg(SP_EL0);
        v18 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
        v7 = vmalloc_noprof(v5);
        *(_QWORD *)(StatusReg + 80) = v18;
        if ( !v7 )
        {
LABEL_26:
          result = 4294967284LL;
          goto LABEL_27;
        }
      }
      memcpy((void *)(v7 + v9), (const void *)v8[3], v12);
      goto LABEL_10;
    }
  }
  result = 4294967274LL;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
