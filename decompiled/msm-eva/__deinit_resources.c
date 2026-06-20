__int64 __fastcall _deinit_resources(_QWORD *a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  unsigned __int64 v6; // x11
  _QWORD *v7; // x22
  __int64 v8; // x8
  int v9; // w9
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x20
  __int64 v12; // x3
  __int64 v13; // x8
  unsigned __int64 v14; // x11
  _QWORD *v15; // x20
  __int64 result; // x0

  v4 = a1[276];
  if ( *(_BYTE *)(v4 + 192) == 1 )
  {
    v6 = *(_QWORD *)(v4 + 200);
    v7 = (_QWORD *)(v6 + 24LL * (unsigned int)(*(_DWORD *)(v4 + 208) - 1));
    if ( (unsigned __int64)v7 >= v6 )
    {
      do
      {
        if ( v7[2] )
        {
          if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
            printk(&unk_96346, "core", *v7, a4);
          llcc_slice_putd();
          v7[2] = 0;
          v4 = a1[276];
        }
        v7 -= 3;
      }
      while ( (unsigned __int64)v7 >= *(_QWORD *)(v4 + 200) );
    }
  }
  kfree(a1[7]);
  v8 = a1[276];
  a1[7] = 0;
  a1[8] = 0;
  v9 = *(_DWORD *)(v8 + 304);
  v10 = *(_QWORD *)(v8 + 296);
  v11 = v10 + 120LL * (unsigned int)(v9 - 1);
  if ( v11 >= v10 )
  {
    do
    {
      *(_QWORD *)(*(_QWORD *)(v11 + 24) + 152LL) = 0;
      icc_put(*(_QWORD *)(v11 + 104));
      *(_QWORD *)(v11 + 104) = 0;
      v11 -= 120LL;
    }
    while ( v11 >= *(_QWORD *)(a1[276] + 296LL) );
  }
  msm_cvp_deinit_clocks(a1);
  v13 = a1[276];
  if ( *(_DWORD *)(v13 + 464) )
  {
    if ( (msm_cvp_debug & 4) != 0 && !msm_cvp_debug_out )
      printk(&unk_92F1F, "info", "__deinit_regulators", v12);
  }
  else
  {
    v14 = *(_QWORD *)(v13 + 264);
    v15 = (_QWORD *)(v14 + 24LL * (unsigned int)(*(_DWORD *)(v13 + 272) - 1));
    if ( (unsigned __int64)v15 >= v14 )
    {
      do
      {
        if ( *v15 )
        {
          regulator_put();
          *v15 = 0;
          v13 = a1[276];
        }
        v15 -= 3;
      }
      while ( (unsigned __int64)v15 >= *(_QWORD *)(v13 + 264) );
    }
  }
  result = kfree(a1[313]);
  a1[313] = 0;
  return result;
}
