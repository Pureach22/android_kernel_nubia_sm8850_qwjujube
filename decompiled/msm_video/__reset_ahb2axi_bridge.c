__int64 __fastcall _reset_ahb2axi_bridge(__int64 a1)
{
  __int64 v1; // x9
  unsigned int v3; // w8
  _QWORD *v4; // x27
  int v5; // w20
  __int64 result; // x0
  __int64 v7; // x9
  _QWORD *v8; // x9
  unsigned __int64 v9; // x8
  __int64 *v10; // x24
  unsigned int v11; // w26
  __int64 v12; // t1
  unsigned int v13; // w26
  unsigned int v14; // w21

  v1 = *(_QWORD *)(a1 + 3904);
  v3 = *(_DWORD *)(v1 + 88);
  v4 = *(_QWORD **)(v1 + 80);
  if ( v4 >= &v4[3 * v3] )
  {
LABEL_19:
    if ( v4 >= &v4[3 * v3] )
      return 0;
    while ( 1 )
    {
      result = reset_control_deassert(*v4);
      if ( (_DWORD)result )
      {
        if ( (msm_vidc_debug & 1) != 0 )
        {
          v13 = result;
          printk(&unk_89520, "err ", 0xFFFFFFFFLL, "codec", "__reset_control_deassert");
LABEL_27:
          result = v13;
        }
      }
      else if ( (msm_vidc_debug & 2) != 0 )
      {
        v13 = 0;
        printk(&unk_89F94, "high", 0xFFFFFFFFLL, "codec", "__reset_control_deassert");
        goto LABEL_27;
      }
      v4 += 3;
      if ( (unsigned __int64)v4 >= *(_QWORD *)(*(_QWORD *)(a1 + 3904) + 80LL)
                                 + 24 * (unsigned __int64)*(unsigned int *)(*(_QWORD *)(a1 + 3904) + 88LL) )
        return result;
    }
  }
  v5 = 0;
  while ( *v4 )
  {
    result = reset_control_assert();
    if ( (_DWORD)result )
    {
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v14 = result;
        printk(&unk_8F4BF, "err ", 0xFFFFFFFFLL, "codec", "__reset_control_assert");
        result = v14;
      }
      v9 = *(_QWORD *)(*(_QWORD *)(a1 + 3904) + 80LL);
      v10 = (__int64 *)(v9 + 24LL * v5);
      if ( (unsigned __int64)v10 >= v9 )
      {
        v11 = result;
        do
        {
          if ( (msm_vidc_debug & 1) != 0 )
            printk(&unk_89F94, "err ", 0xFFFFFFFFLL, "codec", "__reset_control_assert");
          v12 = *v10;
          v10 -= 3;
          reset_control_deassert(v12);
        }
        while ( (unsigned __int64)v10 >= *(_QWORD *)(*(_QWORD *)(a1 + 3904) + 80LL) );
        return v11;
      }
      return result;
    }
    ++v5;
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_91ADF, "high", 0xFFFFFFFFLL, "codec", "__reset_control_assert");
    usleep_range_state(1000, 1100, 2);
    v7 = *(_QWORD *)(a1 + 3904);
    v4 += 3;
    v3 = *(_DWORD *)(v7 + 88);
    v8 = *(_QWORD **)(v7 + 80);
    if ( v4 >= &v8[3 * v3] )
    {
      v4 = v8;
      goto LABEL_19;
    }
  }
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_82D97, "err ", 0xFFFFFFFFLL, "codec", "__reset_control_assert");
  return 4294967274LL;
}
