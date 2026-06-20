__int64 __fastcall msm_dss_get_gpio_io_mem(unsigned int a1, _QWORD *a2)
{
  _QWORD *v4; // x21
  _QWORD *v5; // x2
  __int64 v6; // x9
  _QWORD *v7; // x8
  __int64 result; // x0
  __int64 v9; // [xsp+8h] [xbp-68h] BYREF
  __int64 v10; // [xsp+10h] [xbp-60h]
  __int64 v11; // [xsp+18h] [xbp-58h]
  __int64 v12; // [xsp+20h] [xbp-50h]
  __int64 v13; // [xsp+28h] [xbp-48h]
  __int64 v14; // [xsp+30h] [xbp-40h]
  __int64 v15; // [xsp+38h] [xbp-38h]
  __int64 v16; // [xsp+40h] [xbp-30h]
  __int64 v17; // [xsp+48h] [xbp-28h]
  __int64 v18; // [xsp+50h] [xbp-20h]
  __int64 v19; // [xsp+58h] [xbp-18h]
  __int64 v20; // [xsp+60h] [xbp-10h]
  __int64 v21; // [xsp+68h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a1 & 0x80000000) != 0 )
  {
    result = 4294967274LL;
  }
  else
  {
    v19 = 0;
    v20 = 0;
    v17 = 0;
    v18 = 0;
    v15 = 0;
    v16 = 0;
    v13 = 0;
    v14 = 0;
    v11 = 0;
    v12 = 0;
    v9 = 0;
    v10 = 0;
    v4 = (_QWORD *)_kmalloc_cache_noprof(wake_up_process, 3520, 32);
    if ( v4 )
    {
      if ( (msm_gpio_get_pin_address(a1, &v9) & 1) != 0 )
      {
        v5 = (_QWORD *)*a2;
        v6 = v10 - v9 + 1;
        *v4 = v9;
        v4[1] = v6;
        v7 = v4 + 2;
        if ( (_QWORD *)v5[1] != a2 || v7 == a2 || v5 == v7 )
        {
          _list_add_valid_or_report(v4 + 2, a2);
          result = 0;
        }
        else
        {
          result = 0;
          v5[1] = v7;
          v4[2] = v5;
          v4[3] = a2;
          *a2 = v7;
        }
      }
      else
      {
        kfree(v4);
        result = 4294967277LL;
      }
    }
    else
    {
      result = 4294967284LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
