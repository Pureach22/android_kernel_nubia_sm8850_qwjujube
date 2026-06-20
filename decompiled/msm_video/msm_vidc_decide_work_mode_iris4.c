__int64 __fastcall msm_vidc_decide_work_mode_iris4(_QWORD *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v5; // w8
  unsigned int v6; // w8
  int v7; // w8
  _QWORD *v8; // x19
  char is_less_than; // w8
  _QWORD *v10; // x19
  char is_greater_than; // w8
  int v12; // w10
  unsigned int v13; // w2

  v5 = *((_DWORD *)a1 + 78);
  if ( v5 == 64 )
  {
LABEL_10:
    v6 = 1;
    goto LABEL_22;
  }
  if ( v5 == 8 )
  {
    if ( *((_DWORD *)a1 + 77) == 2 )
      v6 = 1;
    else
      v6 = 2;
LABEL_22:
    if ( a1[1445] <= (__int64)v6 )
      v13 = a1[1445];
    else
      v13 = v6;
    if ( a1 )
    {
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_87DBF, "high", (char *)a1 + 340, v13, a1[1951]);
    }
    ((void (*)(void))msm_vidc_update_cap_value)();
    return 0;
  }
  v7 = *((_DWORD *)a1 + 77);
  if ( v7 == 1 )
  {
    v10 = a1;
    is_greater_than = res_is_greater_than(*((unsigned int *)a1 + 472), *((unsigned int *)a1 + 473), 4096, 2160);
    a1 = v10;
    v12 = 2;
    if ( (is_greater_than & 1) == 0 )
    {
      if ( v10[1951] )
        v12 = 1;
      else
        v12 = 2;
    }
    if ( v10[2119] == 2 )
      v12 = 1;
    if ( v10[3064] )
      v12 = 2;
    if ( v10[1972] )
      v6 = v12;
    else
      v6 = 2;
    goto LABEL_22;
  }
  if ( v7 == 2 )
  {
    v8 = a1;
    is_less_than = res_is_less_than(*((unsigned int *)a1 + 98), *((unsigned int *)a1 + 99), 1280, 720);
    a1 = v8;
    if ( v8[3988] != 1 && !((v8[1951] != 0) | is_less_than & 1) )
    {
      v6 = 2;
      goto LABEL_22;
    }
    goto LABEL_10;
  }
  if ( !a1 || (msm_vidc_debug & 1) == 0 )
    return 4294967274LL;
  printk(&unk_94284, "err ", (char *)a1 + 340, "msm_vidc_decide_work_mode_iris4", a5);
  return 4294967274LL;
}
