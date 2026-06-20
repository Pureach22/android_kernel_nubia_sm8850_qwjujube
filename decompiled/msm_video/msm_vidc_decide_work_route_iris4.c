__int64 __fastcall msm_vidc_decide_work_route_iris4(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v5; // w8
  unsigned int v6; // w19
  int v8; // w8
  bool v9; // zf

  v5 = *(_DWORD *)(a1 + 312);
  v6 = *(_DWORD *)(*(_QWORD *)(a1 + 320) + 4272LL);
  if ( v5 == 8 )
  {
LABEL_4:
    if ( !a1 )
    {
LABEL_7:
      ((void (*)(void))msm_vidc_update_cap_value)();
      return 0;
    }
LABEL_5:
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_8ECAE, "high", a1 + 340, v6, a5);
    goto LABEL_7;
  }
  if ( v5 == 64 )
  {
    v6 = 1;
    goto LABEL_4;
  }
  v8 = *(_DWORD *)(a1 + 308);
  if ( v8 == 1 )
  {
    v9 = *(_DWORD *)(a1 + 16952) == 2;
LABEL_12:
    if ( v9 )
      v6 = 1;
    if ( !a1 )
      goto LABEL_7;
    goto LABEL_5;
  }
  if ( v8 == 2 )
  {
    v9 = *(_QWORD *)(a1 + 31904) == 1;
    goto LABEL_12;
  }
  if ( a1 && (msm_vidc_debug & 1) != 0 )
    printk(&unk_94284, "err ", a1 + 340, "msm_vidc_decide_work_route_iris4", a5);
  return 4294967274LL;
}
