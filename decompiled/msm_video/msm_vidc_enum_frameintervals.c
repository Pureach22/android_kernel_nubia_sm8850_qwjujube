__int64 __fastcall msm_vidc_enum_frameintervals(__int64 a1, _DWORD *a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 result; // x0
  __int64 v6; // x20
  int v9; // w0
  __int64 v10; // x1
  _DWORD *v11; // x8
  int v12; // w0
  __int64 v13; // x4
  __int64 v14; // x9
  __int64 v15; // x9
  unsigned int v16; // w10

  if ( *(_DWORD *)(a1 + 308) == 2 )
  {
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      return 4294967271LL;
    printk(&unk_976FB, "err ", a1 + 340, "msm_vidc_enum_frameintervals", a5);
    return 4294967271LL;
  }
  if ( *a2 )
    return 4294967274LL;
  v6 = *(_QWORD *)(a1 + 320);
  v9 = v4l2_colorformat_from_driver(a1, 0x80000000LL, "msm_vidc_enum_frameintervals");
  v10 = (unsigned int)a2[1];
  v11 = a2;
  if ( (_DWORD)v10 != v9 )
  {
    v12 = v4l2_colorformat_to_driver(a1, v10, "msm_vidc_enum_frameintervals");
    v11 = a2;
    if ( !v12 )
    {
      if ( a1 && (msm_vidc_debug & 1) != 0 )
        printk(&unk_87351, "err ", a1 + 340, "msm_vidc_enum_frameintervals", (unsigned int)a2[1]);
      return 4294967274LL;
    }
  }
  v13 = (unsigned int)v11[2];
  if ( *(_QWORD *)(a1 + 17104) < v13
    || *(_QWORD *)(a1 + 17096) > v13
    || (v14 = (unsigned int)v11[3], *(_QWORD *)(a1 + 17608) < v14)
    || *(_QWORD *)(a1 + 17600) > v14 )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_96193, "err ", a1 + 340, "msm_vidc_enum_frameintervals", v13);
    return 4294967274LL;
  }
  result = 0;
  v15 = *(_QWORD *)(v6 + 4144) / (__int64)(((unsigned int)(v14 + 15) >> 4) * ((unsigned int)(v13 + 15) >> 4));
  *((_QWORD *)v11 + 2) = 0x100000003LL;
  v16 = *(_DWORD *)(a1 + 19456);
  *(_QWORD *)(v11 + 7) = 0x100000001LL;
  if ( (unsigned int)v15 >= v16 )
    LODWORD(v15) = v16;
  v11[6] = v15;
  v11[9] = 1;
  v11[10] = *(_QWORD *)(a1 + 19456);
  return result;
}
