__int64 __fastcall dwc3_msm_req_complete_func(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  _QWORD *v5; // x22
  _QWORD *v6; // x21
  _QWORD *v7; // x8
  _QWORD *v8; // x9
  unsigned __int64 v9; // x8
  __int64 v10; // x9
  int v11; // w23
  _DWORD *v12; // x10
  int v13; // w0
  __int64 v14; // x9
  int v15; // w8
  int v16; // w10
  _QWORD *v17; // x11
  int v18; // w12
  int v19; // w11
  __int64 v20; // x8
  __int64 v21; // x22
  __int64 v22; // x23
  int v23; // w0
  void (__fastcall *v24)(__int64, __int64); // x8

  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 368LL);
  v5 = *(_QWORD **)(*(_QWORD *)(v4 + 96) + 152LL);
  v6 = v5 + 39;
  do
    v6 = (_QWORD *)*v6;
  while ( v6 != v5 + 39 && v6[2] != a2 );
  if ( !v6 || v6[2] != a2 )
    return dev_err(v4, "%s: could not find the request\n", "dwc3_msm_req_complete_func");
  v7 = (_QWORD *)v6[1];
  if ( (_QWORD *)*v7 == v6 && (v8 = (_QWORD *)*v6, *(_QWORD **)(*v6 + 8LL) == v6) )
  {
    v8[1] = v7;
    *v7 = v8;
  }
  else
  {
    v4 = _list_del_entry_valid_or_report(v6);
  }
  *v6 = 0xDEAD000000000100LL;
  v6[1] = 0xDEAD000000000122LL;
  v9 = *(unsigned __int8 *)(a1 + 170);
  ++*(_BYTE *)(a1 + 169);
  if ( v9 >= 0x20 )
  {
    __break(0x5512u);
    return dwc3_ext_event_notify(v4);
  }
  else
  {
    v10 = (__int64)&v5[5 * (unsigned int)v9 + 159];
    if ( *(_DWORD *)(v10 + 8) == 1 )
    {
      v11 = *(unsigned __int8 *)(v10 + 24);
      v12 = (_DWORD *)v5[62];
      LOBYTE(v5[5 * (unsigned int)v9 + 162]) = 0;
      v13 = readl((unsigned int *)(v5[1] + (unsigned int)(*v12 + v12[1] * v11 + 1015808)));
      writel(
        v13 & 0xFFFFFFFE,
        (unsigned int *)(v5[1] + (unsigned int)(*(_DWORD *)v5[62] + *(_DWORD *)(v5[62] + 4LL) * v11 + 1015808)));
    }
    v14 = 0;
    v15 = 0;
    v16 = 0;
    do
    {
      v17 = &v5[v14];
      v14 += 10;
      v18 = *((_DWORD *)v17 + 320);
      v19 = *((_DWORD *)v17 + 330);
      if ( v18 == 1 )
        ++v15;
      if ( v19 == 1 )
        ++v16;
    }
    while ( v14 != 160 );
    if ( !(v16 + v15)
      && !(unsigned int)readl((unsigned int *)(v5[1] + (unsigned int)(*(_DWORD *)(v5[62] + 40LL) + 1015808))) )
    {
      writel(0, (unsigned int *)(v5[1] + (unsigned int)(*(_DWORD *)(v5[62] + 120LL) + 1015808)));
      writel(0, (unsigned int *)(v5[1] + (unsigned int)(*(_DWORD *)(v5[62] + 128LL) + 1015808)));
      v20 = v5[62];
      v21 = v5[1];
      v22 = (unsigned int)(*(_DWORD *)(v20 + 40) + 1015808);
      v23 = readl((unsigned int *)(v21 + v22));
      writel(v23 & 0xFFFF0000, (unsigned int *)(v21 + v22));
      readl((unsigned int *)(v21 + v22));
    }
    v24 = (void (__fastcall *)(__int64, __int64))v6[3];
    *(_QWORD *)(a2 + 48) = v24;
    if ( v24 )
    {
      if ( *((_DWORD *)v24 - 1) != -2083909208 )
        __break(0x8228u);
      v24(a1, a2);
    }
    return kfree(v6);
  }
}
