__int64 __fastcall set_qdss_data_connection(__int64 a1, int a2)
{
  __int64 result; // x0
  __int64 v3; // x1
  void *v4; // x8
  unsigned int v5; // w19

  if ( !a1 )
  {
    printk(&unk_85E2, "set_qdss_data_connection");
    return 4294967274LL;
  }
  if ( a2 )
  {
    result = msm_ep_config(*(_QWORD *)(a1 + 240), *(_QWORD *)(a1 + 288), 1);
    if ( (_DWORD)result )
    {
      v4 = &unk_833A;
LABEL_9:
      v5 = result;
      printk(v4, v3);
      return v5;
    }
  }
  else
  {
    result = msm_ep_unconfig(*(_QWORD *)(a1 + 240));
    if ( (_DWORD)result )
    {
      v4 = &unk_84BA;
      goto LABEL_9;
    }
  }
  return result;
}
