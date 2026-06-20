__int64 __fastcall dp_hw_cookie_conversion_init(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v12; // w25
  int v13; // w28
  unsigned __int64 v14; // x26
  unsigned int *v15; // x21
  unsigned int v16; // w24
  __int64 v17; // x10
  void (*v18)(void); // x8
  __int64 v19; // x0

  if ( *(_DWORD *)(a2 + 4) )
  {
    v12 = 0;
    v13 = *(_DWORD *)a2 >> 2;
    v14 = 0;
    v15 = (unsigned int *)(*(_QWORD *)(a2 + 8) + 16LL);
    do
    {
      v18 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1112LL);
      if ( v18 )
      {
        if ( *((_DWORD *)v18 - 1) != -1966518194 )
          __break(0x8228u);
        v18();
      }
      v16 = v14 + v13;
      if ( (unsigned int)(v14 + v13) >= 0x400 )
      {
        v19 = printk(
                &unk_AAA255,
                "0",
                "dp_hw_cookie_conversion_init",
                "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/be/dp_be.c");
        dump_stack(v19);
      }
      *v15 = v16;
      v17 = *((_QWORD *)v15 - 2);
      ++v14;
      v12 += 4;
      v15 += 6;
      *(_QWORD *)(*(_QWORD *)(a1 + 22608) + 24LL * v16) = v17;
    }
    while ( v14 < *(unsigned int *)(a2 + 4) );
    return 0;
  }
  else
  {
    qdf_trace_msg(0x45u, 2u, "%s: total page num is 0", a3, a4, a5, a6, a7, a8, a9, a10, "dp_hw_cookie_conversion_init");
    return 4;
  }
}
