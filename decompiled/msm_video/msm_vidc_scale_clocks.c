__int64 __fastcall msm_vidc_scale_clocks(__int64 a1)
{
  __int64 v1; // x8
  unsigned int (**v3)(void); // x8
  unsigned int (*v4)(void); // x8
  __int64 v5; // x1
  int v6; // w0
  __int64 v7; // x3
  __int64 v8; // x4

  v1 = *(_QWORD *)(a1 + 320);
  if ( v1 && (v3 = *(unsigned int (***)(void))(v1 + 6560)) != nullptr && (v4 = *v3) != nullptr )
  {
    if ( *((_DWORD *)v4 - 1) != 1661903850 )
      __break(0x8228u);
    v5 = v4();
  }
  else
  {
    v5 = 0;
  }
  v6 = venus_hfi_scale_clocks(a1, v5);
  if ( a1 && v6 && (msm_vidc_debug & 1) != 0 )
    printk(&unk_89422, "err ", a1 + 340, v7, v8);
  return 0;
}
