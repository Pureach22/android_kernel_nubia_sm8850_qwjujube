__int64 __fastcall msm_vidc_trigger_ssr(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x4
  __int64 v3; // x9
  unsigned __int64 v4; // x8
  _DWORD *v5; // x9
  __int64 v6; // x11
  unsigned __int64 v7; // x10
  int v9; // w8
  unsigned __int64 v10; // x9
  __int64 v11; // x1
  unsigned __int64 v13; // x19
  __int64 v14; // x21

  if ( (msm_vidc_debug & 1) != 0 )
  {
    v13 = a2;
    v14 = a1;
    printk(&unk_86996, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_trigger_ssr");
    a2 = v13;
    a1 = v14;
  }
  v2 = a2 & 0xF;
  v3 = *(_QWORD *)(a1 + 3912);
  *(_DWORD *)(a1 + 6432) = v2;
  v4 = *(unsigned int *)(v3 + 640);
  if ( !(_DWORD)v4 )
    goto LABEL_11;
  v5 = *(_DWORD **)(v3 + 632);
  if ( *v5 == (_DWORD)v2 )
    goto LABEL_10;
  v6 = 1;
  do
  {
    v7 = v6;
    if ( v4 == v6 )
      break;
  }
  while ( v5[v6++] != (_DWORD)v2 );
  if ( v7 < v4 )
  {
LABEL_10:
    v9 = (unsigned __int8)a2 >> 4;
    v10 = HIDWORD(a2);
    v11 = system_wq;
    *(_DWORD *)(a1 + 6436) = v9;
    *(_DWORD *)(a1 + 6440) = v10;
    queue_work_on(32, v11, a1 + 6336);
  }
  else
  {
LABEL_11:
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_85AE9, "high", 0xFFFFFFFFLL, "codec", v2);
  }
  return 0;
}
