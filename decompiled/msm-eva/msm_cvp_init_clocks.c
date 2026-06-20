unsigned __int64 __fastcall msm_cvp_init_clocks(__int64 a1)
{
  __int64 v1; // x8
  _QWORD *v3; // x22
  __int64 v4; // x11
  __int16 v5; // w9
  int v6; // w10
  unsigned __int64 result; // x0
  unsigned __int64 v8; // x8
  unsigned __int64 i; // x9
  unsigned __int64 v10; // x20
  __int64 v11; // x9
  unsigned __int64 v12; // x10
  unsigned __int64 v13; // x21
  unsigned __int64 StatusReg; // x8

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 2208);
    v3 = *(_QWORD **)(v1 + 280);
    v4 = *(unsigned int *)(v1 + 288);
    if ( v3 < &v3[4 * v4] )
    {
      v5 = msm_cvp_debug;
      v6 = msm_cvp_debug_out;
      do
      {
        if ( (v5 & 0x400) != 0 && !v6 )
        {
          printk(&unk_86F23, &unk_8DA84, *v3, *((unsigned __int8 *)v3 + 28));
          v5 = msm_cvp_debug;
          v6 = msm_cvp_debug_out;
          v1 = *(_QWORD *)(a1 + 2208);
        }
        v4 = *(unsigned int *)(v1 + 288);
        v3 += 4;
      }
      while ( (unsigned __int64)v3 < *(_QWORD *)(v1 + 280) + 32 * v4 );
      v3 = *(_QWORD **)(v1 + 280);
    }
    for ( i = (unsigned __int64)&v3[4 * v4]; ; i = *(_QWORD *)(v1 + 280) + 32LL * *(unsigned int *)(v1 + 288) )
    {
      if ( (unsigned __int64)v3 >= i )
      {
        result = 0;
        *(_DWORD *)(a1 + 24) = 0;
        return result;
      }
      if ( !v3[2] )
      {
        result = clk_get(*(_QWORD *)(v1 + 256) + 16LL, *v3);
        v3[2] = result;
        if ( result > 0xFFFFFFFFFFFFF000LL )
        {
          v10 = result;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            StatusReg = _ReadStatusReg(SP_EL0);
            printk(&unk_8D35C, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
            result = v10;
          }
          v3[2] = 0;
          v11 = *(_QWORD *)(a1 + 2208);
          *(_DWORD *)(a1 + 24) = 0;
          v12 = *(_QWORD *)(v11 + 280);
          v13 = v12 + 32LL * (unsigned int)(*(_DWORD *)(v11 + 288) - 1);
          if ( v13 >= v12 )
          {
            do
            {
              if ( *(_QWORD *)(v13 + 16) )
              {
                clk_put(*(_QWORD *)(v13 + 16));
                *(_QWORD *)(v13 + 16) = 0;
                result = v10;
                v11 = *(_QWORD *)(a1 + 2208);
              }
              v13 -= 32LL;
            }
            while ( v13 >= *(_QWORD *)(v11 + 280) );
          }
          return result;
        }
        v1 = *(_QWORD *)(a1 + 2208);
      }
      v3 += 4;
    }
  }
  result = 4294967274LL;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v8 = _ReadStatusReg(SP_EL0);
    printk(&unk_837CA, *(unsigned int *)(v8 + 1800), *(unsigned int *)(v8 + 1804), &unk_8E7CE);
    return 4294967274LL;
  }
  return result;
}
