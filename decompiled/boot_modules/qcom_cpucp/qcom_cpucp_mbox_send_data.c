__int64 __fastcall qcom_cpucp_mbox_send_data(_DWORD *a1, unsigned int *a2)
{
  __int64 v2; // x8
  __int64 v3; // x9
  int v4; // w11
  unsigned int v5; // w0
  __int64 v6; // x10

  v2 = *(_QWORD *)a1;
  v3 = *(_QWORD *)(*(_QWORD *)a1 + 152LL);
  if ( *(_BYTE *)(v3 + 28) != 1 )
  {
    v6 = 0;
    v5 = 0x10000000;
    goto LABEL_5;
  }
  if ( a2 )
  {
    v4 = a1[60];
    v5 = *a2;
    v6 = (unsigned int)(*(_DWORD *)(v3 + 24) * v4);
LABEL_5:
    writel(v5, (unsigned int *)(*(_QWORD *)(v2 + 160) + v6 + *(unsigned int *)(v3 + 12)));
  }
  return 0;
}
