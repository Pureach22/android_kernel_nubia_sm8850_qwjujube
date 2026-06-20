unsigned __int64 __fastcall adsp_pds_attach(__int64 a1, _QWORD *a2, __int64 *a3)
{
  unsigned __int64 result; // x0
  __int64 v7; // x22
  __int64 *v8; // x8
  __int64 v9; // t1
  __int64 v10; // x25
  int v11; // w23
  int v12; // w8
  __int64 *v13; // x19
  unsigned int v14; // w20
  int v15; // w21
  __int64 v16; // t1

  if ( !a3 )
    return 0;
  if ( *(_QWORD *)(a1 + 592) )
  {
    *a2 = a1;
    pm_runtime_enable(a1);
    return 1;
  }
  else
  {
    v7 = 1;
    v8 = a3;
    do
    {
      v9 = *v8++;
      --v7;
    }
    while ( v9 );
    if ( v7 )
    {
      v10 = 0;
      v11 = 0;
      while ( 1 )
      {
        result = dev_pm_domain_attach_by_name(a1, a3[v10]);
        a2[v10] = result;
        if ( !result || result >= 0xFFFFFFFFFFFFF001LL )
          break;
        v10 = ++v11;
        if ( -v7 <= (unsigned __int64)v11 )
          return (unsigned int)-(int)v7;
      }
      v12 = v11 - 1;
      if ( result )
        result = (unsigned int)result;
      else
        result = 4294967235LL;
      if ( (v12 & 0x80000000) == 0 )
      {
        v13 = &a2[v12];
        v14 = result;
        v15 = -v11;
        do
        {
          v16 = *v13--;
          dev_pm_domain_detach(v16, 0);
        }
        while ( !__CFADD__(v15++, 1) );
        return v14;
      }
    }
    else
    {
      return (unsigned int)-(int)v7;
    }
  }
  return result;
}
